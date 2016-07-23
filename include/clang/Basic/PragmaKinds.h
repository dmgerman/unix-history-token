begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PragmaKinds.h - #pragma comment() kinds  ---------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_BASIC_PRAGMA_KINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_PRAGMA_KINDS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
enum|enum
name|PragmaMSCommentKind
block|{
name|PCK_Unknown
block|,
name|PCK_Linker
block|,
comment|// #pragma comment(linker, ...)
name|PCK_Lib
block|,
comment|// #pragma comment(lib, ...)
name|PCK_Compiler
block|,
comment|// #pragma comment(compiler, ...)
name|PCK_ExeStr
block|,
comment|// #pragma comment(exestr, ...)
name|PCK_User
comment|// #pragma comment(user, ...)
block|}
enum|;
enum|enum
name|PragmaMSStructKind
block|{
name|PMSST_OFF
block|,
comment|// #pragms ms_struct off
name|PMSST_ON
comment|// #pragms ms_struct on
block|}
enum|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

