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
name|LLVM_CLANG_LEX_EXTERNALPREPROCESSORSOURCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_EXTERNALPREPROCESSORSOURCE_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|Module
decl_stmt|;
comment|/// \brief Abstract interface for external sources of preprocessor
comment|/// information.
comment|///
comment|/// This abstract class allows an external sources (such as the \c ASTReader)
comment|/// to provide additional preprocessing information.
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
comment|/// \brief Update an out-of-date identifier.
name|virtual
name|void
name|updateOutOfDateIdentifier
parameter_list|(
name|IdentifierInfo
modifier|&
name|II
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Return the identifier associated with the given ID number.
comment|///
comment|/// The ID 0 is associated with the NULL identifier.
name|virtual
name|IdentifierInfo
modifier|*
name|GetIdentifier
parameter_list|(
name|unsigned
name|ID
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Map a module ID to a module.
name|virtual
name|Module
modifier|*
name|getModule
parameter_list|(
name|unsigned
name|ModuleID
parameter_list|)
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

end_unit

