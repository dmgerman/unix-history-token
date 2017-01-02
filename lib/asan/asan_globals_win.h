begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_globals_win.h --------------------------------------*- C++ -*-===//
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
comment|// Interface to the Windows-specific global management code. Separated into a
end_comment

begin_comment
comment|// standalone header to allow inclusion from asan_win_dynamic_runtime_thunk,
end_comment

begin_comment
comment|// which defines symbols that clash with other sanitizer headers.
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
name|ASAN_GLOBALS_WIN_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_GLOBALS_WIN_H
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"this file is Windows-only, and uses MSVC pragmas"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN64
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_SYM_PREFIX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_SYM_PREFIX
value|"_"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Use this macro to force linking asan_globals_win.cc into the DSO.
end_comment

begin_define
define|#
directive|define
name|ASAN_LINK_GLOBALS_WIN
parameter_list|()
define|\
value|__pragma(                     \       comment(linker, "/include:" SANITIZER_SYM_PREFIX "__asan_dso_reg_hook"))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_GLOBALS_WIN_H
end_comment

end_unit

