#ifndef _MENU_H
#define _MENU_H

#include "common.h"

// allow the user to drop into a shell provided by busybox
#ifdef DEVELOPMENT
 #define SHELL
#endif

typedef struct _menu_entry
{
	unsigned int id;
	char 	*name,
				*blkdev,
				*kernel,
				*cmdline,
				*initrd;
	struct _menu_entry *next;
} menu_entry;

void free_entry(menu_entry *);
void free_menu(menu_entry *);
void print_menu(menu_entry *);
menu_entry *add_entry(menu_entry *, char *, char *,char *, char *, char *);
menu_entry *del_entry(menu_entry *, menu_entry *);
menu_entry *get_item_by_id(menu_entry *, int);
#endif