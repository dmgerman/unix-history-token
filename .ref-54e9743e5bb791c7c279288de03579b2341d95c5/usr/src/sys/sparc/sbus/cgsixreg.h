begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)cgsixreg.h	8.4 (Berkeley) %G%  *  * from: $Header: cgsixreg.h,v 1.1 93/10/12 15:29:24 torek Exp $  */
end_comment

begin_comment
comment|/*  * CG6 display registers.  (Note, I got tired of writing `cgsix' about  * halfway through and changed everything to cg6, but I probably missed  * some.  Unfortunately, the way config works, we need to spell out `six'  * in some places anyway.)  *  * The cg6 is a complicated beastie.  We have been unable to extract any  * documentation and most of the following are guesses based on a limited  * amount of reverse engineering.  *  * A cg6 is composed of numerous groups of control registers, all with TLAs:  *	FBC - frame buffer control?  *	FHC - fbc hardware configuration / control? register (32 bits)  *	DHC - ???  *	TEC - transform engine control?  *	THC - TEC Hardware Configuration  *	ROM - a 64Kbyte ROM with who knows what in it.  *	colormap - see below  *	frame buffer memory (video RAM)  *	possible other stuff  *  * Like the cg3, the cg6 uses a Brooktree Video DAC (see btreg.h).  *  * Various revisions of the cgsix have various hardware bugs.  So far,  * we have only seen rev 1& 2.  */
end_comment

begin_comment
comment|/* bits in FHC register */
end_comment

begin_define
define|#
directive|define
name|FHC_FBID_MASK
value|0xff000000
end_define

begin_comment
comment|/* bits 24..31 are frame buffer ID */
end_comment

begin_define
define|#
directive|define
name|FHC_FBID_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FHC_REV_MASK
value|0x00f00000
end_define

begin_comment
comment|/* bits 20..23 are revision */
end_comment

begin_define
define|#
directive|define
name|FHC_REV_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|FHC_FROP_DISABLE
value|0x00080000
end_define

begin_comment
comment|/* disable fast/font? rasterops */
end_comment

begin_define
define|#
directive|define
name|FHC_ROW_DISABLE
value|0x00040000
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|FHC_SRC_DISABLE
value|0x00020000
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|FHC_DST_DISABLE
value|0x00010000
end_define

begin_comment
comment|/* disable destination cache */
end_comment

begin_define
define|#
directive|define
name|FHC_RESET
value|0x00008000
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|FHC_XXX0
value|0x00004000
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|FHC_LEBO
value|0x00002000
end_define

begin_comment
comment|/* set little endian byte order? */
end_comment

begin_define
define|#
directive|define
name|FHC_RES_MASK
value|0x00001800
end_define

begin_comment
comment|/* bits 11&12 are resolution */
end_comment

begin_define
define|#
directive|define
name|FHC_RES_1024
value|0x00000000
end_define

begin_comment
comment|/* res = 1024x768 */
end_comment

begin_define
define|#
directive|define
name|FHC_RES_1152
value|0x00000800
end_define

begin_comment
comment|/* res = 1152x900 */
end_comment

begin_define
define|#
directive|define
name|FHC_RES_1280
value|0x00001000
end_define

begin_comment
comment|/* res = 1280x1024 */
end_comment

begin_define
define|#
directive|define
name|FHC_RES_1600
value|0x00001800
end_define

begin_comment
comment|/* res = 1600x1200 */
end_comment

begin_define
define|#
directive|define
name|FHC_CPU_MASK
value|0x00000600
end_define

begin_comment
comment|/* bits 9&10 are cpu type */
end_comment

begin_define
define|#
directive|define
name|FHC_CPU_SPARC
value|0x00000000
end_define

begin_comment
comment|/* cpu = sparc */
end_comment

begin_define
define|#
directive|define
name|FHC_CPU_68020
value|0x00000200
end_define

begin_comment
comment|/* cpu = 68020 */
end_comment

begin_define
define|#
directive|define
name|FHC_CPU_386
value|0x00000400
end_define

begin_comment
comment|/* cpu = 80386 */
end_comment

begin_define
define|#
directive|define
name|FHC_CPU_XXX
value|0x00000600
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|FHC_TEST
value|0x00000100
end_define

begin_comment
comment|/* ??? test window ??? */
end_comment

begin_define
define|#
directive|define
name|FHC_TESTX_MASK
value|0x000000f0
end_define

begin_comment
comment|/* bits 4..7 are test window X */
end_comment

begin_define
define|#
directive|define
name|FHC_TESTX_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|FHC_TESTY_MASK
value|0x0000000f
end_define

begin_comment
comment|/* bits 0..3 are test window Y */
end_comment

begin_define
define|#
directive|define
name|FHC_TESTY_SHIFT
value|0
end_define

begin_comment
comment|/*  * The layout of the THC.  */
end_comment

begin_struct
struct|struct
name|cg6_thc
block|{
name|u_int
name|thc_xxx0
index|[
literal|512
index|]
decl_stmt|;
comment|/* ??? */
name|u_int
name|thc_hsync1
decl_stmt|;
comment|/* horizontal sync timing */
name|u_int
name|thc_hsync2
decl_stmt|;
comment|/* more hsync timing */
name|u_int
name|thc_hsync3
decl_stmt|;
comment|/* yet more hsync timing */
name|u_int
name|thc_vsync1
decl_stmt|;
comment|/* vertical sync timing */
name|u_int
name|thc_vsync2
decl_stmt|;
comment|/* only two of these */
name|u_int
name|thc_refresh
decl_stmt|;
comment|/* refresh counter */
name|u_int
name|thc_misc
decl_stmt|;
comment|/* miscellaneous control& status */
name|u_int
name|thc_xxx1
index|[
literal|56
index|]
decl_stmt|;
comment|/* ??? */
name|u_int
name|thc_cursxy
decl_stmt|;
comment|/* cursor x,y position (16 bits each) */
name|u_int
name|thc_cursmask
index|[
literal|32
index|]
decl_stmt|;
comment|/* cursor mask bits */
name|u_int
name|thc_cursbits
index|[
literal|32
index|]
decl_stmt|;
comment|/* what to show where mask enabled */
block|}
struct|;
end_struct

begin_comment
comment|/* bits in thc_misc */
end_comment

begin_define
define|#
directive|define
name|THC_MISC_XXX0
value|0xfff00000
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|THC_MISC_REVMASK
value|0x000f0000
end_define

begin_comment
comment|/* cg6 revision? */
end_comment

begin_define
define|#
directive|define
name|THC_MISC_REVSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|THC_MISC_XXX1
value|0x0000e000
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|THC_MISC_RESET
value|0x00001000
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|THC_MISC_XXX2
value|0x00000800
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|THC_MISC_VIDEN
value|0x00000400
end_define

begin_comment
comment|/* video enable */
end_comment

begin_define
define|#
directive|define
name|THC_MISC_SYNC
value|0x00000200
end_define

begin_comment
comment|/* not sure what ... */
end_comment

begin_define
define|#
directive|define
name|THC_MISC_VSYNC
value|0x00000100
end_define

begin_comment
comment|/* ... these really are */
end_comment

begin_define
define|#
directive|define
name|THC_MISC_SYNCEN
value|0x00000080
end_define

begin_comment
comment|/* sync enable */
end_comment

begin_define
define|#
directive|define
name|THC_MISC_CURSRES
value|0x00000040
end_define

begin_comment
comment|/* cursor resolution */
end_comment

begin_define
define|#
directive|define
name|THC_MISC_INTEN
value|0x00000020
end_define

begin_comment
comment|/* v.retrace intr enable */
end_comment

begin_define
define|#
directive|define
name|THC_MISC_INTR
value|0x00000010
end_define

begin_comment
comment|/* intr pending / ack bit */
end_comment

begin_define
define|#
directive|define
name|THC_MISC_XXX
value|0x0000000f
end_define

begin_comment
comment|/* ??? */
end_comment

begin_comment
comment|/* cursor x / y position value for `off' */
end_comment

begin_define
define|#
directive|define
name|THC_CURSOFF
value|(65536-32)
end_define

begin_comment
comment|/* i.e., USHRT_MAX+1-32 */
end_comment

begin_comment
comment|/*  * Partial description of TEC (needed to get around FHC rev 1 bugs).  */
end_comment

begin_struct
struct|struct
name|cg6_tec_xxx
block|{
name|u_int
name|tec_mv
decl_stmt|;
comment|/* matrix stuff */
name|u_int
name|tec_clip
decl_stmt|;
comment|/* clipping stuff */
name|u_int
name|tec_vdc
decl_stmt|;
comment|/* ??? */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure exists only to compute the layout of the CG6  * hardware.  Each of the individual substructures lives on a  * separate `page' (where a `page' is at least 4K), and many are  * very far apart.  We avoid large offsets (which make for lousy  * code) by using pointers to the individual interesting pieces,  * and map them in independently (to avoid using up PTEs unnecessarily).  */
end_comment

begin_struct
struct|struct
name|cg6_layout
block|{
comment|/* ROM at 0 */
union|union
block|{
name|long
name|un_id
decl_stmt|;
comment|/* ID = ?? */
name|char
name|un_rom
index|[
literal|65536
index|]
decl_stmt|;
comment|/* 64K rom */
name|char
name|un_pad
index|[
literal|0x200000
index|]
decl_stmt|;
block|}
name|cg6_rom_un
union|;
comment|/* Brooktree DAC at 0x200000 */
union|union
block|{
name|struct
name|bt_regs
name|un_btregs
decl_stmt|;
name|char
name|un_pad
index|[
literal|0x040000
index|]
decl_stmt|;
block|}
name|cg6_bt_un
union|;
comment|/* DHC, whatever that is, at 0x240000 */
union|union
block|{
name|char
name|un_pad
index|[
literal|0x40000
index|]
decl_stmt|;
block|}
name|cg6_dhc_un
union|;
comment|/* ALT, whatever that is, at 0x280000 */
union|union
block|{
name|char
name|un_pad
index|[
literal|0x80000
index|]
decl_stmt|;
block|}
name|cg6_alt_un
union|;
comment|/* FHC register at 0x300000 */
union|union
block|{
name|int
name|un_fhc
decl_stmt|;
name|char
name|un_pad
index|[
literal|0x1000
index|]
decl_stmt|;
block|}
name|cg6_fhc_un
union|;
comment|/* THC at 0x301000 */
union|union
block|{
name|struct
name|cg6_thc
name|un_thc
decl_stmt|;
name|char
name|un_pad
index|[
literal|0x400000
operator|-
literal|0x1000
index|]
decl_stmt|;
block|}
name|cg6_thc_un
union|;
comment|/* FBC at 0x700000 */
union|union
block|{
name|char
name|un_pad
index|[
literal|0x1000
index|]
decl_stmt|;
block|}
name|cg6_fbc_un
union|;
comment|/* TEC at 0x701000 */
union|union
block|{
name|char
name|un_pad
index|[
literal|0x100000
operator|-
literal|0x1000
index|]
decl_stmt|;
name|struct
name|cg6_tec_xxx
name|un_tec
decl_stmt|;
block|}
name|cg6_tec_un
union|;
comment|/* Video RAM at 0x800000 */
name|char
name|cg6_ram
index|[
literal|1024
operator|*
literal|1024
index|]
decl_stmt|;
comment|/* approx.? */
block|}
struct|;
end_struct

end_unit

