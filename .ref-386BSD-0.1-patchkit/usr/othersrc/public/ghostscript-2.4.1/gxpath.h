begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990, 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gxpath.h */
end_comment

begin_comment
comment|/* Lower-level path routines for Ghostscript library */
end_comment

begin_comment
comment|/* Requires gxfixed.h */
end_comment

begin_comment
comment|/* The routines and types in this interface use */
end_comment

begin_comment
comment|/* device, rather than user, coordinates, and fixed-point, */
end_comment

begin_comment
comment|/* rather than floating, representation. */
end_comment

begin_comment
comment|/* Opaque type for a path */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gx_path_s
name|gx_path
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|uint
name|gs_path_sizeof
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Opaque type for a path enumerator */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gx_path_enum_s
name|gx_path_enum
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|uint
name|gx_path_enum_sizeof
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define the two insideness rules */
end_comment

begin_define
define|#
directive|define
name|gx_rule_winding_number
value|(-1)
end_define

begin_define
define|#
directive|define
name|gx_rule_even_odd
value|1
end_define

begin_comment
comment|/* Debugging routines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|gx_path_print
argument_list|(
name|P1
argument_list|(
name|gx_path
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Path constructors. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gx_path_init
argument_list|(
name|P2
argument_list|(
name|gx_path
operator|*
argument_list|,
name|gs_memory_procs
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_release
argument_list|(
name|P1
argument_list|(
name|gx_path
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_share
argument_list|(
name|P1
argument_list|(
name|gx_path
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|gx_path_add_point
argument_list|(
name|P3
argument_list|(
name|gx_path
operator|*
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_add_relative_point
argument_list|(
name|P3
argument_list|(
name|gx_path
operator|*
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_add_line
argument_list|(
name|P3
argument_list|(
name|gx_path
operator|*
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_add_rectangle
argument_list|(
name|P5
argument_list|(
name|gx_path
operator|*
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_add_pgram
argument_list|(
name|P7
argument_list|(
name|gx_path
operator|*
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_add_curve
argument_list|(
name|P7
argument_list|(
name|gx_path
operator|*
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_add_flattened_curve
argument_list|(
name|P8
argument_list|(
name|gx_path
operator|*
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|floatp
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_add_arc
argument_list|(
name|P8
argument_list|(
name|gx_path
operator|*
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|floatp
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_add_path
argument_list|(
name|P2
argument_list|(
name|gx_path
operator|*
argument_list|,
name|gx_path
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_close_subpath
argument_list|(
name|P1
argument_list|(
name|gx_path
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The last argument to gx_path_add_arc is a fraction for computing */
end_comment

begin_comment
comment|/* the curve parameters.  Here is the correct value for quarter-circles. */
end_comment

begin_comment
comment|/* (stroke uses this to draw round caps and joins.) */
end_comment

begin_define
define|#
directive|define
name|quarter_arc_fraction
value|0.552285
end_define

begin_comment
comment|/* Path accessors */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gx_path_current_point
argument_list|(
name|P2
argument_list|(
name|gx_path
operator|*
argument_list|,
name|gs_fixed_point
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_bbox
argument_list|(
name|P2
argument_list|(
name|gx_path
operator|*
argument_list|,
name|gs_fixed_rect
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_has_curves
argument_list|(
name|P1
argument_list|(
name|gx_path
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_is_void
argument_list|(
name|P1
argument_list|(
name|gx_path
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_is_rectangle
argument_list|(
name|P2
argument_list|(
name|gx_path
operator|*
argument_list|,
name|gs_fixed_rect
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Path transformers */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gx_path_copy
argument_list|(
name|P2
argument_list|(
name|gx_path
operator|*
comment|/*old*/
argument_list|,
name|gx_path
operator|*
comment|/*new*/
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_flatten
argument_list|(
name|P3
argument_list|(
name|gx_path
operator|*
comment|/*old*/
argument_list|,
name|gx_path
operator|*
comment|/*new*/
argument_list|,
name|floatp
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_reverse
argument_list|(
name|P2
argument_list|(
name|gx_path
operator|*
comment|/*old*/
argument_list|,
name|gx_path
operator|*
comment|/*new*/
argument_list|)
argument_list|)
decl_stmt|,
name|gx_path_translate
argument_list|(
name|P3
argument_list|(
name|gx_path
operator|*
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------ Clipping paths ------ */
end_comment

begin_comment
comment|/* Opaque type for a path */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gx_clip_path_s
name|gx_clip_path
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|uint
name|gs_clip_path_sizeof
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|gx_clip_to_rectangle
argument_list|(
name|P2
argument_list|(
name|gs_state
operator|*
argument_list|,
name|gs_fixed_rect
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gx_clip_to_path
argument_list|(
name|P1
argument_list|(
name|gs_state
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gx_cpath_from_rectangle
argument_list|(
name|P3
argument_list|(
name|gx_clip_path
operator|*
argument_list|,
name|gs_fixed_rect
operator|*
argument_list|,
name|gs_memory_procs
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gx_cpath_intersect
argument_list|(
name|P4
argument_list|(
name|gs_state
operator|*
argument_list|,
name|gx_clip_path
operator|*
argument_list|,
name|gx_path
operator|*
argument_list|,
name|int
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|gx_cpath_release
argument_list|(
name|P1
argument_list|(
name|gx_clip_path
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gx_cpath_share
argument_list|(
name|P1
argument_list|(
name|gx_clip_path
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|gx_cpath_path
argument_list|(
name|P2
argument_list|(
name|gx_clip_path
operator|*
argument_list|,
name|gx_path
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gx_cpath_box_for_check
argument_list|(
name|P2
argument_list|(
name|gx_clip_path
operator|*
argument_list|,
name|gs_fixed_rect
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gx_cpath_includes_rectangle
argument_list|(
name|P5
argument_list|(
name|gx_clip_path
operator|*
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|,
name|fixed
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Opaque type for a clip list. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gx_clip_list_s
name|gx_clip_list
typedef|;
end_typedef

begin_comment
comment|/* Initialize a clip list. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gx_clip_list_init
argument_list|(
name|P1
argument_list|(
name|gx_clip_list
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize a clip list to a rectangle. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gx_clip_list_from_rectangle
argument_list|(
name|P2
argument_list|(
name|gx_clip_list
operator|*
argument_list|,
name|gs_fixed_rect
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add a clip list to a path. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gx_clip_list_add_to_path
argument_list|(
name|P2
argument_list|(
name|gx_clip_list
operator|*
argument_list|,
name|gx_path
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free a clip list. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gx_clip_list_free
argument_list|(
name|P2
argument_list|(
name|gx_clip_list
operator|*
argument_list|,
name|gs_memory_procs
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

