begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer/common_interface_defs.h -----------------------*- C++ -*-===//
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
name|SANITIZER_COMMON_INTERFACE_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_COMMON_INTERFACE_DEFS_H
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

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_define
define|#
directive|define
name|SANITIZER_SUPPORTS_WEAK_HOOKS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_SUPPORTS_WEAK_HOOKS
value|0
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
if|#
directive|if
name|defined
argument_list|(
name|_WIN64
argument_list|)
comment|// 64-bit Windows uses LLP64 data model.
typedef|typedef
name|unsigned
name|long
name|long
name|uptr
typedef|;
comment|// NOLINT
typedef|typedef
name|signed
name|long
name|long
name|sptr
typedef|;
comment|// NOLINT
else|#
directive|else
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
endif|#
directive|endif
comment|// defined(_WIN64)
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
comment|// Since x32 uses ILP32 data model in 64-bit hardware mode,  we must use
comment|// 64-bit pointer to unwind stack frame.
typedef|typedef
name|unsigned
name|long
name|long
name|uhwptr
typedef|;
comment|// NOLINT
else|#
directive|else
typedef|typedef
name|uptr
name|uhwptr
typedef|;
comment|// NOLINT
endif|#
directive|endif
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

begin_extern
extern|extern
literal|"C"
block|{
comment|// Tell the tools to write their reports to "path.<pid>" instead of stderr.
name|void
name|__sanitizer_set_report_path
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
comment|// Tell the tools to write their reports to given file descriptor instead of
comment|// stderr.
name|void
name|__sanitizer_set_report_fd
argument_list|(
name|int
name|fd
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
comment|// Notify the tools that the sandbox is going to be turned on. The reserved
comment|// parameter will be used in the future to hold a structure with functions
comment|// that the tools may call to bypass the sandbox.
name|void
name|__sanitizer_sandbox_on_notify
argument_list|(
name|void
operator|*
name|reserved
argument_list|)
name|SANITIZER_WEAK_ATTRIBUTE
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_COMMON_INTERFACE_DEFS_H
end_comment

end_unit

