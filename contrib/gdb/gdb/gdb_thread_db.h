begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_THREAD_DB_H
end_ifdef

begin_include
include|#
directive|include
file|<thread_db.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDINT_H
end_ifdef

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_typedef
typedef|typedef
name|uint32_t
name|gdb_uint32_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GDB_UINT32_C
parameter_list|(
name|c
parameter_list|)
value|UINT32_C(c)
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|int
name|gdb_uint32_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GDB_UINT32_C
parameter_list|(
name|c
parameter_list|)
value|c ## U
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Copyright 1999, 2000 Free Software Foundation, Inc.    This file is part of the GNU C Library.     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with the GNU C Library; see the file COPYING.LIB.  If not,    write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_THREAD_DB_H
end_ifndef

begin_define
define|#
directive|define
name|_THREAD_DB_H
value|1
end_define

begin_comment
comment|/* This is the debugger interface for the LinuxThreads library.  It is    modelled closely after the interface with same names in Solaris with    the goal to share the same code in the debugger.  */
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/procfs.h>
end_include

begin_comment
comment|/* Error codes of the library.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TD_OK
block|,
comment|/* No error.  */
name|TD_ERR
block|,
comment|/* No further specified error.  */
name|TD_NOTHR
block|,
comment|/* No matching thread found.  */
name|TD_NOSV
block|,
comment|/* No matching synchronization handle found.  */
name|TD_NOLWP
block|,
comment|/* No matching light-weighted process found.  */
name|TD_BADPH
block|,
comment|/* Invalid process handle.  */
name|TD_BADTH
block|,
comment|/* Invalid thread handle.  */
name|TD_BADSH
block|,
comment|/* Invalid synchronization handle.  */
name|TD_BADTA
block|,
comment|/* Invalid thread agent.  */
name|TD_BADKEY
block|,
comment|/* Invalid key.  */
name|TD_NOMSG
block|,
comment|/* No event available.  */
name|TD_NOFPREGS
block|,
comment|/* No floating-point register content available.  */
name|TD_NOLIBTHREAD
block|,
comment|/* Application not linked with thread library.  */
name|TD_NOEVENT
block|,
comment|/* Requested event is not supported.  */
name|TD_NOCAPAB
block|,
comment|/* Capability not available.  */
name|TD_DBERR
block|,
comment|/* Internal debug library error.  */
name|TD_NOAPLIC
block|,
comment|/* Operation is not applicable.  */
name|TD_NOTSD
block|,
comment|/* No thread-specific data available.  */
name|TD_MALLOC
block|,
comment|/* Out of memory.  */
name|TD_PARTIALREG
block|,
comment|/* Not entire register set was read or written.  */
name|TD_NOXREGS
block|,
comment|/* X register set not available for given thread.  */
name|TD_NOTALLOC
comment|/* TLS memory not yet allocated.  */
block|}
name|td_err_e
typedef|;
end_typedef

begin_comment
comment|/* Possible thread states.  TD_THR_ANY_STATE is a pseudo-state used to    select threads regardless of state in td_ta_thr_iter().  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TD_THR_ANY_STATE
block|,
name|TD_THR_UNKNOWN
block|,
name|TD_THR_STOPPED
block|,
name|TD_THR_RUN
block|,
name|TD_THR_ACTIVE
block|,
name|TD_THR_ZOMBIE
block|,
name|TD_THR_SLEEP
block|,
name|TD_THR_STOPPED_ASLEEP
block|}
name|td_thr_state_e
typedef|;
end_typedef

begin_comment
comment|/* Thread type: user or system.  TD_THR_ANY_TYPE is a pseudo-type used    to select threads regardless of type in td_ta_thr_iter().  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TD_THR_ANY_TYPE
block|,
name|TD_THR_USER
block|,
name|TD_THR_SYSTEM
block|}
name|td_thr_type_e
typedef|;
end_typedef

begin_comment
comment|/* Types of the debugging library.  */
end_comment

begin_comment
comment|/* Handle for a process.  This type is opaque.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|td_thragent
name|td_thragent_t
typedef|;
end_typedef

begin_comment
comment|/* The actual thread handle type.  This is also opaque.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|td_thrhandle
block|{
name|td_thragent_t
modifier|*
name|th_ta_p
decl_stmt|;
name|psaddr_t
name|th_unique
decl_stmt|;
block|}
name|td_thrhandle_t
typedef|;
end_typedef

begin_comment
comment|/* Flags for `td_ta_thr_iter'.  */
end_comment

begin_define
define|#
directive|define
name|TD_THR_ANY_USER_FLAGS
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|TD_THR_LOWEST_PRIORITY
value|-20
end_define

begin_define
define|#
directive|define
name|TD_SIGNO_MASK
value|NULL
end_define

begin_define
define|#
directive|define
name|TD_EVENTSIZE
value|2
end_define

begin_define
define|#
directive|define
name|BT_UISHIFT
value|5
end_define

begin_comment
comment|/* log base 2 of BT_NBIPUI, to extract word index */
end_comment

begin_define
define|#
directive|define
name|BT_NBIPUI
value|(1<< BT_UISHIFT)
end_define

begin_comment
comment|/* n bits per uint */
end_comment

begin_define
define|#
directive|define
name|BT_UIMASK
value|(BT_NBIPUI - 1)
end_define

begin_comment
comment|/* to extract bit index */
end_comment

begin_comment
comment|/* Bitmask of enabled events. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|td_thr_events
block|{
name|gdb_uint32_t
name|event_bits
index|[
name|TD_EVENTSIZE
index|]
decl_stmt|;
block|}
name|td_thr_events_t
typedef|;
end_typedef

begin_comment
comment|/* Event set manipulation macros. */
end_comment

begin_define
define|#
directive|define
name|__td_eventmask
parameter_list|(
name|n
parameter_list|)
define|\
value|(GDB_UINT32_C (1)<< (((n) - 1)& BT_UIMASK))
end_define

begin_define
define|#
directive|define
name|__td_eventword
parameter_list|(
name|n
parameter_list|)
define|\
value|((GDB_UINT32_C ((n) - 1))>> BT_UISHIFT)
end_define

begin_define
define|#
directive|define
name|td_event_emptyset
parameter_list|(
name|setp
parameter_list|)
define|\
value|do {									      \     int __i;								      \     for (__i = TD_EVENTSIZE; __i> 0; --__i)				      \       (setp)->event_bits[__i - 1] = 0;					      \   } while (0)
end_define

begin_define
define|#
directive|define
name|td_event_fillset
parameter_list|(
name|setp
parameter_list|)
define|\
value|do {									      \     int __i;								      \     for (__i = TD_EVENTSIZE; __i> 0; --__i)				      \       (setp)->event_bits[__i - 1] = GDB_UINT32_C (0xffffffff);		      \   } while (0)
end_define

begin_define
define|#
directive|define
name|td_event_addset
parameter_list|(
name|setp
parameter_list|,
name|n
parameter_list|)
define|\
value|(((setp)->event_bits[__td_eventword (n)]) |= __td_eventmask (n))
end_define

begin_define
define|#
directive|define
name|td_event_delset
parameter_list|(
name|setp
parameter_list|,
name|n
parameter_list|)
define|\
value|(((setp)->event_bits[__td_eventword (n)])&= ~__td_eventmask (n))
end_define

begin_define
define|#
directive|define
name|td_eventismember
parameter_list|(
name|setp
parameter_list|,
name|n
parameter_list|)
define|\
value|(__td_eventmask (n)& ((setp)->event_bits[__td_eventword (n)]))
end_define

begin_if
if|#
directive|if
name|TD_EVENTSIZE
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|td_eventisempty
parameter_list|(
name|setp
parameter_list|)
define|\
value|(!((setp)->event_bits[0])&& !((setp)->event_bits[1]))
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"td_eventisempty must be changed to match TD_EVENTSIZE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Events reportable by the thread implementation.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TD_ALL_EVENTS
block|,
comment|/* Pseudo-event number.  */
name|TD_EVENT_NONE
init|=
name|TD_ALL_EVENTS
block|,
comment|/* Depends on context.  */
name|TD_READY
block|,
comment|/* Is executable now. */
name|TD_SLEEP
block|,
comment|/* Blocked in a synchronization obj.  */
name|TD_SWITCHTO
block|,
comment|/* Now assigned to a process.  */
name|TD_SWITCHFROM
block|,
comment|/* Not anymore assigned to a process.  */
name|TD_LOCK_TRY
block|,
comment|/* Trying to get an unavailable lock.  */
name|TD_CATCHSIG
block|,
comment|/* Signal posted to the thread.  */
name|TD_IDLE
block|,
comment|/* Process getting idle.  */
name|TD_CREATE
block|,
comment|/* New thread created.  */
name|TD_DEATH
block|,
comment|/* Thread terminated.  */
name|TD_PREEMPT
block|,
comment|/* Preempted.  */
name|TD_PRI_INHERIT
block|,
comment|/* Inherited elevated priority.  */
name|TD_REAP
block|,
comment|/* Reaped.  */
name|TD_CONCURRENCY
block|,
comment|/* Number of processes changing.  */
name|TD_TIMEOUT
block|,
comment|/* Conditional variable wait timed out.  */
name|TD_MIN_EVENT_NUM
init|=
name|TD_READY
block|,
name|TD_MAX_EVENT_NUM
init|=
name|TD_TIMEOUT
block|,
name|TD_EVENTS_ENABLE
init|=
literal|31
comment|/* Event reporting enabled.  */
block|}
name|td_event_e
typedef|;
end_typedef

begin_comment
comment|/* Values representing the different ways events are reported.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|NOTIFY_BPT
block|,
comment|/* User must insert breakpoint at u.bptaddr. */
name|NOTIFY_AUTOBPT
block|,
comment|/* Breakpoint at u.bptaddr is automatically 				   inserted.  */
name|NOTIFY_SYSCALL
comment|/* System call u.syscallno will be invoked.  */
block|}
name|td_notify_e
typedef|;
end_typedef

begin_comment
comment|/* Description how event type is reported.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|td_notify
block|{
name|td_notify_e
name|type
decl_stmt|;
comment|/* Way the event is reported.  */
union|union
block|{
name|psaddr_t
name|bptaddr
decl_stmt|;
comment|/* Address of breakpoint.  */
name|int
name|syscallno
decl_stmt|;
comment|/* Number of system call used.  */
block|}
name|u
union|;
block|}
name|td_notify_t
typedef|;
end_typedef

begin_comment
comment|/* Some people still have libc5 or old glibc with no uintptr_t.    They lose.  glibc 2.1.3 was released on 2000-02-25, and it has    uintptr_t, so it's reasonable to force these people to upgrade.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UINTPTR_T
end_ifndef

begin_error
error|#
directive|error
error|No uintptr_t available; your C library is too old.
end_error

begin_comment
comment|/* Inhibit further compilation errors after this error.  */
end_comment

begin_define
define|#
directive|define
name|uintptr_t
value|void *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Structure used to report event.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|td_event_msg
block|{
name|td_event_e
name|event
decl_stmt|;
comment|/* Event type being reported.  */
specifier|const
name|td_thrhandle_t
modifier|*
name|th_p
decl_stmt|;
comment|/* Thread reporting the event.  */
union|union
block|{
if|#
directive|if
literal|0
block|td_synchandle_t *sh;
comment|/* Handle of synchronization object.  */
endif|#
directive|endif
name|uintptr_t
name|data
decl_stmt|;
comment|/* Event specific data.  */
block|}
name|msg
union|;
block|}
name|td_event_msg_t
typedef|;
end_typedef

begin_comment
comment|/* Structure containing event data available in each thread structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|td_thr_events_t
name|eventmask
decl_stmt|;
comment|/* Mask of enabled events.  */
name|td_event_e
name|eventnum
decl_stmt|;
comment|/* Number of last event.  */
name|void
modifier|*
name|eventdata
decl_stmt|;
comment|/* Data associated with event.  */
block|}
name|td_eventbuf_t
typedef|;
end_typedef

begin_comment
comment|/* Gathered statistics about the process.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|td_ta_stats
block|{
name|int
name|nthreads
decl_stmt|;
comment|/* Total number of threads in use.  */
name|int
name|r_concurrency
decl_stmt|;
comment|/* Concurrency level requested by user.  */
name|int
name|nrunnable_num
decl_stmt|;
comment|/* Average runnable threads, numerator.  */
name|int
name|nrunnable_den
decl_stmt|;
comment|/* Average runnable threads, denominator.  */
name|int
name|a_concurrency_num
decl_stmt|;
comment|/* Achieved concurrency level, numerator.  */
name|int
name|a_concurrency_den
decl_stmt|;
comment|/* Achieved concurrency level, denominator.  */
name|int
name|nlwps_num
decl_stmt|;
comment|/* Average number of processes in use, 				   numerator.  */
name|int
name|nlwps_den
decl_stmt|;
comment|/* Average number of processes in use, 				   denominator.  */
name|int
name|nidle_num
decl_stmt|;
comment|/* Average number of idling processes, 				   numerator.  */
name|int
name|nidle_den
decl_stmt|;
comment|/* Average number of idling processes, 				   denominator.  */
block|}
name|td_ta_stats_t
typedef|;
end_typedef

begin_comment
comment|/* Since Sun's library is based on Solaris threads we have to define a few    types to map them to POSIX threads.  */
end_comment

begin_typedef
typedef|typedef
name|pthread_t
name|thread_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pthread_key_t
name|thread_key_t
typedef|;
end_typedef

begin_comment
comment|/* Callback for iteration over threads.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|td_thr_iter_f
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Callback for iteration over thread local data.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|td_key_iter_f
parameter_list|(
name|thread_key_t
parameter_list|,
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
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Forward declaration.  This has to be defined by the user.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ps_prochandle
struct_decl|;
end_struct_decl

begin_comment
comment|/* Information about the thread.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|td_thrinfo
block|{
name|td_thragent_t
modifier|*
name|ti_ta_p
decl_stmt|;
comment|/* Process handle.  */
name|unsigned
name|int
name|ti_user_flags
decl_stmt|;
comment|/* Unused.  */
name|thread_t
name|ti_tid
decl_stmt|;
comment|/* Thread ID returned by 					   pthread_create().  */
name|char
modifier|*
name|ti_tls
decl_stmt|;
comment|/* Pointer to thread-local data.  */
name|psaddr_t
name|ti_startfunc
decl_stmt|;
comment|/* Start function passed to 					   pthread_create().  */
name|psaddr_t
name|ti_stkbase
decl_stmt|;
comment|/* Base of thread's stack.  */
name|long
name|int
name|ti_stksize
decl_stmt|;
comment|/* Size of thread's stack.  */
name|psaddr_t
name|ti_ro_area
decl_stmt|;
comment|/* Unused.  */
name|int
name|ti_ro_size
decl_stmt|;
comment|/* Unused.  */
name|td_thr_state_e
name|ti_state
decl_stmt|;
comment|/* Thread state.  */
name|unsigned
name|char
name|ti_db_suspended
decl_stmt|;
comment|/* Nonzero if suspended by debugger. */
name|td_thr_type_e
name|ti_type
decl_stmt|;
comment|/* Type of the thread (system vs 					   user thread).  */
name|intptr_t
name|ti_pc
decl_stmt|;
comment|/* Unused.  */
name|intptr_t
name|ti_sp
decl_stmt|;
comment|/* Unused.  */
name|short
name|int
name|ti_flags
decl_stmt|;
comment|/* Unused.  */
name|int
name|ti_pri
decl_stmt|;
comment|/* Thread priority.  */
name|lwpid_t
name|ti_lid
decl_stmt|;
comment|/* Unused.  */
name|sigset_t
name|ti_sigmask
decl_stmt|;
comment|/* Signal mask.  */
name|unsigned
name|char
name|ti_traceme
decl_stmt|;
comment|/* Nonzero if event reporting 					   enabled.  */
name|unsigned
name|char
name|ti_preemptflag
decl_stmt|;
comment|/* Unused.  */
name|unsigned
name|char
name|ti_pirecflag
decl_stmt|;
comment|/* Unused.  */
name|sigset_t
name|ti_pending
decl_stmt|;
comment|/* Set of pending signals.  */
name|td_thr_events_t
name|ti_events
decl_stmt|;
comment|/* Set of enabled events.  */
block|}
name|td_thrinfo_t
typedef|;
end_typedef

begin_comment
comment|/* Prototypes for exported library functions.  */
end_comment

begin_comment
comment|/* Initialize the thread debug support library.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Historical relict.  Should not be used anymore.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_log
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generate new thread debug library handle for process PS.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_ta_new
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
name|__ps
parameter_list|,
name|td_thragent_t
modifier|*
modifier|*
name|__ta
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free resources allocated for TA.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_ta_delete
parameter_list|(
name|td_thragent_t
modifier|*
name|__ta
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get number of currently running threads in process associated with TA.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_ta_get_nthreads
parameter_list|(
specifier|const
name|td_thragent_t
modifier|*
name|__ta
parameter_list|,
name|int
modifier|*
name|__np
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return process handle passed in `td_ta_new' for process associated with    TA.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_ta_get_ph
parameter_list|(
specifier|const
name|td_thragent_t
modifier|*
name|__ta
parameter_list|,
name|struct
name|ps_prochandle
modifier|*
modifier|*
name|__ph
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Map thread library handle PT to thread debug library handle for process    associated with TA and store result in *TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_ta_map_id2thr
parameter_list|(
specifier|const
name|td_thragent_t
modifier|*
name|__ta
parameter_list|,
name|pthread_t
name|__pt
parameter_list|,
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Map process ID LWPID to thread debug library handle for process    associated with TA and store result in *TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_ta_map_lwp2thr
parameter_list|(
specifier|const
name|td_thragent_t
modifier|*
name|__ta
parameter_list|,
name|lwpid_t
name|__lwpid
parameter_list|,
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Call for each thread in a process associated with TA the callback function    CALLBACK.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_ta_thr_iter
parameter_list|(
specifier|const
name|td_thragent_t
modifier|*
name|__ta
parameter_list|,
name|td_thr_iter_f
modifier|*
name|__callback
parameter_list|,
name|void
modifier|*
name|__cbdata_p
parameter_list|,
name|td_thr_state_e
name|__state
parameter_list|,
name|int
name|__ti_pri
parameter_list|,
name|sigset_t
modifier|*
name|__ti_sigmask_p
parameter_list|,
name|unsigned
name|int
name|__ti_user_flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Call for each defined thread local data entry the callback function KI.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_ta_tsd_iter
parameter_list|(
specifier|const
name|td_thragent_t
modifier|*
name|__ta
parameter_list|,
name|td_key_iter_f
modifier|*
name|__ki
parameter_list|,
name|void
modifier|*
name|__p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get event address for EVENT.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_ta_event_addr
parameter_list|(
specifier|const
name|td_thragent_t
modifier|*
name|__ta
parameter_list|,
name|td_event_e
name|__event
parameter_list|,
name|td_notify_t
modifier|*
name|__ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Enable EVENT in global mask.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_ta_set_event
parameter_list|(
specifier|const
name|td_thragent_t
modifier|*
name|__ta
parameter_list|,
name|td_thr_events_t
modifier|*
name|__event
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Disable EVENT in global mask.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_ta_clear_event
parameter_list|(
specifier|const
name|td_thragent_t
modifier|*
name|__ta
parameter_list|,
name|td_thr_events_t
modifier|*
name|__event
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return information about last event.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_ta_event_getmsg
parameter_list|(
specifier|const
name|td_thragent_t
modifier|*
name|__ta
parameter_list|,
name|td_event_msg_t
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set suggested concurrency level for process associated with TA.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_ta_setconcurrency
parameter_list|(
specifier|const
name|td_thragent_t
modifier|*
name|__ta
parameter_list|,
name|int
name|__level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Enable collecting statistics for process associated with TA.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_ta_enable_stats
parameter_list|(
specifier|const
name|td_thragent_t
modifier|*
name|__ta
parameter_list|,
name|int
name|__enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Reset statistics.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_ta_reset_stats
parameter_list|(
specifier|const
name|td_thragent_t
modifier|*
name|__ta
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Retrieve statistics from process associated with TA.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_ta_get_stats
parameter_list|(
specifier|const
name|td_thragent_t
modifier|*
name|__ta
parameter_list|,
name|td_ta_stats_t
modifier|*
name|__statsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Validate that TH is a thread handle.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_validate
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return information about thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_get_info
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|,
name|td_thrinfo_t
modifier|*
name|__infop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Retrieve floating-point register contents of process running thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_getfpregs
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|,
name|prfpregset_t
modifier|*
name|__regset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Retrieve general register contents of process running thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_getgregs
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|,
name|prgregset_t
name|__gregs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Retrieve extended register contents of process running thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_getxregs
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|,
name|void
modifier|*
name|__xregs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get size of extended register set of process running thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_getxregsize
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|,
name|int
modifier|*
name|__sizep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set floating-point register contents of process running thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_setfpregs
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|,
specifier|const
name|prfpregset_t
modifier|*
name|__fpregs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set general register contents of process running thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_setgregs
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|,
name|prgregset_t
name|__gregs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set extended register contents of process running thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_setxregs
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|,
specifier|const
name|void
modifier|*
name|__addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Enable reporting for EVENT for thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_event_enable
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|,
name|int
name|__event
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Enable EVENT for thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_set_event
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|,
name|td_thr_events_t
modifier|*
name|__event
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Disable EVENT for thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_clear_event
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|,
name|td_thr_events_t
modifier|*
name|__event
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get event message for thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_event_getmsg
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|,
name|td_event_msg_t
modifier|*
name|__msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set priority of thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_setprio
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|,
name|int
name|__prio
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set pending signals for thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_setsigpending
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|,
name|unsigned
name|char
name|__n
parameter_list|,
specifier|const
name|sigset_t
modifier|*
name|__ss
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set signal mask for thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_sigsetmask
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|,
specifier|const
name|sigset_t
modifier|*
name|__ss
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return thread local data associated with key TK in thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_tsd
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|,
specifier|const
name|thread_key_t
name|__tk
parameter_list|,
name|void
modifier|*
modifier|*
name|__data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Suspend execution of thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_dbsuspend
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Resume execution of thread TH.  */
end_comment

begin_function_decl
specifier|extern
name|td_err_e
name|td_thr_dbresume
parameter_list|(
specifier|const
name|td_thrhandle_t
modifier|*
name|__th
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* thread_db.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_THREAD_DB_H */
end_comment

end_unit

