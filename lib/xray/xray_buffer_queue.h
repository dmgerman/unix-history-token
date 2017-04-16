begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- xray_buffer_queue.h ------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is a part of XRay, a dynamic runtime instrumentation system.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Defines the interface for a buffer queue implementation.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XRAY_BUFFER_QUEUE_H
end_ifndef

begin_define
define|#
directive|define
name|XRAY_BUFFER_QUEUE_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_atomic.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_mutex.h"
end_include

begin_include
include|#
directive|include
file|<deque>
end_include

begin_include
include|#
directive|include
file|<unordered_set>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|__xray
block|{
comment|/// BufferQueue implements a circular queue of fixed sized buffers (much like a
comment|/// freelist) but is concerned mostly with making it really quick to initialise,
comment|/// finalise, and get/return buffers to the queue. This is one key component of
comment|/// the "flight data recorder" (FDR) mode to support ongoing XRay function call
comment|/// trace collection.
name|class
name|BufferQueue
block|{
name|public
label|:
struct|struct
name|Buffer
block|{
name|void
modifier|*
name|Buffer
init|=
name|nullptr
decl_stmt|;
name|size_t
name|Size
init|=
literal|0
decl_stmt|;
block|}
struct|;
name|private
label|:
name|size_t
name|BufferSize
decl_stmt|;
comment|// We use a bool to indicate whether the Buffer has been used in this
comment|// freelist implementation.
name|std
operator|::
name|deque
operator|<
name|std
operator|::
name|tuple
operator|<
name|Buffer
operator|,
name|bool
operator|>>
name|Buffers
expr_stmt|;
name|__sanitizer
operator|::
name|BlockingMutex
name|Mutex
expr_stmt|;
name|std
operator|::
name|unordered_set
operator|<
name|void
operator|*
operator|>
name|OwnedBuffers
expr_stmt|;
name|__sanitizer
operator|::
name|atomic_uint8_t
name|Finalizing
expr_stmt|;
name|public
label|:
name|enum
name|class
name|ErrorCode
range|:
name|unsigned
block|{
name|Ok
block|,
name|NotEnoughMemory
block|,
name|QueueFinalizing
block|,
name|UnrecognizedBuffer
block|,
name|AlreadyFinalized
block|,   }
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|getErrorString
parameter_list|(
name|ErrorCode
name|E
parameter_list|)
block|{
switch|switch
condition|(
name|E
condition|)
block|{
case|case
name|ErrorCode
operator|::
name|Ok
case|:
return|return
literal|"(none)"
return|;
case|case
name|ErrorCode
operator|::
name|NotEnoughMemory
case|:
return|return
literal|"no available buffers in the queue"
return|;
case|case
name|ErrorCode
operator|::
name|QueueFinalizing
case|:
return|return
literal|"queue already finalizing"
return|;
case|case
name|ErrorCode
operator|::
name|UnrecognizedBuffer
case|:
return|return
literal|"buffer being returned not owned by buffer queue"
return|;
case|case
name|ErrorCode
operator|::
name|AlreadyFinalized
case|:
return|return
literal|"queue already finalized"
return|;
block|}
return|return
literal|"unknown error"
return|;
block|}
comment|/// Initialise a queue of size |N| with buffers of size |B|. We report success
comment|/// through |Success|.
name|BufferQueue
argument_list|(
argument|size_t B
argument_list|,
argument|size_t N
argument_list|,
argument|bool&Success
argument_list|)
empty_stmt|;
comment|/// Updates |Buf| to contain the pointer to an appropriate buffer. Returns an
comment|/// error in case there are no available buffers to return when we will run
comment|/// over the upper bound for the total buffers.
comment|///
comment|/// Requirements:
comment|///   - BufferQueue is not finalising.
comment|///
comment|/// Returns:
comment|///   - std::errc::not_enough_memory on exceeding MaxSize.
comment|///   - no error when we find a Buffer.
comment|///   - std::errc::state_not_recoverable on finalising BufferQueue.
name|ErrorCode
name|getBuffer
parameter_list|(
name|Buffer
modifier|&
name|Buf
parameter_list|)
function_decl|;
comment|/// Updates |Buf| to point to nullptr, with size 0.
comment|///
comment|/// Returns:
comment|///   - ...
name|ErrorCode
name|releaseBuffer
parameter_list|(
name|Buffer
modifier|&
name|Buf
parameter_list|)
function_decl|;
name|bool
name|finalizing
argument_list|()
specifier|const
block|{
return|return
name|__sanitizer
operator|::
name|atomic_load
argument_list|(
operator|&
name|Finalizing
argument_list|,
name|__sanitizer
operator|::
name|memory_order_acquire
argument_list|)
return|;
block|}
comment|/// Returns the configured size of the buffers in the buffer queue.
name|size_t
name|ConfiguredBufferSize
argument_list|()
specifier|const
block|{
return|return
name|BufferSize
return|;
block|}
comment|/// Sets the state of the BufferQueue to finalizing, which ensures that:
comment|///
comment|///   - All subsequent attempts to retrieve a Buffer will fail.
comment|///   - All releaseBuffer operations will not fail.
comment|///
comment|/// After a call to finalize succeeds, all subsequent calls to finalize will
comment|/// fail with std::errc::state_not_recoverable.
name|ErrorCode
name|finalize
parameter_list|()
function_decl|;
comment|/// Applies the provided function F to each Buffer in the queue, only if the
comment|/// Buffer is marked 'used' (i.e. has been the result of getBuffer(...) and a
comment|/// releaseBuffer(...) operation.
name|template
operator|<
name|class
name|F
operator|>
name|void
name|apply
argument_list|(
argument|F Fn
argument_list|)
block|{
name|__sanitizer
operator|::
name|BlockingMutexLock
name|G
argument_list|(
operator|&
name|Mutex
argument_list|)
block|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|T
range|:
name|Buffers
control|)
block|{
if|if
condition|(
name|std
operator|::
name|get
operator|<
literal|1
operator|>
operator|(
name|T
operator|)
condition|)
name|Fn
argument_list|(
name|std
operator|::
name|get
operator|<
literal|0
operator|>
operator|(
name|T
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Cleans up allocated buffers.
operator|~
name|BufferQueue
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __xray
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// XRAY_BUFFER_QUEUE_H
end_comment

end_unit

