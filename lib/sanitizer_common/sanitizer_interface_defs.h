begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_interface_defs.h -----------------------------*- C++ -*-===//
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
comment|// This file is shared between AddressSanitizer and ThreadSanitizer.
end_comment

begin_comment
comment|// It contains basic macro and types.
end_comment

begin_comment
comment|// NOTE: This file may be included into user code.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_INTERFACE_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_INTERFACE_DEFS_H
end_define

begin_comment
comment|// ----------- ATTENTION -------------
end_comment

begin_comment
comment|// This header should NOT include any other headers to avoid portability issues.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_comment
comment|// FIXME find out what we need on Windows. __declspec(dllexport) ?
end_comment

begin_define
define|#
directive|define
name|SANITIZER_INTERFACE_ATTRIBUTE
end_define

begin_define
define|#
directive|define
name|SANITIZER_WEAK_ATTRIBUTE
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SANITIZER_GO
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SANITIZER_INTERFACE_ATTRIBUTE
end_define

begin_define
define|#
directive|define
name|SANITIZER_WEAK_ATTRIBUTE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_INTERFACE_ATTRIBUTE
value|__attribute__((visibility("default")))
end_define

begin_define
define|#
directive|define
name|SANITIZER_WEAK_ATTRIBUTE
value|__attribute__((weak))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __has_feature
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__has_feature
argument_list|)
end_if

begin_define
define|#
directive|define
name|__has_feature
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// For portability reasons we do not include stddef.h, stdint.h or any other
end_comment

begin_comment
comment|// system header, but we do need some basic types that are not defined
end_comment

begin_comment
comment|// in a portable way by the language itself.
end_comment

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
typedef|typedef
name|unsigned
name|long
name|uptr
typedef|;
comment|// NOLINT
typedef|typedef
name|signed
name|long
name|sptr
typedef|;
comment|// NOLINT
typedef|typedef
name|unsigned
name|char
name|u8
typedef|;
typedef|typedef
name|unsigned
name|short
name|u16
typedef|;
comment|// NOLINT
typedef|typedef
name|unsigned
name|int
name|u32
typedef|;
typedef|typedef
name|unsigned
name|long
name|long
name|u64
typedef|;
comment|// NOLINT
typedef|typedef
name|signed
name|char
name|s8
typedef|;
typedef|typedef
name|signed
name|short
name|s16
typedef|;
comment|// NOLINT
typedef|typedef
name|signed
name|int
name|s32
typedef|;
typedef|typedef
name|signed
name|long
name|long
name|s64
typedef|;
comment|// NOLINT
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
comment|// SANITIZER_INTERFACE_DEFS_H
end_comment

end_unit

