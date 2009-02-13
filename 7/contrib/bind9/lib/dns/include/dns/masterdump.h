begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: masterdump.h,v 1.31.14.4 2005/09/01 03:04:28 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_MASTERDUMP_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_MASTERDUMP_H
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
comment|/***  *** Types  ***/
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_master_style
name|dns_master_style_t
typedef|;
end_typedef

begin_comment
comment|/***  *** Definitions  ***/
end_comment

begin_comment
comment|/*  * Flags affecting master file formatting.  Flags 0x0000FFFF  * define the formatting of the rdata part and are defined in  * rdata.h.  */
end_comment

begin_comment
comment|/*% Omit the owner name when possible. */
end_comment

begin_define
define|#
directive|define
name|DNS_STYLEFLAG_OMIT_OWNER
value|0x00010000U
end_define

begin_comment
comment|/*%  * Omit the TTL when possible.  If DNS_STYLEFLAG_TTL is  * also set, this means no TTLs are ever printed  * because $TTL directives are generated before every  * change in the TTL.  In this case, no columns need to  * be reserved for the TTL.  Master files generated with  * these options will be rejected by BIND 4.x because it  * does not recognize the $TTL directive.  *  * If DNS_STYLEFLAG_TTL is not also set, the TTL will be  * omitted when it is equal to the previous TTL.  * This is correct according to RFC1035, but the  * TTLs may be silently misinterpreted by older  * versions of BIND which use the SOA MINTTL as a  * default TTL value.  */
end_comment

begin_define
define|#
directive|define
name|DNS_STYLEFLAG_OMIT_TTL
value|0x00020000U
end_define

begin_comment
comment|/*% Omit the class when possible. */
end_comment

begin_define
define|#
directive|define
name|DNS_STYLEFLAG_OMIT_CLASS
value|0x00040000U
end_define

begin_comment
comment|/*% Output $TTL directives. */
end_comment

begin_define
define|#
directive|define
name|DNS_STYLEFLAG_TTL
value|0x00080000U
end_define

begin_comment
comment|/*%  * Output $ORIGIN directives and print owner names relative to  * the origin when possible.  */
end_comment

begin_define
define|#
directive|define
name|DNS_STYLEFLAG_REL_OWNER
value|0x00100000U
end_define

begin_comment
comment|/*% Print domain names in RR data in relative form when possible.    For this to take effect, DNS_STYLEFLAG_REL_OWNER must also be set. */
end_comment

begin_define
define|#
directive|define
name|DNS_STYLEFLAG_REL_DATA
value|0x00200000U
end_define

begin_comment
comment|/*% Print the trust level of each rdataset. */
end_comment

begin_define
define|#
directive|define
name|DNS_STYLEFLAG_TRUST
value|0x00400000U
end_define

begin_comment
comment|/*% Print negative caching entries. */
end_comment

begin_define
define|#
directive|define
name|DNS_STYLEFLAG_NCACHE
value|0x00800000U
end_define

begin_comment
comment|/*% Never print the TTL */
end_comment

begin_define
define|#
directive|define
name|DNS_STYLEFLAG_NO_TTL
value|0x01000000U
end_define

begin_comment
comment|/*% Never print the CLASS */
end_comment

begin_define
define|#
directive|define
name|DNS_STYLEFLAG_NO_CLASS
value|0x02000000U
end_define

begin_decl_stmt
name|ISC_LANG_BEGINDECLS
comment|/***  ***	Constants  ***/
comment|/*%  * The default master file style.  *  * This uses $TTL directives to avoid the need to dedicate a  * tab stop for the TTL.  The class is only printed for the first  * rrset in the file and shares a tab stop with the RR type.  */
name|LIBDNS_EXTERNAL_DATA
specifier|extern
specifier|const
name|dns_master_style_t
name|dns_master_style_default
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*%  * A master file style that dumps zones to a very generic format easily  * imported/checked with external tools.  */
end_comment

begin_decl_stmt
name|LIBDNS_EXTERNAL_DATA
specifier|extern
specifier|const
name|dns_master_style_t
name|dns_master_style_full
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*%  * A master file style that prints explicit TTL values on each   * record line, never using $TTL statements.  The TTL has a tab   * stop of its own, but the class and type share one.  */
end_comment

begin_decl_stmt
name|LIBDNS_EXTERNAL_DATA
specifier|extern
specifier|const
name|dns_master_style_t
name|dns_master_style_explicitttl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*%  * A master style format designed for cache files.  It prints explicit TTL  * values on each record line and never uses $ORIGIN or relative names.  */
end_comment

begin_decl_stmt
name|LIBDNS_EXTERNAL_DATA
specifier|extern
specifier|const
name|dns_master_style_t
name|dns_master_style_cache
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*%  * A master style that prints name, ttl, class, type, and value on   * every line.  Similar to explicitttl above, but more verbose.    * Intended for generating master files which can be easily parsed   * by perl scripts and similar applications.  */
end_comment

begin_decl_stmt
name|LIBDNS_EXTERNAL_DATA
specifier|extern
specifier|const
name|dns_master_style_t
name|dns_master_style_simple
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*%  * The style used for debugging, "dig" output, etc.  */
end_comment

begin_decl_stmt
name|LIBDNS_EXTERNAL_DATA
specifier|extern
specifier|const
name|dns_master_style_t
name|dns_master_style_debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***  ***	Functions  ***/
end_comment

begin_function_decl
name|void
name|dns_dumpctx_attach
parameter_list|(
name|dns_dumpctx_t
modifier|*
name|source
parameter_list|,
name|dns_dumpctx_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Attach to a dump context.  *  * Require:  *\li	'source' to be valid.  *\li	'target' to be non NULL and '*target' to be NULL.  */
end_comment

begin_function_decl
name|void
name|dns_dumpctx_detach
parameter_list|(
name|dns_dumpctx_t
modifier|*
modifier|*
name|dctxp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Detach from a dump context.  *  * Require:  *\li	'dctxp' to point to a valid dump context.  *  * Ensures:  *\li	'*dctxp' is NULL.  */
end_comment

begin_function_decl
name|void
name|dns_dumpctx_cancel
parameter_list|(
name|dns_dumpctx_t
modifier|*
name|dctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Cancel a in progress dump.  *  * Require:  *\li	'dctx' to be valid.  */
end_comment

begin_function_decl
name|dns_dbversion_t
modifier|*
name|dns_dumpctx_version
parameter_list|(
name|dns_dumpctx_t
modifier|*
name|dctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the version handle (if any) of the database being dumped.  *  * Require:  *\li	'dctx' to be valid.  */
end_comment

begin_function_decl
name|dns_db_t
modifier|*
name|dns_dumpctx_db
parameter_list|(
name|dns_dumpctx_t
modifier|*
name|dctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the database being dumped.  *  * Require:  *\li	'dctx' to be valid.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_function_decl
name|isc_result_t
name|dns_master_dumptostreaminc
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
specifier|const
name|dns_master_style_t
modifier|*
name|style
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|dns_dumpdonefunc_t
name|done
parameter_list|,
name|void
modifier|*
name|done_arg
parameter_list|,
name|dns_dumpctx_t
modifier|*
modifier|*
name|dctxp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_master_dumptostream
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
specifier|const
name|dns_master_style_t
modifier|*
name|style
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_master_dumptostream2
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
specifier|const
name|dns_master_style_t
modifier|*
name|style
parameter_list|,
name|dns_masterformat_t
name|format
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Dump the database 'db' to the steam 'f' in the specified format by  * 'format'.  If the format is dns_masterformat_text (the RFC1035 format),  * 'style' specifies the file style (e.g.,&dns_master_style_default).  *  * dns_master_dumptostream() is an old form of dns_master_dumptostream2(),  * which always specifies the dns_masterformat_text format.  *  * Temporary dynamic memory may be allocated from 'mctx'.  *  * Require:  *\li	'task' to be valid.  *\li	'done' to be non NULL.  *\li	'dctxp' to be non NULL&& '*dctxp' to be NULL.  *   * Returns:  *\li	ISC_R_SUCCESS  *\li	ISC_R_CONTINUE	dns_master_dumptostreaminc() only.  *\li	ISC_R_NOMEMORY  *\li	Any database or rrset iterator error.  *\li	Any dns_rdata_totext() error code.  */
end_comment

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_function_decl
name|isc_result_t
name|dns_master_dumpinc
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
specifier|const
name|dns_master_style_t
modifier|*
name|style
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|dns_dumpdonefunc_t
name|done
parameter_list|,
name|void
modifier|*
name|done_arg
parameter_list|,
name|dns_dumpctx_t
modifier|*
modifier|*
name|dctxp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_master_dumpinc2
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
specifier|const
name|dns_master_style_t
modifier|*
name|style
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|dns_dumpdonefunc_t
name|done
parameter_list|,
name|void
modifier|*
name|done_arg
parameter_list|,
name|dns_dumpctx_t
modifier|*
modifier|*
name|dctxp
parameter_list|,
name|dns_masterformat_t
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_master_dump
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
specifier|const
name|dns_master_style_t
modifier|*
name|style
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_master_dump2
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
specifier|const
name|dns_master_style_t
modifier|*
name|style
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|dns_masterformat_t
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Dump the database 'db' to the file 'filename' in the specified format by  * 'format'.  If the format is dns_masterformat_text (the RFC1035 format),  * 'style' specifies the file style (e.g.,&dns_master_style_default).  *  * dns_master_dumpinc() and dns_master_dump() are old forms of _dumpinc2()  * and _dump2(), respectively, which always specify the dns_masterformat_text  * format.  *  * Temporary dynamic memory may be allocated from 'mctx'.  *  * Returns:  *\li	ISC_R_SUCCESS  *\li	ISC_R_CONTINUE	dns_master_dumpinc() only.  *\li	ISC_R_NOMEMORY  *\li	Any database or rrset iterator error.  *\li	Any dns_rdata_totext() error code.  */
end_comment

begin_comment
comment|/*@}*/
end_comment

begin_function_decl
name|isc_result_t
name|dns_master_rdatasettotext
parameter_list|(
name|dns_name_t
modifier|*
name|owner_name
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
specifier|const
name|dns_master_style_t
modifier|*
name|style
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Convert 'rdataset' to text format, storing the result in 'target'.  *  * Notes:  *\li	The rdata cursor position will be changed.  *  * Requires:  *\li	'rdataset' is a valid non-question rdataset.  *  *\li	'rdataset' is not empty.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_master_questiontotext
parameter_list|(
name|dns_name_t
modifier|*
name|owner_name
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
specifier|const
name|dns_master_style_t
modifier|*
name|style
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_master_dumpnodetostream
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
specifier|const
name|dns_master_style_t
modifier|*
name|style
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_master_dumpnode
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
specifier|const
name|dns_master_style_t
modifier|*
name|style
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_master_stylecreate
parameter_list|(
name|dns_master_style_t
modifier|*
modifier|*
name|style
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|,
name|unsigned
name|int
name|ttl_column
parameter_list|,
name|unsigned
name|int
name|class_column
parameter_list|,
name|unsigned
name|int
name|type_column
parameter_list|,
name|unsigned
name|int
name|rdata_column
parameter_list|,
name|unsigned
name|int
name|line_length
parameter_list|,
name|unsigned
name|int
name|tab_width
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_master_styledestroy
parameter_list|(
name|dns_master_style_t
modifier|*
modifier|*
name|style
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_MASTERDUMP_H */
end_comment

end_unit

