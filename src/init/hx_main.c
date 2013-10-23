/*
 * =====================================================================================
 *
 *       Filename:  hx_ main.c
 *
 *    Description:  hurlex 内核的入口函数
 *
 *        Version:  1.0
 *        Created:  2013年07月24日 19时31分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
 *        Company:  Class 1107 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include "multiboot.h"
#include "debug.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"
#include "keyboard.h"
#include "mm.h"
#include "kthread.h"
#include "scheduler.h"
#include "spinlock.h"

// 定义 elf 相关信息数据
elf_t kernel_elf;

int hx_main(multiboot_t *mboot_ptr)
{
	// 从 GRUB 提供的信息中获取到内核符号表和代码地址信息
	kernel_elf = elf_from_multiboot(mboot_ptr);
	
	// 初始化全局段描述符表
	init_gdt();
	// 初始化全局中断描述符表
	init_idt();

	// 清屏
	monitor_clear();
	printk_color(rc_black, rc_red, "**************************\n");
	printk_color(rc_black, rc_red, "*  Hello, hurlex kernel! *\n");
	printk_color(rc_black, rc_red, "**************************\n\n");
	printk_color(rc_black, rc_green, "This is a simple OS kernel, just for study.\nYou can copy it freely!\n\n");
	
	// 初始化物理内存管理
	init_pmm(mboot_ptr);
	// 初始化虚拟内存管理
	init_vmm();
	// 初始化物理内存可用页
	init_page_pmm(mboot_ptr);
	// 初始化内核态堆管理
	init_heap();
	// 测试内核堆函数
	test_heap();

	// 初始化时钟中断
// 	init_timer(20);
	// 初始化键盘驱动
	init_keyboard_driver();

	// 解除对 INTR 中断的屏蔽
	asm volatile("sti");

	return 0;
}

