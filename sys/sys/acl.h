begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999, 2000 Robert N. M. Watson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*   * Userland/kernel interface for Access Control Lists.  *  * The POSIX.1e implementation page may be reached at:  * http://www.watson.org/fbsd-hardening/posix1e/  */
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
comment|/*  * POSIX.1e ACL types and related constants  */
end_comment

begin_define
define|#
directive|define
name|ACL_MAX_ENTRIES
value|32
end_define

begin_comment
comment|/* maximum entries in an ACL */
end_comment

begin_define
define|#
directive|define
name|_POSIX_ACL_PATH_MAX
value|ACL_MAX_ENTRIES
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
name|ACL_MAX_ENTRIES
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
comment|/*  * Possible valid values for a_tag of acl_entry_t  */
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

begin_comment
comment|/*  * Possible valid values a_type_t arguments  */
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

begin_define
define|#
directive|define
name|ACL_TYPE_AFS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ACL_TYPE_CODA
value|0x00000003
end_define

begin_define
define|#
directive|define
name|ACL_TYPE_NTFS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ACL_TYPE_NWFS
value|0x00000005
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_comment
comment|/*  * Syscall interface -- use the library calls instead as the syscalls  * have strict acl entry ordering requirements  */
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
name|__END_DECLS
comment|/*  * Supported POSIX.1e ACL manipulation and assignment/retrieval API  * _np calls are local extensions that reflect an environment capable of  * opening file descriptors of directories, and allowing additional  * ACL type for different file systems (i.e., AFS)  */
name|__BEGIN_DECLS
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
comment|/* !_SYS_ACL_H */
end_comment

end_unit

