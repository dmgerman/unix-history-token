begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  * POSIX stdio FILE locking functions. These assume that the locking  * is only required at FILE structure level, not at file descriptor  * level too.  *  */
end_comment

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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_THREAD_SAFE
end_ifdef

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

begin_comment
comment|/*  * Weak symbols for externally visible functions in this file:  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|flockfile
name|=
name|_flockfile
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|ftrylockfile
name|=
name|_ftrylockfile
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|funlockfile
name|=
name|_funlockfile
end_pragma

begin_comment
comment|/*  * The FILE lock structure. The FILE *fp is locked if the owner is  * not NULL. If not locked, the file lock structure can be  * reassigned to a different file by setting fp.  */
end_comment

begin_struct
struct|struct
name|file_lock
block|{
name|LIST_ENTRY
argument_list|(
argument|file_lock
argument_list|)
name|entry
expr_stmt|;
comment|/* Entry if file list.       */
name|TAILQ_HEAD
argument_list|(
argument|lock_head
argument_list|,
argument|pthread
argument_list|)
name|l_head
expr_stmt|;
comment|/* Head of queue for threads */
comment|/* waiting on this lock.     */
name|FILE
modifier|*
name|fp
decl_stmt|;
comment|/* The target file.          */
name|pthread_t
name|owner
decl_stmt|;
comment|/* Thread that owns lock.    */
name|int
name|count
decl_stmt|;
comment|/* Lock count for owner.     */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The number of file lock lists into which the file pointer is  * hashed. Ideally, the FILE structure size would have been increased,  * but this causes incompatibility, so separate data structures are  * required.  */
end_comment

begin_define
define|#
directive|define
name|NUM_HEADS
value|128
end_define

begin_comment
comment|/*  * This macro casts a file pointer to a long integer and right  * shifts this by the number of bytes in a pointer. The shifted  * value is then remaindered using the maximum number of hash  * entries to produce and index into the array of static lock  * structures. If there is a collision, a linear search of the  * dynamic list of locks linked to each static lock is perfomed.  */
end_comment

begin_define
define|#
directive|define
name|file_idx
parameter_list|(
name|_p
parameter_list|)
value|((((u_long) _p)>> sizeof(void *)) % NUM_HEADS)
end_define

begin_comment
comment|/*  * Global array of file locks. The first lock for each hash bucket is  * allocated statically in the hope that there won't be too many  * collisions that require a malloc and an element added to the list.  */
end_comment

begin_struct
struct|struct
name|static_file_lock
block|{
name|LIST_HEAD
argument_list|(
argument|file_list_head
argument_list|,
argument|file_lock
argument_list|)
name|head
expr_stmt|;
name|struct
name|file_lock
name|fl
decl_stmt|;
block|}
name|flh
index|[
name|NUM_HEADS
index|]
struct|;
end_struct

begin_comment
comment|/* Set to non-zero when initialisation is complete: */
end_comment

begin_decl_stmt
specifier|static
name|int
name|init_done
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lock for accesses to the hash table: */
end_comment

begin_decl_stmt
specifier|static
name|spinlock_t
name|hash_lock
init|=
name|_SPINLOCK_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Find a lock structure for a FILE, return NULL if the file is  * not locked:  */
end_comment

begin_function
specifier|static
name|struct
name|file_lock
modifier|*
name|find_lock
parameter_list|(
name|int
name|idx
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|)
block|{
name|struct
name|file_lock
modifier|*
name|p
decl_stmt|;
comment|/* Check if the file is locked using the static structure: */
if|if
condition|(
name|flh
index|[
name|idx
index|]
operator|.
name|fl
operator|.
name|fp
operator|==
name|fp
operator|&&
name|flh
index|[
name|idx
index|]
operator|.
name|fl
operator|.
name|owner
operator|!=
name|NULL
condition|)
comment|/* Return a pointer to the static lock: */
name|p
operator|=
operator|&
name|flh
index|[
name|idx
index|]
operator|.
name|fl
expr_stmt|;
else|else
block|{
comment|/* Point to the first dynamic lock: */
name|p
operator|=
name|flh
index|[
name|idx
index|]
operator|.
name|head
operator|.
name|lh_first
expr_stmt|;
comment|/* 		 * Loop through the dynamic locks looking for the 		 * target file: 		 */
while|while
condition|(
name|p
operator|!=
name|NULL
operator|&&
operator|(
name|p
operator|->
name|fp
operator|!=
name|fp
operator|||
name|p
operator|->
name|owner
operator|==
name|NULL
operator|)
condition|)
comment|/* Not this file, try the next: */
name|p
operator|=
name|p
operator|->
name|entry
operator|.
name|le_next
expr_stmt|;
block|}
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Lock a file, assuming that there is no lock structure currently  * assigned to it.  */
end_comment

begin_function
specifier|static
name|struct
name|file_lock
modifier|*
name|do_lock
parameter_list|(
name|int
name|idx
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|)
block|{
name|struct
name|file_lock
modifier|*
name|p
decl_stmt|;
comment|/* Check if the static structure is not being used: */
if|if
condition|(
name|flh
index|[
name|idx
index|]
operator|.
name|fl
operator|.
name|owner
operator|==
name|NULL
condition|)
block|{
comment|/* Return a pointer to the static lock: */
name|p
operator|=
operator|&
name|flh
index|[
name|idx
index|]
operator|.
name|fl
expr_stmt|;
block|}
else|else
block|{
comment|/* Point to the first dynamic lock: */
name|p
operator|=
name|flh
index|[
name|idx
index|]
operator|.
name|head
operator|.
name|lh_first
expr_stmt|;
comment|/* 		 * Loop through the dynamic locks looking for a 		 * lock structure that is not being used: 		 */
while|while
condition|(
name|p
operator|!=
name|NULL
operator|&&
name|p
operator|->
name|owner
operator|!=
name|NULL
condition|)
comment|/* This one is used, try the next: */
name|p
operator|=
name|p
operator|->
name|entry
operator|.
name|le_next
expr_stmt|;
block|}
comment|/* 	 * If an existing lock structure has not been found, 	 * allocate memory for a new one: 	 */
if|if
condition|(
name|p
operator|==
name|NULL
operator|&&
operator|(
name|p
operator|=
operator|(
expr|struct
name|file_lock
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|file_lock
argument_list|)
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
comment|/* Add the new element to the list: */
name|LIST_INSERT_HEAD
argument_list|(
operator|&
name|flh
index|[
name|idx
index|]
operator|.
name|head
argument_list|,
name|p
argument_list|,
name|entry
argument_list|)
expr_stmt|;
block|}
comment|/* Check if there is a lock structure to acquire: */
if|if
condition|(
name|p
operator|!=
name|NULL
condition|)
block|{
comment|/* Acquire the lock for the running thread: */
name|p
operator|->
name|fp
operator|=
name|fp
expr_stmt|;
name|p
operator|->
name|owner
operator|=
name|_thread_run
expr_stmt|;
name|p
operator|->
name|count
operator|=
literal|1
expr_stmt|;
name|TAILQ_INIT
argument_list|(
operator|&
name|p
operator|->
name|l_head
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_function
name|void
name|_flockfile_debug
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
name|int
name|lineno
parameter_list|)
block|{
name|int
name|idx
init|=
name|file_idx
argument_list|(
name|fp
argument_list|)
decl_stmt|;
name|struct
name|file_lock
modifier|*
name|p
decl_stmt|;
comment|/* Check if this is a real file: */
if|if
condition|(
name|fp
operator|->
name|_file
operator|>=
literal|0
condition|)
block|{
comment|/* Lock the hash table: */
name|_SPINLOCK
argument_list|(
operator|&
name|hash_lock
argument_list|)
expr_stmt|;
comment|/* Check if the static array has not been initialised: */
if|if
condition|(
operator|!
name|init_done
condition|)
block|{
comment|/* Initialise the global array: */
name|memset
argument_list|(
name|flh
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|flh
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Flag the initialisation as complete: */
name|init_done
operator|=
literal|1
expr_stmt|;
block|}
comment|/* Get a pointer to any existing lock for the file: */
if|if
condition|(
operator|(
name|p
operator|=
name|find_lock
argument_list|(
name|idx
argument_list|,
name|fp
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
comment|/* 			 * The file is not locked, so this thread can 			 * grab the lock: 			 */
name|p
operator|=
name|do_lock
argument_list|(
name|idx
argument_list|,
name|fp
argument_list|)
expr_stmt|;
comment|/* Unlock the hash table: */
name|_SPINUNLOCK
argument_list|(
operator|&
name|hash_lock
argument_list|)
expr_stmt|;
comment|/* 		 * The file is already locked, so check if the 		 * running thread is the owner: 		 */
block|}
elseif|else
if|if
condition|(
name|p
operator|->
name|owner
operator|==
name|_thread_run
condition|)
block|{
comment|/* 			 * The running thread is already the 			 * owner, so increment the count of 			 * the number of times it has locked 			 * the file: 			 */
name|p
operator|->
name|count
operator|++
expr_stmt|;
comment|/* Unlock the hash table: */
name|_SPINUNLOCK
argument_list|(
operator|&
name|hash_lock
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* 			 * The file is locked for another thread. 			 * Append this thread to the queue of 			 * threads waiting on the lock. 			 */
name|TAILQ_INSERT_TAIL
argument_list|(
operator|&
name|p
operator|->
name|l_head
argument_list|,
name|_thread_run
argument_list|,
name|qe
argument_list|)
expr_stmt|;
comment|/* Unlock the hash table: */
name|_SPINUNLOCK
argument_list|(
operator|&
name|hash_lock
argument_list|)
expr_stmt|;
comment|/* Wait on the FILE lock: */
name|_thread_kern_sched_state
argument_list|(
name|PS_FILE_WAIT
argument_list|,
name|fname
argument_list|,
name|lineno
argument_list|)
expr_stmt|;
block|}
block|}
return|return;
block|}
end_function

begin_function
name|void
name|_flockfile
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|)
block|{
name|_flockfile_debug
argument_list|(
name|fp
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
name|int
name|_ftrylockfile
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|)
block|{
name|int
name|ret
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|idx
init|=
name|file_idx
argument_list|(
name|fp
argument_list|)
decl_stmt|;
name|struct
name|file_lock
modifier|*
name|p
decl_stmt|;
comment|/* Check if this is a real file: */
if|if
condition|(
name|fp
operator|->
name|_file
operator|>=
literal|0
condition|)
block|{
comment|/* Lock the hash table: */
name|_SPINLOCK
argument_list|(
operator|&
name|hash_lock
argument_list|)
expr_stmt|;
comment|/* Get a pointer to any existing lock for the file: */
if|if
condition|(
operator|(
name|p
operator|=
name|find_lock
argument_list|(
name|idx
argument_list|,
name|fp
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
comment|/* 			 * The file is not locked, so this thread can 			 * grab the lock: 			 */
name|p
operator|=
name|do_lock
argument_list|(
name|idx
argument_list|,
name|fp
argument_list|)
expr_stmt|;
comment|/* 		 * The file is already locked, so check if the 		 * running thread is the owner: 		 */
block|}
elseif|else
if|if
condition|(
name|p
operator|->
name|owner
operator|==
name|_thread_run
condition|)
block|{
comment|/* 			 * The running thread is already the 			 * owner, so increment the count of 			 * the number of times it has locked 			 * the file: 			 */
name|p
operator|->
name|count
operator|++
expr_stmt|;
block|}
else|else
block|{
comment|/* 			 * The file is locked for another thread, 			 * so this try fails. 			 */
name|p
operator|=
name|NULL
expr_stmt|;
block|}
comment|/* Check if the lock was obtained: */
if|if
condition|(
name|p
operator|!=
name|NULL
condition|)
comment|/* Return success: */
name|ret
operator|=
literal|0
expr_stmt|;
comment|/* Unlock the hash table: */
name|_SPINUNLOCK
argument_list|(
operator|&
name|hash_lock
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_function
name|void
name|_funlockfile
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|)
block|{
name|int
name|status
decl_stmt|;
name|int
name|idx
init|=
name|file_idx
argument_list|(
name|fp
argument_list|)
decl_stmt|;
name|struct
name|file_lock
modifier|*
name|p
decl_stmt|;
comment|/* Check if this is a real file: */
if|if
condition|(
name|fp
operator|->
name|_file
operator|>=
literal|0
condition|)
block|{
comment|/* 		 * Defer signals to protect the scheduling queues from 		 * access by the signal handler: 		 */
name|_thread_kern_sig_defer
argument_list|()
expr_stmt|;
comment|/* Lock the hash table: */
name|_SPINLOCK
argument_list|(
operator|&
name|hash_lock
argument_list|)
expr_stmt|;
comment|/* 		 * Get a pointer to the lock for the file and check that 		 * the running thread is the one with the lock: 		 */
if|if
condition|(
operator|(
name|p
operator|=
name|find_lock
argument_list|(
name|idx
argument_list|,
name|fp
argument_list|)
operator|)
operator|!=
name|NULL
operator|&&
name|p
operator|->
name|owner
operator|==
name|_thread_run
condition|)
block|{
comment|/* 			 * Check if this thread has locked the FILE 			 * more than once: 			 */
if|if
condition|(
name|p
operator|->
name|count
operator|>
literal|1
condition|)
comment|/* 				 * Decrement the count of the number of 				 * times the running thread has locked this 				 * file: 				 */
name|p
operator|->
name|count
operator|--
expr_stmt|;
else|else
block|{
comment|/* 				 * The running thread will release the 				 * lock now: 				 */
name|p
operator|->
name|count
operator|=
literal|0
expr_stmt|;
comment|/* Get the new owner of the lock: */
if|if
condition|(
operator|(
name|p
operator|->
name|owner
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|p
operator|->
name|l_head
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
comment|/* Pop the thread off the queue: */
name|TAILQ_REMOVE
argument_list|(
operator|&
name|p
operator|->
name|l_head
argument_list|,
name|p
operator|->
name|owner
argument_list|,
name|qe
argument_list|)
expr_stmt|;
comment|/* 					 * This is the first lock for the new 					 * owner: 					 */
name|p
operator|->
name|count
operator|=
literal|1
expr_stmt|;
comment|/* Allow the new owner to run: */
name|PTHREAD_NEW_STATE
argument_list|(
name|p
operator|->
name|owner
argument_list|,
name|PS_RUNNING
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|/* Unlock the hash table: */
name|_SPINUNLOCK
argument_list|(
operator|&
name|hash_lock
argument_list|)
expr_stmt|;
comment|/* 		 * Undefer and handle pending signals, yielding if 		 * necessary: 		 */
name|_thread_kern_sig_undefer
argument_list|()
expr_stmt|;
block|}
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

