begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gzpath.h */
end_comment

begin_comment
comment|/* Private representation of paths for Ghostscript library */
end_comment

begin_comment
comment|/* Requires gxfixed.h */
end_comment

begin_include
include|#
directive|include
file|"gxpath.h"
end_include

begin_comment
comment|/* Paths are represented as a linked list of line or curve segments, */
end_comment

begin_comment
comment|/* similar to what pathforall reports. */
end_comment

begin_comment
comment|/* Definition of a path segment: a segment start, a line, */
end_comment

begin_comment
comment|/* or a Bezier curve. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|s_start
block|,
name|s_line
block|,
name|s_line_close
block|,
name|s_curve
block|}
name|segment_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|segment_type_sizes
define|\
value|sizeof(subpath), sizeof(line_segment), sizeof(line_close_segment),\   sizeof(curve_segment)
end_define

begin_define
define|#
directive|define
name|segment_common
define|\
value|struct segment_s *prev;\ 	struct segment_s *next;\ 	segment_type type;\ 	gs_fixed_point pt;
end_define

begin_comment
comment|/* initial point for starts, */
end_comment

begin_comment
unit|\
comment|/* final point for others */
end_comment

begin_comment
comment|/* A generic segment */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|segment_s
block|{
name|segment_common
block|}
name|segment
typedef|;
end_typedef

begin_comment
comment|/* A start segment.  This serves as the head of a subpath. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|segment_common
name|segment
modifier|*
name|last
decl_stmt|;
comment|/* last segment of subpath, */
comment|/* points back to here if empty */
name|int
name|curve_count
decl_stmt|;
comment|/* # of curves */
name|char
name|closed
decl_stmt|;
comment|/* true if subpath is closed */
block|}
name|subpath
typedef|;
end_typedef

begin_comment
comment|/* Line segments have no special data. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|segment_common
block|}
name|line_segment
typedef|;
end_typedef

begin_comment
comment|/* Line_close segments are for the lines appended by closepath. */
end_comment

begin_comment
comment|/* They point back to the subpath being closed. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|segment_common
name|subpath
modifier|*
name|sub
decl_stmt|;
block|}
name|line_close_segment
typedef|;
end_typedef

begin_comment
comment|/* Curve segments store the control points, not the coefficients. */
end_comment

begin_comment
comment|/* We may want to change this someday. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|segment_common
name|gs_fixed_point
name|p1
decl_stmt|,
name|p2
decl_stmt|;
block|}
name|curve_segment
typedef|;
end_typedef

begin_comment
comment|/* Here is the actual structure of a path. */
end_comment

begin_struct
struct|struct
name|gx_path_s
block|{
name|gs_memory_procs
name|memory_procs
decl_stmt|;
name|gs_fixed_rect
name|bbox
decl_stmt|;
comment|/* bounding box (in device space) */
name|segment
modifier|*
name|box_last
decl_stmt|;
comment|/* bbox incorporates segments */
comment|/* up to& including this one */
name|subpath
modifier|*
name|first_subpath
decl_stmt|;
name|subpath
modifier|*
name|current_subpath
decl_stmt|;
name|int
name|subpath_count
decl_stmt|;
name|int
name|curve_count
decl_stmt|;
name|gs_fixed_point
name|position
decl_stmt|;
comment|/* current position */
name|char
name|position_valid
decl_stmt|;
name|char
name|subpath_open
decl_stmt|;
name|char
name|shares_segments
decl_stmt|;
comment|/* if true, this path shares its */
comment|/* segment storage with the one in */
comment|/* the previous saved graphics state */
block|}
struct|;
end_struct

begin_comment
comment|/* Macros equivalent to a few heavily used procedures. */
end_comment

begin_comment
comment|/* Be aware that these macros may evaluate arguments more than once. */
end_comment

begin_define
define|#
directive|define
name|gx_path_current_point_inline
parameter_list|(
name|ppath
parameter_list|,
name|ppt
parameter_list|)
define|\
value|( !ppath->position_valid ? gs_note_error(gs_error_nocurrentpoint) :\    ((ppt)->x = ppath->position.x, (ppt)->y = ppath->position.y, 0) )
end_define

begin_comment
comment|/* ...rel_point rather than ...relative_point is because */
end_comment

begin_comment
comment|/* some compilers dislike identifiers of>31 characters. */
end_comment

begin_define
define|#
directive|define
name|gx_path_add_rel_point_inline
parameter_list|(
name|ppath
parameter_list|,
name|dx
parameter_list|,
name|dy
parameter_list|)
define|\
value|( !ppath->position_valid ? gs_note_error(gs_error_nocurrentpoint) :\    (ppath->position.x += dx, ppath->position.y += dy,\     ppath->subpath_open = 0) )
end_define

begin_comment
comment|/* ------ Clipping paths ------ */
end_comment

begin_comment
comment|/*  * For clipping, a path is represented as a list of rectangles.  * Normally, a path is created as a list of segments;  * installing it as a clipping path creates the rectangle list.  * However, when the clipping path originates in some other way  * (e.g., from initclip, or for clipping a cached character),  * or if it is a non-trivial intersection of two paths,  * the resulting clipping path exists only as a rectangle list;  * clippath constructs the segment representation if needed.  * Note that even if the path only exists as a rectangle list,  * its bounding box (path.bbox) is still correct.  */
end_comment

begin_comment
comment|/*  * Rectangle list structure.  * Consecutive gx_clip_rect entries either have the same Y values,  * or ymin of this entry>= ymax of the previous entry.  * Note that the contents are like a gs_int_rect, not a gs_fixed_rect.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gx_clip_rect_s
name|gx_clip_rect
typedef|;
end_typedef

begin_struct
struct|struct
name|gx_clip_rect_s
block|{
name|gx_clip_rect
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
name|int
name|ymin
decl_stmt|,
name|ymax
decl_stmt|;
comment|/* ymax> ymin */
name|int
name|xmin
decl_stmt|,
name|xmax
decl_stmt|;
comment|/* xmax> xmin */
block|}
struct|;
end_struct

begin_comment
comment|/* There is a dummy first entry with xmin = xmax */
end_comment

begin_comment
comment|/* to cover Y values starting at min_int, and a dummy last entry */
end_comment

begin_comment
comment|/* to cover Y values ending at max_int. */
end_comment

begin_comment
comment|/* This eliminates the need for end tests. */
end_comment

begin_comment
comment|/* We also preallocate just one internal entry, so that */
end_comment

begin_comment
comment|/* plain rectangular clipping regions don't need to allocate anything. */
end_comment

begin_struct
struct|struct
name|gx_clip_list_s
block|{
name|gx_clip_rect
name|first
decl_stmt|,
name|sole
decl_stmt|,
name|last
decl_stmt|;
name|int
name|count
decl_stmt|;
comment|/* # of rectangles not counting */
comment|/* first or last */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|clip_list_is_rectangle
parameter_list|(
name|clp
parameter_list|)
value|((clp)->count<= 1)
end_define

begin_comment
comment|/* gx_clip_path is a 'subclass' of gx_path. */
end_comment

begin_struct
struct|struct
name|gx_clip_path_s
block|{
name|gx_path
name|path
decl_stmt|;
name|gs_fixed_rect
name|cbox
decl_stmt|;
comment|/* an inner clipping rectangle */
comment|/* for a quick check */
name|gx_clip_list
name|list
decl_stmt|;
name|char
name|segments_valid
decl_stmt|;
comment|/* segment representation is valid */
name|char
name|shares_list
decl_stmt|;
comment|/* if true, this path shares its*/
comment|/* clip list storage with the one in */
comment|/* the previous saved graphics state */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|gx_cpath_is_rectangle
parameter_list|(
name|pcpath
parameter_list|,
name|pbox
parameter_list|)
define|\
value|(clip_list_is_rectangle(&(pcpath)->list) ?\    (*(pbox) = (pcpath)->cbox, 1) : 0)
end_define

end_unit

