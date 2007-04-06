begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*	Copyright (c) 1983, 1984, 1985, 1986, 1987, 1988, 1989 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved  	*/
end_comment

begin_comment
comment|/*  * University Copyright- Copyright (c) 1982, 1986, 1988  * The Regents of the University of California  * All Rights Reserved  *  * University Acknowledgment- Portions of this document are derived from  * software developed by the University of California, Berkeley, and its  * contributors.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DNLC_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DNLC_H
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
include|#
directive|include
file|<sys/kstat.h>
comment|/*  * DNLC - Directory name lookup cache.  * There are now two sorts of name caching:  *  * Standard dnlc: This original cache holds recent mappings  *                of<directory vnode, name> to vnode mappings.  *  * Directory caches: Entire large directories can be cached, subject to  *		     memory availability and tunables. A directory cache  *		     anchor point must be provided in the xxnode for  *		     a directory.  */
comment|/*  * Standard dnlc  * =============  */
comment|/*  * This structure describes the elements in the cache of recent  * names looked up.  *  * Note namlen is a uchar_t to conserve space  * and alignment padding. The max length of any  * pathname component is defined as MAXNAMELEN  * which is 256 (including the terminating null).  * So provided this doesn't change, we don't include the null,  * we always use bcmp to compare strings, and we don't start  * storing full names, then we are ok. The space savings are worth it.  */
typedef|typedef
struct|struct
name|ncache
block|{
name|struct
name|ncache
modifier|*
name|hash_next
decl_stmt|;
comment|/* hash chain, MUST BE FIRST */
name|struct
name|ncache
modifier|*
name|hash_prev
decl_stmt|;
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
comment|/* vnode the name refers to */
name|struct
name|vnode
modifier|*
name|dp
decl_stmt|;
comment|/* vnode of parent of name */
name|int
name|hash
decl_stmt|;
comment|/* hash signature */
name|uchar_t
name|namlen
decl_stmt|;
comment|/* length of name */
name|char
name|name
index|[
literal|1
index|]
decl_stmt|;
comment|/* segment name - null terminated */
block|}
name|ncache_t
typedef|;
comment|/*  * Hash table bucket structure of name cache entries for fast lookup.  */
typedef|typedef
struct|struct
name|nc_hash
block|{
name|ncache_t
modifier|*
name|hash_next
decl_stmt|;
name|ncache_t
modifier|*
name|hash_prev
decl_stmt|;
name|kmutex_t
name|hash_lock
decl_stmt|;
block|}
name|nc_hash_t
typedef|;
comment|/*  * Statistics on name cache  * Not protected by locks  */
comment|/*  * ncstats has been deprecated, due to the integer size of the counters  * which can easily overflow in the dnlc.  * It is maintained (at some expense) for compatability.  * The preferred interface is the kstat accessible nc_stats below, ehich  * is actually shared with directory caching.  */
struct|struct
name|ncstats
block|{
name|int
name|hits
decl_stmt|;
comment|/* hits that we can really use */
name|int
name|misses
decl_stmt|;
comment|/* cache misses */
name|int
name|enters
decl_stmt|;
comment|/* number of enters done */
name|int
name|dbl_enters
decl_stmt|;
comment|/* number of enters tried when already cached */
name|int
name|long_enter
decl_stmt|;
comment|/* deprecated, no longer accounted */
name|int
name|long_look
decl_stmt|;
comment|/* deprecated, no longer accounted */
name|int
name|move_to_front
decl_stmt|;
comment|/* entry moved to front of hash chain */
name|int
name|purges
decl_stmt|;
comment|/* number of purges of cache */
block|}
struct|;
struct|struct
name|nc_stats
block|{
name|kstat_named_t
name|ncs_hits
decl_stmt|;
comment|/* cache hits */
name|kstat_named_t
name|ncs_misses
decl_stmt|;
comment|/* cache misses */
name|kstat_named_t
name|ncs_neg_hits
decl_stmt|;
comment|/* negative cache hits */
name|kstat_named_t
name|ncs_enters
decl_stmt|;
comment|/* enters */
name|kstat_named_t
name|ncs_dbl_enters
decl_stmt|;
comment|/* enters when entry already cached */
name|kstat_named_t
name|ncs_purge_total
decl_stmt|;
comment|/* total entries prurged */
name|kstat_named_t
name|ncs_purge_all
decl_stmt|;
comment|/* dnlc_purge() calls */
name|kstat_named_t
name|ncs_purge_vp
decl_stmt|;
comment|/* dnlc_purge_vp() calls */
name|kstat_named_t
name|ncs_purge_vfs
decl_stmt|;
comment|/* dnlc_purge_vfs() calls */
name|kstat_named_t
name|ncs_purge_fs1
decl_stmt|;
comment|/* dnlc_purge_fs1() calls */
name|kstat_named_t
name|ncs_pick_free
decl_stmt|;
comment|/* found a free ncache */
name|kstat_named_t
name|ncs_pick_heur
decl_stmt|;
comment|/* found ncache w/ NULL vpages */
name|kstat_named_t
name|ncs_pick_last
decl_stmt|;
comment|/* found last ncache on chain */
block|}
struct|;
comment|/*  * The dnlc hashing function.  * Although really a kernel macro we export it to allow validation  * of ncache_t entries by mdb. Note, mdb can handle the ASSERT.  *  * 'hash' and 'namlen' must be l-values. A check is made to ensure  * the name length fits into an unsigned char (see ncache_t).  */
define|#
directive|define
name|DNLCHASH
parameter_list|(
name|name
parameter_list|,
name|dvp
parameter_list|,
name|hash
parameter_list|,
name|namlen
parameter_list|)
define|\
value|{							\ 		char Xc, *Xcp;					\ 		hash = (int)((uintptr_t)(dvp))>> 8;		\ 		for (Xcp = (name); (Xc = *Xcp) != 0; Xcp++)	\ 			(hash) = ((hash)<< 4) + (hash) + Xc;	\ 		ASSERT((Xcp - (name))<= ((1<< NBBY) - 1));	\ 		(namlen) = Xcp - (name);			\ 	}
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
include|#
directive|include
file|<sys/vfs.h>
include|#
directive|include
file|<sys/vnode.h>
specifier|extern
name|int
name|ncsize
decl_stmt|;
comment|/* set in param_init() # of dnlc entries */
specifier|extern
name|vnode_t
name|negative_cache_vnode
decl_stmt|;
define|#
directive|define
name|DNLC_NO_VNODE
value|&negative_cache_vnode
name|void
name|dnlc_update
parameter_list|(
name|vnode_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|vnode_t
modifier|*
parameter_list|)
function_decl|;
name|vnode_t
modifier|*
name|dnlc_lookup
parameter_list|(
name|vnode_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
name|dnlc_purge_vfsp
parameter_list|(
name|vfs_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
name|dnlc_remove
parameter_list|(
name|vnode_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
name|void
name|dnlc_reduce_cache
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* defined(_KERNEL) */
comment|/*  * Directory caching interfaces  * ============================  */
comment|/*  * Typically for large directories, the file names will be the same or  * at least similar lengths. So there's no point in anything more elaborate  * than a simple unordered linked list of free space entries.  * For small directories the name length distribution doesn't really matter.  */
typedef|typedef
struct|struct
name|dcfree
block|{
name|uint64_t
name|df_handle
decl_stmt|;
comment|/* fs supplied handle */
name|struct
name|dcfree
modifier|*
name|df_next
decl_stmt|;
comment|/* link to next free entry in bucket */
name|uint_t
name|df_len
decl_stmt|;
comment|/* length of free entry */
block|}
name|dcfree_t
typedef|;
typedef|typedef
struct|struct
name|dcentry
block|{
name|uint64_t
name|de_handle
decl_stmt|;
comment|/* fs supplied and returned data */
name|struct
name|dcentry
modifier|*
name|de_next
decl_stmt|;
comment|/* link to next name entry in bucket */
name|int
name|de_hash
decl_stmt|;
comment|/* hash signature */
name|uchar_t
name|de_namelen
decl_stmt|;
comment|/* length of name excluding null */
name|char
name|de_name
index|[
literal|1
index|]
decl_stmt|;
comment|/* null terminated name */
block|}
name|dcentry_t
typedef|;
typedef|typedef
struct|struct
name|dircache
block|{
name|struct
name|dircache
modifier|*
name|dc_next
decl_stmt|;
comment|/* chain - for purge purposes */
name|struct
name|dircache
modifier|*
name|dc_prev
decl_stmt|;
comment|/* chain - for purge purposes */
name|int64_t
name|dc_actime
decl_stmt|;
comment|/* dir access time, from lbolt64 */
name|dcentry_t
modifier|*
modifier|*
name|dc_namehash
decl_stmt|;
comment|/* entry hash table pointer */
name|dcfree_t
modifier|*
modifier|*
name|dc_freehash
decl_stmt|;
comment|/* free entry hash table pointer */
name|uint_t
name|dc_num_entries
decl_stmt|;
comment|/* no of named entries */
name|uint_t
name|dc_num_free
decl_stmt|;
comment|/* no of free space entries */
name|uint_t
name|dc_nhash_mask
decl_stmt|;
comment|/* name hash table size - 1 */
name|uint_t
name|dc_fhash_mask
decl_stmt|;
comment|/* free space hash table size - 1 */
name|struct
name|dcanchor
modifier|*
name|dc_anchor
decl_stmt|;
comment|/* back ptr to anchor */
name|boolean_t
name|dc_complete
decl_stmt|;
comment|/* cache complete boolean */
block|}
name|dircache_t
typedef|;
typedef|typedef
struct|struct
name|dcanchor
block|{
name|void
modifier|*
name|dca_dircache
decl_stmt|;
comment|/* pointer to directory cache */
name|kmutex_t
name|dca_lock
decl_stmt|;
comment|/* protects the directory cache */
block|}
name|dcanchor_t
typedef|;
comment|/*  * Head struct for doubly linked chain of dircache_t  * The next and prev fields must match those of a dircache_t  */
typedef|typedef
struct|struct
block|{
name|dircache_t
modifier|*
name|dch_next
decl_stmt|;
comment|/* next in chain */
name|dircache_t
modifier|*
name|dch_prev
decl_stmt|;
comment|/* prev in chain */
name|kmutex_t
name|dch_lock
decl_stmt|;
comment|/* lock for the chain */
block|}
name|dchead_t
typedef|;
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
comment|/* _SYS_DNLC_H */
end_comment

end_unit

