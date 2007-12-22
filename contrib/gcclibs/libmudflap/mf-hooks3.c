begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Mudflap: narrow-pointer bounds-checking by tree rewriting.    Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.    Contributed by Frank Ch. Eigler<fche@redhat.com>    and Graydon Hoare<graydon@redhat.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  In addition to the permissions in the GNU General Public License, the Free Software Foundation gives you unlimited permission to link the compiled version of this file into combinations with other programs, and to distribute those combinations without any restriction coming from the use of this file.  (The General Public License restrictions do apply in other respects; for example, they cover modification of the file, and distribution when not linked into a combine executable.)  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SOCKLEN_T
end_ifndef

begin_define
define|#
directive|define
name|socklen_t
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These attempt to coax various unix flavours to declare all our    needed tidbits in the system headers.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some BSDs break<sys/socket.h> if this is defined. */
end_comment

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_define
define|#
directive|define
name|_XOPEN_SOURCE
end_define

begin_define
define|#
directive|define
name|_BSD_TYPES
end_define

begin_define
define|#
directive|define
name|__EXTENSIONS__
end_define

begin_define
define|#
directive|define
name|_ALL_SOURCE
end_define

begin_define
define|#
directive|define
name|_LARGE_FILE_API
end_define

begin_define
define|#
directive|define
name|_XOPEN_SOURCE_EXTENDED
value|1
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|"mf-runtime.h"
end_include

begin_include
include|#
directive|include
file|"mf-impl.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_MUDFLAP
end_ifdef

begin_error
error|#
directive|error
literal|"Do not compile this file with -fmudflap!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LIBMUDFLAPTH
end_ifndef

begin_error
error|#
directive|error
literal|"pthreadstuff is to be included only in libmudflapth"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ??? Why isn't this done once in the header files.  */
end_comment

begin_macro
name|DECLARE
argument_list|(
argument|void *
argument_list|,
argument|malloc
argument_list|,
argument|size_t sz
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|DECLARE
argument_list|(
name|void
argument_list|,
name|free
argument_list|,
name|void
operator|*
name|ptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|pthread_create
argument_list|,
name|pthread_t
operator|*
name|thr
argument_list|,
specifier|const
name|pthread_attr_t
operator|*
name|attr
argument_list|,
name|void
operator|*
call|(
modifier|*
name|start
call|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|,
name|void
operator|*
name|arg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Multithreading support hooks.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_TLS
end_ifndef

begin_comment
comment|/* We don't have TLS.  Ordinarily we could use pthread keys, but since we're    commandeering malloc/free that presents a few problems.  The first is that    we'll recurse from __mf_get_state to pthread_setspecific to malloc back to    __mf_get_state during thread startup.  This can be solved with clever uses    of a mutex.  The second problem is that thread shutdown is indistinguishable    from thread startup, since libpthread is deallocating our state variable.    I've no good solution for this.     Which leaves us to handle this mess by totally by hand.  */
end_comment

begin_comment
comment|/* Yes, we want this prime.  If pthread_t is a pointer, it's almost always    page aligned, and if we use a smaller power of 2, this results in "%N"    being the worst possible hash -- all threads hash to zero.  */
end_comment

begin_define
define|#
directive|define
name|LIBMUDFLAPTH_THREADS_MAX
value|1021
end_define

begin_struct
struct|struct
name|mf_thread_data
block|{
name|pthread_t
name|self
decl_stmt|;
name|unsigned
name|char
name|used_p
decl_stmt|;
name|unsigned
name|char
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|mf_thread_data
name|mf_thread_data
index|[
name|LIBMUDFLAPTH_THREADS_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|pthread_mutex_t
name|mf_thread_data_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PTHREAD_HASH
parameter_list|(
name|p
parameter_list|)
value|((unsigned long) (p) % LIBMUDFLAPTH_THREADS_MAX)
end_define

begin_function
specifier|static
name|struct
name|mf_thread_data
modifier|*
name|__mf_find_threadinfo
parameter_list|(
name|int
name|alloc
parameter_list|)
block|{
name|pthread_t
name|self
init|=
name|pthread_self
argument_list|()
decl_stmt|;
name|unsigned
name|long
name|hash
init|=
name|PTHREAD_HASH
argument_list|(
name|self
argument_list|)
decl_stmt|;
name|unsigned
name|long
name|rehash
decl_stmt|;
ifdef|#
directive|ifdef
name|__alpha__
comment|/* Alpha has the loosest memory ordering rules of all.  We need a memory      barrier to flush the reorder buffer before considering a *read* of a      shared variable.  Since we're not always taking a lock, we have to do      this by hand.  */
name|__sync_synchronize
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|rehash
operator|=
name|hash
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
if|if
condition|(
name|mf_thread_data
index|[
name|rehash
index|]
operator|.
name|used_p
operator|&&
name|mf_thread_data
index|[
name|rehash
index|]
operator|.
name|self
operator|==
name|self
condition|)
return|return
operator|&
name|mf_thread_data
index|[
name|rehash
index|]
return|;
name|rehash
operator|+=
literal|7
expr_stmt|;
if|if
condition|(
name|rehash
operator|>=
name|LIBMUDFLAPTH_THREADS_MAX
condition|)
name|rehash
operator|-=
name|LIBMUDFLAPTH_THREADS_MAX
expr_stmt|;
if|if
condition|(
name|rehash
operator|==
name|hash
condition|)
break|break;
block|}
if|if
condition|(
name|alloc
condition|)
block|{
name|pthread_mutex_lock
argument_list|(
operator|&
name|mf_thread_data_lock
argument_list|)
expr_stmt|;
name|rehash
operator|=
name|hash
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
if|if
condition|(
operator|!
name|mf_thread_data
index|[
name|rehash
index|]
operator|.
name|used_p
condition|)
block|{
name|mf_thread_data
index|[
name|rehash
index|]
operator|.
name|self
operator|=
name|self
expr_stmt|;
name|__sync_synchronize
argument_list|()
expr_stmt|;
name|mf_thread_data
index|[
name|rehash
index|]
operator|.
name|used_p
operator|=
literal|1
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mf_thread_data_lock
argument_list|)
expr_stmt|;
return|return
operator|&
name|mf_thread_data
index|[
name|rehash
index|]
return|;
block|}
name|rehash
operator|+=
literal|7
expr_stmt|;
if|if
condition|(
name|rehash
operator|>=
name|LIBMUDFLAPTH_THREADS_MAX
condition|)
name|rehash
operator|-=
name|LIBMUDFLAPTH_THREADS_MAX
expr_stmt|;
if|if
condition|(
name|rehash
operator|==
name|hash
condition|)
break|break;
block|}
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mf_thread_data_lock
argument_list|)
expr_stmt|;
block|}
return|return
name|NULL
return|;
block|}
end_function

begin_function
name|enum
name|__mf_state_enum
name|__mf_get_state
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|mf_thread_data
modifier|*
name|data
init|=
name|__mf_find_threadinfo
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|data
condition|)
return|return
name|data
operator|->
name|state
return|;
comment|/* If we've never seen this thread before, consider it to be in the      reentrant state.  The state gets reset to active for the main thread      in __mf_init, and for child threads in __mf_pthread_spawner.       The trickiest bit here is that the LinuxThreads pthread_manager thread      should *always* be considered to be reentrant, so that none of our       hooks actually do anything.  Why?  Because that thread isn't a real      thread from the point of view of the thread library, and so lots of      stuff isn't initialized, leading to SEGV very quickly.  Even calling      pthread_self is a bit suspect, but it happens to work.  */
return|return
name|reentrant
return|;
block|}
end_function

begin_function
name|void
name|__mf_set_state
parameter_list|(
name|enum
name|__mf_state_enum
name|new_state
parameter_list|)
block|{
name|struct
name|mf_thread_data
modifier|*
name|data
init|=
name|__mf_find_threadinfo
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|data
operator|->
name|state
operator|=
name|new_state
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The following two functions are used only with __mf_opts.heur_std_data.    We're interested in recording the location of the thread-local errno    variable.     Note that this doesn't handle TLS references in general; we have no    visibility into __tls_get_data for when that memory is allocated at    runtime.  Hopefully we get to see the malloc or mmap operation that    eventually allocates the backing store.  */
end_comment

begin_comment
comment|/* Describe the startup information for a new user thread.  */
end_comment

begin_struct
struct|struct
name|mf_thread_start_info
block|{
comment|/* The user's thread entry point and argument.  */
name|void
modifier|*
function_decl|(
modifier|*
name|user_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|user_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|void
name|__mf_pthread_cleanup
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
if|if
condition|(
name|__mf_opts
operator|.
name|heur_std_data
condition|)
name|__mf_unregister
argument_list|(
operator|&
name|errno
argument_list|,
sizeof|sizeof
argument_list|(
name|errno
argument_list|)
argument_list|,
name|__MF_TYPE_GUESS
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|HAVE_TLS
name|struct
name|mf_thread_data
modifier|*
name|data
init|=
name|__mf_find_threadinfo
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|data
condition|)
name|data
operator|->
name|used_p
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|void
modifier|*
name|__mf_pthread_spawner
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|void
modifier|*
name|result
init|=
name|NULL
decl_stmt|;
name|__mf_set_state
argument_list|(
name|active
argument_list|)
expr_stmt|;
comment|/* NB: We could use __MF_TYPE_STATIC here, but we guess that the thread      errno is coming out of some dynamically allocated pool that we already      know of as __MF_TYPE_HEAP. */
if|if
condition|(
name|__mf_opts
operator|.
name|heur_std_data
condition|)
name|__mf_register
argument_list|(
operator|&
name|errno
argument_list|,
sizeof|sizeof
argument_list|(
name|errno
argument_list|)
argument_list|,
name|__MF_TYPE_GUESS
argument_list|,
literal|"errno area (thread)"
argument_list|)
expr_stmt|;
comment|/* We considered using pthread_key_t objects instead of these      cleanup stacks, but they were less cooperative with the      interposed malloc hooks in libmudflap.  */
comment|/* ??? The pthread_key_t problem is solved above...  */
name|pthread_cleanup_push
argument_list|(
name|__mf_pthread_cleanup
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* Extract given entry point and argument.  */
name|struct
name|mf_thread_start_info
modifier|*
name|psi
init|=
name|arg
decl_stmt|;
name|void
modifier|*
function_decl|(
modifier|*
name|user_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
init|=
name|psi
operator|->
name|user_fn
function_decl|;
name|void
modifier|*
name|user_arg
init|=
name|psi
operator|->
name|user_arg
decl_stmt|;
name|CALL_REAL
argument_list|(
name|free
argument_list|,
name|arg
argument_list|)
expr_stmt|;
name|result
operator|=
call|(
modifier|*
name|user_fn
call|)
argument_list|(
name|user_arg
argument_list|)
expr_stmt|;
name|pthread_cleanup_pop
argument_list|(
literal|1
comment|/* execute */
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

begin_if
if|#
directive|if
name|PIC
end_if

begin_comment
comment|/* A special bootstrap variant. */
end_comment

begin_function
name|int
name|__mf_0fn_pthread_create
parameter_list|(
name|pthread_t
modifier|*
name|thr
parameter_list|,
specifier|const
name|pthread_attr_t
modifier|*
name|attr
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
name|start
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|pthread_create
end_undef

begin_macro
name|WRAPPER
argument_list|(
argument|int
argument_list|,
argument|pthread_create
argument_list|,
argument|pthread_t *thr
argument_list|,
argument|const pthread_attr_t *attr
argument_list|,
argument|void * (*start) (void *)
argument_list|,
argument|void *arg
argument_list|)
end_macro

begin_block
block|{
name|struct
name|mf_thread_start_info
modifier|*
name|si
decl_stmt|;
name|TRACE
argument_list|(
literal|"pthread_create\n"
argument_list|)
expr_stmt|;
comment|/* Fill in startup-control fields.  */
name|si
operator|=
name|CALL_REAL
argument_list|(
name|malloc
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|si
argument_list|)
argument_list|)
expr_stmt|;
name|si
operator|->
name|user_fn
operator|=
name|start
expr_stmt|;
name|si
operator|->
name|user_arg
operator|=
name|arg
expr_stmt|;
comment|/* Actually create the thread.  */
return|return
name|CALL_REAL
argument_list|(
name|pthread_create
argument_list|,
name|thr
argument_list|,
name|attr
argument_list|,
name|__mf_pthread_spawner
argument_list|,
name|si
argument_list|)
return|;
block|}
end_block

end_unit

