/*
 * =====================================================================================
 *
 *       Filename:  process.h
 *
 *    Description:  进程管理相关的定义
 *
 *        Version:  1.0
 *        Created:  2013年10月21日 16时18分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
 *        Company:  Class 1107 of Computer Science and Technology
 *
 * =====================================================================================
 */

#ifndef INCLUDE_PROCESS_H_
#define INCLUDE_PROCESS_H_

#include "types.h"

// 进程状态描述
typedef
enum task_state {

};

// 进程控制块 PCB 
typedef
struct task_struct {
	task_state state; 	// 进程当前状态
	
} task_struct;

#endif 	// INCLUDE_PROCESS_H_

