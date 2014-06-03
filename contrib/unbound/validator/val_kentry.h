begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * validator/val_kentry.h - validator key entry definition.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions for dealing with validator key entries.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VALIDATOR_VAL_KENTRY_H
end_ifndef

begin_define
define|#
directive|define
name|VALIDATOR_VAL_KENTRY_H
end_define

begin_struct_decl
struct_decl|struct
name|packed_rrset_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_packed_rrset_key
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|"util/storage/lruhash.h"
end_include

begin_comment
comment|/**  * A key entry for the validator.  * This may or may not be a trusted key.  * This is what is stored in the key cache.  * This is the key part for the cache; the key entry key.  */
end_comment

begin_struct
struct|struct
name|key_entry_key
block|{
comment|/** lru hash entry */
name|struct
name|lruhash_entry
name|entry
decl_stmt|;
comment|/** name of the key */
name|uint8_t
modifier|*
name|name
decl_stmt|;
comment|/** length of name */
name|size_t
name|namelen
decl_stmt|;
comment|/** class of the key, host byteorder */
name|uint16_t
name|key_class
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Key entry for the validator.  * Contains key status.  * This is the data part for the cache, the key entry data.  *  * Can be in three basic states:  * 	isbad=0:		good key  * 	isbad=1:		bad key  * 	isbad=0&& rrset=0:	insecure space.  */
end_comment

begin_struct
struct|struct
name|key_entry_data
block|{
comment|/** the TTL of this entry (absolute time) */
name|time_t
name|ttl
decl_stmt|;
comment|/** the key rrdata. can be NULL to signal keyless name. */
name|struct
name|packed_rrset_data
modifier|*
name|rrset_data
decl_stmt|;
comment|/** not NULL sometimes to give reason why bogus */
name|char
modifier|*
name|reason
decl_stmt|;
comment|/** list of algorithms signalled, ends with 0, or NULL */
name|uint8_t
modifier|*
name|algo
decl_stmt|;
comment|/** DNS RR type of the rrset data (host order) */
name|uint16_t
name|rrset_type
decl_stmt|;
comment|/** if the key is bad: Bogus or malformed */
name|uint8_t
name|isbad
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** function for lruhash operation */
end_comment

begin_function_decl
name|size_t
name|key_entry_sizefunc
parameter_list|(
name|void
modifier|*
name|key
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** function for lruhash operation */
end_comment

begin_function_decl
name|int
name|key_entry_compfunc
parameter_list|(
name|void
modifier|*
name|k1
parameter_list|,
name|void
modifier|*
name|k2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** function for lruhash operation */
end_comment

begin_function_decl
name|void
name|key_entry_delkeyfunc
parameter_list|(
name|void
modifier|*
name|key
parameter_list|,
name|void
modifier|*
name|userarg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** function for lruhash operation */
end_comment

begin_function_decl
name|void
name|key_entry_deldatafunc
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|void
modifier|*
name|userarg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** calculate hash for key entry   * @param kk: key entry. The lruhash entry.hash value is filled in.  */
end_comment

begin_function_decl
name|void
name|key_entry_hash
parameter_list|(
name|struct
name|key_entry_key
modifier|*
name|kk
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Copy a key entry, to be region-allocated.  * @param kkey: the key entry key (and data pointer) to copy.  * @param region: where to allocate it  * @return newly region-allocated entry or NULL on a failure to allocate.  */
end_comment

begin_function_decl
name|struct
name|key_entry_key
modifier|*
name|key_entry_copy_toregion
parameter_list|(
name|struct
name|key_entry_key
modifier|*
name|kkey
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Copy a key entry, malloced.  * @param kkey: the key entry key (and data pointer) to copy.  * @return newly allocated entry or NULL on a failure to allocate memory.  */
end_comment

begin_function_decl
name|struct
name|key_entry_key
modifier|*
name|key_entry_copy
parameter_list|(
name|struct
name|key_entry_key
modifier|*
name|kkey
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if this is a null entry. Does not do locking.  * @param kkey: must have data pointer set correctly  * @return true if it is a NULL rrset entry.  */
end_comment

begin_function_decl
name|int
name|key_entry_isnull
parameter_list|(
name|struct
name|key_entry_key
modifier|*
name|kkey
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if this entry is good. Does not do locking.  * @param kkey: must have data pointer set correctly  * @return true if it is good.  */
end_comment

begin_function_decl
name|int
name|key_entry_isgood
parameter_list|(
name|struct
name|key_entry_key
modifier|*
name|kkey
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if this entry is bad. Does not do locking.  * @param kkey: must have data pointer set correctly  * @return true if it is bad.  */
end_comment

begin_function_decl
name|int
name|key_entry_isbad
parameter_list|(
name|struct
name|key_entry_key
modifier|*
name|kkey
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set reason why a key is bad.  * @param kkey: bad key.  * @param reason: string to attach, you must allocate it.  *    Not safe to call twice unless you deallocate it yourself.  */
end_comment

begin_function_decl
name|void
name|key_entry_set_reason
parameter_list|(
name|struct
name|key_entry_key
modifier|*
name|kkey
parameter_list|,
name|char
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get reason why a key is bad.  * @param kkey: bad key  * @return pointer to string.  *    String is part of key entry and is deleted with it.  */
end_comment

begin_function_decl
name|char
modifier|*
name|key_entry_get_reason
parameter_list|(
name|struct
name|key_entry_key
modifier|*
name|kkey
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create a null entry, in the given region.  * @param region: where to allocate  * @param name: the key name  * @param namelen: length of name  * @param dclass: class of key entry. (host order);  * @param ttl: what ttl should the key have. relative.  * @param now: current time (added to ttl).  * @return new key entry or NULL on alloc failure  */
end_comment

begin_function_decl
name|struct
name|key_entry_key
modifier|*
name|key_entry_create_null
parameter_list|(
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|uint16_t
name|dclass
parameter_list|,
name|time_t
name|ttl
parameter_list|,
name|time_t
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create a key entry from an rrset, in the given region.  * @param region: where to allocate.  * @param name: the key name  * @param namelen: length of name  * @param dclass: class of key entry. (host order);  * @param rrset: data for key entry. This is copied to the region.  * @param sigalg: signalled algorithm list (or NULL).  * @param now: current time (added to ttl of rrset)  * @return new key entry or NULL on alloc failure  */
end_comment

begin_function_decl
name|struct
name|key_entry_key
modifier|*
name|key_entry_create_rrset
parameter_list|(
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|uint16_t
name|dclass
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|uint8_t
modifier|*
name|sigalg
parameter_list|,
name|time_t
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create a bad entry, in the given region.  * @param region: where to allocate  * @param name: the key name  * @param namelen: length of name  * @param dclass: class of key entry. (host order);  * @param ttl: what ttl should the key have. relative.  * @param now: current time (added to ttl).  * @return new key entry or NULL on alloc failure  */
end_comment

begin_function_decl
name|struct
name|key_entry_key
modifier|*
name|key_entry_create_bad
parameter_list|(
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|uint16_t
name|dclass
parameter_list|,
name|time_t
name|ttl
parameter_list|,
name|time_t
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Obtain rrset from a key entry, allocated in region.  * @param kkey: key entry to convert to a rrset.  * @param region: where to allocate rrset  * @return rrset copy; if no rrset or alloc error returns NULL.  */
end_comment

begin_function_decl
name|struct
name|ub_packed_rrset_key
modifier|*
name|key_entry_get_rrset
parameter_list|(
name|struct
name|key_entry_key
modifier|*
name|kkey
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get keysize of the keyentry.  * @param kkey: key, must be a good key, with contents.  * @return size in bits of the key.  */
end_comment

begin_function_decl
name|size_t
name|key_entry_keysize
parameter_list|(
name|struct
name|key_entry_key
modifier|*
name|kkey
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VALIDATOR_VAL_KENTRY_H */
end_comment

end_unit

