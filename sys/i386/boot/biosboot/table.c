begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Mach Operating System  * Copyright (c) 1992, 1991 Carnegie Mellon University  * All Rights Reserved.  *  * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  *  *	from: Mach, Revision 2.2  92/04/04  11:36:43  rpd  * $FreeBSD$  */
end_comment

begin_comment
comment|/*   Copyright 1988, 1989, 1990, 1991, 1992    by Intel Corporation, Santa Clara, California.                  All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appears in all copies and that both the copyright notice and this permission notice appear in supporting documentation, and that the name of Intel not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  INTEL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL INTEL BE LIABLE FOR ANY SPECIAL, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN ACTION OF CONTRACT, NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. */
end_comment

begin_include
include|#
directive|include
file|"boot.h"
end_include

begin_comment
comment|/*  Segment Descriptor  *  * 31          24         19   16                 7           0  * ------------------------------------------------------------  * |             | |B| |A|       | |   |1|0|E|W|A|            |  * | BASE 31..24 |G|/|0|V| LIMIT |P|DPL|  TYPE   | BASE 23:16 |  * |             | |D| |L| 19..16| |   |1|1|C|R|A|            |  * ------------------------------------------------------------  * |                             |                            |  * |        BASE 15..0           |       LIMIT 15..0          |  * |                             |                            |  * ------------------------------------------------------------  */
end_comment

begin_struct
struct|struct
name|seg_desc
block|{
name|unsigned
name|short
name|limit_15_0
decl_stmt|;
name|unsigned
name|short
name|base_15_0
decl_stmt|;
name|unsigned
name|char
name|base_23_16
decl_stmt|;
name|unsigned
name|char
name|p_dpl_type
decl_stmt|;
name|unsigned
name|char
name|g_b_a_limit
decl_stmt|;
name|unsigned
name|char
name|base_31_24
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RUN
value|0
end_define

begin_comment
comment|/* not really 0, but filled in at boot time */
end_comment

begin_decl_stmt
name|struct
name|seg_desc
name|Gdt
index|[]
init|=
block|{
block|{
literal|0x0
block|,
literal|0x0
block|,
literal|0x0
block|,
literal|0x0
block|,
literal|0x0
block|,
literal|0x0
block|}
block|,
comment|/* 0x0 : null */
block|{
literal|0xFFFF
block|,
literal|0x0
block|,
literal|0x0
block|,
literal|0x9F
block|,
literal|0xCF
block|,
literal|0x0
block|}
block|,
comment|/* 0x08 : kernel code */
comment|/* 0x9E? */
block|{
literal|0xFFFF
block|,
literal|0x0
block|,
literal|0x0
block|,
literal|0x93
block|,
literal|0xCF
block|,
literal|0x0
block|}
block|,
comment|/* 0x10 : kernel data */
comment|/* 0x92? */
block|{
literal|0xFFFF
block|,
name|RUN
block|,
name|RUN
block|,
literal|0x9E
block|,
literal|0x40
block|,
literal|0x0
block|}
block|,
comment|/* 0x18 : boot code */
block|{
literal|0xFFFF
block|,
name|RUN
block|,
name|RUN
block|,
literal|0x92
block|,
literal|0x40
block|,
literal|0x0
block|}
block|,
comment|/* 0x20 : boot data */
block|{
literal|0xFFFF
block|,
name|RUN
block|,
name|RUN
block|,
literal|0x9E
block|,
literal|0x0
block|,
literal|0x0
block|}
block|,
comment|/* 0x28 : boot code, 16 bits */
block|{
literal|0xFFFF
block|,
literal|0x0
block|,
literal|0x0
block|,
literal|0x92
block|,
literal|0x0
block|,
literal|0x0
block|}
block|,
comment|/* 0x30 : boot data, 16 bits */
ifdef|#
directive|ifdef
name|BDE_DEBUGGER
comment|/* More for bdb. */
block|{}
block|,
comment|/* BIOS_TMP_INDEX = 7 : null */
block|{}
block|,
comment|/* TSS_INDEX = 8 : null */
block|{
literal|0xFFFF
block|,
literal|0x0
block|,
literal|0x0
block|,
literal|0xB2
block|,
literal|0x40
block|,
literal|0x0
block|}
block|,
comment|/* DS_286_INDEX = 9 */
block|{
literal|0xFFFF
block|,
literal|0x0
block|,
literal|0x0
block|,
literal|0xB2
block|,
literal|0x40
block|,
literal|0x0
block|}
block|,
comment|/* ES_286_INDEX = 10 */
block|{}
block|,
comment|/* Unused = 11 : null */
block|{
literal|0x7FFF
block|,
literal|0x8000
block|,
literal|0xB
block|,
literal|0xB2
block|,
literal|0x40
block|,
literal|0x0
block|}
block|,
comment|/* COLOR_INDEX = 12 */
block|{
literal|0x7FFF
block|,
literal|0x0
block|,
literal|0xB
block|,
literal|0xB2
block|,
literal|0x40
block|,
literal|0x0
block|}
block|,
comment|/* MONO_INDEX = 13 */
block|{
literal|0xFFFF
block|,
name|RUN
block|,
name|RUN
block|,
literal|0x9A
block|,
literal|0x40
block|,
literal|0x0
block|}
block|,
comment|/* DB_CS_INDEX = 14 */
block|{
literal|0xFFFF
block|,
name|RUN
block|,
name|RUN
block|,
literal|0x9A
block|,
literal|0x0
block|,
literal|0x0
block|}
block|,
comment|/* DB_CS16_INDEX = 15 */
block|{
literal|0xFFFF
block|,
name|RUN
block|,
name|RUN
block|,
literal|0x92
block|,
literal|0x40
block|,
literal|0x0
block|}
block|,
comment|/* DB_DS_INDEX = 16 */
block|{
literal|8
operator|*
literal|18
operator|-
literal|1
block|,
name|RUN
block|,
name|RUN
block|,
literal|0x92
block|,
literal|0x40
block|,
literal|0x0
block|}
block|,
comment|/* GDT_INDEX = 17 */
endif|#
directive|endif
comment|/* BDE_DEBUGGER */
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BDE_DEBUGGER
end_ifdef

begin_struct
struct|struct
name|idt_desc
block|{
name|unsigned
name|short
name|entry_15_0
decl_stmt|;
name|unsigned
name|short
name|selector
decl_stmt|;
name|unsigned
name|char
name|padding
decl_stmt|;
name|unsigned
name|char
name|p_dpl_type
decl_stmt|;
name|unsigned
name|short
name|entry_31_16
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|idt_desc
name|Idt
index|[]
init|=
block|{
block|{}
block|,
comment|/* Null (int 0) */
block|{
name|RUN
block|,
literal|0x70
block|,
literal|0
block|,
literal|0x8E
block|,
literal|0
block|}
block|,
comment|/* DEBUG_VECTOR = 1 */
block|{}
block|,
comment|/* Null (int 2) */
block|{
name|RUN
block|,
literal|0x70
block|,
literal|0
block|,
literal|0xEE
block|,
literal|0
block|}
block|,
comment|/* BREAKPOINT_VECTOR = 3 */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BDE_DEBUGGER */
end_comment

begin_struct
struct|struct
name|pseudo_desc
block|{
name|unsigned
name|short
name|limit
decl_stmt|;
name|unsigned
name|short
name|base_low
decl_stmt|;
name|unsigned
name|short
name|base_high
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|pseudo_desc
name|Gdtr
init|=
block|{
sizeof|sizeof
name|Gdt
operator|-
literal|1
block|,
name|RUN
block|,
name|RUN
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BDE_DEBUGGER
end_ifdef

begin_decl_stmt
name|struct
name|pseudo_desc
name|Idtr_prot
init|=
block|{
sizeof|sizeof
name|Idt
operator|-
literal|1
block|,
name|RUN
block|,
name|RUN
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pseudo_desc
name|Idtr_real
init|=
block|{
literal|0x400
operator|-
literal|1
block|,
literal|0x0
block|,
literal|0x0
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * All initialized data is defined in one file to reduce space wastage from  * fragmentation.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|devs
index|[]
init|=
block|{
literal|"wd"
block|,
literal|"dk"
block|,
literal|"fd"
block|,
literal|"wt"
block|,
literal|"da"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|tw_chars
init|=
literal|0x5C2D2F7C
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "\-/|" */
end_comment

end_unit

