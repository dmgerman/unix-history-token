begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by Richard Henderson<rth@redhat.com>.     This file is part of the GNU OpenMP Library (libgomp).     Libgomp is free software; you can redistribute it and/or modify it    under the terms of the GNU Lesser General Public License as published by    the Free Software Foundation; either version 2.1 of the License, or    (at your option) any later version.     Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS    FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for    more details.     You should have received a copy of the GNU Lesser General Public License     along with libgomp; see the file COPYING.LIB.  If not, write to the    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files, some    of which are compiled with GCC, to produce an executable, this library    does not by itself cause the resulting executable to be covered by the    GNU General Public License.  This exception does not however invalidate    any other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_comment
comment|/* This file contains data types and function declarations that are not    part of the official OpenMP user interface.  There are declarations    in here that are part of the GNU OpenMP ABI, in that the compiler is    required to know about them and use them.     The convention is that the all caps prefix "GOMP" is used group items    that are part of the external ABI, and the lower case prefix "gomp"    is used group items that are completely private to the library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBGOMP_H
end_ifndef

begin_define
define|#
directive|define
name|LIBGOMP_H
value|1
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"gstdint.h"
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ATTRIBUTE_VISIBILITY
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|push
name|(
name|hidden
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sem.h"
end_include

begin_include
include|#
directive|include
file|"mutex.h"
end_include

begin_include
include|#
directive|include
file|"bar.h"
end_include

begin_comment
comment|/* This structure contains the data to control one work-sharing construct,    either a LOOP (FOR/DO) or a SECTIONS.  */
end_comment

begin_enum
enum|enum
name|gomp_schedule_type
block|{
name|GFS_STATIC
block|,
name|GFS_DYNAMIC
block|,
name|GFS_GUIDED
block|,
name|GFS_RUNTIME
block|}
enum|;
end_enum

begin_struct
struct|struct
name|gomp_work_share
block|{
comment|/* This member records the SCHEDULE clause to be used for this construct.      The user specification of "runtime" will already have been resolved.      If this is a SECTIONS construct, this value will always be DYNAMIC.  */
name|enum
name|gomp_schedule_type
name|sched
decl_stmt|;
comment|/* This is the chunk_size argument to the SCHEDULE clause.  */
name|long
name|chunk_size
decl_stmt|;
comment|/* This is the iteration end point.  If this is a SECTIONS construct,       this is the number of contained sections.  */
name|long
name|end
decl_stmt|;
comment|/* This is the iteration step.  If this is a SECTIONS construct, this      is always 1.  */
name|long
name|incr
decl_stmt|;
comment|/* This lock protects the update of the following members.  */
name|gomp_mutex_t
name|lock
decl_stmt|;
union|union
block|{
comment|/* This is the next iteration value to be allocated.  In the case of        GFS_STATIC loops, this the iteration start point and never changes.  */
name|long
name|next
decl_stmt|;
comment|/* This is the returned data structure for SINGLE COPYPRIVATE.  */
name|void
modifier|*
name|copyprivate
decl_stmt|;
block|}
union|;
comment|/* This is the count of the number of threads that have exited the work      share construct.  If the construct was marked nowait, they have moved on      to other work; otherwise they're blocked on a barrier.  The last member      of the team to exit the work share construct must deallocate it.  */
name|unsigned
name|threads_completed
decl_stmt|;
comment|/* This is the index into the circular queue ordered_team_ids of the       current thread that's allowed into the ordered reason.  */
name|unsigned
name|ordered_cur
decl_stmt|;
comment|/* This is the number of threads that have registered themselves in      the circular queue ordered_team_ids.  */
name|unsigned
name|ordered_num_used
decl_stmt|;
comment|/* This is the team_id of the currently acknoledged owner of the ordered      section, or -1u if the ordered section has not been acknowledged by      any thread.  This is distinguished from the thread that is *allowed*      to take the section next.  */
name|unsigned
name|ordered_owner
decl_stmt|;
comment|/* This is a circular queue that details which threads will be allowed      into the ordered region and in which order.  When a thread allocates      iterations on which it is going to work, it also registers itself at      the end of the array.  When a thread reaches the ordered region, it      checks to see if it is the one at the head of the queue.  If not, it      blocks on its RELEASE semaphore.  */
name|unsigned
name|ordered_team_ids
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure contains all of the thread-local data associated with     a thread team.  This is the data that must be saved when a thread    encounters a nested PARALLEL construct.  */
end_comment

begin_struct
struct|struct
name|gomp_team_state
block|{
comment|/* This is the team of which the thread is currently a member.  */
name|struct
name|gomp_team
modifier|*
name|team
decl_stmt|;
comment|/* This is the work share construct which this thread is currently      processing.  Recall that with NOWAIT, not all threads may be       processing the same construct.  This value is NULL when there      is no construct being processed.  */
name|struct
name|gomp_work_share
modifier|*
name|work_share
decl_stmt|;
comment|/* This is the ID of this thread within the team.  This value is      guaranteed to be between 0 and N-1, where N is the number of      threads in the team.  */
name|unsigned
name|team_id
decl_stmt|;
comment|/* The work share "generation" is a number that increases by one for      each work share construct encountered in the dynamic flow of the      program.  It is used to find the control data for the work share      when encountering it for the first time.  This particular number      reflects the generation of the work_share member of this struct.  */
name|unsigned
name|work_share_generation
decl_stmt|;
comment|/* For GFS_RUNTIME loops that resolved to GFS_STATIC, this is the      trip number through the loop.  So first time a particular loop      is encountered this number is 0, the second time through the loop      is 1, etc.  This is unused when the compiler knows in advance that      the loop is statically scheduled.  */
name|unsigned
name|long
name|static_trip
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure describes a "team" of threads.  These are the threads    that are spawned by a PARALLEL constructs, as well as the work sharing    constructs that the team encounters.  */
end_comment

begin_struct
struct|struct
name|gomp_team
block|{
comment|/* This lock protects access to the following work shares data structures.  */
name|gomp_mutex_t
name|work_share_lock
decl_stmt|;
comment|/* This is a dynamically sized array containing pointers to the control      structs for all "live" work share constructs.  Here "live" means that      the construct has been encountered by at least one thread, and not      completed by all threads.  */
name|struct
name|gomp_work_share
modifier|*
modifier|*
name|work_shares
decl_stmt|;
comment|/* The work_shares array is indexed by "generation& generation_mask".      The mask will be 2**N - 1, where 2**N is the size of the array.  */
name|unsigned
name|generation_mask
decl_stmt|;
comment|/* These two values define the bounds of the elements of the work_shares      array that are currently in use.  */
name|unsigned
name|oldest_live_gen
decl_stmt|;
name|unsigned
name|num_live_gen
decl_stmt|;
comment|/* This is the number of threads in the current team.  */
name|unsigned
name|nthreads
decl_stmt|;
comment|/* This is the saved team state that applied to a master thread before      the current thread was created.  */
name|struct
name|gomp_team_state
name|prev_ts
decl_stmt|;
comment|/* This barrier is used for most synchronization of the team.  */
name|gomp_barrier_t
name|barrier
decl_stmt|;
comment|/* This semaphore should be used by the master thread instead of its      "native" semaphore in the thread structure.  Required for nested      parallels, as the master is a member of two teams.  */
name|gomp_sem_t
name|master_release
decl_stmt|;
comment|/* This array contains pointers to the release semaphore of the threads      in the team.  */
name|gomp_sem_t
modifier|*
name|ordered_release
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure contains all data that is private to libgomp and is    allocated per thread.  */
end_comment

begin_struct
struct|struct
name|gomp_thread
block|{
comment|/* This is the function that the thread should run upon launch.  */
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
name|void
modifier|*
name|data
decl_stmt|;
comment|/* This is the current team state for this thread.  The ts.team member      is NULL only if the thread is idle.  */
name|struct
name|gomp_team_state
name|ts
decl_stmt|;
comment|/* This semaphore is used for ordered loops.  */
name|gomp_sem_t
name|release
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ... and here is that TLS data.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TLS
end_ifdef

begin_extern
extern|extern __thread struct gomp_thread gomp_tls_data;
end_extern

begin_function
specifier|static
specifier|inline
name|struct
name|gomp_thread
modifier|*
name|gomp_thread
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|&
name|gomp_tls_data
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|pthread_key_t
name|gomp_tls_key
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|struct
name|gomp_thread
modifier|*
name|gomp_thread
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|pthread_getspecific
argument_list|(
name|gomp_tls_key
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These are the OpenMP 2.5 internal control variables described in    section 2.3.  At least those that correspond to environment variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|gomp_nthreads_var
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|gomp_dyn_var
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|gomp_nest_var
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|gomp_schedule_type
name|gomp_run_sched_var
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|gomp_run_sched_chunk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The attributes to be used during thread creation.  */
end_comment

begin_decl_stmt
specifier|extern
name|pthread_attr_t
name|gomp_thread_attr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function prototypes.  */
end_comment

begin_comment
comment|/* alloc.c */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|gomp_malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(malloc
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
modifier|*
name|gomp_malloc_cleared
parameter_list|(
name|size_t
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(malloc
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
modifier|*
name|gomp_realloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Avoid conflicting prototypes of alloca() in system headers by using    GCC's builtin alloca().  */
end_comment

begin_define
define|#
directive|define
name|gomp_alloca
parameter_list|(
name|x
parameter_list|)
value|__builtin_alloca(x)
end_define

begin_comment
comment|/* error.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|gomp_error
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|gomp_fatal
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
operator|,
function_decl|format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* iter.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|gomp_iter_static_next
parameter_list|(
name|long
modifier|*
parameter_list|,
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|gomp_iter_dynamic_next_locked
parameter_list|(
name|long
modifier|*
parameter_list|,
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|gomp_iter_guided_next_locked
parameter_list|(
name|long
modifier|*
parameter_list|,
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYNC_BUILTINS
end_ifdef

begin_function_decl
specifier|extern
name|bool
name|gomp_iter_dynamic_next
parameter_list|(
name|long
modifier|*
parameter_list|,
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|gomp_iter_guided_next
parameter_list|(
name|long
modifier|*
parameter_list|,
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ordered.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|gomp_ordered_first
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gomp_ordered_last
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gomp_ordered_next
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gomp_ordered_static_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gomp_ordered_static_next
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gomp_ordered_sync
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* parallel.c */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|gomp_resolve_num_threads
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* proc.c (in config/) */
end_comment

begin_function_decl
specifier|extern
name|void
name|gomp_init_num_threads
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|gomp_dynamic_max_threads
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* team.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|gomp_team_start
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|struct
name|gomp_work_share
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gomp_team_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* work.c */
end_comment

begin_function_decl
specifier|extern
name|struct
name|gomp_work_share
modifier|*
name|gomp_new_work_share
parameter_list|(
name|bool
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|gomp_work_share_start
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gomp_work_share_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gomp_work_share_end_nowait
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ATTRIBUTE_VISIBILITY
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|pop
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Now that we're back to default visibility, include the globals.  */
end_comment

begin_include
include|#
directive|include
file|"libgomp_g.h"
end_include

begin_comment
comment|/* Include omp.h by parts.  */
end_comment

begin_include
include|#
directive|include
file|"omp-lock.h"
end_include

begin_define
define|#
directive|define
name|_LIBGOMP_OMP_LOCK_DEFINED
value|1
end_define

begin_include
include|#
directive|include
file|"omp.h.in"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ATTRIBUTE_VISIBILITY
end_ifdef

begin_define
define|#
directive|define
name|attribute_hidden
value|__attribute__ ((visibility ("hidden")))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|attribute_hidden
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ATTRIBUTE_ALIAS
end_ifdef

begin_define
define|#
directive|define
name|ialias
parameter_list|(
name|fn
parameter_list|)
define|\
value|extern __typeof (fn) gomp_ialias_##fn \     __attribute__ ((alias (#fn))) attribute_hidden;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ialias
parameter_list|(
name|fn
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

begin_comment
comment|/* LIBGOMP_H */
end_comment

end_unit

