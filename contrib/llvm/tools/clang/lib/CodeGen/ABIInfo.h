begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- ABIInfo.h - ABI information access& encapsulation ---*- C++ -*-===//
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
name|CLANG_CODEGEN_ABIINFO_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_ABIINFO_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CGCXXABI
decl_stmt|;
name|class
name|CGFunctionInfo
decl_stmt|;
name|class
name|CodeGenFunction
decl_stmt|;
name|class
name|CodeGenTypes
decl_stmt|;
block|}
comment|// FIXME: All of this stuff should be part of the target interface
comment|// somehow. It is currently here because it is not clear how to factor
comment|// the targets to support this, since the Targets currently live in a
comment|// layer below types n'stuff.
comment|/// ABIInfo - Target specific hooks for defining how a type should be
comment|/// passed or returned from functions.
name|class
name|ABIInfo
block|{
name|public
label|:
name|CodeGen
operator|::
name|CodeGenTypes
operator|&
name|CGT
expr_stmt|;
name|protected
label|:
name|llvm
operator|::
name|CallingConv
operator|::
name|ID
name|RuntimeCC
expr_stmt|;
name|public
label|:
name|ABIInfo
argument_list|(
name|CodeGen
operator|::
name|CodeGenTypes
operator|&
name|cgt
argument_list|)
operator|:
name|CGT
argument_list|(
name|cgt
argument_list|)
operator|,
name|RuntimeCC
argument_list|(
argument|llvm::CallingConv::C
argument_list|)
block|{}
name|virtual
operator|~
name|ABIInfo
argument_list|()
expr_stmt|;
name|CodeGen
operator|::
name|CGCXXABI
operator|&
name|getCXXABI
argument_list|()
specifier|const
expr_stmt|;
name|ASTContext
operator|&
name|getContext
argument_list|()
specifier|const
expr_stmt|;
name|llvm
operator|::
name|LLVMContext
operator|&
name|getVMContext
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|llvm
operator|::
name|DataLayout
operator|&
name|getDataLayout
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|TargetInfo
operator|&
name|getTarget
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return the calling convention to use for system runtime
comment|/// functions.
name|llvm
operator|::
name|CallingConv
operator|::
name|ID
name|getRuntimeCC
argument_list|()
specifier|const
block|{
return|return
name|RuntimeCC
return|;
block|}
name|virtual
name|void
name|computeInfo
argument_list|(
name|CodeGen
operator|::
name|CGFunctionInfo
operator|&
name|FI
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// EmitVAArg - Emit the target dependent code to load a value of
comment|/// \arg Ty from the va_list pointed to by \arg VAListAddr.
comment|// FIXME: This is a gaping layering violation if we wanted to drop
comment|// the ABI information any lower than CodeGen. Of course, for
comment|// VAArg handling it has to be at this level; there is no way to
comment|// abstract this out.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|EmitVAArg
argument_list|(
argument|llvm::Value *VAListAddr
argument_list|,
argument|QualType Ty
argument_list|,
argument|CodeGen::CodeGenFunction&CGF
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
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

