begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* nsave.h */
end_comment

begin_comment
comment|/* Interpreter client interface for new Ghostscript allocator */
end_comment

begin_comment
comment|/* Requires nalloc.h and ghost.h */
end_comment

begin_comment
comment|/* The routines here parallel those in nalloc.h, but deal with */
end_comment

begin_comment
comment|/* refs and (unaligned) strings. */
end_comment

begin_comment
comment|/* ====== Ordinary clients ====== */
end_comment

begin_comment
comment|/* These are clients who just allocate and deallocate objects. */
end_comment

begin_comment
comment|/* Allocate/free a string. */
end_comment

begin_decl_stmt
specifier|extern
name|byte
modifier|*
name|gs_alloc_string
argument_list|(
name|P3
argument_list|(
name|as_ptr_t
argument_list|,
name|uint
argument_list|,
name|client_name_t
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|gs_free_string
argument_list|(
name|P4
argument_list|(
name|as_ptr_t
argument_list|,
name|byte
operator|*
argument_list|,
name|uint
argument_list|,
name|client_name_t
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocate/free refs. */
end_comment

begin_decl_stmt
specifier|extern
name|ref
modifier|*
name|gs_alloc_refs
argument_list|(
name|P3
argument_list|(
name|as_ptr_t
argument_list|,
name|uint
argument_list|,
name|client_name_t
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|gs_free_refs
argument_list|(
name|P4
argument_list|(
name|as_ptr_t
argument_list|,
name|ref
operator|*
argument_list|,
name|uint
argument_list|,
name|client_name_t
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ====== Root-registering clients ====== */
end_comment

begin_comment
comment|/* Register a ref root. */
end_comment

begin_decl_stmt
name|void
name|gs_alloc_ref_root_register
argument_list|(
name|P3
argument_list|(
name|as_ptr_t
argument_list|,
name|gc_root_t
operator|*
argument_list|,
name|ref
operator|*
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

