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
name|_SYS_ZAP_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ZAP_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_comment
comment|/*  * ZAP - ZFS Attribute Processor  *  * The ZAP is a module which sits on top of the DMU (Data Managemnt  * Unit) and implements a higher-level storage primitive using DMU  * objects.  Its primary consumer is the ZPL (ZFS Posix Layer).  *  * A "zapobj" is a DMU object which the ZAP uses to stores attributes.  * Users should use only zap routines to access a zapobj - they should  * not access the DMU object directly using DMU routines.  *  * The attributes stored in a zapobj are name-value pairs.  The name is  * a zero-terminated string of up to ZAP_MAXNAMELEN bytes (including  * terminating NULL).  The value is an array of integers, which may be  * 1, 2, 4, or 8 bytes long.  The total space used by the array (number  * of integers * integer length) can be up to ZAP_MAXVALUELEN bytes.  * Note that an 8-byte integer value can be used to store the location  * (object number) of another dmu object (which may be itself a zapobj).  * Note that you can use a zero-length attribute to store a single bit  * of information - the attribute is present or not.  *  * The ZAP routines are thread-safe.  However, you must observe the  * DMU's restriction that a transaction may not be operated on  * concurrently.  *  * Any of the routines that return an int may return an I/O error (EIO  * or ECHECKSUM).  *  *  * Implementation / Performance Notes:  *  * The ZAP is intended to operate most efficiently on attributes with  * short (49 bytes or less) names and single 8-byte values, for which  * the microzap will be used.  The ZAP should be efficient enough so  * that the user does not need to cache these attributes.  *  * The ZAP's locking scheme makes its routines thread-safe.  Operations  * on different zapobjs will be processed concurrently.  Operations on  * the same zapobj which only read data will be processed concurrently.  * Operations on the same zapobj which modify data will be processed  * concurrently when there are many attributes in the zapobj (because  * the ZAP uses per-block locking - more than 128 * (number of cpus)  * small attributes will suffice).  */
end_comment

begin_comment
comment|/*  * We're using zero-terminated byte strings (ie. ASCII or UTF-8 C  * strings) for the names of attributes, rather than a byte string  * bounded by an explicit length.  If some day we want to support names  * in character sets which have embedded zeros (eg. UTF-16, UTF-32),  * we'll have to add routines for using length-bounded strings.  */
end_comment

begin_include
include|#
directive|include
file|<sys/dmu.h>
end_include

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
define|#
directive|define
name|ZAP_MAXNAMELEN
value|256
define|#
directive|define
name|ZAP_MAXVALUELEN
value|1024
comment|/*  * Create a new zapobj with no attributes and return its object number.  */
name|uint64_t
name|zap_create
parameter_list|(
name|objset_t
modifier|*
name|ds
parameter_list|,
name|dmu_object_type_t
name|ot
parameter_list|,
name|dmu_object_type_t
name|bonustype
parameter_list|,
name|int
name|bonuslen
parameter_list|,
name|dmu_tx_t
modifier|*
name|tx
parameter_list|)
function_decl|;
comment|/*  * Create a new zapobj with no attributes from the given (unallocated)  * object number.  */
name|int
name|zap_create_claim
parameter_list|(
name|objset_t
modifier|*
name|ds
parameter_list|,
name|uint64_t
name|obj
parameter_list|,
name|dmu_object_type_t
name|ot
parameter_list|,
name|dmu_object_type_t
name|bonustype
parameter_list|,
name|int
name|bonuslen
parameter_list|,
name|dmu_tx_t
modifier|*
name|tx
parameter_list|)
function_decl|;
comment|/*  * The zapobj passed in must be a valid ZAP object for all of the  * following routines.  */
comment|/*  * Destroy this zapobj and all its attributes.  *  * Frees the object number using dmu_object_free.  */
name|int
name|zap_destroy
parameter_list|(
name|objset_t
modifier|*
name|ds
parameter_list|,
name|uint64_t
name|zapobj
parameter_list|,
name|dmu_tx_t
modifier|*
name|tx
parameter_list|)
function_decl|;
comment|/*  * Manipulate attributes.  *  * 'integer_size' is in bytes, and must be 1, 2, 4, or 8.  */
comment|/*  * Retrieve the contents of the attribute with the given name.  *  * If the requested attribute does not exist, the call will fail and  * return ENOENT.  *  * If 'integer_size' is smaller than the attribute's integer size, the  * call will fail and return EINVAL.  *  * If 'integer_size' is equal to or larger than the attribute's integer  * size, the call will succeed and return 0.  * When converting to a  * larger integer size, the integers will be treated as unsigned (ie. no  * sign-extension will be performed).  *  * 'num_integers' is the length (in integers) of 'buf'.  *  * If the attribute is longer than the buffer, as many integers as will  * fit will be transferred to 'buf'.  If the entire attribute was not  * transferred, the call will return EOVERFLOW.  */
name|int
name|zap_lookup
parameter_list|(
name|objset_t
modifier|*
name|ds
parameter_list|,
name|uint64_t
name|zapobj
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uint64_t
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
comment|/*  * Create an attribute with the given name and value.  *  * If an attribute with the given name already exists, the call will  * fail and return EEXIST.  */
name|int
name|zap_add
parameter_list|(
name|objset_t
modifier|*
name|ds
parameter_list|,
name|uint64_t
name|zapobj
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|integer_size
parameter_list|,
name|uint64_t
name|num_integers
parameter_list|,
specifier|const
name|void
modifier|*
name|val
parameter_list|,
name|dmu_tx_t
modifier|*
name|tx
parameter_list|)
function_decl|;
comment|/*  * Set the attribute with the given name to the given value.  If an  * attribute with the given name does not exist, it will be created.  If  * an attribute with the given name already exists, the previous value  * will be overwritten.  The integer_size may be different from the  * existing attribute's integer size, in which case the attribute's  * integer size will be updated to the new value.  */
name|int
name|zap_update
parameter_list|(
name|objset_t
modifier|*
name|ds
parameter_list|,
name|uint64_t
name|zapobj
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|integer_size
parameter_list|,
name|uint64_t
name|num_integers
parameter_list|,
specifier|const
name|void
modifier|*
name|val
parameter_list|,
name|dmu_tx_t
modifier|*
name|tx
parameter_list|)
function_decl|;
comment|/*  * Get the length (in integers) and the integer size of the specified  * attribute.  *  * If the requested attribute does not exist, the call will fail and  * return ENOENT.  */
name|int
name|zap_length
parameter_list|(
name|objset_t
modifier|*
name|ds
parameter_list|,
name|uint64_t
name|zapobj
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uint64_t
modifier|*
name|integer_size
parameter_list|,
name|uint64_t
modifier|*
name|num_integers
parameter_list|)
function_decl|;
comment|/*  * Remove the specified attribute.  *  * If the specified attribute does not exist, the call will fail and  * return ENOENT.  */
name|int
name|zap_remove
parameter_list|(
name|objset_t
modifier|*
name|ds
parameter_list|,
name|uint64_t
name|zapobj
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|dmu_tx_t
modifier|*
name|tx
parameter_list|)
function_decl|;
comment|/*  * Returns (in *count) the number of attributes in the specified zap  * object.  */
name|int
name|zap_count
parameter_list|(
name|objset_t
modifier|*
name|ds
parameter_list|,
name|uint64_t
name|zapobj
parameter_list|,
name|uint64_t
modifier|*
name|count
parameter_list|)
function_decl|;
comment|/*  * Returns (in name) the name of the entry whose value  * (za_first_integer) is value, or ENOENT if not found.  The string  * pointed to by name must be at least 256 bytes long.  */
name|int
name|zap_value_search
parameter_list|(
name|objset_t
modifier|*
name|os
parameter_list|,
name|uint64_t
name|zapobj
parameter_list|,
name|uint64_t
name|value
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
struct_decl|struct
name|zap
struct_decl|;
struct_decl|struct
name|zap_leaf
struct_decl|;
typedef|typedef
struct|struct
name|zap_cursor
block|{
comment|/* This structure is opaque! */
name|objset_t
modifier|*
name|zc_objset
decl_stmt|;
name|struct
name|zap
modifier|*
name|zc_zap
decl_stmt|;
name|struct
name|zap_leaf
modifier|*
name|zc_leaf
decl_stmt|;
name|uint64_t
name|zc_zapobj
decl_stmt|;
name|uint64_t
name|zc_hash
decl_stmt|;
name|uint32_t
name|zc_cd
decl_stmt|;
block|}
name|zap_cursor_t
typedef|;
typedef|typedef
struct|struct
block|{
name|int
name|za_integer_length
decl_stmt|;
name|uint64_t
name|za_num_integers
decl_stmt|;
name|uint64_t
name|za_first_integer
decl_stmt|;
comment|/* no sign extension for<8byte ints */
name|char
name|za_name
index|[
name|MAXNAMELEN
index|]
decl_stmt|;
block|}
name|zap_attribute_t
typedef|;
comment|/*  * The interface for listing all the attributes of a zapobj can be  * thought of as cursor moving down a list of the attributes one by  * one.  The cookie returned by the zap_cursor_serialize routine is  * persistent across system calls (and across reboot, even).  */
comment|/*  * Initialize a zap cursor, pointing to the "first" attribute of the  * zapobj.  You must _fini the cursor when you are done with it.  */
name|void
name|zap_cursor_init
parameter_list|(
name|zap_cursor_t
modifier|*
name|zc
parameter_list|,
name|objset_t
modifier|*
name|ds
parameter_list|,
name|uint64_t
name|zapobj
parameter_list|)
function_decl|;
name|void
name|zap_cursor_fini
parameter_list|(
name|zap_cursor_t
modifier|*
name|zc
parameter_list|)
function_decl|;
comment|/*  * Get the attribute currently pointed to by the cursor.  Returns  * ENOENT if at the end of the attributes.  */
name|int
name|zap_cursor_retrieve
parameter_list|(
name|zap_cursor_t
modifier|*
name|zc
parameter_list|,
name|zap_attribute_t
modifier|*
name|za
parameter_list|)
function_decl|;
comment|/*  * Advance the cursor to the next attribute.  */
name|void
name|zap_cursor_advance
parameter_list|(
name|zap_cursor_t
modifier|*
name|zc
parameter_list|)
function_decl|;
comment|/*  * Get a persistent cookie pointing to the current position of the zap  * cursor.  The low 4 bits in the cookie are always zero, and thus can  * be used as to differentiate a serialized cookie from a different type  * of value.  The cookie will be less than 2^32 as long as there are  * fewer than 2^22 (4.2 million) entries in the zap object.  */
name|uint64_t
name|zap_cursor_serialize
parameter_list|(
name|zap_cursor_t
modifier|*
name|zc
parameter_list|)
function_decl|;
comment|/*  * Initialize a zap cursor pointing to the position recorded by  * zap_cursor_serialize (in the "serialized" argument).  You can also  * use a "serialized" argument of 0 to start at the beginning of the  * zapobj (ie.  zap_cursor_init_serialized(..., 0) is equivalent to  * zap_cursor_init(...).)  */
name|void
name|zap_cursor_init_serialized
parameter_list|(
name|zap_cursor_t
modifier|*
name|zc
parameter_list|,
name|objset_t
modifier|*
name|ds
parameter_list|,
name|uint64_t
name|zapobj
parameter_list|,
name|uint64_t
name|serialized
parameter_list|)
function_decl|;
define|#
directive|define
name|ZAP_HISTOGRAM_SIZE
value|10
typedef|typedef
struct|struct
name|zap_stats
block|{
comment|/* 	 * Size of the pointer table (in number of entries). 	 * This is always a power of 2, or zero if it's a microzap. 	 * In general, it should be considerably greater than zs_num_leafs. 	 */
name|uint64_t
name|zs_ptrtbl_len
decl_stmt|;
name|uint64_t
name|zs_blocksize
decl_stmt|;
comment|/* size of zap blocks */
comment|/* 	 * The number of blocks used.  Note that some blocks may be 	 * wasted because old ptrtbl's and large name/value blocks are 	 * not reused.  (Although their space is reclaimed, we don't 	 * reuse those offsets in the object.) 	 */
name|uint64_t
name|zs_num_blocks
decl_stmt|;
comment|/* 	 * Pointer table values from zap_ptrtbl in the zap_phys_t 	 */
name|uint64_t
name|zs_ptrtbl_nextblk
decl_stmt|;
comment|/* next (larger) copy start block */
name|uint64_t
name|zs_ptrtbl_blks_copied
decl_stmt|;
comment|/* number source blocks copied */
name|uint64_t
name|zs_ptrtbl_zt_blk
decl_stmt|;
comment|/* starting block number */
name|uint64_t
name|zs_ptrtbl_zt_numblks
decl_stmt|;
comment|/* number of blocks */
name|uint64_t
name|zs_ptrtbl_zt_shift
decl_stmt|;
comment|/* bits to index it */
comment|/* 	 * Values of the other members of the zap_phys_t 	 */
name|uint64_t
name|zs_block_type
decl_stmt|;
comment|/* ZBT_HEADER */
name|uint64_t
name|zs_magic
decl_stmt|;
comment|/* ZAP_MAGIC */
name|uint64_t
name|zs_num_leafs
decl_stmt|;
comment|/* The number of leaf blocks */
name|uint64_t
name|zs_num_entries
decl_stmt|;
comment|/* The number of zap entries */
name|uint64_t
name|zs_salt
decl_stmt|;
comment|/* salt to stir into hash function */
comment|/* 	 * Histograms.  For all histograms, the last index 	 * (ZAP_HISTOGRAM_SIZE-1) includes any values which are greater 	 * than what can be represented.  For example 	 * zs_leafs_with_n5_entries[ZAP_HISTOGRAM_SIZE-1] is the number 	 * of leafs with more than 45 entries. 	 */
comment|/* 	 * zs_leafs_with_n_pointers[n] is the number of leafs with 	 * 2^n pointers to it. 	 */
name|uint64_t
name|zs_leafs_with_2n_pointers
index|[
name|ZAP_HISTOGRAM_SIZE
index|]
decl_stmt|;
comment|/* 	 * zs_leafs_with_n_entries[n] is the number of leafs with 	 * [n*5, (n+1)*5) entries.  In the current implementation, there 	 * can be at most 55 entries in any block, but there may be 	 * fewer if the name or value is large, or the block is not 	 * completely full. 	 */
name|uint64_t
name|zs_blocks_with_n5_entries
index|[
name|ZAP_HISTOGRAM_SIZE
index|]
decl_stmt|;
comment|/* 	 * zs_leafs_n_tenths_full[n] is the number of leafs whose 	 * fullness is in the range [n/10, (n+1)/10). 	 */
name|uint64_t
name|zs_blocks_n_tenths_full
index|[
name|ZAP_HISTOGRAM_SIZE
index|]
decl_stmt|;
comment|/* 	 * zs_entries_using_n_chunks[n] is the number of entries which 	 * consume n 24-byte chunks.  (Note, large names/values only use 	 * one chunk, but contribute to zs_num_blocks_large.) 	 */
name|uint64_t
name|zs_entries_using_n_chunks
index|[
name|ZAP_HISTOGRAM_SIZE
index|]
decl_stmt|;
comment|/* 	 * zs_buckets_with_n_entries[n] is the number of buckets (each 	 * leaf has 64 buckets) with n entries. 	 * zs_buckets_with_n_entries[1] should be very close to 	 * zs_num_entries. 	 */
name|uint64_t
name|zs_buckets_with_n_entries
index|[
name|ZAP_HISTOGRAM_SIZE
index|]
decl_stmt|;
block|}
name|zap_stats_t
typedef|;
comment|/*  * Get statistics about a ZAP object.  Note: you need to be aware of the  * internal implementation of the ZAP to correctly interpret some of the  * statistics.  This interface shouldn't be relied on unless you really  * know what you're doing.  */
name|int
name|zap_get_stats
parameter_list|(
name|objset_t
modifier|*
name|ds
parameter_list|,
name|uint64_t
name|zapobj
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
comment|/* _SYS_ZAP_H */
end_comment

end_unit

