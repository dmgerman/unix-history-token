begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2002,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_MAC_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_MAC_H__
end_define

begin_comment
comment|/*  * Mandatory Access Control  *  * Layout of a composite MAC label:  * ml_list contains the list of categories (MSEN) followed by the list of  * divisions (MINT). This is actually a header for the data structure which  * will have an ml_list with more than one element.  *  *      -------------------------------  *      | ml_msen_type | ml_mint_type |  *      -------------------------------  *      | ml_level     | ml_grade     |  *      -------------------------------  *      | ml_catcount                 |  *      -------------------------------  *      | ml_divcount                 |  *      -------------------------------  *      | category 1                  |  *      | . . .                       |  *      | category N                  | (where N = ml_catcount)  *      -------------------------------  *      | division 1                  |  *      | . . .                       |  *      | division M                  | (where M = ml_divcount)  *      -------------------------------  */
end_comment

begin_define
define|#
directive|define
name|XFS_MAC_MAX_SETS
value|250
end_define

begin_typedef
typedef|typedef
struct|struct
name|xfs_mac_label
block|{
name|__uint8_t
name|ml_msen_type
decl_stmt|;
comment|/* MSEN label type */
name|__uint8_t
name|ml_mint_type
decl_stmt|;
comment|/* MINT label type */
name|__uint8_t
name|ml_level
decl_stmt|;
comment|/* Hierarchical level */
name|__uint8_t
name|ml_grade
decl_stmt|;
comment|/* Hierarchical grade */
name|__uint16_t
name|ml_catcount
decl_stmt|;
comment|/* Category count */
name|__uint16_t
name|ml_divcount
decl_stmt|;
comment|/* Division count */
comment|/* Category set, then Division set */
name|__uint16_t
name|ml_list
index|[
name|XFS_MAC_MAX_SETS
index|]
decl_stmt|;
block|}
name|xfs_mac_label_t
typedef|;
end_typedef

begin_comment
comment|/* MSEN label type names. Choose an upper case ASCII character.  */
end_comment

begin_define
define|#
directive|define
name|XFS_MSEN_ADMIN_LABEL
value|'A'
end_define

begin_comment
comment|/* Admin: low<admin != tcsec<high */
end_comment

begin_define
define|#
directive|define
name|XFS_MSEN_EQUAL_LABEL
value|'E'
end_define

begin_comment
comment|/* Wildcard - always equal */
end_comment

begin_define
define|#
directive|define
name|XFS_MSEN_HIGH_LABEL
value|'H'
end_define

begin_comment
comment|/* System High - always dominates */
end_comment

begin_define
define|#
directive|define
name|XFS_MSEN_MLD_HIGH_LABEL
value|'I'
end_define

begin_comment
comment|/* System High, multi-level dir */
end_comment

begin_define
define|#
directive|define
name|XFS_MSEN_LOW_LABEL
value|'L'
end_define

begin_comment
comment|/* System Low - always dominated */
end_comment

begin_define
define|#
directive|define
name|XFS_MSEN_MLD_LABEL
value|'M'
end_define

begin_comment
comment|/* TCSEC label on a multi-level dir */
end_comment

begin_define
define|#
directive|define
name|XFS_MSEN_MLD_LOW_LABEL
value|'N'
end_define

begin_comment
comment|/* System Low, multi-level dir */
end_comment

begin_define
define|#
directive|define
name|XFS_MSEN_TCSEC_LABEL
value|'T'
end_define

begin_comment
comment|/* TCSEC label */
end_comment

begin_define
define|#
directive|define
name|XFS_MSEN_UNKNOWN_LABEL
value|'U'
end_define

begin_comment
comment|/* unknown label */
end_comment

begin_comment
comment|/* MINT label type names. Choose a lower case ASCII character.  */
end_comment

begin_define
define|#
directive|define
name|XFS_MINT_BIBA_LABEL
value|'b'
end_define

begin_comment
comment|/* Dual of a TCSEC label */
end_comment

begin_define
define|#
directive|define
name|XFS_MINT_EQUAL_LABEL
value|'e'
end_define

begin_comment
comment|/* Wildcard - always equal */
end_comment

begin_define
define|#
directive|define
name|XFS_MINT_HIGH_LABEL
value|'h'
end_define

begin_comment
comment|/* High Grade - always dominates */
end_comment

begin_define
define|#
directive|define
name|XFS_MINT_LOW_LABEL
value|'l'
end_define

begin_comment
comment|/* Low Grade - always dominated */
end_comment

begin_comment
comment|/* On-disk XFS extended attribute names */
end_comment

begin_define
define|#
directive|define
name|SGI_MAC_FILE
value|"SGI_MAC_FILE"
end_define

begin_define
define|#
directive|define
name|SGI_MAC_FILE_SIZE
value|(sizeof(SGI_MAC_FILE)-1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_FS_POSIX_MAC
end_ifdef

begin_comment
comment|/* NOT YET IMPLEMENTED */
end_comment

begin_define
define|#
directive|define
name|MACEXEC
value|00100
end_define

begin_define
define|#
directive|define
name|MACWRITE
value|00200
end_define

begin_define
define|#
directive|define
name|MACREAD
value|00400
end_define

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|xfs_mac_iaccess
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|mode_t
parameter_list|,
name|cred_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_MAC_XFS_IACCESS
parameter_list|(
name|i
parameter_list|,
name|m
parameter_list|,
name|c
parameter_list|)
value|(xfs_mac_iaccess(i,m,c))
end_define

begin_define
define|#
directive|define
name|_MAC_VACCESS
parameter_list|(
name|v
parameter_list|,
name|c
parameter_list|,
name|m
parameter_list|)
value|(xfs_mac_vaccess(v,c,m))
end_define

begin_define
define|#
directive|define
name|_MAC_EXISTS
value|xfs_mac_vhaslabel
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_MAC_XFS_IACCESS
parameter_list|(
name|i
parameter_list|,
name|m
parameter_list|,
name|c
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|_MAC_VACCESS
parameter_list|(
name|v
parameter_list|,
name|c
parameter_list|,
name|m
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|_MAC_EXISTS
value|(NULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* __XFS_MAC_H__ */
end_comment

end_unit

