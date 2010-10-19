begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* TI COFF information for Texas Instruments TMS320C54X.    This file customizes the settings in coff/ti.h.         Copyright 2000, 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COFF_TIC54X_H
end_ifndef

begin_define
define|#
directive|define
name|COFF_TIC54X_H
end_define

begin_define
define|#
directive|define
name|TIC54X_TARGET_ID
value|0x98
end_define

begin_define
define|#
directive|define
name|TIC54XALGMAGIC
value|0x009B
end_define

begin_comment
comment|/* c54x algebraic assembler output */
end_comment

begin_define
define|#
directive|define
name|TIC5X_TARGET_ID
value|0x92
end_define

begin_define
define|#
directive|define
name|TI_TARGET_ID
value|TIC54X_TARGET_ID
end_define

begin_define
define|#
directive|define
name|OCTETS_PER_BYTE_POWER
value|1
end_define

begin_comment
comment|/* octets per byte, as a power of two */
end_comment

begin_define
define|#
directive|define
name|HOWTO_BANK
value|6
end_define

begin_comment
comment|/* add to howto to get absolute/sect-relative version */
end_comment

begin_define
define|#
directive|define
name|TICOFF_TARGET_ARCH
value|bfd_arch_tic54x
end_define

begin_define
define|#
directive|define
name|TICOFF_DEFAULT_MAGIC
value|TICOFF1MAGIC
end_define

begin_comment
comment|/* we use COFF1 for compatibility */
end_comment

begin_comment
comment|/* Page macros     The first GDB port requires flags in its remote memory access commands to    distinguish between data/prog space.  Hopefully we can make this go away    eventually.  Stuff the page in the upper bits of a 32-bit address, since    the c5x family only uses 16 or 23 bits.     c2x, c5x and most c54x devices have 16-bit addresses, but the c548 has    23-bit program addresses.  Make sure the page flags don't interfere.    These flags are used by GDB to identify the destination page for    addresses.  */
end_comment

begin_comment
comment|/* Recognized load pages (by common convention).  */
end_comment

begin_define
define|#
directive|define
name|PG_PROG
value|0x0
end_define

begin_comment
comment|/* PROG page */
end_comment

begin_define
define|#
directive|define
name|PG_DATA
value|0x1
end_define

begin_comment
comment|/* DATA page */
end_comment

begin_define
define|#
directive|define
name|PG_IO
value|0x2
end_define

begin_comment
comment|/* I/O page */
end_comment

begin_comment
comment|/** Indicate whether the given storage class requires a page flag.  */
end_comment

begin_define
define|#
directive|define
name|NEEDS_PAGE
parameter_list|(
name|X
parameter_list|)
value|((X)==C_EXT)
end_define

begin_define
define|#
directive|define
name|PAGE_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|ADDR_MASK
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|PG_TO_FLAG
parameter_list|(
name|p
parameter_list|)
value|(((unsigned long)(p)& 0xFF)<< 24)
end_define

begin_define
define|#
directive|define
name|FLAG_TO_PG
parameter_list|(
name|f
parameter_list|)
value|(((f)>> 24)& 0xFF)
end_define

begin_include
include|#
directive|include
file|"coff/ti.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COFF_TIC54X_H */
end_comment

end_unit

