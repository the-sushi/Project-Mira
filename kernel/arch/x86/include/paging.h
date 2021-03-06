#pragma once
#include <types.h>

struct pt_entry_s
{
	unsigned present  : 1;
	unsigned rw       : 1;
	unsigned user     : 1;
	unsigned wthrough : 1;
	unsigned nocache  : 1;
	unsigned accessed : 1;
	unsigned dirty    : 1;
	unsigned zero     : 2; /* actually [PAT, global] but will be zero anyway */
	unsigned avail    : 2;
	unsigned addrress : 20;
} __attribute__ ((packed));

struct pd_entry_s
{
	unsigned present  : 1;
	unsigned rw       : 1;
	unsigned user     : 1;
	unsigned wthrough : 1;
	unsigned nocache  : 1;
	unsigned accessed : 1;
	unsigned dirty    : 1;
	unsigned zero     : 2; /* Actually [zero, global], but global is ignored */
	unsigned avail    : 2;
	unsigned addrress : 20;
} __attribute__ ((packed));

struct pt_entry_s typedef page_table_t[1024];
struct pd_entry_s typedef page_dir_t[1024];

extern page_dir_t page_dir;

int8_t map_page_large (void * virt, struct pd_entry_s pd_entry);