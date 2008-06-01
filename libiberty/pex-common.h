begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Utilities to execute a program in a subprocess (possibly linked by pipes    with other subprocesses), and wait for it.  Shared logic.    Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2003, 2004    Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PEX_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|PEX_COMMON_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|install_error_msg
value|"installation problem, cannot exec `%s'"
end_define

begin_comment
comment|/* stdin file number.  */
end_comment

begin_define
define|#
directive|define
name|STDIN_FILE_NO
value|0
end_define

begin_comment
comment|/* stdout file number.  */
end_comment

begin_define
define|#
directive|define
name|STDOUT_FILE_NO
value|1
end_define

begin_comment
comment|/* stderr file number.  */
end_comment

begin_define
define|#
directive|define
name|STDERR_FILE_NO
value|2
end_define

begin_comment
comment|/* value of `pipe': port index for reading.  */
end_comment

begin_define
define|#
directive|define
name|READ_PORT
value|0
end_define

begin_comment
comment|/* value of `pipe': port index for writing.  */
end_comment

begin_define
define|#
directive|define
name|WRITE_PORT
value|1
end_define

begin_comment
comment|/* The structure used by pex_init and friends.  */
end_comment

begin_struct
struct|struct
name|pex_obj
block|{
comment|/* Flags.  */
name|int
name|flags
decl_stmt|;
comment|/* Name of calling program, for error messages.  */
specifier|const
name|char
modifier|*
name|pname
decl_stmt|;
comment|/* Base name to use for temporary files.  */
specifier|const
name|char
modifier|*
name|tempbase
decl_stmt|;
comment|/* Pipe to use as stdin for next process.  */
name|int
name|next_input
decl_stmt|;
comment|/* File name to use as stdin for next process.  */
name|char
modifier|*
name|next_input_name
decl_stmt|;
comment|/* Whether next_input_name was allocated using malloc.  */
name|int
name|next_input_name_allocated
decl_stmt|;
comment|/* Number of child processes.  */
name|int
name|count
decl_stmt|;
comment|/* PIDs of child processes; array allocated using malloc.  */
name|long
modifier|*
name|children
decl_stmt|;
comment|/* Exit statuses of child processes; array allocated using malloc.  */
name|int
modifier|*
name|status
decl_stmt|;
comment|/* Time used by child processes; array allocated using malloc.  */
name|struct
name|pex_time
modifier|*
name|time
decl_stmt|;
comment|/* Number of children we have already waited for.  */
name|int
name|number_waited
decl_stmt|;
comment|/* FILE created by pex_input_file.  */
name|FILE
modifier|*
name|input_file
decl_stmt|;
comment|/* FILE created by pex_read_output.  */
name|FILE
modifier|*
name|read_output
decl_stmt|;
comment|/* Number of temporary files to remove.  */
name|int
name|remove_count
decl_stmt|;
comment|/* List of temporary files to remove; array allocated using malloc      of strings allocated using malloc.  */
name|char
modifier|*
modifier|*
name|remove
decl_stmt|;
comment|/* Pointers to system dependent functions.  */
specifier|const
name|struct
name|pex_funcs
modifier|*
name|funcs
decl_stmt|;
comment|/* For use by system dependent code.  */
name|void
modifier|*
name|sysdep
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Functions passed to pex_run_common.  */
end_comment

begin_struct
struct|struct
name|pex_funcs
block|{
comment|/* Open file NAME for reading.  If BINARY is non-zero, open in      binary mode.  Return>= 0 on success, -1 on error.  */
name|int
function_decl|(
modifier|*
name|open_read
function_decl|)
parameter_list|(
name|struct
name|pex_obj
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
comment|/* name */
parameter_list|,
name|int
comment|/* binary */
parameter_list|)
function_decl|;
comment|/* Open file NAME for writing.  If BINARY is non-zero, open in      binary mode.  Return>= 0 on success, -1 on error.  */
name|int
function_decl|(
modifier|*
name|open_write
function_decl|)
parameter_list|(
name|struct
name|pex_obj
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
comment|/* name */
parameter_list|,
name|int
comment|/* binary */
parameter_list|)
function_decl|;
comment|/* Execute a child process.  FLAGS, EXECUTABLE, ARGV, ERR are from      pex_run.  IN, OUT, ERRDES, TOCLOSE are all descriptors, from      open_read, open_write, or pipe, or they are one of STDIN_FILE_NO,      STDOUT_FILE_NO or STDERR_FILE_NO; if IN, OUT, and ERRDES are not      STD*_FILE_NO, they should be closed.  If the descriptor TOCLOSE      is not -1, and the system supports pipes, TOCLOSE should be      closed in the child process.  The function should handle the      PEX_STDERR_TO_STDOUT flag.  Return>= 0 on success, or -1 on      error and set *ERRMSG and *ERR.  */
name|long
function_decl|(
modifier|*
name|exec_child
function_decl|)
parameter_list|(
name|struct
name|pex_obj
modifier|*
parameter_list|,
name|int
comment|/* flags */
parameter_list|,
specifier|const
name|char
modifier|*
comment|/* executable */
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
comment|/* argv */
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
comment|/* env */
parameter_list|,
name|int
comment|/* in */
parameter_list|,
name|int
comment|/* out */
parameter_list|,
name|int
comment|/* errdes */
parameter_list|,
name|int
comment|/* toclose */
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
comment|/* errmsg */
parameter_list|,
name|int
modifier|*
comment|/* err */
parameter_list|)
function_decl|;
comment|/* Close a descriptor.  Return 0 on success, -1 on error.  */
name|int
function_decl|(
modifier|*
name|close
function_decl|)
parameter_list|(
name|struct
name|pex_obj
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Wait for a child to complete, returning exit status in *STATUS      and time in *TIME (if it is not null).  CHILD is from fork.  DONE      is 1 if this is called via pex_free.  ERRMSG and ERR are as in      fork.  Return 0 on success, -1 on error.  */
name|int
function_decl|(
modifier|*
name|wait
function_decl|)
parameter_list|(
name|struct
name|pex_obj
modifier|*
parameter_list|,
name|long
comment|/* child */
parameter_list|,
name|int
modifier|*
comment|/* status */
parameter_list|,
name|struct
name|pex_time
modifier|*
comment|/* time */
parameter_list|,
name|int
comment|/* done */
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
comment|/* errmsg */
parameter_list|,
name|int
modifier|*
comment|/* err */
parameter_list|)
function_decl|;
comment|/* Create a pipe (only called if PEX_USE_PIPES is set) storing two      descriptors in P[0] and P[1].  If BINARY is non-zero, open in      binary mode.  Return 0 on success, -1 on error.  */
name|int
function_decl|(
modifier|*
name|pipe
function_decl|)
parameter_list|(
name|struct
name|pex_obj
modifier|*
parameter_list|,
name|int
modifier|*
comment|/* p */
parameter_list|,
name|int
comment|/* binary */
parameter_list|)
function_decl|;
comment|/* Get a FILE pointer to read from a file descriptor (only called if      PEX_USE_PIPES is set).  If BINARY is non-zero, open in binary      mode.  Return pointer on success, NULL on error.  */
name|FILE
modifier|*
function_decl|(
modifier|*
name|fdopenr
function_decl|)
parameter_list|(
name|struct
name|pex_obj
modifier|*
parameter_list|,
name|int
comment|/* fd */
parameter_list|,
name|int
comment|/* binary */
parameter_list|)
function_decl|;
comment|/* Get a FILE pointer to write to the file descriptor FD (only      called if PEX_USE_PIPES is set).  If BINARY is non-zero, open in      binary mode.  Arrange for FD not to be inherited by the child      processes.  Return pointer on success, NULL on error.  */
name|FILE
modifier|*
function_decl|(
modifier|*
name|fdopenw
function_decl|)
parameter_list|(
name|struct
name|pex_obj
modifier|*
parameter_list|,
name|int
comment|/* fd */
parameter_list|,
name|int
comment|/* binary */
parameter_list|)
function_decl|;
comment|/* Free any system dependent data associated with OBJ.  May be      NULL if there is nothing to do.  */
name|void
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|struct
name|pex_obj
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|struct
name|pex_obj
modifier|*
name|pex_init_common
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|pex_funcs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

