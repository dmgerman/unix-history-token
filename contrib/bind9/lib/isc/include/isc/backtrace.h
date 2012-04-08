begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2009  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: backtrace.h,v 1.2 2009/09/01 18:40:25 jinmei Exp $ */
end_comment

begin_comment
comment|/*! \file isc/backtrace.h  * \brief provide a back trace of the running process to help debug problems.  *  * This module tries to get a back trace of the process using some platform  * dependent way when available.  It also manages an internal symbol table  * that maps function addresses used in the process to their textual symbols.  * This module is expected to be used to help debug when some fatal error  * happens.  *  * IMPORTANT NOTE: since the (major) intended use case of this module is  * dumping a back trace on a fatal error, normally followed by self termination,  * functions defined in this module generally doesn't employ assertion checks  * (if it did, a program bug could cause infinite recursive calls to a  * backtrace function).  These functions still perform minimal checks and return  * ISC_R_FAILURE if they detect an error, but the caller should therefore be  * very careful about the use of these functions, and generally discouraged to  * use them except in an exit path.  The exception is  * isc_backtrace_getsymbolfromindex(), which is expected to be used in a  * non-error-handling context and validates arguments with assertion checks.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_BACKTRACE_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_BACKTRACE_H
value|1
end_define

begin_comment
comment|/***  ***	Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_struct
struct|struct
name|isc_backtrace_symmap
block|{
name|void
modifier|*
name|addr
decl_stmt|;
specifier|const
name|char
modifier|*
name|symbol
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|isc__backtrace_nsymbols
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|isc_backtrace_symmap_t
name|isc__backtrace_symtable
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|isc_backtrace_gettrace
parameter_list|(
name|void
modifier|*
modifier|*
name|addrs
parameter_list|,
name|int
name|maxaddrs
parameter_list|,
name|int
modifier|*
name|nframes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get a back trace of the running process above this function itself.  On  * success, addrs[i] will store the address of the call point of the i-th  * stack frame (addrs[0] is the caller of this function).  *nframes will store  * the total number of frames.  *  * Requires (note that these are not ensured by assertion checks, see above):  *  *\li	'addrs' is a valid array containing at least 'maxaddrs' void * entries.  *  *\li	'nframes' must be non NULL.  *  * Returns:  *  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_FAILURE  *\li	#ISC_R_NOTFOUND  *\li	#ISC_R_NOTIMPLEMENTED  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_backtrace_getsymbolfromindex
parameter_list|(
name|int
name|index
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
name|addrp
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|symbolp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns the content of the internal symbol table of the given index.  * On success, *addrsp and *symbolp point to the address and the symbol of  * the 'index'th entry of the table, respectively.  If 'index' is not in the  * range of the symbol table, ISC_R_RANGE will be returned.  *  * Requires  *  *\li	'addrp' must be non NULL&& '*addrp' == NULL.  *  *\li	'symbolp' must be non NULL&& '*symbolp' == NULL.  *  * Returns:  *  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_RANGE  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_backtrace_getsymbol
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|symbolp
parameter_list|,
name|unsigned
name|long
modifier|*
name|offsetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Searches the internal symbol table for the symbol that most matches the  * given 'addr'.  On success, '*symbolp' will point to the name of function  * to which the address 'addr' belong, and '*offsetp' will store the offset  * from the function's entry address to 'addr'.  *  * Requires (note that these are not ensured by assertion checks, see above):  *  *\li	'symbolp' must be non NULL&& '*symbolp' == NULL.  *  *\li	'offsetp' must be non NULL.  *  * Returns:  *  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_FAILURE  *\li	#ISC_R_NOTFOUND  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_BACKTRACE_H */
end_comment

end_unit

