begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/CodeGenCWrappers.h - CodeGen C Wrappers -----*- C++ -*-===//
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
comment|// This file defines C bindings wrappers for enums in llvm/Support/CodeGen.h
end_comment

begin_comment
comment|// that need them.  The wrappers are separated to avoid adding an indirect
end_comment

begin_comment
comment|// dependency on llvm/Config/Targets.def to CodeGen.h.
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
name|LLVM_SUPPORT_CODEGENCWRAPPERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_CODEGENCWRAPPERS_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
specifier|inline
name|CodeModel
operator|::
name|Model
name|unwrap
argument_list|(
argument|LLVMCodeModel Model
argument_list|)
block|{
switch|switch
condition|(
name|Model
condition|)
block|{
case|case
name|LLVMCodeModelDefault
case|:
return|return
name|CodeModel
operator|::
name|Default
return|;
case|case
name|LLVMCodeModelJITDefault
case|:
return|return
name|CodeModel
operator|::
name|JITDefault
return|;
case|case
name|LLVMCodeModelSmall
case|:
return|return
name|CodeModel
operator|::
name|Small
return|;
case|case
name|LLVMCodeModelKernel
case|:
return|return
name|CodeModel
operator|::
name|Kernel
return|;
case|case
name|LLVMCodeModelMedium
case|:
return|return
name|CodeModel
operator|::
name|Medium
return|;
case|case
name|LLVMCodeModelLarge
case|:
return|return
name|CodeModel
operator|::
name|Large
return|;
block|}
return|return
name|CodeModel
operator|::
name|Default
return|;
block|}
specifier|inline
name|LLVMCodeModel
name|wrap
argument_list|(
argument|CodeModel::Model Model
argument_list|)
block|{
switch|switch
condition|(
name|Model
condition|)
block|{
case|case
name|CodeModel
operator|::
name|Default
case|:
return|return
name|LLVMCodeModelDefault
return|;
case|case
name|CodeModel
operator|::
name|JITDefault
case|:
return|return
name|LLVMCodeModelJITDefault
return|;
case|case
name|CodeModel
operator|::
name|Small
case|:
return|return
name|LLVMCodeModelSmall
return|;
case|case
name|CodeModel
operator|::
name|Kernel
case|:
return|return
name|LLVMCodeModelKernel
return|;
case|case
name|CodeModel
operator|::
name|Medium
case|:
return|return
name|LLVMCodeModelMedium
return|;
case|case
name|CodeModel
operator|::
name|Large
case|:
return|return
name|LLVMCodeModelLarge
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Bad CodeModel!"
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

