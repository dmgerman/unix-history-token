begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: keytable.h,v 1.10.206.3 2006/01/06 00:01:42 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_KEYTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_KEYTABLE_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Key Tables  *  * The keytable module provides services for storing and retrieving DNSSEC  * trusted keys, as well as the ability to find the deepest matching key  * for a given domain name.  *  * MP:  *	The module ensures appropriate synchronization of data structures it  *	creates and manipulates.  *  * Resources:  *<TBS>  *  * Security:  *	No anticipated impact.  */
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

begin_include
include|#
directive|include
file|<dst/dst.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_keytable_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_keytable_t
modifier|*
modifier|*
name|keytablep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a keytable.  *  * Requires:  *  *	'mctx' is a valid memory context.  *  *	keytablep != NULL&& *keytablep == NULL  *  * Ensures:  *  *	On success, *keytablep is a valid, empty key table.  *  * Returns:  *  *	ISC_R_SUCCESS  *  *	Any other result indicates failure.  */
end_comment

begin_function_decl
name|void
name|dns_keytable_attach
parameter_list|(
name|dns_keytable_t
modifier|*
name|source
parameter_list|,
name|dns_keytable_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach *targetp to source.  *  * Requires:  *  *	'source' is a valid keytable.  *  *	'targetp' points to a NULL dns_keytable_t *.  *  * Ensures:  *  *	*targetp is attached to source.  */
end_comment

begin_function_decl
name|void
name|dns_keytable_detach
parameter_list|(
name|dns_keytable_t
modifier|*
modifier|*
name|keytablep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach *keytablep from its keytable.  *  * Requires:  *  *	'keytablep' points to a valid keytable.  *  * Ensures:  *  *	*keytablep is NULL.  *  *	If '*keytablep' is the last reference to the keytable,  *  *		All resources used by the keytable will be freed  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_keytable_add
parameter_list|(
name|dns_keytable_t
modifier|*
name|keytable
parameter_list|,
name|dst_key_t
modifier|*
modifier|*
name|keyp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Add '*keyp' to 'keytable'.  *  * Notes:  *  *	Ownership of *keyp is transferred to the keytable.  *  * Requires:  *  *	keyp != NULL&& *keyp is a valid dst_key_t *.  *  * Ensures:  *  *	On success, *keyp == NULL  *  * Returns:  *  *	ISC_R_SUCCESS  *  *	Any other result indicates failure.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_keytable_findkeynode
parameter_list|(
name|dns_keytable_t
modifier|*
name|keytable
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_secalg_t
name|algorithm
parameter_list|,
name|dns_keytag_t
name|tag
parameter_list|,
name|dns_keynode_t
modifier|*
modifier|*
name|keynodep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Search for a key named 'name', matching 'algorithm' and 'tag' in  * 'keytable'.  This finds the first instance which matches.  Use  * dns_keytable_findnextkeynode() to find other instances.  *  * Requires:  *  *	'keytable' is a valid keytable.  *  *	'name' is a valid absolute name.  *  *	keynodep != NULL&& *keynodep == NULL  *  * Returns:  *  *	ISC_R_SUCCESS  *	DNS_R_PARTIALMATCH	the name existed in the keytable.  *	ISC_R_NOTFOUND  *  *	Any other result indicates an error.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_keytable_findnextkeynode
parameter_list|(
name|dns_keytable_t
modifier|*
name|keytable
parameter_list|,
name|dns_keynode_t
modifier|*
name|keynode
parameter_list|,
name|dns_keynode_t
modifier|*
modifier|*
name|nextnodep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Search for the next key with the same properties as 'keynode' in  * 'keytable' as found by dns_keytable_findkeynode().  *  * Requires:  *  *	'keytable' is a valid keytable.  *  *	'keynode' is a valid keynode.  *  *	nextnodep != NULL&& *nextnodep == NULL  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOTFOUND  *  *	Any other result indicates an error.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_keytable_finddeepestmatch
parameter_list|(
name|dns_keytable_t
modifier|*
name|keytable
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_name_t
modifier|*
name|foundname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Search for the deepest match of 'name' in 'keytable'.  *  * Requires:  *  *	'keytable' is a valid keytable.  *  *	'name' is a valid absolute name.  *  *	'foundname' is a name with a dedicated buffer.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOTFOUND  *  *	Any other result indicates an error.  */
end_comment

begin_function_decl
name|void
name|dns_keytable_detachkeynode
parameter_list|(
name|dns_keytable_t
modifier|*
name|keytable
parameter_list|,
name|dns_keynode_t
modifier|*
modifier|*
name|keynodep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Give back a keynode found via dns_keytable_findkeynode().  *  * Requires:  *  *	'keytable' is a valid keytable.  *  *	*keynodep is a valid keynode returned by a call to  *	dns_keytable_findkeynode().  *  * Ensures:  *  *	*keynodep == NULL  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_keytable_issecuredomain
parameter_list|(
name|dns_keytable_t
modifier|*
name|keytable
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|isc_boolean_t
modifier|*
name|wantdnssecp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Is 'name' at or beneath a trusted key?  *  * Requires:  *  *	'keytable' is a valid keytable.  *  *	'name' is a valid absolute name.  *  *	'*wantsdnssecp' is a valid isc_boolean_t.  *  * Ensures:  *  *	On success, *wantsdnssecp will be ISC_TRUE if and only if 'name'  *	is at or beneath a trusted key.  *  * Returns:  *  *	ISC_R_SUCCESS  *  *	Any other result is an error.  */
end_comment

begin_function_decl
name|dst_key_t
modifier|*
name|dns_keynode_key
parameter_list|(
name|dns_keynode_t
modifier|*
name|keynode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the DST key associated with keynode.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_KEYTABLE_H */
end_comment

end_unit

