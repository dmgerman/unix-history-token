begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_allocator_checks.h ----------------------------*- C++ -*-===//
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
comment|// Various checks shared between ThreadSanitizer, MemorySanitizer, etc. memory
end_comment

begin_comment
comment|// allocators.
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
name|SANITIZER_ALLOCATOR_CHECKS_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_ALLOCATOR_CHECKS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_errno.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_platform.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
comment|// A common errno setting logic shared by almost all sanitizer allocator APIs.
name|INLINE
name|void
modifier|*
name|SetErrnoOnNull
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
if|if
condition|(
name|UNLIKELY
argument_list|(
operator|!
name|ptr
argument_list|)
condition|)
name|errno
operator|=
name|errno_ENOMEM
expr_stmt|;
return|return
name|ptr
return|;
block|}
comment|// In case of the check failure, the caller of the following Check... functions
comment|// should "return POLICY::OnBadRequest();" where POLICY is the current allocator
comment|// failure handling policy.
comment|// Checks aligned_alloc() parameters, verifies that the alignment is a power of
comment|// two and that the size is a multiple of alignment for POSIX implementation,
comment|// and a bit relaxed requirement for non-POSIX ones, that the size is a multiple
comment|// of alignment.
name|INLINE
name|bool
name|CheckAlignedAllocAlignmentAndSize
parameter_list|(
name|uptr
name|alignment
parameter_list|,
name|uptr
name|size
parameter_list|)
block|{
if|#
directive|if
name|SANITIZER_POSIX
return|return
name|IsPowerOfTwo
argument_list|(
name|alignment
argument_list|)
operator|&&
operator|(
name|size
operator|&
operator|(
name|alignment
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
return|;
else|#
directive|else
return|return
name|size
operator|%
name|alignment
operator|==
literal|0
return|;
endif|#
directive|endif
block|}
comment|// Checks posix_memalign() parameters, verifies that alignment is a power of two
comment|// and a multiple of sizeof(void *).
name|INLINE
name|bool
name|CheckPosixMemalignAlignment
parameter_list|(
name|uptr
name|alignment
parameter_list|)
block|{
return|return
name|IsPowerOfTwo
argument_list|(
name|alignment
argument_list|)
operator|&&
operator|(
name|alignment
operator|%
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|)
operator|==
literal|0
return|;
comment|// NOLINT
block|}
comment|// Returns true if calloc(size, n) call overflows on size*n calculation.
name|INLINE
name|bool
name|CheckForCallocOverflow
parameter_list|(
name|uptr
name|size
parameter_list|,
name|uptr
name|n
parameter_list|)
block|{
if|if
condition|(
operator|!
name|size
condition|)
return|return
name|false
return|;
name|uptr
name|max
init|=
operator|(
name|uptr
operator|)
operator|-
literal|1L
decl_stmt|;
return|return
operator|(
name|max
operator|/
name|size
operator|)
operator|<
name|n
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_ALLOCATOR_CHECKS_H
end_comment

end_unit

