begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Low level Unix child interface to ptrace, for GDB when running under Unix.    Copyright 1988, 89, 90, 91, 92, 93, 94, 95, 96, 1998     Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
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
file|"target.h"
end_include

begin_include
include|#
directive|include
file|"gdb_string.h"
end_include

begin_include
include|#
directive|include
file|"wait.h"
end_include

begin_include
include|#
directive|include
file|"command.h"
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

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PTRACE_H
end_ifdef

begin_include
include|#
directive|include
file|<ptrace.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PTRACE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/ptrace.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PT_READ_I
argument_list|)
end_if

begin_define
define|#
directive|define
name|PT_READ_I
value|1
end_define

begin_comment
comment|/* Read word from text space */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PT_READ_D
argument_list|)
end_if

begin_define
define|#
directive|define
name|PT_READ_D
value|2
end_define

begin_comment
comment|/* Read word from data space */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PT_READ_U
argument_list|)
end_if

begin_define
define|#
directive|define
name|PT_READ_U
value|3
end_define

begin_comment
comment|/* Read word from kernel user struct */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PT_WRITE_I
argument_list|)
end_if

begin_define
define|#
directive|define
name|PT_WRITE_I
value|4
end_define

begin_comment
comment|/* Write word to text space */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PT_WRITE_D
argument_list|)
end_if

begin_define
define|#
directive|define
name|PT_WRITE_D
value|5
end_define

begin_comment
comment|/* Write word to data space */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PT_WRITE_U
argument_list|)
end_if

begin_define
define|#
directive|define
name|PT_WRITE_U
value|6
end_define

begin_comment
comment|/* Write word to kernel user struct */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PT_CONTINUE
argument_list|)
end_if

begin_define
define|#
directive|define
name|PT_CONTINUE
value|7
end_define

begin_comment
comment|/* Continue after signal */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PT_STEP
argument_list|)
end_if

begin_define
define|#
directive|define
name|PT_STEP
value|9
end_define

begin_comment
comment|/* Set flag for single stepping */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PT_KILL
argument_list|)
end_if

begin_define
define|#
directive|define
name|PT_KILL
value|8
end_define

begin_comment
comment|/* Send child a SIGKILL signal */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PT_ATTACH
end_ifndef

begin_define
define|#
directive|define
name|PT_ATTACH
value|PTRACE_ATTACH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PT_DETACH
end_ifndef

begin_define
define|#
directive|define
name|PT_DETACH
value|PTRACE_DETACH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"gdbcore.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SYS_FILE
end_ifndef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Don't think this is used anymore.  On the sequent (not sure whether it's    dynix or ptx or both), it is included unconditionally by sys/user.h and    not protected against multiple inclusion.  */
end_comment

begin_include
include|#
directive|include
file|"gdb_stat.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FETCH_INFERIOR_REGISTERS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_comment
comment|/* Probably need to poke the user structure */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL_U_ADDR_BSD
argument_list|)
end_if

begin_include
include|#
directive|include
file|<a.out.h>
end_include

begin_comment
comment|/* For struct nlist */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL_U_ADDR_BSD.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !FETCH_INFERIOR_REGISTERS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CHILD_XFER_MEMORY
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|void
name|udot_info
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FETCH_INFERIOR_REGISTERS
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|void
name|fetch_register
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|store_register
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|_initialize_kernel_u_addr
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_initialize_infptrace
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* This function simply calls ptrace with the given arguments.      It exists so that all calls to ptrace are isolated in this     machine-dependent file. */
end_comment

begin_function
name|int
name|call_ptrace
parameter_list|(
name|request
parameter_list|,
name|pid
parameter_list|,
name|addr
parameter_list|,
name|data
parameter_list|)
name|int
name|request
decl_stmt|,
name|pid
decl_stmt|;
name|PTRACE_ARG3_TYPE
name|addr
decl_stmt|;
name|int
name|data
decl_stmt|;
block|{
name|int
name|pt_status
init|=
literal|0
decl_stmt|;
if|#
directive|if
literal|0
block|int saved_errno;    printf ("call_ptrace(request=%d, pid=%d, addr=0x%x, data=0x%x)", 	  request, pid, addr, data);
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PT_SETTRC
argument_list|)
comment|/* If the parent can be told to attach to us, try to do it.  */
if|if
condition|(
name|request
operator|==
name|PT_SETTRC
condition|)
block|{
name|errno
operator|=
literal|0
expr_stmt|;
name|pt_status
operator|=
name|ptrace
argument_list|(
name|PT_SETTRC
argument_list|,
name|pid
argument_list|,
name|addr
argument_list|,
name|data
if|#
directive|if
name|defined
argument_list|(
name|FIVE_ARG_PTRACE
argument_list|)
comment|/* Deal with HPUX 8.0 braindamage.  We never use the                           calls which require the fifth argument.  */
argument_list|,
literal|0
endif|#
directive|endif
argument_list|)
expr_stmt|;
if|if
condition|(
name|errno
condition|)
name|perror_with_name
argument_list|(
literal|"ptrace"
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|printf (" = %d\n", pt_status);
endif|#
directive|endif
if|if
condition|(
name|pt_status
operator|<
literal|0
condition|)
return|return
name|pt_status
return|;
else|else
return|return
name|parent_attach_all
argument_list|(
name|pid
argument_list|,
name|addr
argument_list|,
name|data
argument_list|)
return|;
block|}
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PT_CONTIN1
argument_list|)
comment|/* On HPUX, PT_CONTIN1 is a form of continue that preserves pending      signals.  If it's available, use it.  */
if|if
condition|(
name|request
operator|==
name|PT_CONTINUE
condition|)
name|request
operator|=
name|PT_CONTIN1
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PT_SINGLE1
argument_list|)
comment|/* On HPUX, PT_SINGLE1 is a form of step that preserves pending      signals.  If it's available, use it.  */
if|if
condition|(
name|request
operator|==
name|PT_STEP
condition|)
name|request
operator|=
name|PT_SINGLE1
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
literal|0
block|saved_errno = errno;   errno = 0;
endif|#
directive|endif
name|pt_status
operator|=
name|ptrace
argument_list|(
name|request
argument_list|,
name|pid
argument_list|,
name|addr
argument_list|,
name|data
if|#
directive|if
name|defined
argument_list|(
name|FIVE_ARG_PTRACE
argument_list|)
comment|/* Deal with HPUX 8.0 braindamage.  We never use the 		    calls which require the fifth argument.  */
argument_list|,
literal|0
endif|#
directive|endif
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|if (errno)     printf (" [errno = %d]", errno);    errno = saved_errno;   printf (" = 0x%x\n", pt_status);
endif|#
directive|endif
return|return
name|pt_status
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG_PTRACE
argument_list|)
operator|||
name|defined
argument_list|(
name|FIVE_ARG_PTRACE
argument_list|)
end_if

begin_comment
comment|/* For the rest of the file, use an extra level of indirection */
end_comment

begin_comment
comment|/* This lets us breakpoint usefully on call_ptrace. */
end_comment

begin_define
define|#
directive|define
name|ptrace
value|call_ptrace
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Wait for a process to finish, possibly running a target-specific    hook before returning.  */
end_comment

begin_function
name|int
name|ptrace_wait
parameter_list|(
name|pid
parameter_list|,
name|status
parameter_list|)
name|int
name|pid
decl_stmt|;
name|int
modifier|*
name|status
decl_stmt|;
block|{
name|int
name|wstate
decl_stmt|;
name|wstate
operator|=
name|wait
argument_list|(
name|status
argument_list|)
expr_stmt|;
name|target_post_wait
argument_list|(
name|wstate
argument_list|,
operator|*
name|status
argument_list|)
expr_stmt|;
return|return
name|wstate
return|;
block|}
end_function

begin_function
name|void
name|kill_inferior
parameter_list|()
block|{
name|int
name|status
decl_stmt|;
if|if
condition|(
name|inferior_pid
operator|==
literal|0
condition|)
return|return;
comment|/* This once used to call "kill" to kill the inferior just in case      the inferior was still running.  As others have noted in the past      (kingdon) there shouldn't be any way to get here if the inferior      is still running -- else there's a major problem elsewere in gdb      and it needs to be fixed.       The kill call causes problems under hpux10, so it's been removed;      if this causes problems we'll deal with them as they arise.  */
name|ptrace
argument_list|(
name|PT_KILL
argument_list|,
name|inferior_pid
argument_list|,
operator|(
name|PTRACE_ARG3_TYPE
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ptrace_wait
argument_list|(
literal|0
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
name|target_mourn_inferior
argument_list|()
expr_stmt|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|CHILD_RESUME
end_ifndef

begin_comment
comment|/* Resume execution of the inferior process.    If STEP is nonzero, single-step it.    If SIGNAL is nonzero, give it that signal.  */
end_comment

begin_function
name|void
name|child_resume
parameter_list|(
name|pid
parameter_list|,
name|step
parameter_list|,
name|signal
parameter_list|)
name|int
name|pid
decl_stmt|;
name|int
name|step
decl_stmt|;
name|enum
name|target_signal
name|signal
decl_stmt|;
block|{
name|errno
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|pid
operator|==
operator|-
literal|1
condition|)
comment|/* Resume all threads.  */
comment|/* I think this only gets used in the non-threaded case, where "resume        all threads" and "resume inferior_pid" are the same.  */
name|pid
operator|=
name|inferior_pid
expr_stmt|;
comment|/* An address of (PTRACE_ARG3_TYPE)1 tells ptrace to continue from where      it was.  (If GDB wanted it to start some other way, we have already      written a new PC value to the child.)       If this system does not support PT_STEP, a higher level function will      have called single_step() to transmute the step request into a      continue request (by setting breakpoints on all possible successor      instructions), so we don't have to worry about that here.  */
if|if
condition|(
name|step
condition|)
block|{
if|if
condition|(
name|SOFTWARE_SINGLE_STEP_P
condition|)
name|abort
argument_list|()
expr_stmt|;
comment|/* Make sure this doesn't happen. */
else|else
name|ptrace
argument_list|(
name|PT_STEP
argument_list|,
name|pid
argument_list|,
operator|(
name|PTRACE_ARG3_TYPE
operator|)
literal|1
argument_list|,
name|target_signal_to_host
argument_list|(
name|signal
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
name|ptrace
argument_list|(
name|PT_CONTINUE
argument_list|,
name|pid
argument_list|,
operator|(
name|PTRACE_ARG3_TYPE
operator|)
literal|1
argument_list|,
name|target_signal_to_host
argument_list|(
name|signal
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|errno
condition|)
name|perror_with_name
argument_list|(
literal|"ptrace"
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CHILD_RESUME */
end_comment

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|ATTACH_DETACH
end_ifdef

begin_comment
comment|/* Start debugging the process whose number is PID.  */
end_comment

begin_function
name|int
name|attach
parameter_list|(
name|pid
parameter_list|)
name|int
name|pid
decl_stmt|;
block|{
name|errno
operator|=
literal|0
expr_stmt|;
name|ptrace
argument_list|(
name|PT_ATTACH
argument_list|,
name|pid
argument_list|,
operator|(
name|PTRACE_ARG3_TYPE
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|errno
condition|)
name|perror_with_name
argument_list|(
literal|"ptrace"
argument_list|)
expr_stmt|;
name|attach_flag
operator|=
literal|1
expr_stmt|;
return|return
name|pid
return|;
block|}
end_function

begin_comment
comment|/* Stop debugging the process whose number is PID    and continue it with signal number SIGNAL.    SIGNAL = 0 means just continue it.  */
end_comment

begin_function
name|void
name|detach
parameter_list|(
name|signal
parameter_list|)
name|int
name|signal
decl_stmt|;
block|{
name|errno
operator|=
literal|0
expr_stmt|;
name|ptrace
argument_list|(
name|PT_DETACH
argument_list|,
name|inferior_pid
argument_list|,
operator|(
name|PTRACE_ARG3_TYPE
operator|)
literal|1
argument_list|,
name|signal
argument_list|)
expr_stmt|;
if|if
condition|(
name|errno
condition|)
name|perror_with_name
argument_list|(
literal|"ptrace"
argument_list|)
expr_stmt|;
name|attach_flag
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTACH_DETACH */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Default the type of the ptrace transfer to int.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PTRACE_XFER_TYPE
end_ifndef

begin_define
define|#
directive|define
name|PTRACE_XFER_TYPE
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL_U_ADDR is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL_U_ADDR_BSD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|FETCH_INFERIOR_REGISTERS
argument_list|)
end_if

begin_comment
comment|/* Get kernel_u_addr using BSD-style nlist().  */
end_comment

begin_decl_stmt
name|CORE_ADDR
name|kernel_u_addr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL_U_ADDR_BSD.  */
end_comment

begin_function
name|void
name|_initialize_kernel_u_addr
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|KERNEL_U_ADDR_BSD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|FETCH_INFERIOR_REGISTERS
argument_list|)
name|struct
name|nlist
name|names
index|[
literal|2
index|]
decl_stmt|;
name|names
index|[
literal|0
index|]
operator|.
name|n_un
operator|.
name|n_name
operator|=
literal|"_u"
expr_stmt|;
name|names
index|[
literal|1
index|]
operator|.
name|n_un
operator|.
name|n_name
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|nlist
argument_list|(
literal|"/vmunix"
argument_list|,
name|names
argument_list|)
operator|==
literal|0
condition|)
name|kernel_u_addr
operator|=
name|names
index|[
literal|0
index|]
operator|.
name|n_value
expr_stmt|;
else|else
name|fatal
argument_list|(
literal|"Unable to get kernel u area address."
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* KERNEL_U_ADDR_BSD.  */
block|}
end_function

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FETCH_INFERIOR_REGISTERS
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|offsetof
argument_list|)
end_if

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|TYPE
parameter_list|,
name|MEMBER
parameter_list|)
value|((unsigned long)&((TYPE *)0)->MEMBER)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* U_REGS_OFFSET is the offset of the registers within the u area.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|U_REGS_OFFSET
argument_list|)
end_if

begin_define
define|#
directive|define
name|U_REGS_OFFSET
define|\
value|ptrace (PT_READ_U, inferior_pid, \ 	  (PTRACE_ARG3_TYPE) (offsetof (struct user, u_ar0)), 0) \     - KERNEL_U_ADDR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Registers we shouldn't try to fetch.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CANNOT_FETCH_REGISTER
argument_list|)
end_if

begin_define
define|#
directive|define
name|CANNOT_FETCH_REGISTER
parameter_list|(
name|regno
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Fetch one register.  */
end_comment

begin_function
specifier|static
name|void
name|fetch_register
parameter_list|(
name|regno
parameter_list|)
name|int
name|regno
decl_stmt|;
block|{
comment|/* This isn't really an address.  But ptrace thinks of it as one.  */
name|CORE_ADDR
name|regaddr
decl_stmt|;
name|char
name|mess
index|[
literal|128
index|]
decl_stmt|;
comment|/* For messages */
specifier|register
name|int
name|i
decl_stmt|;
name|unsigned
name|int
name|offset
decl_stmt|;
comment|/* Offset of registers within the u area.  */
name|char
name|buf
index|[
name|MAX_REGISTER_RAW_SIZE
index|]
decl_stmt|;
if|if
condition|(
name|CANNOT_FETCH_REGISTER
argument_list|(
name|regno
argument_list|)
condition|)
block|{
name|memset
argument_list|(
name|buf
argument_list|,
literal|'\0'
argument_list|,
name|REGISTER_RAW_SIZE
argument_list|(
name|regno
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Supply zeroes */
name|supply_register
argument_list|(
name|regno
argument_list|,
name|buf
argument_list|)
expr_stmt|;
return|return;
block|}
name|offset
operator|=
name|U_REGS_OFFSET
expr_stmt|;
name|regaddr
operator|=
name|register_addr
argument_list|(
name|regno
argument_list|,
name|offset
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|REGISTER_RAW_SIZE
argument_list|(
name|regno
argument_list|)
condition|;
name|i
operator|+=
sizeof|sizeof
argument_list|(
name|PTRACE_XFER_TYPE
argument_list|)
control|)
block|{
name|errno
operator|=
literal|0
expr_stmt|;
operator|*
operator|(
name|PTRACE_XFER_TYPE
operator|*
operator|)
operator|&
name|buf
index|[
name|i
index|]
operator|=
name|ptrace
argument_list|(
name|PT_READ_U
argument_list|,
name|inferior_pid
argument_list|,
operator|(
name|PTRACE_ARG3_TYPE
operator|)
name|regaddr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|regaddr
operator|+=
sizeof|sizeof
argument_list|(
name|PTRACE_XFER_TYPE
argument_list|)
expr_stmt|;
if|if
condition|(
name|errno
operator|!=
literal|0
condition|)
block|{
name|sprintf
argument_list|(
name|mess
argument_list|,
literal|"reading register %s (#%d)"
argument_list|,
name|REGISTER_NAME
argument_list|(
name|regno
argument_list|)
argument_list|,
name|regno
argument_list|)
expr_stmt|;
name|perror_with_name
argument_list|(
name|mess
argument_list|)
expr_stmt|;
block|}
block|}
name|supply_register
argument_list|(
name|regno
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Fetch register values from the inferior.    If REGNO is negative, do this for all registers.    Otherwise, REGNO specifies which register (so we can save time). */
end_comment

begin_function
name|void
name|fetch_inferior_registers
parameter_list|(
name|regno
parameter_list|)
name|int
name|regno
decl_stmt|;
block|{
if|if
condition|(
name|regno
operator|>=
literal|0
condition|)
block|{
name|fetch_register
argument_list|(
name|regno
argument_list|)
expr_stmt|;
block|}
else|else
block|{
for|for
control|(
name|regno
operator|=
literal|0
init|;
name|regno
operator|<
name|ARCH_NUM_REGS
condition|;
name|regno
operator|++
control|)
block|{
name|fetch_register
argument_list|(
name|regno
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_comment
comment|/* Registers we shouldn't try to store.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CANNOT_STORE_REGISTER
argument_list|)
end_if

begin_define
define|#
directive|define
name|CANNOT_STORE_REGISTER
parameter_list|(
name|regno
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Store one register. */
end_comment

begin_function
specifier|static
name|void
name|store_register
parameter_list|(
name|regno
parameter_list|)
name|int
name|regno
decl_stmt|;
block|{
comment|/* This isn't really an address.  But ptrace thinks of it as one.  */
name|CORE_ADDR
name|regaddr
decl_stmt|;
name|char
name|mess
index|[
literal|128
index|]
decl_stmt|;
comment|/* For messages */
specifier|register
name|int
name|i
decl_stmt|;
name|unsigned
name|int
name|offset
decl_stmt|;
comment|/* Offset of registers within the u area.  */
if|if
condition|(
name|CANNOT_STORE_REGISTER
argument_list|(
name|regno
argument_list|)
condition|)
block|{
return|return;
block|}
name|offset
operator|=
name|U_REGS_OFFSET
expr_stmt|;
name|regaddr
operator|=
name|register_addr
argument_list|(
name|regno
argument_list|,
name|offset
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|REGISTER_RAW_SIZE
argument_list|(
name|regno
argument_list|)
condition|;
name|i
operator|+=
sizeof|sizeof
argument_list|(
name|PTRACE_XFER_TYPE
argument_list|)
control|)
block|{
name|errno
operator|=
literal|0
expr_stmt|;
name|ptrace
argument_list|(
name|PT_WRITE_U
argument_list|,
name|inferior_pid
argument_list|,
operator|(
name|PTRACE_ARG3_TYPE
operator|)
name|regaddr
argument_list|,
operator|*
operator|(
name|PTRACE_XFER_TYPE
operator|*
operator|)
operator|&
name|registers
index|[
name|REGISTER_BYTE
argument_list|(
name|regno
argument_list|)
operator|+
name|i
index|]
argument_list|)
expr_stmt|;
name|regaddr
operator|+=
sizeof|sizeof
argument_list|(
name|PTRACE_XFER_TYPE
argument_list|)
expr_stmt|;
if|if
condition|(
name|errno
operator|!=
literal|0
condition|)
block|{
name|sprintf
argument_list|(
name|mess
argument_list|,
literal|"writing register %s (#%d)"
argument_list|,
name|REGISTER_NAME
argument_list|(
name|regno
argument_list|)
argument_list|,
name|regno
argument_list|)
expr_stmt|;
name|perror_with_name
argument_list|(
name|mess
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_comment
comment|/* Store our register values back into the inferior.    If REGNO is negative, do this for all registers.    Otherwise, REGNO specifies which register (so we can save time).  */
end_comment

begin_function
name|void
name|store_inferior_registers
parameter_list|(
name|regno
parameter_list|)
name|int
name|regno
decl_stmt|;
block|{
if|if
condition|(
name|regno
operator|>=
literal|0
condition|)
block|{
name|store_register
argument_list|(
name|regno
argument_list|)
expr_stmt|;
block|}
else|else
block|{
for|for
control|(
name|regno
operator|=
literal|0
init|;
name|regno
operator|<
name|ARCH_NUM_REGS
condition|;
name|regno
operator|++
control|)
block|{
name|store_register
argument_list|(
name|regno
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (FETCH_INFERIOR_REGISTERS).  */
end_comment

begin_escape
end_escape

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CHILD_XFER_MEMORY
argument_list|)
end_if

begin_comment
comment|/* NOTE! I tried using PTRACE_READDATA, etc., to read and write memory    in the NEW_SUN_PTRACE case.    It ought to be straightforward.  But it appears that writing did    not write the data that I specified.  I cannot understand where    it got the data that it actually did write.  */
end_comment

begin_comment
comment|/* Copy LEN bytes to or from inferior's memory starting at MEMADDR    to debugger memory starting at MYADDR.   Copy to inferior if    WRITE is nonzero.       Returns the length copied, which is either the LEN argument or zero.    This xfer function does not do partial moves, since child_ops    doesn't allow memory operations to cross below us in the target stack    anyway.  */
end_comment

begin_function
name|int
name|child_xfer_memory
parameter_list|(
name|memaddr
parameter_list|,
name|myaddr
parameter_list|,
name|len
parameter_list|,
name|write
parameter_list|,
name|target
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
name|int
name|write
decl_stmt|;
name|struct
name|target_ops
modifier|*
name|target
decl_stmt|;
comment|/* ignored */
block|{
specifier|register
name|int
name|i
decl_stmt|;
comment|/* Round starting address down to longword boundary.  */
specifier|register
name|CORE_ADDR
name|addr
init|=
name|memaddr
operator|&
operator|-
sizeof|sizeof
argument_list|(
name|PTRACE_XFER_TYPE
argument_list|)
decl_stmt|;
comment|/* Round ending address up; get number of longwords that makes.  */
specifier|register
name|int
name|count
init|=
operator|(
operator|(
operator|(
name|memaddr
operator|+
name|len
operator|)
operator|-
name|addr
operator|)
operator|+
sizeof|sizeof
argument_list|(
name|PTRACE_XFER_TYPE
argument_list|)
operator|-
literal|1
operator|)
operator|/
sizeof|sizeof
argument_list|(
name|PTRACE_XFER_TYPE
argument_list|)
decl_stmt|;
comment|/* Allocate buffer of that many longwords.  */
specifier|register
name|PTRACE_XFER_TYPE
modifier|*
name|buffer
init|=
operator|(
name|PTRACE_XFER_TYPE
operator|*
operator|)
name|alloca
argument_list|(
name|count
operator|*
sizeof|sizeof
argument_list|(
name|PTRACE_XFER_TYPE
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|write
condition|)
block|{
comment|/* Fill start and end extra bytes of buffer with existing memory data.  */
if|if
condition|(
name|addr
operator|!=
name|memaddr
operator|||
name|len
operator|<
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
name|PTRACE_XFER_TYPE
argument_list|)
condition|)
block|{
comment|/* Need part of initial word -- fetch it.  */
name|buffer
index|[
literal|0
index|]
operator|=
name|ptrace
argument_list|(
name|PT_READ_I
argument_list|,
name|inferior_pid
argument_list|,
operator|(
name|PTRACE_ARG3_TYPE
operator|)
name|addr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|count
operator|>
literal|1
condition|)
comment|/* FIXME, avoid if even boundary */
block|{
name|buffer
index|[
name|count
operator|-
literal|1
index|]
operator|=
name|ptrace
argument_list|(
name|PT_READ_I
argument_list|,
name|inferior_pid
argument_list|,
operator|(
call|(
name|PTRACE_ARG3_TYPE
call|)
argument_list|(
name|addr
operator|+
operator|(
name|count
operator|-
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|PTRACE_XFER_TYPE
argument_list|)
argument_list|)
operator|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/* Copy data to be written over corresponding part of buffer */
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|buffer
operator|+
operator|(
name|memaddr
operator|&
operator|(
sizeof|sizeof
argument_list|(
name|PTRACE_XFER_TYPE
argument_list|)
operator|-
literal|1
operator|)
operator|)
argument_list|,
name|myaddr
argument_list|,
name|len
argument_list|)
expr_stmt|;
comment|/* Write the entire buffer.  */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
name|i
operator|++
operator|,
name|addr
operator|+=
sizeof|sizeof
argument_list|(
name|PTRACE_XFER_TYPE
argument_list|)
control|)
block|{
name|errno
operator|=
literal|0
expr_stmt|;
name|ptrace
argument_list|(
name|PT_WRITE_D
argument_list|,
name|inferior_pid
argument_list|,
operator|(
name|PTRACE_ARG3_TYPE
operator|)
name|addr
argument_list|,
name|buffer
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|errno
condition|)
block|{
comment|/* Using the appropriate one (I or D) is necessary for 		 Gould NP1, at least.  */
name|errno
operator|=
literal|0
expr_stmt|;
name|ptrace
argument_list|(
name|PT_WRITE_I
argument_list|,
name|inferior_pid
argument_list|,
operator|(
name|PTRACE_ARG3_TYPE
operator|)
name|addr
argument_list|,
name|buffer
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|errno
condition|)
return|return
literal|0
return|;
block|}
ifdef|#
directive|ifdef
name|CLEAR_INSN_CACHE
name|CLEAR_INSN_CACHE
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
else|else
block|{
comment|/* Read all the longwords */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
name|i
operator|++
operator|,
name|addr
operator|+=
sizeof|sizeof
argument_list|(
name|PTRACE_XFER_TYPE
argument_list|)
control|)
block|{
name|errno
operator|=
literal|0
expr_stmt|;
name|buffer
index|[
name|i
index|]
operator|=
name|ptrace
argument_list|(
name|PT_READ_I
argument_list|,
name|inferior_pid
argument_list|,
operator|(
name|PTRACE_ARG3_TYPE
operator|)
name|addr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|errno
condition|)
return|return
literal|0
return|;
name|QUIT
expr_stmt|;
block|}
comment|/* Copy appropriate bytes out of the buffer.  */
name|memcpy
argument_list|(
name|myaddr
argument_list|,
operator|(
name|char
operator|*
operator|)
name|buffer
operator|+
operator|(
name|memaddr
operator|&
operator|(
sizeof|sizeof
argument_list|(
name|PTRACE_XFER_TYPE
argument_list|)
operator|-
literal|1
operator|)
operator|)
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
return|return
name|len
return|;
block|}
end_function

begin_escape
end_escape

begin_function
specifier|static
name|void
name|udot_info
parameter_list|(
name|dummy1
parameter_list|,
name|dummy2
parameter_list|)
name|char
modifier|*
name|dummy1
decl_stmt|;
name|int
name|dummy2
decl_stmt|;
block|{
if|#
directive|if
name|defined
argument_list|(
name|KERNEL_U_SIZE
argument_list|)
name|int
name|udot_off
decl_stmt|;
comment|/* Offset into user struct */
name|int
name|udot_val
decl_stmt|;
comment|/* Value from user struct at udot_off */
name|char
name|mess
index|[
literal|128
index|]
decl_stmt|;
comment|/* For messages */
endif|#
directive|endif
if|if
condition|(
operator|!
name|target_has_execution
condition|)
block|{
name|error
argument_list|(
literal|"The program is not being run."
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KERNEL_U_SIZE
argument_list|)
comment|/* Adding support for this command is easy.  Typically you just add a      routine, called "kernel_u_size" that returns the size of the user      struct, to the appropriate *-nat.c file and then add to the native      config file "#define KERNEL_U_SIZE kernel_u_size()" */
name|error
argument_list|(
literal|"Don't know how large ``struct user'' is in this version of gdb."
argument_list|)
expr_stmt|;
else|#
directive|else
for|for
control|(
name|udot_off
operator|=
literal|0
init|;
name|udot_off
operator|<
name|KERNEL_U_SIZE
condition|;
name|udot_off
operator|+=
sizeof|sizeof
argument_list|(
name|udot_val
argument_list|)
control|)
block|{
if|if
condition|(
operator|(
name|udot_off
operator|%
literal|24
operator|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|udot_off
operator|>
literal|0
condition|)
block|{
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|printf_filtered
argument_list|(
literal|"%04x:"
argument_list|,
name|udot_off
argument_list|)
expr_stmt|;
block|}
name|udot_val
operator|=
name|ptrace
argument_list|(
name|PT_READ_U
argument_list|,
name|inferior_pid
argument_list|,
operator|(
name|PTRACE_ARG3_TYPE
operator|)
name|udot_off
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|errno
operator|!=
literal|0
condition|)
block|{
name|sprintf
argument_list|(
name|mess
argument_list|,
literal|"\nreading user struct at offset 0x%x"
argument_list|,
name|udot_off
argument_list|)
expr_stmt|;
name|perror_with_name
argument_list|(
name|mess
argument_list|)
expr_stmt|;
block|}
comment|/* Avoid using nonportable (?) "*" in print specs */
name|printf_filtered
argument_list|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|==
literal|4
condition|?
literal|" 0x%08x"
else|:
literal|" 0x%16x"
argument_list|,
name|udot_val
argument_list|)
expr_stmt|;
block|}
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (CHILD_XFER_MEMORY).  */
end_comment

begin_escape
end_escape

begin_function
name|void
name|_initialize_infptrace
parameter_list|()
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CHILD_XFER_MEMORY
argument_list|)
name|add_info
argument_list|(
literal|"udot"
argument_list|,
name|udot_info
argument_list|,
literal|"Print contents of kernel ``struct user'' for current child."
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

