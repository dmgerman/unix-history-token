begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This code is derived from software copyrighted by the Free Software  * Foundation.  *  * Modified 1991 by Donn Seeley at UUNET Technologies, Inc.  * Modified 1990 by Van Jacobson at Lawrence Berkeley Laboratory.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)core.c	6.3 (Berkeley) 5/8/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/* Work with core dump and executable files, for GDB.    Copyright (C) 1986, 1987, 1989 Free Software Foundation, Inc.  This file is part of GDB.  GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GDB; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"frame.h"
end_include

begin_comment
comment|/* required by inferior.h */
end_comment

begin_include
include|#
directive|include
file|"inferior.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|COFF_ENCAPSULATE
end_ifdef

begin_include
include|#
directive|include
file|"a.out.encap.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<a.out.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_MAGIC
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|COFF_FORMAT
end_ifdef

begin_define
define|#
directive|define
name|N_MAGIC
parameter_list|(
name|exec
parameter_list|)
value|((exec).magic)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|N_MAGIC
parameter_list|(
name|exec
parameter_list|)
value|((exec).a_magic)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|UMAX_CORE
end_ifdef

begin_include
include|#
directive|include
file|<sys/ptrace.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_TXTADDR
end_ifndef

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|hdr
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no N_TXTADDR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_DATADDR
end_ifndef

begin_define
define|#
directive|define
name|N_DATADDR
parameter_list|(
name|hdr
parameter_list|)
value|hdr.a_text
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no N_DATADDR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COFF_FORMAT
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|AOUTHDR
end_ifndef

begin_define
define|#
directive|define
name|AOUTHDR
value|struct exec
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_siglist
index|[]
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern core_file_command (
end_extern

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|exec_file_command
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Hook for `exec_file_command' command to call.  */
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|exec_file_display_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* File names of core file and executable file.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|corefile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|execfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Descriptors on which core file and executable file are open.    Note that the execchan is closed when an inferior is created    and reopened if the inferior dies or is killed.  */
end_comment

begin_decl_stmt
name|int
name|corechan
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|execchan
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last modification time of executable file.    Also used in source.c to compare against mtime of a source file.  */
end_comment

begin_decl_stmt
name|int
name|exec_mtime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Virtual addresses of bounds of the two areas of memory in the core file.  */
end_comment

begin_decl_stmt
name|CORE_ADDR
name|data_start
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CORE_ADDR
name|data_end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CORE_ADDR
name|stack_start
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CORE_ADDR
name|stack_end
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|REG_STACK_SEGMENT
argument_list|)
end_if

begin_comment
comment|/* Start and end of the register stack segment.  */
end_comment

begin_decl_stmt
name|CORE_ADDR
name|reg_stack_start
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CORE_ADDR
name|reg_stack_end
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REG_STACK_SEGMENT */
end_comment

begin_comment
comment|/* Virtual addresses of bounds of two areas of memory in the exec file.    Note that the data area in the exec file is used only when there is no core file.  */
end_comment

begin_decl_stmt
name|CORE_ADDR
name|text_start
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CORE_ADDR
name|text_end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CORE_ADDR
name|exec_data_start
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CORE_ADDR
name|exec_data_end
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Offset within executable file of start of text area data.  */
end_comment

begin_decl_stmt
name|int
name|text_offset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Offset within executable file of start of data area data.  */
end_comment

begin_decl_stmt
name|int
name|exec_data_offset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Offset within core file of start of data area data.  */
end_comment

begin_decl_stmt
name|int
name|data_offset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Offset within core file of start of stack area data.  */
end_comment

begin_decl_stmt
name|int
name|stack_offset
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|COFF_FORMAT
end_ifdef

begin_comment
comment|/* various coff data structures */
end_comment

begin_decl_stmt
name|FILHDR
name|file_hdr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCNHDR
name|text_hdr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCNHDR
name|data_hdr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not COFF_FORMAT */
end_comment

begin_comment
comment|/* a.out header saved in core file.  */
end_comment

begin_decl_stmt
name|AOUTHDR
name|core_aouthdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a.out header of exec file.  */
end_comment

begin_decl_stmt
name|AOUTHDR
name|exec_aouthdr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|validate_files
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|register_addr
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Call this to specify the hook for exec_file_command to call back.    This is called from the x-window display code.  */
end_comment

begin_function_decl
name|void
name|specify_exec_file_hook
function_decl|(
name|hook
function_decl|)
name|void
argument_list|(
argument|*hook
argument_list|)
parameter_list|()
function_decl|;
end_function_decl

begin_block
block|{
name|exec_file_display_hook
operator|=
name|hook
expr_stmt|;
block|}
end_block

begin_comment
comment|/* The exec file must be closed before running an inferior.    If it is needed again after the inferior dies, it must    be reopened.  */
end_comment

begin_function
name|void
name|close_exec_file
parameter_list|()
block|{
if|if
condition|(
name|execchan
operator|>=
literal|0
condition|)
name|close
argument_list|(
name|execchan
argument_list|)
expr_stmt|;
name|execchan
operator|=
operator|-
literal|1
expr_stmt|;
block|}
end_function

begin_function
name|void
name|reopen_exec_file
parameter_list|()
block|{
if|if
condition|(
name|execchan
operator|<
literal|0
operator|&&
name|execfile
operator|!=
literal|0
condition|)
block|{
name|char
modifier|*
name|filename
init|=
name|concat
argument_list|(
name|execfile
argument_list|,
literal|""
argument_list|,
literal|""
argument_list|)
decl_stmt|;
name|exec_file_command
argument_list|(
name|filename
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|filename
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* If we have both a core file and an exec file,    print a warning if they don't go together.    This should really check that the core file came    from that exec file, but I don't know how to do it.  */
end_comment

begin_function
name|void
name|validate_files
parameter_list|()
block|{
if|if
condition|(
name|execfile
operator|!=
literal|0
operator|&&
name|corefile
operator|!=
literal|0
condition|)
block|{
name|struct
name|stat
name|st_core
decl_stmt|;
if|if
condition|(
name|fstat
argument_list|(
name|corechan
argument_list|,
operator|&
name|st_core
argument_list|)
operator|<
literal|0
condition|)
comment|/* It might be a good idea to print an error message. 	   On the other hand, if the user tries to *do* anything with 	   the core file, (s)he'll find out soon enough.  */
return|return;
if|if
condition|(
name|N_MAGIC
argument_list|(
name|core_aouthdr
argument_list|)
operator|!=
literal|0
operator|&&
name|bcmp
argument_list|(
operator|&
name|core_aouthdr
argument_list|,
operator|&
name|exec_aouthdr
argument_list|,
sizeof|sizeof
name|core_aouthdr
argument_list|)
condition|)
name|printf
argument_list|(
literal|"Warning: core file does not match specified executable file.\n"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|exec_mtime
operator|>
name|st_core
operator|.
name|st_mtime
condition|)
block|{
ifdef|#
directive|ifdef
name|KERNELDEBUG
specifier|extern
name|int
name|kernel_debugging
decl_stmt|;
if|if
condition|(
operator|!
name|kernel_debugging
condition|)
endif|#
directive|endif
name|printf
argument_list|(
literal|"Warning: exec file is newer than core file.\n"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_comment
comment|/* Return the name of the executable file as a string.    ERR nonzero means get error if there is none specified;    otherwise return 0 in that case.  */
end_comment

begin_function
name|char
modifier|*
name|get_exec_file
parameter_list|(
name|err
parameter_list|)
name|int
name|err
decl_stmt|;
block|{
if|if
condition|(
name|err
operator|&&
name|execfile
operator|==
literal|0
condition|)
name|error
argument_list|(
literal|"No executable file specified.\n\ Use the \"exec-file\" and \"symbol-file\" commands."
argument_list|)
expr_stmt|;
return|return
name|execfile
return|;
block|}
end_function

begin_function
name|int
name|have_core_file_p
parameter_list|()
block|{
return|return
name|corefile
operator|!=
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|files_info
parameter_list|()
block|{
name|char
modifier|*
name|symfile
decl_stmt|;
specifier|extern
name|char
modifier|*
name|get_sym_file
parameter_list|()
function_decl|;
if|if
condition|(
name|execfile
condition|)
name|printf
argument_list|(
literal|"Executable file \"%s\".\n"
argument_list|,
name|execfile
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"No executable file\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|corefile
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"No core dump file\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"Core dump file \"%s\".\n"
argument_list|,
name|corefile
argument_list|)
expr_stmt|;
if|if
condition|(
name|have_inferior_p
argument_list|()
condition|)
name|printf
argument_list|(
literal|"Using the running image of the program, rather than these files.\n"
argument_list|)
expr_stmt|;
name|symfile
operator|=
name|get_sym_file
argument_list|()
expr_stmt|;
if|if
condition|(
name|symfile
operator|!=
literal|0
condition|)
name|printf
argument_list|(
literal|"Symbols from \"%s\".\n"
argument_list|,
name|symfile
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|FILES_INFO_HOOK
if|if
condition|(
name|FILES_INFO_HOOK
argument_list|()
condition|)
return|return;
endif|#
directive|endif
if|if
condition|(
operator|!
name|have_inferior_p
argument_list|()
condition|)
block|{
if|if
condition|(
name|execfile
condition|)
block|{
name|printf
argument_list|(
literal|"Text segment in executable from 0x%x to 0x%x.\n"
argument_list|,
name|text_start
argument_list|,
name|text_end
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Data segment in executable from 0x%x to 0x%x.\n"
argument_list|,
name|exec_data_start
argument_list|,
name|exec_data_end
argument_list|)
expr_stmt|;
if|if
condition|(
name|corefile
condition|)
name|printf
argument_list|(
literal|"(But since we have a core file, we're using...)\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|corefile
condition|)
block|{
name|printf
argument_list|(
literal|"Data segment in core file from 0x%x to 0x%x.\n"
argument_list|,
name|data_start
argument_list|,
name|data_end
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Stack segment in core file from 0x%x to 0x%x.\n"
argument_list|,
name|stack_start
argument_list|,
name|stack_end
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Read "memory data" from core file and/or executable file.    Returns zero if successful, 1 if xfer_core_file failed, errno value if    ptrace failed. */
end_comment

begin_function
name|int
name|read_memory
parameter_list|(
name|memaddr
parameter_list|,
name|myaddr
parameter_list|,
name|len
parameter_list|)
name|CORE_ADDR
name|memaddr
decl_stmt|;
name|char
modifier|*
name|myaddr
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
if|if
condition|(
name|len
operator|==
literal|0
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|have_inferior_p
argument_list|()
condition|)
block|{
if|if
condition|(
name|remote_debugging
condition|)
return|return
name|remote_read_inferior_memory
argument_list|(
name|memaddr
argument_list|,
name|myaddr
argument_list|,
name|len
argument_list|)
return|;
else|else
return|return
name|read_inferior_memory
argument_list|(
name|memaddr
argument_list|,
name|myaddr
argument_list|,
name|len
argument_list|)
return|;
block|}
else|else
return|return
name|xfer_core_file
argument_list|(
name|memaddr
argument_list|,
name|myaddr
argument_list|,
name|len
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Write LEN bytes of data starting at address MYADDR    into debugged program memory at address MEMADDR.    Returns zero if successful, or an errno value if ptrace failed.  */
end_comment

begin_function
name|int
name|write_memory
parameter_list|(
name|memaddr
parameter_list|,
name|myaddr
parameter_list|,
name|len
parameter_list|)
name|CORE_ADDR
name|memaddr
decl_stmt|;
name|char
modifier|*
name|myaddr
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
if|if
condition|(
name|have_inferior_p
argument_list|()
condition|)
block|{
if|if
condition|(
name|remote_debugging
condition|)
return|return
name|remote_write_inferior_memory
argument_list|(
name|memaddr
argument_list|,
name|myaddr
argument_list|,
name|len
argument_list|)
return|;
else|else
return|return
name|write_inferior_memory
argument_list|(
name|memaddr
argument_list|,
name|myaddr
argument_list|,
name|len
argument_list|)
return|;
block|}
else|else
name|error
argument_list|(
literal|"Can write memory only when program being debugged is running."
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|XFER_CORE_FILE
end_ifndef

begin_function_decl
name|int
function_decl|(
modifier|*
name|core_file_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* hook to handle special core files like 				 like /dev/mem and crash dumps */
end_comment

begin_comment
comment|/* Read from the program's memory (except for inferior processes).    This function is misnamed, since it only reads, never writes; and    since it will use the core file and/or executable file as necessary.     It should be extended to write as well as read, FIXME, for patching files.     Return 0 if address could be read, 1 if not. */
end_comment

begin_function
name|int
name|xfer_core_file
parameter_list|(
name|memaddr
parameter_list|,
name|myaddr
parameter_list|,
name|len
parameter_list|)
name|CORE_ADDR
name|memaddr
decl_stmt|;
name|char
modifier|*
name|myaddr
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|;
specifier|register
name|int
name|val
decl_stmt|;
name|int
name|xferchan
decl_stmt|;
name|char
modifier|*
modifier|*
name|xferfile
decl_stmt|;
name|int
name|fileptr
decl_stmt|;
name|int
name|returnval
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|core_file_hook
condition|)
return|return
operator|(
call|(
modifier|*
name|core_file_hook
call|)
argument_list|(
name|memaddr
argument_list|,
name|myaddr
argument_list|,
name|len
argument_list|)
operator|)
return|;
while|while
condition|(
name|len
operator|>
literal|0
condition|)
block|{
name|xferfile
operator|=
literal|0
expr_stmt|;
name|xferchan
operator|=
literal|0
expr_stmt|;
comment|/* Determine which file the next bunch of addresses reside in, 	 and where in the file.  Set the file's read/write pointer 	 to point at the proper place for the desired address 	 and set xferfile and xferchan for the correct file.  	 If desired address is nonexistent, leave them zero.  	 i is set to the number of bytes that can be handled 	 along with the next address.  	 We put the most likely tests first for efficiency.  */
comment|/* Note that if there is no core file 	 data_start and data_end are equal.  */
if|if
condition|(
name|memaddr
operator|>=
name|data_start
operator|&&
name|memaddr
operator|<
name|data_end
condition|)
block|{
name|i
operator|=
name|min
argument_list|(
name|len
argument_list|,
name|data_end
operator|-
name|memaddr
argument_list|)
expr_stmt|;
name|fileptr
operator|=
name|memaddr
operator|-
name|data_start
operator|+
name|data_offset
expr_stmt|;
name|xferfile
operator|=
operator|&
name|corefile
expr_stmt|;
name|xferchan
operator|=
name|corechan
expr_stmt|;
block|}
comment|/* Note that if there is no core file 	 stack_start and stack_end are equal.  */
elseif|else
if|if
condition|(
name|memaddr
operator|>=
name|stack_start
operator|&&
name|memaddr
operator|<
name|stack_end
condition|)
block|{
name|i
operator|=
name|min
argument_list|(
name|len
argument_list|,
name|stack_end
operator|-
name|memaddr
argument_list|)
expr_stmt|;
name|fileptr
operator|=
name|memaddr
operator|-
name|stack_start
operator|+
name|stack_offset
expr_stmt|;
name|xferfile
operator|=
operator|&
name|corefile
expr_stmt|;
name|xferchan
operator|=
name|corechan
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|REG_STACK_SEGMENT
comment|/* Pyramids have an extra segment in the virtual address space          for the (control) stack of register-window frames */
elseif|else
if|if
condition|(
name|memaddr
operator|>=
name|reg_stack_start
operator|&&
name|memaddr
operator|<
name|reg_stack_end
condition|)
block|{
name|i
operator|=
name|min
argument_list|(
name|len
argument_list|,
name|reg_stack_end
operator|-
name|memaddr
argument_list|)
expr_stmt|;
name|fileptr
operator|=
name|memaddr
operator|-
name|reg_stack_start
operator|+
name|reg_stack_offset
expr_stmt|;
name|xferfile
operator|=
operator|&
name|corefile
expr_stmt|;
name|xferchan
operator|=
name|corechan
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* REG_STACK_SEGMENT */
elseif|else
if|if
condition|(
name|corechan
operator|<
literal|0
operator|&&
name|memaddr
operator|>=
name|exec_data_start
operator|&&
name|memaddr
operator|<
name|exec_data_end
condition|)
block|{
name|i
operator|=
name|min
argument_list|(
name|len
argument_list|,
name|exec_data_end
operator|-
name|memaddr
argument_list|)
expr_stmt|;
name|fileptr
operator|=
name|memaddr
operator|-
name|exec_data_start
operator|+
name|exec_data_offset
expr_stmt|;
name|xferfile
operator|=
operator|&
name|execfile
expr_stmt|;
name|xferchan
operator|=
name|execchan
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|memaddr
operator|>=
name|text_start
operator|&&
name|memaddr
operator|<
name|text_end
condition|)
block|{
name|i
operator|=
name|min
argument_list|(
name|len
argument_list|,
name|text_end
operator|-
name|memaddr
argument_list|)
expr_stmt|;
name|fileptr
operator|=
name|memaddr
operator|-
name|text_start
operator|+
name|text_offset
expr_stmt|;
name|xferfile
operator|=
operator|&
name|execfile
expr_stmt|;
name|xferchan
operator|=
name|execchan
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|memaddr
operator|<
name|text_start
condition|)
block|{
name|i
operator|=
name|min
argument_list|(
name|len
argument_list|,
name|text_start
operator|-
name|memaddr
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|memaddr
operator|>=
name|text_end
operator|&&
name|memaddr
operator|<
operator|(
name|corechan
operator|>=
literal|0
condition|?
name|data_start
else|:
name|exec_data_start
operator|)
condition|)
block|{
name|i
operator|=
name|min
argument_list|(
name|len
argument_list|,
name|data_start
operator|-
name|memaddr
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|corechan
operator|>=
literal|0
operator|&&
name|memaddr
operator|>=
name|data_end
operator|&&
name|memaddr
operator|<
name|stack_start
condition|)
block|{
name|i
operator|=
name|min
argument_list|(
name|len
argument_list|,
name|stack_start
operator|-
name|memaddr
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|corechan
operator|<
literal|0
operator|&&
name|memaddr
operator|>=
name|exec_data_end
condition|)
block|{
comment|/* Since there is nothing at higher addresses than data 	     (without a core file or an inferior, there is no 	     stack, set i to do the rest of the operation now.  */
name|i
operator|=
name|len
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|REG_STACK_SEGMENT
elseif|else
if|if
condition|(
name|memaddr
operator|>=
name|reg_stack_end
operator|&&
name|reg_stack_end
operator|!=
literal|0
condition|)
block|{
name|i
operator|=
name|min
argument_list|(
name|len
argument_list|,
name|reg_stack_start
operator|-
name|memaddr
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|memaddr
operator|>=
name|stack_end
operator|&&
name|memaddr
operator|<
name|reg_stack_start
condition|)
else|#
directive|else
comment|/* no REG_STACK_SEGMENT.  */
elseif|else
if|if
condition|(
name|memaddr
operator|>=
name|stack_end
operator|&&
name|stack_end
operator|!=
literal|0
condition|)
endif|#
directive|endif
comment|/* no REG_STACK_SEGMENT.  */
block|{
comment|/* Since there is nothing at higher addresses than 	     the stack, set i to do the rest of the operation now.  */
name|i
operator|=
name|len
expr_stmt|;
block|}
else|else
block|{
comment|/* Address did not classify into one of the known ranges. 	     This shouldn't happen; we catch the endpoints.  */
name|fatal
argument_list|(
literal|"Internal: Bad case logic in xfer_core_file."
argument_list|)
expr_stmt|;
block|}
comment|/* Now we know which file to use. 	 Set up its pointer and transfer the data.  */
if|if
condition|(
name|xferfile
condition|)
block|{
if|if
condition|(
operator|*
name|xferfile
operator|==
literal|0
condition|)
if|if
condition|(
name|xferfile
operator|==
operator|&
name|execfile
condition|)
name|error
argument_list|(
literal|"No program file to examine."
argument_list|)
expr_stmt|;
else|else
name|error
argument_list|(
literal|"No core dump file or running program to examine."
argument_list|)
expr_stmt|;
name|val
operator|=
name|lseek
argument_list|(
name|xferchan
argument_list|,
name|fileptr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|==
operator|-
literal|1
condition|)
name|perror_with_name
argument_list|(
operator|*
name|xferfile
argument_list|)
expr_stmt|;
name|val
operator|=
name|myread
argument_list|(
name|xferchan
argument_list|,
name|myaddr
argument_list|,
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|<
literal|0
condition|)
name|perror_with_name
argument_list|(
operator|*
name|xferfile
argument_list|)
expr_stmt|;
block|}
comment|/* If this address is for nonexistent memory, 	 read zeros if reading, or do nothing if writing. 	 Actually, we never right.  */
else|else
block|{
name|bzero
argument_list|(
name|myaddr
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|returnval
operator|=
literal|1
expr_stmt|;
block|}
name|memaddr
operator|+=
name|i
expr_stmt|;
name|myaddr
operator|+=
name|i
expr_stmt|;
name|len
operator|-=
name|i
expr_stmt|;
block|}
return|return
name|returnval
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XFER_CORE_FILE */
end_comment

begin_escape
end_escape

begin_comment
comment|/* My replacement for the read system call.    Used like `read' but keeps going if `read' returns too soon.  */
end_comment

begin_function
name|int
name|myread
parameter_list|(
name|desc
parameter_list|,
name|addr
parameter_list|,
name|len
parameter_list|)
name|int
name|desc
decl_stmt|;
name|char
modifier|*
name|addr
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
specifier|register
name|int
name|val
decl_stmt|;
name|int
name|orglen
init|=
name|len
decl_stmt|;
while|while
condition|(
name|len
operator|>
literal|0
condition|)
block|{
name|val
operator|=
name|read
argument_list|(
name|desc
argument_list|,
name|addr
argument_list|,
name|len
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|<
literal|0
condition|)
return|return
name|val
return|;
if|if
condition|(
name|val
operator|==
literal|0
condition|)
return|return
name|orglen
operator|-
name|len
return|;
name|len
operator|-=
name|val
expr_stmt|;
name|addr
operator|+=
name|val
expr_stmt|;
block|}
return|return
name|orglen
return|;
block|}
end_function

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|REGISTER_U_ADDR
end_ifdef

begin_comment
comment|/* Return the address in the core dump or inferior of register REGNO.    BLOCKEND is the address of the end of the user structure.  */
end_comment

begin_function
name|unsigned
name|int
name|register_addr
parameter_list|(
name|regno
parameter_list|,
name|blockend
parameter_list|)
name|int
name|regno
decl_stmt|;
name|int
name|blockend
decl_stmt|;
block|{
name|int
name|addr
decl_stmt|;
if|if
condition|(
name|regno
operator|<
literal|0
operator|||
name|regno
operator|>=
name|NUM_REGS
condition|)
name|error
argument_list|(
literal|"Invalid register number %d."
argument_list|,
name|regno
argument_list|)
expr_stmt|;
name|REGISTER_U_ADDR
argument_list|(
name|addr
argument_list|,
name|blockend
argument_list|,
name|regno
argument_list|)
expr_stmt|;
return|return
name|addr
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REGISTER_U_ADDR */
end_comment

begin_escape
end_escape

begin_function
name|void
name|_initialize_core
parameter_list|()
block|{
name|corechan
operator|=
operator|-
literal|1
expr_stmt|;
name|execchan
operator|=
operator|-
literal|1
expr_stmt|;
name|corefile
operator|=
literal|0
expr_stmt|;
name|execfile
operator|=
literal|0
expr_stmt|;
name|exec_file_display_hook
operator|=
literal|0
expr_stmt|;
name|text_start
operator|=
literal|0
expr_stmt|;
name|text_end
operator|=
literal|0
expr_stmt|;
name|data_start
operator|=
literal|0
expr_stmt|;
name|data_end
operator|=
literal|0
expr_stmt|;
name|exec_data_start
operator|=
literal|0
expr_stmt|;
name|exec_data_end
operator|=
literal|0
expr_stmt|;
name|stack_start
operator|=
name|STACK_END_ADDR
expr_stmt|;
name|stack_end
operator|=
name|STACK_END_ADDR
expr_stmt|;
name|add_com
argument_list|(
literal|"core-file"
argument_list|,
name|class_files
argument_list|,
name|core_file_command
argument_list|,
literal|"Use FILE as core dump for examining memory and registers.\n\ No arg means have no core file."
argument_list|)
expr_stmt|;
name|add_com
argument_list|(
literal|"exec-file"
argument_list|,
name|class_files
argument_list|,
name|exec_file_command
argument_list|,
literal|"Use FILE as program for getting contents of pure memory.\n\ If FILE cannot be found as specified, your execution directory path\n\ is searched for a command of that name.\n\ No arg means have no executable file."
argument_list|)
expr_stmt|;
name|add_info
argument_list|(
literal|"files"
argument_list|,
name|files_info
argument_list|,
literal|"Names of files being debugged."
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

