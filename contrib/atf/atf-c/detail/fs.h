begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ATF_C_DETAIL_FS_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATF_C_DETAIL_FS_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<atf-c/detail/dynstr.h>
end_include

begin_include
include|#
directive|include
file|<atf-c/error_fwd.h>
end_include

begin_comment
comment|/* ---------------------------------------------------------------------  * The "atf_fs_path" type.  * --------------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|atf_fs_path
block|{
name|atf_dynstr_t
name|m_data
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atf_fs_path
name|atf_fs_path_t
typedef|;
end_typedef

begin_comment
comment|/* Constructors/destructors. */
end_comment

begin_function_decl
name|atf_error_t
name|atf_fs_path_init_ap
parameter_list|(
name|atf_fs_path_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_fs_path_init_fmt
parameter_list|(
name|atf_fs_path_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_fs_path_copy
parameter_list|(
name|atf_fs_path_t
modifier|*
parameter_list|,
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atf_fs_path_fini
parameter_list|(
name|atf_fs_path_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Getters. */
end_comment

begin_function_decl
name|atf_error_t
name|atf_fs_path_branch_path
parameter_list|(
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|,
name|atf_fs_path_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|atf_fs_path_cstring
parameter_list|(
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_fs_path_leaf_name
parameter_list|(
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|,
name|atf_dynstr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_fs_path_is_absolute
parameter_list|(
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_fs_path_is_root
parameter_list|(
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Modifiers. */
end_comment

begin_function_decl
name|atf_error_t
name|atf_fs_path_append_ap
parameter_list|(
name|atf_fs_path_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_fs_path_append_fmt
parameter_list|(
name|atf_fs_path_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_fs_path_append_path
parameter_list|(
name|atf_fs_path_t
modifier|*
parameter_list|,
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_fs_path_to_absolute
parameter_list|(
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|,
name|atf_fs_path_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Operators. */
end_comment

begin_function_decl
name|bool
name|atf_equal_fs_path_fs_path
parameter_list|(
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|,
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ---------------------------------------------------------------------  * The "atf_fs_stat" type.  * --------------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|atf_fs_stat
block|{
name|int
name|m_type
decl_stmt|;
name|struct
name|stat
name|m_sb
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atf_fs_stat
name|atf_fs_stat_t
typedef|;
end_typedef

begin_comment
comment|/* Constants. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|atf_fs_stat_blk_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|atf_fs_stat_chr_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|atf_fs_stat_dir_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|atf_fs_stat_fifo_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|atf_fs_stat_lnk_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|atf_fs_stat_reg_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|atf_fs_stat_sock_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|atf_fs_stat_wht_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Constructors/destructors. */
end_comment

begin_function_decl
name|atf_error_t
name|atf_fs_stat_init
parameter_list|(
name|atf_fs_stat_t
modifier|*
parameter_list|,
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atf_fs_stat_copy
parameter_list|(
name|atf_fs_stat_t
modifier|*
parameter_list|,
specifier|const
name|atf_fs_stat_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atf_fs_stat_fini
parameter_list|(
name|atf_fs_stat_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Getters. */
end_comment

begin_function_decl
name|dev_t
name|atf_fs_stat_get_device
parameter_list|(
specifier|const
name|atf_fs_stat_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ino_t
name|atf_fs_stat_get_inode
parameter_list|(
specifier|const
name|atf_fs_stat_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mode_t
name|atf_fs_stat_get_mode
parameter_list|(
specifier|const
name|atf_fs_stat_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|atf_fs_stat_get_size
parameter_list|(
specifier|const
name|atf_fs_stat_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atf_fs_stat_get_type
parameter_list|(
specifier|const
name|atf_fs_stat_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_fs_stat_is_owner_readable
parameter_list|(
specifier|const
name|atf_fs_stat_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_fs_stat_is_owner_writable
parameter_list|(
specifier|const
name|atf_fs_stat_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_fs_stat_is_owner_executable
parameter_list|(
specifier|const
name|atf_fs_stat_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_fs_stat_is_group_readable
parameter_list|(
specifier|const
name|atf_fs_stat_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_fs_stat_is_group_writable
parameter_list|(
specifier|const
name|atf_fs_stat_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_fs_stat_is_group_executable
parameter_list|(
specifier|const
name|atf_fs_stat_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_fs_stat_is_other_readable
parameter_list|(
specifier|const
name|atf_fs_stat_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_fs_stat_is_other_writable
parameter_list|(
specifier|const
name|atf_fs_stat_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_fs_stat_is_other_executable
parameter_list|(
specifier|const
name|atf_fs_stat_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ---------------------------------------------------------------------  * Free functions.  * --------------------------------------------------------------------- */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|atf_fs_access_f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|atf_fs_access_r
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|atf_fs_access_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|atf_fs_access_x
decl_stmt|;
end_decl_stmt

begin_function_decl
name|atf_error_t
name|atf_fs_eaccess
parameter_list|(
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_fs_exists
parameter_list|(
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_fs_getcwd
parameter_list|(
name|atf_fs_path_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_fs_mkdtemp
parameter_list|(
name|atf_fs_path_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_fs_mkstemp
parameter_list|(
name|atf_fs_path_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_fs_rmdir
parameter_list|(
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_fs_unlink
parameter_list|(
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(ATF_C_DETAIL_FS_H) */
end_comment

end_unit

