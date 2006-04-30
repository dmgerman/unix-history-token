begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2000 Hans Reiser  * See README for licensing and copyright details  *   * Ported to FreeBSD by Jean-Sébastien Pédron<jspedron@club-internet.fr>  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_REISERFS_REISERFS_FS_SB_H
end_ifndef

begin_define
define|#
directive|define
name|_GNU_REISERFS_REISERFS_FS_SB_H
end_define

begin_typedef
typedef|typedef
name|uint32_t
function_decl|(
modifier|*
name|hashf_t
function_decl|)
parameter_list|(
specifier|const
name|signed
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|sb_block_count
parameter_list|(
name|sbp
parameter_list|)
value|(le32toh((sbp)->s_v1.s_block_count))
end_define

begin_define
define|#
directive|define
name|set_sb_block_count
parameter_list|(
name|sbp
parameter_list|,
name|v
parameter_list|)
value|((sbp)->s_v1.s_block_count = htole32(v))
end_define

begin_define
define|#
directive|define
name|sb_free_blocks
parameter_list|(
name|sbp
parameter_list|)
value|(le32toh((sbp)->s_v1.s_free_blocks))
end_define

begin_define
define|#
directive|define
name|set_sb_free_blocks
parameter_list|(
name|sbp
parameter_list|,
name|v
parameter_list|)
value|((sbp)->s_v1.s_free_blocks = htole32(v))
end_define

begin_define
define|#
directive|define
name|sb_root_block
parameter_list|(
name|sbp
parameter_list|)
value|(le32toh((sbp)->s_v1.s_root_block))
end_define

begin_comment
comment|/* Bitmaps */
end_comment

begin_struct
struct|struct
name|reiserfs_bitmap_info
block|{
name|uint16_t
name|first_zero_hint
decl_stmt|;
name|uint16_t
name|free_count
decl_stmt|;
comment|//struct buf	*bp;      /* The actual bitmap */
name|caddr_t
name|bp_data
decl_stmt|;
comment|/* The actual bitmap */
block|}
struct|;
end_struct

begin_comment
comment|/* ReiserFS union of in-core super block data */
end_comment

begin_struct
struct|struct
name|reiserfs_sb_info
block|{
name|struct
name|reiserfs_super_block
modifier|*
name|s_rs
decl_stmt|;
name|struct
name|reiserfs_bitmap_info
modifier|*
name|s_ap_bitmap
decl_stmt|;
name|struct
name|vnode
modifier|*
name|s_devvp
decl_stmt|;
name|unsigned
name|short
name|s_mount_state
decl_stmt|;
name|hashf_t
name|s_hash_function
decl_stmt|;
comment|/* Pointer to function which 						  is used to sort names in 						  directory. Set on mount */
name|unsigned
name|long
name|s_mount_opt
decl_stmt|;
comment|/* ReiserFS's mount options 						  are set here */
name|int
name|s_generation_counter
decl_stmt|;
comment|/* Increased by one every 						  time the tree gets 						  re-balanced */
name|unsigned
name|long
name|s_properties
decl_stmt|;
comment|/* File system properties. 						  Currently holds on-disk 						  FS format */
name|uint16_t
name|s_blocksize
decl_stmt|;
name|uint16_t
name|s_blocksize_bits
decl_stmt|;
name|char
name|s_rd_only
decl_stmt|;
comment|/* Is it read-only ? */
name|int
name|s_is_unlinked_ok
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sb_version
parameter_list|(
name|sbi
parameter_list|)
value|(le16toh((sbi)->s_v1.s_version))
end_define

begin_define
define|#
directive|define
name|set_sb_version
parameter_list|(
name|sbi
parameter_list|,
name|v
parameter_list|)
value|((sbi)->s_v1.s_version = htole16(v))
end_define

begin_define
define|#
directive|define
name|sb_blocksize
parameter_list|(
name|sbi
parameter_list|)
value|(le16toh((sbi)->s_v1.s_blocksize))
end_define

begin_define
define|#
directive|define
name|set_sb_blocksize
parameter_list|(
name|sbi
parameter_list|,
name|v
parameter_list|)
value|((sbi)->s_v1.s_blocksize = htole16(v))
end_define

begin_define
define|#
directive|define
name|sb_hash_function_code
parameter_list|(
name|sbi
parameter_list|)
define|\
value|(le32toh((sbi)->s_v1.s_hash_function_code))
end_define

begin_define
define|#
directive|define
name|set_sb_hash_function_code
parameter_list|(
name|sbi
parameter_list|,
name|v
parameter_list|)
define|\
value|((sbi)->s_v1.s_hash_function_code = htole32(v))
end_define

begin_define
define|#
directive|define
name|sb_bmap_nr
parameter_list|(
name|sbi
parameter_list|)
value|(le16toh((sbi)->s_v1.s_bmap_nr))
end_define

begin_define
define|#
directive|define
name|set_sb_bmap_nr
parameter_list|(
name|sbi
parameter_list|,
name|v
parameter_list|)
value|((sbi)->s_v1.s_bmap_nr = htole16(v))
end_define

begin_comment
comment|/* Definitions of reiserfs on-disk properties: */
end_comment

begin_define
define|#
directive|define
name|REISERFS_3_5
value|0
end_define

begin_define
define|#
directive|define
name|REISERFS_3_6
value|1
end_define

begin_enum
enum|enum
name|reiserfs_mount_options
block|{
comment|/* Mount options */
name|REISERFS_LARGETAIL
block|,
comment|/* Large tails will be created in a session */
name|REISERFS_SMALLTAIL
block|,
comment|/* Small (for files less than block size) tails 				will be created in a session */
name|REPLAYONLY
block|,
comment|/* Replay journal and return 0. Use by fsck */
name|REISERFS_CONVERT
block|,
comment|/* -o conv: causes conversion of old format super 				block to the new format. If not specified - 				old partition will be dealt with in a manner 				of 3.5.x */
comment|/* 	 * -o hash={tea, rupasov, r5, detect} is meant for properly mounting 	 * reiserfs disks from 3.5.19 or earlier. 99% of the time, this option 	 * is not required. If the normal autodection code can't determine 	 * which hash to use (because both hases had the same value for a 	 * file) use this option to force a specific hash. It won't allow you 	 * to override the existing hash on the FS, so if you have a tea hash 	 * disk, and mount with -o hash=rupasov, the mount will fail. 	 */
name|FORCE_TEA_HASH
block|,
comment|/* try to force tea hash on mount */
name|FORCE_RUPASOV_HASH
block|,
comment|/* try to force rupasov hash on mount */
name|FORCE_R5_HASH
block|,
comment|/* try to force rupasov hash on mount */
name|FORCE_HASH_DETECT
block|,
comment|/* try to detect hash function on mount */
name|REISERFS_DATA_LOG
block|,
name|REISERFS_DATA_ORDERED
block|,
name|REISERFS_DATA_WRITEBACK
block|,
comment|/* 	 * used for testing experimental features, makes benchmarking new 	 * features with and without more convenient, should never be used by 	 * users in any code shipped to users (ideally) 	 */
name|REISERFS_NO_BORDER
block|,
name|REISERFS_NO_UNHASHED_RELOCATION
block|,
name|REISERFS_HASHED_RELOCATION
block|,
name|REISERFS_ATTRS
block|,
name|REISERFS_XATTRS
block|,
name|REISERFS_XATTRS_USER
block|,
name|REISERFS_POSIXACL
block|,
name|REISERFS_TEST1
block|,
name|REISERFS_TEST2
block|,
name|REISERFS_TEST3
block|,
name|REISERFS_TEST4
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|reiserfs_r5_hash
parameter_list|(
name|sbi
parameter_list|)
define|\
value|(REISERFS_SB(sbi)->s_mount_opt& (1<< FORCE_R5_HASH))
end_define

begin_define
define|#
directive|define
name|reiserfs_rupasov_hash
parameter_list|(
name|sbi
parameter_list|)
define|\
value|(REISERFS_SB(sbi)->s_mount_opt& (1<< FORCE_RUPASOV_HASH))
end_define

begin_define
define|#
directive|define
name|reiserfs_tea_hash
parameter_list|(
name|sbi
parameter_list|)
define|\
value|(REISERFS_SB(sbi)->s_mount_opt& (1<< FORCE_TEA_HASH))
end_define

begin_define
define|#
directive|define
name|reiserfs_hash_detect
parameter_list|(
name|sbi
parameter_list|)
define|\
value|(REISERFS_SB(sbi)->s_mount_opt& (1<< FORCE_HASH_DETECT))
end_define

begin_define
define|#
directive|define
name|reiserfs_attrs
parameter_list|(
name|sbi
parameter_list|)
define|\
value|(REISERFS_SB(sbi)->s_mount_opt& (1<< REISERFS_ATTRS))
end_define

begin_define
define|#
directive|define
name|reiserfs_data_log
parameter_list|(
name|sbi
parameter_list|)
define|\
value|(REISERFS_SB(sbi)->s_mount_opt& (1<< REISERFS_DATA_LOG))
end_define

begin_define
define|#
directive|define
name|reiserfs_data_ordered
parameter_list|(
name|sbi
parameter_list|)
define|\
value|(REISERFS_SB(sbi)->s_mount_opt& (1<< REISERFS_DATA_ORDERED))
end_define

begin_define
define|#
directive|define
name|reiserfs_data_writeback
parameter_list|(
name|sbi
parameter_list|)
define|\
value|(REISERFS_SB(sbi)->s_mount_opt& (1<< REISERFS_DATA_WRITEBACK))
end_define

begin_define
define|#
directive|define
name|SB_BUFFER_WITH_SB
parameter_list|(
name|sbi
parameter_list|)
value|(REISERFS_SB(sbi)->s_sbh)
end_define

begin_define
define|#
directive|define
name|SB_AP_BITMAP
parameter_list|(
name|sbi
parameter_list|)
value|(REISERFS_SB(sbi)->s_ap_bitmap)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined _GNU_REISERFS_REISERFS_FS_SB_H */
end_comment

end_unit

