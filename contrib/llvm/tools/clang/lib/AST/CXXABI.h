begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- CXXABI.h - Interface to C++ ABIs ---------------------*- C++ -*-===//
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
comment|// This provides an abstract class for C++ AST support. Concrete
end_comment

begin_comment
comment|// subclasses of this implement AST support for specific C++ ABIs.
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
name|LLVM_CLANG_AST_CXXABI_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_CXXABI_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|MemberPointerType
decl_stmt|;
comment|/// Implements C++ ABI-specific semantic analysis functions.
name|class
name|CXXABI
block|{
name|public
label|:
name|virtual
operator|~
name|CXXABI
argument_list|()
expr_stmt|;
comment|/// Returns the size of a member pointer in multiples of the target
comment|/// pointer size.
name|virtual
name|unsigned
name|getMemberPointerSize
argument_list|(
specifier|const
name|MemberPointerType
operator|*
name|MPT
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|/// Creates an instance of a C++ ABI class.
name|CXXABI
modifier|*
name|CreateARMCXXABI
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
name|CXXABI
modifier|*
name|CreateItaniumCXXABI
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
name|CXXABI
modifier|*
name|CreateMicrosoftCXXABI
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

