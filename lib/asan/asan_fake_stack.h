begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_fake_stack.h ---------------------------------------*- C++ -*-===//
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
comment|// This file is a part of AddressSanitizer, an address sanity checker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ASan-private header for asan_fake_stack.cc
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_FAKE_STACK_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_FAKE_STACK_H
end_define

begin_decl_stmt
name|namespace
name|__asan
block|{
comment|// Fake stack frame contains local variables of one function.
struct|struct
name|FakeFrame
block|{
name|uptr
name|magic
decl_stmt|;
comment|// Modified by the instrumented code.
name|uptr
name|descr
decl_stmt|;
comment|// Modified by the instrumented code.
name|uptr
name|pc
decl_stmt|;
comment|// Modified by the instrumented code.
name|u64
name|real_stack
range|:
literal|48
decl_stmt|;
name|u64
name|size_minus_one
range|:
literal|16
decl_stmt|;
comment|// End of the first 32 bytes.
comment|// The rest should not be used when the frame is active.
name|FakeFrame
modifier|*
name|next
decl_stmt|;
block|}
struct|;
struct|struct
name|FakeFrameFifo
block|{
name|public
label|:
name|void
name|FifoPush
parameter_list|(
name|FakeFrame
modifier|*
name|node
parameter_list|)
function_decl|;
name|FakeFrame
modifier|*
name|FifoPop
parameter_list|()
function_decl|;
name|private
label|:
name|FakeFrame
modifier|*
name|first_
decl_stmt|,
modifier|*
name|last_
decl_stmt|;
block|}
struct|;
name|template
operator|<
name|uptr
name|kMaxNumberOfFrames
operator|>
name|class
name|FakeFrameLifo
block|{
name|public
operator|:
name|explicit
name|FakeFrameLifo
argument_list|(
argument|LinkerInitialized
argument_list|)
block|{}
name|FakeFrameLifo
argument_list|()
operator|:
name|n_frames_
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|LifoPush
argument_list|(
argument|FakeFrame *node
argument_list|)
block|{
name|CHECK_LT
argument_list|(
name|n_frames_
argument_list|,
name|kMaxNumberOfFrames
argument_list|)
block|;
name|frames_
index|[
name|n_frames_
operator|++
index|]
operator|=
name|node
block|;   }
name|void
name|LifoPop
argument_list|()
block|{
name|CHECK
argument_list|(
name|n_frames_
argument_list|)
block|;
name|n_frames_
operator|--
block|;   }
name|FakeFrame
operator|*
name|top
argument_list|()
block|{
if|if
condition|(
name|n_frames_
operator|==
literal|0
condition|)
return|return
literal|0
return|;
return|return
name|frames_
index|[
name|n_frames_
operator|-
literal|1
index|]
return|;
block|}
name|private
label|:
name|uptr
name|n_frames_
decl_stmt|;
name|FakeFrame
modifier|*
name|frames_
index|[
name|kMaxNumberOfFrames
index|]
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// For each thread we create a fake stack and place stack objects on this fake
end_comment

begin_comment
comment|// stack instead of the real stack. The fake stack is not really a stack but
end_comment

begin_comment
comment|// a fast malloc-like allocator so that when a function exits the fake stack
end_comment

begin_comment
comment|// is not poped but remains there for quite some time until gets used again.
end_comment

begin_comment
comment|// So, we poison the objects on the fake stack when function returns.
end_comment

begin_comment
comment|// It helps us find use-after-return bugs.
end_comment

begin_comment
comment|// We can not rely on __asan_stack_free being called on every function exit,
end_comment

begin_comment
comment|// so we maintain a lifo list of all current fake frames and update it on every
end_comment

begin_comment
comment|// call to __asan_stack_malloc.
end_comment

begin_decl_stmt
name|class
name|FakeStack
block|{
name|public
label|:
name|FakeStack
argument_list|()
expr_stmt|;
name|explicit
name|FakeStack
argument_list|(
argument|LinkerInitialized x
argument_list|)
block|:
name|call_stack_
argument_list|(
argument|x
argument_list|)
block|{}
name|void
name|Init
parameter_list|(
name|uptr
name|stack_size
parameter_list|)
function_decl|;
name|void
name|StopUsingFakeStack
parameter_list|()
block|{
name|alive_
operator|=
name|false
expr_stmt|;
block|}
name|void
name|Cleanup
parameter_list|()
function_decl|;
name|uptr
name|AllocateStack
parameter_list|(
name|uptr
name|size
parameter_list|,
name|uptr
name|real_stack
parameter_list|)
function_decl|;
specifier|static
name|void
name|OnFree
parameter_list|(
name|uptr
name|ptr
parameter_list|,
name|uptr
name|size
parameter_list|,
name|uptr
name|real_stack
parameter_list|)
function_decl|;
comment|// Return the bottom of the maped region.
name|uptr
name|AddrIsInFakeStack
parameter_list|(
name|uptr
name|addr
parameter_list|)
function_decl|;
name|bool
name|StackSize
parameter_list|()
block|{
return|return
name|stack_size_
return|;
block|}
name|private
label|:
specifier|static
specifier|const
name|uptr
name|kMinStackFrameSizeLog
init|=
literal|9
decl_stmt|;
comment|// Min frame is 512B.
specifier|static
specifier|const
name|uptr
name|kMaxStackFrameSizeLog
init|=
literal|16
decl_stmt|;
comment|// Max stack frame is 64K.
specifier|static
specifier|const
name|uptr
name|kMaxStackMallocSize
init|=
literal|1
operator|<<
name|kMaxStackFrameSizeLog
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kNumberOfSizeClasses
init|=
name|kMaxStackFrameSizeLog
operator|-
name|kMinStackFrameSizeLog
operator|+
literal|1
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kMaxRecursionDepth
init|=
literal|1023
decl_stmt|;
name|bool
name|AddrIsInSizeClass
parameter_list|(
name|uptr
name|addr
parameter_list|,
name|uptr
name|size_class
parameter_list|)
function_decl|;
comment|// Each size class should be large enough to hold all frames.
name|uptr
name|ClassMmapSize
parameter_list|(
name|uptr
name|size_class
parameter_list|)
function_decl|;
name|uptr
name|ClassSize
parameter_list|(
name|uptr
name|size_class
parameter_list|)
block|{
return|return
literal|1UL
operator|<<
operator|(
name|size_class
operator|+
name|kMinStackFrameSizeLog
operator|)
return|;
block|}
name|void
name|DeallocateFrame
parameter_list|(
name|FakeFrame
modifier|*
name|fake_frame
parameter_list|)
function_decl|;
name|uptr
name|ComputeSizeClass
parameter_list|(
name|uptr
name|alloc_size
parameter_list|)
function_decl|;
name|void
name|AllocateOneSizeClass
parameter_list|(
name|uptr
name|size_class
parameter_list|)
function_decl|;
name|uptr
name|stack_size_
decl_stmt|;
name|bool
name|alive_
decl_stmt|;
name|uptr
name|allocated_size_classes_
index|[
name|kNumberOfSizeClasses
index|]
decl_stmt|;
name|FakeFrameFifo
name|size_classes_
index|[
name|kNumberOfSizeClasses
index|]
decl_stmt|;
name|FakeFrameLifo
operator|<
name|kMaxRecursionDepth
operator|>
name|call_stack_
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace __asan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_FAKE_STACK_H
end_comment

end_unit

