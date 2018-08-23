#include <screen.h>
#include <gdt.h>
#include <idt.h>
#include <pic_c.h>
#include <time.h>


void arch_init()
{
	puts("Initializing GDT...");
	install_gdt();
	puts("GDT initialized!");

	puts("Initializing IDT...");
	install_idt(0x08);
	puts("IDT initialized!");

	puts("Setting up PIC...");
	irq_install(0x08);
	puts("PIC initialized!");

	asm volatile ("sti");

	puts("Setting up PIT...");
	timer_install(100);
	puts("PIT initialized!");

	asm volatile("int $32");
}