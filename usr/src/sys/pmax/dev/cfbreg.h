begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)cfbreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1991,1990,1989 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * HISTORY  * $Log:	bt459.h,v $  * Revision 2.4  91/02/05  17:39:43  mrt  * 	Added author notices  * 	[91/02/04  11:11:57  mrt]  *   * 	Changed to use new Mach copyright  * 	[91/02/02  12:09:39  mrt]  *   * Revision 2.3  90/12/05  23:30:26  af  * 	Cursor color register are supported, contrary to specs.  * 	[90/12/03  23:07:22  af]  *   * Revision 2.1.1.1  90/11/01  03:36:40  af  * 	Created, from Brooktree specs:  * 	"Product Databook 1989"  * 	"Bt459 135 MHz Monolithic CMOS 256x64 Color Palette RAMDAC"  * 	Brooktree Corp. San Diego, CA  * 	LA59001 Rev. J  * 	[90/09/03            af]  */
end_comment

begin_comment
comment|/*  *	File: bt459.h  * 	Author: Alessandro Forin, Carnegie Mellon University  *	Date:	9/90  *  *	Defines for the bt459 Cursor/RAMDAC chip  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|addr_lo
decl_stmt|;
name|char
name|pad0
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|char
name|addr_hi
decl_stmt|;
name|char
name|pad1
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|char
name|addr_reg
decl_stmt|;
name|char
name|pad2
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|char
name|addr_cmap
decl_stmt|;
name|char
name|pad3
index|[
literal|3
index|]
decl_stmt|;
block|}
name|bt459_regmap_t
typedef|;
end_typedef

begin_comment
comment|/*  * Additional registers addressed indirectly  */
end_comment

begin_comment
comment|/* 0000-00ff Color Map entries */
end_comment

begin_comment
comment|/* 0100-010f Overlay color regs, unsupp */
end_comment

begin_define
define|#
directive|define
name|BT459_REG_CCOLOR_1
value|0x0181
end_define

begin_comment
comment|/* Cursor color regs */
end_comment

begin_define
define|#
directive|define
name|BT459_REG_CCOLOR_2
value|0x0182
end_define

begin_define
define|#
directive|define
name|BT459_REG_CCOLOR_3
value|0x0183
end_define

begin_define
define|#
directive|define
name|BT459_REG_ID
value|0x0200
end_define

begin_comment
comment|/* read-only, gives "4a" */
end_comment

begin_define
define|#
directive|define
name|BT459_REG_CMD0
value|0x0201
end_define

begin_define
define|#
directive|define
name|BT459_REG_CMD1
value|0x0202
end_define

begin_define
define|#
directive|define
name|BT459_REG_CMD2
value|0x0203
end_define

begin_define
define|#
directive|define
name|BT459_REG_PRM
value|0x0204
end_define

begin_comment
comment|/* 0205 reserved */
end_comment

begin_define
define|#
directive|define
name|BT459_REG_PBM
value|0x0206
end_define

begin_comment
comment|/* 0207 reserved */
end_comment

begin_define
define|#
directive|define
name|BT459_REG_ORM
value|0x0208
end_define

begin_define
define|#
directive|define
name|BT459_REG_OBM
value|0x0209
end_define

begin_define
define|#
directive|define
name|BT459_REG_ILV
value|0x020a
end_define

begin_define
define|#
directive|define
name|BT459_REG_TEST
value|0x020b
end_define

begin_define
define|#
directive|define
name|BT459_REG_RSIG
value|0x020c
end_define

begin_define
define|#
directive|define
name|BT459_REG_GSIG
value|0x020d
end_define

begin_define
define|#
directive|define
name|BT459_REG_BSIG
value|0x020e
end_define

begin_comment
comment|/* 020f-02ff reserved */
end_comment

begin_define
define|#
directive|define
name|BT459_REG_CCR
value|0x0300
end_define

begin_define
define|#
directive|define
name|BT459_REG_CXLO
value|0x0301
end_define

begin_define
define|#
directive|define
name|BT459_REG_CXHI
value|0x0302
end_define

begin_define
define|#
directive|define
name|BT459_REG_CYLO
value|0x0303
end_define

begin_define
define|#
directive|define
name|BT459_REG_CYHI
value|0x0304
end_define

begin_define
define|#
directive|define
name|BT459_REG_WXLO
value|0x0305
end_define

begin_define
define|#
directive|define
name|BT459_REG_WXHI
value|0x0306
end_define

begin_define
define|#
directive|define
name|BT459_REG_WYLO
value|0x0307
end_define

begin_define
define|#
directive|define
name|BT459_REG_WYHI
value|0x0308
end_define

begin_define
define|#
directive|define
name|BT459_REG_WWLO
value|0x0309
end_define

begin_define
define|#
directive|define
name|BT459_REG_WWHI
value|0x030a
end_define

begin_define
define|#
directive|define
name|BT459_REG_WHLO
value|0x030b
end_define

begin_define
define|#
directive|define
name|BT459_REG_WHHI
value|0x030c
end_define

begin_comment
comment|/* 030d-03ff reserved */
end_comment

begin_define
define|#
directive|define
name|BT459_REG_CRAM_BASE
value|0x0400
end_define

begin_define
define|#
directive|define
name|BT459_REG_CRAM_END
value|0x07ff
end_define

end_unit

