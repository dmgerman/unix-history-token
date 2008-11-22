begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1996-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: symtab.h,v 1.16.206.3 2006/03/02 00:37:20 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_SYMTAB_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_SYMTAB_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Symbol Table  *  * Provides a simple memory-based symbol table.  *  * Keys are C strings, and key comparisons are case-insenstive.  A type may  * be specified when looking up, defining, or undefining.  A type value of  * 0 means "match any type"; any other value will only match the given  * type.  *  * It's possible that a client will attempt to define a<key, type, value>  * tuple when a tuple with the given key and type already exists in the table.  * What to do in this case is specified by the client.  Possible policies are:  *  *	isc_symexists_reject	Disallow the define, returning ISC_R_EXISTS  *	isc_symexists_replace	Replace the old value with the new.  The  *				undefine action (if provided) will be called  *				with the old<key, type, value> tuple.  *	isc_symexists_add	Add the new tuple, leaving the old tuple in  *				the table.  Subsequent lookups will retrieve  *				the most-recently-defined tuple.  *  * A lookup of a key using type 0 will return the most-recently defined  * symbol with that key.  An undefine of a key using type 0 will undefine the  * most-recently defined symbol with that key.  Trying to define a key with  * type 0 is illegal.  *  * The symbol table library does not make a copy the key field, so the  * caller must ensure that any key it passes to isc_symtab_define() will not  * change until it calls isc_symtab_undefine() or isc_symtab_destroy().  *  * A user-specified action will be called (if provided) when a symbol is  * undefined.  It can be used to free memory associated with keys and/or  * values.  *  * MP:  *	The callers of this module must ensure any required synchronization.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *<TBS>  *  * Security:  *	No anticipated impact.  *  * Standards:  *	None.  */
end_comment

begin_comment
comment|/***  *** Imports.  ***/
end_comment

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

begin_comment
comment|/***  *** Symbol Tables.  ***/
end_comment

begin_typedef
typedef|typedef
union|union
name|isc_symvalue
block|{
name|void
modifier|*
name|as_pointer
decl_stmt|;
specifier|const
name|void
modifier|*
name|as_cpointer
decl_stmt|;
name|int
name|as_integer
decl_stmt|;
name|unsigned
name|int
name|as_uinteger
decl_stmt|;
block|}
name|isc_symvalue_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|isc_symtabaction_t
function_decl|)
parameter_list|(
name|char
modifier|*
name|key
parameter_list|,
name|unsigned
name|int
name|type
parameter_list|,
name|isc_symvalue_t
name|value
parameter_list|,
name|void
modifier|*
name|userarg
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|isc_symexists_reject
init|=
literal|0
block|,
name|isc_symexists_replace
init|=
literal|1
block|,
name|isc_symexists_add
init|=
literal|2
block|}
name|isc_symexists_t
typedef|;
end_typedef

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|isc_symtab_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|,
name|isc_symtabaction_t
name|undefine_action
parameter_list|,
name|void
modifier|*
name|undefine_arg
parameter_list|,
name|isc_boolean_t
name|case_sensitive
parameter_list|,
name|isc_symtab_t
modifier|*
modifier|*
name|symtabp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_symtab_destroy
parameter_list|(
name|isc_symtab_t
modifier|*
modifier|*
name|symtabp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_symtab_lookup
parameter_list|(
name|isc_symtab_t
modifier|*
name|symtab
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|unsigned
name|int
name|type
parameter_list|,
name|isc_symvalue_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_symtab_define
parameter_list|(
name|isc_symtab_t
modifier|*
name|symtab
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|unsigned
name|int
name|type
parameter_list|,
name|isc_symvalue_t
name|value
parameter_list|,
name|isc_symexists_t
name|exists_policy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_symtab_undefine
parameter_list|(
name|isc_symtab_t
modifier|*
name|symtab
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|unsigned
name|int
name|type
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
comment|/* ISC_SYMTAB_H */
end_comment

end_unit

