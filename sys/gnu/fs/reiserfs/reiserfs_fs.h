begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2000 Hans Reiser  * See README for licensing and copyright details  *   * Ported to FreeBSD by Jean-Sébastien Pédron<jspedron@club-internet.fr>  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_REISERFS_REISERFS_FS_H
end_ifndef

begin_define
define|#
directive|define
name|_GNU_REISERFS_REISERFS_FS_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/namei.h>
end_include

begin_include
include|#
directive|include
file|<sys/priv.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/dirent.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_comment
comment|//#include<sys/mutex.h>
end_comment

begin_include
include|#
directive|include
file|<sys/ctype.h>
end_include

begin_include
include|#
directive|include
file|<sys/bitstring.h>
end_include

begin_include
include|#
directive|include
file|<geom/geom.h>
end_include

begin_include
include|#
directive|include
file|<geom/geom_vfs.h>
end_include

begin_include
include|#
directive|include
file|<gnu/fs/reiserfs/reiserfs_mount.h>
end_include

begin_include
include|#
directive|include
file|<gnu/fs/reiserfs/reiserfs_fs_sb.h>
end_include

begin_include
include|#
directive|include
file|<gnu/fs/reiserfs/reiserfs_fs_i.h>
end_include

begin_comment
comment|/* n must be power of 2 */
end_comment

begin_define
define|#
directive|define
name|_ROUND_UP
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|(((x) + (n) - 1u)& ~((n) - 1u))
end_define

begin_comment
comment|/* To be ok for alpha and others we have to align structures to 8 byte  * boundary. */
end_comment

begin_define
define|#
directive|define
name|ROUND_UP
parameter_list|(
name|x
parameter_list|)
value|_ROUND_UP(x, 8LL)
end_define

begin_comment
comment|/* -------------------------------------------------------------------  * Global variables  * -------------------------------------------------------------------*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vop_vector
name|reiserfs_vnodeops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vop_vector
name|reiserfs_specops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -------------------------------------------------------------------  * Super block  * -------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|REISERFS_BSIZE
value|1024
end_define

begin_comment
comment|/* ReiserFS leaves the first 64k unused, so that partition labels have  * enough space. If someone wants to write a fancy bootloader that needs  * more than 64k, let us know, and this will be increased in size.  * This number must be larger than than the largest block size on any  * platform, or code will break. -Hans */
end_comment

begin_define
define|#
directive|define
name|REISERFS_DISK_OFFSET
value|64
end_define

begin_define
define|#
directive|define
name|REISERFS_DISK_OFFSET_IN_BYTES
define|\
value|((REISERFS_DISK_OFFSET) * (REISERFS_BSIZE))
end_define

begin_comment
comment|/* The spot for the super in versions 3.5 - 3.5.10 (inclusive) */
end_comment

begin_define
define|#
directive|define
name|REISERFS_OLD_DISK_OFFSET
value|8
end_define

begin_define
define|#
directive|define
name|REISERFS_OLD_DISK_OFFSET_IN_BYTES
define|\
value|((REISERFS_OLD_DISK_OFFSET) * (REISERFS_BSIZE))
end_define

begin_comment
comment|/*  * Structure of a super block on disk, a version of which in RAM is  * often accessed as REISERFS_SB(s)->r_rs. The version in RAM is part of  * a larger structure containing fields never written to disk.  */
end_comment

begin_define
define|#
directive|define
name|UNSET_HASH
value|0
end_define

begin_comment
comment|/* read_super will guess about, what hash names 			     in directories were sorted with */
end_comment

begin_define
define|#
directive|define
name|TEA_HASH
value|1
end_define

begin_define
define|#
directive|define
name|YURA_HASH
value|2
end_define

begin_define
define|#
directive|define
name|R5_HASH
value|3
end_define

begin_define
define|#
directive|define
name|DEFAULT_HASH
value|R5_HASH
end_define

begin_struct
struct|struct
name|journal_params
block|{
name|uint32_t
name|jp_journal_1st_block
decl_stmt|;
comment|/* Where does journal start 						      from on its device */
name|uint32_t
name|jp_journal_dev
decl_stmt|;
comment|/* Journal device st_rdev */
name|uint32_t
name|jp_journal_size
decl_stmt|;
comment|/* Size of the journal */
name|uint32_t
name|jp_journal_trans_max
decl_stmt|;
comment|/* Max number of blocks in 						      a transaction */
name|uint32_t
name|jp_journal_magic
decl_stmt|;
comment|/* Random value made on 						      fs creation (this was 						      sb_journal_block_count) */
name|uint32_t
name|jp_journal_max_batch
decl_stmt|;
comment|/* Max number of blocks to 						      batch into a 						      transaction */
name|uint32_t
name|jp_journal_max_commit_age
decl_stmt|;
comment|/* In seconds, how old can 						      an async commit be */
name|uint32_t
name|jp_journal_max_trans_age
decl_stmt|;
comment|/* In seconds, how old a 						      transaction be */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|reiserfs_super_block_v1
block|{
name|uint32_t
name|s_block_count
decl_stmt|;
comment|/* Blocks count      */
name|uint32_t
name|s_free_blocks
decl_stmt|;
comment|/* Free blocks count */
name|uint32_t
name|s_root_block
decl_stmt|;
comment|/* Root block number */
name|struct
name|journal_params
name|s_journal
decl_stmt|;
name|uint16_t
name|s_blocksize
decl_stmt|;
name|uint16_t
name|s_oid_maxsize
decl_stmt|;
name|uint16_t
name|s_oid_cursize
decl_stmt|;
name|uint16_t
name|s_umount_state
decl_stmt|;
name|char
name|s_magic
index|[
literal|10
index|]
decl_stmt|;
name|uint16_t
name|s_fs_state
decl_stmt|;
name|uint32_t
name|s_hash_function_code
decl_stmt|;
name|uint16_t
name|s_tree_height
decl_stmt|;
name|uint16_t
name|s_bmap_nr
decl_stmt|;
name|uint16_t
name|s_version
decl_stmt|;
name|uint16_t
name|s_reserved_for_journal
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|SB_SIZE_V1
value|(sizeof(struct reiserfs_super_block_v1))
end_define

begin_struct
struct|struct
name|reiserfs_super_block
block|{
name|struct
name|reiserfs_super_block_v1
name|s_v1
decl_stmt|;
name|uint32_t
name|s_inode_generation
decl_stmt|;
name|uint32_t
name|s_flags
decl_stmt|;
name|unsigned
name|char
name|s_uuid
index|[
literal|16
index|]
decl_stmt|;
name|unsigned
name|char
name|s_label
index|[
literal|16
index|]
decl_stmt|;
name|char
name|s_unused
index|[
literal|88
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|SB_SIZE
value|(sizeof(struct reiserfs_super_block))
end_define

begin_define
define|#
directive|define
name|REISERFS_VERSION_1
value|0
end_define

begin_define
define|#
directive|define
name|REISERFS_VERSION_2
value|2
end_define

begin_define
define|#
directive|define
name|REISERFS_SB
parameter_list|(
name|sbi
parameter_list|)
value|(sbi)
end_define

begin_define
define|#
directive|define
name|SB_DISK_SUPER_BLOCK
parameter_list|(
name|sbi
parameter_list|)
value|(REISERFS_SB(sbi)->s_rs)
end_define

begin_define
define|#
directive|define
name|SB_V1_DISK_SUPER_BLOCK
parameter_list|(
name|sbi
parameter_list|)
value|(&(SB_DISK_SUPER_BLOCK(sbi)->s_v1))
end_define

begin_define
define|#
directive|define
name|SB_BLOCKSIZE
parameter_list|(
name|sbi
parameter_list|)
define|\
value|le32toh((SB_V1_DISK_SUPER_BLOCK(sbi)->s_blocksize))
end_define

begin_define
define|#
directive|define
name|SB_BLOCK_COUNT
parameter_list|(
name|sbi
parameter_list|)
define|\
value|le32toh((SB_V1_DISK_SUPER_BLOCK(sbi)->s_block_count))
end_define

begin_define
define|#
directive|define
name|SB_FREE_BLOCKS
parameter_list|(
name|s
parameter_list|)
define|\
value|le32toh((SB_V1_DISK_SUPER_BLOCK(sbi)->s_free_blocks))
end_define

begin_define
define|#
directive|define
name|SB_REISERFS_MAGIC
parameter_list|(
name|sbi
parameter_list|)
define|\
value|(SB_V1_DISK_SUPER_BLOCK(sbi)->s_magic)
end_define

begin_define
define|#
directive|define
name|SB_ROOT_BLOCK
parameter_list|(
name|sbi
parameter_list|)
define|\
value|le32toh((SB_V1_DISK_SUPER_BLOCK(sbi)->s_root_block))
end_define

begin_define
define|#
directive|define
name|SB_TREE_HEIGHT
parameter_list|(
name|sbi
parameter_list|)
define|\
value|le16toh((SB_V1_DISK_SUPER_BLOCK(sbi)->s_tree_height))
end_define

begin_define
define|#
directive|define
name|SB_REISERFS_STATE
parameter_list|(
name|sbi
parameter_list|)
define|\
value|le16toh((SB_V1_DISK_SUPER_BLOCK(sbi)->s_umount_state))
end_define

begin_define
define|#
directive|define
name|SB_VERSION
parameter_list|(
name|sbi
parameter_list|)
value|le16toh((SB_V1_DISK_SUPER_BLOCK(sbi)->s_version))
end_define

begin_define
define|#
directive|define
name|SB_BMAP_NR
parameter_list|(
name|sbi
parameter_list|)
value|le16toh((SB_V1_DISK_SUPER_BLOCK(sbi)->s_bmap_nr))
end_define

begin_define
define|#
directive|define
name|REISERFS_SUPER_MAGIC_STRING
value|"ReIsErFs"
end_define

begin_define
define|#
directive|define
name|REISER2FS_SUPER_MAGIC_STRING
value|"ReIsEr2Fs"
end_define

begin_define
define|#
directive|define
name|REISER2FS_JR_SUPER_MAGIC_STRING
value|"ReIsEr3Fs"
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|reiserfs_3_5_magic_string
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|reiserfs_3_6_magic_string
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|reiserfs_jr_magic_string
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|is_reiserfs_3_5
parameter_list|(
name|struct
name|reiserfs_super_block
modifier|*
name|rs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_reiserfs_3_6
parameter_list|(
name|struct
name|reiserfs_super_block
modifier|*
name|rs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_reiserfs_jr
parameter_list|(
name|struct
name|reiserfs_super_block
modifier|*
name|rs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ReiserFS internal error code (used by search_by_key and fix_nodes) */
end_comment

begin_define
define|#
directive|define
name|IO_ERROR
value|-2
end_define

begin_typedef
typedef|typedef
name|uint32_t
name|b_blocknr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|unp_t
typedef|;
end_typedef

begin_struct
struct|struct
name|unfm_nodeinfo
block|{
name|unp_t
name|unfm_nodenum
decl_stmt|;
name|unsigned
name|short
name|unfm_freespace
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* There are two formats of keys: 3.5 and 3.6 */
end_comment

begin_define
define|#
directive|define
name|KEY_FORMAT_3_5
value|0
end_define

begin_define
define|#
directive|define
name|KEY_FORMAT_3_6
value|1
end_define

begin_comment
comment|/* There are two stat datas */
end_comment

begin_define
define|#
directive|define
name|STAT_DATA_V1
value|0
end_define

begin_define
define|#
directive|define
name|STAT_DATA_V2
value|1
end_define

begin_define
define|#
directive|define
name|REISERFS_I
parameter_list|(
name|ip
parameter_list|)
value|(ip)
end_define

begin_define
define|#
directive|define
name|get_inode_item_key_version
parameter_list|(
name|ip
parameter_list|)
define|\
value|((REISERFS_I(ip)->i_flags& i_item_key_version_mask) ?		\      KEY_FORMAT_3_6 : KEY_FORMAT_3_5)
end_define

begin_define
define|#
directive|define
name|set_inode_item_key_version
parameter_list|(
name|ip
parameter_list|,
name|version
parameter_list|)
value|({			\ 	if ((version) == KEY_FORMAT_3_6)				\     		REISERFS_I(ip)->i_flags |= i_item_key_version_mask;	\     	else								\     		REISERFS_I(ip)->i_flags&= ~i_item_key_version_mask;	\ })
end_define

begin_define
define|#
directive|define
name|get_inode_sd_version
parameter_list|(
name|ip
parameter_list|)
define|\
value|((REISERFS_I(ip)->i_flags& i_stat_data_version_mask) ?		\      STAT_DATA_V2 : STAT_DATA_V1)
end_define

begin_define
define|#
directive|define
name|set_inode_sd_version
parameter_list|(
name|inode
parameter_list|,
name|version
parameter_list|)
value|({				\ 	if((version) == STAT_DATA_V2)					\ 		REISERFS_I(ip)->i_flags |= i_stat_data_version_mask;	\ 	else								\ 		REISERFS_I(ip)->i_flags&= ~i_stat_data_version_mask;	\ })
end_define

begin_comment
comment|/* Values for s_umount_state field */
end_comment

begin_define
define|#
directive|define
name|REISERFS_VALID_FS
value|1
end_define

begin_define
define|#
directive|define
name|REISERFS_ERROR_FS
value|2
end_define

begin_comment
comment|/* There are 5 item types currently */
end_comment

begin_define
define|#
directive|define
name|TYPE_STAT_DATA
value|0
end_define

begin_define
define|#
directive|define
name|TYPE_INDIRECT
value|1
end_define

begin_define
define|#
directive|define
name|TYPE_DIRECT
value|2
end_define

begin_define
define|#
directive|define
name|TYPE_DIRENTRY
value|3
end_define

begin_define
define|#
directive|define
name|TYPE_MAXTYPE
value|3
end_define

begin_define
define|#
directive|define
name|TYPE_ANY
value|15
end_define

begin_comment
comment|/* -------------------------------------------------------------------  * Key& item head  * -------------------------------------------------------------------*/
end_comment

begin_struct
struct|struct
name|offset_v1
block|{
name|uint32_t
name|k_offset
decl_stmt|;
name|uint32_t
name|k_uniqueness
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|offset_v2
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
comment|/* little endian version */
name|uint64_t
name|k_offset
range|:
literal|60
decl_stmt|;
name|uint64_t
name|k_type
range|:
literal|4
decl_stmt|;
else|#
directive|else
comment|/* big endian version */
name|uint64_t
name|k_type
range|:
literal|4
decl_stmt|;
name|uint64_t
name|k_offset
range|:
literal|60
decl_stmt|;
endif|#
directive|endif
block|}
name|__packed
struct|;
end_struct

begin_if
if|#
directive|if
operator|(
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
operator|)
end_if

begin_typedef
typedef|typedef
union|union
block|{
name|struct
name|offset_v2
name|offset_v2
decl_stmt|;
name|uint64_t
name|linear
decl_stmt|;
block|}
name|__packed
name|offset_v2_esafe_overlay
typedef|;
end_typedef

begin_function
specifier|static
specifier|inline
name|uint16_t
name|offset_v2_k_type
parameter_list|(
specifier|const
name|struct
name|offset_v2
modifier|*
name|v2
parameter_list|)
block|{
name|offset_v2_esafe_overlay
name|tmp
init|=
operator|*
operator|(
specifier|const
name|offset_v2_esafe_overlay
operator|*
operator|)
name|v2
decl_stmt|;
name|tmp
operator|.
name|linear
operator|=
name|le64toh
argument_list|(
name|tmp
operator|.
name|linear
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|tmp
operator|.
name|offset_v2
operator|.
name|k_type
operator|<=
name|TYPE_MAXTYPE
operator|)
condition|?
name|tmp
operator|.
name|offset_v2
operator|.
name|k_type
else|:
name|TYPE_ANY
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|set_offset_v2_k_type
parameter_list|(
name|struct
name|offset_v2
modifier|*
name|v2
parameter_list|,
name|int
name|type
parameter_list|)
block|{
name|offset_v2_esafe_overlay
modifier|*
name|tmp
init|=
operator|(
name|offset_v2_esafe_overlay
operator|*
operator|)
name|v2
decl_stmt|;
name|tmp
operator|->
name|linear
operator|=
name|le64toh
argument_list|(
name|tmp
operator|->
name|linear
argument_list|)
expr_stmt|;
name|tmp
operator|->
name|offset_v2
operator|.
name|k_type
operator|=
name|type
expr_stmt|;
name|tmp
operator|->
name|linear
operator|=
name|htole64
argument_list|(
name|tmp
operator|->
name|linear
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|off_t
name|offset_v2_k_offset
parameter_list|(
specifier|const
name|struct
name|offset_v2
modifier|*
name|v2
parameter_list|)
block|{
name|offset_v2_esafe_overlay
name|tmp
init|=
operator|*
operator|(
specifier|const
name|offset_v2_esafe_overlay
operator|*
operator|)
name|v2
decl_stmt|;
name|tmp
operator|.
name|linear
operator|=
name|le64toh
argument_list|(
name|tmp
operator|.
name|linear
argument_list|)
expr_stmt|;
return|return
operator|(
name|tmp
operator|.
name|offset_v2
operator|.
name|k_offset
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|set_offset_v2_k_offset
parameter_list|(
name|struct
name|offset_v2
modifier|*
name|v2
parameter_list|,
name|off_t
name|offset
parameter_list|)
block|{
name|offset_v2_esafe_overlay
modifier|*
name|tmp
init|=
operator|(
name|offset_v2_esafe_overlay
operator|*
operator|)
name|v2
decl_stmt|;
name|tmp
operator|->
name|linear
operator|=
name|le64toh
argument_list|(
name|tmp
operator|->
name|linear
argument_list|)
expr_stmt|;
name|tmp
operator|->
name|offset_v2
operator|.
name|k_offset
operator|=
name|offset
expr_stmt|;
name|tmp
operator|->
name|linear
operator|=
name|htole64
argument_list|(
name|tmp
operator|->
name|linear
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BYTE_ORDER != BIG_ENDIAN */
end_comment

begin_define
define|#
directive|define
name|offset_v2_k_type
parameter_list|(
name|v2
parameter_list|)
value|((v2)->k_type)
end_define

begin_define
define|#
directive|define
name|set_offset_v2_k_type
parameter_list|(
name|v2
parameter_list|,
name|val
parameter_list|)
value|(offset_v2_k_type(v2) = (val))
end_define

begin_define
define|#
directive|define
name|offset_v2_k_offset
parameter_list|(
name|v2
parameter_list|)
value|((v2)->k_offset)
end_define

begin_define
define|#
directive|define
name|set_offset_v2_k_offset
parameter_list|(
name|v2
parameter_list|,
name|val
parameter_list|)
value|(offset_v2_k_offset(v2) = (val))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BYTE_ORDER == BIG_ENDIAN */
end_comment

begin_comment
comment|/*  * Key of an item determines its location in the S+tree, and  * is composed of 4 components  */
end_comment

begin_struct
struct|struct
name|key
block|{
name|uint32_t
name|k_dir_id
decl_stmt|;
comment|/* Packing locality: by default parent 					directory object id */
name|uint32_t
name|k_objectid
decl_stmt|;
comment|/* Object identifier */
union|union
block|{
name|struct
name|offset_v1
name|k_offset_v1
decl_stmt|;
name|struct
name|offset_v2
name|k_offset_v2
decl_stmt|;
block|}
name|__packed
name|u
union|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|cpu_key
block|{
name|struct
name|key
name|on_disk_key
decl_stmt|;
name|int
name|version
decl_stmt|;
name|int
name|key_length
decl_stmt|;
comment|/* 3 in all cases but direct2indirect 				       and indirect2direct conversion */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Our function for comparing keys can compare keys of different  * lengths. It takes as a parameter the length of the keys it is to  * compare. These defines are used in determining what is to be passed  * to it as that parameter.  */
end_comment

begin_define
define|#
directive|define
name|REISERFS_FULL_KEY_LEN
value|4
end_define

begin_define
define|#
directive|define
name|REISERFS_SHORT_KEY_LEN
value|2
end_define

begin_define
define|#
directive|define
name|KEY_SIZE
value|(sizeof(struct key))
end_define

begin_define
define|#
directive|define
name|SHORT_KEY_SIZE
value|(sizeof(uint32_t) + sizeof(uint32_t))
end_define

begin_comment
comment|/* Return values for search_by_key and clones */
end_comment

begin_define
define|#
directive|define
name|ITEM_FOUND
value|1
end_define

begin_define
define|#
directive|define
name|ITEM_NOT_FOUND
value|0
end_define

begin_define
define|#
directive|define
name|ENTRY_FOUND
value|1
end_define

begin_define
define|#
directive|define
name|ENTRY_NOT_FOUND
value|0
end_define

begin_define
define|#
directive|define
name|DIRECTORY_NOT_FOUND
value|-1
end_define

begin_define
define|#
directive|define
name|REGULAR_FILE_FOUND
value|-2
end_define

begin_define
define|#
directive|define
name|DIRECTORY_FOUND
value|-3
end_define

begin_define
define|#
directive|define
name|BYTE_FOUND
value|1
end_define

begin_define
define|#
directive|define
name|BYTE_NOT_FOUND
value|0
end_define

begin_define
define|#
directive|define
name|FILE_NOT_FOUND
value|-1
end_define

begin_define
define|#
directive|define
name|POSITION_FOUND
value|1
end_define

begin_define
define|#
directive|define
name|POSITION_NOT_FOUND
value|0
end_define

begin_comment
comment|/* Return values for reiserfs_find_entry and search_by_entry_key */
end_comment

begin_define
define|#
directive|define
name|NAME_FOUND
value|1
end_define

begin_define
define|#
directive|define
name|NAME_NOT_FOUND
value|0
end_define

begin_define
define|#
directive|define
name|GOTO_PREVIOUS_ITEM
value|2
end_define

begin_define
define|#
directive|define
name|NAME_FOUND_INVISIBLE
value|3
end_define

begin_comment
comment|/*  * Everything in the filesystem is stored as a set of items. The item  * head contains the key of the item, its free space (for indirect  * items) and specifies the location of the item itself within the  * block.  */
end_comment

begin_struct
struct|struct
name|item_head
block|{
comment|/* 	 * Everything in the tree is found by searching for it based on 	 * its key. 	 */
name|struct
name|key
name|ih_key
decl_stmt|;
union|union
block|{
comment|/* 		 * The free space in the last unformatted node of an 		 * indirect item if this is an indirect item. This 		 * equals 0xFFFF iff this is a direct item or stat data 		 * item. Note that the key, not this field, is used to 		 * determine the item type, and thus which field this 		 * union contains. 		 */
name|uint16_t
name|ih_free_space_reserved
decl_stmt|;
comment|/* 		 * If this is a directory item, this field equals the number of 		 * directory entries in the directory item. 		 */
name|uint16_t
name|ih_entry_count
decl_stmt|;
block|}
name|__packed
name|u
union|;
name|uint16_t
name|ih_item_len
decl_stmt|;
comment|/* Total size of the item body */
name|uint16_t
name|ih_item_location
decl_stmt|;
comment|/* An offset to the item body within 					     the block */
name|uint16_t
name|ih_version
decl_stmt|;
comment|/* 0 for all old items, 2 for new 					     ones. Highest bit is set by fsck 					     temporary, cleaned after all 					     done */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Size of item header */
end_comment

begin_define
define|#
directive|define
name|IH_SIZE
value|(sizeof(struct item_head))
end_define

begin_define
define|#
directive|define
name|ih_free_space
parameter_list|(
name|ih
parameter_list|)
value|le16toh((ih)->u.ih_free_space_reserved)
end_define

begin_define
define|#
directive|define
name|ih_version
parameter_list|(
name|ih
parameter_list|)
value|le16toh((ih)->ih_version)
end_define

begin_define
define|#
directive|define
name|ih_entry_count
parameter_list|(
name|ih
parameter_list|)
value|le16toh((ih)->u.ih_entry_count)
end_define

begin_define
define|#
directive|define
name|ih_location
parameter_list|(
name|ih
parameter_list|)
value|le16toh((ih)->ih_item_location)
end_define

begin_define
define|#
directive|define
name|ih_item_len
parameter_list|(
name|ih
parameter_list|)
value|le16toh((ih)->ih_item_len)
end_define

begin_comment
comment|/*  * These operate on indirect items, where you've got an array of ints at  * a possibly unaligned location. These are a noop on IA32.  *   * p is the array of uint32_t, i is the index into the array, v is the  * value to store there.  */
end_comment

begin_define
define|#
directive|define
name|get_unaligned
parameter_list|(
name|ptr
parameter_list|)
define|\
value|({ __typeof__(*(ptr)) __tmp;					\      memcpy(&__tmp, (ptr), sizeof(*(ptr))); __tmp; })
end_define

begin_define
define|#
directive|define
name|put_unaligned
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
define|\
value|({ __typeof__(*(ptr)) __tmp = (val);				\      memcpy((ptr),&__tmp, sizeof(*(ptr)));				\      (void)0; })
end_define

begin_define
define|#
directive|define
name|get_block_num
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|le32toh(get_unaligned((p) + (i)))
end_define

begin_define
define|#
directive|define
name|put_block_num
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|,
name|v
parameter_list|)
value|put_unaligned(htole32(v), (p) + (i))
end_define

begin_comment
comment|/* In old version uniqueness field shows key type */
end_comment

begin_define
define|#
directive|define
name|V1_SD_UNIQUENESS
value|0
end_define

begin_define
define|#
directive|define
name|V1_INDIRECT_UNIQUENESS
value|0xfffffffe
end_define

begin_define
define|#
directive|define
name|V1_DIRECT_UNIQUENESS
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|V1_DIRENTRY_UNIQUENESS
value|500
end_define

begin_define
define|#
directive|define
name|V1_ANY_UNIQUENESS
value|555
end_define

begin_comment
comment|/* Here are conversion routines */
end_comment

begin_function_decl
specifier|static
specifier|inline
name|int
name|uniqueness2type
parameter_list|(
name|uint32_t
name|uniqueness
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|uint32_t
name|type2uniqueness
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|uniqueness2type
parameter_list|(
name|uint32_t
name|uniqueness
parameter_list|)
block|{
switch|switch
condition|(
operator|(
name|int
operator|)
name|uniqueness
condition|)
block|{
case|case
name|V1_SD_UNIQUENESS
case|:
return|return
operator|(
name|TYPE_STAT_DATA
operator|)
return|;
case|case
name|V1_INDIRECT_UNIQUENESS
case|:
return|return
operator|(
name|TYPE_INDIRECT
operator|)
return|;
case|case
name|V1_DIRECT_UNIQUENESS
case|:
return|return
operator|(
name|TYPE_DIRECT
operator|)
return|;
case|case
name|V1_DIRENTRY_UNIQUENESS
case|:
return|return
operator|(
name|TYPE_DIRENTRY
operator|)
return|;
default|default:
name|log
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"reiserfs: unknown uniqueness (%u)\n"
argument_list|,
name|uniqueness
argument_list|)
expr_stmt|;
case|case
name|V1_ANY_UNIQUENESS
case|:
return|return
operator|(
name|TYPE_ANY
operator|)
return|;
block|}
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|type2uniqueness
parameter_list|(
name|int
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|TYPE_STAT_DATA
case|:
return|return
operator|(
name|V1_SD_UNIQUENESS
operator|)
return|;
case|case
name|TYPE_INDIRECT
case|:
return|return
operator|(
name|V1_INDIRECT_UNIQUENESS
operator|)
return|;
case|case
name|TYPE_DIRECT
case|:
return|return
operator|(
name|V1_DIRECT_UNIQUENESS
operator|)
return|;
case|case
name|TYPE_DIRENTRY
case|:
return|return
operator|(
name|V1_DIRENTRY_UNIQUENESS
operator|)
return|;
default|default:
name|log
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"reiserfs: unknown type (%u)\n"
argument_list|,
name|type
argument_list|)
expr_stmt|;
case|case
name|TYPE_ANY
case|:
return|return
operator|(
name|V1_ANY_UNIQUENESS
operator|)
return|;
block|}
block|}
end_function

begin_comment
comment|/*  * Key is pointer to on disk key which is stored in le, result is cpu,  * there is no way to get version of object from key, so, provide  * version to these defines.  */
end_comment

begin_function
specifier|static
specifier|inline
name|off_t
name|le_key_k_offset
parameter_list|(
name|int
name|version
parameter_list|,
specifier|const
name|struct
name|key
modifier|*
name|key
parameter_list|)
block|{
return|return
operator|(
operator|(
name|version
operator|==
name|KEY_FORMAT_3_5
operator|)
condition|?
name|le32toh
argument_list|(
name|key
operator|->
name|u
operator|.
name|k_offset_v1
operator|.
name|k_offset
argument_list|)
else|:
name|offset_v2_k_offset
argument_list|(
operator|&
operator|(
name|key
operator|->
name|u
operator|.
name|k_offset_v2
operator|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|off_t
name|le_ih_k_offset
parameter_list|(
specifier|const
name|struct
name|item_head
modifier|*
name|ih
parameter_list|)
block|{
return|return
operator|(
name|le_key_k_offset
argument_list|(
name|ih_version
argument_list|(
name|ih
argument_list|)
argument_list|,
operator|&
operator|(
name|ih
operator|->
name|ih_key
operator|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|off_t
name|le_key_k_type
parameter_list|(
name|int
name|version
parameter_list|,
specifier|const
name|struct
name|key
modifier|*
name|key
parameter_list|)
block|{
return|return
operator|(
operator|(
name|version
operator|==
name|KEY_FORMAT_3_5
operator|)
condition|?
name|uniqueness2type
argument_list|(
name|le32toh
argument_list|(
name|key
operator|->
name|u
operator|.
name|k_offset_v1
operator|.
name|k_uniqueness
argument_list|)
argument_list|)
else|:
name|offset_v2_k_type
argument_list|(
operator|&
operator|(
name|key
operator|->
name|u
operator|.
name|k_offset_v2
operator|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|off_t
name|le_ih_k_type
parameter_list|(
specifier|const
name|struct
name|item_head
modifier|*
name|ih
parameter_list|)
block|{
return|return
operator|(
name|le_key_k_type
argument_list|(
name|ih_version
argument_list|(
name|ih
argument_list|)
argument_list|,
operator|&
operator|(
name|ih
operator|->
name|ih_key
operator|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|set_le_key_k_offset
parameter_list|(
name|int
name|version
parameter_list|,
name|struct
name|key
modifier|*
name|key
parameter_list|,
name|off_t
name|offset
parameter_list|)
block|{
operator|(
name|version
operator|==
name|KEY_FORMAT_3_5
operator|)
condition|?
operator|(
name|key
operator|->
name|u
operator|.
name|k_offset_v1
operator|.
name|k_offset
operator|=
name|htole32
argument_list|(
name|offset
argument_list|)
operator|)
else|:
operator|(
name|set_offset_v2_k_offset
argument_list|(
operator|&
operator|(
name|key
operator|->
name|u
operator|.
name|k_offset_v2
operator|)
argument_list|,
name|offset
argument_list|)
operator|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|set_le_ih_k_offset
parameter_list|(
name|struct
name|item_head
modifier|*
name|ih
parameter_list|,
name|off_t
name|offset
parameter_list|)
block|{
name|set_le_key_k_offset
argument_list|(
name|ih_version
argument_list|(
name|ih
argument_list|)
argument_list|,
operator|&
operator|(
name|ih
operator|->
name|ih_key
operator|)
argument_list|,
name|offset
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|set_le_key_k_type
parameter_list|(
name|int
name|version
parameter_list|,
name|struct
name|key
modifier|*
name|key
parameter_list|,
name|int
name|type
parameter_list|)
block|{
operator|(
name|version
operator|==
name|KEY_FORMAT_3_5
operator|)
condition|?
operator|(
name|key
operator|->
name|u
operator|.
name|k_offset_v1
operator|.
name|k_uniqueness
operator|=
name|htole32
argument_list|(
name|type2uniqueness
argument_list|(
name|type
argument_list|)
argument_list|)
operator|)
else|:
operator|(
name|set_offset_v2_k_type
argument_list|(
operator|&
operator|(
name|key
operator|->
name|u
operator|.
name|k_offset_v2
operator|)
argument_list|,
name|type
argument_list|)
operator|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|set_le_ih_k_type
parameter_list|(
name|struct
name|item_head
modifier|*
name|ih
parameter_list|,
name|int
name|type
parameter_list|)
block|{
name|set_le_key_k_type
argument_list|(
name|ih_version
argument_list|(
name|ih
argument_list|)
argument_list|,
operator|&
operator|(
name|ih
operator|->
name|ih_key
operator|)
argument_list|,
name|type
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|is_direntry_le_key
parameter_list|(
name|version
parameter_list|,
name|key
parameter_list|)
define|\
value|(le_key_k_type(version, key) == TYPE_DIRENTRY)
end_define

begin_define
define|#
directive|define
name|is_direct_le_key
parameter_list|(
name|version
parameter_list|,
name|key
parameter_list|)
define|\
value|(le_key_k_type(version, key) == TYPE_DIRECT)
end_define

begin_define
define|#
directive|define
name|is_indirect_le_key
parameter_list|(
name|version
parameter_list|,
name|key
parameter_list|)
define|\
value|(le_key_k_type(version, key) == TYPE_INDIRECT)
end_define

begin_define
define|#
directive|define
name|is_statdata_le_key
parameter_list|(
name|version
parameter_list|,
name|key
parameter_list|)
define|\
value|(le_key_k_type(version, key) == TYPE_STAT_DATA)
end_define

begin_comment
comment|/* Item header has version. */
end_comment

begin_define
define|#
directive|define
name|is_direntry_le_ih
parameter_list|(
name|ih
parameter_list|)
define|\
value|is_direntry_le_key(ih_version(ih),&((ih)->ih_key))
end_define

begin_define
define|#
directive|define
name|is_direct_le_ih
parameter_list|(
name|ih
parameter_list|)
define|\
value|is_direct_le_key(ih_version(ih),&((ih)->ih_key))
end_define

begin_define
define|#
directive|define
name|is_indirect_le_ih
parameter_list|(
name|ih
parameter_list|)
define|\
value|is_indirect_le_key(ih_version(ih),&((ih)->ih_key))
end_define

begin_define
define|#
directive|define
name|is_statdata_le_ih
parameter_list|(
name|ih
parameter_list|)
define|\
value|is_statdata_le_key(ih_version(ih),&((ih)->ih_key))
end_define

begin_function
specifier|static
specifier|inline
name|void
name|set_cpu_key_k_offset
parameter_list|(
name|struct
name|cpu_key
modifier|*
name|key
parameter_list|,
name|off_t
name|offset
parameter_list|)
block|{
operator|(
name|key
operator|->
name|version
operator|==
name|KEY_FORMAT_3_5
operator|)
condition|?
operator|(
name|key
operator|->
name|on_disk_key
operator|.
name|u
operator|.
name|k_offset_v1
operator|.
name|k_offset
operator|=
name|offset
operator|)
else|:
operator|(
name|key
operator|->
name|on_disk_key
operator|.
name|u
operator|.
name|k_offset_v2
operator|.
name|k_offset
operator|=
name|offset
operator|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|set_cpu_key_k_type
parameter_list|(
name|struct
name|cpu_key
modifier|*
name|key
parameter_list|,
name|int
name|type
parameter_list|)
block|{
operator|(
name|key
operator|->
name|version
operator|==
name|KEY_FORMAT_3_5
operator|)
condition|?
operator|(
name|key
operator|->
name|on_disk_key
operator|.
name|u
operator|.
name|k_offset_v1
operator|.
name|k_uniqueness
operator|=
name|type2uniqueness
argument_list|(
name|type
argument_list|)
operator|)
else|:
operator|(
name|key
operator|->
name|on_disk_key
operator|.
name|u
operator|.
name|k_offset_v2
operator|.
name|k_type
operator|=
name|type
operator|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|is_direntry_cpu_key
parameter_list|(
name|key
parameter_list|)
value|(cpu_key_k_type (key) == TYPE_DIRENTRY)
end_define

begin_define
define|#
directive|define
name|is_direct_cpu_key
parameter_list|(
name|key
parameter_list|)
value|(cpu_key_k_type (key) == TYPE_DIRECT)
end_define

begin_define
define|#
directive|define
name|is_indirect_cpu_key
parameter_list|(
name|key
parameter_list|)
value|(cpu_key_k_type (key) == TYPE_INDIRECT)
end_define

begin_define
define|#
directive|define
name|is_statdata_cpu_key
parameter_list|(
name|key
parameter_list|)
value|(cpu_key_k_type (key) == TYPE_STAT_DATA)
end_define

begin_comment
comment|/* Maximal length of item */
end_comment

begin_define
define|#
directive|define
name|MAX_ITEM_LEN
parameter_list|(
name|block_size
parameter_list|)
value|(block_size - BLKH_SIZE - IH_SIZE)
end_define

begin_define
define|#
directive|define
name|MIN_ITEM_LEN
value|1
end_define

begin_comment
comment|/* Object identifier for root dir */
end_comment

begin_define
define|#
directive|define
name|REISERFS_ROOT_OBJECTID
value|2
end_define

begin_define
define|#
directive|define
name|REISERFS_ROOT_PARENT_OBJECTID
value|1
end_define

begin_comment
comment|/* key is pointer to cpu key, result is cpu */
end_comment

begin_function
specifier|static
specifier|inline
name|off_t
name|cpu_key_k_offset
parameter_list|(
specifier|const
name|struct
name|cpu_key
modifier|*
name|key
parameter_list|)
block|{
return|return
operator|(
operator|(
name|key
operator|->
name|version
operator|==
name|KEY_FORMAT_3_5
operator|)
condition|?
name|key
operator|->
name|on_disk_key
operator|.
name|u
operator|.
name|k_offset_v1
operator|.
name|k_offset
else|:
name|key
operator|->
name|on_disk_key
operator|.
name|u
operator|.
name|k_offset_v2
operator|.
name|k_offset
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|off_t
name|cpu_key_k_type
parameter_list|(
specifier|const
name|struct
name|cpu_key
modifier|*
name|key
parameter_list|)
block|{
return|return
operator|(
operator|(
name|key
operator|->
name|version
operator|==
name|KEY_FORMAT_3_5
operator|)
condition|?
name|uniqueness2type
argument_list|(
name|key
operator|->
name|on_disk_key
operator|.
name|u
operator|.
name|k_offset_v1
operator|.
name|k_uniqueness
argument_list|)
else|:
name|key
operator|->
name|on_disk_key
operator|.
name|u
operator|.
name|k_offset_v2
operator|.
name|k_type
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Header of a disk block.  More precisely, header of a formatted leaf  * or internal node, and not the header of an unformatted node.  */
end_comment

begin_struct
struct|struct
name|block_head
block|{
name|uint16_t
name|blk_level
decl_stmt|;
comment|/* Level of a block in the 						 tree. */
name|uint16_t
name|blk_nr_item
decl_stmt|;
comment|/* Number of keys/items in a 						 block. */
name|uint16_t
name|blk_free_space
decl_stmt|;
comment|/* Block free space in bytes. */
name|uint16_t
name|blk_reserved
decl_stmt|;
comment|/* Dump this in v4/planA */
name|struct
name|key
name|blk_right_delim_key
decl_stmt|;
comment|/* Kept only for compatibility */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BLKH_SIZE
value|(sizeof(struct block_head))
end_define

begin_define
define|#
directive|define
name|blkh_level
parameter_list|(
name|p_blkh
parameter_list|)
value|(le16toh((p_blkh)->blk_level))
end_define

begin_define
define|#
directive|define
name|blkh_nr_item
parameter_list|(
name|p_blkh
parameter_list|)
value|(le16toh((p_blkh)->blk_nr_item))
end_define

begin_define
define|#
directive|define
name|blkh_free_space
parameter_list|(
name|p_blkh
parameter_list|)
value|(le16toh((p_blkh)->blk_free_space))
end_define

begin_define
define|#
directive|define
name|FREE_LEVEL
value|0
end_define

begin_comment
comment|/* When node gets removed from the tree its 			     blk_level is set to FREE_LEVEL. It is then 			     used to see whether the node is still in the 			     tree */
end_comment

begin_comment
comment|/* Values for blk_level field of the struct block_head */
end_comment

begin_define
define|#
directive|define
name|DISK_LEAF_NODE_LEVEL
value|1
end_define

begin_comment
comment|/* Leaf node level.*/
end_comment

begin_comment
comment|/*  * Given the buffer head of a formatted node, resolve to the block head  * of that node.  */
end_comment

begin_define
define|#
directive|define
name|B_BLK_HEAD
parameter_list|(
name|p_s_bp
parameter_list|)
value|((struct block_head *)((p_s_bp)->b_data))
end_define

begin_define
define|#
directive|define
name|B_NR_ITEMS
parameter_list|(
name|p_s_bp
parameter_list|)
value|(blkh_nr_item(B_BLK_HEAD(p_s_bp)))
end_define

begin_define
define|#
directive|define
name|B_LEVEL
parameter_list|(
name|p_s_bp
parameter_list|)
value|(blkh_level(B_BLK_HEAD(p_s_bp)))
end_define

begin_define
define|#
directive|define
name|B_FREE_SPACE
parameter_list|(
name|p_s_bp
parameter_list|)
value|(blkh_free_space(B_BLK_HEAD(p_s_bp)))
end_define

begin_comment
comment|/* -------------------------------------------------------------------  * Stat data  * -------------------------------------------------------------------*/
end_comment

begin_comment
comment|/*  * Old stat data is 32 bytes long. We are going to distinguish new one  * by different size.  */
end_comment

begin_struct
struct|struct
name|stat_data_v1
block|{
name|uint16_t
name|sd_mode
decl_stmt|;
comment|/* File type, permissions */
name|uint16_t
name|sd_nlink
decl_stmt|;
comment|/* Number of hard links */
name|uint16_t
name|sd_uid
decl_stmt|;
comment|/* Owner */
name|uint16_t
name|sd_gid
decl_stmt|;
comment|/* Group */
name|uint32_t
name|sd_size
decl_stmt|;
comment|/* File size */
name|uint32_t
name|sd_atime
decl_stmt|;
comment|/* Time of last access */
name|uint32_t
name|sd_mtime
decl_stmt|;
comment|/* Time file was last modified  */
name|uint32_t
name|sd_ctime
decl_stmt|;
comment|/* Time inode (stat data) was last changed 				     (except changes to sd_atime and 				     sd_mtime) */
union|union
block|{
name|uint32_t
name|sd_rdev
decl_stmt|;
name|uint32_t
name|sd_blocks
decl_stmt|;
comment|/* Number of blocks file uses */
block|}
name|__packed
name|u
union|;
name|uint32_t
name|sd_first_direct_byte
decl_stmt|;
comment|/* First byte of file which is 						 stored in a direct item: 						 except that if it equals 1 						 it is a symlink and if it 						 equals ~(uint32_t)0 there 						 is no direct item. The 						 existence of this field 						 really grates on me. Let's 						 replace it with a macro based 						 on sd_size and our tail 						 suppression policy. Someday. 						 -Hans */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|SD_V1_SIZE
value|(sizeof(struct stat_data_v1))
end_define

begin_define
define|#
directive|define
name|stat_data_v1
parameter_list|(
name|ih
parameter_list|)
value|(ih_version (ih) == KEY_FORMAT_3_5)
end_define

begin_define
define|#
directive|define
name|sd_v1_mode
parameter_list|(
name|sdp
parameter_list|)
value|(le16toh((sdp)->sd_mode))
end_define

begin_define
define|#
directive|define
name|set_sd_v1_mode
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_mode = htole16(v))
end_define

begin_define
define|#
directive|define
name|sd_v1_nlink
parameter_list|(
name|sdp
parameter_list|)
value|(le16toh((sdp)->sd_nlink))
end_define

begin_define
define|#
directive|define
name|set_sd_v1_nlink
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_nlink = htole16(v))
end_define

begin_define
define|#
directive|define
name|sd_v1_uid
parameter_list|(
name|sdp
parameter_list|)
value|(le16toh((sdp)->sd_uid))
end_define

begin_define
define|#
directive|define
name|set_sd_v1_uid
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_uid = htole16(v))
end_define

begin_define
define|#
directive|define
name|sd_v1_gid
parameter_list|(
name|sdp
parameter_list|)
value|(le16toh((sdp)->sd_gid))
end_define

begin_define
define|#
directive|define
name|set_sd_v1_gid
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_gid = htole16(v))
end_define

begin_define
define|#
directive|define
name|sd_v1_size
parameter_list|(
name|sdp
parameter_list|)
value|(le32toh((sdp)->sd_size))
end_define

begin_define
define|#
directive|define
name|set_sd_v1_size
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_size = htole32(v))
end_define

begin_define
define|#
directive|define
name|sd_v1_atime
parameter_list|(
name|sdp
parameter_list|)
value|(le32toh((sdp)->sd_atime))
end_define

begin_define
define|#
directive|define
name|set_sd_v1_atime
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_atime = htole32(v))
end_define

begin_define
define|#
directive|define
name|sd_v1_mtime
parameter_list|(
name|sdp
parameter_list|)
value|(le32toh((sdp)->sd_mtime))
end_define

begin_define
define|#
directive|define
name|set_sd_v1_mtime
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_mtime = htole32(v))
end_define

begin_define
define|#
directive|define
name|sd_v1_ctime
parameter_list|(
name|sdp
parameter_list|)
value|(le32toh((sdp)->sd_ctime))
end_define

begin_define
define|#
directive|define
name|set_sd_v1_ctime
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_ctime = htole32(v))
end_define

begin_define
define|#
directive|define
name|sd_v1_rdev
parameter_list|(
name|sdp
parameter_list|)
value|(le32toh((sdp)->u.sd_rdev))
end_define

begin_define
define|#
directive|define
name|set_sd_v1_rdev
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->u.sd_rdev = htole32(v))
end_define

begin_define
define|#
directive|define
name|sd_v1_blocks
parameter_list|(
name|sdp
parameter_list|)
value|(le32toh((sdp)->u.sd_blocks))
end_define

begin_define
define|#
directive|define
name|set_sd_v1_blocks
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->u.sd_blocks = htole32(v))
end_define

begin_define
define|#
directive|define
name|sd_v1_first_direct_byte
parameter_list|(
name|sdp
parameter_list|)
define|\
value|(le32toh((sdp)->sd_first_direct_byte))
end_define

begin_define
define|#
directive|define
name|set_sd_v1_first_direct_byte
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
define|\
value|((sdp)->sd_first_direct_byte = htole32(v))
end_define

begin_comment
comment|/*  * We want common flags to have the same values as in ext2,  * so chattr(1) will work without problems  */
end_comment

begin_include
include|#
directive|include
file|<fs/ext2fs/ext2fs.h>
end_include

begin_include
include|#
directive|include
file|<fs/ext2fs/ext2_dinode.h>
end_include

begin_define
define|#
directive|define
name|REISERFS_IMMUTABLE_FL
value|EXT2_IMMUTABLE
end_define

begin_define
define|#
directive|define
name|REISERFS_APPEND_FL
value|EXT2_APPEND
end_define

begin_define
define|#
directive|define
name|REISERFS_SYNC_FL
value|EXT2_SYNC
end_define

begin_define
define|#
directive|define
name|REISERFS_NOATIME_FL
value|EXT2_NOATIME
end_define

begin_define
define|#
directive|define
name|REISERFS_NODUMP_FL
value|EXT2_NODUMP
end_define

begin_define
define|#
directive|define
name|REISERFS_SECRM_FL
value|EXT2_SECRM
end_define

begin_define
define|#
directive|define
name|REISERFS_UNRM_FL
value|EXT2_UNRM
end_define

begin_define
define|#
directive|define
name|REISERFS_COMPR_FL
value|EXT2_COMPR
end_define

begin_define
define|#
directive|define
name|REISERFS_NOTAIL_FL
value|EXT2_NOTAIL_FL
end_define

begin_comment
comment|/*  * Stat Data on disk (reiserfs version of UFS disk inode minus the  * address blocks)  */
end_comment

begin_struct
struct|struct
name|stat_data
block|{
name|uint16_t
name|sd_mode
decl_stmt|;
comment|/* File type, permissions */
name|uint16_t
name|sd_attrs
decl_stmt|;
comment|/* Persistent inode flags */
name|uint32_t
name|sd_nlink
decl_stmt|;
comment|/* Number of hard links */
name|uint64_t
name|sd_size
decl_stmt|;
comment|/* File size */
name|uint32_t
name|sd_uid
decl_stmt|;
comment|/* Owner */
name|uint32_t
name|sd_gid
decl_stmt|;
comment|/* Group */
name|uint32_t
name|sd_atime
decl_stmt|;
comment|/* Time of last access */
name|uint32_t
name|sd_mtime
decl_stmt|;
comment|/* Time file was last modified  */
name|uint32_t
name|sd_ctime
decl_stmt|;
comment|/* Time inode (stat data) was last changed 				     (except changes to sd_atime and 				     sd_mtime) */
name|uint32_t
name|sd_blocks
decl_stmt|;
union|union
block|{
name|uint32_t
name|sd_rdev
decl_stmt|;
name|uint32_t
name|sd_generation
decl_stmt|;
comment|//uint32_t	sd_first_direct_byte;
comment|/* 		 * First byte of file which is stored in a 		 * direct item: except that if it equals 1 		 * it is a symlink and if it equals 		 * ~(uint32_t)0 there is no direct item.  The 		 * existence of this field really grates 		 * on me. Let's replace it with a macro 		 * based on sd_size and our tail 		 * suppression policy? 		 */
block|}
name|__packed
name|u
union|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* This is 44 bytes long */
end_comment

begin_define
define|#
directive|define
name|SD_SIZE
value|(sizeof(struct stat_data))
end_define

begin_define
define|#
directive|define
name|SD_V2_SIZE
value|SD_SIZE
end_define

begin_define
define|#
directive|define
name|stat_data_v2
parameter_list|(
name|ih
parameter_list|)
value|(ih_version (ih) == KEY_FORMAT_3_6)
end_define

begin_define
define|#
directive|define
name|sd_v2_mode
parameter_list|(
name|sdp
parameter_list|)
value|(le16toh((sdp)->sd_mode))
end_define

begin_define
define|#
directive|define
name|set_sd_v2_mode
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_mode = htole16(v))
end_define

begin_comment
comment|/* sd_reserved */
end_comment

begin_comment
comment|/* set_sd_reserved */
end_comment

begin_define
define|#
directive|define
name|sd_v2_nlink
parameter_list|(
name|sdp
parameter_list|)
value|(le32toh((sdp)->sd_nlink))
end_define

begin_define
define|#
directive|define
name|set_sd_v2_nlink
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_nlink = htole32(v))
end_define

begin_define
define|#
directive|define
name|sd_v2_size
parameter_list|(
name|sdp
parameter_list|)
value|(le64toh((sdp)->sd_size))
end_define

begin_define
define|#
directive|define
name|set_sd_v2_size
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_size = cpu_to_le64(v))
end_define

begin_define
define|#
directive|define
name|sd_v2_uid
parameter_list|(
name|sdp
parameter_list|)
value|(le32toh((sdp)->sd_uid))
end_define

begin_define
define|#
directive|define
name|set_sd_v2_uid
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_uid = htole32(v))
end_define

begin_define
define|#
directive|define
name|sd_v2_gid
parameter_list|(
name|sdp
parameter_list|)
value|(le32toh((sdp)->sd_gid))
end_define

begin_define
define|#
directive|define
name|set_sd_v2_gid
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_gid = htole32(v))
end_define

begin_define
define|#
directive|define
name|sd_v2_atime
parameter_list|(
name|sdp
parameter_list|)
value|(le32toh((sdp)->sd_atime))
end_define

begin_define
define|#
directive|define
name|set_sd_v2_atime
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_atime = htole32(v))
end_define

begin_define
define|#
directive|define
name|sd_v2_mtime
parameter_list|(
name|sdp
parameter_list|)
value|(le32toh((sdp)->sd_mtime))
end_define

begin_define
define|#
directive|define
name|set_sd_v2_mtime
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_mtime = htole32(v))
end_define

begin_define
define|#
directive|define
name|sd_v2_ctime
parameter_list|(
name|sdp
parameter_list|)
value|(le32toh((sdp)->sd_ctime))
end_define

begin_define
define|#
directive|define
name|set_sd_v2_ctime
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_ctime = htole32(v))
end_define

begin_define
define|#
directive|define
name|sd_v2_blocks
parameter_list|(
name|sdp
parameter_list|)
value|(le32toh((sdp)->sd_blocks))
end_define

begin_define
define|#
directive|define
name|set_sd_v2_blocks
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_blocks = htole32(v))
end_define

begin_define
define|#
directive|define
name|sd_v2_rdev
parameter_list|(
name|sdp
parameter_list|)
value|(le32toh((sdp)->u.sd_rdev))
end_define

begin_define
define|#
directive|define
name|set_sd_v2_rdev
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->u.sd_rdev = htole32(v))
end_define

begin_define
define|#
directive|define
name|sd_v2_generation
parameter_list|(
name|sdp
parameter_list|)
value|(le32toh((sdp)->u.sd_generation))
end_define

begin_define
define|#
directive|define
name|set_sd_v2_generation
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->u.sd_generation = htole32(v))
end_define

begin_define
define|#
directive|define
name|sd_v2_attrs
parameter_list|(
name|sdp
parameter_list|)
value|(le16toh((sdp)->sd_attrs))
end_define

begin_define
define|#
directive|define
name|set_sd_v2_attrs
parameter_list|(
name|sdp
parameter_list|,
name|v
parameter_list|)
value|((sdp)->sd_attrs = htole16(v))
end_define

begin_comment
comment|/* -------------------------------------------------------------------  * Directory structure  * -------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|SD_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|SD_UNIQUENESS
value|0
end_define

begin_define
define|#
directive|define
name|DOT_OFFSET
value|1
end_define

begin_define
define|#
directive|define
name|DOT_DOT_OFFSET
value|2
end_define

begin_define
define|#
directive|define
name|DIRENTRY_UNIQUENESS
value|500
end_define

begin_define
define|#
directive|define
name|FIRST_ITEM_OFFSET
value|1
end_define

begin_struct
struct|struct
name|reiserfs_de_head
block|{
name|uint32_t
name|deh_offset
decl_stmt|;
comment|/* Third component of the directory 					  entry key */
name|uint32_t
name|deh_dir_id
decl_stmt|;
comment|/* Objectid of the parent directory of 					  the object, that is referenced by 					  directory entry */
name|uint32_t
name|deh_objectid
decl_stmt|;
comment|/* Objectid of the object, that is 					  referenced by directory entry */
name|uint16_t
name|deh_location
decl_stmt|;
comment|/* Offset of name in the whole item */
name|uint16_t
name|deh_state
decl_stmt|;
comment|/* Whether 1) entry contains stat data 					  (for future), and 2) whether entry 					  is hidden (unlinked) */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|DEH_SIZE
value|sizeof(struct reiserfs_de_head)
end_define

begin_define
define|#
directive|define
name|deh_offset
parameter_list|(
name|p_deh
parameter_list|)
value|(le32toh((p_deh)->deh_offset))
end_define

begin_define
define|#
directive|define
name|deh_dir_id
parameter_list|(
name|p_deh
parameter_list|)
value|(le32toh((p_deh)->deh_dir_id))
end_define

begin_define
define|#
directive|define
name|deh_objectid
parameter_list|(
name|p_deh
parameter_list|)
value|(le32toh((p_deh)->deh_objectid))
end_define

begin_define
define|#
directive|define
name|deh_location
parameter_list|(
name|p_deh
parameter_list|)
value|(le16toh((p_deh)->deh_location))
end_define

begin_define
define|#
directive|define
name|deh_state
parameter_list|(
name|p_deh
parameter_list|)
value|(le16toh((p_deh)->deh_state))
end_define

begin_define
define|#
directive|define
name|put_deh_offset
parameter_list|(
name|p_deh
parameter_list|,
name|v
parameter_list|)
value|((p_deh)->deh_offset = htole32((v)))
end_define

begin_define
define|#
directive|define
name|put_deh_dir_id
parameter_list|(
name|p_deh
parameter_list|,
name|v
parameter_list|)
value|((p_deh)->deh_dir_id = htole32((v)))
end_define

begin_define
define|#
directive|define
name|put_deh_objectid
parameter_list|(
name|p_deh
parameter_list|,
name|v
parameter_list|)
value|((p_deh)->deh_objectid = htole32((v)))
end_define

begin_define
define|#
directive|define
name|put_deh_location
parameter_list|(
name|p_deh
parameter_list|,
name|v
parameter_list|)
value|((p_deh)->deh_location = htole16((v)))
end_define

begin_define
define|#
directive|define
name|put_deh_state
parameter_list|(
name|p_deh
parameter_list|,
name|v
parameter_list|)
value|((p_deh)->deh_state = htole16((v)))
end_define

begin_comment
comment|/* Empty directory contains two entries "." and ".." and their headers */
end_comment

begin_define
define|#
directive|define
name|EMPTY_DIR_SIZE
define|\
value|(DEH_SIZE * 2 + ROUND_UP(strlen(".")) + ROUND_UP(strlen("..")))
end_define

begin_comment
comment|/* Old format directories have this size when empty */
end_comment

begin_define
define|#
directive|define
name|EMPTY_DIR_SIZE_V1
value|(DEH_SIZE * 2 + 3)
end_define

begin_define
define|#
directive|define
name|DEH_Statdata
value|0
end_define

begin_comment
comment|/* Not used now */
end_comment

begin_define
define|#
directive|define
name|DEH_Visible
value|2
end_define

begin_comment
comment|/* Macro to map Linux' *_bit function to bitstring.h macros */
end_comment

begin_define
define|#
directive|define
name|set_bit
parameter_list|(
name|bit
parameter_list|,
name|name
parameter_list|)
value|bit_set((bitstr_t *)name, bit)
end_define

begin_define
define|#
directive|define
name|clear_bit
parameter_list|(
name|bit
parameter_list|,
name|name
parameter_list|)
value|bit_clear((bitstr_t *)name, bit)
end_define

begin_define
define|#
directive|define
name|test_bit
parameter_list|(
name|bit
parameter_list|,
name|name
parameter_list|)
value|bit_test((bitstr_t *)name, bit)
end_define

begin_define
define|#
directive|define
name|set_bit_unaligned
parameter_list|(
name|bit
parameter_list|,
name|name
parameter_list|)
value|set_bit(bit, name)
end_define

begin_define
define|#
directive|define
name|clear_bit_unaligned
parameter_list|(
name|bit
parameter_list|,
name|name
parameter_list|)
value|clear_bit(bit, name)
end_define

begin_define
define|#
directive|define
name|test_bit_unaligned
parameter_list|(
name|bit
parameter_list|,
name|name
parameter_list|)
value|test_bit(bit, name)
end_define

begin_define
define|#
directive|define
name|mark_de_with_sd
parameter_list|(
name|deh
parameter_list|)
define|\
value|set_bit_unaligned(DEH_Statdata,&((deh)->deh_state))
end_define

begin_define
define|#
directive|define
name|mark_de_without_sd
parameter_list|(
name|deh
parameter_list|)
define|\
value|clear_bit_unaligned(DEH_Statdata,&((deh)->deh_state))
end_define

begin_define
define|#
directive|define
name|mark_de_visible
parameter_list|(
name|deh
parameter_list|)
define|\
value|set_bit_unaligned (DEH_Visible,&((deh)->deh_state))
end_define

begin_define
define|#
directive|define
name|mark_de_hidden
parameter_list|(
name|deh
parameter_list|)
define|\
value|clear_bit_unaligned (DEH_Visible,&((deh)->deh_state))
end_define

begin_define
define|#
directive|define
name|de_with_sd
parameter_list|(
name|deh
parameter_list|)
define|\
value|test_bit_unaligned(DEH_Statdata,&((deh)->deh_state))
end_define

begin_define
define|#
directive|define
name|de_visible
parameter_list|(
name|deh
parameter_list|)
define|\
value|test_bit_unaligned(DEH_Visible,&((deh)->deh_state))
end_define

begin_define
define|#
directive|define
name|de_hidden
parameter_list|(
name|deh
parameter_list|)
define|\
value|!test_bit_unaligned(DEH_Visible,&((deh)->deh_state))
end_define

begin_comment
comment|/* Two entries per block (at least) */
end_comment

begin_define
define|#
directive|define
name|REISERFS_MAX_NAME
parameter_list|(
name|block_size
parameter_list|)
value|255
end_define

begin_comment
comment|/*  * This structure is used for operations on directory entries. It is not  * a disk structure. When reiserfs_find_entry or search_by_entry_key  * find directory entry, they return filled reiserfs_dir_entry structure  */
end_comment

begin_struct
struct|struct
name|reiserfs_dir_entry
block|{
name|struct
name|buf
modifier|*
name|de_bp
decl_stmt|;
name|int
name|de_item_num
decl_stmt|;
name|struct
name|item_head
modifier|*
name|de_ih
decl_stmt|;
name|int
name|de_entry_num
decl_stmt|;
name|struct
name|reiserfs_de_head
modifier|*
name|de_deh
decl_stmt|;
name|int
name|de_entrylen
decl_stmt|;
name|int
name|de_namelen
decl_stmt|;
name|char
modifier|*
name|de_name
decl_stmt|;
name|char
modifier|*
name|de_gen_number_bit_string
decl_stmt|;
name|uint32_t
name|de_dir_id
decl_stmt|;
name|uint32_t
name|de_objectid
decl_stmt|;
name|struct
name|cpu_key
name|de_entry_key
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Pointer to file name, stored in entry */
end_comment

begin_define
define|#
directive|define
name|B_I_DEH_ENTRY_FILE_NAME
parameter_list|(
name|bp
parameter_list|,
name|ih
parameter_list|,
name|deh
parameter_list|)
define|\
value|(B_I_PITEM(bp, ih) + deh_location(deh))
end_define

begin_comment
comment|/* Length of name */
end_comment

begin_define
define|#
directive|define
name|I_DEH_N_ENTRY_FILE_NAME_LENGTH
parameter_list|(
name|ih
parameter_list|,
name|deh
parameter_list|,
name|entry_num
parameter_list|)
define|\
value|(I_DEH_N_ENTRY_LENGTH(ih, deh, entry_num) -				\      (de_with_sd(deh) ? SD_SIZE : 0))
end_define

begin_comment
comment|/* Hash value occupies bits from 7 up to 30 */
end_comment

begin_define
define|#
directive|define
name|GET_HASH_VALUE
parameter_list|(
name|offset
parameter_list|)
value|((offset)& 0x7fffff80LL)
end_define

begin_comment
comment|/* Generation number occupies 7 bits starting from 0 up to 6 */
end_comment

begin_define
define|#
directive|define
name|GET_GENERATION_NUMBER
parameter_list|(
name|offset
parameter_list|)
value|((offset)& 0x7fLL)
end_define

begin_define
define|#
directive|define
name|MAX_GENERATION_NUMBER
value|127
end_define

begin_comment
comment|/* Get item body */
end_comment

begin_define
define|#
directive|define
name|B_I_PITEM
parameter_list|(
name|bp
parameter_list|,
name|ih
parameter_list|)
value|((bp)->b_data + ih_location(ih))
end_define

begin_define
define|#
directive|define
name|B_I_DEH
parameter_list|(
name|bp
parameter_list|,
name|ih
parameter_list|)
value|((struct reiserfs_de_head *)(B_I_PITEM(bp, ih)))
end_define

begin_comment
comment|/*  * Length of the directory entry in directory item. This define  * calculates length of i-th directory entry using directory entry  * locations from dir entry head. When it calculates length of 0-th  * directory entry, it uses length of whole item in place of entry  * location of the non-existent following entry in the calculation. See  * picture above.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|entry_length
parameter_list|(
specifier|const
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
specifier|const
name|struct
name|item_head
modifier|*
name|ih
parameter_list|,
name|int
name|pos_in_item
parameter_list|)
block|{
name|struct
name|reiserfs_de_head
modifier|*
name|deh
decl_stmt|;
name|deh
operator|=
name|B_I_DEH
argument_list|(
name|bp
argument_list|,
name|ih
argument_list|)
operator|+
name|pos_in_item
expr_stmt|;
if|if
condition|(
name|pos_in_item
condition|)
return|return
operator|(
name|deh_location
argument_list|(
name|deh
operator|-
literal|1
argument_list|)
operator|-
name|deh_location
argument_list|(
name|deh
argument_list|)
operator|)
return|;
return|return
operator|(
name|ih_item_len
argument_list|(
name|ih
argument_list|)
operator|-
name|deh_location
argument_list|(
name|deh
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Number of entries in the directory item, depends on ENTRY_COUNT  * being at the start of directory dynamic data.  */
end_comment

begin_define
define|#
directive|define
name|I_ENTRY_COUNT
parameter_list|(
name|ih
parameter_list|)
value|(ih_entry_count((ih)))
end_define

begin_comment
comment|/* -------------------------------------------------------------------  * Disk child  * -------------------------------------------------------------------*/
end_comment

begin_comment
comment|/*  * Disk child pointer: The pointer from an internal node of the tree  * to a node that is on disk.  */
end_comment

begin_struct
struct|struct
name|disk_child
block|{
name|uint32_t
name|dc_block_number
decl_stmt|;
comment|/* Disk child's block number. */
name|uint16_t
name|dc_size
decl_stmt|;
comment|/* Disk child's used space. */
name|uint16_t
name|dc_reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DC_SIZE
value|(sizeof(struct disk_child))
end_define

begin_define
define|#
directive|define
name|dc_block_number
parameter_list|(
name|dc_p
parameter_list|)
value|(le32toh((dc_p)->dc_block_number))
end_define

begin_define
define|#
directive|define
name|dc_size
parameter_list|(
name|dc_p
parameter_list|)
value|(le16toh((dc_p)->dc_size))
end_define

begin_define
define|#
directive|define
name|put_dc_block_number
parameter_list|(
name|dc_p
parameter_list|,
name|val
parameter_list|)
define|\
value|do { (dc_p)->dc_block_number = htole32(val); } while (0)
end_define

begin_define
define|#
directive|define
name|put_dc_size
parameter_list|(
name|dc_p
parameter_list|,
name|val
parameter_list|)
define|\
value|do { (dc_p)->dc_size = htole16(val); } while (0)
end_define

begin_comment
comment|/* Get disk child by buffer header and position in the tree node. */
end_comment

begin_define
define|#
directive|define
name|B_N_CHILD
parameter_list|(
name|p_s_bp
parameter_list|,
name|n_pos
parameter_list|)
define|\
value|((struct disk_child *)((p_s_bp)->b_data + BLKH_SIZE +		\ 			   B_NR_ITEMS(p_s_bp) * KEY_SIZE +		\ 			   DC_SIZE * (n_pos)))
end_define

begin_comment
comment|/* Get disk child number by buffer header and position in the tree node. */
end_comment

begin_define
define|#
directive|define
name|B_N_CHILD_NUM
parameter_list|(
name|p_s_bp
parameter_list|,
name|n_pos
parameter_list|)
define|\
value|(dc_block_number(B_N_CHILD(p_s_bp, n_pos)))
end_define

begin_define
define|#
directive|define
name|PUT_B_N_CHILD_NUM
parameter_list|(
name|p_s_bp
parameter_list|,
name|n_pos
parameter_list|,
name|val
parameter_list|)
define|\
value|(put_dc_block_number(B_N_CHILD(p_s_bp, n_pos), val))
end_define

begin_comment
comment|/* -------------------------------------------------------------------  * Path structures and defines  * -------------------------------------------------------------------*/
end_comment

begin_struct
struct|struct
name|path_element
block|{
name|struct
name|buf
modifier|*
name|pe_buffer
decl_stmt|;
comment|/* Pointer to the buffer at the path in 					the tree. */
name|int
name|pe_position
decl_stmt|;
comment|/* Position in the tree node which is 					placed in the buffer above. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_HEIGHT
value|5
end_define

begin_comment
comment|/* Maximal height of a tree. Don't 					     change this without changing 					     JOURNAL_PER_BALANCE_CNT */
end_comment

begin_define
define|#
directive|define
name|EXTENDED_MAX_HEIGHT
value|7
end_define

begin_comment
comment|/* Must be equals MAX_HEIGHT + 					     FIRST_PATH_ELEMENT_OFFSET */
end_comment

begin_define
define|#
directive|define
name|FIRST_PATH_ELEMENT_OFFSET
value|2
end_define

begin_comment
comment|/* Must be equal to at least 2. */
end_comment

begin_define
define|#
directive|define
name|ILLEGAL_PATH_ELEMENT_OFFSET
value|1
end_define

begin_comment
comment|/* Must be equal to 					     FIRST_PATH_ELEMENT_OFFSET - 1 */
end_comment

begin_define
define|#
directive|define
name|MAX_FEB_SIZE
value|6
end_define

begin_comment
comment|/* This MUST be MAX_HEIGHT + 1. 					     See about FEB below */
end_comment

begin_struct
struct|struct
name|path
block|{
comment|/* Length of the array below. */
name|int
name|path_length
decl_stmt|;
comment|/* Array of the path element */
name|struct
name|path_element
name|path_elements
index|[
name|EXTENDED_MAX_HEIGHT
index|]
decl_stmt|;
name|int
name|pos_in_item
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|pos_in_item
parameter_list|(
name|path
parameter_list|)
value|((path)->pos_in_item)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_comment
comment|/* To workaround a bug in gcc. He generates a call to memset() which  * is a inline function; this causes a compile time error. */
end_comment

begin_define
define|#
directive|define
name|INITIALIZE_PATH
parameter_list|(
name|var
parameter_list|)
define|\
value|struct path var;							\     bzero(&var, sizeof(var));						\     var.path_length = ILLEGAL_PATH_ELEMENT_OFFSET;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INITIALIZE_PATH
parameter_list|(
name|var
parameter_list|)
define|\
value|struct path var = { ILLEGAL_PATH_ELEMENT_OFFSET, }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get path element by path and path position. */
end_comment

begin_define
define|#
directive|define
name|PATH_OFFSET_PELEMENT
parameter_list|(
name|p_s_path
parameter_list|,
name|n_offset
parameter_list|)
define|\
value|((p_s_path)->path_elements + (n_offset))
end_define

begin_comment
comment|/* Get buffer header at the path by path and path position. */
end_comment

begin_define
define|#
directive|define
name|PATH_OFFSET_PBUFFER
parameter_list|(
name|p_s_path
parameter_list|,
name|n_offset
parameter_list|)
define|\
value|(PATH_OFFSET_PELEMENT(p_s_path, n_offset)->pe_buffer)
end_define

begin_comment
comment|/* Get position in the element at the path by path and path position. */
end_comment

begin_define
define|#
directive|define
name|PATH_OFFSET_POSITION
parameter_list|(
name|p_s_path
parameter_list|,
name|n_offset
parameter_list|)
define|\
value|(PATH_OFFSET_PELEMENT(p_s_path, n_offset)->pe_position)
end_define

begin_define
define|#
directive|define
name|PATH_PLAST_BUFFER
parameter_list|(
name|p_s_path
parameter_list|)
define|\
value|(PATH_OFFSET_PBUFFER((p_s_path), (p_s_path)->path_length))
end_define

begin_define
define|#
directive|define
name|PATH_LAST_POSITION
parameter_list|(
name|p_s_path
parameter_list|)
define|\
value|(PATH_OFFSET_POSITION((p_s_path), (p_s_path)->path_length))
end_define

begin_define
define|#
directive|define
name|PATH_PITEM_HEAD
parameter_list|(
name|p_s_path
parameter_list|)
define|\
value|B_N_PITEM_HEAD(PATH_PLAST_BUFFER(p_s_path), PATH_LAST_POSITION(p_s_path))
end_define

begin_define
define|#
directive|define
name|get_last_bp
parameter_list|(
name|path
parameter_list|)
value|PATH_PLAST_BUFFER(path)
end_define

begin_define
define|#
directive|define
name|get_ih
parameter_list|(
name|path
parameter_list|)
value|PATH_PITEM_HEAD(path)
end_define

begin_comment
comment|/* -------------------------------------------------------------------  * Misc.  * -------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* Size of pointer to the unformatted node. */
end_comment

begin_define
define|#
directive|define
name|UNFM_P_SIZE
value|(sizeof(unp_t))
end_define

begin_define
define|#
directive|define
name|UNFM_P_SHIFT
value|2
end_define

begin_comment
comment|/* In in-core inode key is stored on le form */
end_comment

begin_define
define|#
directive|define
name|INODE_PKEY
parameter_list|(
name|ip
parameter_list|)
value|((struct key *)(REISERFS_I(ip)->i_key))
end_define

begin_define
define|#
directive|define
name|MAX_UL_INT
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|MAX_INT
value|0x7ffffff
end_define

begin_define
define|#
directive|define
name|MAX_US_INT
value|0xffff
end_define

begin_comment
comment|/* The purpose is to detect overflow of an unsigned short */
end_comment

begin_define
define|#
directive|define
name|REISERFS_LINK_MAX
value|(MAX_US_INT - 1000)
end_define

begin_define
define|#
directive|define
name|fs_generation
parameter_list|(
name|sbi
parameter_list|)
value|(REISERFS_SB(sbi)->s_generation_counter)
end_define

begin_define
define|#
directive|define
name|get_generation
parameter_list|(
name|sbi
parameter_list|)
value|(fs_generation(sbi))
end_define

begin_define
define|#
directive|define
name|__fs_changed
parameter_list|(
name|gen
parameter_list|,
name|sbi
parameter_list|)
value|(gen != get_generation (sbi))
end_define

begin_comment
comment|/*#define	fs_changed(gen, sbi)	({ cond_resched();		\     __fs_changed(gen, sbi); })*/
end_comment

begin_define
define|#
directive|define
name|fs_changed
parameter_list|(
name|gen
parameter_list|,
name|sbi
parameter_list|)
value|(__fs_changed(gen, sbi))
end_define

begin_comment
comment|/* -------------------------------------------------------------------  * Fixate node  * -------------------------------------------------------------------*/
end_comment

begin_comment
comment|/*  * To make any changes in the tree we always first find node, that  * contains item to be changed/deleted or place to insert a new item.  * We call this node S. To do balancing we need to decide what we will  * shift to left/right neighbor, or to a new node, where new item will  * be etc. To make this analysis simpler we build virtual node. Virtual  * node is an array of items, that will replace items of node S. (For  * instance if we are going to delete an item, virtual node does not  * contain it). Virtual node keeps information about item sizes and  * types, mergeability of first and last items, sizes of all entries in  * directory item. We use this array of items when calculating what we  * can shift to neighbors and how many nodes we have to have if we do  * not any shiftings, if we shift to left/right neighbor or to both.  */
end_comment

begin_struct
struct|struct
name|virtual_item
block|{
name|int
name|vi_index
decl_stmt|;
comment|/* Index in the array of item 						 operations */
name|unsigned
name|short
name|vi_type
decl_stmt|;
comment|/* Left/right mergeability */
name|unsigned
name|short
name|vi_item_len
decl_stmt|;
comment|/* Length of item that it will 						 have after balancing */
name|struct
name|item_head
modifier|*
name|vi_ih
decl_stmt|;
specifier|const
name|char
modifier|*
name|vi_item
decl_stmt|;
comment|/* Body of item (old or new) */
specifier|const
name|void
modifier|*
name|vi_new_data
decl_stmt|;
comment|/* 0 always but paste mode */
name|void
modifier|*
name|vi_uarea
decl_stmt|;
comment|/* Item specific area */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|virtual_node
block|{
name|char
modifier|*
name|vn_free_ptr
decl_stmt|;
comment|/* This is a pointer to the free space 					 in the buffer */
name|unsigned
name|short
name|vn_nr_item
decl_stmt|;
comment|/* Number of items in virtual node */
name|short
name|vn_size
decl_stmt|;
comment|/* Size of node , that node would have 					 if it has unlimited size and no 					 balancing is performed */
name|short
name|vn_mode
decl_stmt|;
comment|/* Mode of balancing (paste, insert, 					 delete, cut) */
name|short
name|vn_affected_item_num
decl_stmt|;
name|short
name|vn_pos_in_item
decl_stmt|;
name|struct
name|item_head
modifier|*
name|vn_ins_ih
decl_stmt|;
comment|/* Item header of inserted item, 0 for 					 other modes */
specifier|const
name|void
modifier|*
name|vn_data
decl_stmt|;
name|struct
name|virtual_item
modifier|*
name|vn_vi
decl_stmt|;
comment|/* Array of items (including a new one, 					 excluding item to be deleted) */
block|}
struct|;
end_struct

begin_comment
comment|/* Used by directory items when creating virtual nodes */
end_comment

begin_struct
struct|struct
name|direntry_uarea
block|{
name|int
name|flags
decl_stmt|;
name|uint16_t
name|entry_count
decl_stmt|;
name|uint16_t
name|entry_sizes
index|[
literal|1
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* -------------------------------------------------------------------  * Tree balance  * -------------------------------------------------------------------*/
end_comment

begin_struct
struct|struct
name|reiserfs_iget_args
block|{
name|uint32_t
name|objectid
decl_stmt|;
name|uint32_t
name|dirid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|item_operations
block|{
name|int
function_decl|(
modifier|*
name|bytes_number
function_decl|)
parameter_list|(
name|struct
name|item_head
modifier|*
name|ih
parameter_list|,
name|int
name|block_size
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|decrement_key
function_decl|)
parameter_list|(
name|struct
name|cpu_key
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|is_left_mergeable
function_decl|)
parameter_list|(
name|struct
name|key
modifier|*
name|ih
parameter_list|,
name|unsigned
name|long
name|bsize
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|print_item
function_decl|)
parameter_list|(
name|struct
name|item_head
modifier|*
parameter_list|,
name|char
modifier|*
name|item
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|check_item
function_decl|)
parameter_list|(
name|struct
name|item_head
modifier|*
parameter_list|,
name|char
modifier|*
name|item
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|create_vi
function_decl|)
parameter_list|(
name|struct
name|virtual_node
modifier|*
name|vn
parameter_list|,
name|struct
name|virtual_item
modifier|*
name|vi
parameter_list|,
name|int
name|is_affected
parameter_list|,
name|int
name|insert_size
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|check_left
function_decl|)
parameter_list|(
name|struct
name|virtual_item
modifier|*
name|vi
parameter_list|,
name|int
name|free
parameter_list|,
name|int
name|start_skip
parameter_list|,
name|int
name|end_skip
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|check_right
function_decl|)
parameter_list|(
name|struct
name|virtual_item
modifier|*
name|vi
parameter_list|,
name|int
name|free
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|part_size
function_decl|)
parameter_list|(
name|struct
name|virtual_item
modifier|*
name|vi
parameter_list|,
name|int
name|from
parameter_list|,
name|int
name|to
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|unit_num
function_decl|)
parameter_list|(
name|struct
name|virtual_item
modifier|*
name|vi
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|print_vi
function_decl|)
parameter_list|(
name|struct
name|virtual_item
modifier|*
name|vi
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|item_operations
modifier|*
name|item_ops
index|[
name|TYPE_ANY
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|op_bytes_number
parameter_list|(
name|ih
parameter_list|,
name|bsize
parameter_list|)
define|\
value|item_ops[le_ih_k_type(ih)]->bytes_number(ih, bsize)
end_define

begin_define
define|#
directive|define
name|COMP_KEYS
value|comp_keys
end_define

begin_define
define|#
directive|define
name|COMP_SHORT_KEYS
value|comp_short_keys
end_define

begin_comment
comment|/* Get the item header */
end_comment

begin_define
define|#
directive|define
name|B_N_PITEM_HEAD
parameter_list|(
name|bp
parameter_list|,
name|item_num
parameter_list|)
define|\
value|((struct item_head *)((bp)->b_data + BLKH_SIZE) + (item_num))
end_define

begin_comment
comment|/* Get key */
end_comment

begin_define
define|#
directive|define
name|B_N_PDELIM_KEY
parameter_list|(
name|bp
parameter_list|,
name|item_num
parameter_list|)
define|\
value|((struct key *)((bp)->b_data + BLKH_SIZE) + (item_num))
end_define

begin_comment
comment|/* -------------------------------------------------------------------  * Function declarations  * -------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* reiserfs_stree.c */
end_comment

begin_function_decl
name|int
name|B_IS_IN_TREE
parameter_list|(
specifier|const
name|struct
name|buf
modifier|*
name|p_s_bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|copy_item_head
parameter_list|(
name|struct
name|item_head
modifier|*
name|p_v_to
parameter_list|,
specifier|const
name|struct
name|item_head
modifier|*
name|p_v_from
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|comp_keys
parameter_list|(
specifier|const
name|struct
name|key
modifier|*
name|le_key
parameter_list|,
specifier|const
name|struct
name|cpu_key
modifier|*
name|cpu_key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|comp_short_keys
parameter_list|(
specifier|const
name|struct
name|key
modifier|*
name|le_key
parameter_list|,
specifier|const
name|struct
name|cpu_key
modifier|*
name|cpu_key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|comp_le_keys
parameter_list|(
specifier|const
name|struct
name|key
modifier|*
parameter_list|,
specifier|const
name|struct
name|key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|le_key_version
parameter_list|(
specifier|const
name|struct
name|key
modifier|*
name|key
parameter_list|)
block|{
name|int
name|type
decl_stmt|;
name|type
operator|=
name|offset_v2_k_type
argument_list|(
operator|&
operator|(
name|key
operator|->
name|u
operator|.
name|k_offset_v2
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|!=
name|TYPE_DIRECT
operator|&&
name|type
operator|!=
name|TYPE_INDIRECT
operator|&&
name|type
operator|!=
name|TYPE_DIRENTRY
condition|)
return|return
operator|(
name|KEY_FORMAT_3_5
operator|)
return|;
return|return
operator|(
name|KEY_FORMAT_3_6
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|copy_key
parameter_list|(
name|struct
name|key
modifier|*
name|to
parameter_list|,
specifier|const
name|struct
name|key
modifier|*
name|from
parameter_list|)
block|{
name|memcpy
argument_list|(
name|to
argument_list|,
name|from
argument_list|,
name|KEY_SIZE
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|const
name|struct
name|key
modifier|*
name|get_lkey
parameter_list|(
specifier|const
name|struct
name|path
modifier|*
name|p_s_chk_path
parameter_list|,
specifier|const
name|struct
name|reiserfs_sb_info
modifier|*
name|p_s_sbi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|key
modifier|*
name|get_rkey
parameter_list|(
specifier|const
name|struct
name|path
modifier|*
name|p_s_chk_path
parameter_list|,
specifier|const
name|struct
name|reiserfs_sb_info
modifier|*
name|p_s_sbi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bin_search
parameter_list|(
specifier|const
name|void
modifier|*
name|p_v_key
parameter_list|,
specifier|const
name|void
modifier|*
name|p_v_base
parameter_list|,
name|int
name|p_n_num
parameter_list|,
name|int
name|p_n_width
parameter_list|,
name|int
modifier|*
name|p_n_pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pathrelse
parameter_list|(
name|struct
name|path
modifier|*
name|p_s_search_path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|reiserfs_check_path
parameter_list|(
name|struct
name|path
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|search_by_key
parameter_list|(
name|struct
name|reiserfs_sb_info
modifier|*
name|p_s_sbi
parameter_list|,
specifier|const
name|struct
name|cpu_key
modifier|*
name|p_s_key
parameter_list|,
name|struct
name|path
modifier|*
name|p_s_search_path
parameter_list|,
name|int
name|n_stop_level
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|search_item
parameter_list|(
name|sbi
parameter_list|,
name|key
parameter_list|,
name|path
parameter_list|)
define|\
value|search_by_key(sbi, key, path, DISK_LEAF_NODE_LEVEL)
end_define

begin_function_decl
name|int
name|search_for_position_by_key
parameter_list|(
name|struct
name|reiserfs_sb_info
modifier|*
name|p_s_sbi
parameter_list|,
specifier|const
name|struct
name|cpu_key
modifier|*
name|p_s_cpu_key
parameter_list|,
name|struct
name|path
modifier|*
name|p_s_search_path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|decrement_counters_in_path
parameter_list|(
name|struct
name|path
modifier|*
name|p_s_search_path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* reiserfs_inode.c */
end_comment

begin_decl_stmt
name|vop_read_t
name|reiserfs_read
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_inactive_t
name|reiserfs_inactive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_reclaim_t
name|reiserfs_reclaim
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|reiserfs_get_block
parameter_list|(
name|struct
name|reiserfs_node
modifier|*
name|ip
parameter_list|,
name|long
name|block
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|make_cpu_key
parameter_list|(
name|struct
name|cpu_key
modifier|*
name|cpu_key
parameter_list|,
name|struct
name|reiserfs_node
modifier|*
name|ip
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|key_length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reiserfs_read_locked_inode
parameter_list|(
name|struct
name|reiserfs_node
modifier|*
name|ip
parameter_list|,
name|struct
name|reiserfs_iget_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|reiserfs_iget
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
specifier|const
name|struct
name|cpu_key
modifier|*
name|key
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sd_attrs_to_i_attrs
parameter_list|(
name|uint16_t
name|sd_attrs
parameter_list|,
name|struct
name|reiserfs_node
modifier|*
name|ip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i_attrs_to_sd_attrs
parameter_list|(
name|struct
name|reiserfs_node
modifier|*
name|ip
parameter_list|,
name|uint16_t
modifier|*
name|sd_attrs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* reiserfs_namei.c */
end_comment

begin_decl_stmt
name|vop_readdir_t
name|reiserfs_readdir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_cachedlookup_t
name|reiserfs_lookup
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|set_de_name_and_namelen
parameter_list|(
name|struct
name|reiserfs_dir_entry
modifier|*
name|de
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|search_by_entry_key
parameter_list|(
name|struct
name|reiserfs_sb_info
modifier|*
name|sbi
parameter_list|,
specifier|const
name|struct
name|cpu_key
modifier|*
name|key
parameter_list|,
name|struct
name|path
modifier|*
name|path
parameter_list|,
name|struct
name|reiserfs_dir_entry
modifier|*
name|de
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* reiserfs_prints.c */
end_comment

begin_function_decl
name|char
modifier|*
name|reiserfs_hashname
parameter_list|(
name|int
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reiserfs_dump_buffer
parameter_list|(
name|caddr_t
name|buf
parameter_list|,
name|off_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|REISERFS_DEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|reiserfs_log
parameter_list|(
name|lvl
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|log(lvl, "ReiserFS/%s: " fmt, __func__, ## __VA_ARGS__)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|REISERFS_DEBUG_CONS
argument_list|)
end_elif

begin_define
define|#
directive|define
name|reiserfs_log
parameter_list|(
name|lvl
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|printf("%s:%d: " fmt, __func__, __LINE__, ## __VA_ARGS__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|reiserfs_log
parameter_list|(
name|lvl
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|reiserfs_log_0
parameter_list|(
name|lvl
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|printf("%s:%d: " fmt, __func__, __LINE__, ## __VA_ARGS__)
end_define

begin_comment
comment|/* reiserfs_hashes.c */
end_comment

begin_function_decl
name|uint32_t
name|keyed_hash
parameter_list|(
specifier|const
name|signed
name|char
modifier|*
name|msg
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|yura_hash
parameter_list|(
specifier|const
name|signed
name|char
modifier|*
name|msg
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|r5_hash
parameter_list|(
specifier|const
name|signed
name|char
modifier|*
name|msg
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|reiserfs_test_le_bit
value|test_bit
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined _GNU_REISERFS_REISERFS_FS_H */
end_comment

end_unit

