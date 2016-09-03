begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ubsan_platform.h ----------------------------------------*- C++ -*-===//
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
comment|// Defines the platforms which UBSan is supported at.
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
name|UBSAN_PLATFORM_H
end_ifndef

begin_define
define|#
directive|define
name|UBSAN_PLATFORM_H
end_define

begin_comment
comment|// Other platforms should be easy to add, and probably work as-is.
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|)
operator|&&
expr|\
operator|(
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__aarch64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__s390__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|CAN_SANITIZE_UB
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_elif

begin_define
define|#
directive|define
name|CAN_SANITIZE_UB
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CAN_SANITIZE_UB
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

