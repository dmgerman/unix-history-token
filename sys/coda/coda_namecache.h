begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   *             Coda: an Experimental Distributed File System  *                              Release 3.1  *   *           Copyright (c) 1987-1998 Carnegie Mellon University  *                          All Rights Reserved  *   * Permission  to  use, copy, modify and distribute this software and its  * documentation is hereby granted,  provided  that  both  the  copyright  * notice  and  this  permission  notice  appear  in  all  copies  of the  * software, derivative works or  modified  versions,  and  any  portions  * thereof, and that both notices appear in supporting documentation, and  * that credit is given to Carnegie Mellon University  in  all  documents  * and publicity pertaining to direct or indirect use of this code or its  * derivatives.  *   * CODA IS AN EXPERIMENTAL SOFTWARE SYSTEM AND IS  KNOWN  TO  HAVE  BUGS,  * SOME  OF  WHICH MAY HAVE SERIOUS CONSEQUENCES.  CARNEGIE MELLON ALLOWS  * FREE USE OF THIS SOFTWARE IN ITS "AS IS" CONDITION.   CARNEGIE  MELLON  * DISCLAIMS  ANY  LIABILITY  OF  ANY  KIND  FOR  ANY  DAMAGES WHATSOEVER  * RESULTING DIRECTLY OR INDIRECTLY FROM THE USE OF THIS SOFTWARE  OR  OF  * ANY DERIVATIVE WORK.  *   * Carnegie  Mellon  encourages  users  of  this  software  to return any  * improvements or extensions that  they  make,  and  to  grant  Carnegie  * Mellon the rights to redistribute these changes without encumbrance.  *   * 	@(#) src/sys/coda/coda_namecache.h,v 1.1.1.1 1998/08/29 21:14:52 rvb Exp $   * $FreeBSD$  *   */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1990 Carnegie-Mellon University  * Copyright (c) 1989 Carnegie-Mellon University  * All rights reserved.  The CMU software License Agreement specifies  * the terms and conditions for use and redistribution.  */
end_comment

begin_comment
comment|/*  * This code was written for the Coda file system at Carnegie Mellon University.  * Contributers include David Steere, James Kistler, and M. Satyanarayanan.  */
end_comment

begin_comment
comment|/*   * HISTORY  * $Log: coda_namecache.h,v $  * Revision 1.4  1998/09/13 13:57:59  rvb  * Finish conversion of cfs -> coda  *  * Revision 1.3  1998/09/11 18:50:17  rvb  * All the references to cfs, in symbols, structs, and strings  * have been changed to coda.  (Same for CFS.)  *  * Revision 1.2  1998/09/02 19:09:53  rvb  * Pass2 complete  *  * Revision 1.1.1.1  1998/08/29 21:14:52  rvb  * Very Preliminary Coda  *  * Revision 1.8  1998/08/28 18:12:25  rvb  * Now it also works on FreeBSD -current.  This code will be  * committed to the FreeBSD -current and NetBSD -current  * trees.  It will then be tailored to the particular platform  * by flushing conditional code.  *  * Revision 1.7  1998/08/18 17:05:24  rvb  * Don't use __RCSID now  *  * Revision 1.6  1998/08/18 16:31:49  rvb  * Sync the code for NetBSD -current; test on 1.3 later  *  * Revision 1.5  98/01/23  11:53:51  rvb  * Bring RVB_CODA1_1 to HEAD  *   * Revision 1.4.2.1  97/12/16  12:40:23  rvb  * Sync with 1.3  *   * Revision 1.4  97/12/05  10:39:29  rvb  * Read CHANGES  *   * Revision 1.3.4.3  97/11/24  15:44:51  rvb  * Final cfs_venus.c w/o macros, but one locking bug  *   * Revision 1.3.4.2  97/11/12  12:09:44  rvb  * reorg pass1  *   * Revision 1.3.4.1  97/11/06  21:06:05  rvb  * don't include headers in headers  *   * Revision 1.3  97/08/05  11:08:19  lily  * Removed cfsnc_replace, replaced it with a coda_find, unhash, and  * rehash.  This fixes a cnode leak and a bug in which the fid is  * not actually replaced.  (cfs_namecache.c, cfsnc.h, cfs_subr.c)  *   * Revision 1.2  96/01/02  16:57:19  bnoble  * Added support for Coda MiniCache and raw inode calls (final commit)  *   * Revision 1.1.2.1  1995/12/20 01:57:45  bnoble  * Added CODA-specific files  *  * Revision 3.1.1.1  1995/03/04  19:08:22  bnoble  * Branch for NetBSD port revisions  *  * Revision 3.1  1995/03/04  19:08:21  bnoble  * Bump to major revision 3 to prepare for NetBSD port  *  * Revision 2.2  1994/08/28  19:37:39  luqi  * Add a new CODA_REPLACE call to allow venus to replace a ViceFid in the  * mini-cache.  *  * In "cfs.h":  * Add CODA_REPLACE decl.  *  * In "cfs_namecache.c":  * Add routine cfsnc_replace.  *  * In "cfs_subr.c":  * Add case-statement to process CODA_REPLACE.  *  * In "cfsnc.h":  * Add decl for CODA_NC_REPLACE.  *  * Revision 2.1  94/07/21  16:25:27  satya  * Conversion to C++ 3.0; start of Coda Release 2.0  *  * Revision 1.2  92/10/27  17:58:34  lily  * merge kernel/latest and alpha/src/cfs  *   * Revision 2.2  90/07/05  11:27:04  mrt  * 	Created for the Coda File System.  * 	[90/05/23            dcs]  *   * Revision 1.4  90/05/31  17:02:12  dcs  * Prepare for merge with facilities kernel.  *   *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CODA_NC_HEADER_
end_ifndef

begin_define
define|#
directive|define
name|_CODA_NC_HEADER_
end_define

begin_comment
comment|/*  * Coda constants  */
end_comment

begin_define
define|#
directive|define
name|CODA_NC_NAMELEN
value|15
end_define

begin_comment
comment|/* longest name stored in cache */
end_comment

begin_define
define|#
directive|define
name|CODA_NC_CACHESIZE
value|256
end_define

begin_comment
comment|/* Default cache size */
end_comment

begin_define
define|#
directive|define
name|CODA_NC_HASHSIZE
value|64
end_define

begin_comment
comment|/* Must be multiple of 2 */
end_comment

begin_comment
comment|/*  * Hash function for the primary hash.  */
end_comment

begin_comment
comment|/*   * First try -- (first + last letters + length + (int)cp) mod size  * 2nd try -- same, except dir fid.vnode instead of cp  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|oldhash
end_ifdef

begin_define
define|#
directive|define
name|CODA_NC_HASH
parameter_list|(
name|name
parameter_list|,
name|namelen
parameter_list|,
name|cp
parameter_list|)
define|\
value|((name[0] + name[namelen-1] + namelen + (int)(cp))& (coda_nc_hashsize-1))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CODA_NC_HASH
parameter_list|(
name|name
parameter_list|,
name|namelen
parameter_list|,
name|cp
parameter_list|)
define|\
value|((name[0] + (name[namelen-1]<<4) + namelen + (((int)cp)>>8))& (coda_nc_hashsize-1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CODA_NAMEMATCH
parameter_list|(
name|cp
parameter_list|,
name|name
parameter_list|,
name|namelen
parameter_list|,
name|dcp
parameter_list|)
define|\
value|((namelen == cp->namelen)&& (dcp == cp->dcp)&& \ 		 (bcmp(cp->name,name,namelen) == 0))
end_define

begin_comment
comment|/*  * Functions to modify the hash and lru chains.  * insque and remque assume that the pointers are the first thing  * in the list node, thus the trickery for lru.  */
end_comment

begin_define
define|#
directive|define
name|CODA_NC_HSHINS
parameter_list|(
name|elem
parameter_list|,
name|pred
parameter_list|)
value|insque(elem,pred)
end_define

begin_define
define|#
directive|define
name|CODA_NC_HSHREM
parameter_list|(
name|elem
parameter_list|)
value|remque(elem)
end_define

begin_define
define|#
directive|define
name|CODA_NC_HSHNUL
parameter_list|(
name|elem
parameter_list|)
value|(elem)->hash_next = \ 					(elem)->hash_prev = (elem)
end_define

begin_define
define|#
directive|define
name|CODA_NC_LRUINS
parameter_list|(
name|elem
parameter_list|,
name|pred
parameter_list|)
value|insque(LRU_PART(elem), LRU_PART(pred))
end_define

begin_define
define|#
directive|define
name|CODA_NC_LRUREM
parameter_list|(
name|elem
parameter_list|)
value|remque(LRU_PART(elem));
end_define

begin_define
define|#
directive|define
name|CODA_NC_LRUGET
parameter_list|(
name|lruhead
parameter_list|)
value|LRU_TOP((lruhead).lru_prev)
end_define

begin_define
define|#
directive|define
name|CODA_NC_VALID
parameter_list|(
name|cncp
parameter_list|)
value|(cncp->dcp != (struct cnode *)0)
end_define

begin_define
define|#
directive|define
name|LRU_PART
parameter_list|(
name|cncp
parameter_list|)
value|(struct coda_cache *) \ 				((char *)cncp + (2*sizeof(struct coda_cache *)))
end_define

begin_define
define|#
directive|define
name|LRU_TOP
parameter_list|(
name|cncp
parameter_list|)
value|(struct coda_cache *) \ 			((char *)cncp - (2*sizeof(struct coda_cache *)))
end_define

begin_define
define|#
directive|define
name|DATA_PART
parameter_list|(
name|cncp
parameter_list|)
value|(struct coda_cache *) \ 			((char *)cncp + (4*sizeof(struct coda_cache *)))
end_define

begin_define
define|#
directive|define
name|DATA_SIZE
value|(sizeof(struct coda_cache)-(4*sizeof(struct coda_cache *)))
end_define

begin_comment
comment|/*  * Structure for an element in the CODA Name Cache.  * NOTE: I use the position of arguments and their size in the  * implementation of the functions CODA_NC_LRUINS, CODA_NC_LRUREM, and  * DATA_PART.  */
end_comment

begin_struct
struct|struct
name|coda_cache
block|{
name|struct
name|coda_cache
modifier|*
name|hash_next
decl_stmt|,
modifier|*
name|hash_prev
decl_stmt|;
comment|/* Hash list */
name|struct
name|coda_cache
modifier|*
name|lru_next
decl_stmt|,
modifier|*
name|lru_prev
decl_stmt|;
comment|/* LRU list */
name|struct
name|cnode
modifier|*
name|cp
decl_stmt|;
comment|/* vnode of the file */
name|struct
name|cnode
modifier|*
name|dcp
decl_stmt|;
comment|/* parent's cnode */
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
comment|/* user credentials */
name|char
name|name
index|[
name|CODA_NC_NAMELEN
index|]
decl_stmt|;
comment|/* segment name */
name|int
name|namelen
decl_stmt|;
comment|/* length of name */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_lru
block|{
comment|/* Start of LRU chain */
name|char
modifier|*
name|dummy1
decl_stmt|,
modifier|*
name|dummy2
decl_stmt|;
comment|/* place holders */
name|struct
name|coda_cache
modifier|*
name|lru_next
decl_stmt|,
modifier|*
name|lru_prev
decl_stmt|;
comment|/* position of pointers is important */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coda_hash
block|{
comment|/* Start of Hash chain */
name|struct
name|coda_cache
modifier|*
name|hash_next
decl_stmt|,
modifier|*
name|hash_prev
decl_stmt|;
comment|/* NOTE: chain pointers must be first */
name|int
name|length
decl_stmt|;
comment|/* used for tuning purposes */
block|}
struct|;
end_struct

begin_comment
comment|/*   * Symbols to aid in debugging the namecache code. Assumes the existence  * of the variable coda_nc_debug, which is defined in cfs_namecache.c  */
end_comment

begin_define
define|#
directive|define
name|CODA_NC_DEBUG
parameter_list|(
name|N
parameter_list|,
name|STMT
parameter_list|)
value|{ if (coda_nc_debug& (1<<N)) { STMT } }
end_define

begin_comment
comment|/* Prototypes of functions exported within cfs */
end_comment

begin_function_decl
specifier|extern
name|void
name|coda_nc_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|coda_nc_enter
parameter_list|(
name|struct
name|cnode
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|cnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|cnode
modifier|*
name|coda_nc_lookup
parameter_list|(
name|struct
name|cnode
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|coda_nc_zapParentfid
parameter_list|(
name|ViceFid
modifier|*
parameter_list|,
name|enum
name|dc_status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|coda_nc_zapfid
parameter_list|(
name|ViceFid
modifier|*
parameter_list|,
name|enum
name|dc_status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|coda_nc_zapvnode
parameter_list|(
name|ViceFid
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|enum
name|dc_status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|coda_nc_zapfile
parameter_list|(
name|struct
name|cnode
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|coda_nc_purge_user
parameter_list|(
name|vuid_t
parameter_list|,
name|enum
name|dc_status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|coda_nc_flush
parameter_list|(
name|enum
name|dc_status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_coda_nc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|coda_nc_gather_stats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|coda_nc_resize
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|dc_status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|coda_nc_name
parameter_list|(
name|struct
name|cnode
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Structure to contain statistics on the cache usage  */
end_comment

begin_struct
struct|struct
name|coda_nc_statistics
block|{
name|unsigned
name|hits
decl_stmt|;
name|unsigned
name|misses
decl_stmt|;
name|unsigned
name|enters
decl_stmt|;
name|unsigned
name|dbl_enters
decl_stmt|;
name|unsigned
name|long_name_enters
decl_stmt|;
name|unsigned
name|long_name_lookups
decl_stmt|;
name|unsigned
name|long_remove
decl_stmt|;
name|unsigned
name|lru_rm
decl_stmt|;
name|unsigned
name|zapPfids
decl_stmt|;
name|unsigned
name|zapFids
decl_stmt|;
name|unsigned
name|zapFile
decl_stmt|;
name|unsigned
name|zapUsers
decl_stmt|;
name|unsigned
name|Flushes
decl_stmt|;
name|unsigned
name|Sum_bucket_len
decl_stmt|;
name|unsigned
name|Sum2_bucket_len
decl_stmt|;
name|unsigned
name|Max_bucket_len
decl_stmt|;
name|unsigned
name|Num_zero_len
decl_stmt|;
name|unsigned
name|Search_len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CODA_NC_FIND
value|((u_long) 1)
end_define

begin_define
define|#
directive|define
name|CODA_NC_REMOVE
value|((u_long) 2)
end_define

begin_define
define|#
directive|define
name|CODA_NC_INIT
value|((u_long) 3)
end_define

begin_define
define|#
directive|define
name|CODA_NC_ENTER
value|((u_long) 4)
end_define

begin_define
define|#
directive|define
name|CODA_NC_LOOKUP
value|((u_long) 5)
end_define

begin_define
define|#
directive|define
name|CODA_NC_ZAPPFID
value|((u_long) 6)
end_define

begin_define
define|#
directive|define
name|CODA_NC_ZAPFID
value|((u_long) 7)
end_define

begin_define
define|#
directive|define
name|CODA_NC_ZAPVNODE
value|((u_long) 8)
end_define

begin_define
define|#
directive|define
name|CODA_NC_ZAPFILE
value|((u_long) 9)
end_define

begin_define
define|#
directive|define
name|CODA_NC_PURGEUSER
value|((u_long) 10)
end_define

begin_define
define|#
directive|define
name|CODA_NC_FLUSH
value|((u_long) 11)
end_define

begin_define
define|#
directive|define
name|CODA_NC_PRINTCODA_NC
value|((u_long) 12)
end_define

begin_define
define|#
directive|define
name|CODA_NC_PRINTSTATS
value|((u_long) 13)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

