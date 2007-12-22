begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: master.h,v 1.38.18.6 2005/06/20 01:19:43 marka Exp $ */
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
comment|/*! \file */
end_comment

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
comment|/*%< Age the ttl based on $DATE. */
end_comment

begin_define
define|#
directive|define
name|DNS_MASTER_MANYERRORS
value|0x00000002
end_define

begin_comment
comment|/*%< Continue processing on errors. */
end_comment

begin_define
define|#
directive|define
name|DNS_MASTER_NOINCLUDE
value|0x00000004
end_define

begin_comment
comment|/*%< Disallow $INCLUDE directives. */
end_comment

begin_define
define|#
directive|define
name|DNS_MASTER_ZONE
value|0x00000008
end_define

begin_comment
comment|/*%< Loading a zone master file. */
end_comment

begin_define
define|#
directive|define
name|DNS_MASTER_HINT
value|0x00000010
end_define

begin_comment
comment|/*%< Loading a hint master file. */
end_comment

begin_define
define|#
directive|define
name|DNS_MASTER_SLAVE
value|0x00000020
end_define

begin_comment
comment|/*%< Loading a slave master file. */
end_comment

begin_define
define|#
directive|define
name|DNS_MASTER_CHECKNS
value|0x00000040
end_define

begin_comment
comment|/*%< 						 * Check NS records to see  						 * if they are an address 						 */
end_comment

begin_define
define|#
directive|define
name|DNS_MASTER_FATALNS
value|0x00000080
end_define

begin_comment
comment|/*%< 						 * Treat DNS_MASTER_CHECKNS 						 * matches as fatal 						 */
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

begin_define
define|#
directive|define
name|DNS_MASTER_CHECKWILDCARD
value|0x00000400
end_define

begin_comment
comment|/* Check for internal wildcards. */
end_comment

begin_define
define|#
directive|define
name|DNS_MASTER_CHECKMX
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DNS_MASTER_CHECKMXFAIL
value|0x00001000
end_define

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/*  * Structures that implement the "raw" format for master dump.  * These are provided for a reference purpose only; in the actual  * encoding, we directly read/write each field so that the encoded data  * is always "packed", regardless of the hardware architecture.  */
end_comment

begin_define
define|#
directive|define
name|DNS_RAWFORMAT_VERSION
value|0
end_define

begin_comment
comment|/* Common header */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isc_uint32_t
name|format
decl_stmt|;
comment|/* must be 						 * dns_masterformat_raw */
name|isc_uint32_t
name|version
decl_stmt|;
comment|/* compatibility for future 						 * extensions */
name|isc_uint32_t
name|dumptime
decl_stmt|;
comment|/* timestamp on creation 						 * (currently unused) 						 */
block|}
name|dns_masterrawheader_t
typedef|;
end_typedef

begin_comment
comment|/* The structure for each RRset */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isc_uint32_t
name|totallen
decl_stmt|;
comment|/* length of the data for this 						 * RRset, including the 						 * "header" part */
name|dns_rdataclass_t
name|rdclass
decl_stmt|;
comment|/* 16-bit class */
name|dns_rdatatype_t
name|type
decl_stmt|;
comment|/* 16-bit type */
name|dns_rdatatype_t
name|covers
decl_stmt|;
comment|/* same as type */
name|dns_ttl_t
name|ttl
decl_stmt|;
comment|/* 32-bit TTL */
name|isc_uint32_t
name|nrdata
decl_stmt|;
comment|/* number of RRs in this set */
comment|/* followed by encoded owner name, and then rdata */
block|}
name|dns_masterrawrdataset_t
typedef|;
end_typedef

begin_comment
comment|/***  ***	Function  ***/
end_comment

begin_function_decl
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
name|dns_master_loadfile2
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
parameter_list|,
name|dns_masterformat_t
name|format
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
name|dns_master_loadfileinc2
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
parameter_list|,
name|dns_masterformat_t
name|format
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
comment|/*%<  * Loads a RFC1305 master file from a file, stream, buffer, or existing  * lexer into rdatasets and then calls 'callbacks->commit' to commit the  * rdatasets.  Rdata memory belongs to dns_master_load and will be  * reused / released when the callback completes.  dns_load_master will  * abort if callbacks->commit returns any value other than ISC_R_SUCCESS.  *  * If 'DNS_MASTER_AGETTL' is set and the master file contains one or more  * $DATE directives, the TTLs of the data will be aged accordingly.  *  * 'callbacks->commit' is assumed to call 'callbacks->error' or  * 'callbacks->warn' to generate any error messages required.  *  * 'done' is called with 'done_arg' and a result code when the loading  * is completed or has failed.  If the initial setup fails 'done' is  * not called.  *  * Requires:  *\li	'master_file' points to a valid string.  *\li	'lexer' points to a valid lexer.  *\li	'top' points to a valid name.  *\li	'origin' points to a valid name.  *\li	'callbacks->commit' points to a valid function.  *\li	'callbacks->error' points to a valid function.  *\li	'callbacks->warn' points to a valid function.  *\li	'mctx' points to a valid memory context.  *\li	'task' and 'done' to be valid.  *\li	'lmgr' to be valid.  *\li	'ctxp != NULL&& ctxp == NULL'.  *  * Returns:  *\li	ISC_R_SUCCESS upon successfully loading the master file.  *\li	ISC_R_SEENINCLUDE upon successfully loading the master file with  *		a $INCLUDE statement.  *\li	ISC_R_NOMEMORY out of memory.  *\li	ISC_R_UNEXPECTEDEND expected to be able to read a input token and  *		there was not one.  *\li	ISC_R_UNEXPECTED  *\li	DNS_R_NOOWNER failed to specify a ownername.  *\li	DNS_R_NOTTL failed to specify a ttl.  *\li	DNS_R_BADCLASS record class did not match zone class.  *\li	DNS_R_CONTINUE load still in progress (dns_master_load*inc() only).  *\li	Any dns_rdata_fromtext() error code.  *\li	Any error code from callbacks->commit().  */
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
comment|/*%<  * Detach from the load context.  *  * Requires:  *\li	'*ctxp' to be valid.  *  * Ensures:  *\li	'*ctxp == NULL'  */
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
comment|/*%<  * Attach to the load context.  *  * Requires:  *\li	'source' to be valid.  *\li	'target != NULL&& *target == NULL'.  */
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
comment|/*%<  * Cancel loading the zone file associated with this load context.  *  * Requires:  *\li	'ctx' to be valid  */
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

