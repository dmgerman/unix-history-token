begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_DIR_SF_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_DIR_SF_H__
end_define

begin_comment
comment|/*  * Directory layout when stored internal to an inode.  *  * Small directories are packed as tightly as possible so as to  * fit into the literal area of the inode.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|__uint8_t
name|i
index|[
sizeof|sizeof
argument_list|(
name|xfs_ino_t
argument_list|)
index|]
decl_stmt|;
block|}
name|xfs_dir_ino_t
typedef|;
end_typedef

begin_comment
comment|/*  * The parent directory has a dedicated field, and the self-pointer must  * be calculated on the fly.  *  * Entries are packed toward the top as tight as possible.  The header  * and the elements much be memcpy'd out into a work area to get correct  * alignment for the inode number fields.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir_sf_hdr
block|{
comment|/* constant-structure header block */
name|xfs_dir_ino_t
name|parent
decl_stmt|;
comment|/* parent dir inode number */
name|__uint8_t
name|count
decl_stmt|;
comment|/* count of active entries */
block|}
name|xfs_dir_sf_hdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir_sf_entry
block|{
name|xfs_dir_ino_t
name|inumber
decl_stmt|;
comment|/* referenced inode number */
name|__uint8_t
name|namelen
decl_stmt|;
comment|/* actual length of name (no NULL) */
name|__uint8_t
name|name
index|[
literal|1
index|]
decl_stmt|;
comment|/* name */
block|}
name|xfs_dir_sf_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir_shortform
block|{
name|xfs_dir_sf_hdr_t
name|hdr
decl_stmt|;
name|xfs_dir_sf_entry_t
name|list
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable sized array */
block|}
name|xfs_dir_shortform_t
typedef|;
end_typedef

begin_comment
comment|/*  * We generate this then sort it, so that readdirs are returned in  * hash-order.  Else seekdir won't work.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir_sf_sort
block|{
name|__uint8_t
name|entno
decl_stmt|;
comment|/* .=0, ..=1, else entry# + 2 */
name|__uint8_t
name|seqno
decl_stmt|;
comment|/* sequence # with same hash value */
name|__uint8_t
name|namelen
decl_stmt|;
comment|/* length of name value (no null) */
name|xfs_dahash_t
name|hash
decl_stmt|;
comment|/* this entry's hash value */
name|xfs_intino_t
name|ino
decl_stmt|;
comment|/* this entry's inode number */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name value, pointer into buffer */
block|}
name|xfs_dir_sf_sort_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_DIR_SF_GET_DIRINO
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
value|xfs_dir_sf_get_dirino(from, to)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|xfs_dir_sf_get_dirino
parameter_list|(
name|xfs_dir_ino_t
modifier|*
name|from
parameter_list|,
name|xfs_ino_t
modifier|*
name|to
parameter_list|)
block|{
operator|*
operator|(
name|to
operator|)
operator|=
name|XFS_GET_DIR_INO8
argument_list|(
operator|*
name|from
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_DIR_SF_PUT_DIRINO
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
value|xfs_dir_sf_put_dirino(from, to)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|xfs_dir_sf_put_dirino
parameter_list|(
name|xfs_ino_t
modifier|*
name|from
parameter_list|,
name|xfs_dir_ino_t
modifier|*
name|to
parameter_list|)
block|{
name|XFS_PUT_DIR_INO8
argument_list|(
operator|*
operator|(
name|from
operator|)
argument_list|,
operator|*
operator|(
name|to
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_DIR_SF_ENTSIZE_BYNAME
parameter_list|(
name|len
parameter_list|)
value|xfs_dir_sf_entsize_byname(len)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|xfs_dir_sf_entsize_byname
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
name|xfs_dir_sf_entry_t
argument_list|)
operator|-
literal|1
operator|+
operator|(
name|len
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_DIR_SF_ENTSIZE_BYENTRY
parameter_list|(
name|sfep
parameter_list|)
value|xfs_dir_sf_entsize_byentry(sfep)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|xfs_dir_sf_entsize_byentry
parameter_list|(
name|xfs_dir_sf_entry_t
modifier|*
name|sfep
parameter_list|)
block|{
return|return
operator|(
name|uint
operator|)
sizeof|sizeof
argument_list|(
name|xfs_dir_sf_entry_t
argument_list|)
operator|-
literal|1
operator|+
operator|(
name|sfep
operator|)
operator|->
name|namelen
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_DIR_SF_NEXTENTRY
parameter_list|(
name|sfep
parameter_list|)
value|xfs_dir_sf_nextentry(sfep)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_dir_sf_entry_t
modifier|*
name|xfs_dir_sf_nextentry
parameter_list|(
name|xfs_dir_sf_entry_t
modifier|*
name|sfep
parameter_list|)
block|{
return|return
operator|(
name|xfs_dir_sf_entry_t
operator|*
operator|)
expr|\
operator|(
operator|(
name|char
operator|*
operator|)
operator|(
name|sfep
operator|)
operator|+
name|XFS_DIR_SF_ENTSIZE_BYENTRY
argument_list|(
name|sfep
argument_list|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_DIR_SF_ALLFIT
parameter_list|(
name|count
parameter_list|,
name|totallen
parameter_list|)
define|\
value|xfs_dir_sf_allfit(count,totallen)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|xfs_dir_sf_allfit
parameter_list|(
name|int
name|count
parameter_list|,
name|int
name|totallen
parameter_list|)
block|{
return|return
operator|(
operator|(
name|uint
operator|)
sizeof|sizeof
argument_list|(
name|xfs_dir_sf_hdr_t
argument_list|)
operator|+
expr|\
operator|(
operator|(
name|uint
operator|)
sizeof|sizeof
argument_list|(
name|xfs_dir_sf_entry_t
argument_list|)
operator|-
literal|1
operator|)
operator|*
operator|(
name|count
operator|)
operator|+
operator|(
name|totallen
operator|)
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XFS_DIR_TRACE
argument_list|)
end_if

begin_comment
comment|/*  * Kernel tracing support for directories.  */
end_comment

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_da_intnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_dinode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_dir_leafblock
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_dir_leaf_entry
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|XFS_DIR_TRACE_SIZE
value|4096
end_define

begin_comment
comment|/* size of global trace buffer */
end_comment

begin_decl_stmt
specifier|extern
name|ktrace_t
modifier|*
name|xfs_dir_trace_buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Trace record types.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR_KTRACE_G_DU
value|1
end_define

begin_comment
comment|/* dp, uio */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR_KTRACE_G_DUB
value|2
end_define

begin_comment
comment|/* dp, uio, bno */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR_KTRACE_G_DUN
value|3
end_define

begin_comment
comment|/* dp, uio, node */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR_KTRACE_G_DUL
value|4
end_define

begin_comment
comment|/* dp, uio, leaf */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR_KTRACE_G_DUE
value|5
end_define

begin_comment
comment|/* dp, uio, leaf entry */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR_KTRACE_G_DUC
value|6
end_define

begin_comment
comment|/* dp, uio, cookie */
end_comment

begin_function_decl
name|void
name|xfs_dir_trace_g_du
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
name|struct
name|xfs_inode
modifier|*
name|dp
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
name|xfs_dir_trace_g_dub
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
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
name|xfs_dablk_t
name|bno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_dir_trace_g_dun
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
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
name|struct
name|xfs_da_intnode
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_dir_trace_g_dul
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
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
name|struct
name|xfs_dir_leafblock
modifier|*
name|leaf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_dir_trace_g_due
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
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
name|struct
name|xfs_dir_leaf_entry
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_dir_trace_g_duc
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
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
name|xfs_off_t
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_dir_trace_enter
parameter_list|(
name|int
name|type
parameter_list|,
name|char
modifier|*
name|where
parameter_list|,
name|void
modifier|*
name|a0
parameter_list|,
name|void
modifier|*
name|a1
parameter_list|,
name|void
modifier|*
name|a2
parameter_list|,
name|void
modifier|*
name|a3
parameter_list|,
name|void
modifier|*
name|a4
parameter_list|,
name|void
modifier|*
name|a5
parameter_list|,
name|void
modifier|*
name|a6
parameter_list|,
name|void
modifier|*
name|a7
parameter_list|,
name|void
modifier|*
name|a8
parameter_list|,
name|void
modifier|*
name|a9
parameter_list|,
name|void
modifier|*
name|a10
parameter_list|,
name|void
modifier|*
name|a11
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xfs_dir_trace_g_du
parameter_list|(
name|w
parameter_list|,
name|d
parameter_list|,
name|u
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_dir_trace_g_dub
parameter_list|(
name|w
parameter_list|,
name|d
parameter_list|,
name|u
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_dir_trace_g_dun
parameter_list|(
name|w
parameter_list|,
name|d
parameter_list|,
name|u
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_dir_trace_g_dul
parameter_list|(
name|w
parameter_list|,
name|d
parameter_list|,
name|u
parameter_list|,
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_dir_trace_g_due
parameter_list|(
name|w
parameter_list|,
name|d
parameter_list|,
name|u
parameter_list|,
name|e
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_dir_trace_g_duc
parameter_list|(
name|w
parameter_list|,
name|d
parameter_list|,
name|u
parameter_list|,
name|c
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_DIR_SF_H__ */
end_comment

end_unit

