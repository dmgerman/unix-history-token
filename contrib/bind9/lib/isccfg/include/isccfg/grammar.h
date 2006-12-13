begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2002, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: grammar.h,v 1.3.50.6 2006/03/02 00:37:20 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISCCFG_GRAMMAR_H
end_ifndef

begin_define
define|#
directive|define
name|ISCCFG_GRAMMAR_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/lex.h>
end_include

begin_include
include|#
directive|include
file|<isc/netaddr.h>
end_include

begin_include
include|#
directive|include
file|<isc/sockaddr.h>
end_include

begin_include
include|#
directive|include
file|<isc/region.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<isccfg/cfg.h>
end_include

begin_comment
comment|/*  * Definitions shared between the configuration parser  * and the grammars; not visible to users of the parser.  */
end_comment

begin_comment
comment|/* Clause may occur multiple times (e.g., "zone") */
end_comment

begin_define
define|#
directive|define
name|CFG_CLAUSEFLAG_MULTI
value|0x00000001
end_define

begin_comment
comment|/* Clause is obsolete */
end_comment

begin_define
define|#
directive|define
name|CFG_CLAUSEFLAG_OBSOLETE
value|0x00000002
end_define

begin_comment
comment|/* Clause is not implemented, and may never be */
end_comment

begin_define
define|#
directive|define
name|CFG_CLAUSEFLAG_NOTIMP
value|0x00000004
end_define

begin_comment
comment|/* Clause is not implemented yet */
end_comment

begin_define
define|#
directive|define
name|CFG_CLAUSEFLAG_NYI
value|0x00000008
end_define

begin_comment
comment|/* Default value has changed since earlier release */
end_comment

begin_define
define|#
directive|define
name|CFG_CLAUSEFLAG_NEWDEFAULT
value|0x00000010
end_define

begin_comment
comment|/*  * Clause needs to be interpreted during parsing  * by calling a callback function, like the  * "directory" option.  */
end_comment

begin_define
define|#
directive|define
name|CFG_CLAUSEFLAG_CALLBACK
value|0x00000020
end_define

begin_typedef
typedef|typedef
name|struct
name|cfg_clausedef
name|cfg_clausedef_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cfg_tuplefielddef
name|cfg_tuplefielddef_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cfg_printer
name|cfg_printer_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|cfg_listelt_t
argument_list|)
name|cfg_list_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cfg_map
name|cfg_map_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cfg_rep
name|cfg_rep_t
typedef|;
end_typedef

begin_comment
comment|/*  * Function types for configuration object methods  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|cfg_parsefunc_t
function_decl|)
parameter_list|(
name|cfg_parser_t
modifier|*
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cfg_printfunc_t
function_decl|)
parameter_list|(
name|cfg_printer_t
modifier|*
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cfg_docfunc_t
function_decl|)
parameter_list|(
name|cfg_printer_t
modifier|*
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cfg_freefunc_t
function_decl|)
parameter_list|(
name|cfg_parser_t
modifier|*
parameter_list|,
name|cfg_obj_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Structure definitions  */
end_comment

begin_comment
comment|/*  * A configuration printer object.  This is an abstract  * interface to a destination to which text can be printed  * by calling the function 'f'.  */
end_comment

begin_struct
struct|struct
name|cfg_printer
block|{
name|void
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|void
modifier|*
name|closure
parameter_list|,
specifier|const
name|char
modifier|*
name|text
parameter_list|,
name|int
name|textlen
parameter_list|)
function_decl|;
name|void
modifier|*
name|closure
decl_stmt|;
name|int
name|indent
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A clause definition. */
end_comment

begin_struct
struct|struct
name|cfg_clausedef
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|cfg_type_t
modifier|*
name|type
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A tuple field definition. */
end_comment

begin_struct
struct|struct
name|cfg_tuplefielddef
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|cfg_type_t
modifier|*
name|type
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A configuration object type definition. */
end_comment

begin_struct
struct|struct
name|cfg_type
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* For debugging purposes only */
name|cfg_parsefunc_t
name|parse
decl_stmt|;
name|cfg_printfunc_t
name|print
decl_stmt|;
name|cfg_docfunc_t
name|doc
decl_stmt|;
comment|/* Print grammar description */
name|cfg_rep_t
modifier|*
name|rep
decl_stmt|;
comment|/* Data representation */
specifier|const
name|void
modifier|*
name|of
decl_stmt|;
comment|/* Additional data for meta-types */
block|}
struct|;
end_struct

begin_comment
comment|/* A keyword-type definition, for things like "port<integer>". */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|cfg_type_t
modifier|*
name|type
decl_stmt|;
block|}
name|keyword_type_t
typedef|;
end_typedef

begin_struct
struct|struct
name|cfg_map
block|{
name|cfg_obj_t
modifier|*
name|id
decl_stmt|;
comment|/* Used for 'named maps' like keys, zones,&c */
specifier|const
name|cfg_clausedef_t
modifier|*
specifier|const
modifier|*
name|clausesets
decl_stmt|;
comment|/* The clauses that 						      can occur in this map; 						      used for printing */
name|isc_symtab_t
modifier|*
name|symtab
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cfg_netprefix
name|cfg_netprefix_t
typedef|;
end_typedef

begin_struct
struct|struct
name|cfg_netprefix
block|{
name|isc_netaddr_t
name|address
decl_stmt|;
comment|/* IP4/IP6 */
name|unsigned
name|int
name|prefixlen
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * A configuration data representation.  */
end_comment

begin_struct
struct|struct
name|cfg_rep
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* For debugging only */
name|cfg_freefunc_t
name|free
decl_stmt|;
comment|/* How to free this kind of data. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A configuration object.  This is the main building block  * of the configuration parse tree.  */
end_comment

begin_struct
struct|struct
name|cfg_obj
block|{
specifier|const
name|cfg_type_t
modifier|*
name|type
decl_stmt|;
union|union
block|{
name|isc_uint32_t
name|uint32
decl_stmt|;
name|isc_uint64_t
name|uint64
decl_stmt|;
name|isc_textregion_t
name|string
decl_stmt|;
comment|/* null terminated, too */
name|isc_boolean_t
name|boolean
decl_stmt|;
name|cfg_map_t
name|map
decl_stmt|;
name|cfg_list_t
name|list
decl_stmt|;
name|cfg_obj_t
modifier|*
modifier|*
name|tuple
decl_stmt|;
name|isc_sockaddr_t
name|sockaddr
decl_stmt|;
name|cfg_netprefix_t
name|netprefix
decl_stmt|;
block|}
name|value
union|;
specifier|const
name|char
modifier|*
name|file
decl_stmt|;
name|unsigned
name|int
name|line
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A list element. */
end_comment

begin_struct
struct|struct
name|cfg_listelt
block|{
name|cfg_obj_t
modifier|*
name|obj
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|cfg_listelt_t
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The parser object. */
end_comment

begin_struct
struct|struct
name|cfg_parser
block|{
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|isc_log_t
modifier|*
name|lctx
decl_stmt|;
name|isc_lex_t
modifier|*
name|lexer
decl_stmt|;
name|unsigned
name|int
name|errors
decl_stmt|;
name|unsigned
name|int
name|warnings
decl_stmt|;
name|isc_token_t
name|token
decl_stmt|;
comment|/* We are at the end of all input. */
name|isc_boolean_t
name|seen_eof
decl_stmt|;
comment|/* The current token has been pushed back. */
name|isc_boolean_t
name|ungotten
decl_stmt|;
comment|/* 	 * The stack of currently active files, represented 	 * as a configuration list of configuration strings. 	 * The head is the top-level file, subsequent elements  	 * (if any) are the nested include files, and the  	 * last element is the file currently being parsed. 	 */
name|cfg_obj_t
modifier|*
name|open_files
decl_stmt|;
comment|/* 	 * Names of files that we have parsed and closed 	 * and were previously on the open_file list. 	 * We keep these objects around after closing 	 * the files because the file names may still be 	 * referenced from other configuration objects 	 * for use in reporting semantic errors after 	 * parsing is complete. 	 */
name|cfg_obj_t
modifier|*
name|closed_files
decl_stmt|;
comment|/* 	 * Current line number.  We maintain our own 	 * copy of this so that it is available even 	 * when a file has just been closed. 	 */
name|unsigned
name|int
name|line
decl_stmt|;
name|cfg_parsecallback_t
name|callback
decl_stmt|;
name|void
modifier|*
name|callbackarg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags defining whether to accept certain types of network addresses.  */
end_comment

begin_define
define|#
directive|define
name|CFG_ADDR_V4OK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CFG_ADDR_V4PREFIXOK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CFG_ADDR_V6OK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CFG_ADDR_WILDOK
value|0x00000008
end_define

begin_comment
comment|/*  * Predefined data representation types.  */
end_comment

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_rep_t
name|cfg_rep_uint32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_rep_t
name|cfg_rep_uint64
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_rep_t
name|cfg_rep_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_rep_t
name|cfg_rep_boolean
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_rep_t
name|cfg_rep_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_rep_t
name|cfg_rep_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_rep_t
name|cfg_rep_tuple
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_rep_t
name|cfg_rep_sockaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_rep_t
name|cfg_rep_netprefix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_rep_t
name|cfg_rep_void
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Predefined configuration object types.  */
end_comment

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_type_t
name|cfg_type_boolean
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_type_t
name|cfg_type_uint32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_type_t
name|cfg_type_uint64
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_type_t
name|cfg_type_qstring
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_type_t
name|cfg_type_astring
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_type_t
name|cfg_type_ustring
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_type_t
name|cfg_type_sockaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_type_t
name|cfg_type_netaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_type_t
name|cfg_type_netprefix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_type_t
name|cfg_type_void
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_type_t
name|cfg_type_token
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_type_t
name|cfg_type_unsupported
decl_stmt|;
end_decl_stmt

begin_function_decl
name|isc_result_t
name|cfg_gettoken
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
name|int
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_peektoken
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
name|int
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_ungettoken
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CFG_LEXOPT_QSTRING
value|(ISC_LEXOPT_QSTRING | ISC_LEXOPT_QSTRINGMULTILINE)
end_define

begin_function_decl
name|isc_result_t
name|cfg_create_obj
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_print_rawuint
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
name|unsigned
name|int
name|u
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_uint32
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_print_uint32
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_print_uint64
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_qstring
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_print_ustring
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_astring
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_rawaddr
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|,
name|isc_netaddr_t
modifier|*
name|na
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_print_rawaddr
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|isc_netaddr_t
modifier|*
name|na
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_boolean_t
name|cfg_lookingat_netaddr
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_rawport
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|,
name|in_port_t
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_sockaddr
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_print_sockaddr
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_doc_sockaddr
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_netprefix
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_special
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
name|int
name|special
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Parse a required special character 'special'. */
end_comment

begin_function_decl
name|isc_result_t
name|cfg_create_tuple
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_tuple
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_print_tuple
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_doc_tuple
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_create_list
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_listelt
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|elttype
parameter_list|,
name|cfg_listelt_t
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_bracketed_list
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_print_bracketed_list
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_doc_bracketed_list
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_spacelist
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_print_spacelist
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_enum
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_doc_enum
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_print_chars
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|char
modifier|*
name|text
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print 'len' characters at 'text' */
end_comment

begin_function_decl
name|void
name|cfg_print_cstr
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print the null-terminated string 's' */
end_comment

begin_function_decl
name|isc_result_t
name|cfg_parse_map
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_named_map
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_addressed_map
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_print_map
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_doc_map
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_mapbody
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_print_mapbody
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_doc_mapbody
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_void
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_print_void
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_doc_void
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|cfg_parse_obj
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_print_obj
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_doc_obj
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Print a description of the grammar of an arbitrary configuration  * type 'type'  */
end_comment

begin_function_decl
name|void
name|cfg_doc_terminal
parameter_list|(
name|cfg_printer_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Document the type 'type' as a terminal by printing its  * name in angle brackets, e.g.,<uint32>.  */
end_comment

begin_function_decl
name|void
name|cfg_parser_error
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Pass one of these flags to cfg_parser_error() to include the  * token text in log message.  */
end_comment

begin_define
define|#
directive|define
name|CFG_LOG_NEAR
value|0x00000001
end_define

begin_comment
comment|/* Say "near<token>" */
end_comment

begin_define
define|#
directive|define
name|CFG_LOG_BEFORE
value|0x00000002
end_define

begin_comment
comment|/* Say "before<token>" */
end_comment

begin_define
define|#
directive|define
name|CFG_LOG_NOPREP
value|0x00000004
end_define

begin_comment
comment|/* Say just "<token>" */
end_comment

begin_function_decl
name|void
name|cfg_parser_warning
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|isc_boolean_t
name|cfg_is_enum
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|enums
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true iff the string 's' is one of the strings in 'enums' */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISCCFG_GRAMMAR_H */
end_comment

end_unit

