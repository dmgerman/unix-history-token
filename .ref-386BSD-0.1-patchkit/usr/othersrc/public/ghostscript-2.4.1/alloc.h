begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990, 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* alloc.h */
end_comment

begin_comment
comment|/* Interface to Ghostscript memory allocator */
end_comment

begin_comment
comment|/* Ordinary allocator interface */
end_comment

begin_decl_stmt
name|void
name|alloc_init
argument_list|(
name|P3
argument_list|(
name|proc_alloc_t
argument_list|,
name|proc_free_t
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|alloc
argument_list|(
name|P3
argument_list|(
argument|uint num_elts
argument_list|,
argument|uint elt_size
argument_list|,
argument|const char *client_name
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alloc_free
argument_list|(
name|P4
argument_list|(
argument|char *data
argument_list|,
argument|uint num_elts
argument_list|,
argument|uint elt_size
argument_list|,
argument|const char *client_name
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alloc_status
argument_list|(
name|P2
argument_list|(
name|long
operator|*
argument_list|,
name|long
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dynamic allocation */
end_comment

begin_comment
comment|/* Note that these procedures use byte * rather than char * */
end_comment

begin_decl_stmt
name|byte
modifier|*
name|alloc_grow
argument_list|(
name|P5
argument_list|(
argument|byte *data
argument_list|,
argument|uint old_num
argument_list|,
argument|uint new_num
argument_list|,
argument|uint elt_size
argument_list|,
argument|const char *client_name
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|byte
modifier|*
name|alloc_shrink
argument_list|(
name|P5
argument_list|(
argument|byte *data
argument_list|,
argument|uint old_num
argument_list|,
argument|uint new_num
argument_list|,
argument|uint elt_size
argument_list|,
argument|const char *client_name
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

