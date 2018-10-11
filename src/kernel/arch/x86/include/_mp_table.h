#pragma once
#include <types.h>


struct mp_config_s
{
	char   sig[4]; /* PCMP */
	uint16 base_len;
	uint8  revision;
	uint8  checksum;

	char oem_id[8];
	char product_id[12];

	uint32 oem_table_ptr;
	uint16 oem_table_len;

	uint16 entry_count;
	uint32 lapic_addr;
	uint16 table_extended_len;
	uint8  table_extended_checksum;

	uint8 reserved;
} __attribute__ ((packed));

struct mp_processor_s
{
	uint8 type;
	uint8 apic_id;
	uint8 apic_ver      : 8;
	uint8
		enabled   : 1,
		bootstrap : 1,
		reserved  : 6;

	unsigned cpu_sig       : 32;
	unsigned cpu_feature   : 32;
} __attribute__ ((packed));

struct mp_io_apic_s
{
	uint8 type;
	uint8 apic_id;
	uint8 version;
	uint8
		enabled  : 1,
		reserved : 6;
	uint32 addr;
} __attribute__ ((packed));

struct mp_bus_s
{
	uint8 type;
	uint8 id;
	char bus_type[6];
} __attribute__ ((packed));

struct mp_irq
{
	uint8 type;
	uint8 irq_type;
	uint16
		polarity : 2,
		mode     : 2,
		reserved : 12;

	uint8 src_bus_id;
	uint8 src_bus_irq;

	uint8 src_dest_apic_id;
	uint8 src_dest_apic_pin;
} __attribute__ ((packed));

struct mp_floating_s
{
	char           sig[4]; /* _MP_ */
	mp_config_s *  config;
	uint8          len;
	uint8          revision;
	uint8          checksum;
	uint8          feature[5];
} __attribute__ ((packed));