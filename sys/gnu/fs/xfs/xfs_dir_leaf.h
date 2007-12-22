begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_DIR_LEAF_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_DIR_LEAF_H__
end_define

begin_comment
comment|/*  * Directory layout, internal structure, access macros, etc.  *  * Large directories are structured around Btrees where all the data  * elements are in the leaf nodes.  Filenames are hashed into an int,  * then that int is used as the index into the Btree.  Since the hashval  * of a filename may not be unique, we may have duplicate keys.  The  * internal links in the Btree are logical block offsets into the file.  */
end_comment

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_bmap_free
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
name|xfs_dir_put_args
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
comment|/*========================================================================  * Directory Structure when equal to XFS_LBSIZE(mp) bytes.  *========================================================================*/
end_comment

begin_comment
comment|/*  * This is the structure of the leaf nodes in the Btree.  *  * Struct leaf_entry's are packed from the top.  Names grow from the bottom  * but are not packed.  The freemap contains run-length-encoded entries  * for the free bytes after the leaf_entry's, but only the N largest such,  * smaller runs are dropped.  When the freemap doesn't show enough space  * for an allocation, we compact the namelist area and try again.  If we  * still don't have enough space, then we have to split the block.  *  * Since we have duplicate hash keys, for each key that matches, compare  * the actual string.  The root and intermediate node search always takes  * the first-in-the-block key match found, so we should only have to work  * "forw"ard.  If none matches, continue with the "forw"ard leaf nodes  * until the hash key changes or the filename is found.  *  * The parent directory and the self-pointer are explicitly represented  * (ie: there are entries for "." and "..").  *  * Note that the count being a __uint16_t limits us to something like a  * blocksize of 1.3MB in the face of worst case (short) filenames.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR_LEAF_MAPSIZE
value|3
end_define

begin_comment
comment|/* how many freespace slots */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir_leaf_map
block|{
comment|/* RLE map of free bytes */
name|__uint16_t
name|base
decl_stmt|;
comment|/* base of free region */
name|__uint16_t
name|size
decl_stmt|;
comment|/* run length of free region */
block|}
name|xfs_dir_leaf_map_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir_leaf_hdr
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
name|namebytes
decl_stmt|;
comment|/* num bytes of name strings stored */
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
name|xfs_dir_leaf_map_t
name|freemap
index|[
name|XFS_DIR_LEAF_MAPSIZE
index|]
decl_stmt|;
block|}
name|xfs_dir_leaf_hdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir_leaf_entry
block|{
comment|/* sorted on key, not name */
name|xfs_dahash_t
name|hashval
decl_stmt|;
comment|/* hash value of name */
name|__uint16_t
name|nameidx
decl_stmt|;
comment|/* index into buffer of name */
name|__uint8_t
name|namelen
decl_stmt|;
comment|/* length of name string */
name|__uint8_t
name|pad2
decl_stmt|;
block|}
name|xfs_dir_leaf_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir_leaf_name
block|{
name|xfs_dir_ino_t
name|inumber
decl_stmt|;
comment|/* inode number for this key */
name|__uint8_t
name|name
index|[
literal|1
index|]
decl_stmt|;
comment|/* name string itself */
block|}
name|xfs_dir_leaf_name_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir_leafblock
block|{
name|xfs_dir_leaf_hdr_t
name|hdr
decl_stmt|;
comment|/* constant-structure header block */
name|xfs_dir_leaf_entry_t
name|entries
index|[
literal|1
index|]
decl_stmt|;
comment|/* var sized array */
name|xfs_dir_leaf_name_t
name|namelist
index|[
literal|1
index|]
decl_stmt|;
comment|/* grows from bottom of buf */
block|}
name|xfs_dir_leafblock_t
typedef|;
end_typedef

begin_comment
comment|/*  * Length of name for which a 512-byte block filesystem  * can get a double split.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR_LEAF_CAN_DOUBLE_SPLIT_LEN
define|\
value|(512 - (uint)sizeof(xfs_dir_leaf_hdr_t) - \ 	 (uint)sizeof(xfs_dir_leaf_entry_t) * 2 - \ 	 (uint)sizeof(xfs_dir_leaf_name_t) * 2 - (MAXNAMELEN - 2) + 1 + 1)
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_dir_put_t
function_decl|)
parameter_list|(
name|struct
name|xfs_dir_put_args
modifier|*
name|pa
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|xfs_off_t
name|o
decl_stmt|;
comment|/* offset (cookie) */
comment|/* 	 * Watch the order here (endian-ness dependent). 	 */
struct|struct
block|{
ifndef|#
directive|ifndef
name|XFS_NATIVE_HOST
name|xfs_dahash_t
name|h
decl_stmt|;
comment|/* hash value */
name|__uint32_t
name|be
decl_stmt|;
comment|/* block and entry */
else|#
directive|else
name|__uint32_t
name|be
decl_stmt|;
comment|/* block and entry */
name|xfs_dahash_t
name|h
decl_stmt|;
comment|/* hash value */
endif|#
directive|endif
comment|/* XFS_NATIVE_HOST */
block|}
name|s
struct|;
block|}
name|xfs_dircook_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_PUT_COOKIE
parameter_list|(
name|c
parameter_list|,
name|mp
parameter_list|,
name|bno
parameter_list|,
name|entry
parameter_list|,
name|hash
parameter_list|)
define|\
value|((c).s.be = XFS_DA_MAKE_BNOENTRY(mp, bno, entry), (c).s.h = (hash))
end_define

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir_put_args
block|{
name|xfs_dircook_t
name|cook
decl_stmt|;
comment|/* cookie of (next) entry */
name|xfs_intino_t
name|ino
decl_stmt|;
comment|/* inode number */
name|struct
name|xfs_dirent
modifier|*
name|dbp
decl_stmt|;
comment|/* buffer pointer */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* directory entry name */
name|int
name|namelen
decl_stmt|;
comment|/* length of name */
name|int
name|done
decl_stmt|;
comment|/* output: set if value was stored */
name|xfs_dir_put_t
name|put
decl_stmt|;
comment|/* put function ptr (i/o) */
name|struct
name|uio
modifier|*
name|uio
decl_stmt|;
comment|/* uio control structure */
block|}
name|xfs_dir_put_args_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_DIR_LEAF_ENTSIZE_BYNAME
parameter_list|(
name|len
parameter_list|)
define|\
value|xfs_dir_leaf_entsize_byname(len)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|xfs_dir_leaf_entsize_byname
parameter_list|(
name|int
name|len
parameter_list|)
block|{
return|return
operator|(
name|uint
operator|)
sizeof|sizeof
argument_list|(
name|xfs_dir_leaf_name_t
argument_list|)
operator|-
literal|1
operator|+
name|len
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_DIR_LEAF_ENTSIZE_BYENTRY
parameter_list|(
name|entry
parameter_list|)
define|\
value|xfs_dir_leaf_entsize_byentry(entry)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|xfs_dir_leaf_entsize_byentry
parameter_list|(
name|xfs_dir_leaf_entry_t
modifier|*
name|entry
parameter_list|)
block|{
return|return
operator|(
name|uint
operator|)
sizeof|sizeof
argument_list|(
name|xfs_dir_leaf_name_t
argument_list|)
operator|-
literal|1
operator|+
operator|(
name|entry
operator|)
operator|->
name|namelen
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_DIR_LEAF_NAMESTRUCT
parameter_list|(
name|leafp
parameter_list|,
name|offset
parameter_list|)
define|\
value|xfs_dir_leaf_namestruct(leafp,offset)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_dir_leaf_name_t
modifier|*
name|xfs_dir_leaf_namestruct
parameter_list|(
name|xfs_dir_leafblock_t
modifier|*
name|leafp
parameter_list|,
name|int
name|offset
parameter_list|)
block|{
return|return
operator|(
name|xfs_dir_leaf_name_t
operator|*
operator|)
operator|&
operator|(
operator|(
name|char
operator|*
operator|)
operator|(
name|leafp
operator|)
operator|)
index|[
name|offset
index|]
return|;
block|}
end_function

begin_comment
comment|/*========================================================================  * Function prototypes for the kernel.  *========================================================================*/
end_comment

begin_comment
comment|/*  * Internal routines when dirsize< XFS_LITINO(mp).  */
end_comment

begin_function_decl
name|int
name|xfs_dir_shortform_create
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|xfs_ino_t
name|parent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_dir_shortform_addname
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
name|xfs_dir_shortform_lookup
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
name|xfs_dir_shortform_to_leaf
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
name|xfs_dir_shortform_removename
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
name|xfs_dir_shortform_getdents
parameter_list|(
name|struct
name|xfs_inode
modifier|*
name|dp
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
modifier|*
name|eofp
parameter_list|,
name|struct
name|xfs_dirent
modifier|*
name|dbp
parameter_list|,
name|xfs_dir_put_t
name|put
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_dir_shortform_replace
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Internal routines when dirsize == XFS_LBSIZE(mp).  */
end_comment

begin_function_decl
name|int
name|xfs_dir_leaf_to_node
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
name|xfs_dir_leaf_to_shortform
parameter_list|(
name|struct
name|xfs_da_args
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
name|xfs_dir_leaf_split
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
name|xfs_dir_leaf_add
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
parameter_list|,
name|int
name|insertion_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_dir_leaf_addname
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
name|xfs_dir_leaf_lookup_int
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
parameter_list|,
name|int
modifier|*
name|index_found_at
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_dir_leaf_remove
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|trans
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|leaf_buffer
parameter_list|,
name|int
name|index_to_remove
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_dir_leaf_getdents_int
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
parameter_list|,
name|xfs_dablk_t
name|bno
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
modifier|*
name|eobp
parameter_list|,
name|struct
name|xfs_dirent
modifier|*
name|dbp
parameter_list|,
name|xfs_dir_put_t
name|put
parameter_list|,
name|xfs_daddr_t
name|nextda
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Routines used for shrinking the Btree.  */
end_comment

begin_function_decl
name|int
name|xfs_dir_leaf_toosmall
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
name|xfs_dir_leaf_unbalance
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

begin_comment
comment|/*  * Utility routines.  */
end_comment

begin_function_decl
name|uint
name|xfs_dir_leaf_lasthash
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
name|xfs_dir_leaf_order
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
name|xfs_dir_put_dirent64_direct
parameter_list|(
name|xfs_dir_put_args_t
modifier|*
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_dir_put_dirent64_uio
parameter_list|(
name|xfs_dir_put_args_t
modifier|*
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_dir_ino_validate
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_ino_t
name|ino
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Global data.  */
end_comment

begin_decl_stmt
specifier|extern
name|xfs_dahash_t
name|xfs_dir_hash_dot
decl_stmt|,
name|xfs_dir_hash_dotdot
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_DIR_LEAF_H__ */
end_comment

end_unit

