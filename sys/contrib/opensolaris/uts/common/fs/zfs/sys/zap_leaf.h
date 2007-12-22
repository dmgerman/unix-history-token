begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ZAP_LEAF_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ZAP_LEAF_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
struct_decl|struct
name|zap
struct_decl|;
define|#
directive|define
name|ZAP_LEAF_MAGIC
value|0x2AB1EAF
comment|/* chunk size = 24 bytes */
define|#
directive|define
name|ZAP_LEAF_CHUNKSIZE
value|24
comment|/*  * The amount of space available for chunks is:  * block size (1<<l->l_bs) - hash entry size (2) * number of hash  * entries - header space (2*chunksize)  */
define|#
directive|define
name|ZAP_LEAF_NUMCHUNKS
parameter_list|(
name|l
parameter_list|)
define|\
value|(((1<<(l)->l_bs) - 2*ZAP_LEAF_HASH_NUMENTRIES(l)) / \ 	ZAP_LEAF_CHUNKSIZE - 2)
comment|/*  * The amount of space within the chunk available for the array is:  * chunk size - space for type (1) - space for next pointer (2)  */
define|#
directive|define
name|ZAP_LEAF_ARRAY_BYTES
value|(ZAP_LEAF_CHUNKSIZE - 3)
define|#
directive|define
name|ZAP_LEAF_ARRAY_NCHUNKS
parameter_list|(
name|bytes
parameter_list|)
define|\
value|(((bytes)+ZAP_LEAF_ARRAY_BYTES-1)/ZAP_LEAF_ARRAY_BYTES)
comment|/*  * Low water mark:  when there are only this many chunks free, start  * growing the ptrtbl.  Ideally, this should be larger than a  * "reasonably-sized" entry.  20 chunks is more than enough for the  * largest directory entry (MAXNAMELEN (256) byte name, 8-byte value),  * while still being only around 3% for 16k blocks.  */
define|#
directive|define
name|ZAP_LEAF_LOW_WATER
value|(20)
comment|/*  * The leaf hash table has block size / 2^5 (32) number of entries,  * which should be more than enough for the maximum number of entries,  * which is less than block size / CHUNKSIZE (24) / minimum number of  * chunks per entry (3).  */
define|#
directive|define
name|ZAP_LEAF_HASH_SHIFT
parameter_list|(
name|l
parameter_list|)
value|((l)->l_bs - 5)
define|#
directive|define
name|ZAP_LEAF_HASH_NUMENTRIES
parameter_list|(
name|l
parameter_list|)
value|(1<< ZAP_LEAF_HASH_SHIFT(l))
comment|/*  * The chunks start immediately after the hash table.  The end of the  * hash table is at l_hash + HASH_NUMENTRIES, which we simply cast to a  * chunk_t.  */
define|#
directive|define
name|ZAP_LEAF_CHUNK
parameter_list|(
name|l
parameter_list|,
name|idx
parameter_list|)
define|\
value|((zap_leaf_chunk_t *) \ 	((l)->l_phys->l_hash + ZAP_LEAF_HASH_NUMENTRIES(l)))[idx]
define|#
directive|define
name|ZAP_LEAF_ENTRY
parameter_list|(
name|l
parameter_list|,
name|idx
parameter_list|)
value|(&ZAP_LEAF_CHUNK(l, idx).l_entry)
typedef|typedef
enum|enum
name|zap_chunk_type
block|{
name|ZAP_CHUNK_FREE
init|=
literal|253
block|,
name|ZAP_CHUNK_ENTRY
init|=
literal|252
block|,
name|ZAP_CHUNK_ARRAY
init|=
literal|251
block|,
name|ZAP_CHUNK_TYPE_MAX
init|=
literal|250
block|}
name|zap_chunk_type_t
typedef|;
comment|/*  * TAKE NOTE:  * If zap_leaf_phys_t is modified, zap_leaf_byteswap() must be modified.  */
typedef|typedef
struct|struct
name|zap_leaf_phys
block|{
struct|struct
name|zap_leaf_header
block|{
name|uint64_t
name|lh_block_type
decl_stmt|;
comment|/* ZBT_LEAF */
name|uint64_t
name|lh_pad1
decl_stmt|;
name|uint64_t
name|lh_prefix
decl_stmt|;
comment|/* hash prefix of this leaf */
name|uint32_t
name|lh_magic
decl_stmt|;
comment|/* ZAP_LEAF_MAGIC */
name|uint16_t
name|lh_nfree
decl_stmt|;
comment|/* number free chunks */
name|uint16_t
name|lh_nentries
decl_stmt|;
comment|/* number of entries */
name|uint16_t
name|lh_prefix_len
decl_stmt|;
comment|/* num bits used to id this */
comment|/* above is accessable to zap, below is zap_leaf private */
name|uint16_t
name|lh_freelist
decl_stmt|;
comment|/* chunk head of free list */
name|uint8_t
name|lh_pad2
index|[
literal|12
index|]
decl_stmt|;
block|}
name|l_hdr
struct|;
comment|/* 2 24-byte chunks */
comment|/* 	 * The header is followed by a hash table with 	 * ZAP_LEAF_HASH_NUMENTRIES(zap) entries.  The hash table is 	 * followed by an array of ZAP_LEAF_NUMCHUNKS(zap) 	 * zap_leaf_chunk structures.  These structures are accessed 	 * with the ZAP_LEAF_CHUNK() macro. 	 */
name|uint16_t
name|l_hash
index|[
literal|1
index|]
decl_stmt|;
block|}
name|zap_leaf_phys_t
typedef|;
typedef|typedef
union|union
name|zap_leaf_chunk
block|{
struct|struct
name|zap_leaf_entry
block|{
name|uint8_t
name|le_type
decl_stmt|;
comment|/* always ZAP_CHUNK_ENTRY */
name|uint8_t
name|le_int_size
decl_stmt|;
comment|/* size of ints */
name|uint16_t
name|le_next
decl_stmt|;
comment|/* next entry in hash chain */
name|uint16_t
name|le_name_chunk
decl_stmt|;
comment|/* first chunk of the name */
name|uint16_t
name|le_name_length
decl_stmt|;
comment|/* bytes in name, incl null */
name|uint16_t
name|le_value_chunk
decl_stmt|;
comment|/* first chunk of the value */
name|uint16_t
name|le_value_length
decl_stmt|;
comment|/* value length in ints */
name|uint32_t
name|le_cd
decl_stmt|;
comment|/* collision differentiator */
name|uint64_t
name|le_hash
decl_stmt|;
comment|/* hash value of the name */
block|}
name|l_entry
struct|;
struct|struct
name|zap_leaf_array
block|{
name|uint8_t
name|la_type
decl_stmt|;
comment|/* always ZAP_CHUNK_ARRAY */
name|uint8_t
name|la_array
index|[
name|ZAP_LEAF_ARRAY_BYTES
index|]
decl_stmt|;
name|uint16_t
name|la_next
decl_stmt|;
comment|/* next blk or CHAIN_END */
block|}
name|l_array
struct|;
struct|struct
name|zap_leaf_free
block|{
name|uint8_t
name|lf_type
decl_stmt|;
comment|/* always ZAP_CHUNK_FREE */
name|uint8_t
name|lf_pad
index|[
name|ZAP_LEAF_ARRAY_BYTES
index|]
decl_stmt|;
name|uint16_t
name|lf_next
decl_stmt|;
comment|/* next in free list, or CHAIN_END */
block|}
name|l_free
struct|;
block|}
name|zap_leaf_chunk_t
typedef|;
typedef|typedef
struct|struct
name|zap_leaf
block|{
name|krwlock_t
name|l_rwlock
decl_stmt|;
comment|/* only used on head of chain */
name|uint64_t
name|l_blkid
decl_stmt|;
comment|/* 1<<ZAP_BLOCK_SHIFT byte block off */
name|int
name|l_bs
decl_stmt|;
comment|/* block size shift */
name|dmu_buf_t
modifier|*
name|l_dbuf
decl_stmt|;
name|zap_leaf_phys_t
modifier|*
name|l_phys
decl_stmt|;
block|}
name|zap_leaf_t
typedef|;
typedef|typedef
struct|struct
name|zap_entry_handle
block|{
comment|/* below is set by zap_leaf.c and is public to zap.c */
name|uint64_t
name|zeh_num_integers
decl_stmt|;
name|uint64_t
name|zeh_hash
decl_stmt|;
name|uint32_t
name|zeh_cd
decl_stmt|;
name|uint8_t
name|zeh_integer_size
decl_stmt|;
comment|/* below is private to zap_leaf.c */
name|uint16_t
name|zeh_fakechunk
decl_stmt|;
name|uint16_t
modifier|*
name|zeh_chunkp
decl_stmt|;
name|zap_leaf_t
modifier|*
name|zeh_leaf
decl_stmt|;
block|}
name|zap_entry_handle_t
typedef|;
comment|/*  * Return a handle to the named entry, or ENOENT if not found.  The hash  * value must equal zap_hash(name).  */
specifier|extern
name|int
name|zap_leaf_lookup
parameter_list|(
name|zap_leaf_t
modifier|*
name|l
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uint64_t
name|h
parameter_list|,
name|zap_entry_handle_t
modifier|*
name|zeh
parameter_list|)
function_decl|;
comment|/*  * Return a handle to the entry with this hash+cd, or the entry with the  * next closest hash+cd.  */
specifier|extern
name|int
name|zap_leaf_lookup_closest
parameter_list|(
name|zap_leaf_t
modifier|*
name|l
parameter_list|,
name|uint64_t
name|hash
parameter_list|,
name|uint32_t
name|cd
parameter_list|,
name|zap_entry_handle_t
modifier|*
name|zeh
parameter_list|)
function_decl|;
comment|/*  * Read the first num_integers in the attribute.  Integer size  * conversion will be done without sign extension.  Return EINVAL if  * integer_size is too small.  Return EOVERFLOW if there are more than  * num_integers in the attribute.  */
specifier|extern
name|int
name|zap_entry_read
parameter_list|(
specifier|const
name|zap_entry_handle_t
modifier|*
name|zeh
parameter_list|,
name|uint8_t
name|integer_size
parameter_list|,
name|uint64_t
name|num_integers
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zap_entry_read_name
parameter_list|(
specifier|const
name|zap_entry_handle_t
modifier|*
name|zeh
parameter_list|,
name|uint16_t
name|buflen
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/*  * Replace the value of an existing entry.  *  * zap_entry_update may fail if it runs out of space (ENOSPC).  */
specifier|extern
name|int
name|zap_entry_update
parameter_list|(
name|zap_entry_handle_t
modifier|*
name|zeh
parameter_list|,
name|uint8_t
name|integer_size
parameter_list|,
name|uint64_t
name|num_integers
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/*  * Remove an entry.  */
specifier|extern
name|void
name|zap_entry_remove
parameter_list|(
name|zap_entry_handle_t
modifier|*
name|zeh
parameter_list|)
function_decl|;
comment|/*  * Create an entry. An equal entry must not exist, and this entry must  * belong in this leaf (according to its hash value).  Fills in the  * entry handle on success.  Returns 0 on success or ENOSPC on failure.  */
specifier|extern
name|int
name|zap_entry_create
parameter_list|(
name|zap_leaf_t
modifier|*
name|l
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uint64_t
name|h
parameter_list|,
name|uint32_t
name|cd
parameter_list|,
name|uint8_t
name|integer_size
parameter_list|,
name|uint64_t
name|num_integers
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|zap_entry_handle_t
modifier|*
name|zeh
parameter_list|)
function_decl|;
comment|/*  * Other stuff.  */
specifier|extern
name|void
name|zap_leaf_init
parameter_list|(
name|zap_leaf_t
modifier|*
name|l
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zap_leaf_byteswap
parameter_list|(
name|zap_leaf_phys_t
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zap_leaf_split
parameter_list|(
name|zap_leaf_t
modifier|*
name|l
parameter_list|,
name|zap_leaf_t
modifier|*
name|nl
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zap_leaf_stats
parameter_list|(
name|zap_t
modifier|*
name|zap
parameter_list|,
name|zap_leaf_t
modifier|*
name|l
parameter_list|,
name|zap_stats_t
modifier|*
name|zs
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_ZAP_LEAF_H */
end_comment

end_unit

