begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Robert N. M. Watson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*   * Userland/kernel interface for Access Control Lists  *  * This code from the FreeBSD POSIX.1e implementation.  Not all of the ACL  * code is committed yet; in order to use the library routines listed  * below, you'll need to download libposix1e_acl from the POSIX.1e  * implementation page, or possibly update to a more recent version of  * FreeBSD, as the code may have been committed.  *  * The POSIX.1e implementation page may be reached at:  *   http://www.watson.org/fbsd-hardening/posix1e/  *  * However, all syscalls will pass through to appropriate VFS vnops, so  * file systems implementing the vnops are accessible through the syscalls.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ACL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ACL_H
end_define

begin_comment
comment|/*  * POSIX.1e ACL types  */
end_comment

begin_define
define|#
directive|define
name|MAX_ACL_ENTRIES
value|32
end_define

begin_comment
comment|/* maximum entries in an ACL */
end_comment

begin_define
define|#
directive|define
name|_POSIX_ACL_PATH_MAX
value|MAX_ACL_ENTRIES
end_define

begin_define
define|#
directive|define
name|ACL_MAX_ENTRIES
value|MAX_ACL_ENTRIES
end_define

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
name|MAX_ACL_ENTRIES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|acl
modifier|*
name|acl_t
typedef|;
end_typedef

begin_comment
comment|/*  * Possible valid values for a_type of acl_entry_t  */
end_comment

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
name|ACL_AFS_ID
value|0x00000040
end_define

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
comment|/*  * Possible flags in a_perm field  */
end_comment

begin_define
define|#
directive|define
name|ACL_PERM_EXEC
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACL_PERM_WRITE
value|0x0002
end_define

begin_define
define|#
directive|define
name|ACL_PERM_READ
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
value|(ACL_PERM_EXEC | ACL_PERM_WRITE | ACL_PERM_READ)
end_define

begin_define
define|#
directive|define
name|ACL_POSIX1E_BITS
value|(ACL_PERM_EXEC | ACL_PERM_WRITE | ACL_PERM_READ)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Storage for ACLs and support structures  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_ACL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Dummy declarations so that we can expose acl_access all over the place  * without worrying about including ucred and friends.  vnode.h does the  * same thing.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * POSIX.1e and generic kernel/vfs semantics functions--not currently in the  * base distribution, but will be soon.  */
end_comment

begin_struct_decl
struct_decl|struct
name|vattr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_getacl_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_aclcheck_args
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|posix1e_acl_access
parameter_list|(
name|struct
name|acl
modifier|*
name|a_acl
parameter_list|,
name|int
name|a_mode
parameter_list|,
name|struct
name|ucred
modifier|*
name|a_cred
parameter_list|,
name|struct
name|proc
modifier|*
name|a_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generic_attr_to_posix1e_acl
parameter_list|(
name|struct
name|acl
modifier|*
name|a_acl
parameter_list|,
name|struct
name|vattr
modifier|*
name|vattr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|generic_vop_getacl
parameter_list|(
name|struct
name|vop_getacl_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|generic_vop_aclcheck
parameter_list|(
name|struct
name|vop_aclcheck_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix1e_vop_aclcheck
parameter_list|(
name|struct
name|vop_aclcheck_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Syscall interface -- use the library calls instead as the syscalls  * have strict acl entry ordering requirements  */
end_comment

begin_function_decl
name|int
name|acl_syscall_get_file
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|acl_type_t
name|type
parameter_list|,
name|struct
name|acl
modifier|*
name|aclp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_syscall_set_file
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|acl_type_t
name|type
parameter_list|,
name|struct
name|acl
modifier|*
name|aclp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_syscall_get_fd
parameter_list|(
name|int
name|filedes
parameter_list|,
name|acl_type_t
name|type
parameter_list|,
name|struct
name|acl
modifier|*
name|aclp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_syscall_set_fd
parameter_list|(
name|int
name|filedes
parameter_list|,
name|acl_type_t
name|type
parameter_list|,
name|struct
name|acl
modifier|*
name|aclp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_syscall_delete_file
parameter_list|(
specifier|const
name|char
modifier|*
name|path_p
parameter_list|,
name|acl_type_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_syscall_delete_fd
parameter_list|(
name|int
name|filedes
parameter_list|,
name|acl_type_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_syscall_aclcheck_file
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|acl_type_t
name|type
parameter_list|,
name|struct
name|acl
modifier|*
name|aclp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_syscall_aclcheck_fd
parameter_list|(
name|int
name|filedes
parameter_list|,
name|acl_type_t
name|type
parameter_list|,
name|struct
name|acl
modifier|*
name|aclp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Supported POSIX.1e ACL manipulation and assignment/retrieval API  * These are currently provided by libposix1e_acl, which is not shipped  * with the base distribution, but will be soon.  Some of these are  * from POSIX.1e-extensions.  *  * Not all POSIX.1e ACL functions are listed here yet, but more will  * be soon.  */
end_comment

begin_function_decl
name|int
name|acl_calc_mask
parameter_list|(
name|acl_t
modifier|*
name|acl_p
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
name|path_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_delete_def_fd
parameter_list|(
name|int
name|filedes
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
name|buf_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|acl_t
name|acl_get_fd
parameter_list|(
name|int
name|fd
parameter_list|,
name|acl_type_t
name|type
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
name|path_p
parameter_list|,
name|acl_type_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|acl_t
name|acl_init
parameter_list|(
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_set_fd
parameter_list|(
name|int
name|fd
parameter_list|,
name|acl_t
name|acl
parameter_list|,
name|acl_type_t
name|type
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
name|path_p
parameter_list|,
name|acl_type_t
name|type
parameter_list|,
name|acl_t
name|acl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|acl_to_text
parameter_list|(
name|acl_t
name|acl
parameter_list|,
name|ssize_t
modifier|*
name|len_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_valid
parameter_list|(
name|acl_t
name|acl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_valid_file
parameter_list|(
specifier|const
name|char
modifier|*
name|path_p
parameter_list|,
name|acl_type_t
name|type
parameter_list|,
name|acl_t
name|acl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_valid_fd
parameter_list|(
name|int
name|fd
parameter_list|,
name|acl_type_t
name|type
parameter_list|,
name|acl_t
name|acl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acl_free
parameter_list|(
name|void
modifier|*
name|obj_p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_ACL_H */
end_comment

end_unit

