begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XWDFile.h,v 1.14 91/01/06 12:18:26 rws Exp $ */
end_comment

begin_comment
comment|/* Copyright 1985, 1986, Massachusetts Institute of Technology */
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_comment
comment|/*  * XWDFile.h	MIT Project Athena, X Window system window raster  *		image dumper, dump file format header file.  *  *  Author:	Tony Della Fera, DEC  *		27-Jun-85  *   * Modifier:    William F. Wyatt, SAO  *              18-Nov-86  - version 6 for saving/restoring color maps  */
end_comment

begin_comment
comment|/*  * This is not portable between machines of differing word sizes.  To make  * it portable, do the following things:  *  *     o  #include<X11/Xmd.h>  *     o  remove the typedef for xwdval  *     o  replace all instances of xwdval with the appropriate CARD32 ... B32  *     o  make sure that XWDFileHeader is padded to quadword boundaries  *     o  make sure the window name is written out quadword aligned  *     o  create an XWDColor structure that contains the same fields as XColor  *        but which is defined in terms of CARD32 B32, CARD16 B16, and CARD8  *     o  convert XColor structures to XWDColor structures in xwd  *     o  remove all xwdval casts from xwd  *     o  pack image data before writing out if necessary  *     o  replace casts from xwdval objects in xwud with cvtINT macros  *     o  convert XWDColor structures to XColor structures  *     o  unpack data after reading in if necessary  */
end_comment

begin_include
include|#
directive|include
file|<X11/Xmd.h>
end_include

begin_define
define|#
directive|define
name|XWD_FILE_VERSION
value|7
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WORD64
end_ifdef

begin_define
define|#
directive|define
name|sz_XWDheader
value|104
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sz_XWDheader
value|100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|sz_XWDColor
value|12
end_define

begin_typedef
typedef|typedef
name|CARD32
name|xwdval
typedef|;
end_typedef

begin_comment
comment|/* for old broken programs */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_xwd_file_header
block|{
name|CARD32
name|header_size
name|B32
decl_stmt|;
comment|/* Size of the entire file header (bytes). */
name|CARD32
name|file_version
name|B32
decl_stmt|;
comment|/* XWD_FILE_VERSION */
name|CARD32
name|pixmap_format
name|B32
decl_stmt|;
comment|/* Pixmap format */
name|CARD32
name|pixmap_depth
name|B32
decl_stmt|;
comment|/* Pixmap depth */
name|CARD32
name|pixmap_width
name|B32
decl_stmt|;
comment|/* Pixmap width */
name|CARD32
name|pixmap_height
name|B32
decl_stmt|;
comment|/* Pixmap height */
name|CARD32
name|xoffset
name|B32
decl_stmt|;
comment|/* Bitmap x offset */
name|CARD32
name|byte_order
name|B32
decl_stmt|;
comment|/* MSBFirst, LSBFirst */
name|CARD32
name|bitmap_unit
name|B32
decl_stmt|;
comment|/* Bitmap unit */
name|CARD32
name|bitmap_bit_order
name|B32
decl_stmt|;
comment|/* MSBFirst, LSBFirst */
name|CARD32
name|bitmap_pad
name|B32
decl_stmt|;
comment|/* Bitmap scanline pad */
name|CARD32
name|bits_per_pixel
name|B32
decl_stmt|;
comment|/* Bits per pixel */
name|CARD32
name|bytes_per_line
name|B32
decl_stmt|;
comment|/* Bytes per scanline */
name|CARD32
name|visual_class
name|B32
decl_stmt|;
comment|/* Class of colormap */
name|CARD32
name|red_mask
name|B32
decl_stmt|;
comment|/* Z red mask */
name|CARD32
name|green_mask
name|B32
decl_stmt|;
comment|/* Z green mask */
name|CARD32
name|blue_mask
name|B32
decl_stmt|;
comment|/* Z blue mask */
name|CARD32
name|bits_per_rgb
name|B32
decl_stmt|;
comment|/* Log2 of distinct color values */
name|CARD32
name|colormap_entries
name|B32
decl_stmt|;
comment|/* Number of entries in colormap */
name|CARD32
name|ncolors
name|B32
decl_stmt|;
comment|/* Number of Color structures */
name|CARD32
name|window_width
name|B32
decl_stmt|;
comment|/* Window width */
name|CARD32
name|window_height
name|B32
decl_stmt|;
comment|/* Window height */
name|CARD32
name|window_x
name|B32
decl_stmt|;
comment|/* Window upper left X coordinate */
name|CARD32
name|window_y
name|B32
decl_stmt|;
comment|/* Window upper left Y coordinate */
name|CARD32
name|window_bdrwidth
name|B32
decl_stmt|;
comment|/* Window border width */
ifdef|#
directive|ifdef
name|WORD64
name|CARD32
name|header_end
name|B32
decl_stmt|;
comment|/* Pad to fill out word */
endif|#
directive|endif
block|}
name|XWDFileHeader
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD32
name|pixel
name|B32
decl_stmt|;
name|CARD16
name|red
name|B16
decl_stmt|;
name|CARD16
name|green
name|B16
decl_stmt|;
name|CARD16
name|blue
name|B16
decl_stmt|;
name|CARD8
name|flags
decl_stmt|;
name|CARD8
name|pad
decl_stmt|;
block|}
name|XWDColor
typedef|;
end_typedef

end_unit

