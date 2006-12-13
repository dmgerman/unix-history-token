begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: cfg.h,v 1.30.12.6 2006/03/02 00:37:20 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISCCFG_CFG_H
end_ifndef

begin_define
define|#
directive|define
name|ISCCFG_CFG_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * This is the new, table-driven, YACC-free configuration file parser.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/formatcheck.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<isc/list.h>
end_include

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_typedef
typedef|typedef
name|struct
name|cfg_parser
name|cfg_parser_t
typedef|;
end_typedef

begin_comment
comment|/*  * A configuration parser.  */
end_comment

begin_comment
comment|/*  * A configuration type definition object.  There is a single  * static cfg_type_t object for each data type supported by  * the configuration parser.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|cfg_type
name|cfg_type_t
typedef|;
end_typedef

begin_comment
comment|/*  * A configuration object.  This is the basic building block of the  * configuration parse tree.  It contains a value (which may be  * of one of several types) and information identifying the file  * and line number the value came from, for printing error  * messages.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|cfg_obj
name|cfg_obj_t
typedef|;
end_typedef

begin_comment
comment|/*  * A configuration object list element.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|cfg_listelt
name|cfg_listelt_t
typedef|;
end_typedef

begin_comment
comment|/*  * A callback function to be called when parsing an option   * that needs to be interpreted at parsing time, like  * "directory".  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|cfg_parsecallback_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|clausename
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|cfg_parser_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
name|cfg_parser_t
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a configuration file parser.  Any warning and error  * messages will be logged to 'lctx'.  *  * The parser object returned can be used for a single call  * to cfg_parse_file() or cfg_parse_buffer().  It must not  * be reused for parsing multiple files or buffers.  */
end_comment

begin_function_decl
name|void
name|cfg_parser_setcallback
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
name|cfg_parsecallback_t
name|callback
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make the parser call 'callback' whenever it encounters  * a configuration clause with the callback attribute,  * passing it the clause name, the clause value,  * and 'arg' as arguments.  *  * To restore the default of not invoking callbacks, pass  * callback==NULL and arg==NULL.  */
end_comment

begin_function_decl
name|isc_result_t
name|cfg_parse_file
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
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
name|cfg_parse_buffer
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
name|isc_buffer_t
modifier|*
name|buffer
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

begin_comment
comment|/*  * Read a configuration containing data of type 'type'  * and make '*ret' point to its parse tree.  *  * The configuration is read from the file 'filename'  * (isc_parse_file()) or the buffer 'buffer'  * (isc_parse_buffer()).  *  * Returns an error if the file does not parse correctly.  *   * Requires:  *      "filename" is valid.  *      "mem" is valid.  *	"type" is valid.  *      "cfg" is non-NULL and "*cfg" is NULL.  *  * Returns:  *      ISC_R_SUCCESS                 - success  *      ISC_R_NOMEMORY                - no memory available  *      ISC_R_INVALIDFILE             - file doesn't exist or is unreadable  *      others	                      - file contains errors  */
end_comment

begin_function_decl
name|void
name|cfg_parser_destroy
parameter_list|(
name|cfg_parser_t
modifier|*
modifier|*
name|pctxp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy a configuration parser.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|cfg_obj_isvoid
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return true iff 'obj' is of void type (e.g., an optional   * value not specified).  */
end_comment

begin_function_decl
name|isc_boolean_t
name|cfg_obj_ismap
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return true iff 'obj' is of a map type.  */
end_comment

begin_function_decl
name|isc_result_t
name|cfg_map_get
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|mapobj
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Extract an element from a configuration object, which  * must be of a map type.  *  * Requires:  *      'mapobj' points to a valid configuration object of a map type.  *      'name' points to a null-terminated string.  * 	'obj' is non-NULL and '*obj' is NULL.  *  * Returns:  *      ISC_R_SUCCESS                  - success  *      ISC_R_NOTFOUND                 - name not found in map  */
end_comment

begin_function_decl
specifier|const
name|cfg_obj_t
modifier|*
name|cfg_map_getname
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|mapobj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the name of a named map object, like a server "key" clause.  *  * Requires:  *      'mapobj' points to a valid configuration object of a map type.  *  * Returns:  *      A pointer to a configuration object naming the map object,  *	or NULL if the map object does not have a name.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|cfg_obj_istuple
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return true iff 'obj' is of a map type.  */
end_comment

begin_function_decl
specifier|const
name|cfg_obj_t
modifier|*
name|cfg_tuple_get
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|tupleobj
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Extract an element from a configuration object, which  * must be of a tuple type.  *  * Requires:  *      'tupleobj' points to a valid configuration object of a tuple type.  *      'name' points to a null-terminated string naming one of the  *	fields of said tuple type.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|cfg_obj_isuint32
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return true iff 'obj' is of integer type.  */
end_comment

begin_function_decl
name|isc_uint32_t
name|cfg_obj_asuint32
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the value of a configuration object of 32-bit integer type.  *  * Requires:  *      'obj' points to a valid configuration object of 32-bit integer type.  *  * Returns:  *      A 32-bit unsigned integer.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|cfg_obj_isuint64
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return true iff 'obj' is of integer type.  */
end_comment

begin_function_decl
name|isc_uint64_t
name|cfg_obj_asuint64
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the value of a configuration object of 64-bit integer type.  *  * Requires:  *      'obj' points to a valid configuration object of 64-bit integer type.  *  * Returns:  *      A 64-bit unsigned integer.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|cfg_obj_isstring
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return true iff 'obj' is of string type.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|cfg_obj_asstring
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the value of a configuration object of a string type  * as a null-terminated string.  *  * Requires:  *      'obj' points to a valid configuration object of a string type.  *  * Returns:  *      A pointer to a null terminated string.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|cfg_obj_isboolean
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return true iff 'obj' is of a boolean type.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|cfg_obj_asboolean
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the value of a configuration object of a boolean type.  *  * Requires:  *      'obj' points to a valid configuration object of a boolean type.  *  * Returns:  *      A boolean value.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|cfg_obj_issockaddr
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return true iff 'obj' is a socket address.  */
end_comment

begin_function_decl
specifier|const
name|isc_sockaddr_t
modifier|*
name|cfg_obj_assockaddr
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the value of a configuration object representing a socket address.  *  * Requires:  *      'obj' points to a valid configuration object of a socket address type.  *  * Returns:  *      A pointer to a sockaddr.  The sockaddr must be copied by the caller  *      if necessary.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|cfg_obj_isnetprefix
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return true iff 'obj' is a network prefix.  */
end_comment

begin_function_decl
name|void
name|cfg_obj_asnetprefix
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|,
name|isc_netaddr_t
modifier|*
name|netaddr
parameter_list|,
name|unsigned
name|int
modifier|*
name|prefixlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Gets the value of a configuration object representing a network  * prefix.  The network address is returned through 'netaddr' and the  * prefix length in bits through 'prefixlen'.  *  * Requires:  *      'obj' points to a valid configuration object of network prefix type.  *	'netaddr' and 'prefixlen' are non-NULL.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|cfg_obj_islist
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return true iff 'obj' is of list type.  */
end_comment

begin_function_decl
specifier|const
name|cfg_listelt_t
modifier|*
name|cfg_list_first
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the first list element in a configuration object of a list type.  *  * Requires:  *      'obj' points to a valid configuration object of a list type or NULL.  *  * Returns:  *      A pointer to a cfg_listelt_t representing the first list element,  * 	or NULL if the list is empty or nonexistent.  */
end_comment

begin_function_decl
specifier|const
name|cfg_listelt_t
modifier|*
name|cfg_list_next
parameter_list|(
specifier|const
name|cfg_listelt_t
modifier|*
name|elt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the next element of a list of configuration objects.  *  * Requires:  *      'elt' points to cfg_listelt_t obtained from cfg_list_first() or  *	a previous call to cfg_list_next().  *  * Returns:  *      A pointer to a cfg_listelt_t representing the next element,  * 	or NULL if there are no more elements.  */
end_comment

begin_function_decl
specifier|const
name|cfg_obj_t
modifier|*
name|cfg_listelt_value
parameter_list|(
specifier|const
name|cfg_listelt_t
modifier|*
name|elt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the configuration object associated with cfg_listelt_t.  *  * Requires:  *      'elt' points to cfg_listelt_t obtained from cfg_list_first() or  *	cfg_list_next().  *  * Returns:  *      A non-NULL pointer to a configuration object.  */
end_comment

begin_function_decl
name|void
name|cfg_print
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|,
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
parameter_list|,
name|void
modifier|*
name|closure
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Print the configuration object 'obj' by repeatedly calling the  * function 'f', passing 'closure' and a region of text starting  * at 'text' and comprising 'textlen' characters.  */
end_comment

begin_function_decl
name|void
name|cfg_print_grammar
parameter_list|(
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|,
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
parameter_list|,
name|void
modifier|*
name|closure
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Print a summary of the grammar of the configuration type 'type'.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|cfg_obj_istype
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|,
specifier|const
name|cfg_type_t
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return true iff 'obj' is of type 'type'.   */
end_comment

begin_function_decl
name|void
name|cfg_obj_destroy
parameter_list|(
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy a configuration object.  */
end_comment

begin_function_decl
name|void
name|cfg_obj_log
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|,
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
name|int
name|level
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
function_decl|4
operator|,
function_decl|5
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Log a message concerning configuration object 'obj' to the logging  * channel of 'pctx', at log level 'level'.  The message will be prefixed  * with the file name(s) and line number where 'obj' was defined.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|cfg_obj_file
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the file that defined this object.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|cfg_obj_line
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the line in file where this object was defined.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISCCFG_CFG_H */
end_comment

end_unit

