begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999-2001 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by Robert Watson for the TrustedBSD Project.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*   * Developed by the TrustedBSD Project.  * Support for POSIX.1e access control lists.  */
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
comment|/*  * POSIX.1e ACL types and related constants.  */
end_comment

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
name|ACL_MAX_ENTRIES
value|32
end_define

begin_comment
comment|/* maximum entries in an ACL */
end_comment

begin_typedef
typedef|typedef
name|int
name|acl_type_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|acl_tag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|mode_t
name|acl_perm_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|mode_t
modifier|*
name|acl_permset_t
typedef|;
end_typedef

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
comment|/* internal ACL structure */
end_comment

begin_struct
struct|struct
name|acl
block|{
name|int
name|acl_cnt
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
comment|/* external ACL structure */
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

begin_comment
comment|/*  * Possible valid values for ae_tag field.  */
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

begin_comment
comment|/*  * Possible valid values for acl_type_t arguments.  */
end_comment

begin_define
define|#
directive|define
name|ACL_TYPE_ACCESS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ACL_TYPE_DEFAULT
value|0x00000001
end_define

begin_comment
comment|/*  * Possible flags in ae_perm field.  */
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
comment|/*  * Possible entry_id values for acl_get_entry()  */
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
comment|/*  * Undefined value in ae_id field  */
end_comment

begin_define
define|#
directive|define
name|ACL_UNDEFINED_ID
value|((uid_t)-1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|acl_zone
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/*  * File system independent code to move back and forth between POSIX mode and  * POSIX.1e ACL representations.  */
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

begin_comment
comment|/*  * File system independent syntax check for a POSIX.1e ACL.  */
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_comment
comment|/*  * Syscall interface -- use the library calls instead as the syscalls have  * strict acl entry ordering requirements.  */
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
comment|/*  * Supported POSIX.1e ACL manipulation and assignment/retrieval API _np calls  * are local extensions that reflect an environment capable of opening file  * descriptors of directories, and allowing additional ACL type for different  * filesystems (i.e., AFS).  */
name|__BEGIN_DECLS
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

