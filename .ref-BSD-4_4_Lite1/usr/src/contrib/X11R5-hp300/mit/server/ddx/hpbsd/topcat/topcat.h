begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright (c) 1986, 1987 by Hewlett-Packard Company Copyright (c) 1986, 1987 by the Massachusetts Institute of Technology  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  HEWLETT-PACKARD MAKES NO WARRANTY OF ANY KIND WITH REGARD TO THIS SOFWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE.  Hewlett-Packard shall not be liable for errors  contained herein or direct, indirect, special, incidental or  consequential damages in connection with the furnishing,  performance, or use of this material.  This software is not subject to any license of the American Telephone and Telegraph Company or of the Regents of the University of California.  */
end_comment

begin_if
if|#
directive|if
name|RCSID
operator|&&
name|IN_MAIN
end_if

begin_decl_stmt
specifier|static
name|char
modifier|*
name|trcsid
init|=
literal|"$XConsortium: topcat.h,v 1.4 88/09/06 15:22:02 jim Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSID
end_endif

begin_comment
comment|/*  *  topcat.h	- access to topcat chip  *  *  This module is part of the low-level graphics primitives   *  for the Hewlett-Packard 9000 Series 300.  *  *  Hewlett-Packard Instrument Systems Lab - Loveland, Colorado  *  *  (c) Copyright 1986 Hewlett-Packard Company.  All rights are  *  reserved.  Copying or other reproduction of the program except  *  for archival purposes is prohibited without prior written  *  consent of Hewlett-Packard Company.  *  * $Log: topcat.h,v $  * Revision 1.1  1992/09/30  03:20:46  root  * Initial revision  *  * Revision 1.2  89/02/15  19:54:23  stoller  * hpbsd change: Add id_second field to topcat struct so we can determine  * if we are running on a Catseye or Topcat.  * gcc change: waitbusy loop was being optimized away.  *   * Revision 1.1  89/01/16  15:15:36  stoller  * Initial revision  *   * Revision 1.4  88/09/06  15:22:02  jim  * XConsortium  *   * Revision 1.3  88/08/17  13:40:20  jim  * new version from hp  *   * Revision 1.10  88/01/27  15:58:17  15:58:17  harry (Harry Phinney)  * added extern decleration of tcPolyOptText()  *   * Revision 1.9  88/01/12  16:40:38  16:40:38  harry (Harry Phinney)  * Change for optimized variable width fonts  *   * Revision 1.8  87/12/21  17:57:21  17:57:21  harry (Harry Phinney)  * Merging with MIT sources  *   *   * Revision 1.1  87/12/16  13:35:00  hp  * Initial revision  *   * Revision 1.1  87/12/14  14:48:02  hp  * Initial revision  *   * Revision 1.7  87/12/02 17:14:08 GMT  harry  * Added extern declarations for the text and rectangle fill functions  *   * Revision 1.6  87/11/29  12:58:54  12:58:54  harry (Harry Phinney)  * Parameterized waitbusy for gp_hardware& surrounded both params w/ parens  *   * Revision 1.5  87/11/04  14:30:12  14:30:12  andreas (Jim Andreas)  * graphics.h is doubly included (by topcat.h and topcat.c)  * removed include of graphics.h  *   * Revision 1.4  87/10/26  14:55:38  14:55:38  bennett  * HP frame buffer reorg;  *   * Revision 1.3  87/10/20  11:56:53  11:56:53  leichner (Robert C. Leichner)  * Made topcatMover an extern procedure.  *   * Revision 1.2  87/10/08  15:24:13  15:24:13  bennett  * Define some new macros to reach into the bowels of the screen and pull  * out some hardware specific into;  *   * Revision 1.1  87/09/22  18:04:56  18:04:56  leichner (Robert C. Leichner)  * Initial revision  *   * Revision 3.4  87/09/14  18:11:06  18:11:06  leichner (Robert C. Leichner)  * Use new definition for screen->devPrivate and no longer use screens  * array.  *   * Revision 3.3  87/09/03  14:30:31  14:30:31  leichner (Robert C. Leichner)  * Moved several defines into .h file. Also added extern declarations  * from topcat.c. Externs are used by topcatgc.c.  *   * Revision 3.2  87/08/31  12:20:00  12:20:00  leichner (Robert C. Leichner)  * Assorted fixes to allow multiple screens.   * Also eliminated extra parameter in topcatUninstallColormap.  *   * Revision 3.1  87/08/28  17:07:32  17:07:32  leichner (Robert C. Leichner)  * consolidated device dependant info in a single structure.  *   * Revision 3.0  87/08/12  16:15:08  16:15:08  bennett  * beta 3.0  *   * Revision 1.1  87/07/02  10:10:25  bennett  * Initial revision  *   * Revision 1.1  87/06/01  10:16:32  10:16:32  palevich (John H. Palevich)  * Initial revision  *   * Revision 1.2  86/08/20  13:06:40  13:06:40  dan ()  * Checkpoint before output speed optimization.  *   * Revision 1.1  86/07/22  16:37:55  16:37:55  dan ()  * Initial revision  *   * Revision 1.2  86/07/17  07:33:37  07:33:37  dan ()  * Fix the replacement rule locations.  * .,  *   * Revision 1.1  86/06/04  12:34:01  12:34:01  dan ()  * Initial revision  *   * Revision 1.4  86/04/03  10:21:13  tw  * Checkpoint before revising to use bufalloc.  *   * Revision 1.3  86/04/01  15:45:02  tw  * Finally got colormap hardware registers mapped correctly.  *   * Revision 1.2  86/03/04  17:26:32  tw  * Changed replacement rules to be u_chars instead of u_shorts.  *   * Revision 1.1  86/02/27  16:05:14  tw  * Initial revision  *   *   */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * list of topcat external procedures  */
end_comment

begin_function_decl
specifier|extern
name|RegionPtr
name|tcCopyPlane
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcFillBoxSoild
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcPolyFillRect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcWholeGlyph
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcImageVarGlyph
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcImageGlyphBlt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcPutImage
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcSolidFS
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcPaintWindow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|topcatCreateGC
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcImageOptTEText8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcImageOptText8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tcPolyOptText8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcPolyFillStippledRect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|topcatZeroLine
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|topcatZeroDash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|topcatInstallColormap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|topcatUninstallColormap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|topcatListInstalledColormaps
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|topcatStoreColors
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|topcatResolvePseudoColor
parameter_list|()
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"../hpDisplays.h"
end_include

begin_comment
comment|/*  * Map of the topcat chip in memory ...  */
end_comment

begin_typedef
typedef|typedef
name|VOLATILE
struct|struct
block|{
name|u_short
name|id_reset
decl_stmt|;
comment|/* id and reset register 	*/
comment|/* 0x01 */
name|u_char
name|filler2
decl_stmt|;
name|u_char
name|interrupts
decl_stmt|;
comment|/* interrupts			*/
comment|/* 0x03 */
name|u_char
name|filler2a
decl_stmt|;
name|u_char
name|t_memwide
decl_stmt|;
comment|/* top half frame buf width	*/
comment|/* 0x05 */
name|u_char
name|filler2b
decl_stmt|;
name|u_char
name|b_memwide
decl_stmt|;
comment|/* bottom half frame buf width	*/
comment|/* 0x07 */
name|u_char
name|filler2c
decl_stmt|;
name|u_char
name|t_memhigh
decl_stmt|;
comment|/* top half frame buf height 	*/
comment|/* 0x09 */
name|u_char
name|filler2d
decl_stmt|;
name|u_char
name|b_memhigh
decl_stmt|;
comment|/* bot half frame buf height	*/
comment|/* 0x0b */
name|u_char
name|filler2e
decl_stmt|;
name|u_char
name|t_dispwide
decl_stmt|;
comment|/* top half display width	*/
comment|/* 0x0d */
name|u_char
name|filler2f
decl_stmt|;
name|u_char
name|b_dispwide
decl_stmt|;
comment|/* bot half display width	*/
comment|/* 0x0f */
name|u_char
name|filler2g
decl_stmt|;
name|u_char
name|t_disphigh
decl_stmt|;
comment|/* top half display height	*/
comment|/* 0x11 */
name|u_char
name|filler2h
decl_stmt|;
name|u_char
name|b_disphigh
decl_stmt|;
comment|/* bot half display height	*/
comment|/* 0x13 */
name|u_char
name|filler2i
decl_stmt|;
name|u_char
name|id_second
decl_stmt|;
comment|/* secondary id 5=LCC 6=HRC 	*/
comment|/* 0x15 */
name|u_char
name|filler2j
decl_stmt|;
comment|/* 7=HRM, 9=319X		*/
name|u_char
name|bits
decl_stmt|;
comment|/* 0 square pixels, 1 double hi */
comment|/* 0x17 */
if|#
directive|if
literal|1
name|u_char
name|filler3
index|[
literal|67
index|]
decl_stmt|;
else|#
directive|else
comment|/* catseye stuff */
name|u_char
name|filler2k
decl_stmt|;
name|u_char
name|byte_pixel
decl_stmt|;
comment|/* byte/pixel at powerup        */
comment|/* 0x19 */
name|u_char
name|filler2l
decl_stmt|;
name|u_char
name|id_crtc
decl_stmt|;
comment|/* CRTC ID IRIS                 */
comment|/* 0x1B */
name|u_char
name|filler2m
decl_stmt|;
name|u_char
name|rom_rev
decl_stmt|;
comment|/* rom revision                 */
comment|/* 0x1D */
name|u_char
name|filler3
index|[
literal|57
index|]
decl_stmt|;
name|u_char
name|t_cmapaddr
decl_stmt|;
comment|/* color map address (MSB)      */
comment|/* 0x57 */
name|u_char
name|filler2n
decl_stmt|;
name|u_char
name|b_cmapaddr
decl_stmt|;
comment|/* color map address (LSB)      */
comment|/* 0x59 */
name|u_char
name|filler2o
decl_stmt|;
endif|#
directive|endif
name|u_char
name|num_planes
decl_stmt|;
comment|/* number of color planes	*/
comment|/* 0x5b */
name|u_char
name|id_font
index|[
literal|16356
index|]
decl_stmt|;
comment|/* display id, font, ...	*/
comment|/* plane status registers (read only) at 0x0040*/
name|u_char
name|vert_blank
decl_stmt|;
comment|/* vertical blanking		*/
comment|/* 0x4040 */
name|u_char
name|filler01
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|move_active
decl_stmt|;
comment|/* window move active		*/
name|u_char
name|filler02
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|vert_request
decl_stmt|;
comment|/* vert retrace intr request	*/
name|u_char
name|filler03
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|move_request
decl_stmt|;
comment|/* window move intr request	*/
name|u_char
name|filler04
index|[
literal|51
index|]
decl_stmt|;
comment|/* plane control registers (read/write) at 0x0080 */
name|u_char
name|nblank
decl_stmt|;
comment|/* video output enable		*/
comment|/* 0x4080 */
name|u_char
name|filler4
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|enable_sync
decl_stmt|;
comment|/* sync enable			*/
name|u_char
name|filler5
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|write_enable
decl_stmt|;
comment|/* enable writes		*/
name|u_char
name|filler6
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|read_enable
decl_stmt|;
comment|/* enable reads			*/
name|u_char
name|filler7
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|frame_buf_write_enable
decl_stmt|;
comment|/* frame buffer write enable	*/
name|u_char
name|filler8
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|vert_enable
decl_stmt|;
comment|/* vertical retrace int enable	*/
name|u_char
name|filler9
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|move_enable
decl_stmt|;
comment|/* window move interrupt enable */
name|u_char
name|filler10
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|start_move
decl_stmt|;
comment|/* start window move		*/
name|u_char
name|filler11
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|blink
decl_stmt|;
comment|/* blink control		*/
name|u_char
name|filler12
index|[
literal|11
index|]
decl_stmt|;
name|u_char
name|cursor_on
decl_stmt|;
comment|/* turn cursor on		*/
name|u_char
name|filler13
index|[
literal|61
index|]
decl_stmt|;
comment|/* raster op control registers (read/write, word wide) at 0x00ea */
name|u_char
name|pixel_write_replacement_rule
decl_stmt|;
comment|/* 0x40ea */
name|u_char
name|fillerA
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|window_move_replacement_rule
decl_stmt|;
comment|/* this is 0x40ef */
name|u_char
name|fillerB
index|[
literal|1
index|]
decl_stmt|;
name|u_short
name|source_x
decl_stmt|;
name|u_short
name|fillerC
decl_stmt|;
name|u_short
name|source_y
decl_stmt|;
name|u_short
name|fillerD
decl_stmt|;
name|u_short
name|dest_x
decl_stmt|;
name|u_short
name|fillerE
decl_stmt|;
name|u_short
name|dest_y
decl_stmt|;
name|u_short
name|fillerF
decl_stmt|;
name|u_short
name|window_width
decl_stmt|;
name|u_short
name|fillerG
decl_stmt|;
name|u_short
name|window_height
decl_stmt|;
name|u_short
name|fillerH
decl_stmt|;
name|u_short
name|cursor_x
decl_stmt|;
name|u_short
name|fillerI
decl_stmt|;
name|u_short
name|cursor_y
decl_stmt|;
name|u_short
name|fillerJ
decl_stmt|;
name|u_short
name|cursor_length
decl_stmt|;
name|u_char
name|filler99
index|[
literal|7919
index|]
decl_stmt|;
comment|/* color map status (color systems only) at 0x2002 */
name|u_char
name|colormap_status
decl_stmt|;
comment|/* bit 2 set if RAM is busy	*/
comment|/* 0x6003 */
name|u_char
name|filler999
index|[
literal|172
index|]
decl_stmt|;
comment|/* color map registers (color systems only) at 0x20B2 */
comment|/* 0x60b2 */
name|u_short
name|filler1A
decl_stmt|;
name|u_short
name|red_data
decl_stmt|;
name|u_short
name|green_data
decl_stmt|;
name|u_short
name|blue_data
decl_stmt|;
name|u_short
name|color_index
decl_stmt|;
name|u_short
name|plane_mask
decl_stmt|;
name|u_char
name|filler1E
index|[
literal|52
index|]
decl_stmt|;
name|u_short
name|colormap_writestrobe
decl_stmt|;
block|}
name|TOPCAT
typedef|;
end_typedef

begin_comment
comment|/* additional info for topcat control. */
end_comment

begin_define
define|#
directive|define
name|IDREG
value|(0x1)
end_define

begin_define
define|#
directive|define
name|INTREG
value|(0x3)
end_define

begin_define
define|#
directive|define
name|RAI0
value|(0x23)
end_define

begin_define
define|#
directive|define
name|RAI1
value|(0x27)
end_define

begin_define
define|#
directive|define
name|RAI2
value|(0x2b)
end_define

begin_define
define|#
directive|define
name|RAI3
value|(0x2f)
end_define

begin_define
define|#
directive|define
name|TC_VIDEO_ON
value|0xff
end_define

begin_define
define|#
directive|define
name|TC_VIDEO_OFF
value|0x00
end_define

begin_comment
comment|/* private field for topcat display */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TOPCAT
modifier|*
name|topcatDev
decl_stmt|;
comment|/* pointer to device hardware */
name|ColormapPtr
name|InstalledMap
decl_stmt|;
comment|/* pointer to installed colormap */
name|void
function_decl|(
modifier|*
name|UpdateColormap
function_decl|)
parameter_list|()
function_decl|;
comment|/* cmap update differs for topcat& catseye */
block|}
name|topcatPriv
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|topcatPriv
modifier|*
name|topcatPrivPtr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|waitbusy
parameter_list|(
name|pMask
parameter_list|,
name|gp_hardware
parameter_list|)
define|\
value|while ((pMask)& (gp_hardware)->move_active) \ 			{ int i; for (i=0;i<20;i++); }
end_define

begin_define
define|#
directive|define
name|getTcHardware
parameter_list|(
name|pScreen
parameter_list|)
define|\
value|(((topcatPrivPtr) getPrivScreenPtr(pScreen)->pHardwareScreen)->topcatDev)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|GXclear
end_ifndef

begin_comment
comment|/* defines for replacement rules -- same as for X window system */
end_comment

begin_define
define|#
directive|define
name|GXclear
value|0x0
end_define

begin_comment
comment|/* 0 			*/
end_comment

begin_define
define|#
directive|define
name|GXand
value|0x1
end_define

begin_comment
comment|/* src AND dst 		*/
end_comment

begin_define
define|#
directive|define
name|GXandReverse
value|0x2
end_define

begin_comment
comment|/* src AND NOT dst	*/
end_comment

begin_define
define|#
directive|define
name|GXcopy
value|0x3
end_define

begin_comment
comment|/* src 			*/
end_comment

begin_define
define|#
directive|define
name|GXandInverted
value|0x4
end_define

begin_comment
comment|/* NOT src AND dst	*/
end_comment

begin_define
define|#
directive|define
name|GXnoop
value|0x5
end_define

begin_comment
comment|/* dst			*/
end_comment

begin_define
define|#
directive|define
name|GXxor
value|0x6
end_define

begin_comment
comment|/* src XOR dst		*/
end_comment

begin_define
define|#
directive|define
name|GXor
value|0x7
end_define

begin_comment
comment|/* src OR dst		*/
end_comment

begin_define
define|#
directive|define
name|GXnor
value|0x8
end_define

begin_comment
comment|/* NOT src AND NOT dst	*/
end_comment

begin_define
define|#
directive|define
name|GXequiv
value|0x9
end_define

begin_comment
comment|/* NOT src XOR dst	*/
end_comment

begin_define
define|#
directive|define
name|GXinvert
value|0xa
end_define

begin_comment
comment|/* NOT dst		*/
end_comment

begin_define
define|#
directive|define
name|GXorReverse
value|0xb
end_define

begin_comment
comment|/* src OR NOT dst	*/
end_comment

begin_define
define|#
directive|define
name|GXcopyInverted
value|0xc
end_define

begin_comment
comment|/* NOT src		*/
end_comment

begin_define
define|#
directive|define
name|GXorInverted
value|0xd
end_define

begin_comment
comment|/* NOT src OR dst	*/
end_comment

begin_define
define|#
directive|define
name|GXnand
value|0xe
end_define

begin_comment
comment|/* NOT src OR NOT dst	*/
end_comment

begin_define
define|#
directive|define
name|GXset
value|0xf
end_define

begin_comment
comment|/* 1			*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GXclear */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST_DEFINES
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|TOPCAT
name|t
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|()
block|{
name|int
name|T
decl_stmt|;
name|T
operator|=
operator|(
name|int
operator|)
operator|&
name|t
expr_stmt|;
name|printf
argument_list|(
literal|"          \tGot\tWanted\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"topcat at:\t0x%x\t0x%x\n"
argument_list|,
name|T
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"vert_blank at:\t0x%x\t0x%x\n"
argument_list|,
operator|&
name|t
operator|.
name|vert_blank
argument_list|,
literal|0x4040
operator|+
name|T
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"nblank at:\t0x%x\t0x%x\n"
argument_list|,
operator|&
name|t
operator|.
name|nblank
argument_list|,
literal|0x4080
operator|+
name|T
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"cursor_on at:\t0x%x\t0x%x\n"
argument_list|,
operator|&
name|t
operator|.
name|cursor_on
argument_list|,
literal|0x40ac
operator|+
name|T
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"pixel_wrr at:\t0x%x\t0x%x\n"
argument_list|,
operator|&
name|t
operator|.
name|pixel_write_replacement_rule
argument_list|,
literal|0x40ea
operator|+
name|T
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"cursor_len at:\t0x%x\t0x%x\n"
argument_list|,
operator|&
name|t
operator|.
name|cursor_length
argument_list|,
literal|0x4112
operator|+
name|T
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"cmap_status at:\t0x%x\t0x%x\n"
argument_list|,
operator|&
name|t
operator|.
name|colormap_status
argument_list|,
literal|0x6003
operator|+
name|T
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"red_data at:\t0x%x\t0x%x\n"
argument_list|,
operator|&
name|t
operator|.
name|red_data
argument_list|,
literal|0x60b2
operator|+
name|T
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"green_data at:\t0x%x\t0x%x\n"
argument_list|,
operator|&
name|t
operator|.
name|green_data
argument_list|,
literal|0x60b4
operator|+
name|T
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"blue_data at:\t0x%x\t0x%x\n"
argument_list|,
operator|&
name|t
operator|.
name|blue_data
argument_list|,
literal|0x60b6
operator|+
name|T
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"write_str at:\t0x%x\t0x%x\n"
argument_list|,
operator|&
name|t
operator|.
name|colormap_writestrobe
argument_list|,
literal|0x60f0
operator|+
name|T
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TEST_DEFINES */
end_comment

end_unit

