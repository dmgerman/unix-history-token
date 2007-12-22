begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2002,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_DA_BTREE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_DA_BTREE_H__
end_define

begin_struct_decl
struct_decl|struct
name|xfs_buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_bmap_free
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

begin_struct_decl
struct_decl|struct
name|zone
struct_decl|;
end_struct_decl

begin_comment
comment|/*========================================================================  * Directory Structure when greater than XFS_LBSIZE(mp) bytes.  *========================================================================*/
end_comment

begin_comment
comment|/*  * This structure is common to both leaf nodes and non-leaf nodes in the Btree.  *  * Is is used to manage a doubly linked list of all blocks at the same  * level in the Btree, and to identify which type of block this is.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DA_NODE_MAGIC
value|0xfebe
end_define

begin_comment
comment|/* magic number: non-leaf blocks */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR_LEAF_MAGIC
value|0xfeeb
end_define

begin_comment
comment|/* magic number: directory leaf blks */
end_comment

begin_define
define|#
directive|define
name|XFS_ATTR_LEAF_MAGIC
value|0xfbee
end_define

begin_comment
comment|/* magic number: attribute leaf blks */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_LEAF1_MAGIC
value|0xd2f1
end_define

begin_comment
comment|/* magic number: v2 dirlf single blks */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_LEAFN_MAGIC
value|0xd2ff
end_define

begin_comment
comment|/* magic number: v2 dirlf multi blks */
end_comment

begin_define
define|#
directive|define
name|XFS_DIRX_LEAF_MAGIC
parameter_list|(
name|mp
parameter_list|)
define|\
value|(XFS_DIR_IS_V1(mp) ? XFS_DIR_LEAF_MAGIC : XFS_DIR2_LEAFN_MAGIC)
end_define

begin_typedef
typedef|typedef
struct|struct
name|xfs_da_blkinfo
block|{
name|__be32
name|forw
decl_stmt|;
comment|/* previous block in list */
name|__be32
name|back
decl_stmt|;
comment|/* following block in list */
name|__be16
name|magic
decl_stmt|;
comment|/* validity check on block */
name|__be16
name|pad
decl_stmt|;
comment|/* unused */
block|}
name|xfs_da_blkinfo_t
typedef|;
end_typedef

begin_comment
comment|/*  * This is the structure of the root and intermediate nodes in the Btree.  * The leaf nodes are defined above.  *  * Entries are not packed.  *  * Since we have duplicate keys, use a binary search but always follow  * all match in the block, not just the first match found.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DA_NODE_MAXDEPTH
value|5
end_define

begin_comment
comment|/* max depth of Btree */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_da_intnode
block|{
struct|struct
name|xfs_da_node_hdr
block|{
comment|/* constant-structure header block */
name|xfs_da_blkinfo_t
name|info
decl_stmt|;
comment|/* block type, links, etc. */
name|__be16
name|count
decl_stmt|;
comment|/* count of active entries */
name|__be16
name|level
decl_stmt|;
comment|/* level above leaves (leaf == 0) */
block|}
name|hdr
struct|;
struct|struct
name|xfs_da_node_entry
block|{
name|__be32
name|hashval
decl_stmt|;
comment|/* hash value for this descendant */
name|__be32
name|before
decl_stmt|;
comment|/* Btree block before this key */
block|}
name|btree
index|[
literal|1
index|]
struct|;
comment|/* variable sized array of keys */
block|}
name|xfs_da_intnode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xfs_da_node_hdr
name|xfs_da_node_hdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xfs_da_node_entry
name|xfs_da_node_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_DA_MAXHASH
value|((xfs_dahash_t)-1)
end_define

begin_comment
comment|/* largest valid hash value */
end_comment

begin_define
define|#
directive|define
name|XFS_LBSIZE
parameter_list|(
name|mp
parameter_list|)
value|(mp)->m_sb.sb_blocksize
end_define

begin_define
define|#
directive|define
name|XFS_LBLOG
parameter_list|(
name|mp
parameter_list|)
value|(mp)->m_sb.sb_blocklog
end_define

begin_define
define|#
directive|define
name|XFS_DA_MAKE_BNOENTRY
parameter_list|(
name|mp
parameter_list|,
name|bno
parameter_list|,
name|entry
parameter_list|)
define|\
value|(((bno)<< (mp)->m_dircook_elog) | (entry))
end_define

begin_define
define|#
directive|define
name|XFS_DA_MAKE_COOKIE
parameter_list|(
name|mp
parameter_list|,
name|bno
parameter_list|,
name|entry
parameter_list|,
name|hash
parameter_list|)
define|\
value|(((xfs_off_t)XFS_DA_MAKE_BNOENTRY(mp, bno, entry)<< 32) | (hash))
end_define

begin_define
define|#
directive|define
name|XFS_DA_COOKIE_HASH
parameter_list|(
name|mp
parameter_list|,
name|cookie
parameter_list|)
value|((xfs_dahash_t)cookie)
end_define

begin_define
define|#
directive|define
name|XFS_DA_COOKIE_BNO
parameter_list|(
name|mp
parameter_list|,
name|cookie
parameter_list|)
define|\
value|((((xfs_off_t)(cookie)>> 31) == -1LL ? \ 		(xfs_dablk_t)0 : \ 		(xfs_dablk_t)((xfs_off_t)(cookie)>> \ 				((mp)->m_dircook_elog + 32))))
end_define

begin_define
define|#
directive|define
name|XFS_DA_COOKIE_ENTRY
parameter_list|(
name|mp
parameter_list|,
name|cookie
parameter_list|)
define|\
value|((((xfs_off_t)(cookie)>> 31) == -1LL ?	\ 		(xfs_dablk_t)0 : \ 		(xfs_dablk_t)(((xfs_off_t)(cookie)>> 32)& \ 				((1<< (mp)->m_dircook_elog) - 1))))
end_define

begin_comment
comment|/*========================================================================  * Btree searching and modification structure definitions.  *========================================================================*/
end_comment

begin_comment
comment|/*  * Structure to ease passing around component names.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_da_args
block|{
specifier|const
name|uchar_t
modifier|*
name|name
decl_stmt|;
comment|/* string (maybe not NULL terminated) */
name|int
name|namelen
decl_stmt|;
comment|/* length of string (maybe no NULL) */
name|uchar_t
modifier|*
name|value
decl_stmt|;
comment|/* set of bytes (maybe contain NULLs) */
name|int
name|valuelen
decl_stmt|;
comment|/* length of value */
name|int
name|flags
decl_stmt|;
comment|/* argument flags (eg: ATTR_NOCREATE) */
name|xfs_dahash_t
name|hashval
decl_stmt|;
comment|/* hash value of name */
name|xfs_ino_t
name|inumber
decl_stmt|;
comment|/* input/output inode number */
name|struct
name|xfs_inode
modifier|*
name|dp
decl_stmt|;
comment|/* directory inode to manipulate */
name|xfs_fsblock_t
modifier|*
name|firstblock
decl_stmt|;
comment|/* ptr to firstblock for bmap calls */
name|struct
name|xfs_bmap_free
modifier|*
name|flist
decl_stmt|;
comment|/* ptr to freelist for bmap_finish */
name|struct
name|xfs_trans
modifier|*
name|trans
decl_stmt|;
comment|/* current trans (changes over time) */
name|xfs_extlen_t
name|total
decl_stmt|;
comment|/* total blocks needed, for 1st bmap */
name|int
name|whichfork
decl_stmt|;
comment|/* data or attribute fork */
name|xfs_dablk_t
name|blkno
decl_stmt|;
comment|/* blkno of attr leaf of interest */
name|int
name|index
decl_stmt|;
comment|/* index of attr of interest in blk */
name|xfs_dablk_t
name|rmtblkno
decl_stmt|;
comment|/* remote attr value starting blkno */
name|int
name|rmtblkcnt
decl_stmt|;
comment|/* remote attr value block count */
name|xfs_dablk_t
name|blkno2
decl_stmt|;
comment|/* blkno of 2nd attr leaf of interest */
name|int
name|index2
decl_stmt|;
comment|/* index of 2nd attr in blk */
name|xfs_dablk_t
name|rmtblkno2
decl_stmt|;
comment|/* remote attr value starting blkno */
name|int
name|rmtblkcnt2
decl_stmt|;
comment|/* remote attr value block count */
name|unsigned
name|char
name|justcheck
decl_stmt|;
comment|/* T/F: check for ok with no space */
name|unsigned
name|char
name|rename
decl_stmt|;
comment|/* T/F: this is an atomic rename op */
name|unsigned
name|char
name|addname
decl_stmt|;
comment|/* T/F: this is an add operation */
name|unsigned
name|char
name|oknoent
decl_stmt|;
comment|/* T/F: ok to return ENOENT, else die */
block|}
name|xfs_da_args_t
typedef|;
end_typedef

begin_comment
comment|/*  * Structure to describe buffer(s) for a block.  * This is needed in the directory version 2 format case, when  * multiple non-contiguous fsblocks might be needed to cover one  * logical directory block.  * If the buffer count is 1 then the data pointer points to the  * same place as the b_addr field for the buffer, else to kmem_alloced memory.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dabuf
block|{
name|int
name|nbuf
decl_stmt|;
comment|/* number of buffer pointers present */
name|short
name|dirty
decl_stmt|;
comment|/* data needs to be copied back */
name|short
name|bbcount
decl_stmt|;
comment|/* how large is data in bbs */
name|void
modifier|*
name|data
decl_stmt|;
comment|/* pointer for buffers' data */
ifdef|#
directive|ifdef
name|XFS_DABUF_DEBUG
name|inst_t
modifier|*
name|ra
decl_stmt|;
comment|/* return address of caller to make */
name|struct
name|xfs_dabuf
modifier|*
name|next
decl_stmt|;
comment|/* next in global chain */
name|struct
name|xfs_dabuf
modifier|*
name|prev
decl_stmt|;
comment|/* previous in global chain */
name|struct
name|xfs_buftarg
modifier|*
name|target
decl_stmt|;
comment|/* device for buffer */
name|xfs_daddr_t
name|blkno
decl_stmt|;
comment|/* daddr first in bps[0] */
endif|#
directive|endif
name|struct
name|xfs_buf
modifier|*
name|bps
index|[
literal|1
index|]
decl_stmt|;
comment|/* actually nbuf of these */
block|}
name|xfs_dabuf_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_DA_BUF_SIZE
parameter_list|(
name|n
parameter_list|)
define|\
value|(sizeof(xfs_dabuf_t) + sizeof(struct xfs_buf *) * ((n) - 1))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|XFS_DABUF_DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|xfs_dabuf_t
modifier|*
name|xfs_dabuf_global_list
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Storage for holding state during Btree searches and split/join ops.  *  * Only need space for 5 intermediate nodes.  With a minimum of 62-way  * fanout to the Btree, we can support over 900 million directory blocks,  * which is slightly more than enough.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_da_state_blk
block|{
name|xfs_dabuf_t
modifier|*
name|bp
decl_stmt|;
comment|/* buffer containing block */
name|xfs_dablk_t
name|blkno
decl_stmt|;
comment|/* filesystem blkno of buffer */
name|xfs_daddr_t
name|disk_blkno
decl_stmt|;
comment|/* on-disk blkno (in BBs) of buffer */
name|int
name|index
decl_stmt|;
comment|/* relevant index into block */
name|xfs_dahash_t
name|hashval
decl_stmt|;
comment|/* last hash value in block */
name|int
name|magic
decl_stmt|;
comment|/* blk's magic number, ie: blk type */
block|}
name|xfs_da_state_blk_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_da_state_path
block|{
name|int
name|active
decl_stmt|;
comment|/* number of active levels */
name|xfs_da_state_blk_t
name|blk
index|[
name|XFS_DA_NODE_MAXDEPTH
index|]
decl_stmt|;
block|}
name|xfs_da_state_path_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_da_state
block|{
name|xfs_da_args_t
modifier|*
name|args
decl_stmt|;
comment|/* filename arguments */
name|struct
name|xfs_mount
modifier|*
name|mp
decl_stmt|;
comment|/* filesystem mount point */
name|unsigned
name|int
name|blocksize
decl_stmt|;
comment|/* logical block size */
name|unsigned
name|int
name|node_ents
decl_stmt|;
comment|/* how many entries in danode */
name|xfs_da_state_path_t
name|path
decl_stmt|;
comment|/* search/split paths */
name|xfs_da_state_path_t
name|altpath
decl_stmt|;
comment|/* alternate path for join */
name|unsigned
name|char
name|inleaf
decl_stmt|;
comment|/* insert into 1->lf, 0->splf */
name|unsigned
name|char
name|extravalid
decl_stmt|;
comment|/* T/F: extrablk is in use */
name|unsigned
name|char
name|extraafter
decl_stmt|;
comment|/* T/F: extrablk is after new */
name|xfs_da_state_blk_t
name|extrablk
decl_stmt|;
comment|/* for double-splits on leafs */
comment|/* for dirv2 extrablk is data */
block|}
name|xfs_da_state_t
typedef|;
end_typedef

begin_comment
comment|/*  * Utility macros to aid in logging changed structure fields.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DA_LOGOFF
parameter_list|(
name|BASE
parameter_list|,
name|ADDR
parameter_list|)
value|((char *)(ADDR) - (char *)(BASE))
end_define

begin_define
define|#
directive|define
name|XFS_DA_LOGRANGE
parameter_list|(
name|BASE
parameter_list|,
name|ADDR
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|(uint)(XFS_DA_LOGOFF(BASE, ADDR)), \ 		(uint)(XFS_DA_LOGOFF(BASE, ADDR)+(SIZE)-1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/*========================================================================  * Function prototypes for the kernel.  *========================================================================*/
end_comment

begin_comment
comment|/*  * Routines used for growing the Btree.  */
end_comment

begin_function_decl
name|int
name|xfs_da_node_create
parameter_list|(
name|xfs_da_args_t
modifier|*
name|args
parameter_list|,
name|xfs_dablk_t
name|blkno
parameter_list|,
name|int
name|level
parameter_list|,
name|xfs_dabuf_t
modifier|*
modifier|*
name|bpp
parameter_list|,
name|int
name|whichfork
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_da_split
parameter_list|(
name|xfs_da_state_t
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Routines used for shrinking the Btree.  */
end_comment

begin_function_decl
name|int
name|xfs_da_join
parameter_list|(
name|xfs_da_state_t
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_da_fixhashpath
parameter_list|(
name|xfs_da_state_t
modifier|*
name|state
parameter_list|,
name|xfs_da_state_path_t
modifier|*
name|path_to_to_fix
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Routines used for finding things in the Btree.  */
end_comment

begin_function_decl
name|int
name|xfs_da_node_lookup_int
parameter_list|(
name|xfs_da_state_t
modifier|*
name|state
parameter_list|,
name|int
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_da_path_shift
parameter_list|(
name|xfs_da_state_t
modifier|*
name|state
parameter_list|,
name|xfs_da_state_path_t
modifier|*
name|path
parameter_list|,
name|int
name|forward
parameter_list|,
name|int
name|release
parameter_list|,
name|int
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Utility routines.  */
end_comment

begin_function_decl
name|int
name|xfs_da_blk_link
parameter_list|(
name|xfs_da_state_t
modifier|*
name|state
parameter_list|,
name|xfs_da_state_blk_t
modifier|*
name|old_blk
parameter_list|,
name|xfs_da_state_blk_t
modifier|*
name|new_blk
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Utility routines.  */
end_comment

begin_function_decl
name|int
name|xfs_da_grow_inode
parameter_list|(
name|xfs_da_args_t
modifier|*
name|args
parameter_list|,
name|xfs_dablk_t
modifier|*
name|new_blkno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_da_get_buf
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|trans
parameter_list|,
name|struct
name|xfs_inode
modifier|*
name|dp
parameter_list|,
name|xfs_dablk_t
name|bno
parameter_list|,
name|xfs_daddr_t
name|mappedbno
parameter_list|,
name|xfs_dabuf_t
modifier|*
modifier|*
name|bp
parameter_list|,
name|int
name|whichfork
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_da_read_buf
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|trans
parameter_list|,
name|struct
name|xfs_inode
modifier|*
name|dp
parameter_list|,
name|xfs_dablk_t
name|bno
parameter_list|,
name|xfs_daddr_t
name|mappedbno
parameter_list|,
name|xfs_dabuf_t
modifier|*
modifier|*
name|bpp
parameter_list|,
name|int
name|whichfork
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_daddr_t
name|xfs_da_reada_buf
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|trans
parameter_list|,
name|struct
name|xfs_inode
modifier|*
name|dp
parameter_list|,
name|xfs_dablk_t
name|bno
parameter_list|,
name|int
name|whichfork
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_da_shrink_inode
parameter_list|(
name|xfs_da_args_t
modifier|*
name|args
parameter_list|,
name|xfs_dablk_t
name|dead_blkno
parameter_list|,
name|xfs_dabuf_t
modifier|*
name|dead_buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint
name|xfs_da_hashname
parameter_list|(
specifier|const
name|uchar_t
modifier|*
name|name_string
parameter_list|,
name|int
name|name_length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint
name|xfs_da_log2_roundup
parameter_list|(
name|uint
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_da_state_t
modifier|*
name|xfs_da_state_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_da_state_free
parameter_list|(
name|xfs_da_state_t
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_da_buf_done
parameter_list|(
name|xfs_dabuf_t
modifier|*
name|dabuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_da_log_buf
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
name|xfs_dabuf_t
modifier|*
name|dabuf
parameter_list|,
name|uint
name|first
parameter_list|,
name|uint
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_da_brelse
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
name|xfs_dabuf_t
modifier|*
name|dabuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_da_binval
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
name|xfs_dabuf_t
modifier|*
name|dabuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_daddr_t
name|xfs_da_blkno
parameter_list|(
name|xfs_dabuf_t
modifier|*
name|dabuf
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|kmem_zone
modifier|*
name|xfs_da_state_zone
decl_stmt|;
end_decl_stmt

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
comment|/* __XFS_DA_BTREE_H__ */
end_comment

end_unit

