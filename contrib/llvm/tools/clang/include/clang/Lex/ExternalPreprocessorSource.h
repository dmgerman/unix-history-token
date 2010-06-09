begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ExternalPreprocessorSource.h - Abstract Macro Interface --*- C++ -*-===//
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
comment|//  This file defines the ExternalPreprocessorSource interface, which enables
end_comment

begin_comment
comment|//  construction of macro definitions from some external source.
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
name|LLVM_CLANG_LEX_EXTERNAL_PREPROCESSOR_SOURCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_EXTERNAL_PREPROCESSOR_SOURCE_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Abstract interface for external sources of preprocessor
comment|/// information.
comment|///
comment|/// This abstract class allows an external sources (such as the \c PCHReader)
comment|/// to provide additional macro definitions.
name|class
name|ExternalPreprocessorSource
block|{
name|public
label|:
name|virtual
operator|~
name|ExternalPreprocessorSource
argument_list|()
expr_stmt|;
comment|/// \brief Read the set of macros defined by this external macro source.
name|virtual
name|void
name|ReadDefinedMacros
parameter_list|()
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_LEX_EXTERNAL_PREPROCESSOR_SOURCE_H
end_comment

end_unit

