begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- CGCXXABI.h - Interface to C++ ABIs -------------------*- C++ -*-===//
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
comment|// This provides an abstract class for C++ code generation. Concrete subclasses
end_comment

begin_comment
comment|// of this implement code generation for specific C++ ABIs.
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
name|CLANG_CODEGEN_CXXABI_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CXXABI_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenModule
decl_stmt|;
name|class
name|MangleContext
decl_stmt|;
comment|/// Implements C++ ABI-specific code generation functions.
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
comment|/// Gets the mangle context.
name|virtual
name|MangleContext
modifier|&
name|getMangleContext
parameter_list|()
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|/// Creates an instance of a C++ ABI class.
name|CXXABI
modifier|*
name|CreateItaniumCXXABI
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

