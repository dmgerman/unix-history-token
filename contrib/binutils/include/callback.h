begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Remote target system call callback support.    Copyright 1997 Free Software Foundation, Inc.    Contributed by Cygnus Solutions.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This interface isn't intended to be specific to any particular kind    of remote (hardware, simulator, whatever).  As such, support for it    (e.g. sim/common/callback.c) should *not* live in the simulator source    tree, nor should it live in the gdb source tree.  */
end_comment

begin_comment
comment|/* There are various ways to handle system calls:     1) Have a simulator intercept the appropriate trap instruction and    directly perform the system call on behalf of the target program.    This is the typical way of handling system calls for embedded targets.    [Handling system calls for embedded targets isn't that much of an    oxymoron as running compiler testsuites make use of the capability.]     This method of system call handling is done when STATE_ENVIRONMENT    is ENVIRONMENT_USER.     2) Have a simulator emulate the hardware as much as possible.    If the program running on the real hardware communicates with some sort    of target manager, one would want to be able to run this program on the    simulator as well.     This method of system call handling is done when STATE_ENVIRONMENT    is ENVIRONMENT_OPERATING. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CALLBACK_H
end_ifndef

begin_define
define|#
directive|define
name|CALLBACK_H
end_define

begin_comment
comment|/* ??? The reason why we check for va_start here should be documented.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|va_start
end_ifndef

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_PROTOTYPES
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Mapping of host/target values.  */
end_comment

begin_comment
comment|/* ??? For debugging purposes, one might want to add a string of the    name of the symbol.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|host_val
decl_stmt|;
name|int
name|target_val
decl_stmt|;
block|}
name|CB_TARGET_DEFS_MAP
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_CALLBACK_FDS
value|10
end_define

begin_comment
comment|/* Forward decl for stat/fstat.  */
end_comment

begin_struct_decl
struct_decl|struct
name|stat
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|host_callback_struct
name|host_callback
typedef|;
end_typedef

begin_struct
struct|struct
name|host_callback_struct
block|{
name|int
argument_list|(
argument|*close
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*get_errno
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*isatty
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*lseek
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
name|int
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*open
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
name|mode
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*read
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*read_stdin
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*rename
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*system
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
name|long
argument_list|(
argument|*time
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
name|long
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*unlink
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*write
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*write_stdout
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*flush_stdout
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*write_stderr
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*flush_stderr
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*stat
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*fstat
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
name|int
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* When present, call to the client to give it the oportunity to      poll any io devices for a request to quit (indicated by a nonzero      return value). */
name|int
argument_list|(
argument|*poll_quit
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Used when the target has gone away, so we can close open      handles and free memory etc etc.  */
name|int
argument_list|(
argument|*shutdown
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*init
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* depreciated, use vprintf_filtered - Talk to the user on a console.  */
name|void
argument_list|(
argument|*printf_filtered
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
expr_stmt|;
comment|/* Talk to the user on a console.  */
name|void
argument_list|(
argument|*vprintf_filtered
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|va_list
operator|)
argument_list|)
expr_stmt|;
comment|/* Same as vprintf_filtered but to stderr.  */
name|void
argument_list|(
argument|*evprintf_filtered
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|va_list
operator|)
argument_list|)
expr_stmt|;
comment|/* Print an error message and "exit".      In the case of gdb "exiting" means doing a longjmp back to the main      command loop.  */
name|void
argument_list|(
argument|*error
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
expr_stmt|;
name|int
name|last_errno
decl_stmt|;
comment|/* host format */
name|int
name|fdmap
index|[
name|MAX_CALLBACK_FDS
index|]
decl_stmt|;
name|char
name|fdopen
index|[
name|MAX_CALLBACK_FDS
index|]
decl_stmt|;
name|char
name|alwaysopen
index|[
name|MAX_CALLBACK_FDS
index|]
decl_stmt|;
comment|/* System call numbers.  */
name|CB_TARGET_DEFS_MAP
modifier|*
name|syscall_map
decl_stmt|;
comment|/* Errno values.  */
name|CB_TARGET_DEFS_MAP
modifier|*
name|errno_map
decl_stmt|;
comment|/* Flags to the open system call.  */
name|CB_TARGET_DEFS_MAP
modifier|*
name|open_map
decl_stmt|;
comment|/* Signal numbers.  */
name|CB_TARGET_DEFS_MAP
modifier|*
name|signal_map
decl_stmt|;
comment|/* Layout of `stat' struct.      The format is a series of "name,length" pairs separated by colons.      Empty space is indicated with a `name' of "space".      All padding must be explicitly mentioned.      Lengths are in bytes.  If this needs to be extended to bits,      use "name.bits".      Example: "st_dev,4:st_ino,4:st_mode,4:..."  */
specifier|const
name|char
modifier|*
name|stat_map
decl_stmt|;
comment|/* Marker for those wanting to do sanity checks.      This should remain the last member of this struct to help catch      miscompilation errors. */
define|#
directive|define
name|HOST_CALLBACK_MAGIC
value|4705
comment|/* teds constant */
name|int
name|magic
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|host_callback
name|default_callback
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Canonical versions of system call numbers.    It's not intended to willy-nilly throw every system call ever heard    of in here.  Only include those that have an important use.    ??? One can certainly start a discussion over the ones that are currently    here, but that will always be true.  */
end_comment

begin_comment
comment|/* These are used by the ANSI C support of libc.  */
end_comment

begin_define
define|#
directive|define
name|CB_SYS_exit
value|1
end_define

begin_define
define|#
directive|define
name|CB_SYS_open
value|2
end_define

begin_define
define|#
directive|define
name|CB_SYS_close
value|3
end_define

begin_define
define|#
directive|define
name|CB_SYS_read
value|4
end_define

begin_define
define|#
directive|define
name|CB_SYS_write
value|5
end_define

begin_define
define|#
directive|define
name|CB_SYS_lseek
value|6
end_define

begin_define
define|#
directive|define
name|CB_SYS_unlink
value|7
end_define

begin_define
define|#
directive|define
name|CB_SYS_getpid
value|8
end_define

begin_define
define|#
directive|define
name|CB_SYS_kill
value|9
end_define

begin_define
define|#
directive|define
name|CB_SYS_fstat
value|10
end_define

begin_comment
comment|/*#define CB_SYS_sbrk	11 - not currently a system call, but reserved.  */
end_comment

begin_comment
comment|/* ARGV support.  */
end_comment

begin_define
define|#
directive|define
name|CB_SYS_argvlen
value|12
end_define

begin_define
define|#
directive|define
name|CB_SYS_argv
value|13
end_define

begin_comment
comment|/* These are extras added for one reason or another.  */
end_comment

begin_define
define|#
directive|define
name|CB_SYS_chdir
value|14
end_define

begin_define
define|#
directive|define
name|CB_SYS_stat
value|15
end_define

begin_define
define|#
directive|define
name|CB_SYS_chmod
value|16
end_define

begin_define
define|#
directive|define
name|CB_SYS_utime
value|17
end_define

begin_define
define|#
directive|define
name|CB_SYS_time
value|18
end_define

begin_escape
end_escape

begin_comment
comment|/* Struct use to pass and return information necessary to perform a    system call.  */
end_comment

begin_comment
comment|/* FIXME: Need to consider target word size.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cb_syscall
block|{
comment|/* The target's value of what system call to perform.  */
name|int
name|func
decl_stmt|;
comment|/* The arguments to the syscall.  */
name|long
name|arg1
decl_stmt|,
name|arg2
decl_stmt|,
name|arg3
decl_stmt|,
name|arg4
decl_stmt|;
comment|/* The result.  */
name|long
name|result
decl_stmt|;
comment|/* Some system calls have two results.  */
name|long
name|result2
decl_stmt|;
comment|/* The target's errno value, or 0 if success.      This is converted to the target's value with host_to_target_errno.  */
name|int
name|errcode
decl_stmt|;
comment|/* Working space to be used by memory read/write callbacks.  */
name|PTR
name|p1
decl_stmt|;
name|PTR
name|p2
decl_stmt|;
name|long
name|x1
decl_stmt|,
name|x2
decl_stmt|;
comment|/* Callbacks for reading/writing memory (e.g. for read/write syscalls).      ??? long or unsigned long might be better to use for the `count'      argument here.  We mimic sim_{read,write} for now.  Be careful to      test any changes with -Wall -Werror, mixed signed comparisons      will get you.  */
name|int
argument_list|(
argument|*read_mem
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
comment|/*cb*/
operator|,
expr|struct
name|cb_syscall
operator|*
comment|/*sc*/
operator|,
name|unsigned
name|long
comment|/*taddr*/
operator|,
name|char
operator|*
comment|/*buf*/
operator|,
name|int
comment|/*bytes*/
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*write_mem
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
comment|/*cb*/
operator|,
expr|struct
name|cb_syscall
operator|*
comment|/*sc*/
operator|,
name|unsigned
name|long
comment|/*taddr*/
operator|,
specifier|const
name|char
operator|*
comment|/*buf*/
operator|,
name|int
comment|/*bytes*/
operator|)
argument_list|)
expr_stmt|;
comment|/* For sanity checking, should be last entry.  */
name|int
name|magic
decl_stmt|;
block|}
name|CB_SYSCALL
typedef|;
end_typedef

begin_comment
comment|/* Magic number sanity checker.  */
end_comment

begin_define
define|#
directive|define
name|CB_SYSCALL_MAGIC
value|0x12344321
end_define

begin_comment
comment|/* Macro to initialize CB_SYSCALL.  Called first, before filling in    any fields.  */
end_comment

begin_define
define|#
directive|define
name|CB_SYSCALL_INIT
parameter_list|(
name|sc
parameter_list|)
define|\
value|do { \   memset ((sc), 0, sizeof (*(sc))); \   (sc)->magic = CB_SYSCALL_MAGIC; \ } while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Return codes for various interface routines.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CB_RC_OK
init|=
literal|0
block|,
comment|/* generic error */
name|CB_RC_ERR
block|,
comment|/* either file not found or no read access */
name|CB_RC_ACCESS
block|,
name|CB_RC_NO_MEM
block|}
name|CB_RC
typedef|;
end_typedef

begin_comment
comment|/* Read in target values for system call numbers, errno values, signals.  */
end_comment

begin_decl_stmt
name|CB_RC
name|cb_read_target_syscall_maps
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Translate target to host syscall function numbers.  */
end_comment

begin_decl_stmt
name|int
name|cb_target_to_host_syscall
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Translate host to target errno value.  */
end_comment

begin_decl_stmt
name|int
name|cb_host_to_target_errno
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Translate target to host open flags.  */
end_comment

begin_decl_stmt
name|int
name|cb_target_to_host_open
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Translate target signal number to host.  */
end_comment

begin_decl_stmt
name|int
name|cb_target_to_host_signal
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Translate host signal number to target.  */
end_comment

begin_decl_stmt
name|int
name|cb_host_to_target_signal
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Translate host stat struct to target.    If stat struct ptr is NULL, just compute target stat struct size.    Result is size of target stat struct or 0 if error.  */
end_comment

begin_decl_stmt
name|int
name|cb_host_to_target_stat
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
specifier|const
expr|struct
name|stat
operator|*
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Perform a system call.  */
end_comment

begin_decl_stmt
name|CB_RC
name|cb_syscall
name|PARAMS
argument_list|(
operator|(
name|host_callback
operator|*
operator|,
name|CB_SYSCALL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

