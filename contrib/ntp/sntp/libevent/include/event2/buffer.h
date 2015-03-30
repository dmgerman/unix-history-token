begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENT2_BUFFER_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVENT2_BUFFER_H_INCLUDED_
end_define

begin_comment
comment|/** @file event2/buffer.h    Functions for buffering data for network sending or receiving.    An evbuffer can be used for preparing data before sending it to   the network or conversely for reading data from the network.   Evbuffers try to avoid memory copies as much as possible.  As a   result, evbuffers can be used to pass data around without actually   incurring the overhead of copying the data.    A new evbuffer can be allocated with evbuffer_new(), and can be   freed with evbuffer_free().  Most users will be using evbuffers via   the bufferevent interface.  To access a bufferevent's evbuffers, use   bufferevent_get_input() and bufferevent_get_output().    There are several guidelines for using evbuffers.    - if you already know how much data you are going to add as a result     of calling evbuffer_add() multiple times, it makes sense to use     evbuffer_expand() first to make sure that enough memory is allocated     before hand.    - evbuffer_add_buffer() adds the contents of one buffer to the other     without incurring any unnecessary memory copies.    - evbuffer_add() and evbuffer_add_buffer() do not mix very well:     if you use them, you will wind up with fragmented memory in your 	buffer.    - For high-performance code, you may want to avoid copying data into and out     of buffers.  You can skip the copy step by using     evbuffer_reserve_space()/evbuffer_commit_space() when writing into a     buffer, and evbuffer_peek() when reading.    In Libevent 2.0 and later, evbuffers are represented using a linked   list of memory chunks, with pointers to the first and last chunk in   the chain.    As the contents of an evbuffer can be stored in multiple different   memory blocks, it cannot be accessed directly.  Instead, evbuffer_pullup()   can be used to force a specified number of bytes to be contiguous. This   will cause memory reallocation and memory copies if the data is split   across multiple blocks.  It is more efficient, however, to use   evbuffer_peek() if you don't require that the memory to be contiguous.  */
end_comment

begin_include
include|#
directive|include
file|<event2/visibility.h>
end_include

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
file|<event2/event-config.h>
include|#
directive|include
file|<stdarg.h>
ifdef|#
directive|ifdef
name|EVENT__HAVE_SYS_TYPES_H
include|#
directive|include
file|<sys/types.h>
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EVENT__HAVE_SYS_UIO_H
include|#
directive|include
file|<sys/uio.h>
endif|#
directive|endif
include|#
directive|include
file|<event2/util.h>
comment|/**    An evbuffer is an opaque data type for efficiently buffering data to be    sent or received on the network.     @see event2/event.h for more information */
struct|struct
name|evbuffer
ifdef|#
directive|ifdef
name|EVENT_IN_DOXYGEN_
block|{}
endif|#
directive|endif
struct|;
comment|/**     Pointer to a position within an evbuffer.      Used when repeatedly searching through a buffer.  Calling any function     that modifies or re-packs the buffer contents may invalidate all     evbuffer_ptrs for that buffer.  Do not modify these values except with     evbuffer_ptr_set.      Used when repeatedly searching through a buffer.  Calls to any function     that modifies or re-packs the buffer contents may invalidate all     evbuffer_ptrs for that buffer.  Do not modify these values except with     evbuffer_ptr_set.      An evbuffer_ptr can represent any position from the start of a buffer up     to a position immediately after the end of a buffer.      @see evbuffer_ptr_set()  */
struct|struct
name|evbuffer_ptr
block|{
name|ev_ssize_t
name|pos
decl_stmt|;
comment|/* Do not alter or rely on the values of fields: they are for internal 	 * use */
struct|struct
block|{
name|void
modifier|*
name|chain
decl_stmt|;
name|size_t
name|pos_in_chain
decl_stmt|;
block|}
name|internal_
struct|;
block|}
struct|;
comment|/** Describes a single extent of memory inside an evbuffer.  Used for     direct-access functions.      @see evbuffer_reserve_space, evbuffer_commit_space, evbuffer_peek  */
ifdef|#
directive|ifdef
name|EVENT__HAVE_SYS_UIO_H
define|#
directive|define
name|evbuffer_iovec
value|iovec
comment|/* Internal use -- defined only if we are using the native struct iovec */
define|#
directive|define
name|EVBUFFER_IOVEC_IS_NATIVE_
else|#
directive|else
struct|struct
name|evbuffer_iovec
block|{
comment|/** The start of the extent of memory. */
name|void
modifier|*
name|iov_base
decl_stmt|;
comment|/** The length of the extent of memory. */
name|size_t
name|iov_len
decl_stmt|;
block|}
struct|;
endif|#
directive|endif
comment|/**   Allocate storage for a new evbuffer.    @return a pointer to a newly allocated evbuffer struct, or NULL if an error 	occurred  */
name|EVENT2_EXPORT_SYMBOL
name|struct
name|evbuffer
modifier|*
name|evbuffer_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**   Deallocate storage for an evbuffer.    @param buf pointer to the evbuffer to be freed  */
name|EVENT2_EXPORT_SYMBOL
name|void
name|evbuffer_free
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/**    Enable locking on an evbuffer so that it can safely be used by multiple    threads at the same time.     NOTE: when locking is enabled, the lock will be held when callbacks are    invoked.  This could result in deadlock if you aren't careful.  Plan    accordingly!     @param buf An evbuffer to make lockable.    @param lock A lock object, or NULL if we should allocate our own.    @return 0 on success, -1 on failure.  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_enable_locking
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
name|void
modifier|*
name|lock
parameter_list|)
function_decl|;
comment|/**    Acquire the lock on an evbuffer.  Has no effect if locking was not enabled    with evbuffer_enable_locking. */
name|EVENT2_EXPORT_SYMBOL
name|void
name|evbuffer_lock
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/**    Release the lock on an evbuffer.  Has no effect if locking was not enabled    with evbuffer_enable_locking. */
name|EVENT2_EXPORT_SYMBOL
name|void
name|evbuffer_unlock
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/** If this flag is set, then we will not use evbuffer_peek(),  * evbuffer_remove(), evbuffer_remove_buffer(), and so on to read bytes  * from this buffer: we'll only take bytes out of this buffer by  * writing them to the network (as with evbuffer_write_atmost), by  * removing them without observing them (as with evbuffer_drain),  * or by copying them all out at once (as with evbuffer_add_buffer).  *  * Using this option allows the implementation to use sendfile-based  * operations for evbuffer_add_file(); see that function for more  * information.  *  * This flag is on by default for bufferevents that can take advantage  * of it; you should never actually need to set it on a bufferevent's  * output buffer.  */
define|#
directive|define
name|EVBUFFER_FLAG_DRAINS_TO_FD
value|1
comment|/** Change the flags that are set for an evbuffer by adding more.  *  * @param buffer the evbuffer that the callback is watching.  * @param cb the callback whose status we want to change.  * @param flags One or more EVBUFFER_FLAG_* options  * @return 0 on success, -1 on failure.  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_set_flags
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
name|ev_uint64_t
name|flags
parameter_list|)
function_decl|;
comment|/** Change the flags that are set for an evbuffer by removing some.  *  * @param buffer the evbuffer that the callback is watching.  * @param cb the callback whose status we want to change.  * @param flags One or more EVBUFFER_FLAG_* options  * @return 0 on success, -1 on failure.  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_clear_flags
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
name|ev_uint64_t
name|flags
parameter_list|)
function_decl|;
comment|/**   Returns the total number of bytes stored in the evbuffer    @param buf pointer to the evbuffer   @return the number of bytes stored in the evbuffer */
name|EVENT2_EXPORT_SYMBOL
name|size_t
name|evbuffer_get_length
parameter_list|(
specifier|const
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/**    Returns the number of contiguous available bytes in the first buffer chain.     This is useful when processing data that might be split into multiple    chains, or that might all be in the first chain.  Calls to    evbuffer_pullup() that cause reallocation and copying of data can thus be    avoided.     @param buf pointer to the evbuffer    @return 0 if no data is available, otherwise the number of available bytes      in the first buffer chain. */
name|EVENT2_EXPORT_SYMBOL
name|size_t
name|evbuffer_get_contiguous_space
parameter_list|(
specifier|const
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/**   Expands the available space in an evbuffer.    Expands the available space in the evbuffer to at least datlen, so that   appending datlen additional bytes will not require any new allocations.    @param buf the evbuffer to be expanded   @param datlen the new minimum length requirement   @return 0 if successful, or -1 if an error occurred */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_expand
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
name|size_t
name|datlen
parameter_list|)
function_decl|;
comment|/**    Reserves space in the last chain or chains of an evbuffer.     Makes space available in the last chain or chains of an evbuffer that can    be arbitrarily written to by a user.  The space does not become    available for reading until it has been committed with    evbuffer_commit_space().     The space is made available as one or more extents, represented by    an initial pointer and a length.  You can force the memory to be    available as only one extent.  Allowing more extents, however, makes the    function more efficient.     Multiple subsequent calls to this function will make the same space    available until evbuffer_commit_space() has been called.     It is an error to do anything that moves around the buffer's internal    memory structures before committing the space.     NOTE: The code currently does not ever use more than two extents.    This may change in future versions.     @param buf the evbuffer in which to reserve space.    @param size how much space to make available, at minimum.  The       total length of the extents may be greater than the requested       length.    @param vec an array of one or more evbuffer_iovec structures to       hold pointers to the reserved extents of memory.    @param n_vec The length of the vec array.  Must be at least 1;        2 is more efficient.    @return the number of provided extents, or -1 on error.    @see evbuffer_commit_space() */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_reserve_space
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
name|ev_ssize_t
name|size
parameter_list|,
name|struct
name|evbuffer_iovec
modifier|*
name|vec
parameter_list|,
name|int
name|n_vec
parameter_list|)
function_decl|;
comment|/**    Commits previously reserved space.     Commits some of the space previously reserved with    evbuffer_reserve_space().  It then becomes available for reading.     This function may return an error if the pointer in the extents do    not match those returned from evbuffer_reserve_space, or if data    has been added to the buffer since the space was reserved.     If you want to commit less data than you got reserved space for,    modify the iov_len pointer of the appropriate extent to a smaller    value.  Note that you may have received more space than you    requested if it was available!     @param buf the evbuffer in which to reserve space.    @param vec one or two extents returned by evbuffer_reserve_space.    @param n_vecs the number of extents.    @return 0 on success, -1 on error    @see evbuffer_reserve_space() */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_commit_space
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
name|struct
name|evbuffer_iovec
modifier|*
name|vec
parameter_list|,
name|int
name|n_vecs
parameter_list|)
function_decl|;
comment|/**   Append data to the end of an evbuffer.    @param buf the evbuffer to be appended to   @param data pointer to the beginning of the data buffer   @param datlen the number of bytes to be copied from the data buffer   @return 0 on success, -1 on failure.  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_add
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|datlen
parameter_list|)
function_decl|;
comment|/**   Read data from an evbuffer and drain the bytes read.    If more bytes are requested than are available in the evbuffer, we   only extract as many bytes as were available.    @param buf the evbuffer to be read from   @param data the destination buffer to store the result   @param datlen the maximum size of the destination buffer   @return the number of bytes read, or -1 if we can't drain the buffer.  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_remove
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|datlen
parameter_list|)
function_decl|;
comment|/**   Read data from an evbuffer, and leave the buffer unchanged.    If more bytes are requested than are available in the evbuffer, we   only extract as many bytes as were available.    @param buf the evbuffer to be read from   @param data_out the destination buffer to store the result   @param datlen the maximum size of the destination buffer   @return the number of bytes read, or -1 if we can't drain the buffer.  */
name|EVENT2_EXPORT_SYMBOL
name|ev_ssize_t
name|evbuffer_copyout
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
name|void
modifier|*
name|data_out
parameter_list|,
name|size_t
name|datlen
parameter_list|)
function_decl|;
comment|/**   Read data from the middle of an evbuffer, and leave the buffer unchanged.    If more bytes are requested than are available in the evbuffer, we   only extract as many bytes as were available.    @param buf the evbuffer to be read from   @param pos the position to start reading from   @param data_out the destination buffer to store the result   @param datlen the maximum size of the destination buffer   @return the number of bytes read, or -1 if we can't drain the buffer.  */
name|EVENT2_EXPORT_SYMBOL
name|ev_ssize_t
name|evbuffer_copyout_from
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
specifier|const
name|struct
name|evbuffer_ptr
modifier|*
name|pos
parameter_list|,
name|void
modifier|*
name|data_out
parameter_list|,
name|size_t
name|datlen
parameter_list|)
function_decl|;
comment|/**   Read data from an evbuffer into another evbuffer, draining   the bytes from the source buffer.  This function avoids copy   operations to the extent possible.    If more bytes are requested than are available in src, the src   buffer is drained completely.    @param src the evbuffer to be read from   @param dst the destination evbuffer to store the result into   @param datlen the maximum numbers of bytes to transfer   @return the number of bytes read  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_remove_buffer
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|src
parameter_list|,
name|struct
name|evbuffer
modifier|*
name|dst
parameter_list|,
name|size_t
name|datlen
parameter_list|)
function_decl|;
comment|/** Used to tell evbuffer_readln what kind of line-ending to look for.  */
enum|enum
name|evbuffer_eol_style
block|{
comment|/** Any sequence of CR and LF characters is acceptable as an 	 * EOL. 	 * 	 * Note that this style can produce ambiguous results: the 	 * sequence "CRLF" will be treated as a single EOL if it is 	 * all in the buffer at once, but if you first read a CR from 	 * the network and later read an LF from the network, it will 	 * be treated as two EOLs. 	 */
name|EVBUFFER_EOL_ANY
block|,
comment|/** An EOL is an LF, optionally preceded by a CR.  This style is 	 * most useful for implementing text-based internet protocols. */
name|EVBUFFER_EOL_CRLF
block|,
comment|/** An EOL is a CR followed by an LF. */
name|EVBUFFER_EOL_CRLF_STRICT
block|,
comment|/** An EOL is a LF. */
name|EVBUFFER_EOL_LF
block|,
comment|/** An EOL is a NUL character (that is, a single byte with value 0) */
name|EVBUFFER_EOL_NUL
block|}
enum|;
comment|/**  * Read a single line from an evbuffer.  *  * Reads a line terminated by an EOL as determined by the evbuffer_eol_style  * argument.  Returns a newly allocated nul-terminated string; the caller must  * free the returned value.  The EOL is not included in the returned string.  *  * @param buffer the evbuffer to read from  * @param n_read_out if non-NULL, points to a size_t that is set to the  *       number of characters in the returned string.  This is useful for  *       strings that can contain NUL characters.  * @param eol_style the style of line-ending to use.  * @return pointer to a single line, or NULL if an error occurred  */
name|EVENT2_EXPORT_SYMBOL
name|char
modifier|*
name|evbuffer_readln
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
name|size_t
modifier|*
name|n_read_out
parameter_list|,
name|enum
name|evbuffer_eol_style
name|eol_style
parameter_list|)
function_decl|;
comment|/**   Move all data from one evbuffer into another evbuffer.    This is a destructive add.  The data from one buffer moves into   the other buffer.  However, no unnecessary memory copies occur.    @param outbuf the output buffer   @param inbuf the input buffer   @return 0 if successful, or -1 if an error occurred    @see evbuffer_remove_buffer()  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_add_buffer
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|outbuf
parameter_list|,
name|struct
name|evbuffer
modifier|*
name|inbuf
parameter_list|)
function_decl|;
comment|/**   Copy data from one evbuffer into another evbuffer.    This is a non-destructive add.  The data from one buffer is copied   into the other buffer.  However, no unnecessary memory copies occur.    Note that buffers already containing buffer references can't be added   to other buffers.    @param outbuf the output buffer   @param inbuf the input buffer   @return 0 if successful, or -1 if an error occurred  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_add_buffer_reference
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|outbuf
parameter_list|,
name|struct
name|evbuffer
modifier|*
name|inbuf
parameter_list|)
function_decl|;
comment|/**    A cleanup function for a piece of memory added to an evbuffer by    reference.     @see evbuffer_add_reference()  */
typedef|typedef
name|void
function_decl|(
modifier|*
name|evbuffer_ref_cleanup_cb
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|datalen
parameter_list|,
name|void
modifier|*
name|extra
parameter_list|)
function_decl|;
comment|/**   Reference memory into an evbuffer without copying.    The memory needs to remain valid until all the added data has been   read.  This function keeps just a reference to the memory without   actually incurring the overhead of a copy.    @param outbuf the output buffer   @param data the memory to reference   @param datlen how memory to reference   @param cleanupfn callback to be invoked when the memory is no longer 	referenced by this evbuffer.   @param cleanupfn_arg optional argument to the cleanup callback   @return 0 if successful, or -1 if an error occurred  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_add_reference
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|outbuf
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|datlen
parameter_list|,
name|evbuffer_ref_cleanup_cb
name|cleanupfn
parameter_list|,
name|void
modifier|*
name|cleanupfn_arg
parameter_list|)
function_decl|;
comment|/**   Copy data from a file into the evbuffer for writing to a socket.    This function avoids unnecessary data copies between userland and   kernel.  If sendfile is available and the EVBUFFER_FLAG_DRAINS_TO_FD   flag is set, it uses those functions.  Otherwise, it tries to use   mmap (or CreateFileMapping on Windows).    The function owns the resulting file descriptor and will close it   when finished transferring data.    The results of using evbuffer_remove() or evbuffer_pullup() on   evbuffers whose data was added using this function are undefined.    For more fine-grained control, use evbuffer_add_file_segment.    @param outbuf the output buffer   @param fd the file descriptor   @param offset the offset from which to read data   @param length how much data to read, or -1 to read as much as possible.     (-1 requires that 'fd' support fstat.)   @return 0 if successful, or -1 if an error occurred */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_add_file
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|outbuf
parameter_list|,
name|int
name|fd
parameter_list|,
name|ev_off_t
name|offset
parameter_list|,
name|ev_off_t
name|length
parameter_list|)
function_decl|;
comment|/**   An evbuffer_file_segment holds a reference to a range of a file --   possibly the whole file! -- for use in writing from an evbuffer to a   socket.  It could be implemented with mmap, sendfile, splice, or (if all   else fails) by just pulling all the data into RAM.  A single   evbuffer_file_segment can be added more than once, and to more than one   evbuffer.  */
struct_decl|struct
name|evbuffer_file_segment
struct_decl|;
comment|/**     Flag for creating evbuffer_file_segment: If this flag is set, then when     the evbuffer_file_segment is freed and no longer in use by any     evbuffer, the underlying fd is closed.  */
define|#
directive|define
name|EVBUF_FS_CLOSE_ON_FREE
value|0x01
comment|/**    Flag for creating evbuffer_file_segment: Disable memory-map based    implementations.  */
define|#
directive|define
name|EVBUF_FS_DISABLE_MMAP
value|0x02
comment|/**    Flag for creating evbuffer_file_segment: Disable direct fd-to-fd    implementations (including sendfile and splice).     You might want to use this option if data needs to be taken from the    evbuffer by any means other than writing it to the network: the sendfile    backend is fast, but it only works for sending files directly to the    network.  */
define|#
directive|define
name|EVBUF_FS_DISABLE_SENDFILE
value|0x04
comment|/**    Flag for creating evbuffer_file_segment: Do not allocate a lock for this    segment.  If this option is set, then neither the segment nor any    evbuffer it is added to may ever be accessed from more than one thread    at a time.  */
define|#
directive|define
name|EVBUF_FS_DISABLE_LOCKING
value|0x08
comment|/**    A cleanup function for a evbuffer_file_segment added to an evbuffer    for reference.  */
typedef|typedef
name|void
function_decl|(
modifier|*
name|evbuffer_file_segment_cleanup_cb
function_decl|)
parameter_list|(
name|struct
name|evbuffer_file_segment
specifier|const
modifier|*
name|seg
parameter_list|,
name|int
name|flags
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|/**    Create and return a new evbuffer_file_segment for reading data from a    file and sending it out via an evbuffer.     This function avoids unnecessary data copies between userland and    kernel.  Where available, it uses sendfile or splice.     The file descriptor must not be closed so long as any evbuffer is using    this segment.     The results of using evbuffer_remove() or evbuffer_pullup() or any other    function that reads bytes from an evbuffer on any evbuffer containing    the newly returned segment are undefined, unless you pass the    EVBUF_FS_DISABLE_SENDFILE flag to this function.     @param fd an open file to read from.    @param offset an index within the file at which to start reading    @param length how much data to read, or -1 to read as much as possible.       (-1 requires that 'fd' support fstat.)    @param flags any number of the EVBUF_FS_* flags    @return a new evbuffer_file_segment, or NULL on failure.  **/
name|EVENT2_EXPORT_SYMBOL
name|struct
name|evbuffer_file_segment
modifier|*
name|evbuffer_file_segment_new
parameter_list|(
name|int
name|fd
parameter_list|,
name|ev_off_t
name|offset
parameter_list|,
name|ev_off_t
name|length
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
comment|/**    Free an evbuffer_file_segment     It is safe to call this function even if the segment has been added to    one or more evbuffers.  The evbuffer_file_segment will not be freed    until no more references to it exist.  */
name|EVENT2_EXPORT_SYMBOL
name|void
name|evbuffer_file_segment_free
parameter_list|(
name|struct
name|evbuffer_file_segment
modifier|*
name|seg
parameter_list|)
function_decl|;
comment|/**    Add cleanup callback and argument for the callback to an    evbuffer_file_segment.     The cleanup callback will be invoked when no more references to the    evbuffer_file_segment exist.  **/
name|EVENT2_EXPORT_SYMBOL
name|void
name|evbuffer_file_segment_add_cleanup_cb
parameter_list|(
name|struct
name|evbuffer_file_segment
modifier|*
name|seg
parameter_list|,
name|evbuffer_file_segment_cleanup_cb
name|cb
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|/**    Insert some or all of an evbuffer_file_segment at the end of an evbuffer     Note that the offset and length parameters of this function have a    different meaning from those provided to evbuffer_file_segment_new: When    you create the segment, the offset is the offset _within the file_, and    the length is the length _of the segment_, whereas when you add a    segment to an evbuffer, the offset is _within the segment_ and the    length is the length of the _part of the segment you want to use.     In other words, if you have a 10 KiB file, and you create an    evbuffer_file_segment for it with offset 20 and length 1000, it will    refer to bytes 20..1019 inclusive.  If you then pass this segment to    evbuffer_add_file_segment and specify an offset of 20 and a length of    50, you will be adding bytes 40..99 inclusive.     @param buf the evbuffer to append to    @param seg the segment to add    @param offset the offset within the segment to start from    @param length the amount of data to add, or -1 to add it all.    @return 0 on success, -1 on failure.  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_add_file_segment
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
name|struct
name|evbuffer_file_segment
modifier|*
name|seg
parameter_list|,
name|ev_off_t
name|offset
parameter_list|,
name|ev_off_t
name|length
parameter_list|)
function_decl|;
comment|/**   Append a formatted string to the end of an evbuffer.    The string is formated as printf.    @param buf the evbuffer that will be appended to   @param fmt a format string   @param ... arguments that will be passed to printf(3)   @return The number of bytes added if successful, or -1 if an error occurred.    @see evutil_printf(), evbuffer_add_vprintf()  */
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_add_printf
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
ifdef|#
directive|ifdef
name|__GNUC__
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
block|)
end_extern

begin_endif
unit|))
endif|#
directive|endif
end_endif

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**   Append a va_list formatted string to the end of an evbuffer.    @param buf the evbuffer that will be appended to   @param fmt a format string   @param ap a varargs va_list argument array that will be passed to vprintf(3)   @return The number of bytes added if successful, or -1 if an error occurred.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_add_vprintf
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
ifdef|#
directive|ifdef
name|__GNUC__
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_endif
unit|)))
endif|#
directive|endif
end_endif

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**   Remove a specified number of bytes data from the beginning of an evbuffer.    @param buf the evbuffer to be drained   @param len the number of bytes to drain from the beginning of the buffer   @return 0 on success, -1 on failure.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_drain
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Write the contents of an evbuffer to a file descriptor.    The evbuffer will be drained after the bytes have been successfully written.    @param buffer the evbuffer to be written and drained   @param fd the file descriptor to be written to   @return the number of bytes written, or -1 if an error occurred   @see evbuffer_read()  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_write
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
name|evutil_socket_t
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Write some of the contents of an evbuffer to a file descriptor.    The evbuffer will be drained after the bytes have been successfully written.    @param buffer the evbuffer to be written and drained   @param fd the file descriptor to be written to   @param howmuch the largest allowable number of bytes to write, or -1 	to write as many bytes as we can.   @return the number of bytes written, or -1 if an error occurred   @see evbuffer_read()  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_write_atmost
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
name|evutil_socket_t
name|fd
parameter_list|,
name|ev_ssize_t
name|howmuch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Read from a file descriptor and store the result in an evbuffer.    @param buffer the evbuffer to store the result   @param fd the file descriptor to read from   @param howmuch the number of bytes to be read   @return the number of bytes read, or -1 if an error occurred   @see evbuffer_write()  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_read
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
name|evutil_socket_t
name|fd
parameter_list|,
name|int
name|howmuch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**    Search for a string within an evbuffer.     @param buffer the evbuffer to be searched    @param what the string to be searched for    @param len the length of the search string    @param start NULL or a pointer to a valid struct evbuffer_ptr.    @return a struct evbuffer_ptr whose 'pos' field has the offset of the      first occurrence of the string in the buffer after 'start'.  The 'pos'      field of the result is -1 if the string was not found.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|struct
name|evbuffer_ptr
name|evbuffer_search
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
specifier|const
name|char
modifier|*
name|what
parameter_list|,
name|size_t
name|len
parameter_list|,
specifier|const
name|struct
name|evbuffer_ptr
modifier|*
name|start
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**    Search for a string within part of an evbuffer.     @param buffer the evbuffer to be searched    @param what the string to be searched for    @param len the length of the search string    @param start NULL or a pointer to a valid struct evbuffer_ptr that      indicates where we should start searching.    @param end NULL or a pointer to a valid struct evbuffer_ptr that      indicates where we should stop searching.    @return a struct evbuffer_ptr whose 'pos' field has the offset of the      first occurrence of the string in the buffer after 'start'.  The 'pos'      field of the result is -1 if the string was not found.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|struct
name|evbuffer_ptr
name|evbuffer_search_range
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
specifier|const
name|char
modifier|*
name|what
parameter_list|,
name|size_t
name|len
parameter_list|,
specifier|const
name|struct
name|evbuffer_ptr
modifier|*
name|start
parameter_list|,
specifier|const
name|struct
name|evbuffer_ptr
modifier|*
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**    Defines how to adjust an evbuffer_ptr by evbuffer_ptr_set()     @see evbuffer_ptr_set() */
end_comment

begin_enum
enum|enum
name|evbuffer_ptr_how
block|{
comment|/** Sets the pointer to the position; can be called on with an 	    uninitialized evbuffer_ptr. */
name|EVBUFFER_PTR_SET
block|,
comment|/** Advances the pointer by adding to the current position. */
name|EVBUFFER_PTR_ADD
block|}
enum|;
end_enum

begin_comment
comment|/**    Sets the search pointer in the buffer to position.     There are two ways to use this function: you can call       evbuffer_ptr_set(buf,&pos, N, EVBUFFER_PTR_SET)    to move 'pos' to a position 'N' bytes after the start of the buffer, or       evbuffer_ptr_set(buf,&pos, N, EVBUFFER_PTR_SET)    to move 'pos' forward by 'N' bytes.     If evbuffer_ptr is not initialized, this function can only be called    with EVBUFFER_PTR_SET.     An evbuffer_ptr can represent any position from the start of the buffer to    a position immediately after the end of the buffer.     @param buffer the evbuffer to be search    @param ptr a pointer to a struct evbuffer_ptr    @param position the position at which to start the next search    @param how determines how the pointer should be manipulated.    @returns 0 on success or -1 otherwise */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_ptr_set
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
name|struct
name|evbuffer_ptr
modifier|*
name|ptr
parameter_list|,
name|size_t
name|position
parameter_list|,
name|enum
name|evbuffer_ptr_how
name|how
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**    Search for an end-of-line string within an evbuffer.     @param buffer the evbuffer to be searched    @param start NULL or a pointer to a valid struct evbuffer_ptr to start       searching at.    @param eol_len_out If non-NULL, the pointed-to value will be set to       the length of the end-of-line string.    @param eol_style The kind of EOL to look for; see evbuffer_readln() for       more information    @return a struct evbuffer_ptr whose 'pos' field has the offset of the      first occurrence EOL in the buffer after 'start'.  The 'pos'      field of the result is -1 if the string was not found.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|struct
name|evbuffer_ptr
name|evbuffer_search_eol
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
name|struct
name|evbuffer_ptr
modifier|*
name|start
parameter_list|,
name|size_t
modifier|*
name|eol_len_out
parameter_list|,
name|enum
name|evbuffer_eol_style
name|eol_style
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Function to peek at data inside an evbuffer without removing it or     copying it out.      Pointers to the data are returned by filling the 'vec_out' array     with pointers to one or more extents of data inside the buffer.      The total data in the extents that you get back may be more than     you requested (if there is more data last extent than you asked     for), or less (if you do not provide enough evbuffer_iovecs, or if     the buffer does not have as much data as you asked to see).      @param buffer the evbuffer to peek into,     @param len the number of bytes to try to peek.  If len is negative, we        will try to fill as much of vec_out as we can.  If len is negative        and vec_out is not provided, we return the number of evbuffer_iovecs        that would be needed to get all the data in the buffer.     @param start_at an evbuffer_ptr indicating the point at which we        should start looking for data.  NULL means, "At the start of the        buffer."     @param vec_out an array of evbuffer_iovec     @param n_vec the length of vec_out.  If 0, we only count how many        extents would be necessary to point to the requested amount of        data.     @return The number of extents needed.  This may be less than n_vec        if we didn't need all the evbuffer_iovecs we were given, or more        than n_vec if we would need more to return all the data that was        requested.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_peek
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
name|ev_ssize_t
name|len
parameter_list|,
name|struct
name|evbuffer_ptr
modifier|*
name|start_at
parameter_list|,
name|struct
name|evbuffer_iovec
modifier|*
name|vec_out
parameter_list|,
name|int
name|n_vec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Structure passed to an evbuffer_cb_func evbuffer callback      @see evbuffer_cb_func, evbuffer_add_cb()  */
end_comment

begin_struct
struct|struct
name|evbuffer_cb_info
block|{
comment|/** The number of bytes in this evbuffer when callbacks were last 	 * invoked. */
name|size_t
name|orig_size
decl_stmt|;
comment|/** The number of bytes added since callbacks were last invoked. */
name|size_t
name|n_added
decl_stmt|;
comment|/** The number of bytes removed since callbacks were last invoked. */
name|size_t
name|n_deleted
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** Type definition for a callback that is invoked whenever data is added or     removed from an evbuffer.      An evbuffer may have one or more callbacks set at a time.  The order     in which they are executed is undefined.      A callback function may add more callbacks, or remove itself from the     list of callbacks, or add or remove data from the buffer.  It may not     remove another callback from the list.      If a callback adds or removes data from the buffer or from another     buffer, this can cause a recursive invocation of your callback or     other callbacks.  If you ask for an infinite loop, you might just get     one: watch out!      @param buffer the buffer whose size has changed     @param info a structure describing how the buffer changed.     @param arg a pointer to user data */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|evbuffer_cb_func
function_decl|)
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
specifier|const
name|struct
name|evbuffer_cb_info
modifier|*
name|info
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_struct_decl
struct_decl|struct
name|evbuffer_cb_entry
struct_decl|;
end_struct_decl

begin_comment
comment|/** Add a new callback to an evbuffer.    Subsequent calls to evbuffer_add_cb() add new callbacks.  To remove this   callback, call evbuffer_remove_cb or evbuffer_remove_cb_entry.    @param buffer the evbuffer to be monitored   @param cb the callback function to invoke when the evbuffer is modified, 	or NULL to remove all callbacks.   @param cbarg an argument to be provided to the callback function   @return a handle to the callback on success, or NULL on failure.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|struct
name|evbuffer_cb_entry
modifier|*
name|evbuffer_add_cb
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
name|evbuffer_cb_func
name|cb
parameter_list|,
name|void
modifier|*
name|cbarg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Remove a callback from an evbuffer, given a handle returned from     evbuffer_add_cb.      Calling this function invalidates the handle.      @return 0 if a callback was removed, or -1 if no matching callback was     found.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_remove_cb_entry
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
name|struct
name|evbuffer_cb_entry
modifier|*
name|ent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Remove a callback from an evbuffer, given the function and argument     used to add it.      @return 0 if a callback was removed, or -1 if no matching callback was     found.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_remove_cb
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
name|evbuffer_cb_func
name|cb
parameter_list|,
name|void
modifier|*
name|cbarg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** If this flag is not set, then a callback is temporarily disabled, and  * should not be invoked.  *  * @see evbuffer_cb_set_flags(), evbuffer_cb_clear_flags()  */
end_comment

begin_define
define|#
directive|define
name|EVBUFFER_CB_ENABLED
value|1
end_define

begin_comment
comment|/** Change the flags that are set for a callback on a buffer by adding more.      @param buffer the evbuffer that the callback is watching.     @param cb the callback whose status we want to change.     @param flags EVBUFFER_CB_ENABLED to re-enable the callback.     @return 0 on success, -1 on failure.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_cb_set_flags
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
name|struct
name|evbuffer_cb_entry
modifier|*
name|cb
parameter_list|,
name|ev_uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Change the flags that are set for a callback on a buffer by removing some      @param buffer the evbuffer that the callback is watching.     @param cb the callback whose status we want to change.     @param flags EVBUFFER_CB_ENABLED to disable the callback.     @return 0 on success, -1 on failure.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_cb_clear_flags
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
name|struct
name|evbuffer_cb_entry
modifier|*
name|cb
parameter_list|,
name|ev_uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/** Postpone calling a given callback until unsuspend is called later.      This is different from disabling the callback, since the callback will get 	invoked later if the buffer size changes between now and when we unsuspend 	it.  	@param the buffer that the callback is watching. 	@param cb the callback we want to suspend.  */
end_comment

begin_comment
unit|EVENT2_EXPORT_SYMBOL void evbuffer_cb_suspend(struct evbuffer *buffer, struct evbuffer_cb_entry *cb);
comment|/** Stop postponing a callback that we postponed with evbuffer_cb_suspend.  	If data was added to or removed from the buffer while the callback was 	suspended, the callback will get called once now.  	@param the buffer that the callback is watching. 	@param cb the callback we want to stop suspending.  */
end_comment

begin_endif
unit|EVENT2_EXPORT_SYMBOL void evbuffer_cb_unsuspend(struct evbuffer *buffer, struct evbuffer_cb_entry *cb);
endif|#
directive|endif
end_endif

begin_comment
comment|/**   Makes the data at the beginning of an evbuffer contiguous.    @param buf the evbuffer to make contiguous   @param size the number of bytes to make contiguous, or -1 to make the 	entire buffer contiguous.   @return a pointer to the contiguous memory array, or NULL if param size 	requested more data than is present in the buffer. */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|unsigned
name|char
modifier|*
name|evbuffer_pullup
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
name|ev_ssize_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Prepends data to the beginning of the evbuffer    @param buf the evbuffer to which to prepend data   @param data a pointer to the memory to prepend   @param size the number of bytes to prepend   @return 0 if successful, or -1 otherwise */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_prepend
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Prepends all data from the src evbuffer to the beginning of the dst   evbuffer.    @param dst the evbuffer to which to prepend data   @param src the evbuffer to prepend; it will be emptied as a result   @return 0 if successful, or -1 otherwise */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_prepend_buffer
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|dst
parameter_list|,
name|struct
name|evbuffer
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**    Prevent calls that modify an evbuffer from succeeding. A buffer may    frozen at the front, at the back, or at both the front and the back.     If the front of a buffer is frozen, operations that drain data from    the front of the buffer, or that prepend data to the buffer, will    fail until it is unfrozen.   If the back a buffer is frozen, operations    that append data from the buffer will fail until it is unfrozen.     @param buf The buffer to freeze    @param at_front If true, we freeze the front of the buffer.  If false,       we freeze the back.    @return 0 on success, -1 on failure. */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_freeze
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
name|int
name|at_front
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**    Re-enable calls that modify an evbuffer.     @param buf The buffer to un-freeze    @param at_front If true, we unfreeze the front of the buffer.  If false,       we unfreeze the back.    @return 0 on success, -1 on failure.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_unfreeze
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buf
parameter_list|,
name|int
name|at_front
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|event_base
struct_decl|;
end_struct_decl

begin_comment
comment|/**    Force all the callbacks on an evbuffer to be run, not immediately after    the evbuffer is altered, but instead from inside the event loop.     This can be used to serialize all the callbacks to a single thread    of execution.  */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|int
name|evbuffer_defer_callbacks
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
name|struct
name|event_base
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Append data from 1 or more iovec's to an evbuffer    Calculates the number of bytes needed for an iovec structure and guarantees   all data will fit into a single chain. Can be used in lieu of functionality   which calls evbuffer_add() constantly before being used to increase   performance.    @param buffer the destination buffer   @param vec the source iovec   @param n_vec the number of iovec structures.   @return the number of bytes successfully written to the output buffer. */
end_comment

begin_function_decl
name|EVENT2_EXPORT_SYMBOL
name|size_t
name|evbuffer_add_iovec
parameter_list|(
name|struct
name|evbuffer
modifier|*
name|buffer
parameter_list|,
name|struct
name|evbuffer_iovec
modifier|*
name|vec
parameter_list|,
name|int
name|n_vec
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EVENT2_BUFFER_H_INCLUDED_ */
end_comment

end_unit

