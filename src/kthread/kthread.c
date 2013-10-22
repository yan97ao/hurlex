/*
 * =====================================================================================
 *
 *       Filename:  kthread.c
 *
 *    Description:  内核线程的实现
 *
 *        Version:  1.0
 *        Created:  2013年10月10日 15时53分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
 *        Company:  Class 1107 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include "kthread.h"
#include "string.h"
#include "heap.h"
#include "printk.h"
#include "scheduler.h"


