begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999-2001 Robert N. M. Watson  * Copyright (c) 2008 Edward Tomasz NapieraÅa<trasz@FreeBSD.org>  * All rights reserved.  *  * This software was developed by Robert Watson for the TrustedBSD Project.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*   * Developed by the TrustedBSD Project.  * Support for POSIX.1e and NFSv4 access control lists.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ACL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ACL_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_comment
comment|/*  * POSIX.1e and NFSv4 ACL types and related constants.  */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|acl_tag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|acl_perm_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|acl_entry_type_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|acl_flag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|acl_type_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
modifier|*
name|acl_permset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
modifier|*
name|acl_flagset_t
typedef|;
end_typedef

begin_comment
comment|/*  * With 254 entries, "struct acl_t_struct" is exactly one 4kB page big.  * Note that with NFSv4 ACLs, the maximum number of ACL entries one  * may set on file or directory is about half of ACL_MAX_ENTRIES.  *  * If you increase this, you might also need to increase  * _ACL_T_ALIGNMENT_BITS in lib/libc/posix1e/acl_support.h.  *  * The maximum number of POSIX.1e ACLs is controlled  * by OLDACL_MAX_ENTRIES.  Changing that one will break binary  * compatibility with pre-8.0 userland and change on-disk ACL layout.  */
end_comment

begin_define
define|#
directive|define
name|ACL_MAX_ENTRIES
value|254
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_ACL_PRIVATE
argument_list|)
end_if

begin_define
define|#
directive|define
name|POSIX1E_ACL_ACCESS_EXTATTR_NAMESPACE
value|EXTATTR_NAMESPACE_SYSTEM
end_define

begin_define
define|#
directive|define
name|POSIX1E_ACL_ACCESS_EXTATTR_NAME
value|"posix1e.acl_access"
end_define

begin_define
define|#
directive|define
name|POSIX1E_ACL_DEFAULT_EXTATTR_NAMESPACE
value|EXTATTR_NAMESPACE_SYSTEM
end_define

begin_define
define|#
directive|define
name|POSIX1E_ACL_DEFAULT_EXTATTR_NAME
value|"posix1e.acl_default"
end_define

begin_define
define|#
directive|define
name|NFS4_ACL_EXTATTR_NAMESPACE
value|EXTATTR_NAMESPACE_SYSTEM
end_define

begin_define
define|#
directive|define
name|NFS4_ACL_EXTATTR_NAME
value|"nfs4.acl"
end_define

begin_define
define|#
directive|define
name|OLDACL_MAX_ENTRIES
value|32
end_define

begin_comment
comment|/*  * "struct oldacl" is used in compatibility ACL syscalls and for on-disk  * storage of POSIX.1e ACLs.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|oldacl_tag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|mode_t
name|oldacl_perm_t
typedef|;
end_typedef

begin_struct
struct|struct
name|oldacl_entry
block|{
name|oldacl_tag_t
name|ae_tag
decl_stmt|;
name|uid_t
name|ae_id
decl_stmt|;
name|oldacl_perm_t
name|ae_perm
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|oldacl_entry
modifier|*
name|oldacl_entry_t
typedef|;
end_typedef

begin_struct
struct|struct
name|oldacl
block|{
name|int
name|acl_cnt
decl_stmt|;
name|struct
name|oldacl_entry
name|acl_entry
index|[
name|OLDACL_MAX_ENTRIES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Current "struct acl".  */
end_comment

begin_struct
struct|struct
name|acl_entry
block|{
name|acl_tag_t
name|ae_tag
decl_stmt|;
name|uid_t
name|ae_id
decl_stmt|;
name|acl_perm_t
name|ae_perm
decl_stmt|;
comment|/* NFSv4 entry type, "allow" or "deny".  Unused in POSIX.1e ACLs. */
name|acl_entry_type_t
name|ae_entry_type
decl_stmt|;
comment|/* NFSv4 ACL inheritance.  Unused in POSIX.1e ACLs. */
name|acl_flag_t
name|ae_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|acl_entry
modifier|*
name|acl_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * Internal ACL structure, used in libc, kernel APIs and for on-disk  * storage of NFSv4 ACLs.  POSIX.1e ACLs use "struct oldacl" for on-disk  * storage.  */
end_comment

begin_struct
struct|struct
name|acl
block|{
name|unsigned
name|int
name|acl_maxcnt
decl_stmt|;
name|unsigned
name|int
name|acl_cnt
decl_stmt|;
comment|/* Will be required e.g. to implement NFSv4.1 ACL inheritance. */
name|int
name|acl_spare
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|acl_entry
name|acl_entry
index|[
name|ACL_MAX_ENTRIES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ACL structure internal to libc.  */
end_comment

begin_struct
struct|struct
name|acl_t_struct
block|{
name|struct
name|acl
name|ats_acl
decl_stmt|;
name|int
name|ats_cur_entry
decl_stmt|;
comment|/* 	 * ats_brand is for libc internal bookkeeping only. 	 * Applications should use acl_get_brand_np(3). 	 * Kernel code should use the "type" argument passed 	 * to VOP_SETACL, VOP_GETACL or VOP_ACLCHECK calls; 	 * ACL_TYPE_ACCESS or ACL_TYPE_DEFAULT mean POSIX.1e 	 * ACL, ACL_TYPE_NFS4 means NFSv4 ACL. 	 */
name|int
name|ats_brand
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|acl_t_struct
modifier|*
name|acl_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _KERNEL || _ACL_PRIVATE */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|acl_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|acl_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL&& !_ACL_PRIVATE */
end_comment

begin_comment
comment|/*  * Possible valid values for ats_brand field.  */
end_comment

begin_define
define|#
directive|define
name|ACL_BRAND_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|ACL_BRAND_POSIX
value|1
end_define

begin_define
define|#
directive|define
name|ACL_BRAND_NFS4
value|2
end_define

begin_comment
comment|/*  * Possible valid values for ae_tag field.  For explanation, see acl(9).  */
end_comment

begin_define
define|#
directive|define
name|ACL_UNDEFINED_TAG
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ACL_USER_OBJ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ACL_USER
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ACL_GROUP_OBJ
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ACL_GROUP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ACL_MASK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ACL_OTHER
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ACL_OTHER_OBJ
value|ACL_OTHER
end_define

begin_define
define|#
directive|define
name|ACL_EVERYONE
value|0x00000040
end_define

begin_comment
comment|/*  * Possible valid values for ae_entry_type field, valid only for NFSv4 ACLs.  */
end_comment

begin_define
define|#
directive|define
name|ACL_ENTRY_TYPE_ALLOW
value|0x0100
end_define

begin_define
define|#
directive|define
name|ACL_ENTRY_TYPE_DENY
value|0x0200
end_define

begin_define
define|#
directive|define
name|ACL_ENTRY_TYPE_AUDIT
value|0x0400
end_define

begin_define
define|#
directive|define
name|ACL_ENTRY_TYPE_ALARM
value|0x0800
end_define

begin_comment
comment|/*  * Possible valid values for acl_type_t arguments.  First two  * are provided only for backwards binary compatibility.  */
end_comment

begin_define
define|#
directive|define
name|ACL_TYPE_ACCESS_OLD
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ACL_TYPE_DEFAULT_OLD
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ACL_TYPE_ACCESS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ACL_TYPE_DEFAULT
value|0x00000003
end_define

begin_define
define|#
directive|define
name|ACL_TYPE_NFS4
value|0x00000004
end_define

begin_comment
comment|/*  * Possible bits in ae_perm field for POSIX.1e ACLs.  Note  * that ACL_EXECUTE may be used in both NFSv4 and POSIX.1e ACLs.  */
end_comment

begin_define
define|#
directive|define
name|ACL_EXECUTE
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACL_WRITE
value|0x0002
end_define

begin_define
define|#
directive|define
name|ACL_READ
value|0x0004
end_define

begin_define
define|#
directive|define
name|ACL_PERM_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|ACL_PERM_BITS
value|(ACL_EXECUTE | ACL_WRITE | ACL_READ)
end_define

begin_define
define|#
directive|define
name|ACL_POSIX1E_BITS
value|(ACL_EXECUTE | ACL_WRITE | ACL_READ)
end_define

begin_comment
comment|/*  * Possible bits in ae_perm field for NFSv4 ACLs.  */
end_comment

begin_define
define|#
directive|define
name|ACL_READ_DATA
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ACL_LIST_DIRECTORY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ACL_WRITE_DATA
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ACL_ADD_FILE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ACL_APPEND_DATA
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ACL_ADD_SUBDIRECTORY
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ACL_READ_NAMED_ATTRS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ACL_WRITE_NAMED_ATTRS
value|0x00000080
end_define

begin_comment
comment|/* ACL_EXECUTE is defined above. */
end_comment

begin_define
define|#
directive|define
name|ACL_DELETE_CHILD
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ACL_READ_ATTRIBUTES
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ACL_WRITE_ATTRIBUTES
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ACL_DELETE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|ACL_READ_ACL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|ACL_WRITE_ACL
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ACL_WRITE_OWNER
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ACL_SYNCHRONIZE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ACL_NFS4_PERM_BITS
value|(ACL_READ_DATA | ACL_WRITE_DATA | \     ACL_APPEND_DATA | ACL_READ_NAMED_ATTRS | ACL_WRITE_NAMED_ATTRS | \     ACL_EXECUTE | ACL_DELETE_CHILD | ACL_READ_ATTRIBUTES | \     ACL_WRITE_ATTRIBUTES | ACL_DELETE | ACL_READ_ACL | ACL_WRITE_ACL | \     ACL_WRITE_OWNER | ACL_SYNCHRONIZE)
end_define

begin_comment
comment|/*  * Possible entry_id values for acl_get_entry(3).  */
end_comment

begin_define
define|#
directive|define
name|ACL_FIRST_ENTRY
value|0
end_define

begin_define
define|#
directive|define
name|ACL_NEXT_ENTRY
value|1
end_define

begin_comment
comment|/*  * Possible values in ae_flags field; valid only for NFSv4 ACLs.  */
end_comment

begin_define
define|#
directive|define
name|ACL_ENTRY_FILE_INHERIT
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACL_ENTRY_DIRECTORY_INHERIT
value|0x0002
end_define

begin_define
define|#
directive|define
name|ACL_ENTRY_NO_PROPAGATE_INHERIT
value|0x0004
end_define

begin_define
define|#
directive|define
name|ACL_ENTRY_INHERIT_ONLY
value|0x0008
end_define

begin_define
define|#
directive|define
name|ACL_ENTRY_SUCCESSFUL_ACCESS
value|0x0010
end_define

begin_define
define|#
directive|define
name|ACL_ENTRY_FAILED_ACCESS
value|0x0020
end_define

begin_define
define|#
directive|define
name|ACL_FLAGS_BITS
value|(ACL_ENTRY_FILE_INHERIT | \     ACL_ENTRY_DIRECTORY_INHERIT | ACL_ENTRY_NO_PROPAGATE_INHERIT | \     ACL_ENTRY_INHERIT_ONLY | ACL_ENTRY_SUCCESSFUL_ACCESS | \     ACL_ENTRY_FAILED_ACCESS)
end_define

begin_comment
comment|/*  * Undefined value in ae_id field.  ae_id should be set to this value  * iff ae_tag is ACL_USER_OBJ, ACL_GROUP_OBJ, ACL_OTHER or ACL_EVERYONE.  */
end_comment

begin_define
define|#
directive|define
name|ACL_UNDEFINED_ID
value|((uid_t)-1)
end_define

begin_comment
comment|/*  * Possible values for _flags parameter in acl_to_text_np(3).  */
end_comment

begin_define
define|#
directive|define
name|ACL_TEXT_VERBOSE
value|0x01
end_define

begin_define
define|#
directive|define
name|ACL_TEXT_NUMERIC_IDS
value|0x02
end_define

begin_define
define|#
directive|define
name|ACL_TEXT_APPEND_ID
value|0x04
end_define

begin_comment
comment|/*  * POSIX.1e ACLs are capable of expressing the read, write, and execute bits  * of the POSIX mode field.  We provide two masks: one that defines the bits  * the ACL will replace in the mode, and the other that defines the bits that  * must be preseved when an ACL is updating a mode.  */
end_comment

begin_define
define|#
directive|define
name|ACL_OVERRIDE_MASK
value|(S_IRWXU | S_IRWXG | S_IRWXO)
end_define

begin_define
define|#
directive|define
name|ACL_PRESERVE_MASK
value|(~ACL_OVERRIDE_MASK)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Filesystem-independent code to move back and forth between POSIX mode and  * POSIX.1e ACL representations.  */
end_comment

begin_function_decl
name|acl_perm_t
name|acl_posix1e_mode_to_perm
parameter_list|(
name|acl_tag_t
name|tag
parameter_list|,
name|mode_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|acl_entry
name|acl_posix1e_mode_to_entry
parameter_list|(
name|acl_tag_t
name|tag
parameter_list|,
name|uid_t
name|uid
parameter_list|,
name|gid_t
name|gid
parameter_list|,
name|mode_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mode_t
name|acl_posix1e_perms_to_mode
parameter_list|(
name|struct
name|acl_entry
modifier|*
name|acl_user_obj_entry
parameter_list|,
name|struct
name|acl_entry
modifier|*
name|acl_group_obj_entry
parameter_list|,
name|struct
name|acl_entry
modifier|*
name|acl_other_entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mode_t
name|acl_posix1e_acl_to_mode
parameter_list|(
name|struct
name|acl
modifier|*
name|acl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mode_t
name|acl_posix1e_newfilemode
parameter_list|(
name|mode_t
name|cmode
parameter_list|,
name|struct
name|acl
modifier|*
name|dacl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|acl
modifier|*
name|acl_alloc
parameter_list|(
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acl_free
parameter_list|(
name|struct
name|acl
modifier|*
name|aclp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acl_nfs4_sync_acl_from_mode
parameter_list|(
name|struct
name|acl
modifier|*
name|aclp
parameter_list|,
name|mode_t
name|mode
parameter_list|,
name|int
name|file_owner_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acl_nfs4_sync_mode_from_acl
parameter_list|(
name|mode_t
modifier|*
name|mode
parameter_list|,
specifier|const
name|struct
name|acl
modifier|*
name|aclp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_nfs4_is_trivial
parameter_list|(
specifier|const
name|struct
name|acl
modifier|*
name|aclp
parameter_list|,
name|int
name|file_owner_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acl_nfs4_compute_inherited_acl
parameter_list|(
specifier|const
name|struct
name|acl
modifier|*
name|parent_aclp
parameter_list|,
name|struct
name|acl
modifier|*
name|child_aclp
parameter_list|,
name|mode_t
name|mode
parameter_list|,
name|int
name|file_owner_id
parameter_list|,
name|int
name|is_directory
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_copy_oldacl_into_acl
parameter_list|(
specifier|const
name|struct
name|oldacl
modifier|*
name|source
parameter_list|,
name|struct
name|acl
modifier|*
name|dest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_copy_acl_into_oldacl
parameter_list|(
specifier|const
name|struct
name|acl
modifier|*
name|source
parameter_list|,
name|struct
name|oldacl
modifier|*
name|dest
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * To allocate 'struct acl', use acl_alloc()/acl_free() instead of this.  */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_ACL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Filesystem-independent syntax check for a POSIX.1e ACL.  */
end_comment

begin_function_decl
name|int
name|acl_posix1e_check
parameter_list|(
name|struct
name|acl
modifier|*
name|acl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_nfs4_check
parameter_list|(
specifier|const
name|struct
name|acl
modifier|*
name|aclp
parameter_list|,
name|int
name|is_directory
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_ACL_PRIVATE
argument_list|)
end_if

begin_comment
comment|/*  * Syscall interface -- use the library calls instead as the syscalls have  * strict ACL entry ordering requirements.  */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|int
name|__acl_aclcheck_fd
parameter_list|(
name|int
name|_filedes
parameter_list|,
name|acl_type_t
name|_type
parameter_list|,
name|struct
name|acl
modifier|*
name|_aclp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__acl_aclcheck_file
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|acl_type_t
name|_type
parameter_list|,
name|struct
name|acl
modifier|*
name|_aclp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__acl_aclcheck_link
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|acl_type_t
name|_type
parameter_list|,
name|struct
name|acl
modifier|*
name|_aclp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__acl_delete_fd
parameter_list|(
name|int
name|_filedes
parameter_list|,
name|acl_type_t
name|_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__acl_delete_file
parameter_list|(
specifier|const
name|char
modifier|*
name|_path_p
parameter_list|,
name|acl_type_t
name|_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__acl_delete_link
parameter_list|(
specifier|const
name|char
modifier|*
name|_path_p
parameter_list|,
name|acl_type_t
name|_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__acl_get_fd
parameter_list|(
name|int
name|_filedes
parameter_list|,
name|acl_type_t
name|_type
parameter_list|,
name|struct
name|acl
modifier|*
name|_aclp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__acl_get_file
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|acl_type_t
name|_type
parameter_list|,
name|struct
name|acl
modifier|*
name|_aclp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__acl_get_link
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|acl_type_t
name|_type
parameter_list|,
name|struct
name|acl
modifier|*
name|_aclp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__acl_set_fd
parameter_list|(
name|int
name|_filedes
parameter_list|,
name|acl_type_t
name|_type
parameter_list|,
name|struct
name|acl
modifier|*
name|_aclp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__acl_set_file
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|acl_type_t
name|_type
parameter_list|,
name|struct
name|acl
modifier|*
name|_aclp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__acl_set_link
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|acl_type_t
name|_type
parameter_list|,
name|struct
name|acl
modifier|*
name|_aclp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
endif|#
directive|endif
comment|/* _ACL_PRIVATE */
comment|/*  * Supported POSIX.1e ACL manipulation and assignment/retrieval API _np calls  * are local extensions that reflect an environment capable of opening file  * descriptors of directories, and allowing additional ACL type for different  * filesystems (i.e., AFS).  */
name|__BEGIN_DECLS
name|int
name|acl_add_flag_np
parameter_list|(
name|acl_flagset_t
name|_flagset_d
parameter_list|,
name|acl_flag_t
name|_flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_add_perm
parameter_list|(
name|acl_permset_t
name|_permset_d
parameter_list|,
name|acl_perm_t
name|_perm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_calc_mask
parameter_list|(
name|acl_t
modifier|*
name|_acl_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_clear_flags_np
parameter_list|(
name|acl_flagset_t
name|_flagset_d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_clear_perms
parameter_list|(
name|acl_permset_t
name|_permset_d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_copy_entry
parameter_list|(
name|acl_entry_t
name|_dest_d
parameter_list|,
name|acl_entry_t
name|_src_d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|acl_copy_ext
parameter_list|(
name|void
modifier|*
name|_buf_p
parameter_list|,
name|acl_t
name|_acl
parameter_list|,
name|ssize_t
name|_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|acl_t
name|acl_copy_int
parameter_list|(
specifier|const
name|void
modifier|*
name|_buf_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_create_entry
parameter_list|(
name|acl_t
modifier|*
name|_acl_p
parameter_list|,
name|acl_entry_t
modifier|*
name|_entry_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_create_entry_np
parameter_list|(
name|acl_t
modifier|*
name|_acl_p
parameter_list|,
name|acl_entry_t
modifier|*
name|_entry_p
parameter_list|,
name|int
name|_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_delete_entry
parameter_list|(
name|acl_t
name|_acl
parameter_list|,
name|acl_entry_t
name|_entry_d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_delete_entry_np
parameter_list|(
name|acl_t
name|_acl
parameter_list|,
name|int
name|_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_delete_fd_np
parameter_list|(
name|int
name|_filedes
parameter_list|,
name|acl_type_t
name|_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_delete_file_np
parameter_list|(
specifier|const
name|char
modifier|*
name|_path_p
parameter_list|,
name|acl_type_t
name|_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_delete_link_np
parameter_list|(
specifier|const
name|char
modifier|*
name|_path_p
parameter_list|,
name|acl_type_t
name|_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_delete_def_file
parameter_list|(
specifier|const
name|char
modifier|*
name|_path_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_delete_def_link_np
parameter_list|(
specifier|const
name|char
modifier|*
name|_path_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_delete_flag_np
parameter_list|(
name|acl_flagset_t
name|_flagset_d
parameter_list|,
name|acl_flag_t
name|_flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_delete_perm
parameter_list|(
name|acl_permset_t
name|_permset_d
parameter_list|,
name|acl_perm_t
name|_perm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|acl_t
name|acl_dup
parameter_list|(
name|acl_t
name|_acl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_free
parameter_list|(
name|void
modifier|*
name|_obj_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|acl_t
name|acl_from_text
parameter_list|(
specifier|const
name|char
modifier|*
name|_buf_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_get_brand_np
parameter_list|(
name|acl_t
name|_acl
parameter_list|,
name|int
modifier|*
name|_brand_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_get_entry
parameter_list|(
name|acl_t
name|_acl
parameter_list|,
name|int
name|_entry_id
parameter_list|,
name|acl_entry_t
modifier|*
name|_entry_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|acl_t
name|acl_get_fd
parameter_list|(
name|int
name|_fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|acl_t
name|acl_get_fd_np
parameter_list|(
name|int
name|fd
parameter_list|,
name|acl_type_t
name|_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|acl_t
name|acl_get_file
parameter_list|(
specifier|const
name|char
modifier|*
name|_path_p
parameter_list|,
name|acl_type_t
name|_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_get_entry_type_np
parameter_list|(
name|acl_entry_t
name|_entry_d
parameter_list|,
name|acl_entry_type_t
modifier|*
name|_entry_type_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|acl_t
name|acl_get_link_np
parameter_list|(
specifier|const
name|char
modifier|*
name|_path_p
parameter_list|,
name|acl_type_t
name|_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|acl_get_qualifier
parameter_list|(
name|acl_entry_t
name|_entry_d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_get_flag_np
parameter_list|(
name|acl_flagset_t
name|_flagset_d
parameter_list|,
name|acl_flag_t
name|_flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_get_perm_np
parameter_list|(
name|acl_permset_t
name|_permset_d
parameter_list|,
name|acl_perm_t
name|_perm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_get_flagset_np
parameter_list|(
name|acl_entry_t
name|_entry_d
parameter_list|,
name|acl_flagset_t
modifier|*
name|_flagset_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_get_permset
parameter_list|(
name|acl_entry_t
name|_entry_d
parameter_list|,
name|acl_permset_t
modifier|*
name|_permset_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_get_tag_type
parameter_list|(
name|acl_entry_t
name|_entry_d
parameter_list|,
name|acl_tag_t
modifier|*
name|_tag_type_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|acl_t
name|acl_init
parameter_list|(
name|int
name|_count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_set_fd
parameter_list|(
name|int
name|_fd
parameter_list|,
name|acl_t
name|_acl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_set_fd_np
parameter_list|(
name|int
name|_fd
parameter_list|,
name|acl_t
name|_acl
parameter_list|,
name|acl_type_t
name|_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_set_file
parameter_list|(
specifier|const
name|char
modifier|*
name|_path_p
parameter_list|,
name|acl_type_t
name|_type
parameter_list|,
name|acl_t
name|_acl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_set_entry_type_np
parameter_list|(
name|acl_entry_t
name|_entry_d
parameter_list|,
name|acl_entry_type_t
name|_entry_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_set_link_np
parameter_list|(
specifier|const
name|char
modifier|*
name|_path_p
parameter_list|,
name|acl_type_t
name|_type
parameter_list|,
name|acl_t
name|_acl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_set_flagset_np
parameter_list|(
name|acl_entry_t
name|_entry_d
parameter_list|,
name|acl_flagset_t
name|_flagset_d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_set_permset
parameter_list|(
name|acl_entry_t
name|_entry_d
parameter_list|,
name|acl_permset_t
name|_permset_d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_set_qualifier
parameter_list|(
name|acl_entry_t
name|_entry_d
parameter_list|,
specifier|const
name|void
modifier|*
name|_tag_qualifier_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_set_tag_type
parameter_list|(
name|acl_entry_t
name|_entry_d
parameter_list|,
name|acl_tag_t
name|_tag_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|acl_size
parameter_list|(
name|acl_t
name|_acl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|acl_to_text
parameter_list|(
name|acl_t
name|_acl
parameter_list|,
name|ssize_t
modifier|*
name|_len_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|acl_to_text_np
parameter_list|(
name|acl_t
name|_acl
parameter_list|,
name|ssize_t
modifier|*
name|_len_p
parameter_list|,
name|int
name|_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_valid
parameter_list|(
name|acl_t
name|_acl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_valid_fd_np
parameter_list|(
name|int
name|_fd
parameter_list|,
name|acl_type_t
name|_type
parameter_list|,
name|acl_t
name|_acl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_valid_file_np
parameter_list|(
specifier|const
name|char
modifier|*
name|_path_p
parameter_list|,
name|acl_type_t
name|_type
parameter_list|,
name|acl_t
name|_acl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_valid_link_np
parameter_list|(
specifier|const
name|char
modifier|*
name|_path_p
parameter_list|,
name|acl_type_t
name|_type
parameter_list|,
name|acl_t
name|_acl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_is_trivial_np
parameter_list|(
specifier|const
name|acl_t
name|_acl
parameter_list|,
name|int
modifier|*
name|_trivialp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|acl_t
name|acl_strip_np
parameter_list|(
specifier|const
name|acl_t
name|_acl
parameter_list|,
name|int
name|recalculate_mask
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

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
comment|/* !_SYS_ACL_H_ */
end_comment

end_unit

