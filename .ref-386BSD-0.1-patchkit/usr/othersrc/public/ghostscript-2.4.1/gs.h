begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gs.h */
end_comment

begin_comment
comment|/* Common definitions for Ghostscript library */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"std.h"
end_include

begin_comment
comment|/* Ghostscript never writes directly to stdout. */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|gs_out
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|gs_debug_out
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|dstderr
end_undef

begin_define
define|#
directive|define
name|dstderr
value|gs_debug_out
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Representation of a point. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gs_point_s
block|{
name|double
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|gs_point
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|gs_int_point_s
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|gs_int_point
typedef|;
end_typedef

begin_comment
comment|/* Representation of a rectangle. */
end_comment

begin_comment
comment|/* Note that rectangles are half-open, i.e.: their width is */
end_comment

begin_comment
comment|/* q.x-p.x and their height is q.y-p.y; they include the points */
end_comment

begin_comment
comment|/* (x,y) such that p.x<=x<q.x and p.y<=y<q.y. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gs_rect_s
block|{
name|gs_point
name|p
decl_stmt|,
name|q
decl_stmt|;
comment|/* origin point, corner point */
block|}
name|gs_rect
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|gs_int_rect_s
block|{
name|gs_int_point
name|p
decl_stmt|,
name|q
decl_stmt|;
block|}
name|gs_int_rect
typedef|;
end_typedef

begin_comment
comment|/* So many routines use the graphics state */
end_comment

begin_comment
comment|/* that we may as well declare the abstract type here. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gs_state_s
name|gs_state
typedef|;
end_typedef

begin_comment
comment|/* A number of interfaces involve user-specified allocation */
end_comment

begin_comment
comment|/* and deallocation procedures, so we define the structure here. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|proc_alloc_t
name|alloc
decl_stmt|;
name|proc_free_t
name|free
decl_stmt|;
block|}
name|gs_memory_procs
typedef|;
end_typedef

begin_comment
comment|/* We define our own versions of malloc and free that conform */
end_comment

begin_comment
comment|/* to the types proc_alloc_t and proc_free_t: */
end_comment

begin_decl_stmt
name|char
modifier|*
name|gs_malloc
argument_list|(
name|P3
argument_list|(
name|uint
argument_list|,
name|uint
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gs_free
argument_list|(
name|P4
argument_list|(
name|char
operator|*
argument_list|,
name|uint
argument_list|,
name|uint
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

