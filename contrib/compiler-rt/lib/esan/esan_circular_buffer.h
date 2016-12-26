begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- esan_circular_buffer.h ----------------------------------*- C++ -*-===//
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
comment|// This file is a part of EfficiencySanitizer, a family of performance tuners.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Circular buffer data structure.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_common.h"
end_include

begin_decl_stmt
name|namespace
name|__esan
block|{
comment|// A circular buffer for POD data whose memory is allocated using mmap.
comment|// There are two usage models: one is to use initialize/free (for global
comment|// instances) and the other is to use placement new with the
comment|// constructor and to call the destructor or free (they are equivalent).
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|CircularBuffer
block|{
name|public
operator|:
comment|// To support global instances we cannot initialize any field in the
comment|// default constructor.
name|explicit
name|CircularBuffer
argument_list|()
block|{}
name|CircularBuffer
argument_list|(
argument|uptr BufferCapacity
argument_list|)
block|{
name|initialize
argument_list|(
name|BufferCapacity
argument_list|)
block|;
name|WasConstructed
operator|=
name|true
block|;   }
operator|~
name|CircularBuffer
argument_list|()
block|{
if|if
condition|(
name|WasConstructed
condition|)
comment|// Else caller will call free() explicitly.
name|free
argument_list|()
expr_stmt|;
block|}
name|void
name|initialize
argument_list|(
argument|uptr BufferCapacity
argument_list|)
block|{
name|Capacity
operator|=
name|BufferCapacity
block|;
comment|// MmapOrDie rounds up to the page size for us.
name|Data
operator|=
operator|(
name|T
operator|*
operator|)
name|MmapOrDie
argument_list|(
name|Capacity
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
literal|"CircularBuffer"
argument_list|)
block|;
name|StartIdx
operator|=
literal|0
block|;
name|Count
operator|=
literal|0
block|;
name|WasConstructed
operator|=
name|false
block|;   }
name|void
name|free
argument_list|()
block|{
name|UnmapOrDie
argument_list|(
name|Data
argument_list|,
name|Capacity
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|;   }
name|T
operator|&
name|operator
index|[]
operator|(
name|uptr
name|Idx
operator|)
block|{
name|CHECK_LT
argument_list|(
name|Idx
argument_list|,
name|Count
argument_list|)
block|;
name|uptr
name|ArrayIdx
operator|=
operator|(
name|StartIdx
operator|+
name|Idx
operator|)
operator|%
name|Capacity
block|;
return|return
name|Data
index|[
name|ArrayIdx
index|]
return|;
block|}
specifier|const
name|T
operator|&
name|operator
index|[]
operator|(
name|uptr
name|Idx
operator|)
specifier|const
block|{
name|CHECK_LT
argument_list|(
name|Idx
argument_list|,
name|Count
argument_list|)
block|;
name|uptr
name|ArrayIdx
operator|=
operator|(
name|StartIdx
operator|+
name|Idx
operator|)
operator|%
name|Capacity
block|;
return|return
name|Data
index|[
name|ArrayIdx
index|]
return|;
block|}
name|void
name|push_back
argument_list|(
argument|const T&Item
argument_list|)
block|{
name|CHECK_GT
argument_list|(
name|Capacity
argument_list|,
literal|0
argument_list|)
block|;
name|uptr
name|ArrayIdx
operator|=
operator|(
name|StartIdx
operator|+
name|Count
operator|)
operator|%
name|Capacity
block|;
name|Data
index|[
name|ArrayIdx
index|]
operator|=
name|Item
block|;
if|if
condition|(
name|Count
operator|<
name|Capacity
condition|)
operator|++
name|Count
expr_stmt|;
else|else
name|StartIdx
operator|=
operator|(
name|StartIdx
operator|+
literal|1
operator|)
operator|%
name|Capacity
expr_stmt|;
block|}
name|T
operator|&
name|back
argument_list|()
block|{
name|CHECK_GT
argument_list|(
name|Count
argument_list|,
literal|0
argument_list|)
block|;
name|uptr
name|ArrayIdx
operator|=
operator|(
name|StartIdx
operator|+
name|Count
operator|-
literal|1
operator|)
operator|%
name|Capacity
block|;
return|return
name|Data
index|[
name|ArrayIdx
index|]
return|;
block|}
name|void
name|pop_back
argument_list|()
block|{
name|CHECK_GT
argument_list|(
name|Count
argument_list|,
literal|0
argument_list|)
block|;
operator|--
name|Count
block|;   }
name|uptr
name|size
argument_list|()
specifier|const
block|{
return|return
name|Count
return|;
block|}
name|void
name|clear
argument_list|()
block|{
name|StartIdx
operator|=
literal|0
block|;
name|Count
operator|=
literal|0
block|;   }
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|==
literal|0
return|;
block|}
name|private
operator|:
name|CircularBuffer
argument_list|(
specifier|const
name|CircularBuffer
operator|&
argument_list|)
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|CircularBuffer
operator|&
operator|)
block|;
name|bool
name|WasConstructed
block|;
name|T
operator|*
name|Data
block|;
name|uptr
name|Capacity
block|;
name|uptr
name|StartIdx
block|;
name|uptr
name|Count
block|; }
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __esan
end_comment

end_unit

