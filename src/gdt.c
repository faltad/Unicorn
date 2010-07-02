
t_gdtptr	gdtptr;
t_gdt_entry	gdt_entries[5];


void init_gdt_desc(uint base, uint limite, uchar acces, uchar other,
                   struct t_gdt_entry *desc)
{
   desc->lim0_15 = (limite & 0xffff);
   desc->base0_15 = (base & 0xffff);
   desc->base16_23 = (base & 0xff0000) >> 16;
   desc->acces = acces;
   desc->lim16_19 = (limite & 0xf0000) >> 16;
   desc->other = (other & 0xf);
   desc->base24_31 = (base & 0xff000000) >> 24;
   return;
}

void	init_gdt(void)
{
   init_gdt_desc(0, 0, 0, 0, &gdt_entries[0]); // NULL segment 
   init_gdt_desc(0, 0xFFFFFFFF, 0x9A, 0xCF, &gdt_entries[1]); // Kernel code 
   init_gdt_desc(0, 0xFFFFFFFF, 0x92, 0xCF, &gdt_entries[2]); // Kernel data
   gdtptr.base = GDTADDR;
   gdtptr.limit = 3 * sizeof(t_gdt_entry) - 1;
   memcpy((void *)gdtptr.base, (void *)gdt_entries, gdtptr.limit);
}
