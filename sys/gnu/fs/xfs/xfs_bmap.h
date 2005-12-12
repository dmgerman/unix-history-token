begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_BMAP_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_BMAP_H__
end_define

begin_struct_decl
struct_decl|struct
name|getbmap
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_bmbt_irec
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_trans
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * List of extents to be free "later".  * The list is kept sorted on xbf_startblock.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_bmap_free_item
block|{
name|xfs_fsblock_t
name|xbfi_startblock
decl_stmt|;
comment|/* starting fs block number */
name|xfs_extlen_t
name|xbfi_blockcount
decl_stmt|;
comment|/* number of blocks in extent */
name|struct
name|xfs_bmap_free_item
modifier|*
name|xbfi_next
decl_stmt|;
comment|/* link to next entry */
block|}
name|xfs_bmap_free_item_t
typedef|;
end_typedef

begin_comment
comment|/*  * Header for free extent list.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_bmap_free
block|{
name|xfs_bmap_free_item_t
modifier|*
name|xbf_first
decl_stmt|;
comment|/* list of to-be-free extents */
name|int
name|xbf_count
decl_stmt|;
comment|/* count of items on list */
name|int
name|xbf_low
decl_stmt|;
comment|/* kludge: alloc in low mode */
block|}
name|xfs_bmap_free_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_BMAP_MAX_NMAP
value|4
end_define

begin_comment
comment|/*  * Flags for xfs_bmapi  */
end_comment

begin_define
define|#
directive|define
name|XFS_BMAPI_WRITE
value|0x001
end_define

begin_comment
comment|/* write operation: allocate space */
end_comment

begin_define
define|#
directive|define
name|XFS_BMAPI_DELAY
value|0x002
end_define

begin_comment
comment|/* delayed write operation */
end_comment

begin_define
define|#
directive|define
name|XFS_BMAPI_ENTIRE
value|0x004
end_define

begin_comment
comment|/* return entire extent, not trimmed */
end_comment

begin_define
define|#
directive|define
name|XFS_BMAPI_METADATA
value|0x008
end_define

begin_comment
comment|/* mapping metadata not user data */
end_comment

begin_define
define|#
directive|define
name|XFS_BMAPI_EXACT
value|0x010
end_define

begin_comment
comment|/* allocate only to spec'd bounds */
end_comment

begin_define
define|#
directive|define
name|XFS_BMAPI_ATTRFORK
value|0x020
end_define

begin_comment
comment|/* use attribute fork not data */
end_comment

begin_define
define|#
directive|define
name|XFS_BMAPI_ASYNC
value|0x040
end_define

begin_comment
comment|/* bunmapi xactions can be async */
end_comment

begin_define
define|#
directive|define
name|XFS_BMAPI_RSVBLOCKS
value|0x080
end_define

begin_comment
comment|/* OK to alloc. reserved data blocks */
end_comment

begin_define
define|#
directive|define
name|XFS_BMAPI_PREALLOC
value|0x100
end_define

begin_comment
comment|/* preallocation op: unwritten space */
end_comment

begin_define
define|#
directive|define
name|XFS_BMAPI_IGSTATE
value|0x200
end_define

begin_comment
comment|/* Ignore state - */
end_comment

begin_comment
comment|/* combine contig. space */
end_comment

begin_define
define|#
directive|define
name|XFS_BMAPI_CONTIG
value|0x400
end_define

begin_comment
comment|/* must allocate only one extent */
end_comment

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_BMAPI_AFLAG
operator|)
end_if

begin_function_decl
name|int
name|xfs_bmapi_aflag
parameter_list|(
name|int
name|w
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_BMAPI_AFLAG
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAPI_AFLAG
parameter_list|(
name|w
parameter_list|)
value|xfs_bmapi_aflag(w)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAPI_AFLAG
parameter_list|(
name|w
parameter_list|)
value|((w) == XFS_ATTR_FORK ? XFS_BMAPI_ATTRFORK : 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Special values for xfs_bmbt_irec_t br_startblock field.  */
end_comment

begin_define
define|#
directive|define
name|DELAYSTARTBLOCK
value|((xfs_fsblock_t)-1LL)
end_define

begin_define
define|#
directive|define
name|HOLESTARTBLOCK
value|((xfs_fsblock_t)-2LL)
end_define

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_BMAP_INIT
operator|)
end_if

begin_function_decl
name|void
name|xfs_bmap_init
parameter_list|(
name|xfs_bmap_free_t
modifier|*
name|flp
parameter_list|,
name|xfs_fsblock_t
modifier|*
name|fbp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_BMAP_INIT
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_INIT
parameter_list|(
name|flp
parameter_list|,
name|fbp
parameter_list|)
value|xfs_bmap_init(flp,fbp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_INIT
parameter_list|(
name|flp
parameter_list|,
name|fbp
parameter_list|)
define|\
value|((flp)->xbf_first = NULL, (flp)->xbf_count = 0, \ 	 (flp)->xbf_low = 0, *(fbp) = NULLFSBLOCK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Argument structure for xfs_bmap_alloc.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_bmalloca
block|{
name|xfs_fsblock_t
name|firstblock
decl_stmt|;
comment|/* i/o first block allocated */
name|xfs_fsblock_t
name|rval
decl_stmt|;
comment|/* starting block of new extent */
name|xfs_fileoff_t
name|off
decl_stmt|;
comment|/* offset in file filling in */
name|struct
name|xfs_trans
modifier|*
name|tp
decl_stmt|;
comment|/* transaction pointer */
name|struct
name|xfs_inode
modifier|*
name|ip
decl_stmt|;
comment|/* incore inode pointer */
name|struct
name|xfs_bmbt_irec
modifier|*
name|prevp
decl_stmt|;
comment|/* extent before the new one */
name|struct
name|xfs_bmbt_irec
modifier|*
name|gotp
decl_stmt|;
comment|/* extent after, or delayed */
name|xfs_extlen_t
name|alen
decl_stmt|;
comment|/* i/o length asked/allocated */
name|xfs_extlen_t
name|total
decl_stmt|;
comment|/* total blocks needed for xaction */
name|xfs_extlen_t
name|minlen
decl_stmt|;
comment|/* mininum allocation size (blocks) */
name|xfs_extlen_t
name|minleft
decl_stmt|;
comment|/* amount must be left after alloc */
name|char
name|eof
decl_stmt|;
comment|/* set if allocating past last extent */
name|char
name|wasdel
decl_stmt|;
comment|/* replacing a delayed allocation */
name|char
name|userdata
decl_stmt|;
comment|/* set if is user data */
name|char
name|low
decl_stmt|;
comment|/* low on space, using seq'l ags */
name|char
name|aeof
decl_stmt|;
comment|/* allocated space at eof */
block|}
name|xfs_bmalloca_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XFS_BMAP_TRACE
argument_list|)
end_if

begin_comment
comment|/*  * Trace operations for bmap extent tracing  */
end_comment

begin_define
define|#
directive|define
name|XFS_BMAP_KTRACE_DELETE
value|1
end_define

begin_define
define|#
directive|define
name|XFS_BMAP_KTRACE_INSERT
value|2
end_define

begin_define
define|#
directive|define
name|XFS_BMAP_KTRACE_PRE_UP
value|3
end_define

begin_define
define|#
directive|define
name|XFS_BMAP_KTRACE_POST_UP
value|4
end_define

begin_define
define|#
directive|define
name|XFS_BMAP_TRACE_SIZE
value|4096
end_define

begin_comment
comment|/* size of global trace buffer */
end_comment

begin_define
define|#
directive|define
name|XFS_BMAP_KTRACE_SIZE
value|32
end_define

begin_comment
comment|/* size of per-inode trace buffer */
end_comment

begin_decl_stmt
specifier|extern
name|ktrace_t
modifier|*
name|xfs_bmap_trace_buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Add bmap trace insert entries for all the contents of the extent list.  */
end_comment

begin_function_decl
name|void
name|xfs_bmap_trace_exlist
parameter_list|(
name|char
modifier|*
name|fname
parameter_list|,
comment|/* function name */
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|,
comment|/* incore inode pointer */
name|xfs_extnum_t
name|cnt
parameter_list|,
comment|/* count of entries in list */
name|int
name|whichfork
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* data or attr fork */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xfs_bmap_trace_exlist
parameter_list|(
name|f
parameter_list|,
name|ip
parameter_list|,
name|c
parameter_list|,
name|w
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Convert inode from non-attributed to attributed.  * Must not be in a transaction, ip must not be locked.  */
end_comment

begin_function_decl
name|int
comment|/* error code */
name|xfs_bmap_add_attrfork
parameter_list|(
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|,
comment|/* incore inode pointer */
name|int
name|rsvd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* flag for reserved block allocation */
end_comment

begin_comment
comment|/*  * Add the extent to the list of extents to be free at transaction end.  * The list is maintained sorted (by block number).  */
end_comment

begin_function_decl
name|void
name|xfs_bmap_add_free
parameter_list|(
name|xfs_fsblock_t
name|bno
parameter_list|,
comment|/* fs block number of extent */
name|xfs_filblks_t
name|len
parameter_list|,
comment|/* length of extent */
name|xfs_bmap_free_t
modifier|*
name|flist
parameter_list|,
comment|/* list of extents */
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mount point structure */
end_comment

begin_comment
comment|/*  * Routine to clean up the free list data structure when  * an error occurs during a transaction.  */
end_comment

begin_function_decl
name|void
name|xfs_bmap_cancel
parameter_list|(
name|xfs_bmap_free_t
modifier|*
name|flist
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* free list to clean up */
end_comment

begin_comment
comment|/*  * Routine to check if a specified inode is swap capable.  */
end_comment

begin_function_decl
name|int
name|xfs_bmap_check_swappable
parameter_list|(
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* incore inode */
end_comment

begin_comment
comment|/*  * Compute and fill in the value of the maximum depth of a bmap btree  * in this filesystem.  Done once, during mount.  */
end_comment

begin_function_decl
name|void
name|xfs_bmap_compute_maxlevels
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
comment|/* file system mount structure */
name|int
name|whichfork
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* data or attr fork */
end_comment

begin_comment
comment|/*  * Routine to be called at transaction's end by xfs_bmapi, xfs_bunmapi  * caller.  Frees all the extents that need freeing, which must be done  * last due to locking considerations.  *  * Return 1 if the given transaction was committed and a new one allocated,  * and 0 otherwise.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_bmap_finish
parameter_list|(
name|struct
name|xfs_trans
modifier|*
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer addr */
name|xfs_bmap_free_t
modifier|*
name|flist
parameter_list|,
comment|/* i/o: list extents to free */
name|xfs_fsblock_t
name|firstblock
parameter_list|,
comment|/* controlled a.g. for allocs */
name|int
modifier|*
name|committed
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* xact committed or not */
end_comment

begin_comment
comment|/*  * Returns the file-relative block number of the first unused block in the file.  * This is the lowest-address hole if the file has holes, else the first block  * past the end of file.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_bmap_first_unused
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|,
comment|/* incore inode */
name|xfs_extlen_t
name|len
parameter_list|,
comment|/* size of hole to find */
name|xfs_fileoff_t
modifier|*
name|unused
parameter_list|,
comment|/* unused block num */
name|int
name|whichfork
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* data or attr fork */
end_comment

begin_comment
comment|/*  * Returns the file-relative block number of the last block + 1 before  * last_block (input value) in the file.  * This is not based on i_size, it is based on the extent list.  * Returns 0 for local files, as they do not have an extent list.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_bmap_last_before
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|,
comment|/* incore inode */
name|xfs_fileoff_t
modifier|*
name|last_block
parameter_list|,
comment|/* last block */
name|int
name|whichfork
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* data or attr fork */
end_comment

begin_comment
comment|/*  * Returns the file-relative block number of the first block past eof in  * the file.  This is not based on i_size, it is based on the extent list.  * Returns 0 for local files, as they do not have an extent list.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_bmap_last_offset
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|,
comment|/* incore inode */
name|xfs_fileoff_t
modifier|*
name|unused
parameter_list|,
comment|/* last block num */
name|int
name|whichfork
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* data or attr fork */
end_comment

begin_comment
comment|/*  * Returns whether the selected fork of the inode has exactly one  * block or not.  For the data fork we check this matches di_size,  * implying the file's range is 0..bsize-1.  */
end_comment

begin_function_decl
name|int
name|xfs_bmap_one_block
parameter_list|(
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|,
comment|/* incore inode */
name|int
name|whichfork
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* data or attr fork */
end_comment

begin_comment
comment|/*  * Read in the extents to iu_extents.  * All inode fields are set up by caller, we just traverse the btree  * and copy the records in.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_bmap_read_extents
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|,
comment|/* incore inode */
name|int
name|whichfork
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* data or attr fork */
end_comment

begin_comment
comment|/*  * Map file blocks to filesystem blocks.  * File range is given by the bno/len pair.  * Adds blocks to file if a write ("flags& XFS_BMAPI_WRITE" set)  * into a hole or past eof.  * Only allocates blocks from a single allocation group,  * to avoid locking problems.  * The returned value in "firstblock" from the first call in a transaction  * must be remembered and presented to subsequent calls in "firstblock".  * An upper bound for the number of blocks to be allocated is supplied to  * the first call in "total"; if no allocation group has that many free  * blocks then the call will fail (return NULLFSBLOCK in "firstblock").  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_bmapi
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|,
comment|/* incore inode */
name|xfs_fileoff_t
name|bno
parameter_list|,
comment|/* starting file offs. mapped */
name|xfs_filblks_t
name|len
parameter_list|,
comment|/* length to map in file */
name|int
name|flags
parameter_list|,
comment|/* XFS_BMAPI_... */
name|xfs_fsblock_t
modifier|*
name|firstblock
parameter_list|,
comment|/* first allocated block 						   controls a.g. for allocs */
name|xfs_extlen_t
name|total
parameter_list|,
comment|/* total blocks needed */
name|struct
name|xfs_bmbt_irec
modifier|*
name|mval
parameter_list|,
comment|/* output: map values */
name|int
modifier|*
name|nmap
parameter_list|,
comment|/* i/o: mval size/count */
name|xfs_bmap_free_t
modifier|*
name|flist
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* i/o: list extents to free */
end_comment

begin_comment
comment|/*  * Map file blocks to filesystem blocks, simple version.  * One block only, read-only.  * For flags, only the XFS_BMAPI_ATTRFORK flag is examined.  * For the other flag values, the effect is as if XFS_BMAPI_METADATA  * was set and all the others were clear.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_bmapi_single
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|,
comment|/* incore inode */
name|int
name|whichfork
parameter_list|,
comment|/* data or attr fork */
name|xfs_fsblock_t
modifier|*
name|fsb
parameter_list|,
comment|/* output: mapped block */
name|xfs_fileoff_t
name|bno
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* starting file offs. mapped */
end_comment

begin_comment
comment|/*  * Unmap (remove) blocks from a file.  * If nexts is nonzero then the number of extents to remove is limited to  * that value.  If not all extents in the block range can be removed then  * *done is set.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_bunmapi
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|,
comment|/* incore inode */
name|xfs_fileoff_t
name|bno
parameter_list|,
comment|/* starting offset to unmap */
name|xfs_filblks_t
name|len
parameter_list|,
comment|/* length to unmap in file */
name|int
name|flags
parameter_list|,
comment|/* XFS_BMAPI_... */
name|xfs_extnum_t
name|nexts
parameter_list|,
comment|/* number of extents max */
name|xfs_fsblock_t
modifier|*
name|firstblock
parameter_list|,
comment|/* first allocated block 						   controls a.g. for allocs */
name|xfs_bmap_free_t
modifier|*
name|flist
parameter_list|,
comment|/* i/o: list extents to free */
name|int
modifier|*
name|done
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set if not done yet */
end_comment

begin_comment
comment|/*  * Fcntl interface to xfs_bmapi.  */
end_comment

begin_function_decl
name|int
comment|/* error code */
name|xfs_getbmap
parameter_list|(
name|bhv_desc_t
modifier|*
name|bdp
parameter_list|,
comment|/* XFS behavior descriptor*/
name|struct
name|getbmap
modifier|*
name|bmv
parameter_list|,
comment|/* user bmap structure */
name|void
modifier|*
name|ap
parameter_list|,
comment|/* pointer to user's array */
name|int
name|iflags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* interface flags */
end_comment

begin_comment
comment|/*  * Check the last inode extent to determine whether this allocation will result  * in blocks being allocated at the end of the file. When we allocate new data  * blocks at the end of the file which do not start at the previous data block,  * we will try to align the new blocks at stripe unit boundaries.  */
end_comment

begin_function_decl
name|int
name|xfs_bmap_isaeof
parameter_list|(
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|,
name|xfs_fileoff_t
name|off
parameter_list|,
name|int
name|whichfork
parameter_list|,
name|char
modifier|*
name|aeof
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Check if the endoff is outside the last extent. If so the caller will grow  * the allocation to a stripe unit boundary  */
end_comment

begin_function_decl
name|int
name|xfs_bmap_eof
parameter_list|(
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|,
name|xfs_fileoff_t
name|endoff
parameter_list|,
name|int
name|whichfork
parameter_list|,
name|int
modifier|*
name|eof
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Count fsblocks of the given fork.  */
end_comment

begin_function_decl
name|int
name|xfs_bmap_count_blocks
parameter_list|(
name|xfs_trans_t
modifier|*
name|tp
parameter_list|,
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|,
name|int
name|whichfork
parameter_list|,
name|int
modifier|*
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Check an extent list, which has just been read, for  * any bit in the extent flag field.  */
end_comment

begin_function_decl
name|int
name|xfs_check_nostate_extents
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|ep
parameter_list|,
name|xfs_extnum_t
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_BMAP_H__ */
end_comment

end_unit

