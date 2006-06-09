begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2002,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_TRANS_PRIV_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_TRANS_PRIV_H__
end_define

begin_struct_decl
struct_decl|struct
name|xfs_log_item
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_log_item_desc
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
comment|/*  * From xfs_trans_item.c  */
end_comment

begin_function_decl
name|struct
name|xfs_log_item_desc
modifier|*
name|xfs_trans_add_item
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|struct
name|xfs_log_item
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_free_item
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|struct
name|xfs_log_item_desc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|xfs_log_item_desc
modifier|*
name|xfs_trans_find_item
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|struct
name|xfs_log_item
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|xfs_log_item_desc
modifier|*
name|xfs_trans_first_item
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|xfs_log_item_desc
modifier|*
name|xfs_trans_next_item
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|struct
name|xfs_log_item_desc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_free_items
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_unlock_items
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|xfs_lsn_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_free_busy
parameter_list|(
name|xfs_trans_t
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|xfs_log_busy_slot_t		*xfs_trans_add_busy(xfs_trans_t *tp, 						    xfs_agnumber_t ag, 						    xfs_extlen_t idx);
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * From xfs_trans_ail.c  */
end_comment

begin_function_decl
name|void
name|xfs_trans_update_ail
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|struct
name|xfs_log_item
modifier|*
parameter_list|,
name|xfs_lsn_t
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_delete_ail
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|struct
name|xfs_log_item
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|xfs_log_item
modifier|*
name|xfs_trans_first_ail
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|xfs_log_item
modifier|*
name|xfs_trans_next_ail
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|struct
name|xfs_log_item
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_TRANS_PRIV_H__ */
end_comment

end_unit

