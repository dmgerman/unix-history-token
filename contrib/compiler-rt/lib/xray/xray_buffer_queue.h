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
file|<atomic>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<deque>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_include
include|#
directive|include
file|<unordered_set>
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
name|std
operator|::
name|size_t
name|Size
operator|=
literal|0
expr_stmt|;
block|}
struct|;
name|private
label|:
name|std
operator|::
name|size_t
name|BufferSize
expr_stmt|;
name|std
operator|::
name|deque
operator|<
name|Buffer
operator|>
name|Buffers
expr_stmt|;
name|std
operator|::
name|mutex
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
name|std
operator|::
name|atomic
operator|<
name|bool
operator|>
name|Finalizing
expr_stmt|;
name|public
label|:
comment|/// Initialise a queue of size |N| with buffers of size |B|.
name|BufferQueue
argument_list|(
argument|std::size_t B
argument_list|,
argument|std::size_t N
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
name|std
operator|::
name|error_code
name|getBuffer
argument_list|(
name|Buffer
operator|&
name|Buf
argument_list|)
expr_stmt|;
comment|/// Updates |Buf| to point to nullptr, with size 0.
comment|///
comment|/// Returns:
comment|///   - ...
name|std
operator|::
name|error_code
name|releaseBuffer
argument_list|(
name|Buffer
operator|&
name|Buf
argument_list|)
expr_stmt|;
name|bool
name|finalizing
argument_list|()
specifier|const
block|{
return|return
name|Finalizing
operator|.
name|load
argument_list|(
name|std
operator|::
name|memory_order_acquire
argument_list|)
return|;
block|}
comment|// Sets the state of the BufferQueue to finalizing, which ensures that:
comment|//
comment|//   - All subsequent attempts to retrieve a Buffer will fail.
comment|//   - All releaseBuffer operations will not fail.
comment|//
comment|// After a call to finalize succeeds, all subsequent calls to finalize will
comment|// fail with std::errc::state_not_recoverable.
name|std
operator|::
name|error_code
name|finalize
argument_list|()
expr_stmt|;
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

