/*
 * =====================================================================================
 *
 *       Filename:  fs.c
 *
 *    Description:  文件系统
 *
 *        Version:  1.0
 *        Created:  2013年10月25日 17时06分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
 *        Company:  Class 1107 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include "fs.h"

// 跟文件系统
fs_node_t *fs_root = NULL;

uint32_t read_fs(fs_node_t *node, uint32_t offset, uint32_t size, uint8_t *buffer)
{
	// Has the node got a read callback?
	if (node->read != NULL)
	      return node->read(node, offset, size, buffer);
	
	return 0;
}

uint32_t write_fs(fs_node_t *node, uint32_t offset, uint32_t size, uint8_t *buffer)
{
	// Has the node got a write callback?
	if (node->write != NULL)
	      return node->write(node, offset, size, buffer);
	
	return NULL;
}

void open_fs(fs_node_t *node, uint8_t read, uint8_t write)
{
	// Has the node got an open callback?
	if (node->open != NULL)
	      node->open(node);
}

void close_fs(fs_node_t *node)
{
	// Has the node got a close callback?
	if (node->close != NULL)
	      node->close(node);
}

struct dirent *readdir_fs(fs_node_t *node, uint32_t index)
{
	// Is the node a directory, and does it have a callback?
	if ((node->flags & 0x7) == FS_DIRECTORY && node->readdir != 0)
	      return node->readdir(node, index);
	
	return NULL;
}

fs_node_t *finddir_fs(fs_node_t *node, char *name)
{
	// Is the node a directory, and does it have a callback?
	if ((node->flags & 0x7) == FS_DIRECTORY && node->finddir != 0)
	      return node->finddir(node, name);
	
	return NULL;
}

