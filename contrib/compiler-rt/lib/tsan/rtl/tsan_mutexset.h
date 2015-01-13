begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_mutexset.h -----------------------------------------*- C++ -*-===//
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
comment|// This file is a part of ThreadSanitizer (TSan), a race detector.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MutexSet holds the set of mutexes currently held by a thread.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_MUTEXSET_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_MUTEXSET_H
end_define

begin_include
include|#
directive|include
file|"tsan_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__tsan
block|{
name|class
name|MutexSet
block|{
name|public
label|:
comment|// Holds limited number of mutexes.
comment|// The oldest mutexes are discarded on overflow.
specifier|static
specifier|const
name|uptr
name|kMaxSize
init|=
literal|16
decl_stmt|;
struct|struct
name|Desc
block|{
name|u64
name|id
decl_stmt|;
name|u64
name|epoch
decl_stmt|;
name|int
name|count
decl_stmt|;
name|bool
name|write
decl_stmt|;
block|}
struct|;
name|MutexSet
argument_list|()
expr_stmt|;
comment|// The 'id' is obtained from SyncVar::GetId().
name|void
name|Add
parameter_list|(
name|u64
name|id
parameter_list|,
name|bool
name|write
parameter_list|,
name|u64
name|epoch
parameter_list|)
function_decl|;
name|void
name|Del
parameter_list|(
name|u64
name|id
parameter_list|,
name|bool
name|write
parameter_list|)
function_decl|;
name|void
name|Remove
parameter_list|(
name|u64
name|id
parameter_list|)
function_decl|;
comment|// Removes the mutex completely (if it's destroyed).
name|uptr
name|Size
argument_list|()
specifier|const
expr_stmt|;
name|Desc
name|Get
argument_list|(
name|uptr
name|i
argument_list|)
decl|const
decl_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|MutexSet
operator|&
name|other
operator|)
block|{
name|internal_memcpy
argument_list|(
name|this
argument_list|,
operator|&
name|other
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|this
argument_list|)
argument_list|)
block|;   }
name|private
operator|:
ifndef|#
directive|ifndef
name|SANITIZER_GO
name|uptr
name|size_
decl_stmt|;
name|Desc
name|descs_
index|[
name|kMaxSize
index|]
decl_stmt|;
endif|#
directive|endif
name|void
name|RemovePos
parameter_list|(
name|uptr
name|i
parameter_list|)
function_decl|;
name|MutexSet
argument_list|(
specifier|const
name|MutexSet
operator|&
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|// Go does not have mutexes, so do not spend memory and time.
comment|// (Go sync.Mutex is actually a semaphore -- can be unlocked
comment|// in different goroutine).
ifdef|#
directive|ifdef
name|SANITIZER_GO
name|MutexSet
operator|::
name|MutexSet
argument_list|()
block|{}
name|void
name|MutexSet
operator|::
name|Add
argument_list|(
argument|u64 id
argument_list|,
argument|bool write
argument_list|,
argument|u64 epoch
argument_list|)
block|{}
name|void
name|MutexSet
operator|::
name|Del
argument_list|(
argument|u64 id
argument_list|,
argument|bool write
argument_list|)
block|{}
name|void
name|MutexSet
operator|::
name|Remove
argument_list|(
argument|u64 id
argument_list|)
block|{}
name|void
name|MutexSet
operator|::
name|RemovePos
argument_list|(
argument|uptr i
argument_list|)
block|{}
name|uptr
name|MutexSet
operator|::
name|Size
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|MutexSet
operator|::
name|Desc
name|MutexSet
operator|::
name|Get
argument_list|(
argument|uptr i
argument_list|)
specifier|const
block|{
return|return
name|Desc
argument_list|()
return|;
block|}
endif|#
directive|endif
block|}
end_decl_stmt

begin_comment
comment|// namespace __tsan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TSAN_MUTEXSET_H
end_comment

end_unit

