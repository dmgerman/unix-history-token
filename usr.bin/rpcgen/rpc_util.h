begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"@(#)rpc_util.h 1.16     94/05/15 SMI"
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
comment|/*      @(#)rpc_util.h  1.5  90/08/29  (C) 1987 SMI   */
end_comment

begin_comment
comment|/*  * rpc_util.h, Useful definitions for the RPC protocol compiler   */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

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
name|definition
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

begin_struct
struct|struct
name|xdrfunc
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|pointerp
decl_stmt|;
name|struct
name|xdrfunc
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xdrfunc
name|xdrfunc
typedef|;
end_typedef

begin_struct
struct|struct
name|commandline
block|{
name|int
name|cflag
decl_stmt|;
comment|/* xdr C routines */
name|int
name|hflag
decl_stmt|;
comment|/* header file */
name|int
name|lflag
decl_stmt|;
comment|/* client side stubs */
name|int
name|mflag
decl_stmt|;
comment|/* server side stubs */
name|int
name|nflag
decl_stmt|;
comment|/* netid flag */
name|int
name|sflag
decl_stmt|;
comment|/* server stubs for the given transport */
name|int
name|tflag
decl_stmt|;
comment|/* dispatch Table file */
name|int
name|Ssflag
decl_stmt|;
comment|/* produce server sample code */
name|int
name|Scflag
decl_stmt|;
comment|/* produce client sample code */
name|int
name|makefileflag
decl_stmt|;
comment|/* Generate a template Makefile */
name|char
modifier|*
name|infile
decl_stmt|;
comment|/* input module name */
name|char
modifier|*
name|outfile
decl_stmt|;
comment|/* output module name */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PUT
value|1
end_define

begin_define
define|#
directive|define
name|GET
value|2
end_define

begin_comment
comment|/*  * Global variables   */
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

begin_decl_stmt
specifier|extern
name|bas_type
modifier|*
name|typ_list_h
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bas_type
modifier|*
name|typ_list_t
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|xdrfunc
modifier|*
name|xdrfunc_head
decl_stmt|,
modifier|*
name|xdrfunc_tail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * All the option flags  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inetdflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pmflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tblflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|logflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|newstyle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Cflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ANSI-C/C++ flag */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|CCflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C++ flag */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tirpcflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag for generating tirpc code */
end_comment

begin_extern
extern|extern int
specifier|inline
namespace|;
comment|/* if this is 0, then do not generate inline code */
namespace|extern
name|int
name|mtflag
namespace|;
end_extern

begin_comment
comment|/*  * Other flags related with inetd jumpstart.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|indefinitewait
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|exitnow
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|timerflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nonfatalerrors
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pid_t
name|childpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * rpc_util routines   */
end_comment

begin_function_decl
name|void
name|reinitialize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|crash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_type
parameter_list|(
name|int
name|len
parameter_list|,
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

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
value|storeval(list,item)
end_define

begin_function_decl
name|definition
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
value|findval(list, item, finder)
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
name|char
modifier|*
name|locase
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pvname_svc
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

begin_function_decl
name|bas_type
modifier|*
name|find_type
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * rpc_cout routines   */
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
comment|/*  * rpc_hout routines   */
end_comment

begin_function_decl
name|void
name|print_datadef
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_funcdef
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_xdr_func_def
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * rpc_svcout routines   */
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

begin_function_decl
name|void
name|write_programs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_svc_aux
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_inetd_register
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_netid_register
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_nettype_register
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

begin_comment
comment|/*  * rpc_tblout routines  */
end_comment

begin_function_decl
name|void
name|write_tables
parameter_list|()
function_decl|;
end_function_decl

end_unit

