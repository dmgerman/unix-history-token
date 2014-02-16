begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CapturedStmt.h - Types for CapturedStmts ---------------*- C++ -*-===//
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
name|LLVM_CLANG_BASIC_CAPTUREDSTMT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_CAPTUREDSTMT_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief The different kinds of captured statement.
enum|enum
name|CapturedRegionKind
block|{
name|CR_Default
block|,
name|CR_OpenMP
block|}
enum|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_BASIC_CAPTUREDSTMT_H
end_comment

end_unit

