begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_EXTFREE_ITEM_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_EXTFREE_ITEM_H__
end_define

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|kmem_zone
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|xfs_extent
block|{
name|xfs_dfsbno_t
name|ext_start
decl_stmt|;
name|xfs_extlen_t
name|ext_len
decl_stmt|;
block|}
name|xfs_extent_t
typedef|;
end_typedef

begin_comment
comment|/*  * This is the structure used to lay out an efi log item in the  * log.  The efi_extents field is a variable size array whose  * size is given by efi_nextents.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_efi_log_format
block|{
name|unsigned
name|short
name|efi_type
decl_stmt|;
comment|/* efi log item type */
name|unsigned
name|short
name|efi_size
decl_stmt|;
comment|/* size of this item */
name|uint
name|efi_nextents
decl_stmt|;
comment|/* # extents to free */
name|__uint64_t
name|efi_id
decl_stmt|;
comment|/* efi identifier */
name|xfs_extent_t
name|efi_extents
index|[
literal|1
index|]
decl_stmt|;
comment|/* array of extents to free */
block|}
name|xfs_efi_log_format_t
typedef|;
end_typedef

begin_comment
comment|/*  * This is the structure used to lay out an efd log item in the  * log.  The efd_extents array is a variable size array whose  * size is given by efd_nextents;  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_efd_log_format
block|{
name|unsigned
name|short
name|efd_type
decl_stmt|;
comment|/* efd log item type */
name|unsigned
name|short
name|efd_size
decl_stmt|;
comment|/* size of this item */
name|uint
name|efd_nextents
decl_stmt|;
comment|/* # of extents freed */
name|__uint64_t
name|efd_efi_id
decl_stmt|;
comment|/* id of corresponding efi */
name|xfs_extent_t
name|efd_extents
index|[
literal|1
index|]
decl_stmt|;
comment|/* array of extents freed */
block|}
name|xfs_efd_log_format_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/*  * Max number of extents in fast allocation path.  */
end_comment

begin_define
define|#
directive|define
name|XFS_EFI_MAX_FAST_EXTENTS
value|16
end_define

begin_comment
comment|/*  * Define EFI flags.  */
end_comment

begin_define
define|#
directive|define
name|XFS_EFI_RECOVERED
value|0x1
end_define

begin_define
define|#
directive|define
name|XFS_EFI_COMMITTED
value|0x2
end_define

begin_define
define|#
directive|define
name|XFS_EFI_CANCELED
value|0x4
end_define

begin_comment
comment|/*  * This is the "extent free intention" log item.  It is used  * to log the fact that some extents need to be free.  It is  * used in conjunction with the "extent free done" log item  * described below.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_efi_log_item
block|{
name|xfs_log_item_t
name|efi_item
decl_stmt|;
name|uint
name|efi_flags
decl_stmt|;
comment|/* misc flags */
name|uint
name|efi_next_extent
decl_stmt|;
name|xfs_efi_log_format_t
name|efi_format
decl_stmt|;
block|}
name|xfs_efi_log_item_t
typedef|;
end_typedef

begin_comment
comment|/*  * This is the "extent free done" log item.  It is used to log  * the fact that some extents earlier mentioned in an efi item  * have been freed.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_efd_log_item
block|{
name|xfs_log_item_t
name|efd_item
decl_stmt|;
name|xfs_efi_log_item_t
modifier|*
name|efd_efip
decl_stmt|;
name|uint
name|efd_next_extent
decl_stmt|;
name|xfs_efd_log_format_t
name|efd_format
decl_stmt|;
block|}
name|xfs_efd_log_item_t
typedef|;
end_typedef

begin_comment
comment|/*  * Max number of extents in fast allocation path.  */
end_comment

begin_define
define|#
directive|define
name|XFS_EFD_MAX_FAST_EXTENTS
value|16
end_define

begin_decl_stmt
specifier|extern
name|struct
name|kmem_zone
modifier|*
name|xfs_efi_zone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|kmem_zone
modifier|*
name|xfs_efd_zone
decl_stmt|;
end_decl_stmt

begin_function_decl
name|xfs_efi_log_item_t
modifier|*
name|xfs_efi_init
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_efd_log_item_t
modifier|*
name|xfs_efd_init
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|xfs_efi_log_item_t
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_efi_item_free
parameter_list|(
name|xfs_efi_log_item_t
modifier|*
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
comment|/* __XFS_EXTFREE_ITEM_H__ */
end_comment

end_unit

