begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* state.h */
end_comment

begin_comment
comment|/* Ghostscript interpreter graphics state definition */
end_comment

begin_comment
comment|/* Note that from the interpreter's point of view, */
end_comment

begin_comment
comment|/* the graphics state is opaque, i.e. the interpreter is */
end_comment

begin_comment
comment|/* just another client of the library. */
end_comment

begin_comment
comment|/* The interpreter requires additional items in the graphics state: */
end_comment

begin_typedef
typedef|typedef
name|struct
name|int_gstate_s
name|int_gstate
typedef|;
end_typedef

begin_struct
struct|struct
name|int_gstate_s
block|{
comment|/* Any refs must come first, for alignment. */
name|ref
name|screen_proc
decl_stmt|;
comment|/* halftone screen procedure */
struct|struct
block|{
name|ref
name|red
decl_stmt|,
name|green
decl_stmt|,
name|blue
decl_stmt|,
name|gray
decl_stmt|;
comment|/* transfer procedures */
block|}
name|transfer_procs
struct|;
name|ref
name|font
decl_stmt|;
comment|/* font object (dictionary) */
name|int_gstate
modifier|*
name|saved
decl_stmt|;
comment|/* previous int_gstate from gsave */
block|}
struct|;
end_struct

begin_comment
comment|/* Enumerate the refs in an int_gstate. */
end_comment

begin_define
define|#
directive|define
name|int_gstate_map_refs
parameter_list|(
name|p
parameter_list|,
name|m
parameter_list|)
define|\
value|(m(&(p)->screen_proc), m(&(p)->transfer_procs.red),\   m(&(p)->transfer_procs.green), m(&(p)->transfer_procs.blue),\   m(&(p)->font))
end_define

begin_comment
comment|/* The current instances. */
end_comment

begin_decl_stmt
specifier|extern
name|int_gstate
name|istate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gs_state
modifier|*
name|igs
decl_stmt|;
end_decl_stmt

end_unit

