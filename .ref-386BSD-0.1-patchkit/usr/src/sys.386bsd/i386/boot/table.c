begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Ported to boot 386BSD by Julian Elischer (julian@tfs.com) Sept 1992  *  * Mach Operating System  * Copyright (c) 1992, 1991 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * HISTORY  * $Log:	table.c,v $  * Revision 2.2  92/04/04  11:36:43  rpd  * 	Fix Intel Copyright as per B. Davies authorization.  * 	[92/04/03            rvb]  * 	Taken from 2.5 bootstrap.  * 	[92/03/30            rvb]  *   * Revision 2.2  91/04/02  14:42:22  mbj  * 	Add Intel copyright  * 	[90/02/09            rvb]  *   */
end_comment

begin_comment
comment|/*   Copyright 1988, 1989, 1990, 1991, 1992     by Intel Corporation, Santa Clara, California.                  All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appears in all copies and that both the copyright notice and this permission notice appear in supporting documentation, and that the name of Intel not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  INTEL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL INTEL BE LIABLE FOR ANY SPECIAL, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN ACTION OF CONTRACT, NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. */
end_comment

begin_define
define|#
directive|define
name|NGDTENT
value|6
end_define

begin_define
define|#
directive|define
name|GDTLIMIT
value|48
end_define

begin_comment
comment|/* NGDTENT * 8 */
end_comment

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
name|bit_15_8
decl_stmt|;
name|unsigned
name|char
name|bit_23_16
decl_stmt|;
name|unsigned
name|char
name|base_31_24
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|seg_desc
name|Gdt
index|[
name|NGDTENT
index|]
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
block|{
literal|0xFFFF
block|,
literal|0x0000
block|,
literal|0x9
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
literal|0x0000
block|,
literal|0x9
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
literal|0x0000
block|,
literal|0x9
block|,
literal|0x9E
block|,
literal|0x0
block|,
literal|0x0
block|}
comment|/* 0x28 : boot code, 16 bits */
block|}
decl_stmt|;
end_decl_stmt

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
name|GDTLIMIT
block|,
literal|0x0400
block|,
literal|9
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pseudo_desc
name|Gdtr2
init|=
block|{
name|GDTLIMIT
block|,
literal|0xfe00
block|,
literal|9
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* boot is loaded at 0x90000, Gdt is at boot+1024 */
end_comment

end_unit

