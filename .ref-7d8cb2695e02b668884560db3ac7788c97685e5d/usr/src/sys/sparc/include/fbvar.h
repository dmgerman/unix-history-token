begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)fbvar.h	7.3 (Berkeley) %G%  *  * from: $Header: fbvar.h,v 1.15 92/11/26 02:04:34 torek Exp $  */
end_comment

begin_comment
comment|/*  * Frame buffer variables.  All frame buffer drivers must provide the  * following in order to participate.  */
end_comment

begin_struct
struct|struct
name|fbdriver
block|{
comment|/* device unblank function (force kernel output to display) */
name|void
function_decl|(
modifier|*
name|fbd_unblank
function_decl|)
parameter_list|(
name|struct
name|device
modifier|*
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|notyet
name|void
function_decl|(
modifier|*
name|fbd_wrrop
function_decl|)
parameter_list|()
function_decl|;
comment|/* `write region' rasterop */
name|void
function_decl|(
modifier|*
name|fbd_cprop
function_decl|)
parameter_list|()
function_decl|;
comment|/* `copy region' rasterop */
name|void
function_decl|(
modifier|*
name|fbd_clrop
function_decl|)
parameter_list|()
function_decl|;
comment|/* `clear region' rasterop */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fbdevice
block|{
name|int
name|fb_major
decl_stmt|;
comment|/* XXX */
name|struct
name|fbtype
name|fb_type
decl_stmt|;
comment|/* what it says */
name|caddr_t
name|fb_pixels
decl_stmt|;
comment|/* display RAM */
name|int
name|fb_linebytes
decl_stmt|;
comment|/* bytes per display line */
name|struct
name|fbdriver
modifier|*
name|fb_driver
decl_stmt|;
comment|/* pointer to driver */
name|struct
name|device
modifier|*
name|fb_device
decl_stmt|;
comment|/* parameter for fbd_unblank */
comment|/* Raster console emulator state */
name|u_int
name|fb_bits
decl_stmt|;
comment|/* see defines below */
name|int
name|fb_ringing
decl_stmt|;
comment|/* bell currently ringing */
name|int
name|fb_belldepth
decl_stmt|;
comment|/* audible bell depth */
name|int
name|fb_scroll
decl_stmt|;
comment|/* stupid sun scroll mode */
name|int
name|fb_p0
decl_stmt|;
comment|/* escape sequence parameter 0 */
name|int
name|fb_p1
decl_stmt|;
comment|/* escape sequence parameter 1 */
name|int
modifier|*
name|fb_row
decl_stmt|;
comment|/* emulator row */
name|int
modifier|*
name|fb_col
decl_stmt|;
comment|/* emulator column */
name|int
name|fb_maxrow
decl_stmt|;
comment|/* emulator height of screen */
name|int
name|fb_maxcol
decl_stmt|;
comment|/* emulator width of screen */
name|int
name|fb_emuwidth
decl_stmt|;
comment|/* emulator screen width  */
name|int
name|fb_emuheight
decl_stmt|;
comment|/* emulator screen height */
name|int
name|fb_xorigin
decl_stmt|;
comment|/* x origin for first column */
name|int
name|fb_yorigin
decl_stmt|;
comment|/* y origin for first row */
name|struct
name|raster
modifier|*
name|fb_sp
decl_stmt|;
comment|/* frame buffer raster */
name|struct
name|raster
modifier|*
name|fb_cursor
decl_stmt|;
comment|/* optional cursor */
name|int
name|fb_ras_blank
decl_stmt|;
comment|/* current screen blank raster op */
name|struct
name|raster_font
modifier|*
name|fb_font
decl_stmt|;
comment|/* font and related info */
name|int
name|fb_font_ascent
decl_stmt|;
comment|/* distance from font to char origin */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FB_INESC
value|0x001
end_define

begin_comment
comment|/* processing an escape sequence */
end_comment

begin_define
define|#
directive|define
name|FB_STANDOUT
value|0x002
end_define

begin_comment
comment|/* standout mode */
end_comment

begin_comment
comment|/* #define FB_BOLD	0x?		/* boldface mode */
end_comment

begin_define
define|#
directive|define
name|FB_INVERT
value|0x008
end_define

begin_comment
comment|/* white on black mode */
end_comment

begin_define
define|#
directive|define
name|FB_VISBELL
value|0x010
end_define

begin_comment
comment|/* visual bell */
end_comment

begin_define
define|#
directive|define
name|FB_CURSOR
value|0x020
end_define

begin_comment
comment|/* cursor is visible */
end_comment

begin_define
define|#
directive|define
name|FB_P0_DEFAULT
value|0x100
end_define

begin_comment
comment|/* param 0 is defaulted */
end_comment

begin_define
define|#
directive|define
name|FB_P1_DEFAULT
value|0x200
end_define

begin_comment
comment|/* param 1 is defaulted */
end_comment

begin_define
define|#
directive|define
name|FB_P0
value|0x400
end_define

begin_comment
comment|/* working on param 0 */
end_comment

begin_define
define|#
directive|define
name|FB_P1
value|0x800
end_define

begin_comment
comment|/* working on param 1 */
end_comment

begin_decl_stmt
name|void
name|fbattach
name|__P
argument_list|(
operator|(
expr|struct
name|fbdevice
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

