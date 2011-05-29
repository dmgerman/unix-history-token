begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1988, 2010, Oracle and/or its affiliates. All rights reserved.  */
end_comment

begin_comment
comment|/*	Copyright (c) 1983, 1984, 1985, 1986, 1987, 1988, 1989 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved  	*/
end_comment

begin_comment
comment|/*  * University Copyright- Copyright (c) 1982, 1986, 1988  * The Regents of the University of California  * All Rights Reserved  *  * University Acknowledgment- Portions of this document are derived from  * software developed by the University of California, Berkeley, and its  * contributors.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_VNODE_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VNODE_H
end_define

begin_empty
empty|#include_next<sys/vnode.h>
end_empty

begin_define
define|#
directive|define
name|IS_DEVVP
parameter_list|(
name|vp
parameter_list|)
define|\
value|((vp)->v_type == VCHR || (vp)->v_type == VBLK || (vp)->v_type == VFIFO)
end_define

begin_define
define|#
directive|define
name|V_XATTRDIR
value|0x0000
end_define

begin_comment
comment|/* attribute unnamed directory */
end_comment

begin_define
define|#
directive|define
name|AV_SCANSTAMP_SZ
value|32
end_define

begin_comment
comment|/* length of anti-virus scanstamp */
end_comment

begin_comment
comment|/*  * Structure of all optional attributes.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xoptattr
block|{
name|timestruc_t
name|xoa_createtime
decl_stmt|;
comment|/* Create time of file */
name|uint8_t
name|xoa_archive
decl_stmt|;
name|uint8_t
name|xoa_system
decl_stmt|;
name|uint8_t
name|xoa_readonly
decl_stmt|;
name|uint8_t
name|xoa_hidden
decl_stmt|;
name|uint8_t
name|xoa_nounlink
decl_stmt|;
name|uint8_t
name|xoa_immutable
decl_stmt|;
name|uint8_t
name|xoa_appendonly
decl_stmt|;
name|uint8_t
name|xoa_nodump
decl_stmt|;
name|uint8_t
name|xoa_opaque
decl_stmt|;
name|uint8_t
name|xoa_av_quarantined
decl_stmt|;
name|uint8_t
name|xoa_av_modified
decl_stmt|;
name|uint8_t
name|xoa_av_scanstamp
index|[
name|AV_SCANSTAMP_SZ
index|]
decl_stmt|;
name|uint8_t
name|xoa_reparse
decl_stmt|;
name|uint64_t
name|xoa_generation
decl_stmt|;
name|uint8_t
name|xoa_offline
decl_stmt|;
name|uint8_t
name|xoa_sparse
decl_stmt|;
block|}
name|xoptattr_t
typedef|;
end_typedef

begin_comment
comment|/*  * The xvattr structure is really a variable length structure that  * is made up of:  * - The classic vattr_t (xva_vattr)  * - a 32 bit quantity (xva_mapsize) that specifies the size of the  *   attribute bitmaps in 32 bit words.  * - A pointer to the returned attribute bitmap (needed because the  *   previous element, the requested attribute bitmap) is variable lenth.  * - The requested attribute bitmap, which is an array of 32 bit words.  *   Callers use the XVA_SET_REQ() macro to set the bits corresponding to  *   the attributes that are being requested.  * - The returned attribute bitmap, which is an array of 32 bit words.  *   File systems that support optional attributes use the XVA_SET_RTN()  *   macro to set the bits corresponding to the attributes that are being  *   returned.  * - The xoptattr_t structure which contains the attribute values  *  * xva_mapsize determines how many words in the attribute bitmaps.  * Immediately following the attribute bitmaps is the xoptattr_t.  * xva_getxoptattr() is used to get the pointer to the xoptattr_t  * section.  */
end_comment

begin_define
define|#
directive|define
name|XVA_MAPSIZE
value|3
end_define

begin_comment
comment|/* Size of attr bitmaps */
end_comment

begin_define
define|#
directive|define
name|XVA_MAGIC
value|0x78766174
end_define

begin_comment
comment|/* Magic # for verification */
end_comment

begin_comment
comment|/*  * The xvattr structure is an extensible structure which permits optional  * attributes to be requested/returned.  File systems may or may not support  * optional attributes.  They do so at their own discretion but if they do  * support optional attributes, they must register the VFSFT_XVATTR feature  * so that the optional attributes can be set/retrived.  *  * The fields of the xvattr structure are:  *  * xva_vattr - The first element of an xvattr is a legacy vattr structure  * which includes the common attributes.  If AT_XVATTR is set in the va_mask  * then the entire structure is treated as an xvattr.  If AT_XVATTR is not  * set, then only the xva_vattr structure can be used.  *  * xva_magic - 0x78766174 (hex for "xvat"). Magic number for verification.  *  * xva_mapsize - Size of requested and returned attribute bitmaps.  *  * xva_rtnattrmapp - Pointer to xva_rtnattrmap[].  We need this since the  * size of the array before it, xva_reqattrmap[], could change which means  * the location of xva_rtnattrmap[] could change.  This will allow unbundled  * file systems to find the location of xva_rtnattrmap[] when the sizes change.  *  * xva_reqattrmap[] - Array of requested attributes.  Attributes are  * represented by a specific bit in a specific element of the attribute  * map array.  Callers set the bits corresponding to the attributes  * that the caller wants to get/set.  *  * xva_rtnattrmap[] - Array of attributes that the file system was able to  * process.  Not all file systems support all optional attributes.  This map  * informs the caller which attributes the underlying file system was able  * to set/get.  (Same structure as the requested attributes array in terms  * of each attribute  corresponding to specific bits and array elements.)  *  * xva_xoptattrs - Structure containing values of optional attributes.  * These values are only valid if the corresponding bits in xva_reqattrmap  * are set and the underlying file system supports those attributes.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xvattr
block|{
name|vattr_t
name|xva_vattr
decl_stmt|;
comment|/* Embedded vattr structure */
name|uint32_t
name|xva_magic
decl_stmt|;
comment|/* Magic Number */
name|uint32_t
name|xva_mapsize
decl_stmt|;
comment|/* Size of attr bitmap (32-bit words) */
name|uint32_t
modifier|*
name|xva_rtnattrmapp
decl_stmt|;
comment|/* Ptr to xva_rtnattrmap[] */
name|uint32_t
name|xva_reqattrmap
index|[
name|XVA_MAPSIZE
index|]
decl_stmt|;
comment|/* Requested attrs */
name|uint32_t
name|xva_rtnattrmap
index|[
name|XVA_MAPSIZE
index|]
decl_stmt|;
comment|/* Returned attrs */
name|xoptattr_t
name|xva_xoptattrs
decl_stmt|;
comment|/* Optional attributes */
block|}
name|xvattr_t
typedef|;
end_typedef

begin_comment
comment|/*  * Attributes of interest to the caller of setattr or getattr.  */
end_comment

begin_define
define|#
directive|define
name|AT_TYPE
value|0x00001
end_define

begin_define
define|#
directive|define
name|AT_MODE
value|0x00002
end_define

begin_define
define|#
directive|define
name|AT_UID
value|0x00004
end_define

begin_define
define|#
directive|define
name|AT_GID
value|0x00008
end_define

begin_define
define|#
directive|define
name|AT_FSID
value|0x00010
end_define

begin_define
define|#
directive|define
name|AT_NODEID
value|0x00020
end_define

begin_define
define|#
directive|define
name|AT_NLINK
value|0x00040
end_define

begin_define
define|#
directive|define
name|AT_SIZE
value|0x00080
end_define

begin_define
define|#
directive|define
name|AT_ATIME
value|0x00100
end_define

begin_define
define|#
directive|define
name|AT_MTIME
value|0x00200
end_define

begin_define
define|#
directive|define
name|AT_CTIME
value|0x00400
end_define

begin_define
define|#
directive|define
name|AT_RDEV
value|0x00800
end_define

begin_define
define|#
directive|define
name|AT_BLKSIZE
value|0x01000
end_define

begin_define
define|#
directive|define
name|AT_NBLOCKS
value|0x02000
end_define

begin_comment
comment|/*			0x04000 */
end_comment

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|AT_SEQ
value|0x08000
end_define

begin_comment
comment|/*  * If AT_XVATTR is set then there are additional bits to process in  * the xvattr_t's attribute bitmap.  If this is not set then the bitmap  * MUST be ignored.  Note that this bit must be set/cleared explicitly.  * That is, setting AT_ALL will NOT set AT_XVATTR.  */
end_comment

begin_define
define|#
directive|define
name|AT_XVATTR
value|0x10000
end_define

begin_define
define|#
directive|define
name|AT_ALL
value|(AT_TYPE|AT_MODE|AT_UID|AT_GID|AT_FSID|AT_NODEID|\ 			AT_NLINK|AT_SIZE|AT_ATIME|AT_MTIME|AT_CTIME|\ 			AT_RDEV|AT_BLKSIZE|AT_NBLOCKS|AT_SEQ)
end_define

begin_define
define|#
directive|define
name|AT_STAT
value|(AT_MODE|AT_UID|AT_GID|AT_FSID|AT_NODEID|AT_NLINK|\ 			AT_SIZE|AT_ATIME|AT_MTIME|AT_CTIME|AT_RDEV|AT_TYPE)
end_define

begin_define
define|#
directive|define
name|AT_TIMES
value|(AT_ATIME|AT_MTIME|AT_CTIME)
end_define

begin_define
define|#
directive|define
name|AT_NOSET
value|(AT_NLINK|AT_RDEV|AT_FSID|AT_NODEID|AT_TYPE|\ 			AT_BLKSIZE|AT_NBLOCKS|AT_SEQ)
end_define

begin_comment
comment|/*  * Attribute bits used in the extensible attribute's (xva's) attribute  * bitmaps.  Note that the bitmaps are made up of a variable length number  * of 32-bit words.  The convention is to use XAT{n}_{attrname} where "n"  * is the element in the bitmap (starting at 1).  This convention is for  * the convenience of the maintainer to keep track of which element each  * attribute belongs to.  *  * NOTE THAT CONSUMERS MUST *NOT* USE THE XATn_* DEFINES DIRECTLY.  CONSUMERS  * MUST USE THE XAT_* DEFINES.  */
end_comment

begin_define
define|#
directive|define
name|XAT0_INDEX
value|0LL
end_define

begin_comment
comment|/* Index into bitmap for XAT0 attrs */
end_comment

begin_define
define|#
directive|define
name|XAT0_CREATETIME
value|0x00000001
end_define

begin_comment
comment|/* Create time of file */
end_comment

begin_define
define|#
directive|define
name|XAT0_ARCHIVE
value|0x00000002
end_define

begin_comment
comment|/* Archive */
end_comment

begin_define
define|#
directive|define
name|XAT0_SYSTEM
value|0x00000004
end_define

begin_comment
comment|/* System */
end_comment

begin_define
define|#
directive|define
name|XAT0_READONLY
value|0x00000008
end_define

begin_comment
comment|/* Readonly */
end_comment

begin_define
define|#
directive|define
name|XAT0_HIDDEN
value|0x00000010
end_define

begin_comment
comment|/* Hidden */
end_comment

begin_define
define|#
directive|define
name|XAT0_NOUNLINK
value|0x00000020
end_define

begin_comment
comment|/* Nounlink */
end_comment

begin_define
define|#
directive|define
name|XAT0_IMMUTABLE
value|0x00000040
end_define

begin_comment
comment|/* immutable */
end_comment

begin_define
define|#
directive|define
name|XAT0_APPENDONLY
value|0x00000080
end_define

begin_comment
comment|/* appendonly */
end_comment

begin_define
define|#
directive|define
name|XAT0_NODUMP
value|0x00000100
end_define

begin_comment
comment|/* nodump */
end_comment

begin_define
define|#
directive|define
name|XAT0_OPAQUE
value|0x00000200
end_define

begin_comment
comment|/* opaque */
end_comment

begin_define
define|#
directive|define
name|XAT0_AV_QUARANTINED
value|0x00000400
end_define

begin_comment
comment|/* anti-virus quarantine */
end_comment

begin_define
define|#
directive|define
name|XAT0_AV_MODIFIED
value|0x00000800
end_define

begin_comment
comment|/* anti-virus modified */
end_comment

begin_define
define|#
directive|define
name|XAT0_AV_SCANSTAMP
value|0x00001000
end_define

begin_comment
comment|/* anti-virus scanstamp */
end_comment

begin_define
define|#
directive|define
name|XAT0_REPARSE
value|0x00002000
end_define

begin_comment
comment|/* FS reparse point */
end_comment

begin_define
define|#
directive|define
name|XAT0_GEN
value|0x00004000
end_define

begin_comment
comment|/* object generation number */
end_comment

begin_define
define|#
directive|define
name|XAT0_OFFLINE
value|0x00008000
end_define

begin_comment
comment|/* offline */
end_comment

begin_define
define|#
directive|define
name|XAT0_SPARSE
value|0x00010000
end_define

begin_comment
comment|/* sparse */
end_comment

begin_define
define|#
directive|define
name|XAT0_ALL_ATTRS
value|(XAT0_CREATETIME|XAT0_ARCHIVE|XAT0_SYSTEM| \     XAT0_READONLY|XAT0_HIDDEN|XAT0_NOUNLINK|XAT0_IMMUTABLE|XAT0_APPENDONLY| \     XAT0_NODUMP|XAT0_OPAQUE|XAT0_AV_QUARANTINED|  XAT0_AV_MODIFIED| \     XAT0_AV_SCANSTAMP|XAT0_REPARSE|XATO_GEN|XAT0_OFFLINE|XAT0_SPARSE)
end_define

begin_comment
comment|/* Support for XAT_* optional attributes */
end_comment

begin_define
define|#
directive|define
name|XVA_MASK
value|0xffffffff
end_define

begin_comment
comment|/* Used to mask off 32 bits */
end_comment

begin_define
define|#
directive|define
name|XVA_SHFT
value|32
end_define

begin_comment
comment|/* Used to shift index */
end_comment

begin_comment
comment|/*  * Used to pry out the index and attribute bits from the XAT_* attributes  * defined below.  Note that we're masking things down to 32 bits then  * casting to uint32_t.  */
end_comment

begin_define
define|#
directive|define
name|XVA_INDEX
parameter_list|(
name|attr
parameter_list|)
value|((uint32_t)(((attr)>> XVA_SHFT)& XVA_MASK))
end_define

begin_define
define|#
directive|define
name|XVA_ATTRBIT
parameter_list|(
name|attr
parameter_list|)
value|((uint32_t)((attr)& XVA_MASK))
end_define

begin_comment
comment|/*  * The following defines present a "flat namespace" so that consumers don't  * need to keep track of which element belongs to which bitmap entry.  *  * NOTE THAT THESE MUST NEVER BE OR-ed TOGETHER  */
end_comment

begin_define
define|#
directive|define
name|XAT_CREATETIME
value|((XAT0_INDEX<< XVA_SHFT) | XAT0_CREATETIME)
end_define

begin_define
define|#
directive|define
name|XAT_ARCHIVE
value|((XAT0_INDEX<< XVA_SHFT) | XAT0_ARCHIVE)
end_define

begin_define
define|#
directive|define
name|XAT_SYSTEM
value|((XAT0_INDEX<< XVA_SHFT) | XAT0_SYSTEM)
end_define

begin_define
define|#
directive|define
name|XAT_READONLY
value|((XAT0_INDEX<< XVA_SHFT) | XAT0_READONLY)
end_define

begin_define
define|#
directive|define
name|XAT_HIDDEN
value|((XAT0_INDEX<< XVA_SHFT) | XAT0_HIDDEN)
end_define

begin_define
define|#
directive|define
name|XAT_NOUNLINK
value|((XAT0_INDEX<< XVA_SHFT) | XAT0_NOUNLINK)
end_define

begin_define
define|#
directive|define
name|XAT_IMMUTABLE
value|((XAT0_INDEX<< XVA_SHFT) | XAT0_IMMUTABLE)
end_define

begin_define
define|#
directive|define
name|XAT_APPENDONLY
value|((XAT0_INDEX<< XVA_SHFT) | XAT0_APPENDONLY)
end_define

begin_define
define|#
directive|define
name|XAT_NODUMP
value|((XAT0_INDEX<< XVA_SHFT) | XAT0_NODUMP)
end_define

begin_define
define|#
directive|define
name|XAT_OPAQUE
value|((XAT0_INDEX<< XVA_SHFT) | XAT0_OPAQUE)
end_define

begin_define
define|#
directive|define
name|XAT_AV_QUARANTINED
value|((XAT0_INDEX<< XVA_SHFT) | XAT0_AV_QUARANTINED)
end_define

begin_define
define|#
directive|define
name|XAT_AV_MODIFIED
value|((XAT0_INDEX<< XVA_SHFT) | XAT0_AV_MODIFIED)
end_define

begin_define
define|#
directive|define
name|XAT_AV_SCANSTAMP
value|((XAT0_INDEX<< XVA_SHFT) | XAT0_AV_SCANSTAMP)
end_define

begin_define
define|#
directive|define
name|XAT_REPARSE
value|((XAT0_INDEX<< XVA_SHFT) | XAT0_REPARSE)
end_define

begin_define
define|#
directive|define
name|XAT_GEN
value|((XAT0_INDEX<< XVA_SHFT) | XAT0_GEN)
end_define

begin_define
define|#
directive|define
name|XAT_OFFLINE
value|((XAT0_INDEX<< XVA_SHFT) | XAT0_OFFLINE)
end_define

begin_define
define|#
directive|define
name|XAT_SPARSE
value|((XAT0_INDEX<< XVA_SHFT) | XAT0_SPARSE)
end_define

begin_comment
comment|/*  * The returned attribute map array (xva_rtnattrmap[]) is located past the  * requested attribute map array (xva_reqattrmap[]).  Its location changes  * when the array sizes change.  We use a separate pointer in a known location  * (xva_rtnattrmapp) to hold the location of xva_rtnattrmap[].  This is  * set in xva_init()  */
end_comment

begin_define
define|#
directive|define
name|XVA_RTNATTRMAP
parameter_list|(
name|xvap
parameter_list|)
value|((xvap)->xva_rtnattrmapp)
end_define

begin_comment
comment|/*  * XVA_SET_REQ() sets an attribute bit in the proper element in the bitmap  * of requested attributes (xva_reqattrmap[]).  */
end_comment

begin_define
define|#
directive|define
name|XVA_SET_REQ
parameter_list|(
name|xvap
parameter_list|,
name|attr
parameter_list|)
define|\
value|ASSERT((xvap)->xva_vattr.va_mask | AT_XVATTR);		\ 	ASSERT((xvap)->xva_magic == XVA_MAGIC);			\ 	(xvap)->xva_reqattrmap[XVA_INDEX(attr)] |= XVA_ATTRBIT(attr)
end_define

begin_comment
comment|/*  * XVA_CLR_REQ() clears an attribute bit in the proper element in the bitmap  * of requested attributes (xva_reqattrmap[]).  */
end_comment

begin_define
define|#
directive|define
name|XVA_CLR_REQ
parameter_list|(
name|xvap
parameter_list|,
name|attr
parameter_list|)
define|\
value|ASSERT((xvap)->xva_vattr.va_mask | AT_XVATTR);		\ 	ASSERT((xvap)->xva_magic == XVA_MAGIC);			\ 	(xvap)->xva_reqattrmap[XVA_INDEX(attr)]&= ~XVA_ATTRBIT(attr)
end_define

begin_comment
comment|/*  * XVA_SET_RTN() sets an attribute bit in the proper element in the bitmap  * of returned attributes (xva_rtnattrmap[]).  */
end_comment

begin_define
define|#
directive|define
name|XVA_SET_RTN
parameter_list|(
name|xvap
parameter_list|,
name|attr
parameter_list|)
define|\
value|ASSERT((xvap)->xva_vattr.va_mask | AT_XVATTR);		\ 	ASSERT((xvap)->xva_magic == XVA_MAGIC);			\ 	(XVA_RTNATTRMAP(xvap))[XVA_INDEX(attr)] |= XVA_ATTRBIT(attr)
end_define

begin_comment
comment|/*  * XVA_ISSET_REQ() checks the requested attribute bitmap (xva_reqattrmap[])  * to see of the corresponding attribute bit is set.  If so, returns non-zero.  */
end_comment

begin_define
define|#
directive|define
name|XVA_ISSET_REQ
parameter_list|(
name|xvap
parameter_list|,
name|attr
parameter_list|)
define|\
value|((((xvap)->xva_vattr.va_mask | AT_XVATTR)&&			\ 		((xvap)->xva_magic == XVA_MAGIC)&&			\ 		((xvap)->xva_mapsize> XVA_INDEX(attr))) ?		\ 	((xvap)->xva_reqattrmap[XVA_INDEX(attr)]& XVA_ATTRBIT(attr)) :	0)
end_define

begin_comment
comment|/*  * XVA_ISSET_RTN() checks the returned attribute bitmap (xva_rtnattrmap[])  * to see of the corresponding attribute bit is set.  If so, returns non-zero.  */
end_comment

begin_define
define|#
directive|define
name|XVA_ISSET_RTN
parameter_list|(
name|xvap
parameter_list|,
name|attr
parameter_list|)
define|\
value|((((xvap)->xva_vattr.va_mask | AT_XVATTR)&&			\ 		((xvap)->xva_magic == XVA_MAGIC)&&			\ 		((xvap)->xva_mapsize> XVA_INDEX(attr))) ?		\ 	((XVA_RTNATTRMAP(xvap))[XVA_INDEX(attr)]& XVA_ATTRBIT(attr)) : 0)
end_define

begin_define
define|#
directive|define
name|MODEMASK
value|07777
end_define

begin_comment
comment|/* mode bits plus permission bits */
end_comment

begin_define
define|#
directive|define
name|PERMMASK
value|00777
end_define

begin_comment
comment|/* permission bits */
end_comment

begin_comment
comment|/*  * VOP_ACCESS flags  */
end_comment

begin_define
define|#
directive|define
name|V_ACE_MASK
value|0x1
end_define

begin_comment
comment|/* mask represents  NFSv4 ACE permissions */
end_comment

begin_comment
comment|/*  * Flags for vnode operations.  */
end_comment

begin_enum
enum|enum
name|rm
block|{
name|RMFILE
block|,
name|RMDIRECTORY
block|}
enum|;
end_enum

begin_comment
comment|/* rm or rmdir (remove) */
end_comment

begin_enum
enum|enum
name|create
block|{
name|CRCREAT
block|,
name|CRMKNOD
block|,
name|CRMKDIR
block|}
enum|;
end_enum

begin_comment
comment|/* reason for create */
end_comment

begin_comment
comment|/*  * Structure used on VOP_GETSECATTR and VOP_SETSECATTR operations  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vsecattr
block|{
name|uint_t
name|vsa_mask
decl_stmt|;
comment|/* See below */
name|int
name|vsa_aclcnt
decl_stmt|;
comment|/* ACL entry count */
name|void
modifier|*
name|vsa_aclentp
decl_stmt|;
comment|/* pointer to ACL entries */
name|int
name|vsa_dfaclcnt
decl_stmt|;
comment|/* default ACL entry count */
name|void
modifier|*
name|vsa_dfaclentp
decl_stmt|;
comment|/* pointer to default ACL entries */
name|size_t
name|vsa_aclentsz
decl_stmt|;
comment|/* ACE size in bytes of vsa_aclentp */
name|uint_t
name|vsa_aclflags
decl_stmt|;
comment|/* ACE ACL flags */
block|}
name|vsecattr_t
typedef|;
end_typedef

begin_comment
comment|/* vsa_mask values */
end_comment

begin_define
define|#
directive|define
name|VSA_ACL
value|0x0001
end_define

begin_define
define|#
directive|define
name|VSA_ACLCNT
value|0x0002
end_define

begin_define
define|#
directive|define
name|VSA_DFACL
value|0x0004
end_define

begin_define
define|#
directive|define
name|VSA_DFACLCNT
value|0x0008
end_define

begin_define
define|#
directive|define
name|VSA_ACE
value|0x0010
end_define

begin_define
define|#
directive|define
name|VSA_ACECNT
value|0x0020
end_define

begin_define
define|#
directive|define
name|VSA_ACE_ALLTYPES
value|0x0040
end_define

begin_define
define|#
directive|define
name|VSA_ACE_ACLFLAGS
value|0x0080
end_define

begin_comment
comment|/* get/set ACE ACL flags */
end_comment

begin_comment
comment|/*  * Structure used by various vnode operations to determine  * the context (pid, host, identity) of a caller.  *  * The cc_caller_id is used to identify one or more callers who invoke  * operations, possibly on behalf of others.  For example, the NFS  * server could have it's own cc_caller_id which can be detected by  * vnode/vfs operations or (FEM) monitors on those operations.  New  * caller IDs are generated by fs_new_caller_id().  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|caller_context
block|{
name|pid_t
name|cc_pid
decl_stmt|;
comment|/* Process ID of the caller */
name|int
name|cc_sysid
decl_stmt|;
comment|/* System ID, used for remote calls */
name|u_longlong_t
name|cc_caller_id
decl_stmt|;
comment|/* Identifier for (set of) caller(s) */
name|ulong_t
name|cc_flags
decl_stmt|;
block|}
name|caller_context_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|taskq
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Flags for VOP_LOOKUP  *  * Defined in file.h, but also possible, FIGNORECASE and FSEARCH  *  */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_DIR
value|0x01
end_define

begin_comment
comment|/* want parent dir vp */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_XATTR
value|0x02
end_define

begin_comment
comment|/* lookup up extended attr dir */
end_comment

begin_define
define|#
directive|define
name|CREATE_XATTR_DIR
value|0x04
end_define

begin_comment
comment|/* Create extended attr dir */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_HAVE_SYSATTR_DIR
value|0x08
end_define

begin_comment
comment|/* Already created virtual GFS dir */
end_comment

begin_comment
comment|/*  * Flags for VOP_READDIR  */
end_comment

begin_define
define|#
directive|define
name|V_RDDIR_ENTFLAGS
value|0x01
end_define

begin_comment
comment|/* request dirent flags */
end_comment

begin_define
define|#
directive|define
name|V_RDDIR_ACCFILTER
value|0x02
end_define

begin_comment
comment|/* filter out inaccessible dirents */
end_comment

begin_comment
comment|/*  * Public vnode manipulation functions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|vn_rele_async
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|taskq
modifier|*
name|taskq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Extensible vnode attribute (xva) routines:  * xva_init() initializes an xvattr_t (zero struct, init mapsize, set AT_XATTR)  * xva_getxoptattr() returns a ponter to the xoptattr_t section of xvattr_t  */
end_comment

begin_function_decl
name|void
name|xva_init
parameter_list|(
name|xvattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xoptattr_t
modifier|*
name|xva_getxoptattr
parameter_list|(
name|xvattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get ptr to xoptattr_t */
end_comment

begin_define
define|#
directive|define
name|VN_RELE_ASYNC
parameter_list|(
name|vp
parameter_list|,
name|taskq
parameter_list|)
value|{ \ 	vn_rele_async(vp, taskq); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Flags to VOP_SETATTR/VOP_GETATTR.  */
end_comment

begin_define
define|#
directive|define
name|ATTR_UTIME
value|0x01
end_define

begin_comment
comment|/* non-default utime(2) request */
end_comment

begin_define
define|#
directive|define
name|ATTR_EXEC
value|0x02
end_define

begin_comment
comment|/* invocation from exec(2) */
end_comment

begin_define
define|#
directive|define
name|ATTR_COMM
value|0x04
end_define

begin_comment
comment|/* yield common vp attributes */
end_comment

begin_define
define|#
directive|define
name|ATTR_HINT
value|0x08
end_define

begin_comment
comment|/* information returned will be `hint' */
end_comment

begin_define
define|#
directive|define
name|ATTR_REAL
value|0x10
end_define

begin_comment
comment|/* yield attributes of the real vp */
end_comment

begin_define
define|#
directive|define
name|ATTR_NOACLCHECK
value|0x20
end_define

begin_comment
comment|/* Don't check ACL when checking permissions */
end_comment

begin_define
define|#
directive|define
name|ATTR_TRIGGER
value|0x40
end_define

begin_comment
comment|/* Mount first if vnode is a trigger mount */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_VNODE_H */
end_comment

end_unit

