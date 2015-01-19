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
comment|// ASan-private header for asan_fake_stack.cc, implements FakeStack.
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

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_common.h"
end_include

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
name|uptr
name|real_stack
decl_stmt|;
block|}
struct|;
comment|// For each thread we create a fake stack and place stack objects on this fake
comment|// stack instead of the real stack. The fake stack is not really a stack but
comment|// a fast malloc-like allocator so that when a function exits the fake stack
comment|// is not popped but remains there for quite some time until gets used again.
comment|// So, we poison the objects on the fake stack when function returns.
comment|// It helps us find use-after-return bugs.
comment|//
comment|// The FakeStack objects is allocated by a single mmap call and has no other
comment|// pointers. The size of the fake stack depends on the actual thread stack size
comment|// and thus can not be a constant.
comment|// stack_size is a power of two greater or equal to the thread's stack size;
comment|// we store it as its logarithm (stack_size_log).
comment|// FakeStack has kNumberOfSizeClasses (11) size classes, each size class
comment|// is a power of two, starting from 64 bytes. Each size class occupies
comment|// stack_size bytes and thus can allocate
comment|// NumberOfFrames=(stack_size/BytesInSizeClass) fake frames (also a power of 2).
comment|// For each size class we have NumberOfFrames allocation flags,
comment|// each flag indicates whether the given frame is currently allocated.
comment|// All flags for size classes 0 .. 10 are stored in a single contiguous region
comment|// followed by another contiguous region which contains the actual memory for
comment|// size classes. The addresses are computed by GetFlags and GetFrame without
comment|// any memory accesses solely based on 'this' and stack_size_log.
comment|// Allocate() flips the appropriate allocation flag atomically, thus achieving
comment|// async-signal safety.
comment|// This allocator does not have quarantine per se, but it tries to allocate the
comment|// frames in round robin fasion to maximize the delay between a deallocation
comment|// and the next allocation.
name|class
name|FakeStack
block|{
specifier|static
specifier|const
name|uptr
name|kMinStackFrameSizeLog
init|=
literal|6
decl_stmt|;
comment|// Min frame is 64B.
specifier|static
specifier|const
name|uptr
name|kMaxStackFrameSizeLog
init|=
literal|16
decl_stmt|;
comment|// Max stack frame is 64K.
name|public
label|:
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
comment|// CTOR: create the FakeStack as a single mmap-ed object.
specifier|static
name|FakeStack
modifier|*
name|Create
parameter_list|(
name|uptr
name|stack_size_log
parameter_list|)
function_decl|;
name|void
name|Destroy
parameter_list|(
name|int
name|tid
parameter_list|)
function_decl|;
comment|// stack_size_log is at least 15 (stack_size>= 32K).
specifier|static
name|uptr
name|SizeRequiredForFlags
parameter_list|(
name|uptr
name|stack_size_log
parameter_list|)
block|{
return|return
literal|1UL
operator|<<
operator|(
name|stack_size_log
operator|+
literal|1
operator|-
name|kMinStackFrameSizeLog
operator|)
return|;
block|}
comment|// Each size class occupies stack_size bytes.
specifier|static
name|uptr
name|SizeRequiredForFrames
parameter_list|(
name|uptr
name|stack_size_log
parameter_list|)
block|{
return|return
operator|(
literal|1ULL
operator|<<
name|stack_size_log
operator|)
operator|*
name|kNumberOfSizeClasses
return|;
block|}
comment|// Number of bytes requires for the whole object.
specifier|static
name|uptr
name|RequiredSize
parameter_list|(
name|uptr
name|stack_size_log
parameter_list|)
block|{
return|return
name|kFlagsOffset
operator|+
name|SizeRequiredForFlags
argument_list|(
name|stack_size_log
argument_list|)
operator|+
name|SizeRequiredForFrames
argument_list|(
name|stack_size_log
argument_list|)
return|;
block|}
comment|// Offset of the given flag from the first flag.
comment|// The flags for class 0 begin at offset  000000000
comment|// The flags for class 1 begin at offset  100000000
comment|// ....................2................  110000000
comment|// ....................3................  111000000
comment|// and so on.
specifier|static
name|uptr
name|FlagsOffset
parameter_list|(
name|uptr
name|stack_size_log
parameter_list|,
name|uptr
name|class_id
parameter_list|)
block|{
name|uptr
name|t
init|=
name|kNumberOfSizeClasses
operator|-
literal|1
operator|-
name|class_id
decl_stmt|;
specifier|const
name|uptr
name|all_ones
init|=
operator|(
literal|1
operator|<<
operator|(
name|kNumberOfSizeClasses
operator|-
literal|1
operator|)
operator|)
operator|-
literal|1
decl_stmt|;
return|return
operator|(
operator|(
name|all_ones
operator|>>
name|t
operator|)
operator|<<
name|t
operator|)
operator|<<
operator|(
name|stack_size_log
operator|-
literal|15
operator|)
return|;
block|}
specifier|static
name|uptr
name|NumberOfFrames
parameter_list|(
name|uptr
name|stack_size_log
parameter_list|,
name|uptr
name|class_id
parameter_list|)
block|{
return|return
literal|1UL
operator|<<
operator|(
name|stack_size_log
operator|-
name|kMinStackFrameSizeLog
operator|-
name|class_id
operator|)
return|;
block|}
comment|// Divide n by the numbe of frames in size class.
specifier|static
name|uptr
name|ModuloNumberOfFrames
parameter_list|(
name|uptr
name|stack_size_log
parameter_list|,
name|uptr
name|class_id
parameter_list|,
name|uptr
name|n
parameter_list|)
block|{
return|return
name|n
operator|&
operator|(
name|NumberOfFrames
argument_list|(
name|stack_size_log
argument_list|,
name|class_id
argument_list|)
operator|-
literal|1
operator|)
return|;
block|}
comment|// The the pointer to the flags of the given class_id.
name|u8
modifier|*
name|GetFlags
parameter_list|(
name|uptr
name|stack_size_log
parameter_list|,
name|uptr
name|class_id
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|u8
operator|*
operator|>
operator|(
name|this
operator|)
operator|+
name|kFlagsOffset
operator|+
name|FlagsOffset
argument_list|(
name|stack_size_log
argument_list|,
name|class_id
argument_list|)
return|;
block|}
comment|// Get frame by class_id and pos.
name|u8
modifier|*
name|GetFrame
parameter_list|(
name|uptr
name|stack_size_log
parameter_list|,
name|uptr
name|class_id
parameter_list|,
name|uptr
name|pos
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|u8
operator|*
operator|>
operator|(
name|this
operator|)
operator|+
name|kFlagsOffset
operator|+
name|SizeRequiredForFlags
argument_list|(
name|stack_size_log
argument_list|)
operator|+
operator|(
literal|1
operator|<<
name|stack_size_log
operator|)
operator|*
name|class_id
operator|+
name|BytesInSizeClass
argument_list|(
name|class_id
argument_list|)
operator|*
name|pos
return|;
block|}
comment|// Allocate the fake frame.
name|FakeFrame
modifier|*
name|Allocate
parameter_list|(
name|uptr
name|stack_size_log
parameter_list|,
name|uptr
name|class_id
parameter_list|,
name|uptr
name|real_stack
parameter_list|)
function_decl|;
comment|// Deallocate the fake frame: read the saved flag address and write 0 there.
specifier|static
name|void
name|Deallocate
parameter_list|(
name|uptr
name|x
parameter_list|,
name|uptr
name|class_id
parameter_list|)
block|{
operator|*
operator|*
name|SavedFlagPtr
argument_list|(
name|x
argument_list|,
name|class_id
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
comment|// Poison the entire FakeStack's shadow with the magic value.
name|void
name|PoisonAll
parameter_list|(
name|u8
name|magic
parameter_list|)
function_decl|;
comment|// Return the beginning of the FakeFrame or 0 if the address is not ours.
name|uptr
name|AddrIsInFakeStack
parameter_list|(
name|uptr
name|addr
parameter_list|,
name|uptr
modifier|*
name|frame_beg
parameter_list|,
name|uptr
modifier|*
name|frame_end
parameter_list|)
function_decl|;
name|USED
name|uptr
name|AddrIsInFakeStack
parameter_list|(
name|uptr
name|addr
parameter_list|)
block|{
name|uptr
name|t1
decl_stmt|,
name|t2
decl_stmt|;
return|return
name|AddrIsInFakeStack
argument_list|(
name|addr
argument_list|,
operator|&
name|t1
argument_list|,
operator|&
name|t2
argument_list|)
return|;
block|}
comment|// Number of bytes in a fake frame of this size class.
specifier|static
name|uptr
name|BytesInSizeClass
parameter_list|(
name|uptr
name|class_id
parameter_list|)
block|{
return|return
literal|1UL
operator|<<
operator|(
name|class_id
operator|+
name|kMinStackFrameSizeLog
operator|)
return|;
block|}
comment|// The fake frame is guaranteed to have a right redzone.
comment|// We use the last word of that redzone to store the address of the flag
comment|// that corresponds to the current frame to make faster deallocation.
specifier|static
name|u8
modifier|*
modifier|*
name|SavedFlagPtr
parameter_list|(
name|uptr
name|x
parameter_list|,
name|uptr
name|class_id
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|u8
operator|*
operator|*
operator|>
operator|(
name|x
operator|+
name|BytesInSizeClass
argument_list|(
name|class_id
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|x
argument_list|)
operator|)
return|;
block|}
name|uptr
name|stack_size_log
argument_list|()
specifier|const
block|{
return|return
name|stack_size_log_
return|;
block|}
name|void
name|HandleNoReturn
parameter_list|()
function_decl|;
name|void
name|GC
parameter_list|(
name|uptr
name|real_stack
parameter_list|)
function_decl|;
name|void
name|ForEachFakeFrame
parameter_list|(
name|RangeIteratorCallback
name|callback
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|private
label|:
name|FakeStack
argument_list|()
block|{ }
specifier|static
specifier|const
name|uptr
name|kFlagsOffset
init|=
literal|4096
decl_stmt|;
comment|// This is were the flags begin.
comment|// Must match the number of uses of DEFINE_STACK_MALLOC_FREE_WITH_CLASS_ID
name|COMPILER_CHECK
argument_list|(
name|kNumberOfSizeClasses
operator|==
literal|11
argument_list|)
expr_stmt|;
specifier|static
specifier|const
name|uptr
name|kMaxStackMallocSize
init|=
literal|1
operator|<<
name|kMaxStackFrameSizeLog
decl_stmt|;
name|uptr
name|hint_position_
index|[
name|kNumberOfSizeClasses
index|]
decl_stmt|;
name|uptr
name|stack_size_log_
decl_stmt|;
comment|// a bit is set if something was allocated from the corresponding size class.
name|bool
name|needs_gc_
decl_stmt|;
block|}
empty_stmt|;
name|FakeStack
modifier|*
name|GetTLSFakeStack
parameter_list|()
function_decl|;
name|void
name|SetTLSFakeStack
parameter_list|(
name|FakeStack
modifier|*
name|fs
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
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

