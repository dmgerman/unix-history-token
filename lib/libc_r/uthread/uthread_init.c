begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/* Allocate space for global thread variables here: */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_PTHREAD_PRIVATE
end_define

begin_include
include|#
directive|include
file|<errno.h>
end_include

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

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_THREAD_SAFE
end_ifdef

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|"pthread_private.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|_thread_autoinit_dummy_decl
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|GCC_2_8_MADE_THREAD_AWARE
end_ifdef

begin_typedef
typedef|typedef
name|void
modifier|*
modifier|*
modifier|*
function_decl|(
modifier|*
name|dynamic_handler_allocator
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|__set_dynamic_handler_allocator
parameter_list|(
name|dynamic_handler_allocator
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|pthread_key_t
name|except_head_key
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
modifier|*
name|__dynamic_handler_chain
decl_stmt|;
name|void
modifier|*
name|top_elt
index|[
literal|2
index|]
decl_stmt|;
block|}
name|except_struct
typedef|;
end_typedef

begin_function
specifier|static
name|void
modifier|*
modifier|*
modifier|*
name|dynamic_allocator_handler_fn
parameter_list|()
block|{
name|except_struct
modifier|*
name|dh
init|=
operator|(
name|except_struct
operator|*
operator|)
name|pthread_getspecific
argument_list|(
name|except_head_key
argument_list|)
decl_stmt|;
if|if
condition|(
name|dh
operator|==
name|NULL
condition|)
block|{
name|dh
operator|=
operator|(
name|except_struct
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|except_struct
argument_list|)
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|dh
argument_list|,
literal|'\0'
argument_list|,
sizeof|sizeof
argument_list|(
name|except_struct
argument_list|)
argument_list|)
expr_stmt|;
name|dh
operator|->
name|__dynamic_handler_chain
operator|=
name|dh
operator|->
name|top_elt
expr_stmt|;
name|pthread_setspecific
argument_list|(
name|except_head_key
argument_list|,
operator|(
name|void
operator|*
operator|)
name|dh
argument_list|)
expr_stmt|;
block|}
return|return
operator|&
name|dh
operator|->
name|__dynamic_handler_chain
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_2_8_MADE_THREAD_AWARE */
end_comment

begin_comment
comment|/*  * Threaded process initialization  */
end_comment

begin_function
name|void
name|_thread_init
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|flags
decl_stmt|;
name|int
name|i
decl_stmt|;
name|struct
name|sigaction
name|act
decl_stmt|;
comment|/* Ensure that the auto-initialization routine is linked in: */
name|_thread_autoinit_dummy_decl
operator|=
literal|1
expr_stmt|;
comment|/* Check if this function has already been called: */
if|if
condition|(
name|_thread_initial
condition|)
comment|/* Only initialise the threaded application once. */
return|return;
comment|/* Get the standard I/O flags before messing with them : */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|3
condition|;
name|i
operator|++
control|)
if|if
condition|(
operator|(
name|_pthread_stdio_flags
index|[
name|i
index|]
operator|=
name|_thread_sys_fcntl
argument_list|(
name|i
argument_list|,
name|F_GETFL
argument_list|,
name|NULL
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
name|PANIC
argument_list|(
literal|"Cannot get stdio flags"
argument_list|)
expr_stmt|;
comment|/* 	 * Create a pipe that is written to by the signal handler to prevent 	 * signals being missed in calls to _thread_sys_select:  	 */
if|if
condition|(
name|_thread_sys_pipe
argument_list|(
name|_thread_kern_pipe
argument_list|)
operator|!=
literal|0
condition|)
block|{
comment|/* Cannot create pipe, so abort: */
name|PANIC
argument_list|(
literal|"Cannot create kernel pipe"
argument_list|)
expr_stmt|;
block|}
comment|/* Get the flags for the read pipe: */
elseif|else
if|if
condition|(
operator|(
name|flags
operator|=
name|_thread_sys_fcntl
argument_list|(
name|_thread_kern_pipe
index|[
literal|0
index|]
argument_list|,
name|F_GETFL
argument_list|,
name|NULL
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* Abort this application: */
name|PANIC
argument_list|(
literal|"Cannot get kernel read pipe flags"
argument_list|)
expr_stmt|;
block|}
comment|/* Make the read pipe non-blocking: */
elseif|else
if|if
condition|(
name|_thread_sys_fcntl
argument_list|(
name|_thread_kern_pipe
index|[
literal|0
index|]
argument_list|,
name|F_SETFL
argument_list|,
name|flags
operator||
name|O_NONBLOCK
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* Abort this application: */
name|PANIC
argument_list|(
literal|"Cannot make kernel read pipe non-blocking"
argument_list|)
expr_stmt|;
block|}
comment|/* Get the flags for the write pipe: */
elseif|else
if|if
condition|(
operator|(
name|flags
operator|=
name|_thread_sys_fcntl
argument_list|(
name|_thread_kern_pipe
index|[
literal|1
index|]
argument_list|,
name|F_GETFL
argument_list|,
name|NULL
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* Abort this application: */
name|PANIC
argument_list|(
literal|"Cannot get kernel write pipe flags"
argument_list|)
expr_stmt|;
block|}
comment|/* Make the write pipe non-blocking: */
elseif|else
if|if
condition|(
name|_thread_sys_fcntl
argument_list|(
name|_thread_kern_pipe
index|[
literal|1
index|]
argument_list|,
name|F_SETFL
argument_list|,
name|flags
operator||
name|O_NONBLOCK
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* Abort this application: */
name|PANIC
argument_list|(
literal|"Cannot get kernel write pipe flags"
argument_list|)
expr_stmt|;
block|}
comment|/* Allocate memory for the thread structure of the initial thread: */
elseif|else
if|if
condition|(
operator|(
name|_thread_initial
operator|=
operator|(
name|pthread_t
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|pthread
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
comment|/* 		 * Insufficient memory to initialise this application, so 		 * abort:  		 */
name|PANIC
argument_list|(
literal|"Cannot allocate memory for initial thread"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Zero the global kernel thread structure: */
name|memset
argument_list|(
operator|&
name|_thread_kern_thread
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pthread
argument_list|)
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|_thread_initial
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pthread
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Default the priority of the initial thread: */
name|_thread_initial
operator|->
name|pthread_priority
operator|=
name|PTHREAD_DEFAULT_PRIORITY
expr_stmt|;
comment|/* Initialise the state of the initial thread: */
name|_thread_initial
operator|->
name|state
operator|=
name|PS_RUNNING
expr_stmt|;
comment|/* Initialise the queue: */
name|_thread_queue_init
argument_list|(
operator|&
operator|(
name|_thread_initial
operator|->
name|join_queue
operator|)
argument_list|)
expr_stmt|;
comment|/* Initialise the rest of the fields: */
name|_thread_initial
operator|->
name|parent_thread
operator|=
name|NULL
expr_stmt|;
name|_thread_initial
operator|->
name|specific_data
operator|=
name|NULL
expr_stmt|;
name|_thread_initial
operator|->
name|cleanup
operator|=
name|NULL
expr_stmt|;
name|_thread_initial
operator|->
name|queue
operator|=
name|NULL
expr_stmt|;
name|_thread_initial
operator|->
name|qnxt
operator|=
name|NULL
expr_stmt|;
name|_thread_initial
operator|->
name|nxt
operator|=
name|NULL
expr_stmt|;
name|_thread_initial
operator|->
name|flags
operator|=
literal|0
expr_stmt|;
name|_thread_initial
operator|->
name|error
operator|=
literal|0
expr_stmt|;
name|_thread_link_list
operator|=
name|_thread_initial
expr_stmt|;
name|_thread_run
operator|=
name|_thread_initial
expr_stmt|;
comment|/* Enter a loop to get the existing signal status: */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|NSIG
condition|;
name|i
operator|++
control|)
block|{
comment|/* Check for signals which cannot be trapped: */
if|if
condition|(
name|i
operator|==
name|SIGKILL
operator|||
name|i
operator|==
name|SIGSTOP
condition|)
block|{ 			}
comment|/* Get the signal handler details: */
elseif|else
if|if
condition|(
name|_thread_sys_sigaction
argument_list|(
name|i
argument_list|,
name|NULL
argument_list|,
operator|&
name|act
argument_list|)
operator|!=
literal|0
condition|)
block|{
comment|/* 				 * Abort this process if signal 				 * initialisation fails:  				 */
name|PANIC
argument_list|(
literal|"Cannot read signal handler info"
argument_list|)
expr_stmt|;
block|}
comment|/* Set the signal handler for the initial thread: */
elseif|else
if|if
condition|(
name|sigaction
argument_list|(
name|i
argument_list|,
operator|&
name|act
argument_list|,
name|NULL
argument_list|)
operator|!=
literal|0
condition|)
block|{
comment|/* 				 * Abort this process if signal 				 * initialisation fails:  				 */
name|PANIC
argument_list|(
literal|"Cannot initialise signal handler for initial thread"
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* Initialise the global signal action structure: */
name|sigfillset
argument_list|(
operator|&
name|act
operator|.
name|sa_mask
argument_list|)
expr_stmt|;
name|act
operator|.
name|sa_handler
operator|=
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|_thread_sig_handler
expr_stmt|;
name|act
operator|.
name|sa_flags
operator|=
name|SA_RESTART
expr_stmt|;
comment|/* Enter a loop to initialise the rest of the signals: */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|NSIG
condition|;
name|i
operator|++
control|)
block|{
comment|/* Check for signals which cannot be trapped: */
if|if
condition|(
name|i
operator|==
name|SIGKILL
operator|||
name|i
operator|==
name|SIGSTOP
condition|)
block|{ 			}
comment|/* Initialise the signal for default handling: */
elseif|else
if|if
condition|(
name|_thread_sys_sigaction
argument_list|(
name|i
argument_list|,
operator|&
name|act
argument_list|,
name|NULL
argument_list|)
operator|!=
literal|0
condition|)
block|{
comment|/* 				 * Abort this process if signal 				 * initialisation fails:  				 */
name|PANIC
argument_list|(
literal|"Cannot initialise signal handler"
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* Get the table size: */
if|if
condition|(
operator|(
name|_thread_dtablesize
operator|=
name|getdtablesize
argument_list|()
operator|)
operator|<
literal|0
condition|)
block|{
comment|/* 			 * Cannot get the system defined table size, so abort 			 * this process.  			 */
name|PANIC
argument_list|(
literal|"Cannot get dtablesize"
argument_list|)
expr_stmt|;
block|}
comment|/* Allocate memory for the file descriptor table: */
if|if
condition|(
operator|(
name|_thread_fd_table
operator|=
operator|(
expr|struct
name|fd_table_entry
operator|*
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|fd_table_entry
operator|*
argument_list|)
operator|*
name|_thread_dtablesize
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
comment|/* 			 * Cannot allocate memory for the file descriptor 			 * table, so abort this process.  			 */
name|PANIC
argument_list|(
literal|"Cannot allocate memory for file descriptor table"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* 			 * Enter a loop to initialise the file descriptor 			 * table:  			 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|_thread_dtablesize
condition|;
name|i
operator|++
control|)
block|{
comment|/* Initialise the file descriptor table: */
name|_thread_fd_table
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
block|}
block|}
block|}
ifdef|#
directive|ifdef
name|GCC_2_8_MADE_THREAD_AWARE
comment|/* Create the thread-specific data for the exception linked list. */
if|if
condition|(
name|pthread_key_create
argument_list|(
operator|&
name|except_head_key
argument_list|,
name|NULL
argument_list|)
operator|!=
literal|0
condition|)
name|PANIC
argument_list|(
literal|"Failed to create thread specific execption head"
argument_list|)
expr_stmt|;
comment|/* Setup the gcc exception handler per thread. */
name|__set_dynamic_handler_allocator
argument_list|(
name|dynamic_allocator_handler_fn
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* GCC_2_8_MADE_THREAD_AWARE */
return|return;
block|}
end_function

begin_comment
comment|/*  * Special start up code for NetBSD/Alpha   */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__alpha__
argument_list|)
end_if

begin_function_decl
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|_thread_main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|env
parameter_list|)
block|{
name|_thread_init
argument_list|()
expr_stmt|;
return|return
operator|(
name|main
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|env
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * A stub for non-threaded programs.  */
end_comment

begin_function
name|void
name|_thread_init
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

