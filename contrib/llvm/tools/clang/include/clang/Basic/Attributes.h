begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Attributes.h - Attributes header -----------------------*- C++ -*-===//
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
name|LLVM_CLANG_BASIC_ATTRIBUTES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_ATTRIBUTES_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TargetInfo.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|IdentifierInfo
decl_stmt|;
name|enum
name|class
name|AttrSyntax
block|{
comment|/// Is the identifier known as a GNU-style attribute?
name|GNU
operator|,
comment|/// Is the identifier known as a __declspec-style attribute?
name|Declspec
operator|,
comment|// Is the identifier known as a C++-style attribute?
name|CXX
operator|,
comment|// Is the identifier known as a pragma attribute?
name|Pragma
block|}
empty_stmt|;
comment|/// \brief Return the version number associated with the attribute if we
comment|/// recognize and implement the attribute specified by the given information.
name|int
name|hasAttribute
parameter_list|(
name|AttrSyntax
name|Syntax
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|*
name|Scope
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|*
name|Attr
parameter_list|,
specifier|const
name|TargetInfo
modifier|&
name|Target
parameter_list|,
specifier|const
name|LangOptions
modifier|&
name|LangOpts
parameter_list|)
function_decl|;
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
comment|// LLVM_CLANG_BASIC_ATTRIBUTES_H
end_comment

end_unit

