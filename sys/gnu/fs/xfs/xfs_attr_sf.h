begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2002,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_ATTR_SF_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_ATTR_SF_H__
end_define

begin_comment
comment|/*  * Attribute storage when stored inside the inode.  *  * Small attribute lists are packed as tightly as possible so as  * to fit into the literal area of the inode.  */
end_comment

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Entries are packed toward the top as tight as possible.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_attr_shortform
block|{
struct|struct
name|xfs_attr_sf_hdr
block|{
comment|/* constant-structure header block */
name|__be16
name|totsize
decl_stmt|;
comment|/* total bytes in shortform list */
name|__u8
name|count
decl_stmt|;
comment|/* count of active entries */
block|}
name|hdr
struct|;
struct|struct
name|xfs_attr_sf_entry
block|{
name|__uint8_t
name|namelen
decl_stmt|;
comment|/* actual length of name (no NULL) */
name|__uint8_t
name|valuelen
decl_stmt|;
comment|/* actual length of value (no NULL) */
name|__uint8_t
name|flags
decl_stmt|;
comment|/* flags bits (see xfs_attr_leaf.h) */
name|__uint8_t
name|nameval
index|[
literal|1
index|]
decl_stmt|;
comment|/* name& value bytes concatenated */
block|}
name|list
index|[
literal|1
index|]
struct|;
comment|/* variable sized array */
block|}
name|xfs_attr_shortform_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xfs_attr_sf_hdr
name|xfs_attr_sf_hdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xfs_attr_sf_entry
name|xfs_attr_sf_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * We generate this then sort it, attr_list() must return things in hash-order.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_attr_sf_sort
block|{
name|__uint8_t
name|entno
decl_stmt|;
comment|/* entry number in original list */
name|__uint8_t
name|namelen
decl_stmt|;
comment|/* length of name value (no null) */
name|__uint8_t
name|valuelen
decl_stmt|;
comment|/* length of value */
name|__uint8_t
name|flags
decl_stmt|;
comment|/* flags bits (see xfs_attr_leaf.h) */
name|xfs_dahash_t
name|hash
decl_stmt|;
comment|/* this entry's hash value */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name value, pointer into buffer */
block|}
name|xfs_attr_sf_sort_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_ATTR_SF_ENTSIZE_BYNAME
parameter_list|(
name|nlen
parameter_list|,
name|vlen
parameter_list|)
comment|/* space name/value uses */
define|\
value|(((int)sizeof(xfs_attr_sf_entry_t)-1 + (nlen)+(vlen)))
end_define

begin_define
define|#
directive|define
name|XFS_ATTR_SF_ENTSIZE_MAX
comment|/* max space for name&value */
define|\
value|((1<< (NBBY*(int)sizeof(__uint8_t))) - 1)
end_define

begin_define
define|#
directive|define
name|XFS_ATTR_SF_ENTSIZE
parameter_list|(
name|sfep
parameter_list|)
comment|/* space an entry uses */
define|\
value|((int)sizeof(xfs_attr_sf_entry_t)-1 + (sfep)->namelen+(sfep)->valuelen)
end_define

begin_define
define|#
directive|define
name|XFS_ATTR_SF_NEXTENTRY
parameter_list|(
name|sfep
parameter_list|)
comment|/* next entry in struct */
define|\
value|((xfs_attr_sf_entry_t *)((char *)(sfep) + XFS_ATTR_SF_ENTSIZE(sfep)))
end_define

begin_define
define|#
directive|define
name|XFS_ATTR_SF_TOTSIZE
parameter_list|(
name|dp
parameter_list|)
comment|/* total space in use */
define|\
value|(be16_to_cpu(((xfs_attr_shortform_t *)	\ 		((dp)->i_afp->if_u1.if_data))->hdr.totsize))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XFS_ATTR_TRACE
argument_list|)
end_if

begin_comment
comment|/*  * Kernel tracing support for attribute lists  */
end_comment

begin_struct_decl
struct_decl|struct
name|xfs_attr_list_context
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_da_intnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_da_node_entry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_attr_leafblock
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|XFS_ATTR_TRACE_SIZE
value|4096
end_define

begin_comment
comment|/* size of global trace buffer */
end_comment

begin_decl_stmt
specifier|extern
name|ktrace_t
modifier|*
name|xfs_attr_trace_buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Trace record types.  */
end_comment

begin_define
define|#
directive|define
name|XFS_ATTR_KTRACE_L_C
value|1
end_define

begin_comment
comment|/* context */
end_comment

begin_define
define|#
directive|define
name|XFS_ATTR_KTRACE_L_CN
value|2
end_define

begin_comment
comment|/* context, node */
end_comment

begin_define
define|#
directive|define
name|XFS_ATTR_KTRACE_L_CB
value|3
end_define

begin_comment
comment|/* context, btree */
end_comment

begin_define
define|#
directive|define
name|XFS_ATTR_KTRACE_L_CL
value|4
end_define

begin_comment
comment|/* context, leaf */
end_comment

begin_function_decl
name|void
name|xfs_attr_trace_l_c
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
name|struct
name|xfs_attr_list_context
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_attr_trace_l_cn
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
name|struct
name|xfs_attr_list_context
modifier|*
name|context
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
name|xfs_attr_trace_l_cb
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
name|struct
name|xfs_attr_list_context
modifier|*
name|context
parameter_list|,
name|struct
name|xfs_da_node_entry
modifier|*
name|btree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_attr_trace_l_cl
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
name|struct
name|xfs_attr_list_context
modifier|*
name|context
parameter_list|,
name|struct
name|xfs_attr_leafblock
modifier|*
name|leaf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_attr_trace_enter
parameter_list|(
name|int
name|type
parameter_list|,
name|char
modifier|*
name|where
parameter_list|,
name|__psunsigned_t
name|a2
parameter_list|,
name|__psunsigned_t
name|a3
parameter_list|,
name|__psunsigned_t
name|a4
parameter_list|,
name|__psunsigned_t
name|a5
parameter_list|,
name|__psunsigned_t
name|a6
parameter_list|,
name|__psunsigned_t
name|a7
parameter_list|,
name|__psunsigned_t
name|a8
parameter_list|,
name|__psunsigned_t
name|a9
parameter_list|,
name|__psunsigned_t
name|a10
parameter_list|,
name|__psunsigned_t
name|a11
parameter_list|,
name|__psunsigned_t
name|a12
parameter_list|,
name|__psunsigned_t
name|a13
parameter_list|,
name|__psunsigned_t
name|a14
parameter_list|,
name|__psunsigned_t
name|a15
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
name|xfs_attr_trace_l_c
parameter_list|(
name|w
parameter_list|,
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_attr_trace_l_cn
parameter_list|(
name|w
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_attr_trace_l_cb
parameter_list|(
name|w
parameter_list|,
name|c
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_attr_trace_l_cl
parameter_list|(
name|w
parameter_list|,
name|c
parameter_list|,
name|l
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XFS_ATTR_TRACE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_ATTR_SF_H__ */
end_comment

end_unit

