begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2002-2003,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_ATTR_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_ATTR_H__
end_define

begin_comment
comment|/*  * xfs_attr.h  *  * Large attribute lists are structured around Btrees where all the data  * elements are in the leaf nodes.  Attribute names are hashed into an int,  * then that int is used as the index into the Btree.  Since the hashval  * of an attribute name may not be unique, we may have duplicate keys.  * The internal links in the Btree are logical block offsets into the file.  *  * Small attribute lists use a different format and are packed as tightly  * as possible so as to fit into the literal area of the inode.  */
end_comment

begin_comment
comment|/*========================================================================  * External interfaces  *========================================================================*/
end_comment

begin_struct_decl
struct_decl|struct
name|cred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_vnode
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|attrset_t
function_decl|)
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|attrget_t
function_decl|)
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|attrremove_t
function_decl|)
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|attrexists_t
function_decl|)
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|attrcapable_t
function_decl|)
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|struct
name|cred
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|attrnames
block|{
name|char
modifier|*
name|attr_name
decl_stmt|;
name|unsigned
name|int
name|attr_namelen
decl_stmt|;
name|unsigned
name|int
name|attr_flag
decl_stmt|;
name|attrget_t
name|attr_get
decl_stmt|;
name|attrset_t
name|attr_set
decl_stmt|;
name|attrremove_t
name|attr_remove
decl_stmt|;
name|attrexists_t
name|attr_exists
decl_stmt|;
name|attrcapable_t
name|attr_capable
decl_stmt|;
block|}
name|attrnames_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATTR_NAMECOUNT
value|4
end_define

begin_decl_stmt
specifier|extern
name|struct
name|attrnames
name|attr_user
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|attrnames
name|attr_secure
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|attrnames
name|attr_system
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|attrnames
name|attr_trusted
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|attrnames
modifier|*
name|attr_namespaces
index|[
name|ATTR_NAMECOUNT
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|attrnames_t
modifier|*
name|attr_lookup_namespace
parameter_list|(
name|char
modifier|*
parameter_list|,
name|attrnames_t
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|attr_generic_list
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|ssize_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ATTR_DONTFOLLOW
value|0x0001
end_define

begin_comment
comment|/* -- unused, from IRIX -- */
end_comment

begin_define
define|#
directive|define
name|ATTR_ROOT
value|0x0002
end_define

begin_comment
comment|/* use attrs in root (trusted) namespace */
end_comment

begin_define
define|#
directive|define
name|ATTR_TRUST
value|0x0004
end_define

begin_comment
comment|/* -- unused, from IRIX -- */
end_comment

begin_define
define|#
directive|define
name|ATTR_SECURE
value|0x0008
end_define

begin_comment
comment|/* use attrs in security namespace */
end_comment

begin_define
define|#
directive|define
name|ATTR_CREATE
value|0x0010
end_define

begin_comment
comment|/* pure create: fail if attr already exists */
end_comment

begin_define
define|#
directive|define
name|ATTR_REPLACE
value|0x0020
end_define

begin_comment
comment|/* pure set: fail if attr does not exist */
end_comment

begin_define
define|#
directive|define
name|ATTR_SYSTEM
value|0x0100
end_define

begin_comment
comment|/* use attrs in system (pseudo) namespace */
end_comment

begin_define
define|#
directive|define
name|ATTR_KERNACCESS
value|0x0400
end_define

begin_comment
comment|/* [kernel] iaccess, inode held io-locked */
end_comment

begin_define
define|#
directive|define
name|ATTR_KERNOTIME
value|0x1000
end_define

begin_comment
comment|/* [kernel] don't update inode timestamps */
end_comment

begin_define
define|#
directive|define
name|ATTR_KERNOVAL
value|0x2000
end_define

begin_comment
comment|/* [kernel] get attr size only, not value */
end_comment

begin_define
define|#
directive|define
name|ATTR_KERNAMELS
value|0x4000
end_define

begin_comment
comment|/* [kernel] list attr names (simple list) */
end_comment

begin_define
define|#
directive|define
name|ATTR_KERNORMALS
value|0x0800
end_define

begin_comment
comment|/* [kernel] normal attr list: user+secure */
end_comment

begin_define
define|#
directive|define
name|ATTR_KERNROOTLS
value|0x8000
end_define

begin_comment
comment|/* [kernel] include root in the attr list */
end_comment

begin_define
define|#
directive|define
name|ATTR_KERNFULLS
value|(ATTR_KERNORMALS|ATTR_KERNROOTLS)
end_define

begin_comment
comment|/*  * The maximum size (into the kernel or returned from the kernel) of an  * attribute value or the buffer used for an attr_list() call.  Larger  * sizes will result in an ERANGE return code.  */
end_comment

begin_define
define|#
directive|define
name|ATTR_MAX_VALUELEN
value|(64*1024)
end_define

begin_comment
comment|/* max length of a value */
end_comment

begin_comment
comment|/*  * Define how lists of attribute names are returned to the user from  * the attr_list() call.  A large, 32bit aligned, buffer is passed in  * along with its size.  We put an array of offsets at the top that each  * reference an attrlist_ent_t and pack the attrlist_ent_t's at the bottom.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|attrlist
block|{
name|__s32
name|al_count
decl_stmt|;
comment|/* number of entries in attrlist */
name|__s32
name|al_more
decl_stmt|;
comment|/* T/F: more attrs (do call again) */
name|__s32
name|al_offset
index|[
literal|1
index|]
decl_stmt|;
comment|/* byte offsets of attrs [var-sized] */
block|}
name|attrlist_t
typedef|;
end_typedef

begin_comment
comment|/*  * Show the interesting info about one attribute.  This is what the  * al_offset[i] entry points to.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|attrlist_ent
block|{
comment|/* data from attr_list() */
name|__u32
name|a_valuelen
decl_stmt|;
comment|/* number bytes in value of attr */
name|char
name|a_name
index|[
literal|1
index|]
decl_stmt|;
comment|/* attr name (NULL terminated) */
block|}
name|attrlist_ent_t
typedef|;
end_typedef

begin_comment
comment|/*  * Given a pointer to the (char*) buffer containing the attr_list() result,  * and an index, return a pointer to the indicated attribute in the buffer.  */
end_comment

begin_define
define|#
directive|define
name|ATTR_ENTRY
parameter_list|(
name|buffer
parameter_list|,
name|index
parameter_list|)
define|\
value|((attrlist_ent_t *)			\&((char *)buffer)[ ((attrlist_t *)(buffer))->al_offset[index] ])
end_define

begin_comment
comment|/*  * Multi-attribute operation vector.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|attr_multiop
block|{
name|int
name|am_opcode
decl_stmt|;
comment|/* operation to perform (ATTR_OP_GET, etc.) */
name|int
name|am_error
decl_stmt|;
comment|/* [out arg] result of this sub-op (an errno) */
name|char
modifier|*
name|am_attrname
decl_stmt|;
comment|/* attribute name to work with */
name|char
modifier|*
name|am_attrvalue
decl_stmt|;
comment|/* [in/out arg] attribute value (raw bytes) */
name|int
name|am_length
decl_stmt|;
comment|/* [in/out arg] length of value */
name|int
name|am_flags
decl_stmt|;
comment|/* bitwise OR of attr API flags defined above */
block|}
name|attr_multiop_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATTR_OP_GET
value|1
end_define

begin_comment
comment|/* return the indicated attr's value */
end_comment

begin_define
define|#
directive|define
name|ATTR_OP_SET
value|2
end_define

begin_comment
comment|/* set/create the indicated attr/value pair */
end_comment

begin_define
define|#
directive|define
name|ATTR_OP_REMOVE
value|3
end_define

begin_comment
comment|/* remove the indicated attr */
end_comment

begin_comment
comment|/*  * Kernel-internal version of the attrlist cursor.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|attrlist_cursor_kern
block|{
name|__u32
name|hashval
decl_stmt|;
comment|/* hash value of next entry to add */
name|__u32
name|blkno
decl_stmt|;
comment|/* block containing entry (suggestion) */
name|__u32
name|offset
decl_stmt|;
comment|/* offset in list of equal-hashvals */
name|__u16
name|pad1
decl_stmt|;
comment|/* padding to match user-level */
name|__u8
name|pad2
decl_stmt|;
comment|/* padding to match user-level */
name|__u8
name|initted
decl_stmt|;
comment|/* T/F: cursor has been initialized */
block|}
name|attrlist_cursor_kern_t
typedef|;
end_typedef

begin_comment
comment|/*========================================================================  * Function prototypes for the kernel.  *========================================================================*/
end_comment

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|attrlist_cursor_kern
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_da_args
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Overall external interface routines.  */
end_comment

begin_function_decl
name|int
name|xfs_attr_get
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|cred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_set
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|cred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_remove
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|cred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_list
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|attrlist_cursor_kern
modifier|*
parameter_list|,
name|struct
name|cred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_inactive
parameter_list|(
name|struct
name|xfs_inode
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_shortform_getvalue
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_attr_fetch
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|cred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_ATTR_H__ */
end_comment

end_unit

