begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUFFEREVENT_INTERNAL_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|BUFFEREVENT_INTERNAL_H_INCLUDED_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|"event2/event-config.h"
include|#
directive|include
file|"event2/event_struct.h"
include|#
directive|include
file|"evconfig-private.h"
include|#
directive|include
file|"event2/util.h"
include|#
directive|include
file|"defer-internal.h"
include|#
directive|include
file|"evthread-internal.h"
include|#
directive|include
file|"event2/thread.h"
include|#
directive|include
file|"ratelim-internal.h"
include|#
directive|include
file|"event2/bufferevent_struct.h"
comment|/* These flags are reasons that we might be declining to actually enable    reading or writing on a bufferevent.  */
comment|/* On a all bufferevents, for reading: used when we have read up to the    watermark value.     On a filtering bufferevent, for writing: used when the underlying    bufferevent's write buffer has been filled up to its watermark    value. */
define|#
directive|define
name|BEV_SUSPEND_WM
value|0x01
comment|/* On a base bufferevent: when we have emptied a bandwidth buckets */
define|#
directive|define
name|BEV_SUSPEND_BW
value|0x02
comment|/* On a base bufferevent: when we have emptied the group's bandwidth bucket. */
define|#
directive|define
name|BEV_SUSPEND_BW_GROUP
value|0x04
comment|/* On a socket bufferevent: can't do any operations while we're waiting for  * name lookup to finish. */
define|#
directive|define
name|BEV_SUSPEND_LOOKUP
value|0x08
comment|/* On a base bufferevent, for reading: used when a filter has choked this  * (underlying) bufferevent because it has stopped reading from it. */
define|#
directive|define
name|BEV_SUSPEND_FILT_READ
value|0x10
typedef|typedef
name|ev_uint16_t
name|bufferevent_suspend_flags
typedef|;
struct|struct
name|bufferevent_rate_limit_group
block|{
comment|/** List of all members in the group */
name|LIST_HEAD
argument_list|(
argument|rlim_group_member_list
argument_list|,
argument|bufferevent_private
argument_list|)
name|members
expr_stmt|;
comment|/** Current limits for the group. */
name|struct
name|ev_token_bucket
name|rate_limit
decl_stmt|;
name|struct
name|ev_token_bucket_cfg
name|rate_limit_cfg
decl_stmt|;
comment|/** True iff we don't want to read from any member of the group.until 	 * the token bucket refills.  */
name|unsigned
name|read_suspended
range|:
literal|1
decl_stmt|;
comment|/** True iff we don't want to write from any member of the group.until 	 * the token bucket refills.  */
name|unsigned
name|write_suspended
range|:
literal|1
decl_stmt|;
comment|/** True iff we were unable to suspend one of the bufferevents in the 	 * group for reading the last time we tried, and we should try 	 * again. */
name|unsigned
name|pending_unsuspend_read
range|:
literal|1
decl_stmt|;
comment|/** True iff we were unable to suspend one of the bufferevents in the 	 * group for writing the last time we tried, and we should try 	 * again. */
name|unsigned
name|pending_unsuspend_write
range|:
literal|1
decl_stmt|;
comment|/*@{*/
comment|/** Total number of bytes read or written in this group since last 	 * reset. */
name|ev_uint64_t
name|total_read
decl_stmt|;
name|ev_uint64_t
name|total_written
decl_stmt|;
comment|/*@}*/
comment|/** The number of bufferevents in the group. */
name|int
name|n_members
decl_stmt|;
comment|/** The smallest number of bytes that any member of the group should 	 * be limited to read or write at a time. */
name|ev_ssize_t
name|min_share
decl_stmt|;
name|ev_ssize_t
name|configured_min_share
decl_stmt|;
comment|/** Timeout event that goes off once a tick, when the bucket is ready 	 * to refill. */
name|struct
name|event
name|master_refill_event
decl_stmt|;
comment|/** Seed for weak random number generator. Protected by 'lock' */
name|struct
name|evutil_weakrand_state
name|weakrand_seed
decl_stmt|;
comment|/** Lock to protect the members of this group.  This lock should nest 	 * within every bufferevent lock: if you are holding this lock, do 	 * not assume you can lock another bufferevent. */
name|void
modifier|*
name|lock
decl_stmt|;
block|}
struct|;
comment|/** Fields for rate-limiting a single bufferevent. */
struct|struct
name|bufferevent_rate_limit
block|{
comment|/* Linked-list elements for storing this bufferevent_private in a 	 * group. 	 * 	 * Note that this field is supposed to be protected by the group 	 * lock */
name|LIST_ENTRY
argument_list|(
argument|bufferevent_private
argument_list|)
name|next_in_group
expr_stmt|;
comment|/** The rate-limiting group for this bufferevent, or NULL if it is 	 * only rate-limited on its own. */
name|struct
name|bufferevent_rate_limit_group
modifier|*
name|group
decl_stmt|;
comment|/* This bufferevent's current limits. */
name|struct
name|ev_token_bucket
name|limit
decl_stmt|;
comment|/* Pointer to the rate-limit configuration for this bufferevent. 	 * Can be shared.  XXX reference-count this? */
name|struct
name|ev_token_bucket_cfg
modifier|*
name|cfg
decl_stmt|;
comment|/* Timeout event used when one this bufferevent's buckets are 	 * empty. */
name|struct
name|event
name|refill_bucket_event
decl_stmt|;
block|}
struct|;
comment|/** Parts of the bufferevent structure that are shared among all bufferevent  * types, but not exposed in bufferevent_struct.h. */
struct|struct
name|bufferevent_private
block|{
comment|/** The underlying bufferevent structure. */
name|struct
name|bufferevent
name|bev
decl_stmt|;
comment|/** Evbuffer callback to enforce watermarks on input. */
name|struct
name|evbuffer_cb_entry
modifier|*
name|read_watermarks_cb
decl_stmt|;
comment|/** If set, we should free the lock when we free the bufferevent. */
name|unsigned
name|own_lock
range|:
literal|1
decl_stmt|;
comment|/** Flag: set if we have deferred callbacks and a read callback is 	 * pending. */
name|unsigned
name|readcb_pending
range|:
literal|1
decl_stmt|;
comment|/** Flag: set if we have deferred callbacks and a write callback is 	 * pending. */
name|unsigned
name|writecb_pending
range|:
literal|1
decl_stmt|;
comment|/** Flag: set if we are currently busy connecting. */
name|unsigned
name|connecting
range|:
literal|1
decl_stmt|;
comment|/** Flag: set if a connect failed prematurely; this is a hack for 	 * getting around the bufferevent abstraction. */
name|unsigned
name|connection_refused
range|:
literal|1
decl_stmt|;
comment|/** Set to the events pending if we have deferred callbacks and 	 * an events callback is pending. */
name|short
name|eventcb_pending
decl_stmt|;
comment|/** If set, read is suspended until one or more conditions are over. 	 * The actual value here is a bitfield of those conditions; see the 	 * BEV_SUSPEND_* flags above. */
name|bufferevent_suspend_flags
name|read_suspended
decl_stmt|;
comment|/** If set, writing is suspended until one or more conditions are over. 	 * The actual value here is a bitfield of those conditions; see the 	 * BEV_SUSPEND_* flags above. */
name|bufferevent_suspend_flags
name|write_suspended
decl_stmt|;
comment|/** Set to the current socket errno if we have deferred callbacks and 	 * an events callback is pending. */
name|int
name|errno_pending
decl_stmt|;
comment|/** The DNS error code for bufferevent_socket_connect_hostname */
name|int
name|dns_error
decl_stmt|;
comment|/** Used to implement deferred callbacks */
name|struct
name|event_callback
name|deferred
decl_stmt|;
comment|/** The options this bufferevent was constructed with */
name|enum
name|bufferevent_options
name|options
decl_stmt|;
comment|/** Current reference count for this bufferevent. */
name|int
name|refcnt
decl_stmt|;
comment|/** Lock for this bufferevent.  Shared by the inbuf and the outbuf. 	 * If NULL, locking is disabled. */
name|void
modifier|*
name|lock
decl_stmt|;
comment|/** No matter how big our bucket gets, don't try to read more than this 	 * much in a single read operation. */
name|ev_ssize_t
name|max_single_read
decl_stmt|;
comment|/** No matter how big our bucket gets, don't try to write more than this 	 * much in a single write operation. */
name|ev_ssize_t
name|max_single_write
decl_stmt|;
comment|/** Rate-limiting information for this bufferevent */
name|struct
name|bufferevent_rate_limit
modifier|*
name|rate_limiting
decl_stmt|;
block|}
struct|;
comment|/** Possible operations for a control callback. */
enum|enum
name|bufferevent_ctrl_op
block|{
name|BEV_CTRL_SET_FD
block|,
name|BEV_CTRL_GET_FD
block|,
name|BEV_CTRL_GET_UNDERLYING
block|,
name|BEV_CTRL_CANCEL_ALL
block|}
enum|;
comment|/** Possible data types for a control callback */
union|union
name|bufferevent_ctrl_data
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
name|evutil_socket_t
name|fd
decl_stmt|;
block|}
union|;
comment|/**    Implementation table for a bufferevent: holds function pointers and other    information to make the various bufferevent types work. */
struct|struct
name|bufferevent_ops
block|{
comment|/** The name of the bufferevent's type. */
specifier|const
name|char
modifier|*
name|type
decl_stmt|;
comment|/** At what offset into the implementation type will we find a 	    bufferevent structure?  	    Example: if the type is implemented as 	    struct bufferevent_x { 	       int extra_data; 	       struct bufferevent bev; 	    } 	    then mem_offset should be offsetof(struct bufferevent_x, bev) 	*/
name|off_t
name|mem_offset
decl_stmt|;
comment|/** Enables one or more of EV_READ|EV_WRITE on a bufferevent.  Does 	    not need to adjust the 'enabled' field.  Returns 0 on success, -1 	    on failure. 	 */
name|int
function_decl|(
modifier|*
name|enable
function_decl|)
parameter_list|(
name|struct
name|bufferevent
modifier|*
parameter_list|,
name|short
parameter_list|)
function_decl|;
comment|/** Disables one or more of EV_READ|EV_WRITE on a bufferevent.  Does 	    not need to adjust the 'enabled' field.  Returns 0 on success, -1 	    on failure. 	 */
name|int
function_decl|(
modifier|*
name|disable
function_decl|)
parameter_list|(
name|struct
name|bufferevent
modifier|*
parameter_list|,
name|short
parameter_list|)
function_decl|;
comment|/** Detatches the bufferevent from related data structures. Called as 	 * soon as its reference count reaches 0. */
name|void
function_decl|(
modifier|*
name|unlink
function_decl|)
parameter_list|(
name|struct
name|bufferevent
modifier|*
parameter_list|)
function_decl|;
comment|/** Free any storage and deallocate any extra data or structures used 	    in this implementation. Called when the bufferevent is 	    finalized. 	 */
name|void
function_decl|(
modifier|*
name|destruct
function_decl|)
parameter_list|(
name|struct
name|bufferevent
modifier|*
parameter_list|)
function_decl|;
comment|/** Called when the timeouts on the bufferevent have changed.*/
name|int
function_decl|(
modifier|*
name|adj_timeouts
function_decl|)
parameter_list|(
name|struct
name|bufferevent
modifier|*
parameter_list|)
function_decl|;
comment|/** Called to flush data. */
name|int
function_decl|(
modifier|*
name|flush
function_decl|)
parameter_list|(
name|struct
name|bufferevent
modifier|*
parameter_list|,
name|short
parameter_list|,
name|enum
name|bufferevent_flush_mode
parameter_list|)
function_decl|;
comment|/** Called to access miscellaneous fields. */
name|int
function_decl|(
modifier|*
name|ctrl
function_decl|)
parameter_list|(
name|struct
name|bufferevent
modifier|*
parameter_list|,
name|enum
name|bufferevent_ctrl_op
parameter_list|,
name|union
name|bufferevent_ctrl_data
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
specifier|extern
specifier|const
name|struct
name|bufferevent_ops
name|bufferevent_ops_socket
decl_stmt|;
specifier|extern
specifier|const
name|struct
name|bufferevent_ops
name|bufferevent_ops_filter
decl_stmt|;
specifier|extern
specifier|const
name|struct
name|bufferevent_ops
name|bufferevent_ops_pair
decl_stmt|;
define|#
directive|define
name|BEV_IS_SOCKET
parameter_list|(
name|bevp
parameter_list|)
value|((bevp)->be_ops ==&bufferevent_ops_socket)
define|#
directive|define
name|BEV_IS_FILTER
parameter_list|(
name|bevp
parameter_list|)
value|((bevp)->be_ops ==&bufferevent_ops_filter)
define|#
directive|define
name|BEV_IS_PAIR
parameter_list|(
name|bevp
parameter_list|)
value|((bevp)->be_ops ==&bufferevent_ops_pair)
ifdef|#
directive|ifdef
name|_WIN32
specifier|extern
specifier|const
name|struct
name|bufferevent_ops
name|bufferevent_ops_async
decl_stmt|;
define|#
directive|define
name|BEV_IS_ASYNC
parameter_list|(
name|bevp
parameter_list|)
value|((bevp)->be_ops ==&bufferevent_ops_async)
else|#
directive|else
define|#
directive|define
name|BEV_IS_ASYNC
parameter_list|(
name|bevp
parameter_list|)
value|0
endif|#
directive|endif
comment|/** Initialize the shared parts of a bufferevent. */
name|int
name|bufferevent_init_common_
parameter_list|(
name|struct
name|bufferevent_private
modifier|*
parameter_list|,
name|struct
name|event_base
modifier|*
parameter_list|,
specifier|const
name|struct
name|bufferevent_ops
modifier|*
parameter_list|,
name|enum
name|bufferevent_options
name|options
parameter_list|)
function_decl|;
comment|/** For internal use: temporarily stop all reads on bufev, until the conditions  * in 'what' are over. */
name|void
name|bufferevent_suspend_read_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bufev
parameter_list|,
name|bufferevent_suspend_flags
name|what
parameter_list|)
function_decl|;
comment|/** For internal use: clear the conditions 'what' on bufev, and re-enable  * reading if there are no conditions left. */
name|void
name|bufferevent_unsuspend_read_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bufev
parameter_list|,
name|bufferevent_suspend_flags
name|what
parameter_list|)
function_decl|;
comment|/** For internal use: temporarily stop all writes on bufev, until the conditions  * in 'what' are over. */
name|void
name|bufferevent_suspend_write_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bufev
parameter_list|,
name|bufferevent_suspend_flags
name|what
parameter_list|)
function_decl|;
comment|/** For internal use: clear the conditions 'what' on bufev, and re-enable  * writing if there are no conditions left. */
name|void
name|bufferevent_unsuspend_write_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bufev
parameter_list|,
name|bufferevent_suspend_flags
name|what
parameter_list|)
function_decl|;
define|#
directive|define
name|bufferevent_wm_suspend_read
parameter_list|(
name|b
parameter_list|)
define|\
value|bufferevent_suspend_read_((b), BEV_SUSPEND_WM)
define|#
directive|define
name|bufferevent_wm_unsuspend_read
parameter_list|(
name|b
parameter_list|)
define|\
value|bufferevent_unsuspend_read_((b), BEV_SUSPEND_WM)
comment|/*   Disable a bufferevent.  Equivalent to bufferevent_disable(), but   first resets 'connecting' flag to force EV_WRITE down for sure.    XXXX this method will go away in the future; try not to add new users.     See comment in evhttp_connection_reset_() for discussion.    @param bufev the bufferevent to be disabled   @param event any combination of EV_READ | EV_WRITE.   @return 0 if successful, or -1 if an error occurred   @see bufferevent_disable()  */
name|int
name|bufferevent_disable_hard_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bufev
parameter_list|,
name|short
name|event
parameter_list|)
function_decl|;
comment|/** Internal: Set up locking on a bufferevent.  If lock is set, use it.  * Otherwise, use a new lock. */
name|int
name|bufferevent_enable_locking_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bufev
parameter_list|,
name|void
modifier|*
name|lock
parameter_list|)
function_decl|;
comment|/** Internal: Increment the reference count on bufev. */
name|void
name|bufferevent_incref_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bufev
parameter_list|)
function_decl|;
comment|/** Internal: Lock bufev and increase its reference count.  * unlocking it otherwise. */
name|void
name|bufferevent_incref_and_lock_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bufev
parameter_list|)
function_decl|;
comment|/** Internal: Decrement the reference count on bufev.  Returns 1 if it freed  * the bufferevent.*/
name|int
name|bufferevent_decref_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bufev
parameter_list|)
function_decl|;
comment|/** Internal: Drop the reference count on bufev, freeing as necessary, and  * unlocking it otherwise.  Returns 1 if it freed the bufferevent. */
name|int
name|bufferevent_decref_and_unlock_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bufev
parameter_list|)
function_decl|;
comment|/** Internal: If callbacks are deferred and we have a read callback, schedule  * a readcb.  Otherwise just run the readcb. Ignores watermarks. */
name|void
name|bufferevent_run_readcb_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bufev
parameter_list|,
name|int
name|options
parameter_list|)
function_decl|;
comment|/** Internal: If callbacks are deferred and we have a write callback, schedule  * a writecb.  Otherwise just run the writecb. Ignores watermarks. */
name|void
name|bufferevent_run_writecb_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bufev
parameter_list|,
name|int
name|options
parameter_list|)
function_decl|;
comment|/** Internal: If callbacks are deferred and we have an eventcb, schedule  * it to run with events "what".  Otherwise just run the eventcb.  * See bufferevent_trigger_event for meaning of "options". */
name|void
name|bufferevent_run_eventcb_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bufev
parameter_list|,
name|short
name|what
parameter_list|,
name|int
name|options
parameter_list|)
function_decl|;
comment|/** Internal: Run or schedule (if deferred or options contain  * BEV_TRIG_DEFER_CALLBACKS) I/O callbacks specified in iotype.  * Must already hold the bufev lock. Honors watermarks unless  * BEV_TRIG_IGNORE_WATERMARKS is in options. */
specifier|static
specifier|inline
name|void
name|bufferevent_trigger_nolock_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bufev
parameter_list|,
name|short
name|iotype
parameter_list|,
name|int
name|options
parameter_list|)
function_decl|;
comment|/* Making this inline since all of the common-case calls to this function in  * libevent use constant arguments. */
specifier|static
specifier|inline
name|void
name|bufferevent_trigger_nolock_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bufev
parameter_list|,
name|short
name|iotype
parameter_list|,
name|int
name|options
parameter_list|)
block|{
if|if
condition|(
operator|(
name|iotype
operator|&
name|EV_READ
operator|)
operator|&&
operator|(
operator|(
name|options
operator|&
name|BEV_TRIG_IGNORE_WATERMARKS
operator|)
operator|||
name|evbuffer_get_length
argument_list|(
name|bufev
operator|->
name|input
argument_list|)
operator|>=
name|bufev
operator|->
name|wm_read
operator|.
name|low
operator|)
condition|)
name|bufferevent_run_readcb_
argument_list|(
name|bufev
argument_list|,
name|options
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|iotype
operator|&
name|EV_WRITE
operator|)
operator|&&
operator|(
operator|(
name|options
operator|&
name|BEV_TRIG_IGNORE_WATERMARKS
operator|)
operator|||
name|evbuffer_get_length
argument_list|(
name|bufev
operator|->
name|output
argument_list|)
operator|<=
name|bufev
operator|->
name|wm_write
operator|.
name|low
operator|)
condition|)
name|bufferevent_run_writecb_
argument_list|(
name|bufev
argument_list|,
name|options
argument_list|)
expr_stmt|;
block|}
comment|/** Internal: Add the event 'ev' with timeout tv, unless tv is set to 0, in  * which case add ev with no timeout. */
name|int
name|bufferevent_add_event_
parameter_list|(
name|struct
name|event
modifier|*
name|ev
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
name|tv
parameter_list|)
function_decl|;
comment|/* =========  * These next functions implement timeouts for bufferevents that aren't doing  * anything else with ev_read and ev_write, to handle timeouts.  * ========= */
comment|/** Internal use: Set up the ev_read and ev_write callbacks so that  * the other "generic_timeout" functions will work on it.  Call this from  * the constructor function. */
name|void
name|bufferevent_init_generic_timeout_cbs_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bev
parameter_list|)
function_decl|;
comment|/** Internal use: Add or delete the generic timeout events as appropriate.  * (If an event is enabled and a timeout is set, we add the event.  Otherwise  * we delete it.)  Call this from anything that changes the timeout values,  * that enabled EV_READ or EV_WRITE, or that disables EV_READ or EV_WRITE. */
name|int
name|bufferevent_generic_adj_timeouts_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bev
parameter_list|)
function_decl|;
name|enum
name|bufferevent_options
name|bufferevent_get_options_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bev
parameter_list|)
function_decl|;
comment|/** Internal use: We have just successfully read data into an inbuf, so  * reset the read timeout (if any). */
define|#
directive|define
name|BEV_RESET_GENERIC_READ_TIMEOUT
parameter_list|(
name|bev
parameter_list|)
define|\
value|do {								\ 		if (evutil_timerisset(&(bev)->timeout_read))		\ 			event_add(&(bev)->ev_read,&(bev)->timeout_read); \ 	} while (0)
comment|/** Internal use: We have just successfully written data from an inbuf, so  * reset the read timeout (if any). */
define|#
directive|define
name|BEV_RESET_GENERIC_WRITE_TIMEOUT
parameter_list|(
name|bev
parameter_list|)
define|\
value|do {								\ 		if (evutil_timerisset(&(bev)->timeout_write))		\ 			event_add(&(bev)->ev_write,&(bev)->timeout_write); \ 	} while (0)
define|#
directive|define
name|BEV_DEL_GENERIC_READ_TIMEOUT
parameter_list|(
name|bev
parameter_list|)
define|\
value|event_del(&(bev)->ev_read)
define|#
directive|define
name|BEV_DEL_GENERIC_WRITE_TIMEOUT
parameter_list|(
name|bev
parameter_list|)
define|\
value|event_del(&(bev)->ev_write)
comment|/** Internal: Given a bufferevent, return its corresponding  * bufferevent_private. */
define|#
directive|define
name|BEV_UPCAST
parameter_list|(
name|b
parameter_list|)
value|EVUTIL_UPCAST((b), struct bufferevent_private, bev)
ifdef|#
directive|ifdef
name|EVENT__DISABLE_THREAD_SUPPORT
define|#
directive|define
name|BEV_LOCK
parameter_list|(
name|b
parameter_list|)
value|EVUTIL_NIL_STMT_
define|#
directive|define
name|BEV_UNLOCK
parameter_list|(
name|b
parameter_list|)
value|EVUTIL_NIL_STMT_
else|#
directive|else
comment|/** Internal: Grab the lock (if any) on a bufferevent */
define|#
directive|define
name|BEV_LOCK
parameter_list|(
name|b
parameter_list|)
value|do {						\ 		struct bufferevent_private *locking =  BEV_UPCAST(b);	\ 		EVLOCK_LOCK(locking->lock, 0);				\ 	} while (0)
comment|/** Internal: Release the lock (if any) on a bufferevent */
define|#
directive|define
name|BEV_UNLOCK
parameter_list|(
name|b
parameter_list|)
value|do {						\ 		struct bufferevent_private *locking =  BEV_UPCAST(b);	\ 		EVLOCK_UNLOCK(locking->lock, 0);			\ 	} while (0)
endif|#
directive|endif
comment|/* ==== For rate-limiting. */
name|int
name|bufferevent_decrement_write_buckets_
parameter_list|(
name|struct
name|bufferevent_private
modifier|*
name|bev
parameter_list|,
name|ev_ssize_t
name|bytes
parameter_list|)
function_decl|;
name|int
name|bufferevent_decrement_read_buckets_
parameter_list|(
name|struct
name|bufferevent_private
modifier|*
name|bev
parameter_list|,
name|ev_ssize_t
name|bytes
parameter_list|)
function_decl|;
name|ev_ssize_t
name|bufferevent_get_read_max_
parameter_list|(
name|struct
name|bufferevent_private
modifier|*
name|bev
parameter_list|)
function_decl|;
name|ev_ssize_t
name|bufferevent_get_write_max_
parameter_list|(
name|struct
name|bufferevent_private
modifier|*
name|bev
parameter_list|)
function_decl|;
name|int
name|bufferevent_ratelim_init_
parameter_list|(
name|struct
name|bufferevent_private
modifier|*
name|bev
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BUFFEREVENT_INTERNAL_H_INCLUDED_ */
end_comment

end_unit

