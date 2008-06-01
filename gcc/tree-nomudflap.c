begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Mudflap: narrow-pointer bounds-checking by tree rewriting.    Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.    Contributed by Frank Ch. Eigler<fche@redhat.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"tree-inline.h"
end_include

begin_include
include|#
directive|include
file|"c-tree.h"
end_include

begin_include
include|#
directive|include
file|"c-common.h"
end_include

begin_include
include|#
directive|include
file|"tree-gimple.h"
end_include

begin_include
include|#
directive|include
file|"diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"hashtab.h"
end_include

begin_include
include|#
directive|include
file|"output.h"
end_include

begin_include
include|#
directive|include
file|"varray.h"
end_include

begin_include
include|#
directive|include
file|"langhooks.h"
end_include

begin_include
include|#
directive|include
file|"tree-mudflap.h"
end_include

begin_include
include|#
directive|include
file|"tree-pass.h"
end_include

begin_include
include|#
directive|include
file|"ggc.h"
end_include

begin_include
include|#
directive|include
file|"toplev.h"
end_include

begin_comment
comment|/* This file contains placeholder functions, to be used only for    language processors that cannot handle tree-mudflap.c directly.    (e.g. Fortran).  */
end_comment

begin_function
specifier|static
name|void
name|nogo
parameter_list|(
name|void
parameter_list|)
block|{
name|internal_error
argument_list|(
literal|"mudflap: this language is not supported"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|mudflap_enqueue_decl
parameter_list|(
name|tree
name|obj
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
name|nogo
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|mudflap_enqueue_constant
parameter_list|(
name|tree
name|obj
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
name|nogo
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|mudflap_finish_file
parameter_list|(
name|void
parameter_list|)
block|{
name|nogo
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|int
name|mf_marked_p
parameter_list|(
name|tree
name|t
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
name|nogo
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|mf_mark
parameter_list|(
name|tree
name|t
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
name|nogo
argument_list|()
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* The pass structures must exist, but need not do anything.  */
end_comment

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_mudflap_1
init|=
block|{
literal|"mudflap1"
block|,
comment|/* name */
name|NULL
block|,
comment|/* gate */
name|NULL
block|,
comment|/* execute */
name|NULL
block|,
comment|/* sub */
name|NULL
block|,
comment|/* next */
literal|0
block|,
comment|/* static_pass_number */
literal|0
block|,
comment|/* tv_id */
literal|0
block|,
comment|/* properties_required */
literal|0
block|,
comment|/* properties_provided */
literal|0
block|,
comment|/* properties_destroyed */
literal|0
block|,
comment|/* todo_flags_start */
literal|0
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_mudflap_2
init|=
block|{
literal|"mudflap2"
block|,
comment|/* name */
name|NULL
block|,
comment|/* gate */
name|NULL
block|,
comment|/* execute */
name|NULL
block|,
comment|/* sub */
name|NULL
block|,
comment|/* next */
literal|0
block|,
comment|/* static_pass_number */
literal|0
block|,
comment|/* tv_id */
literal|0
block|,
comment|/* properties_required */
literal|0
block|,
comment|/* properties_provided */
literal|0
block|,
comment|/* properties_destroyed */
literal|0
block|,
comment|/* todo_flags_start */
literal|0
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Instead of: #include "gt-tree-mudflap.h" We prepare a little dummy struct here. */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|ggc_root_tab
name|gt_ggc_r_gt_tree_mudflap_h
index|[]
init|=
block|{
name|LAST_GGC_ROOT_TAB
block|}
decl_stmt|;
end_decl_stmt

end_unit

