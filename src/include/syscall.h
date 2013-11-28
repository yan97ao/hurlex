/*
 * =====================================================================================
 *
 *       Filename:  syscall.h
 *
 *    Description:  系统调用相关定义
 *
 *        Version:  1.0
 *        Created:  2013年11月26日 13时33分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
 *        Company:  Class 1107 of Computer Science and Technology
 *
 * =====================================================================================
 */

#ifndef INCLUDE_SYSCALL_H_
#define INCLUDE_SYSCALL_H_

#include "common.h"
#include "debug.h"

#define SYSCALL_COUNT 1

// 初始化系统调用
void init_syscall();

#define DECL_SYSCALL1(fn,p1) int32_t syscall_##fn(p1);

DECL_SYSCALL1(printk, const char *)

#define DEFN_SYSCALL1(fn, num, P1) \
int32_t syscall_##fn(P1 p1) \
{ \
	int32_t a; \
	asm volatile("int $0xFF" : "=a" (a) : "0" (num), "b" ((int32_t)p1)); \
	return a; \
}

#endif 	// INCLUDE_SYSCALL_H_
