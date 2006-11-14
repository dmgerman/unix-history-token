begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: dbtable.h,v 1.16.206.1 2004/03/06 08:13:55 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_DBTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_DBTABLE_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * DNS DB Tables  *  * XXX<TBS> XXX  *  * MP:  *	The module ensures appropriate synchronization of data structures it  *	creates and manipulates.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *	None.  *  * Security:  *	No anticipated impact.  *  * Standards:  *	None.  */
end_comment

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

begin_define
define|#
directive|define
name|DNS_DBTABLEFIND_NOEXACT
value|0x01
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_dbtable_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_dbtable_t
modifier|*
modifier|*
name|dbtablep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make a new dbtable of class 'rdclass'  *  * Requires:  *	mctx != NULL  * 	dbtablep != NULL&& *dptablep == NULL  *	'rdclass' is a valid class  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|void
name|dns_dbtable_attach
parameter_list|(
name|dns_dbtable_t
modifier|*
name|source
parameter_list|,
name|dns_dbtable_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach '*targetp' to 'source'.  *  * Requires:  *  *	'source' is a valid dbtable.  *  *	'targetp' points to a NULL dns_dbtable_t *.  *  * Ensures:  *  *	*targetp is attached to source.  */
end_comment

begin_function_decl
name|void
name|dns_dbtable_detach
parameter_list|(
name|dns_dbtable_t
modifier|*
modifier|*
name|dbtablep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach *dbtablep from its dbtable.  *  * Requires:  *  *	'*dbtablep' points to a valid dbtable.  *  * Ensures:  *  *	*dbtablep is NULL.  *  *	If '*dbtablep' is the last reference to the dbtable,  *  *		All resources used by the dbtable will be freed  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dbtable_add
parameter_list|(
name|dns_dbtable_t
modifier|*
name|dbtable
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Add 'db' to 'dbtable'.  *  * Requires:  *	'dbtable' is a valid dbtable.  *  *	'db' is a valid database with the same class as 'dbtable'  */
end_comment

begin_function_decl
name|void
name|dns_dbtable_remove
parameter_list|(
name|dns_dbtable_t
modifier|*
name|dbtable
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Remove 'db' from 'dbtable'.  *  * Requires:  *	'db' was previously added to 'dbtable'.  */
end_comment

begin_function_decl
name|void
name|dns_dbtable_adddefault
parameter_list|(
name|dns_dbtable_t
modifier|*
name|dbtable
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Use 'db' as the result of a dns_dbtable_find() if no better match is  * available.  */
end_comment

begin_function_decl
name|void
name|dns_dbtable_getdefault
parameter_list|(
name|dns_dbtable_t
modifier|*
name|dbtable
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the 'db' used as the result of a dns_dbtable_find()  * if no better match is available.  */
end_comment

begin_function_decl
name|void
name|dns_dbtable_removedefault
parameter_list|(
name|dns_dbtable_t
modifier|*
name|dbtable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Remove the default db from 'dbtable'.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dbtable_find
parameter_list|(
name|dns_dbtable_t
modifier|*
name|dbtable
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|dbp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find the deepest match to 'name' in the dbtable, and return it  *  * Notes:  *	If the DNS_DBTABLEFIND_NOEXACT option is set, the best partial  *	match (if any) to 'name' will be returned.  *  * Returns:  ISC_R_SUCCESS		on success  *<something else>		no default and match  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_DBTABLE_H */
end_comment

end_unit

