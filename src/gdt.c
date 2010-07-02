
#include "descriptor_table.h"
#include "types.h"

t_gdtptr	gdtptr;
t_gdt_entry	gdt_entries[5];

static void gdt_set_gate(int num, uint base, uint limit, uchar access, uchar gran)
{
    gdt_entries[num].base_low    = (base & 0xFFFF);
    gdt_entries[num].base_middle = (base >> 16) & 0xFF;
    gdt_entries[num].base_high   = (base >> 24) & 0xFF;

    gdt_entries[num].limit_low   = (limit & 0xFFFF);
    gdt_entries[num].granularity = (limit >> 16) & 0x0F;
    
    gdt_entries[num].granularity |= gran & 0xF0;
    gdt_entries[num].access      = access;
}


void	gdt_flush(void)
{
   asm("lgdtl (gdtptr)");
   asm("movw 0x10, %ax\n \
        movw %ax, %ds\n \
        movw %ax, %es\n \
	movw %ax, %fs\n \
        movw %ax, %gs\n \
        movw %ax, %ss\n \
	ljmp $0x08, $next\n \
	next:		\n");
}

void	init_gdt(void)
{

    gdtptr.limit = (sizeof(t_gdt_entry) * 5) - 1;
    gdtptr.base  = (uint)&gdt_entries;

    gdt_set_gate(0, 0, 0, 0, 0);                // Null segment
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
    gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
    gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

    gdt_flush();
}
