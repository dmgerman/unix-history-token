begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* iutil.h */
end_comment

begin_comment
comment|/* Prototypes for procedures in iutil.c */
end_comment

begin_comment
comment|/* ------ Object utilities ------ */
end_comment

begin_comment
comment|/* Copy refs from one place to another. */
end_comment

begin_comment
comment|/* (If we are copying to the stack, we can just use memcpy.) */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|refcpy_to_new
argument_list|(
name|P3
argument_list|(
argument|ref *to
argument_list|,
argument|const ref *from
argument_list|,
argument|uint size
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|refcpy_to_old
argument_list|(
name|P4
argument_list|(
argument|ref *to
argument_list|,
argument|const ref *from
argument_list|,
argument|uint size
argument_list|,
argument|const char *client_name
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fill an array with nulls. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|refset_null
argument_list|(
name|P2
argument_list|(
argument|ref *to
argument_list|,
argument|uint size
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Compare two objects for equality.  Return 1 if equal, 0 if not. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|obj_eq
argument_list|(
name|P2
argument_list|(
specifier|const
name|ref
operator|*
argument_list|,
specifier|const
name|ref
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create a printable representation of an object, a la cvs. */
end_comment

begin_comment
comment|/* Return 0 if OK,<0 if the destination wasn't large enough. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|obj_cvs
argument_list|(
name|P4
argument_list|(
specifier|const
name|ref
operator|*
argument_list|,
name|byte
operator|*
argument_list|,
name|uint
argument_list|,
name|uint
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------ String utilities ------ */
end_comment

begin_comment
comment|/* Convert a C string to a Ghostscript string */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|string_to_ref
argument_list|(
name|P3
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|ref
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Convert a Ghostscript string to a C string. */
end_comment

begin_comment
comment|/* Return 0 iff the buffer can't be allocated. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ref_to_string
argument_list|(
name|P2
argument_list|(
specifier|const
name|ref
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------ Operand utilities ------ */
end_comment

begin_comment
comment|/* Get N numeric operands from the stack. */
end_comment

begin_comment
comment|/* Note that the first argument must be ref * rather than os_ptr, */
end_comment

begin_comment
comment|/* because num_params is sometimes used elsewhere than */
end_comment

begin_comment
comment|/* on the operand stack. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|num_params
argument_list|(
name|P3
argument_list|(
specifier|const
name|ref
operator|*
argument_list|,
name|int
argument_list|,
name|float
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get a real parameter. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|real_param
argument_list|(
name|P2
argument_list|(
specifier|const
name|ref
operator|*
argument_list|,
name|float
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check for a matrix operand with read access. */
end_comment

begin_struct_decl
struct_decl|struct
name|gs_matrix_s
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|read_matrix
argument_list|(
name|P2
argument_list|(
specifier|const
name|ref
operator|*
argument_list|,
expr|struct
name|gs_matrix_s
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check for a matrix operand with write access. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|write_matrix
argument_list|(
name|P1
argument_list|(
name|ref
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

