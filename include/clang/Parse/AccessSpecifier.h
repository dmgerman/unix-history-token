begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- AccessSpecifier.h - C++ Access Specifiers -*- C++ -*-===//
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
comment|// This file defines interfaces used for C++ access specifiers.
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
name|LLVM_CLANG_PARSE_ACCESS_SPECIFIER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_PARSE_ACCESS_SPECIFIER_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// AccessSpecifier - A C++ access specifier (none, public, private,
comment|/// protected).
enum|enum
name|AccessSpecifier
block|{
name|AS_none
block|,
name|AS_public
block|,
name|AS_protected
block|,
name|AS_private
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

end_unit

