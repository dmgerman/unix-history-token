begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* save.h */
end_comment

begin_comment
comment|/* Interface to Ghostscript save/restore machinery */
end_comment

begin_comment
comment|/* Store checking / change saving */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|alloc_save_new_mask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* l_new if in save, 0 if not */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|alloc_save_test_mask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 if in save, -1 if not */
end_comment

begin_decl_stmt
name|ref
modifier|*
name|alloc_refs
argument_list|(
name|P2
argument_list|(
argument|uint num_refs
argument_list|,
argument|const char *client_name
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alloc_free_refs
argument_list|(
name|P3
argument_list|(
argument|ref *ptr
argument_list|,
argument|uint num_refs
argument_list|,
argument|const char *client_name
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|alloc_save_change
argument_list|(
name|P2
argument_list|(
name|ref
operator|*
name|ptr
argument_list|,
specifier|const
name|char
operator|*
name|client_name
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save and restore state */
end_comment

begin_typedef
typedef|typedef
name|struct
name|alloc_save_s
name|alloc_save
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|alloc_change_s
name|alloc_change
typedef|;
end_typedef

begin_decl_stmt
name|alloc_save
modifier|*
name|alloc_save_state
argument_list|(
name|P0
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 if can't alloc save block */
end_comment

begin_decl_stmt
name|int
name|alloc_save_level
argument_list|(
name|P0
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|alloc_is_since_save
argument_list|(
name|P2
argument_list|(
name|char
operator|*
argument_list|,
name|alloc_save
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|alloc_name_is_since_save
argument_list|(
name|P2
argument_list|(
name|ref
operator|*
argument_list|,
name|alloc_save
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|alloc_restore_state_check
argument_list|(
name|P1
argument_list|(
name|alloc_save
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 if OK,<0 if not */
end_comment

begin_decl_stmt
name|void
name|alloc_restore_state
argument_list|(
name|P1
argument_list|(
name|alloc_save
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

