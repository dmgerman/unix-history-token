begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2007 Niels Provos<provos@citi.umich.edu>  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVBUFFER_INTERNAL_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVBUFFER_INTERNAL_H_INCLUDED_
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
file|"evconfig-private.h"
include|#
directive|include
file|"event2/util.h"
include|#
directive|include
file|"event2/event_struct.h"
include|#
directive|include
file|"util-internal.h"
include|#
directive|include
file|"defer-internal.h"
comment|/* Experimental cb flag: "never deferred."  Implementation note:  * these callbacks may get an inaccurate view of n_del/n_added in their  * arguments. */
define|#
directive|define
name|EVBUFFER_CB_NODEFER
value|2
ifdef|#
directive|ifdef
name|_WIN32
include|#
directive|include
file|<winsock2.h>
endif|#
directive|endif
include|#
directive|include
file|<sys/queue.h>
comment|/* Minimum allocation for a chain.  We define this so that we're burning no  * more than 5% of each allocation on overhead.  It would be nice to lose even  * less space, though. */
if|#
directive|if
name|EVENT__SIZEOF_VOID_P
operator|<
literal|8
define|#
directive|define
name|MIN_BUFFER_SIZE
value|512
else|#
directive|else
define|#
directive|define
name|MIN_BUFFER_SIZE
value|1024
endif|#
directive|endif
comment|/** A single evbuffer callback for an evbuffer. This function will be invoked  * when bytes are added to or removed from the evbuffer. */
struct|struct
name|evbuffer_cb_entry
block|{
comment|/** Structures to implement a doubly-linked queue of callbacks */
name|LIST_ENTRY
argument_list|(
argument|evbuffer_cb_entry
argument_list|)
name|next
expr_stmt|;
comment|/** The callback function to invoke when this callback is called. 	    If EVBUFFER_CB_OBSOLETE is set in flags, the cb_obsolete field is 	    valid; otherwise, cb_func is valid. */
union|union
block|{
name|evbuffer_cb_func
name|cb_func
decl_stmt|;
name|evbuffer_cb
name|cb_obsolete
decl_stmt|;
block|}
name|cb
union|;
comment|/** Argument to pass to cb. */
name|void
modifier|*
name|cbarg
decl_stmt|;
comment|/** Currently set flags on this callback. */
name|ev_uint32_t
name|flags
decl_stmt|;
block|}
struct|;
struct_decl|struct
name|bufferevent
struct_decl|;
struct_decl|struct
name|evbuffer_chain
struct_decl|;
struct|struct
name|evbuffer
block|{
comment|/** The first chain in this buffer's linked list of chains. */
name|struct
name|evbuffer_chain
modifier|*
name|first
decl_stmt|;
comment|/** The last chain in this buffer's linked list of chains. */
name|struct
name|evbuffer_chain
modifier|*
name|last
decl_stmt|;
comment|/** Pointer to the next pointer pointing at the 'last_with_data' chain. 	 * 	 * To unpack: 	 * 	 * The last_with_data chain is the last chain that has any data in it. 	 * If all chains in the buffer are empty, it is the first chain. 	 * If the buffer has no chains, it is NULL. 	 * 	 * The last_with_datap pointer points at _whatever 'next' pointer_ 	 * points at the last_with_datap chain.  If the last_with_data chain 	 * is the first chain, or it is NULL, then the last_with_datap pointer 	 * is&buf->first. 	 */
name|struct
name|evbuffer_chain
modifier|*
modifier|*
name|last_with_datap
decl_stmt|;
comment|/** Total amount of bytes stored in all chains.*/
name|size_t
name|total_len
decl_stmt|;
comment|/** Number of bytes we have added to the buffer since we last tried to 	 * invoke callbacks. */
name|size_t
name|n_add_for_cb
decl_stmt|;
comment|/** Number of bytes we have removed from the buffer since we last 	 * tried to invoke callbacks. */
name|size_t
name|n_del_for_cb
decl_stmt|;
ifndef|#
directive|ifndef
name|EVENT__DISABLE_THREAD_SUPPORT
comment|/** A lock used to mediate access to this buffer. */
name|void
modifier|*
name|lock
decl_stmt|;
endif|#
directive|endif
comment|/** True iff we should free the lock field when we free this 	 * evbuffer. */
name|unsigned
name|own_lock
range|:
literal|1
decl_stmt|;
comment|/** True iff we should not allow changes to the front of the buffer 	 * (drains or prepends). */
name|unsigned
name|freeze_start
range|:
literal|1
decl_stmt|;
comment|/** True iff we should not allow changes to the end of the buffer 	 * (appends) */
name|unsigned
name|freeze_end
range|:
literal|1
decl_stmt|;
comment|/** True iff this evbuffer's callbacks are not invoked immediately 	 * upon a change in the buffer, but instead are deferred to be invoked 	 * from the event_base's loop.	Useful for preventing enormous stack 	 * overflows when we have mutually recursive callbacks, and for 	 * serializing callbacks in a single thread. */
name|unsigned
name|deferred_cbs
range|:
literal|1
decl_stmt|;
ifdef|#
directive|ifdef
name|_WIN32
comment|/** True iff this buffer is set up for overlapped IO. */
name|unsigned
name|is_overlapped
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
comment|/** Zero or more EVBUFFER_FLAG_* bits */
name|ev_uint32_t
name|flags
decl_stmt|;
comment|/** Used to implement deferred callbacks. */
name|struct
name|event_base
modifier|*
name|cb_queue
decl_stmt|;
comment|/** A reference count on this evbuffer.	 When the reference count 	 * reaches 0, the buffer is destroyed.	Manipulated with 	 * evbuffer_incref and evbuffer_decref_and_unlock and 	 * evbuffer_free. */
name|int
name|refcnt
decl_stmt|;
comment|/** A struct event_callback handle to make all of this buffer's callbacks 	 * invoked from the event loop. */
name|struct
name|event_callback
name|deferred
decl_stmt|;
comment|/** A doubly-linked-list of callback functions */
name|LIST_HEAD
argument_list|(
argument|evbuffer_cb_queue
argument_list|,
argument|evbuffer_cb_entry
argument_list|)
name|callbacks
expr_stmt|;
comment|/** The parent bufferevent object this evbuffer belongs to. 	 * NULL if the evbuffer stands alone. */
name|struct
name|bufferevent
modifier|*
name|parent
decl_stmt|;
block|}
struct|;
comment|/** A single item in an evbuffer. */
struct|struct
name|evbuffer_chain
block|{
comment|/** points to next buffer in the chain */
name|struct
name|evbuffer_chain
modifier|*
name|next
decl_stmt|;
comment|/** total allocation available in the buffer field. */
name|size_t
name|buffer_len
decl_stmt|;
comment|/** unused space at the beginning of buffer or an offset into a 	 * file for sendfile buffers. */
name|ev_off_t
name|misalign
decl_stmt|;
comment|/** Offset into buffer + misalign at which to start writing. 	 * In other words, the total number of bytes actually stored 	 * in buffer. */
name|size_t
name|off
decl_stmt|;
comment|/** Set if special handling is required for this chain */
name|unsigned
name|flags
decl_stmt|;
define|#
directive|define
name|EVBUFFER_FILESEGMENT
value|0x0001
comment|/**< A chain used for a file segment */
define|#
directive|define
name|EVBUFFER_SENDFILE
value|0x0002
comment|/**< a chain used with sendfile */
define|#
directive|define
name|EVBUFFER_REFERENCE
value|0x0004
comment|/**< a chain with a mem reference */
define|#
directive|define
name|EVBUFFER_IMMUTABLE
value|0x0008
comment|/**< read-only chain */
comment|/** a chain that mustn't be reallocated or freed, or have its contents 	 * memmoved, until the chain is un-pinned. */
define|#
directive|define
name|EVBUFFER_MEM_PINNED_R
value|0x0010
define|#
directive|define
name|EVBUFFER_MEM_PINNED_W
value|0x0020
define|#
directive|define
name|EVBUFFER_MEM_PINNED_ANY
value|(EVBUFFER_MEM_PINNED_R|EVBUFFER_MEM_PINNED_W)
comment|/** a chain that should be freed, but can't be freed until it is 	 * un-pinned. */
define|#
directive|define
name|EVBUFFER_DANGLING
value|0x0040
comment|/** a chain that is a referenced copy of another chain */
define|#
directive|define
name|EVBUFFER_MULTICAST
value|0x0080
comment|/** number of references to this chain */
name|int
name|refcnt
decl_stmt|;
comment|/** Usually points to the read-write memory belonging to this 	 * buffer allocated as part of the evbuffer_chain allocation. 	 * For mmap, this can be a read-only buffer and 	 * EVBUFFER_IMMUTABLE will be set in flags.  For sendfile, it 	 * may point to NULL. 	 */
name|unsigned
name|char
modifier|*
name|buffer
decl_stmt|;
block|}
struct|;
comment|/** callback for a reference chain; lets us know what to do with it when  * we're done with it. Lives at the end of an evbuffer_chain with the  * EVBUFFER_REFERENCE flag set */
struct|struct
name|evbuffer_chain_reference
block|{
name|evbuffer_ref_cleanup_cb
name|cleanupfn
decl_stmt|;
name|void
modifier|*
name|extra
decl_stmt|;
block|}
struct|;
comment|/** File segment for a file-segment chain.  Lives at the end of an  * evbuffer_chain with the EVBUFFER_FILESEGMENT flag set.  */
struct|struct
name|evbuffer_chain_file_segment
block|{
name|struct
name|evbuffer_file_segment
modifier|*
name|segment
decl_stmt|;
ifdef|#
directive|ifdef
name|_WIN32
comment|/** If we're using CreateFileMapping, this is the handle to the view. */
name|HANDLE
name|view_handle
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
comment|/* Declared in event2/buffer.h; defined here. */
struct|struct
name|evbuffer_file_segment
block|{
name|void
modifier|*
name|lock
decl_stmt|;
comment|/**< lock prevent concurrent access to refcnt */
name|int
name|refcnt
decl_stmt|;
comment|/**< Reference count for this file segment */
name|unsigned
name|flags
decl_stmt|;
comment|/**< combination of EVBUF_FS_* flags  */
comment|/** What kind of file segment is this? */
name|unsigned
name|can_sendfile
range|:
literal|1
decl_stmt|;
name|unsigned
name|is_mapping
range|:
literal|1
decl_stmt|;
comment|/** The fd that we read the data from. */
name|int
name|fd
decl_stmt|;
comment|/** If we're using mmap, this is the raw mapped memory. */
name|void
modifier|*
name|mapping
decl_stmt|;
ifdef|#
directive|ifdef
name|_WIN32
comment|/** If we're using CreateFileMapping, this is the mapping */
name|HANDLE
name|mapping_handle
decl_stmt|;
endif|#
directive|endif
comment|/** If we're using mmap or IO, this is the content of the file 	 * segment. */
name|char
modifier|*
name|contents
decl_stmt|;
comment|/** Position of this segment within the file. */
name|ev_off_t
name|file_offset
decl_stmt|;
comment|/** If we're using mmap, this is the offset within 'mapping' where 	 * this data segment begins. */
name|ev_off_t
name|mmap_offset
decl_stmt|;
comment|/** The length of this segment. */
name|ev_off_t
name|length
decl_stmt|;
comment|/** Cleanup callback function */
name|evbuffer_file_segment_cleanup_cb
name|cleanup_cb
decl_stmt|;
comment|/** Argument to be pass to cleanup callback function */
name|void
modifier|*
name|cleanup_cb_arg
decl_stmt|;
block|}
struct|;
comment|/** Information about the multicast parent of a chain.  Lives at the  * end of an evbuffer_chain with the EVBUFFER_MULTICAST flag set.  */
struct|struct
name|evbuffer_multicast_parent
block|{
comment|/** source buffer the multicast parent belongs to */
name|struct
name|evbuffer
modifier|*
name|source
decl_stmt|;
comment|/** multicast parent for this chain */
name|struct
name|evbuffer_chain
modifier|*
name|parent
decl_stmt|;
block|}
struct|;
define|#
directive|define
name|EVBUFFER_CHAIN_SIZE
value|sizeof(struct evbuffer_chain)
comment|/** Return a pointer to extra data allocated along with an evbuffer. */
define|#
directive|define
name|EVBUFFER_CHAIN_EXTRA
parameter_list|(
name|t
parameter_list|,
name|c
parameter_list|)
value|(t *)((struct evbuffer_chain *)(c) + 1)
comment|/** Assert that we are holding the lock on an evbuffer */
define|#
directive|define
name|ASSERT_EVBUFFER_LOCKED
parameter_list|(
name|buffer
parameter_list|)
define|\
value|EVLOCK_ASSERT_LOCKED((buffer)->lock)
define|#
directive|define
name|EVBUFFER_LOCK
parameter_list|(
name|buffer
parameter_list|)
define|\
value|do {								\ 		EVLOCK_LOCK((buffer)->lock, 0);				\ 	} while (0)
define|#
directive|define
name|EVBUFFER_UNLOCK
parameter_list|(
name|buffer
parameter_list|)
define|\
value|do {								\ 		EVLOCK_UNLOCK((buffer)->lock, 0);			\ 	} while (0)
define|#
directive|define
name|EVBUFFER_LOCK2
parameter_list|(
name|buffer1
parameter_list|,
name|buffer2
parameter_list|)
define|\
value|do {								\ 		EVLOCK_LOCK2((buffer1)->lock, (buffer2)->lock, 0, 0);	\ 	} while (0)
define|#
directive|define
name|EVBUFFER_UNLOCK2
parameter_list|(
name|buffer1
parameter_list|,
name|buffer2
parameter_list|)
define|\
value|do {								\ 		EVLOCK_UNLOCK2((buffer1)->lock, (buffer2)->lock, 0, 0);	\ 	} while (0)
comment|/** Increase the reference count of buf by one. */
name|void
name|evbuffer_incref_
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/** Increase the reference count of buf by one and acquire the lock. */
name|void
name|evbuffer_incref_and_lock_
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/** Pin a single buffer chain using a given flag. A pinned chunk may not be  * moved or freed until it is unpinned. */
name|void
name|evbuffer_chain_pin_
parameter_list|(
name|struct
name|evbuffer_chain
modifier|*
name|chain
parameter_list|,
name|unsigned
name|flag
parameter_list|)
function_decl|;
comment|/** Unpin a single buffer chain using a given flag. */
name|void
name|evbuffer_chain_unpin_
parameter_list|(
name|struct
name|evbuffer_chain
modifier|*
name|chain
parameter_list|,
name|unsigned
name|flag
parameter_list|)
function_decl|;
comment|/** As evbuffer_free, but requires that we hold a lock on the buffer, and  * releases the lock before freeing it and the buffer. */
name|void
name|evbuffer_decref_and_unlock_
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|)
function_decl|;
comment|/** As evbuffer_expand, but does not guarantee that the newly allocated memory  * is contiguous.  Instead, it may be split across two or more chunks. */
name|int
name|evbuffer_expand_fast_
parameter_list|(
name|struct
name|evbuffer
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/** Helper: prepares for a readv/WSARecv call by expanding the buffer to  * hold enough memory to read 'howmuch' bytes in possibly noncontiguous memory.  * Sets up the one or two iovecs in 'vecs' to point to the free memory and its  * extent, and *chainp to point to the first chain that we'll try to read into.  * Returns the number of vecs used.  */
name|int
name|evbuffer_read_setup_vecs_
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
name|ev_ssize_t
name|howmuch
parameter_list|,
name|struct
name|evbuffer_iovec
modifier|*
name|vecs
parameter_list|,
name|int
name|n_vecs
parameter_list|,
name|struct
name|evbuffer_chain
modifier|*
modifier|*
modifier|*
name|chainp
parameter_list|,
name|int
name|exact
parameter_list|)
function_decl|;
comment|/* Helper macro: copies an evbuffer_iovec in ei to a win32 WSABUF in i. */
define|#
directive|define
name|WSABUF_FROM_EVBUFFER_IOV
parameter_list|(
name|i
parameter_list|,
name|ei
parameter_list|)
value|do {		\ 		(i)->buf = (ei)->iov_base;		\ 		(i)->len = (unsigned long)(ei)->iov_len;	\ 	} while (0)
comment|/* XXXX the cast above is safe for now, but not if we allow mmaps on win64.  * See note in buffer_iocp's launch_write function */
comment|/** Set the parent bufferevent object for buf to bev */
name|void
name|evbuffer_set_parent_
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
name|struct
name|bufferevent
modifier|*
name|bev
parameter_list|)
function_decl|;
name|void
name|evbuffer_invoke_callbacks_
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|)
function_decl|;
name|int
name|evbuffer_get_callbacks_
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
name|struct
name|event_callback
modifier|*
modifier|*
name|cbs
parameter_list|,
name|int
name|max_cbs
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
comment|/* EVBUFFER_INTERNAL_H_INCLUDED_ */
end_comment

end_unit

