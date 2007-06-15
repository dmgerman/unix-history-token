begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Stack overflow handling.     Copyright (C) 2002, 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert.  */
end_comment

begin_comment
comment|/* NOTES:     A program that uses alloca, dynamic arrays, or large local    variables may extend the stack by more than a page at a time.  If    so, when the stack overflows the operating system may not detect    the overflow until the program uses the array, and this module may    incorrectly report a program error instead of a stack overflow.     To avoid this problem, allocate only small objects on the stack; a    program should be OK if it limits single allocations to a page or    less.  Allocate larger arrays in static storage, or on the heap    (e.g., with malloc).  Yes, this is a pain, but we don't know of any    better solution that is portable.     No attempt has been made to deal with multithreaded applications.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__attribute__
end_ifndef

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|3
operator|||
name|__STRICT_ANSI__
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
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
file|"gettext.h"
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|msgid
parameter_list|)
value|gettext (msgid)
end_define

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|ENOTSUP
end_ifndef

begin_define
define|#
directive|define
name|ENOTSUP
value|EINVAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EOVERFLOW
end_ifndef

begin_define
define|#
directive|define
name|EOVERFLOW
value|EINVAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_if
if|#
directive|if
operator|!
name|HAVE_STACK_T
operator|&&
operator|!
name|defined
name|stack_t
end_if

begin_typedef
typedef|typedef
name|struct
name|sigaltstack
name|stack_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_if
if|#
directive|if
name|HAVE_SYS_RESOURCE_H
end_if

begin_comment
comment|/* Include sys/time.h here, because...    SunOS-4.1.x<sys/resource.h> fails to include<sys/time.h>.    This gives "incomplete type" errors for ru_utime and tu_stime.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_TIME_H
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_UCONTEXT_H
end_if

begin_include
include|#
directive|include
file|<ucontext.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDERR_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|DEBUG
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"c-stack.h"
end_include

begin_include
include|#
directive|include
file|"exitfail.h"
end_include

begin_if
if|#
directive|if
operator|(
name|HAVE_STRUCT_SIGACTION_SA_SIGACTION
operator|&&
name|defined
name|SA_NODEFER
expr|\
operator|&&
name|defined
name|SA_ONSTACK
operator|&&
name|defined
name|SA_RESETHAND
operator|&&
name|defined
name|SA_SIGINFO
operator|)
end_if

begin_define
define|#
directive|define
name|SIGACTION_WORKS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIGACTION_WORKS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The user-specified action to take when a SEGV-related program error    or stack overflow occurs.  */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
operator|*
specifier|volatile
name|segv_action
argument_list|)
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Translated messages for program errors and stack overflow.  Do not    translate them in the signal handler, since gettext is not    async-signal-safe.  */
end_comment

begin_decl_stmt
specifier|static
name|char
specifier|const
modifier|*
specifier|volatile
name|program_error_message
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
specifier|const
modifier|*
specifier|volatile
name|stack_overflow_message
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output an error message, then exit with status EXIT_FAILURE if it    appears to have been a stack overflow, or with a core dump    otherwise.  This function is async-signal-safe.  */
end_comment

begin_function_decl
specifier|static
name|void
name|die
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
specifier|static
name|void
name|die
parameter_list|(
name|int
name|signo
parameter_list|)
block|{
name|char
specifier|const
modifier|*
name|message
decl_stmt|;
name|segv_action
argument_list|(
name|signo
argument_list|)
expr_stmt|;
name|message
operator|=
name|signo
condition|?
name|program_error_message
else|:
name|stack_overflow_message
expr_stmt|;
name|write
argument_list|(
name|STDERR_FILENO
argument_list|,
name|program_name
argument_list|,
name|strlen
argument_list|(
name|program_name
argument_list|)
argument_list|)
expr_stmt|;
name|write
argument_list|(
name|STDERR_FILENO
argument_list|,
literal|": "
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|write
argument_list|(
name|STDERR_FILENO
argument_list|,
name|message
argument_list|,
name|strlen
argument_list|(
name|message
argument_list|)
argument_list|)
expr_stmt|;
name|write
argument_list|(
name|STDERR_FILENO
argument_list|,
literal|"\n"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|signo
condition|)
name|_exit
argument_list|(
name|exit_failure
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|signo
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|HAVE_SIGALTSTACK
operator|&&
name|HAVE_DECL_SIGALTSTACK
end_if

begin_comment
comment|/* Direction of the C runtime stack.  This function is    async-signal-safe.  */
end_comment

begin_if
if|#
directive|if
name|STACK_DIRECTION
end_if

begin_define
define|#
directive|define
name|find_stack_direction
parameter_list|(
name|ptr
parameter_list|)
value|STACK_DIRECTION
end_define

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|int
name|find_stack_direction
parameter_list|(
name|char
specifier|const
modifier|*
name|addr
parameter_list|)
block|{
name|char
name|dummy
decl_stmt|;
return|return
operator|!
name|addr
condition|?
name|find_stack_direction
argument_list|(
operator|&
name|dummy
argument_list|)
else|:
name|addr
operator|<
operator|&
name|dummy
condition|?
literal|1
else|:
operator|-
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Storage for the alternate signal stack.  */
end_comment

begin_union
specifier|static
union|union
block|{
name|char
name|buffer
index|[
name|SIGSTKSZ
index|]
decl_stmt|;
comment|/* These other members are for proper alignment.  There's no      standard way to guarantee stack alignment, but this seems enough      in practice.  */
name|long
name|double
name|ld
decl_stmt|;
name|long
name|l
decl_stmt|;
name|void
modifier|*
name|p
decl_stmt|;
block|}
name|alternate_signal_stack
union|;
end_union

begin_if
if|#
directive|if
name|SIGACTION_WORKS
end_if

begin_comment
comment|/* Handle a segmentation violation and exit.  This function is    async-signal-safe.  */
end_comment

begin_function_decl
specifier|static
name|void
name|segv_handler
parameter_list|(
name|int
parameter_list|,
name|siginfo_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|static
name|void
name|segv_handler
argument_list|(
name|int
name|signo
argument_list|,
name|siginfo_t
operator|*
name|info
argument_list|,
name|void
operator|*
name|context
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
argument_list|)
block|{
comment|/* Clear SIGNO if it seems to have been a stack overflow.  */
if|if
condition|(
literal|0
operator|<
name|info
operator|->
name|si_code
condition|)
block|{
if|#
directive|if
operator|!
name|HAVE_XSI_STACK_OVERFLOW_HEURISTIC
comment|/* We can't easily determine whether it is a stack overflow; so 	 assume that the rest of our program is perfect (!) and that 	 this segmentation violation is a stack overflow.  */
name|signo
operator|=
literal|0
expr_stmt|;
else|#
directive|else
comment|/* If the faulting address is within the stack, or within one 	 page of the stack end, assume that it is a stack 	 overflow.  */
name|ucontext_t
specifier|const
modifier|*
name|user_context
init|=
name|context
decl_stmt|;
name|char
specifier|const
modifier|*
name|stack_base
init|=
name|user_context
operator|->
name|uc_stack
operator|.
name|ss_sp
decl_stmt|;
name|size_t
name|stack_size
init|=
name|user_context
operator|->
name|uc_stack
operator|.
name|ss_size
decl_stmt|;
name|char
specifier|const
modifier|*
name|faulting_address
init|=
name|info
operator|->
name|si_addr
decl_stmt|;
name|size_t
name|s
init|=
name|faulting_address
operator|-
name|stack_base
decl_stmt|;
name|size_t
name|page_size
init|=
name|sysconf
argument_list|(
name|_SC_PAGESIZE
argument_list|)
decl_stmt|;
if|if
condition|(
name|find_stack_direction
argument_list|(
literal|0
argument_list|)
operator|<
literal|0
condition|)
name|s
operator|+=
name|page_size
expr_stmt|;
if|if
condition|(
name|s
operator|<
name|stack_size
operator|+
name|page_size
condition|)
name|signo
operator|=
literal|0
expr_stmt|;
if|#
directive|if
name|DEBUG
block|{
name|char
name|buf
index|[
literal|1024
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"segv_handler fault=%p base=%p size=%lx page=%lx signo=%d\n"
argument_list|,
name|faulting_address
argument_list|,
name|stack_base
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|stack_size
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|page_size
argument_list|,
name|signo
argument_list|)
expr_stmt|;
name|write
argument_list|(
name|STDERR_FILENO
argument_list|,
name|buf
argument_list|,
name|strlen
argument_list|(
name|buf
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|#
directive|endif
block|}
name|die
argument_list|(
name|signo
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|void
name|null_action
argument_list|(
name|int
name|signo
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
argument_list|)
block|{ }
end_decl_stmt

begin_comment
comment|/* Set up ACTION so that it is invoked on C stack overflow.  Return -1    (setting errno) if this cannot be done.     When ACTION is called, it is passed an argument equal to SIGSEGV    for a segmentation violation that does not appear related to stack    overflow, and is passed zero otherwise.  On many platforms it is    hard to tell; when in doubt, zero is passed.     A null ACTION acts like an action that does nothing.     ACTION must be async-signal-safe.  ACTION together with its callees    must not require more than SIGSTKSZ bytes of stack space.  */
end_comment

begin_function
name|int
name|c_stack_action
parameter_list|(
name|void
function_decl|(
modifier|*
name|action
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
block|{
name|int
name|r
decl_stmt|;
name|stack_t
name|st
decl_stmt|;
name|st
operator|.
name|ss_flags
operator|=
literal|0
expr_stmt|;
name|st
operator|.
name|ss_sp
operator|=
name|alternate_signal_stack
operator|.
name|buffer
expr_stmt|;
name|st
operator|.
name|ss_size
operator|=
sizeof|sizeof
name|alternate_signal_stack
operator|.
name|buffer
expr_stmt|;
name|r
operator|=
name|sigaltstack
argument_list|(
operator|&
name|st
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|!=
literal|0
condition|)
return|return
name|r
return|;
name|segv_action
operator|=
name|action
condition|?
name|action
else|:
name|null_action
expr_stmt|;
name|program_error_message
operator|=
name|_
argument_list|(
literal|"program error"
argument_list|)
expr_stmt|;
name|stack_overflow_message
operator|=
name|_
argument_list|(
literal|"stack overflow"
argument_list|)
expr_stmt|;
block|{
if|#
directive|if
name|SIGACTION_WORKS
name|struct
name|sigaction
name|act
decl_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|act
operator|.
name|sa_mask
argument_list|)
expr_stmt|;
comment|/* POSIX 1003.1-2001 says SA_RESETHAND implies SA_NODEFER, but        this is not true on Solaris 8 at least.  It doesn't hurt to use        SA_NODEFER here, so leave it in.  */
name|act
operator|.
name|sa_flags
operator|=
name|SA_NODEFER
operator||
name|SA_ONSTACK
operator||
name|SA_RESETHAND
operator||
name|SA_SIGINFO
expr_stmt|;
name|act
operator|.
name|sa_sigaction
operator|=
name|segv_handler
expr_stmt|;
return|return
name|sigaction
argument_list|(
name|SIGSEGV
argument_list|,
operator|&
name|act
argument_list|,
literal|0
argument_list|)
return|;
else|#
directive|else
return|return
name|signal
argument_list|(
name|SIGSEGV
argument_list|,
name|die
argument_list|)
operator|==
name|SIG_ERR
condition|?
operator|-
literal|1
else|:
literal|0
return|;
endif|#
directive|endif
block|}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! (HAVE_SIGALTSTACK&& HAVE_DECL_SIGALTSTACK) */
end_comment

begin_decl_stmt
name|int
name|c_stack_action
argument_list|(
name|void
argument_list|(
argument|*action
argument_list|)
operator|(
name|int
operator|)
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
argument_list|)
block|{
name|errno
operator|=
name|ENOTSUP
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_if
if|#
directive|if
name|DEBUG
end_if

begin_decl_stmt
name|int
specifier|volatile
name|exit_failure
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|long
name|recurse
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
block|{
name|char
name|array
index|[
literal|500
index|]
decl_stmt|;
name|array
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
return|return
operator|*
name|p
operator|+
name|recurse
argument_list|(
name|array
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
decl|main
argument_list|(
name|int
name|argc
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
argument_list|,
name|char
operator|*
operator|*
name|argv
argument_list|)
block|{
name|program_name
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"The last output line should contain \"stack overflow\".\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|c_stack_action
argument_list|(
literal|0
argument_list|)
operator|==
literal|0
condition|)
return|return
name|recurse
argument_list|(
literal|"\1"
argument_list|)
return|;
name|perror
argument_list|(
literal|"c_stack_action"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Local Variables: compile-command: "gcc -DDEBUG -DHAVE_CONFIG_H -I.. -g -O -Wall -W c-stack.c" End: */
end_comment

end_unit

