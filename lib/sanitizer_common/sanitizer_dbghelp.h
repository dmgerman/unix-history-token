begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_dbghelp.h ------------------------------*- C++ -*-===//
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
comment|// Wrappers for lazy loaded dbghelp.dll. Provides function pointers and a
end_comment

begin_comment
comment|// callback to initialize them.
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
name|SANITIZER_SYMBOLIZER_WIN_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_SYMBOLIZER_WIN_H
end_define

begin_if
if|#
directive|if
operator|!
name|SANITIZER_WINDOWS
end_if

begin_error
error|#
directive|error
literal|"sanitizer_dbghelp.h is a Windows-only header"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WIN32_LEAN_AND_MEAN
end_define

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|<dbghelp.h>
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
extern|extern decltype(::StackWalk64
block|)
modifier|*
name|StackWalk64
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern decltype(::SymCleanup
end_extern

begin_expr_stmt
unit|)
operator|*
name|SymCleanup
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern decltype(::SymFromAddr
end_extern

begin_expr_stmt
unit|)
operator|*
name|SymFromAddr
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern decltype(::SymFunctionTableAccess64
end_extern

begin_expr_stmt
unit|)
operator|*
name|SymFunctionTableAccess64
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern decltype(::SymGetLineFromAddr64
end_extern

begin_expr_stmt
unit|)
operator|*
name|SymGetLineFromAddr64
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern decltype(::SymGetModuleBase64
end_extern

begin_expr_stmt
unit|)
operator|*
name|SymGetModuleBase64
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern decltype(::SymGetSearchPathW
end_extern

begin_expr_stmt
unit|)
operator|*
name|SymGetSearchPathW
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern decltype(::SymInitialize
end_extern

begin_expr_stmt
unit|)
operator|*
name|SymInitialize
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern decltype(::SymSetOptions
end_extern

begin_expr_stmt
unit|)
operator|*
name|SymSetOptions
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern decltype(::SymSetSearchPathW
end_extern

begin_expr_stmt
unit|)
operator|*
name|SymSetSearchPathW
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern decltype(::UnDecorateSymbolName
end_extern

begin_expr_stmt
unit|)
operator|*
name|UnDecorateSymbolName
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_SYMBOLIZER_WIN_H
end_comment

end_unit

