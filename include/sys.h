/* a place for definitions related to system */

#ifndef __SYS_UNICORN__
#define __SYS_UNICORN__

void		idt_setup(void);
void		idt_set_gate(unsigned char, unsigned long, 
			     unsigned short, unsigned char);

#endif /* __SYS_H__ */
