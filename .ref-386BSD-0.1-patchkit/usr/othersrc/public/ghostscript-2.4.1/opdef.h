begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* opdef.h */
end_comment

begin_comment
comment|/* Operator definition interface for Ghostscript */
end_comment

begin_comment
comment|/* Typedef for an operator procedure. */
end_comment

begin_comment
comment|/*  * Operator procedures return 0 for success, a negative code for an error,   * or a positive code for some uncommon situations (see below).  */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
operator|*
name|op_proc_p
argument_list|)
argument_list|(
name|P1
argument_list|(
name|os_ptr
argument_list|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* Structure for initializing the operator table. */
end_comment

begin_comment
comment|/*  * Each operator file declares an array of these, of the following kind:  op_def my_defs[] = { 	{"1name", zname},   --or--  {"1%name", zname,&iname}, 	    ... 	op_def_end(iproc) }   * where iproc is an initialization procedure for the file, or 0.  * This definition always appears at the END of the file,  * to avoid the necessity for forward declarations for all the  * operator procedures.  *  * The second form of definition is for internal operators, such as  * continuation operators, that do not appear in systemdict and whose  * name indices must be stored in a static variable.  Ghostscript assumes  * that these operators cannot appear anywhere (in executable form)  * except on the e-stack; to maintain this invariant, the execstack  * operator converts them to literal form, and cvx refuses to convert  * them back.  As a result of this invariant, they do not need to  * push themselves back on the e-stack when executed, since the only  * place they could have come from was the e-stack.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
name|_ds
modifier|*
name|oname
decl_stmt|;
name|op_proc_p
name|proc
decl_stmt|;
name|int
name|_ds
modifier|*
name|oindex
decl_stmt|;
block|}
name|op_def
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|op_def
specifier|const
name|_ds
modifier|*
name|op_def_ptr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|op_def_end
parameter_list|(
name|iproc
parameter_list|)
value|{(char _ds *)0, (op_proc_p)iproc}
end_define

begin_comment
comment|/*  * All operators are catalogued in a table, primarily so  * that they can have a convenient packed representation.  * The `size' of an operator is its index in this table.  */
end_comment

begin_define
define|#
directive|define
name|op_index
parameter_list|(
name|opref
parameter_list|)
value|r_size(opref)
end_define

begin_comment
comment|/*  * There are actually two kinds of operators: the real ones (t_operator),  * and ones defined by procedures (t_oparray).  The catalog for the former  * is op_def_table, and their index is in the range [1..op_def_count).  */
end_comment

begin_decl_stmt
specifier|extern
name|op_def_ptr
modifier|*
name|op_def_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint
name|op_def_count
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|op_num_args
parameter_list|(
name|opref
parameter_list|)
value|(op_def_table[op_index(opref)]->oname[0] - '0')
end_define

begin_comment
comment|/*  * The catalog for the latter is op_array_table, and their index is in  * the range [op_def_count..op_def_count+op_array_count).  The actual  * index in op_array_table is the operator index minus op_def_count.  */
end_comment

begin_decl_stmt
specifier|extern
name|ref
name|op_array_table
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* t_array */
end_comment

begin_decl_stmt
specifier|extern
name|ushort
modifier|*
name|op_array_nx_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint
name|op_array_count
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|op_index_ref
parameter_list|(
name|index
parameter_list|,
name|pref
parameter_list|)
define|\
value|((index)< op_def_count ?\    make_oper(pref, index, op_def_table[index]->proc) :\    (r_set_type_attrs(pref, t_oparray, a_executable), r_set_size(pref, index)))
end_define

end_unit

