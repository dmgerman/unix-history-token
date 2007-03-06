begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999-2001 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by Robert Watson for the TrustedBSD Project.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Developed by the TrustedBSD Project.  * Support for extended filesystem attributes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UFS_UFS_EXTATTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_UFS_UFS_EXTATTR_H_
end_define

begin_define
define|#
directive|define
name|UFS_EXTATTR_MAGIC
value|0x00b5d5ec
end_define

begin_define
define|#
directive|define
name|UFS_EXTATTR_VERSION
value|0x00000003
end_define

begin_define
define|#
directive|define
name|UFS_EXTATTR_FSROOTSUBDIR
value|".attribute"
end_define

begin_define
define|#
directive|define
name|UFS_EXTATTR_SUBDIR_SYSTEM
value|"system"
end_define

begin_define
define|#
directive|define
name|UFS_EXTATTR_SUBDIR_USER
value|"user"
end_define

begin_define
define|#
directive|define
name|UFS_EXTATTR_MAXEXTATTRNAME
value|65
end_define

begin_comment
comment|/* including null */
end_comment

begin_define
define|#
directive|define
name|UFS_EXTATTR_ATTR_FLAG_INUSE
value|0x00000001
end_define

begin_comment
comment|/* attr has been set */
end_comment

begin_define
define|#
directive|define
name|UFS_EXTATTR_PERM_KERNEL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|UFS_EXTATTR_PERM_ROOT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|UFS_EXTATTR_PERM_OWNER
value|0x00000002
end_define

begin_define
define|#
directive|define
name|UFS_EXTATTR_PERM_ANYONE
value|0x00000003
end_define

begin_define
define|#
directive|define
name|UFS_EXTATTR_UEPM_INITIALIZED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|UFS_EXTATTR_UEPM_STARTED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|UFS_EXTATTR_CMD_START
value|0x00000001
end_define

begin_define
define|#
directive|define
name|UFS_EXTATTR_CMD_STOP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|UFS_EXTATTR_CMD_ENABLE
value|0x00000003
end_define

begin_define
define|#
directive|define
name|UFS_EXTATTR_CMD_DISABLE
value|0x00000004
end_define

begin_struct
struct|struct
name|ufs_extattr_fileheader
block|{
name|u_int
name|uef_magic
decl_stmt|;
comment|/* magic number for sanity checking */
name|u_int
name|uef_version
decl_stmt|;
comment|/* version of attribute file */
name|u_int
name|uef_size
decl_stmt|;
comment|/* size of attributes, w/o header */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ufs_extattr_header
block|{
name|u_int
name|ueh_flags
decl_stmt|;
comment|/* flags for attribute */
name|u_int
name|ueh_len
decl_stmt|;
comment|/* local defined length;<= uef_size */
name|u_int32_t
name|ueh_i_gen
decl_stmt|;
comment|/* generation number for sanity */
comment|/* data follows the header */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure defines the required fields of an extended-attribute header.  */
end_comment

begin_struct
struct|struct
name|extattr
block|{
name|int32_t
name|ea_length
decl_stmt|;
comment|/* length of this attribute */
name|int8_t
name|ea_namespace
decl_stmt|;
comment|/* name space of this attribute */
name|int8_t
name|ea_contentpadlen
decl_stmt|;
comment|/* bytes of padding at end of attribute */
name|int8_t
name|ea_namelength
decl_stmt|;
comment|/* length of attribute name */
name|char
name|ea_name
index|[
literal|1
index|]
decl_stmt|;
comment|/* null-terminated attribute name */
comment|/* extended attribute content follows */
block|}
struct|;
end_struct

begin_comment
comment|/*  * These macros are used to access and manipulate an extended attribute:  *  * EXTATTR_NEXT(eap) returns a pointer to the next extended attribute  *	following eap.  * EXTATTR_CONTENT(eap) returns a pointer to the extended attribute  *	content referenced by eap.  * EXTATTR_CONTENT_SIZE(eap) returns the size of the extended attribute  *	content referenced by eap.  * EXTATTR_SET_LENGTHS(eap, contentsize) called after initializing the  *	attribute name to calculate and set the ea_length, ea_namelength,  *	and ea_contentpadlen fields of the extended attribute structure.  */
end_comment

begin_define
define|#
directive|define
name|EXTATTR_NEXT
parameter_list|(
name|eap
parameter_list|)
define|\
value|((struct extattr *)(((void *)(eap)) + (eap)->ea_length))
end_define

begin_define
define|#
directive|define
name|EXTATTR_CONTENT
parameter_list|(
name|eap
parameter_list|)
value|(((void *)(eap)) + EXTATTR_BASE_LENGTH(eap))
end_define

begin_define
define|#
directive|define
name|EXTATTR_CONTENT_SIZE
parameter_list|(
name|eap
parameter_list|)
define|\
value|((eap)->ea_length - EXTATTR_BASE_LENGTH(eap) - (eap)->ea_contentpadlen)
end_define

begin_define
define|#
directive|define
name|EXTATTR_BASE_LENGTH
parameter_list|(
name|eap
parameter_list|)
define|\
value|((sizeof(struct extattr) + (eap)->ea_namelength + 7)& ~7)
end_define

begin_define
define|#
directive|define
name|EXTATTR_SET_LENGTHS
parameter_list|(
name|eap
parameter_list|,
name|contentsize
parameter_list|)
value|do { \ 	KASSERT(((eap)->ea_name[0] != 0), \ 		("Must initialize name before setting lengths")); \ 	(eap)->ea_namelength = strlen((eap)->ea_name); \ 	(eap)->ea_contentpadlen = ((contentsize) % 8) ? \ 		8 - ((contentsize) % 8) : 0; \ 	(eap)->ea_length = EXTATTR_BASE_LENGTH(eap) + \ 		(contentsize) + (eap)->ea_contentpadlen; \ } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_EXTATTR
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|ufs_extattr_list_head
argument_list|,
name|ufs_extattr_list_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|ufs_extattr_list_entry
block|{
name|LIST_ENTRY
argument_list|(
argument|ufs_extattr_list_entry
argument_list|)
name|uele_entries
expr_stmt|;
name|struct
name|ufs_extattr_fileheader
name|uele_fileheader
decl_stmt|;
name|int
name|uele_attrnamespace
decl_stmt|;
name|char
name|uele_attrname
index|[
name|UFS_EXTATTR_MAXEXTATTRNAME
index|]
decl_stmt|;
name|struct
name|vnode
modifier|*
name|uele_backing_vnode
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|lock
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ufs_extattr_per_mount
block|{
name|struct
name|lock
name|uepm_lock
decl_stmt|;
name|struct
name|ufs_extattr_list_head
name|uepm_list
decl_stmt|;
name|struct
name|ucred
modifier|*
name|uepm_ucred
decl_stmt|;
name|int
name|uepm_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ufs_extattr_uepm_init
parameter_list|(
name|struct
name|ufs_extattr_per_mount
modifier|*
name|uepm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ufs_extattr_uepm_destroy
parameter_list|(
name|struct
name|ufs_extattr_per_mount
modifier|*
name|uepm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_extattr_start
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_extattr_autostart
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_extattr_stop
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_extattrctl
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|int
name|cmd
parameter_list|,
name|struct
name|vnode
modifier|*
name|filename
parameter_list|,
name|int
name|attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|attrname
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_getextattr
parameter_list|(
name|struct
name|vop_getextattr_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_deleteextattr
parameter_list|(
name|struct
name|vop_deleteextattr_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_setextattr
parameter_list|(
name|struct
name|vop_setextattr_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ufs_extattr_vnode_inactive
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* User-level definition of KASSERT for macros above */
end_comment

begin_define
define|#
directive|define
name|KASSERT
parameter_list|(
name|cond
parameter_list|,
name|str
parameter_list|)
value|do { \         if (!(cond)) { printf("panic: "); printf(str); printf("\n"); exit(1); }\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_UFS_UFS_EXTATTR_H_ */
end_comment

end_unit

