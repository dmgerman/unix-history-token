begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000, 2002-2003 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_ATTR_LEAF_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_ATTR_LEAF_H__
end_define

begin_comment
comment|/*  * Attribute storage layout, internal structure, access macros, etc.  *  * Attribute lists are structured around Btrees where all the data  * elements are in the leaf nodes.  Attribute names are hashed into an int,  * then that int is used as the index into the Btree.  Since the hashval  * of an attribute name may not be unique, we may have duplicate keys.  The  * internal links in the Btree are logical block offsets into the file.  */
end_comment

begin_struct_decl
struct_decl|struct
name|attrlist
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|attrlist_cursor_kern
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|attrnames
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_dabuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_da_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_da_state
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_da_state_blk
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_trans
struct_decl|;
end_struct_decl

begin_comment
comment|/*========================================================================  * Attribute structure when equal to XFS_LBSIZE(mp) bytes.  *========================================================================*/
end_comment

begin_comment
comment|/*  * This is the structure of the leaf nodes in the Btree.  *  * Struct leaf_entry's are packed from the top.  Name/values grow from the  * bottom but are not packed.  The freemap contains run-length-encoded entries  * for the free bytes after the leaf_entry's, but only the N largest such,  * smaller runs are dropped.  When the freemap doesn't show enough space  * for an allocation, we compact the name/value area and try again.  If we  * still don't have enough space, then we have to split the block.  The  * name/value structs (both local and remote versions) must be 32bit aligned.  *  * Since we have duplicate hash keys, for each key that matches, compare  * the actual name string.  The root and intermediate node search always  * takes the first-in-the-block key match found, so we should only have  * to work "forw"ard.  If none matches, continue with the "forw"ard leaf  * nodes until the hash key changes or the attribute name is found.  *  * We store the fact that an attribute is a ROOT/USER/SECURE attribute in  * the leaf_entry.  The namespaces are independent only because we also look  * at the namespace bit when we are looking for a matching attribute name.  *  * We also store a "incomplete" bit in the leaf_entry.  It shows that an  * attribute is in the middle of being created and should not be shown to  * the user if we crash during the time that the bit is set.  We clear the  * bit when we have finished setting up the attribute.  We do this because  * we cannot create some large attributes inside a single transaction, and we  * need some indication that we weren't finished if we crash in the middle.  */
end_comment

begin_define
define|#
directive|define
name|XFS_ATTR_LEAF_MAPSIZE
value|3
end_define

begin_comment
comment|/* how many freespace slots */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_attr_leafblock
block|{
struct|struct
name|xfs_attr_leaf_hdr
block|{
comment|/* constant-structure header block */
name|xfs_da_blkinfo_t
name|info
decl_stmt|;
comment|/* block type, links, etc. */
name|__uint16_t
name|count
decl_stmt|;
comment|/* count of active leaf_entry's */
name|__uint16_t
name|usedbytes
decl_stmt|;
comment|/* num bytes of names/values stored */
name|__uint16_t
name|firstused
decl_stmt|;
comment|/* first used byte in name area */
name|__uint8_t
name|holes
decl_stmt|;
comment|/* != 0 if blk needs compaction */
name|__uint8_t
name|pad1
decl_stmt|;
struct|struct
name|xfs_attr_leaf_map
block|{
comment|/* RLE map of free bytes */
name|__uint16_t
name|base
decl_stmt|;
comment|/* base of free region */
name|__uint16_t
name|size
decl_stmt|;
comment|/* length of free region */
block|}
name|freemap
index|[
name|XFS_ATTR_LEAF_MAPSIZE
index|]
struct|;
comment|/* N largest free regions */
block|}
name|hdr
struct|;
struct|struct
name|xfs_attr_leaf_entry
block|{
comment|/* sorted on key, not name */
name|xfs_dahash_t
name|hashval
decl_stmt|;
comment|/* hash value of name */
name|__uint16_t
name|nameidx
decl_stmt|;
comment|/* index into buffer of name/value */
name|__uint8_t
name|flags
decl_stmt|;
comment|/* LOCAL/ROOT/SECURE/INCOMPLETE flag */
name|__uint8_t
name|pad2
decl_stmt|;
comment|/* unused pad byte */
block|}
name|entries
index|[
literal|1
index|]
struct|;
comment|/* variable sized array */
struct|struct
name|xfs_attr_leaf_name_local
block|{
name|__uint16_t
name|valuelen
decl_stmt|;
comment|/* number of bytes in value */
name|__uint8_t
name|namelen
decl_stmt|;
comment|/* length of name bytes */
name|__uint8_t
name|nameval
index|[
literal|1
index|]
decl_stmt|;
comment|/* name/value bytes */
block|}
name|namelist
struct|;
comment|/* grows from bottom of buf */
struct|struct
name|xfs_attr_leaf_name_remote
block|{
name|xfs_dablk_t
name|valueblk
decl_stmt|;
comment|/* block number of value bytes */
name|__uint32_t
name|valuelen
decl_stmt|;
comment|/* number of bytes in value */
name|__uint8_t
name|namelen
decl_stmt|;
comment|/* length of name bytes */
name|__uint8_t
name|name
index|[
literal|1
index|]
decl_stmt|;
comment|/* name bytes */
block|}
name|valuelist
struct|;
comment|/* grows from bottom of buf */
block|}
name|xfs_attr_leafblock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xfs_attr_leaf_hdr
name|xfs_attr_leaf_hdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xfs_attr_leaf_map
name|xfs_attr_leaf_map_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xfs_attr_leaf_entry
name|xfs_attr_leaf_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xfs_attr_leaf_name_local
name|xfs_attr_leaf_name_local_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xfs_attr_leaf_name_remote
name|xfs_attr_leaf_name_remote_t
typedef|;
end_typedef

begin_comment
comment|/*  * Flags used in the leaf_entry[i].flags field.  * NOTE: the INCOMPLETE bit must not collide with the flags bits specified  * on the system call, they are "or"ed together for various operations.  */
end_comment

begin_define
define|#
directive|define
name|XFS_ATTR_LOCAL_BIT
value|0
end_define

begin_comment
comment|/* attr is stored locally */
end_comment

begin_define
define|#
directive|define
name|XFS_ATTR_ROOT_BIT
value|1
end_define

begin_comment
comment|/* limit access to trusted attrs */
end_comment

begin_define
define|#
directive|define
name|XFS_ATTR_SECURE_BIT
value|2
end_define

begin_comment
comment|/* limit access to secure attrs */
end_comment

begin_define
define|#
directive|define
name|XFS_ATTR_INCOMPLETE_BIT
value|7
end_define

begin_comment
comment|/* attr in middle of create/delete */
end_comment

begin_define
define|#
directive|define
name|XFS_ATTR_LOCAL
value|(1<< XFS_ATTR_LOCAL_BIT)
end_define

begin_define
define|#
directive|define
name|XFS_ATTR_ROOT
value|(1<< XFS_ATTR_ROOT_BIT)
end_define

begin_define
define|#
directive|define
name|XFS_ATTR_SECURE
value|(1<< XFS_ATTR_SECURE_BIT)
end_define

begin_define
define|#
directive|define
name|XFS_ATTR_INCOMPLETE
value|(1<< XFS_ATTR_INCOMPLETE_BIT)
end_define

begin_comment
comment|/*  * Alignment for namelist and valuelist entries (since they are mixed  * there can be only one alignment value)  */
end_comment

begin_define
define|#
directive|define
name|XFS_ATTR_LEAF_NAME_ALIGN
value|((uint)sizeof(xfs_dablk_t))
end_define

begin_comment
comment|/*  * Cast typed pointers for "local" and "remote" name/value structs.  */
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
name|XFSSO_XFS_ATTR_LEAF_NAME_REMOTE
operator|)
end_if

begin_function_decl
name|xfs_attr_leaf_name_remote_t
modifier|*
name|xfs_attr_leaf_name_remote
parameter_list|(
name|xfs_attr_leafblock_t
modifier|*
name|leafp
parameter_list|,
name|int
name|idx
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
name|XFSSO_XFS_ATTR_LEAF_NAME_REMOTE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_ATTR_LEAF_NAME_REMOTE
parameter_list|(
name|leafp
parameter_list|,
name|idx
parameter_list|)
define|\
value|xfs_attr_leaf_name_remote(leafp,idx)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_ATTR_LEAF_NAME_REMOTE
parameter_list|(
name|leafp
parameter_list|,
name|idx
parameter_list|)
comment|/* remote name struct ptr */
define|\
value|((xfs_attr_leaf_name_remote_t *)		\&((char *)(leafp))[ INT_GET((leafp)->entries[idx].nameidx, ARCH_CONVERT) ])
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|XFSSO_XFS_ATTR_LEAF_NAME_LOCAL
operator|)
end_if

begin_function_decl
name|xfs_attr_leaf_name_local_t
modifier|*
name|xfs_attr_leaf_name_local
parameter_list|(
name|xfs_attr_leafblock_t
modifier|*
name|leafp
parameter_list|,
name|int
name|idx
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
name|XFSSO_XFS_ATTR_LEAF_NAME_LOCAL
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_ATTR_LEAF_NAME_LOCAL
parameter_list|(
name|leafp
parameter_list|,
name|idx
parameter_list|)
define|\
value|xfs_attr_leaf_name_local(leafp,idx)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_ATTR_LEAF_NAME_LOCAL
parameter_list|(
name|leafp
parameter_list|,
name|idx
parameter_list|)
comment|/* local name struct ptr */
define|\
value|((xfs_attr_leaf_name_local_t *)		\&((char *)(leafp))[ INT_GET((leafp)->entries[idx].nameidx, ARCH_CONVERT) ])
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|XFSSO_XFS_ATTR_LEAF_NAME
operator|)
end_if

begin_function_decl
name|char
modifier|*
name|xfs_attr_leaf_name
parameter_list|(
name|xfs_attr_leafblock_t
modifier|*
name|leafp
parameter_list|,
name|int
name|idx
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
name|XFSSO_XFS_ATTR_LEAF_NAME
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_ATTR_LEAF_NAME
parameter_list|(
name|leafp
parameter_list|,
name|idx
parameter_list|)
value|xfs_attr_leaf_name(leafp,idx)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_ATTR_LEAF_NAME
parameter_list|(
name|leafp
parameter_list|,
name|idx
parameter_list|)
comment|/* generic name struct ptr */
define|\
value|(&((char *)(leafp))[ INT_GET((leafp)->entries[idx].nameidx, ARCH_CONVERT) ])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Calculate total bytes used (including trailing pad for alignment) for  * a "local" name/value structure, a "remote" name/value structure, and  * a pointer which might be either.  */
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
name|XFSSO_XFS_ATTR_LEAF_ENTSIZE_REMOTE
operator|)
end_if

begin_function_decl
name|int
name|xfs_attr_leaf_entsize_remote
parameter_list|(
name|int
name|nlen
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
name|XFSSO_XFS_ATTR_LEAF_ENTSIZE_REMOTE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_ATTR_LEAF_ENTSIZE_REMOTE
parameter_list|(
name|nlen
parameter_list|)
define|\
value|xfs_attr_leaf_entsize_remote(nlen)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_ATTR_LEAF_ENTSIZE_REMOTE
parameter_list|(
name|nlen
parameter_list|)
comment|/* space for remote struct */
define|\
value|(((uint)sizeof(xfs_attr_leaf_name_remote_t) - 1 + (nlen) + \ 	  XFS_ATTR_LEAF_NAME_ALIGN - 1)& ~(XFS_ATTR_LEAF_NAME_ALIGN - 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|XFSSO_XFS_ATTR_LEAF_ENTSIZE_LOCAL
operator|)
end_if

begin_function_decl
name|int
name|xfs_attr_leaf_entsize_local
parameter_list|(
name|int
name|nlen
parameter_list|,
name|int
name|vlen
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
name|XFSSO_XFS_ATTR_LEAF_ENTSIZE_LOCAL
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_ATTR_LEAF_ENTSIZE_LOCAL
parameter_list|(
name|nlen
parameter_list|,
name|vlen
parameter_list|)
define|\
value|xfs_attr_leaf_entsize_local(nlen,vlen)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_ATTR_LEAF_ENTSIZE_LOCAL
parameter_list|(
name|nlen
parameter_list|,
name|vlen
parameter_list|)
comment|/* space for local struct */
define|\
value|(((uint)sizeof(xfs_attr_leaf_name_local_t) - 1 + (nlen) + (vlen) + \ 	  XFS_ATTR_LEAF_NAME_ALIGN - 1)& ~(XFS_ATTR_LEAF_NAME_ALIGN - 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|XFSSO_XFS_ATTR_LEAF_ENTSIZE_LOCAL_MAX
operator|)
end_if

begin_function_decl
name|int
name|xfs_attr_leaf_entsize_local_max
parameter_list|(
name|int
name|bsize
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
name|XFSSO_XFS_ATTR_LEAF_ENTSIZE_LOCAL_MAX
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_ATTR_LEAF_ENTSIZE_LOCAL_MAX
parameter_list|(
name|bsize
parameter_list|)
define|\
value|xfs_attr_leaf_entsize_local_max(bsize)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_ATTR_LEAF_ENTSIZE_LOCAL_MAX
parameter_list|(
name|bsize
parameter_list|)
comment|/* max local struct size */
define|\
value|(((bsize)>> 1) + ((bsize)>> 2))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*========================================================================  * Structure used to pass context around among the routines.  *========================================================================*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_attr_list_context
block|{
name|struct
name|xfs_inode
modifier|*
name|dp
decl_stmt|;
comment|/* inode */
name|struct
name|attrlist_cursor_kern
modifier|*
name|cursor
decl_stmt|;
comment|/* position in list */
name|struct
name|attrlist
modifier|*
name|alist
decl_stmt|;
comment|/* output buffer */
name|int
name|count
decl_stmt|;
comment|/* num used entries */
name|int
name|dupcnt
decl_stmt|;
comment|/* count dup hashvals seen */
name|int
name|bufsize
decl_stmt|;
comment|/* total buffer size */
name|int
name|firstu
decl_stmt|;
comment|/* first used byte in buffer */
name|int
name|flags
decl_stmt|;
comment|/* from VOP call */
name|int
name|resynch
decl_stmt|;
comment|/* T/F: resynch with cursor */
block|}
name|xfs_attr_list_context_t
typedef|;
end_typedef

begin_comment
comment|/*  * Used to keep a list of "remote value" extents when unlinking an inode.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_attr_inactive_list
block|{
name|xfs_dablk_t
name|valueblk
decl_stmt|;
comment|/* block number of value bytes */
name|int
name|valuelen
decl_stmt|;
comment|/* number of bytes in value */
block|}
name|xfs_attr_inactive_list_t
typedef|;
end_typedef

begin_comment
comment|/*========================================================================  * Function prototypes for the kernel.  *========================================================================*/
end_comment

begin_comment
comment|/*  * Internal routines when dirsize< XFS_LITINO(mp).  */
end_comment

begin_function_decl
name|int
name|xfs_attr_shortform_create
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_shortform_add
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|add
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_shortform_lookup
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_shortform_to_leaf
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_shortform_remove
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|remove
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_shortform_list
parameter_list|(
name|struct
name|xfs_attr_list_context
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_shortform_replace
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_shortform_allfit
parameter_list|(
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|,
name|struct
name|xfs_inode
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Internal routines when dirsize == XFS_LBSIZE(mp).  */
end_comment

begin_function_decl
name|int
name|xfs_attr_leaf_to_node
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_leaf_to_shortform
parameter_list|(
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|,
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_leaf_clearflag
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_leaf_setflag
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_leaf_flipflags
parameter_list|(
name|xfs_da_args_t
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Routines used for growing the Btree.  */
end_comment

begin_function_decl
name|int
name|xfs_attr_leaf_create
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|xfs_dablk_t
name|which_block
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
modifier|*
name|bpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_leaf_split
parameter_list|(
name|struct
name|xfs_da_state
modifier|*
name|state
parameter_list|,
name|struct
name|xfs_da_state_blk
modifier|*
name|oldblk
parameter_list|,
name|struct
name|xfs_da_state_blk
modifier|*
name|newblk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_leaf_lookup_int
parameter_list|(
name|struct
name|xfs_dabuf
modifier|*
name|leaf
parameter_list|,
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_leaf_getvalue
parameter_list|(
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|,
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_leaf_add
parameter_list|(
name|struct
name|xfs_dabuf
modifier|*
name|leaf_buffer
parameter_list|,
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_leaf_remove
parameter_list|(
name|struct
name|xfs_dabuf
modifier|*
name|leaf_buffer
parameter_list|,
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_leaf_list_int
parameter_list|(
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|,
name|struct
name|xfs_attr_list_context
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Routines used for shrinking the Btree.  */
end_comment

begin_function_decl
name|int
name|xfs_attr_leaf_toosmall
parameter_list|(
name|struct
name|xfs_da_state
modifier|*
name|state
parameter_list|,
name|int
modifier|*
name|retval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_attr_leaf_unbalance
parameter_list|(
name|struct
name|xfs_da_state
modifier|*
name|state
parameter_list|,
name|struct
name|xfs_da_state_blk
modifier|*
name|drop_blk
parameter_list|,
name|struct
name|xfs_da_state_blk
modifier|*
name|save_blk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_root_inactive
parameter_list|(
name|struct
name|xfs_trans
modifier|*
modifier|*
name|trans
parameter_list|,
name|struct
name|xfs_inode
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_node_inactive
parameter_list|(
name|struct
name|xfs_trans
modifier|*
modifier|*
name|trans
parameter_list|,
name|struct
name|xfs_inode
modifier|*
name|dp
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|,
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_leaf_inactive
parameter_list|(
name|struct
name|xfs_trans
modifier|*
modifier|*
name|trans
parameter_list|,
name|struct
name|xfs_inode
modifier|*
name|dp
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_leaf_freextent
parameter_list|(
name|struct
name|xfs_trans
modifier|*
modifier|*
name|trans
parameter_list|,
name|struct
name|xfs_inode
modifier|*
name|dp
parameter_list|,
name|xfs_dablk_t
name|blkno
parameter_list|,
name|int
name|blkcnt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Utility routines.  */
end_comment

begin_function_decl
name|xfs_dahash_t
name|xfs_attr_leaf_lasthash
parameter_list|(
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|,
name|int
modifier|*
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_leaf_order
parameter_list|(
name|struct
name|xfs_dabuf
modifier|*
name|leaf1_bp
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|leaf2_bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_leaf_newentsize
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|int
name|blocksize
parameter_list|,
name|int
modifier|*
name|local
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_leaf_entsize
parameter_list|(
name|struct
name|xfs_attr_leafblock
modifier|*
name|leaf
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_put_listent
parameter_list|(
name|struct
name|xfs_attr_list_context
modifier|*
name|context
parameter_list|,
name|struct
name|attrnames
modifier|*
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|int
name|namelen
parameter_list|,
name|int
name|valuelen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_rolltrans
parameter_list|(
name|struct
name|xfs_trans
modifier|*
modifier|*
name|transp
parameter_list|,
name|struct
name|xfs_inode
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_ATTR_LEAF_H__ */
end_comment

end_unit

