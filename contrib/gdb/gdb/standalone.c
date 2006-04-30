begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface to bare machine for GDB running as kernel debugger.     Copyright 1986, 1989, 1991, 1992, 1993, 1995, 1996, 2000, 2001,    2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"gdb_stat.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SIGTSTP
argument_list|)
operator|&&
name|defined
argument_list|(
name|SIGIO
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGTSTP and SIGIO defined (must be 4.2) */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_include
include|#
directive|include
file|"frame.h"
end_include

begin_include
include|#
directive|include
file|"inferior.h"
end_include

begin_include
include|#
directive|include
file|"gdb_wait.h"
end_include

begin_escape
end_escape

begin_comment
comment|/* Random system calls, mostly no-ops to prevent link problems  */
end_comment

begin_macro
name|ioctl
argument_list|(
argument|int desc
argument_list|,
argument|int code
argument_list|,
argument|int arg
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_macro
name|int
argument_list|(
argument|*signal ()
argument_list|)
end_macro

begin_expr_stmt
operator|(
operator|)
block|{ }
name|kill
argument_list|(
argument|void
argument_list|)
block|{ }
name|getpid
argument_list|(
argument|void
argument_list|)
block|{
return|return
literal|0
return|;
block|}
end_expr_stmt

begin_macro
name|sigsetmask
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_macro
name|chdir
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_function
name|char
modifier|*
name|getcwd
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
block|{
name|buf
index|[
literal|0
index|]
operator|=
literal|'/'
expr_stmt|;
name|buf
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
return|return
name|buf
return|;
block|}
end_function

begin_comment
comment|/* Used to check for existence of .gdbinit.  Say no.  */
end_comment

begin_macro
name|access
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
return|return
operator|-
literal|1
return|;
block|}
end_block

begin_macro
name|exit
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|error
argument_list|(
literal|"Fatal error; restarting."
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* Reading "files".  The contents of some files are written into kdb's    data area before it is run.  These files are used to contain the    symbol table for kdb to load, and the source files (in case the    kdb user wants to print them).  The symbols are stored in a file    named "kdb-symbols" in a.out format (except that all the text and    data have been stripped to save room).     The files are stored in the following format:    int     number of bytes of data for this file, including these four.    char[]  name of the file, ending with a null.    padding to multiple of 4 boundary.    char[]  file contents.  The length can be deduced from what was    specified before.  There is no terminating null here.     If the int at the front is zero, it means there are no more files.     Opening a file in kdb returns a nonzero value to indicate success,    but the value does not matter.  Only one file can be open, and only    for reading.  All the primitives for input from the file know    which file is open and ignore what is specified for the descriptor    or for the stdio stream.     Input with fgetc can be done either on the file that is open    or on stdin (which reads from the terminal through tty_input ()  */
end_comment

begin_comment
comment|/* Address of data for the files stored in format described above.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|files_start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The file stream currently open:  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|sourcebeg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* beginning of contents */
end_comment

begin_decl_stmt
name|int
name|sourcesize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of contents */
end_comment

begin_decl_stmt
name|char
modifier|*
name|sourceptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current read pointer */
end_comment

begin_decl_stmt
name|int
name|sourceleft
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of bytes to eof */
end_comment

begin_comment
comment|/* "descriptor" for the file now open.    Incremented at each close.    If specified descriptor does not match this,    it means the program is trying to use a closed descriptor.    We report an error for that.  */
end_comment

begin_decl_stmt
name|int
name|sourcedesc
decl_stmt|;
end_decl_stmt

begin_macro
name|open
argument_list|(
argument|char *filename
argument_list|,
argument|int modes
argument_list|)
end_macro

begin_block
block|{
name|char
modifier|*
name|next
decl_stmt|;
if|if
condition|(
name|modes
condition|)
block|{
name|errno
operator|=
name|EROFS
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|sourceptr
condition|)
block|{
name|errno
operator|=
name|EMFILE
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
for|for
control|(
name|next
operator|=
name|files_start
init|;
operator|*
operator|(
name|int
operator|*
operator|)
name|next
condition|;
name|next
operator|+=
operator|*
operator|(
name|int
operator|*
operator|)
name|next
control|)
block|{
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|next
operator|+
literal|4
argument_list|,
name|filename
argument_list|)
condition|)
block|{
name|sourcebeg
operator|=
name|next
operator|+
literal|4
operator|+
name|strlen
argument_list|(
name|next
operator|+
literal|4
argument_list|)
operator|+
literal|1
expr_stmt|;
name|sourcebeg
operator|=
operator|(
name|char
operator|*
operator|)
operator|(
operator|(
operator|(
name|int
operator|)
name|sourcebeg
operator|+
literal|3
operator|)
operator|&
operator|(
operator|-
literal|4
operator|)
operator|)
expr_stmt|;
name|sourceptr
operator|=
name|sourcebeg
expr_stmt|;
name|sourcesize
operator|=
name|next
operator|+
operator|*
operator|(
name|int
operator|*
operator|)
name|next
operator|-
name|sourceptr
expr_stmt|;
name|sourceleft
operator|=
name|sourcesize
expr_stmt|;
return|return
name|sourcedesc
return|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|close
argument_list|(
argument|int desc
argument_list|)
end_macro

begin_block
block|{
name|sourceptr
operator|=
literal|0
expr_stmt|;
name|sourcedesc
operator|++
expr_stmt|;
comment|/* Don't let sourcedesc get big enough to be confused with stdin.  */
if|if
condition|(
name|sourcedesc
operator|==
literal|100
condition|)
name|sourcedesc
operator|=
literal|5
expr_stmt|;
block|}
end_block

begin_function
name|FILE
modifier|*
name|fopen
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|,
name|char
modifier|*
name|modes
parameter_list|)
block|{
return|return
operator|(
name|FILE
operator|*
operator|)
name|open
argument_list|(
name|filename
argument_list|,
operator|*
name|modes
operator|==
literal|'w'
argument_list|)
return|;
block|}
end_function

begin_function
name|FILE
modifier|*
name|fdopen
parameter_list|(
name|int
name|desc
parameter_list|)
block|{
return|return
operator|(
name|FILE
operator|*
operator|)
name|desc
return|;
block|}
end_function

begin_macro
name|fclose
argument_list|(
argument|int desc
argument_list|)
end_macro

begin_block
block|{
name|close
argument_list|(
name|desc
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|fstat
argument_list|(
argument|int desc
argument_list|,
argument|struct stat *statbuf
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|desc
operator|!=
name|sourcedesc
condition|)
block|{
name|errno
operator|=
name|EBADF
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
name|statbuf
operator|->
name|st_size
operator|=
name|sourcesize
expr_stmt|;
block|}
end_block

begin_macro
name|myread
argument_list|(
argument|int desc
argument_list|,
argument|char *destptr
argument_list|,
argument|int size
argument_list|,
argument|char *filename
argument_list|)
end_macro

begin_block
block|{
name|int
name|len
init|=
name|min
argument_list|(
name|sourceleft
argument_list|,
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|desc
operator|!=
name|sourcedesc
condition|)
block|{
name|errno
operator|=
name|EBADF
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
name|memcpy
argument_list|(
name|destptr
argument_list|,
name|sourceptr
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|sourceleft
operator|-=
name|len
expr_stmt|;
return|return
name|len
return|;
block|}
end_block

begin_function
name|int
name|fread
parameter_list|(
name|int
name|bufp
parameter_list|,
name|int
name|numelts
parameter_list|,
name|int
name|eltsize
parameter_list|,
name|int
name|stream
parameter_list|)
block|{
name|int
name|elts
init|=
name|min
argument_list|(
name|numelts
argument_list|,
name|sourceleft
operator|/
name|eltsize
argument_list|)
decl_stmt|;
name|int
name|len
init|=
name|elts
operator|*
name|eltsize
decl_stmt|;
if|if
condition|(
name|stream
operator|!=
name|sourcedesc
condition|)
block|{
name|errno
operator|=
name|EBADF
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
name|memcpy
argument_list|(
name|bufp
argument_list|,
name|sourceptr
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|sourceleft
operator|-=
name|len
expr_stmt|;
return|return
name|elts
return|;
block|}
end_function

begin_function
name|int
name|fgetc
parameter_list|(
name|int
name|desc
parameter_list|)
block|{
if|if
condition|(
name|desc
operator|==
operator|(
name|int
operator|)
name|stdin
condition|)
return|return
name|tty_input
argument_list|()
return|;
if|if
condition|(
name|desc
operator|!=
name|sourcedesc
condition|)
block|{
name|errno
operator|=
name|EBADF
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|sourceleft
operator|--
operator|<=
literal|0
condition|)
return|return
name|EOF
return|;
return|return
operator|*
name|sourceptr
operator|++
return|;
block|}
end_function

begin_macro
name|lseek
argument_list|(
argument|int desc
argument_list|,
argument|int pos
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|desc
operator|!=
name|sourcedesc
condition|)
block|{
name|errno
operator|=
name|EBADF
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|pos
operator|<
literal|0
operator|||
name|pos
operator|>
name|sourcesize
condition|)
block|{
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
name|sourceptr
operator|=
name|sourcebeg
operator|+
name|pos
expr_stmt|;
name|sourceleft
operator|=
name|sourcesize
operator|-
name|pos
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* Output in kdb can go only to the terminal, so the stream    specified may be ignored.  */
end_comment

begin_macro
name|printf
argument_list|(
argument|int a1
argument_list|,
argument|int a2
argument_list|,
argument|int a3
argument_list|,
argument|int a4
argument_list|,
argument|int a5
argument_list|,
argument|int a6
argument_list|,
argument|int a7
argument_list|,
argument|int a8
argument_list|,
argument|int a9
argument_list|)
end_macro

begin_block
block|{
name|char
name|buffer
index|[
literal|1024
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|buffer
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
name|a4
argument_list|,
name|a5
argument_list|,
name|a6
argument_list|,
name|a7
argument_list|,
name|a8
argument_list|,
name|a9
argument_list|)
expr_stmt|;
name|display_string
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|fprintf
argument_list|(
argument|int ign
argument_list|,
argument|int a1
argument_list|,
argument|int a2
argument_list|,
argument|int a3
argument_list|,
argument|int a4
argument_list|,
argument|int a5
argument_list|,
argument|int a6
argument_list|,
argument|int a7
argument_list|,
argument|int a8
argument_list|,
argument|int a9
argument_list|)
end_macro

begin_block
block|{
name|char
name|buffer
index|[
literal|1024
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|buffer
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
name|a4
argument_list|,
name|a5
argument_list|,
name|a6
argument_list|,
name|a7
argument_list|,
name|a8
argument_list|,
name|a9
argument_list|)
expr_stmt|;
name|display_string
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|fwrite
argument_list|(
argument|char *buf
argument_list|,
argument|int numelts
argument_list|,
argument|int size
argument_list|,
argument|int stream
argument_list|)
end_macro

begin_block
block|{
name|int
name|i
init|=
name|numelts
operator|*
name|size
decl_stmt|;
while|while
condition|(
name|i
operator|--
operator|>
literal|0
condition|)
name|fputc
argument_list|(
operator|*
name|buf
operator|++
argument_list|,
name|stream
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|fputc
argument_list|(
argument|int c
argument_list|,
argument|int ign
argument_list|)
end_macro

begin_block
block|{
name|char
name|buf
index|[
literal|2
index|]
decl_stmt|;
name|buf
index|[
literal|0
index|]
operator|=
name|c
expr_stmt|;
name|buf
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
name|display_string
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* sprintf refers to this, but loading this from the    library would cause fflush to be loaded from it too.    In fact there should be no need to call this (I hope).  */
end_comment

begin_macro
name|_flsbuf
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|error
argument_list|(
literal|"_flsbuf was actually called."
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|fflush
argument_list|(
argument|int ign
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_escape
end_escape

begin_comment
comment|/* Entries into core and inflow, needed only to make things link ok.  */
end_comment

begin_macro
name|exec_file_command
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_macro
name|core_file_command
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_function
name|char
modifier|*
name|get_exec_file
parameter_list|(
name|int
name|err
parameter_list|)
block|{
comment|/* Makes one printout look reasonable; value does not matter otherwise.  */
return|return
literal|"run"
return|;
block|}
end_function

begin_comment
comment|/* Nonzero if there is a core file.  */
end_comment

begin_macro
name|have_core_file_p
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|kill_command
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|inferior_ptid
operator|=
name|null_ptid
expr_stmt|;
block|}
end_block

begin_macro
name|terminal_inferior
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_macro
name|terminal_ours
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_macro
name|terminal_init_inferior
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_macro
name|write_inferior_register
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_macro
name|read_inferior_register
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_macro
name|read_memory
argument_list|(
argument|CORE_ADDR memaddr
argument_list|,
argument|char *myaddr
argument_list|,
argument|int len
argument_list|)
end_macro

begin_block
block|{
name|memcpy
argument_list|(
name|myaddr
argument_list|,
name|memaddr
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Always return 0 indicating success.  */
end_comment

begin_macro
name|write_memory
argument_list|(
argument|CORE_ADDR memaddr
argument_list|,
argument|char *myaddr
argument_list|,
argument|int len
argument_list|)
end_macro

begin_block
block|{
name|memcpy
argument_list|(
name|memaddr
argument_list|,
name|myaddr
argument_list|,
name|len
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_decl_stmt
specifier|static
name|REGISTER_TYPE
name|saved_regs
index|[
name|NUM_REGS
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|REGISTER_TYPE
name|read_register
parameter_list|(
name|int
name|regno
parameter_list|)
block|{
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
literal|"Register number %d out of range."
argument_list|,
name|regno
argument_list|)
expr_stmt|;
return|return
name|saved_regs
index|[
name|regno
index|]
return|;
block|}
end_function

begin_function
name|void
name|write_register
parameter_list|(
name|int
name|regno
parameter_list|,
name|REGISTER_TYPE
name|value
parameter_list|)
block|{
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
literal|"Register number %d out of range."
argument_list|,
name|regno
argument_list|)
expr_stmt|;
name|saved_regs
index|[
name|regno
index|]
operator|=
name|value
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* System calls needed in relation to running the "inferior".  */
end_comment

begin_macro
name|vfork
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
comment|/* Just appear to "succeed".  Say the inferior's pid is 1.  */
return|return
literal|1
return|;
block|}
end_block

begin_comment
comment|/* These are called by code that normally runs in the inferior    that has just been forked.  That code never runs, when standalone,    and these definitions are so it will link without errors.  */
end_comment

begin_macro
name|ptrace
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_macro
name|setpgrp
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_macro
name|execle
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_macro
name|_exit
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_escape
end_escape

begin_comment
comment|/* Malloc calls these.  */
end_comment

begin_macro
name|malloc_warning
argument_list|(
argument|char *str
argument_list|)
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"\n%s.\n\n"
argument_list|,
name|str
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
name|char
modifier|*
name|next_free
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|memory_limit
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|sbrk
parameter_list|(
name|int
name|amount
parameter_list|)
block|{
if|if
condition|(
name|next_free
operator|+
name|amount
operator|>
name|memory_limit
condition|)
return|return
operator|(
name|char
operator|*
operator|)
operator|-
literal|1
return|;
name|next_free
operator|+=
name|amount
expr_stmt|;
return|return
name|next_free
operator|-
name|amount
return|;
block|}
end_function

begin_comment
comment|/* Various ways malloc might ask where end of memory is.  */
end_comment

begin_function
name|char
modifier|*
name|ulimit
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|memory_limit
return|;
block|}
end_function

begin_function
name|int
name|vlimit
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|memory_limit
operator|-
name|next_free
return|;
block|}
end_function

begin_macro
name|getrlimit
argument_list|(
argument|struct rlimit *addr
argument_list|)
end_macro

begin_block
block|{
name|addr
operator|->
name|rlim_cur
operator|=
name|memory_limit
operator|-
name|next_free
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* Context switching to and from program being debugged.  */
end_comment

begin_comment
comment|/* GDB calls here to run the user program.    The frame pointer for this function is saved in    gdb_stack by save_frame_pointer; then we restore    all of the user program's registers, including PC and PS.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|fault_code
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|REGISTER_TYPE
name|gdb_stack
decl_stmt|;
end_decl_stmt

begin_macro
name|resume
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|REGISTER_TYPE
name|restore
index|[
name|NUM_REGS
index|]
decl_stmt|;
name|PUSH_FRAME_PTR
expr_stmt|;
name|save_frame_pointer
argument_list|()
expr_stmt|;
name|memcpy
argument_list|(
name|restore
argument_list|,
name|saved_regs
argument_list|,
sizeof|sizeof
name|restore
argument_list|)
expr_stmt|;
name|POP_REGISTERS
expr_stmt|;
comment|/* Control does not drop through here!  */
block|}
end_block

begin_macro
name|save_frame_pointer
argument_list|(
argument|CORE_ADDR val
argument_list|)
end_macro

begin_block
block|{
name|gdb_stack
operator|=
name|val
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Fault handlers call here, running in the user program stack.    They must first push a fault code,    old PC, old PS, and any other info about the fault.    The exact format is machine-dependent and is known only    in the definition of PUSH_REGISTERS.  */
end_comment

begin_macro
name|fault
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
comment|/* Transfer all registers and fault code to the stack      in canonical order: registers in order of GDB register number,      followed by fault code.  */
name|PUSH_REGISTERS
expr_stmt|;
comment|/* Transfer them to saved_regs and fault_code.  */
name|save_registers
argument_list|()
expr_stmt|;
name|restore_gdb
argument_list|()
expr_stmt|;
comment|/* Control does not reach here */
block|}
end_block

begin_macro
name|restore_gdb
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|CORE_ADDR
name|new_fp
init|=
name|gdb_stack
decl_stmt|;
comment|/* Switch to GDB's stack  */
name|POP_FRAME_PTR
expr_stmt|;
comment|/* Return from the function `resume'.  */
block|}
end_block

begin_comment
comment|/* Assuming register contents and fault code have been pushed on the stack as    arguments to this function, copy them into the standard place    for the program's registers while GDB is running.  */
end_comment

begin_macro
name|save_registers
argument_list|(
argument|int firstreg
argument_list|)
end_macro

begin_block
block|{
name|memcpy
argument_list|(
name|saved_regs
argument_list|,
operator|&
name|firstreg
argument_list|,
sizeof|sizeof
name|saved_regs
argument_list|)
expr_stmt|;
name|fault_code
operator|=
operator|(
operator|&
name|firstreg
operator|)
index|[
name|NUM_REGS
index|]
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Store into the structure such as `wait' would return    the information on why the program faulted,    converted into a machine-independent signal number.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|fault_table
index|[]
init|=
name|FAULT_TABLE
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|wait
parameter_list|(
name|WAITTYPE
modifier|*
name|w
parameter_list|)
block|{
name|WSETSTOP
argument_list|(
operator|*
name|w
argument_list|,
name|fault_table
index|[
name|fault_code
operator|/
name|FAULT_CODE_UNITS
index|]
argument_list|)
expr_stmt|;
return|return
name|PIDGET
argument_list|(
name|inferior_ptid
argument_list|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Allocate a big space in which files for kdb to read will be stored.    Whatever is left is where malloc can allocate storage.     Initialize it, so that there will be space in the executable file    for it.  Then the files can be put into kdb by writing them into    kdb's executable file.  */
end_comment

begin_comment
comment|/* The default size is as much space as we expect to be available    for kdb to use!  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEAP_SIZE
end_ifndef

begin_define
define|#
directive|define
name|HEAP_SIZE
value|400000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
name|heap
index|[
name|HEAP_SIZE
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|STACK_SIZE
end_ifndef

begin_define
define|#
directive|define
name|STACK_SIZE
value|100000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|kdb_stack_beg
index|[
name|STACK_SIZE
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kdb_stack_end
decl_stmt|;
end_decl_stmt

begin_macro
name|_initialize_standalone
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|char
modifier|*
name|next
decl_stmt|;
comment|/* Find start of data on files.  */
name|files_start
operator|=
name|heap
expr_stmt|;
comment|/* Find the end of the data on files.  */
for|for
control|(
name|next
operator|=
name|files_start
init|;
operator|*
operator|(
name|int
operator|*
operator|)
name|next
condition|;
name|next
operator|+=
operator|*
operator|(
name|int
operator|*
operator|)
name|next
control|)
block|{     }
comment|/* That is where free storage starts for sbrk to give out.  */
name|next_free
operator|=
name|next
expr_stmt|;
name|memory_limit
operator|=
name|heap
operator|+
sizeof|sizeof
name|heap
expr_stmt|;
block|}
end_block

end_unit

