begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* Copyright 1985, 1986, Massachusetts Institute of Technology */
end_comment

begin_comment
comment|/* $Header: XWDFile.h,v 10.5 86/11/24 17:01:47 jg Rel $ */
end_comment

begin_comment
comment|/*  * XWDFile.h	MIT Project Athena, X Window system window raster  *		image dumper, dump file format header file.  *  *  Author:	Tony Della Fera, DEC  *		27-Jun-85  *   * Modifier:    William F. Wyatt, SAO  *              18-Nov-86  - version 6 for saving/restoring color maps  */
end_comment

begin_define
define|#
directive|define
name|XWD_FILE_VERSION
value|6
end_define

begin_typedef
typedef|typedef
struct|struct
name|_xwd_file_header
block|{
name|int
name|header_size
decl_stmt|;
comment|/* Size of the entire file header (bytes). */
name|int
name|file_version
decl_stmt|;
comment|/* XWD_FILE_VERSION */
name|int
name|display_type
decl_stmt|;
comment|/* Display type. */
name|int
name|display_planes
decl_stmt|;
comment|/* Number of display planes. */
name|int
name|pixmap_format
decl_stmt|;
comment|/* Pixmap format. */
name|int
name|pixmap_width
decl_stmt|;
comment|/* Pixmap width. */
name|int
name|pixmap_height
decl_stmt|;
comment|/* Pixmap height. */
name|short
name|window_width
decl_stmt|;
comment|/* Window width. */
name|short
name|window_height
decl_stmt|;
comment|/* Window height. */
name|short
name|window_x
decl_stmt|;
comment|/* Window upper left X coordinate. */
name|short
name|window_y
decl_stmt|;
comment|/* Window upper left Y coordinate. */
name|short
name|window_bdrwidth
decl_stmt|;
comment|/* Window border width. */
name|short
name|window_ncolors
decl_stmt|;
comment|/* number of Color entries in this window */
block|}
name|XWDFileHeader
typedef|;
end_typedef

end_unit

