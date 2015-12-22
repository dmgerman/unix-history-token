begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       outqueue.h
end_comment

begin_comment
comment|/// \brief      Output queue handling in multithreaded coding
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_comment
comment|/// Output buffer for a single thread
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/// Pointer to the output buffer of lzma_outq.buf_size_max bytes
name|uint8_t
modifier|*
name|buf
decl_stmt|;
comment|/// Amount of data written to buf
name|size_t
name|size
decl_stmt|;
comment|/// Additional size information
name|lzma_vli
name|unpadded_size
decl_stmt|;
name|lzma_vli
name|uncompressed_size
decl_stmt|;
comment|/// True when no more data will be written into this buffer.
comment|///
comment|/// \note       This is read by another thread and thus access
comment|///             to this variable needs a mutex.
name|bool
name|finished
decl_stmt|;
block|}
name|lzma_outbuf
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/// Array of buffers that are used cyclically.
name|lzma_outbuf
modifier|*
name|bufs
decl_stmt|;
comment|/// Memory allocated for all the buffers
name|uint8_t
modifier|*
name|bufs_mem
decl_stmt|;
comment|/// Amount of buffer space available in each buffer
name|size_t
name|buf_size_max
decl_stmt|;
comment|/// Number of buffers allocated
name|uint32_t
name|bufs_allocated
decl_stmt|;
comment|/// Position in the bufs array. The next buffer to be taken
comment|/// into use is bufs[bufs_pos].
name|uint32_t
name|bufs_pos
decl_stmt|;
comment|/// Number of buffers in use
name|uint32_t
name|bufs_used
decl_stmt|;
comment|/// Position in the buffer in lzma_outq_read()
name|size_t
name|read_pos
decl_stmt|;
block|}
name|lzma_outq
typedef|;
end_typedef

begin_comment
comment|/**  * \brief       Calculate the memory usage of an output queue  *  * \return      Approximate memory usage in bytes or UINT64_MAX on error.  */
end_comment

begin_function_decl
specifier|extern
name|uint64_t
name|lzma_outq_memusage
parameter_list|(
name|uint64_t
name|buf_size_max
parameter_list|,
name|uint32_t
name|threads
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Initialize an output queue
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param      outq            Pointer to an output queue. Before calling
end_comment

begin_comment
comment|///                             this function the first time, *outq should
end_comment

begin_comment
comment|///                             have been zeroed with memzero() so that this
end_comment

begin_comment
comment|///                             function knows that there are no previous
end_comment

begin_comment
comment|///                             allocations to free.
end_comment

begin_comment
comment|/// \param      allocator       Pointer to allocator or NULL
end_comment

begin_comment
comment|/// \param      buf_size_max    Maximum amount of data that a single buffer
end_comment

begin_comment
comment|///                             in the queue may need to store.
end_comment

begin_comment
comment|/// \param      threads         Number of buffers that may be in use
end_comment

begin_comment
comment|///                             concurrently. Note that more than this number
end_comment

begin_comment
comment|///                             of buffers will actually get allocated to
end_comment

begin_comment
comment|///                             improve performance when buffers finish
end_comment

begin_comment
comment|///                             out of order.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return     - LZMA_OK
end_comment

begin_comment
comment|///             - LZMA_MEM_ERROR
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_outq_init
parameter_list|(
name|lzma_outq
modifier|*
name|outq
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|,
name|uint64_t
name|buf_size_max
parameter_list|,
name|uint32_t
name|threads
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Free the memory associated with the output queue
end_comment

begin_function_decl
specifier|extern
name|void
name|lzma_outq_end
parameter_list|(
name|lzma_outq
modifier|*
name|outq
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Get a new buffer
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// lzma_outq_has_buf() must be used to check that there is a buffer
end_comment

begin_comment
comment|/// available before calling lzma_outq_get_buf().
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
specifier|extern
name|lzma_outbuf
modifier|*
name|lzma_outq_get_buf
parameter_list|(
name|lzma_outq
modifier|*
name|outq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Test if there is data ready to be read
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Call to this function must be protected with the same mutex that
end_comment

begin_comment
comment|/// is used to protect lzma_outbuf.finished.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
specifier|extern
name|bool
name|lzma_outq_is_readable
parameter_list|(
specifier|const
name|lzma_outq
modifier|*
name|outq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Read finished data
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param      outq            Pointer to an output queue
end_comment

begin_comment
comment|/// \param      out             Beginning of the output buffer
end_comment

begin_comment
comment|/// \param      out_pos         The next byte will be written to
end_comment

begin_comment
comment|///                             out[*out_pos].
end_comment

begin_comment
comment|/// \param      out_size        Size of the out buffer; the first byte into
end_comment

begin_comment
comment|///                             which no data is written to is out[out_size].
end_comment

begin_comment
comment|/// \param      unpadded_size   Unpadded Size from the Block encoder
end_comment

begin_comment
comment|/// \param      uncompressed_size Uncompressed Size from the Block encoder
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return     - LZMA: All OK. Either no data was available or the buffer
end_comment

begin_comment
comment|///               being read didn't become empty yet.
end_comment

begin_comment
comment|///             - LZMA_STREAM_END: The buffer being read was finished.
end_comment

begin_comment
comment|///               *unpadded_size and *uncompressed_size were set.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \note       This reads lzma_outbuf.finished variables and thus call
end_comment

begin_comment
comment|///             to this function needs to be protected with a mutex.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_outq_read
parameter_list|(
name|lzma_outq
modifier|*
specifier|restrict
name|outq
parameter_list|,
name|uint8_t
modifier|*
specifier|restrict
name|out
parameter_list|,
name|size_t
modifier|*
specifier|restrict
name|out_pos
parameter_list|,
name|size_t
name|out_size
parameter_list|,
name|lzma_vli
modifier|*
specifier|restrict
name|unpadded_size
parameter_list|,
name|lzma_vli
modifier|*
specifier|restrict
name|uncompressed_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Test if there is at least one buffer free
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This must be used before getting a new buffer with lzma_outq_get_buf().
end_comment

begin_comment
comment|///
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|lzma_outq_has_buf
parameter_list|(
specifier|const
name|lzma_outq
modifier|*
name|outq
parameter_list|)
block|{
return|return
name|outq
operator|->
name|bufs_used
operator|<
name|outq
operator|->
name|bufs_allocated
return|;
block|}
end_function

begin_comment
comment|/// \brief      Test if the queue is completely empty
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|lzma_outq_is_empty
parameter_list|(
specifier|const
name|lzma_outq
modifier|*
name|outq
parameter_list|)
block|{
return|return
name|outq
operator|->
name|bufs_used
operator|==
literal|0
return|;
block|}
end_function

end_unit

