begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"@(#)rpc_parse.h 1.10     94/05/15 SMI"
end_pragma

begin_comment
comment|/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved  	*/
end_comment

begin_comment
comment|/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
end_comment

begin_comment
comment|/*	The copyright notice above does not evidence any   	*/
end_comment

begin_comment
comment|/*	actual or intended publication of such source code.	*/
end_comment

begin_comment
comment|/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++ *	PROPRIETARY NOTICE (Combined) * * This source code is unpublished proprietary information * constituting, or derived under license from AT&T's UNIX(r) System V. * In addition, portions of such source code were derived from Berkeley * 4.3 BSD under license from the Regents of the University of * California. * * * *	Copyright Notice  * * Notice of copyright on this source code product does not indicate  *  publication. * *	(c) 1986,1987,1988.1989  Sun Microsystems, Inc *	(c) 1983,1984,1985,1986,1987,1988,1989  AT&T. *          All rights reserved. */
end_comment

begin_comment
comment|/*      @(#)rpc_parse.h  1.3  90/08/29  (C) 1987 SMI   */
end_comment

begin_comment
comment|/*  * rpc_parse.h, Definitions for the RPCL parser   */
end_comment

begin_enum
enum|enum
name|defkind
block|{
name|DEF_CONST
block|,
name|DEF_STRUCT
block|,
name|DEF_UNION
block|,
name|DEF_ENUM
block|,
name|DEF_TYPEDEF
block|,
name|DEF_PROGRAM
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|defkind
name|defkind
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|const_def
typedef|;
end_typedef

begin_enum
enum|enum
name|relation
block|{
name|REL_VECTOR
block|,
comment|/* fixed length array */
name|REL_ARRAY
block|,
comment|/* variable length array */
name|REL_POINTER
block|,
comment|/* pointer */
name|REL_ALIAS
block|,
comment|/* simple */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|relation
name|relation
typedef|;
end_typedef

begin_struct
struct|struct
name|typedef_def
block|{
name|char
modifier|*
name|old_prefix
decl_stmt|;
name|char
modifier|*
name|old_type
decl_stmt|;
name|relation
name|rel
decl_stmt|;
name|char
modifier|*
name|array_max
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|typedef_def
name|typedef_def
typedef|;
end_typedef

begin_struct
struct|struct
name|enumval_list
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|assignment
decl_stmt|;
name|struct
name|enumval_list
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|enumval_list
name|enumval_list
typedef|;
end_typedef

begin_struct
struct|struct
name|enum_def
block|{
name|enumval_list
modifier|*
name|vals
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|enum_def
name|enum_def
typedef|;
end_typedef

begin_struct
struct|struct
name|declaration
block|{
name|char
modifier|*
name|prefix
decl_stmt|;
name|char
modifier|*
name|type
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|relation
name|rel
decl_stmt|;
name|char
modifier|*
name|array_max
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|declaration
name|declaration
typedef|;
end_typedef

begin_struct
struct|struct
name|decl_list
block|{
name|declaration
name|decl
decl_stmt|;
name|struct
name|decl_list
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|decl_list
name|decl_list
typedef|;
end_typedef

begin_struct
struct|struct
name|struct_def
block|{
name|decl_list
modifier|*
name|decls
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|struct_def
name|struct_def
typedef|;
end_typedef

begin_struct
struct|struct
name|case_list
block|{
name|char
modifier|*
name|case_name
decl_stmt|;
name|int
name|contflag
decl_stmt|;
name|declaration
name|case_decl
decl_stmt|;
name|struct
name|case_list
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|case_list
name|case_list
typedef|;
end_typedef

begin_struct
struct|struct
name|union_def
block|{
name|declaration
name|enum_decl
decl_stmt|;
name|case_list
modifier|*
name|cases
decl_stmt|;
name|declaration
modifier|*
name|default_decl
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|union_def
name|union_def
typedef|;
end_typedef

begin_struct
struct|struct
name|arg_list
block|{
name|char
modifier|*
name|argname
decl_stmt|;
comment|/* name of struct for arg*/
name|decl_list
modifier|*
name|decls
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|arg_list
name|arg_list
typedef|;
end_typedef

begin_struct
struct|struct
name|proc_list
block|{
name|char
modifier|*
name|proc_name
decl_stmt|;
name|char
modifier|*
name|proc_num
decl_stmt|;
name|arg_list
name|args
decl_stmt|;
name|int
name|arg_num
decl_stmt|;
name|char
modifier|*
name|res_type
decl_stmt|;
name|char
modifier|*
name|res_prefix
decl_stmt|;
name|struct
name|proc_list
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|proc_list
name|proc_list
typedef|;
end_typedef

begin_struct
struct|struct
name|version_list
block|{
name|char
modifier|*
name|vers_name
decl_stmt|;
name|char
modifier|*
name|vers_num
decl_stmt|;
name|proc_list
modifier|*
name|procs
decl_stmt|;
name|struct
name|version_list
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|version_list
name|version_list
typedef|;
end_typedef

begin_struct
struct|struct
name|program_def
block|{
name|char
modifier|*
name|prog_num
decl_stmt|;
name|version_list
modifier|*
name|versions
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|program_def
name|program_def
typedef|;
end_typedef

begin_struct
struct|struct
name|definition
block|{
name|char
modifier|*
name|def_name
decl_stmt|;
name|defkind
name|def_kind
decl_stmt|;
union|union
block|{
name|const_def
name|co
decl_stmt|;
name|struct_def
name|st
decl_stmt|;
name|union_def
name|un
decl_stmt|;
name|enum_def
name|en
decl_stmt|;
name|typedef_def
name|ty
decl_stmt|;
name|program_def
name|pr
decl_stmt|;
block|}
name|def
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|definition
name|definition
typedef|;
end_typedef

begin_function_decl
name|definition
modifier|*
name|get_definition
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|bas_type
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|length
decl_stmt|;
name|struct
name|bas_type
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bas_type
name|bas_type
typedef|;
end_typedef

end_unit

