begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005, 2007, 2009, 2010  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: keytable.h,v 1.23 2010-06-25 03:24:05 marka Exp $ */
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
comment|/*! \file  * \brief  * The keytable module provides services for storing and retrieving DNSSEC  * trusted keys, as well as the ability to find the deepest matching key  * for a given domain name.  *  * MP:  *\li	The module ensures appropriate synchronization of data structures it  *	creates and manipulates.  *  * Resources:  *\li	TBS  *  * Security:  *\li	No anticipated impact.  */
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/magic.h>
end_include

begin_include
include|#
directive|include
file|<isc/refcount.h>
end_include

begin_include
include|#
directive|include
file|<isc/rwlock.h>
end_include

begin_include
include|#
directive|include
file|<isc/stdtime.h>
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

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_struct
struct|struct
name|dns_keytable
block|{
comment|/* Unlocked. */
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|isc_mutex_t
name|lock
decl_stmt|;
name|isc_rwlock_t
name|rwlock
decl_stmt|;
comment|/* Locked by lock. */
name|isc_uint32_t
name|active_nodes
decl_stmt|;
comment|/* Locked by rwlock. */
name|isc_uint32_t
name|references
decl_stmt|;
name|dns_rbt_t
modifier|*
name|table
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KEYTABLE_MAGIC
value|ISC_MAGIC('K', 'T', 'b', 'l')
end_define

begin_define
define|#
directive|define
name|VALID_KEYTABLE
parameter_list|(
name|kt
parameter_list|)
value|ISC_MAGIC_VALID(kt, KEYTABLE_MAGIC)
end_define

begin_struct
struct|struct
name|dns_keynode
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_refcount_t
name|refcount
decl_stmt|;
name|dst_key_t
modifier|*
name|key
decl_stmt|;
name|isc_boolean_t
name|managed
decl_stmt|;
name|struct
name|dns_keynode
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KEYNODE_MAGIC
value|ISC_MAGIC('K', 'N', 'o', 'd')
end_define

begin_define
define|#
directive|define
name|VALID_KEYNODE
parameter_list|(
name|kn
parameter_list|)
value|ISC_MAGIC_VALID(kn, KEYNODE_MAGIC)
end_define

begin_function_decl
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
comment|/*%<  * Create a keytable.  *  * Requires:  *  *\li	'mctx' is a valid memory context.  *  *\li	keytablep != NULL&& *keytablep == NULL  *  * Ensures:  *  *\li	On success, *keytablep is a valid, empty key table.  *  * Returns:  *  *\li	ISC_R_SUCCESS  *  *\li	Any other result indicates failure.  */
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
comment|/*%<  * Attach *targetp to source.  *  * Requires:  *  *\li	'source' is a valid keytable.  *  *\li	'targetp' points to a NULL dns_keytable_t *.  *  * Ensures:  *  *\li	*targetp is attached to source.  */
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
comment|/*%<  * Detach *keytablep from its keytable.  *  * Requires:  *  *\li	'keytablep' points to a valid keytable.  *  * Ensures:  *  *\li	*keytablep is NULL.  *  *\li	If '*keytablep' is the last reference to the keytable,  *		all resources used by the keytable will be freed  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_keytable_add
parameter_list|(
name|dns_keytable_t
modifier|*
name|keytable
parameter_list|,
name|isc_boolean_t
name|managed
parameter_list|,
name|dst_key_t
modifier|*
modifier|*
name|keyp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Add '*keyp' to 'keytable' (using the name in '*keyp').  * The value of keynode->managed is set to 'managed'  *  * Notes:  *  *\li	Ownership of *keyp is transferred to the keytable.  *\li   If the key already exists in the table, ISC_R_EXISTS is  *      returned and the new key is freed.  *  * Requires:  *  *\li	'keytable' points to a valid keytable.  *  *\li	keyp != NULL&& *keyp is a valid dst_key_t *.  *  * Ensures:  *  *\li	On success, *keyp == NULL  *  * Returns:  *  *\li	ISC_R_SUCCESS  *\li	ISC_R_EXISTS  *  *\li	Any other result indicates failure.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_keytable_marksecure
parameter_list|(
name|dns_keytable_t
modifier|*
name|keytable
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Add a null key to 'keytable' for name 'name'.  This marks the  * name as a secure domain, but doesn't supply any key data to allow the  * domain to be validated.  (Used when automated trust anchor management  * has gotten broken by a zone misconfiguration; for example, when the  * active key has been revoked but the stand-by key was still in its 30-day  * waiting period for validity.)  *  * Notes:  *  *\li   If a key already exists in the table, ISC_R_EXISTS is  *      returned and nothing is done.  *  * Requires:  *  *\li	'keytable' points to a valid keytable.  *  *\li	keyp != NULL&& *keyp is a valid dst_key_t *.  *  * Returns:  *  *\li	ISC_R_SUCCESS  *\li	ISC_R_EXISTS  *  *\li	Any other result indicates failure.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_keytable_delete
parameter_list|(
name|dns_keytable_t
modifier|*
name|keytable
parameter_list|,
name|dns_name_t
modifier|*
name|keyname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Delete node(s) from 'keytable' matching name 'keyname'  *  * Requires:  *  *\li	'keytable' points to a valid keytable.  *  *\li	'name' is not NULL  *  * Returns:  *  *\li	ISC_R_SUCCESS  *  *\li	Any other result indicates failure.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_keytable_deletekeynode
parameter_list|(
name|dns_keytable_t
modifier|*
name|keytable
parameter_list|,
name|dst_key_t
modifier|*
name|dstkey
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Delete node(s) from 'keytable' containing copies of the key pointed  * to by 'dstkey'  *  * Requires:  *  *\li	'keytable' points to a valid keytable.  *\li	'dstkey' is not NULL  *  * Returns:  *  *\li	ISC_R_SUCCESS  *  *\li	Any other result indicates failure.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_keytable_find
parameter_list|(
name|dns_keytable_t
modifier|*
name|keytable
parameter_list|,
name|dns_name_t
modifier|*
name|keyname
parameter_list|,
name|dns_keynode_t
modifier|*
modifier|*
name|keynodep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Search for the first instance of a key named 'name' in 'keytable',  * without regard to keyid and algorithm.  Use dns_keytable_nextkeynode()  * to find subsequent instances.  *  * Requires:  *  *\li	'keytable' is a valid keytable.  *  *\li	'name' is a valid absolute name.  *  *\li	keynodep != NULL&& *keynodep == NULL  *  * Returns:  *  *\li	ISC_R_SUCCESS  *\li	ISC_R_NOTFOUND  *  *\li	Any other result indicates an error.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_keytable_nextkeynode
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
comment|/*%<  * Return for the next key after 'keynode' in 'keytable', without regard to  * keyid and algorithm.  *  * Requires:  *  *\li	'keytable' is a valid keytable.  *  *\li	'keynode' is a valid keynode.  *  *\li	nextnodep != NULL&& *nextnodep == NULL  *  * Returns:  *  *\li	ISC_R_SUCCESS  *\li	ISC_R_NOTFOUND  *  *\li	Any other result indicates an error.  */
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
comment|/*%<  * Search for a key named 'name', matching 'algorithm' and 'tag' in  * 'keytable'.  This finds the first instance which matches.  Use  * dns_keytable_findnextkeynode() to find other instances.  *  * Requires:  *  *\li	'keytable' is a valid keytable.  *  *\li	'name' is a valid absolute name.  *  *\li	keynodep != NULL&& *keynodep == NULL  *  * Returns:  *  *\li	ISC_R_SUCCESS  *\li	DNS_R_PARTIALMATCH	the name existed in the keytable.  *\li	ISC_R_NOTFOUND  *  *\li	Any other result indicates an error.  */
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
comment|/*%<  * Search for the next key with the same properties as 'keynode' in  * 'keytable' as found by dns_keytable_findkeynode().  *  * Requires:  *  *\li	'keytable' is a valid keytable.  *  *\li	'keynode' is a valid keynode.  *  *\li	nextnodep != NULL&& *nextnodep == NULL  *  * Returns:  *  *\li	ISC_R_SUCCESS  *\li	ISC_R_NOTFOUND  *  *\li	Any other result indicates an error.  */
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
comment|/*%<  * Search for the deepest match of 'name' in 'keytable'.  *  * Requires:  *  *\li	'keytable' is a valid keytable.  *  *\li	'name' is a valid absolute name.  *  *\li	'foundname' is a name with a dedicated buffer.  *  * Returns:  *  *\li	ISC_R_SUCCESS  *\li	ISC_R_NOTFOUND  *  *\li	Any other result indicates an error.  */
end_comment

begin_function_decl
name|void
name|dns_keytable_attachkeynode
parameter_list|(
name|dns_keytable_t
modifier|*
name|keytable
parameter_list|,
name|dns_keynode_t
modifier|*
name|source
parameter_list|,
name|dns_keynode_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Attach a keynode and and increment the active_nodes counter in a  * corresponding keytable.  *  * Requires:  *  *\li	'keytable' is a valid keytable.  *  *\li	'source' is a valid keynode.  *  *\li	'target' is not null and '*target' is null.  */
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
comment|/*%<  * Give back a keynode found via dns_keytable_findkeynode().  *  * Requires:  *  *\li	'keytable' is a valid keytable.  *  *\li	*keynodep is a valid keynode returned by a call to  *	dns_keytable_findkeynode().  *  * Ensures:  *  *\li	*keynodep == NULL  */
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
comment|/*%<  * Is 'name' at or beneath a trusted key?  *  * Requires:  *  *\li	'keytable' is a valid keytable.  *  *\li	'name' is a valid absolute name.  *  *\li	'*wantsdnssecp' is a valid isc_boolean_t.  *  * Ensures:  *  *\li	On success, *wantsdnssecp will be ISC_TRUE if and only if 'name'  *	is at or beneath a trusted key.  *  * Returns:  *  *\li	ISC_R_SUCCESS  *  *\li	Any other result is an error.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_keytable_dump
parameter_list|(
name|dns_keytable_t
modifier|*
name|keytable
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Dump the keytable on fp.  */
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
comment|/*%<  * Get the DST key associated with keynode.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_keynode_managed
parameter_list|(
name|dns_keynode_t
modifier|*
name|keynode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Is this flagged as a managed key?  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_keynode_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_keynode_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Allocate space for a keynode  */
end_comment

begin_function_decl
name|void
name|dns_keynode_attach
parameter_list|(
name|dns_keynode_t
modifier|*
name|source
parameter_list|,
name|dns_keynode_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Attach keynode 'source' to '*target'  */
end_comment

begin_function_decl
name|void
name|dns_keynode_detach
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_keynode_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Detach a single keynode, without touching any keynodes that  * may be pointed to by its 'next' pointer  */
end_comment

begin_function_decl
name|void
name|dns_keynode_detachall
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_keynode_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Detach a keynode and all its succesors.  */
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

