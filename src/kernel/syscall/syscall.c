/*
 * =====================================================================================
 *
 *       Filename:  syscall.c
 *
 *    Description:  系统调用相关
 *
 *        Version:  1.0
 *        Created:  2013年11月26日 13时34分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
 *        Company:  Class 1107 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include "syscall.h"
#include "idt.h"

static void syscall_handler(pt_regs *regs);

DEFN_SYSCALL1(printk, 0, const char*);

uint32_t syscall_count = SYSCALL_COUNT;

static void *syscalls[SYSCALL_COUNT] = { &printk };

void init_syscall()
{
	register_interrupt_handler(0xFF, syscall_handler);
}

void syscall_handler(pt_regs *regs)
{
	if (regs->eax >= syscall_count) {
		return;
	}

	void *sys_fun = syscalls[regs->eax];

	asm volatile (" push %1 \n\t"
			"push %2 \n\t"
			"push %3 \n\t"
			"push %4 \n\t"
			"push %5 \n\t"
			"call *%6 \n\t"
			"pop %%ebp \n\t"
			"pop %%ebp \n\t"
			"pop %%ebp \n\t"
			"pop %%ebp \n\t"
			"pop %%ebp \n\t"
			: "=a" (regs->eax) : "r" (regs->edi), "r" (regs->esi), \
			"r" (regs->edx), "r" (regs->ecx), "r" (regs->ebx), \
			"r" (sys_fun) );
}

