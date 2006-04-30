begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: master.h,v 1.31.2.3.2.7 2004/03/08 09:04:36 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_MASTER_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_MASTER_H
value|1
end_define

begin_comment
comment|/***  ***	Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_comment
comment|/*  * Flags to be passed in the 'options' argument in the functions below.  */
end_comment

begin_define
define|#
directive|define
name|DNS_MASTER_AGETTL
value|0x00000001
end_define

begin_comment
comment|/* Age the ttl based on $DATE. */
end_comment

begin_define
define|#
directive|define
name|DNS_MASTER_MANYERRORS
value|0x00000002
end_define

begin_comment
comment|/* Continue processing on errors. */
end_comment

begin_define
define|#
directive|define
name|DNS_MASTER_NOINCLUDE
value|0x00000004
end_define

begin_comment
comment|/* Disallow $INCLUDE directives. */
end_comment

begin_define
define|#
directive|define
name|DNS_MASTER_ZONE
value|0x00000008
end_define

begin_comment
comment|/* Loading a zone master file. */
end_comment

begin_define
define|#
directive|define
name|DNS_MASTER_HINT
value|0x00000010
end_define

begin_comment
comment|/* Loading a hint master file. */
end_comment

begin_define
define|#
directive|define
name|DNS_MASTER_SLAVE
value|0x00000020
end_define

begin_comment
comment|/* Loading a slave master file. */
end_comment

begin_define
define|#
directive|define
name|DNS_MASTER_CHECKNS
value|0x00000040
end_define

begin_comment
comment|/* Check NS records to see if 						 * they are an address */
end_comment

begin_define
define|#
directive|define
name|DNS_MASTER_FATALNS
value|0x00000080
end_define

begin_comment
comment|/* Treat DNS_MASTER_CHECKNS 						 * matches as fatal */
end_comment

begin_define
define|#
directive|define
name|DNS_MASTER_CHECKNAMES
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DNS_MASTER_CHECKNAMESFAIL
value|0x00000200
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/***  ***	Function  ***/
name|isc_result_t
name|dns_master_loadfile
parameter_list|(
specifier|const
name|char
modifier|*
name|master_file
parameter_list|,
name|dns_name_t
modifier|*
name|top
parameter_list|,
name|dns_name_t
modifier|*
name|origin
parameter_list|,
name|dns_rdataclass_t
name|zclass
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_rdatacallbacks_t
modifier|*
name|callbacks
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_master_loadstream
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|,
name|dns_name_t
modifier|*
name|top
parameter_list|,
name|dns_name_t
modifier|*
name|origin
parameter_list|,
name|dns_rdataclass_t
name|zclass
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_rdatacallbacks_t
modifier|*
name|callbacks
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_master_loadbuffer
parameter_list|(
name|isc_buffer_t
modifier|*
name|buffer
parameter_list|,
name|dns_name_t
modifier|*
name|top
parameter_list|,
name|dns_name_t
modifier|*
name|origin
parameter_list|,
name|dns_rdataclass_t
name|zclass
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_rdatacallbacks_t
modifier|*
name|callbacks
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_master_loadlexer
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|,
name|dns_name_t
modifier|*
name|top
parameter_list|,
name|dns_name_t
modifier|*
name|origin
parameter_list|,
name|dns_rdataclass_t
name|zclass
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_rdatacallbacks_t
modifier|*
name|callbacks
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_master_loadfileinc
parameter_list|(
specifier|const
name|char
modifier|*
name|master_file
parameter_list|,
name|dns_name_t
modifier|*
name|top
parameter_list|,
name|dns_name_t
modifier|*
name|origin
parameter_list|,
name|dns_rdataclass_t
name|zclass
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_rdatacallbacks_t
modifier|*
name|callbacks
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|dns_loaddonefunc_t
name|done
parameter_list|,
name|void
modifier|*
name|done_arg
parameter_list|,
name|dns_loadctx_t
modifier|*
modifier|*
name|ctxp
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_master_loadstreaminc
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|,
name|dns_name_t
modifier|*
name|top
parameter_list|,
name|dns_name_t
modifier|*
name|origin
parameter_list|,
name|dns_rdataclass_t
name|zclass
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_rdatacallbacks_t
modifier|*
name|callbacks
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|dns_loaddonefunc_t
name|done
parameter_list|,
name|void
modifier|*
name|done_arg
parameter_list|,
name|dns_loadctx_t
modifier|*
modifier|*
name|ctxp
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_master_loadbufferinc
parameter_list|(
name|isc_buffer_t
modifier|*
name|buffer
parameter_list|,
name|dns_name_t
modifier|*
name|top
parameter_list|,
name|dns_name_t
modifier|*
name|origin
parameter_list|,
name|dns_rdataclass_t
name|zclass
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_rdatacallbacks_t
modifier|*
name|callbacks
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|dns_loaddonefunc_t
name|done
parameter_list|,
name|void
modifier|*
name|done_arg
parameter_list|,
name|dns_loadctx_t
modifier|*
modifier|*
name|ctxp
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_master_loadlexerinc
parameter_list|(
name|isc_lex_t
modifier|*
name|lex
parameter_list|,
name|dns_name_t
modifier|*
name|top
parameter_list|,
name|dns_name_t
modifier|*
name|origin
parameter_list|,
name|dns_rdataclass_t
name|zclass
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_rdatacallbacks_t
modifier|*
name|callbacks
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|dns_loaddonefunc_t
name|done
parameter_list|,
name|void
modifier|*
name|done_arg
parameter_list|,
name|dns_loadctx_t
modifier|*
modifier|*
name|ctxp
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Loads a RFC 1305 master file from a file, stream, buffer, or existing  * lexer into rdatasets and then calls 'callbacks->commit' to commit the  * rdatasets.  Rdata memory belongs to dns_master_load and will be  * reused / released when the callback completes.  dns_load_master will  * abort if callbacks->commit returns any value other than ISC_R_SUCCESS.  *  * If 'DNS_MASTER_AGETTL' is set and the master file contains one or more  * $DATE directives, the TTLs of the data will be aged accordingly.  *  * 'callbacks->commit' is assumed to call 'callbacks->error' or  * 'callbacks->warn' to generate any error messages required.  *  * 'done' is called with 'done_arg' and a result code when the loading  * is completed or has failed.  If the initial setup fails 'done' is  * not called.  *  * Requires:  *	'master_file' points to a valid string.  *	'lexer' points to a valid lexer.  *	'top' points to a valid name.  *	'origin' points to a valid name.  *	'callbacks->commit' points to a valid function.  *	'callbacks->error' points to a valid function.  *	'callbacks->warn' points to a valid function.  *	'mctx' points to a valid memory context.  *	'task' and 'done' to be valid.  *	'lmgr' to be valid.  *	'ctxp != NULL&& ctxp == NULL'.  *  * Returns:  *	ISC_R_SUCCESS upon successfully loading the master file.  *	ISC_R_SEENINCLUDE upon successfully loading the master file with  *		a $INCLUDE statement.  *	ISC_R_NOMEMORY out of memory.  *	ISC_R_UNEXPECTEDEND expected to be able to read a input token and  *		there was not one.  *	ISC_R_UNEXPECTED  *	DNS_R_NOOWNER failed to specify a ownername.  *	DNS_R_NOTTL failed to specify a ttl.  *	DNS_R_BADCLASS record class did not match zone class.  *	DNS_R_CONTINUE load still in progress (dns_master_load*inc() only).  *	Any dns_rdata_fromtext() error code.  *	Any error code from callbacks->commit().  */
end_comment

begin_function_decl
name|void
name|dns_loadctx_detach
parameter_list|(
name|dns_loadctx_t
modifier|*
modifier|*
name|ctxp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach from the load context.  *  * Requires:  *	'*ctxp' to be valid.  *  * Ensures:  *	'*ctxp == NULL'  */
end_comment

begin_function_decl
name|void
name|dns_loadctx_attach
parameter_list|(
name|dns_loadctx_t
modifier|*
name|source
parameter_list|,
name|dns_loadctx_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach to the load context.  *  * Requires:  *	'source' to be valid.  *	'target != NULL&& *target == NULL'.  */
end_comment

begin_function_decl
name|void
name|dns_loadctx_cancel
parameter_list|(
name|dns_loadctx_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Cancel loading the zone file associated with this load context.  *  * Requires:  *	'ctx' to be valid  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_MASTER_H */
end_comment

end_unit

