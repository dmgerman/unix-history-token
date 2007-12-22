begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_DIR2_TRACE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_DIR2_TRACE_H__
end_define

begin_comment
comment|/*  * Tracing for xfs v2 directories.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XFS_DIR2_TRACE
argument_list|)
end_if

begin_struct_decl
struct_decl|struct
name|ktrace
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_dabuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_da_args
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|XFS_DIR2_GTRACE_SIZE
value|4096
end_define

begin_comment
comment|/* global buffer */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_KTRACE_SIZE
value|32
end_define

begin_comment
comment|/* per-inode buffer */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ktrace
modifier|*
name|xfs_dir2_trace_buf
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|XFS_DIR2_KTRACE_ARGS
value|1
end_define

begin_comment
comment|/* args only */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_KTRACE_ARGS_B
value|2
end_define

begin_comment
comment|/* args + buffer */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_KTRACE_ARGS_BB
value|3
end_define

begin_comment
comment|/* args + 2 buffers */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_KTRACE_ARGS_DB
value|4
end_define

begin_comment
comment|/* args, db, buffer */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_KTRACE_ARGS_I
value|5
end_define

begin_comment
comment|/* args, inum */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_KTRACE_ARGS_S
value|6
end_define

begin_comment
comment|/* args, int */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_KTRACE_ARGS_SB
value|7
end_define

begin_comment
comment|/* args, int, buffer */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_KTRACE_ARGS_BIBII
value|8
end_define

begin_comment
comment|/* args, buf/int/buf/int/int */
end_comment

begin_function_decl
name|void
name|xfs_dir2_trace_args
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_dir2_trace_args_b
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_dir2_trace_args_bb
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|lbp
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|dbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_dir2_trace_args_bibii
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|bs
parameter_list|,
name|int
name|ss
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|bd
parameter_list|,
name|int
name|sd
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_dir2_trace_args_db
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|xfs_dir2_db_t
name|db
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_dir2_trace_args_i
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|xfs_ino_t
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_dir2_trace_args_s
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|int
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_dir2_trace_args_sb
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|int
name|s
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* XFS_DIR2_TRACE */
end_comment

begin_define
define|#
directive|define
name|xfs_dir2_trace_args
parameter_list|(
name|where
parameter_list|,
name|args
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_dir2_trace_args_b
parameter_list|(
name|where
parameter_list|,
name|args
parameter_list|,
name|bp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_dir2_trace_args_bb
parameter_list|(
name|where
parameter_list|,
name|args
parameter_list|,
name|lbp
parameter_list|,
name|dbp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_dir2_trace_args_bibii
parameter_list|(
name|where
parameter_list|,
name|args
parameter_list|,
name|bs
parameter_list|,
name|ss
parameter_list|,
name|bd
parameter_list|,
name|sd
parameter_list|,
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_dir2_trace_args_db
parameter_list|(
name|where
parameter_list|,
name|args
parameter_list|,
name|db
parameter_list|,
name|bp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_dir2_trace_args_i
parameter_list|(
name|where
parameter_list|,
name|args
parameter_list|,
name|i
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_dir2_trace_args_s
parameter_list|(
name|where
parameter_list|,
name|args
parameter_list|,
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_dir2_trace_args_sb
parameter_list|(
name|where
parameter_list|,
name|args
parameter_list|,
name|s
parameter_list|,
name|bp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XFS_DIR2_TRACE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_DIR2_TRACE_H__ */
end_comment

end_unit

