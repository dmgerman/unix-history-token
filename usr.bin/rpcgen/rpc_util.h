begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  *  *	from: @(#)rpc_util.h 1.6 87/06/24 (C) 1987 SMI  *	from: @(#)rpc_util.h	2.1 88/08/01 4.0 RPCSRC  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * rpc_util.h, Useful definitions for the RPC protocol compiler  * Copyright (C) 1987, Sun Microsystems, Inc.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|alloc
parameter_list|(
name|size
parameter_list|)
value|malloc((unsigned)(size))
end_define

begin_define
define|#
directive|define
name|ALLOC
parameter_list|(
name|object
parameter_list|)
value|(object *) malloc(sizeof(object))
end_define

begin_define
define|#
directive|define
name|s_print
value|(void) sprintf
end_define

begin_define
define|#
directive|define
name|f_print
value|(void) fprintf
end_define

begin_struct
struct|struct
name|list
block|{
name|char
modifier|*
name|val
decl_stmt|;
name|struct
name|list
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|list
name|list
typedef|;
end_typedef

begin_comment
comment|/*  * Global variables  */
end_comment

begin_define
define|#
directive|define
name|MAXLINESIZE
value|1024
end_define

begin_decl_stmt
specifier|extern
name|char
name|curline
index|[
name|MAXLINESIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|where
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|linenum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|infilename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|fout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|fin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|list
modifier|*
name|defined
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * rpc_util routines  */
end_comment

begin_function_decl
name|void
name|storeval
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|STOREVAL
parameter_list|(
name|list
parameter_list|,
name|item
parameter_list|)
define|\
value|storeval(list,(char *)item)
end_define

begin_function_decl
name|char
modifier|*
name|findval
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FINDVAL
parameter_list|(
name|list
parameter_list|,
name|item
parameter_list|,
name|finder
parameter_list|)
define|\
value|findval(list, (char *) item, finder)
end_define

begin_function_decl
name|char
modifier|*
name|fixtype
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|stringfix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pvname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ptype
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isvectordef
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|streq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|expected1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|expected2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|expected3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tabify
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|record_open
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * rpc_cout routines  */
end_comment

begin_function_decl
name|void
name|cprint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * rpc_hout routines  */
end_comment

begin_function_decl
name|void
name|print_datadef
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * rpc_svcout routines  */
end_comment

begin_function_decl
name|void
name|write_most
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_register
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_rest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * rpc_clntout routines  */
end_comment

begin_function_decl
name|void
name|write_stubs
parameter_list|()
function_decl|;
end_function_decl

end_unit

