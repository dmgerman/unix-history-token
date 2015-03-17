begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- CGCUDARuntime.h - Interface to CUDA Runtimes ---------*- C++ -*-===//
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
comment|// This provides an abstract class for CUDA code generation.  Concrete
end_comment

begin_comment
comment|// subclasses of this implement code generation for specific CUDA
end_comment

begin_comment
comment|// runtime libraries.
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
name|LLVM_CLANG_LIB_CODEGEN_CGCUDARUNTIME_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_CGCUDARUNTIME_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CUDAKernelCallExpr
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenFunction
decl_stmt|;
name|class
name|CodeGenModule
decl_stmt|;
name|class
name|FunctionArgList
decl_stmt|;
name|class
name|ReturnValueSlot
decl_stmt|;
name|class
name|RValue
decl_stmt|;
name|class
name|CGCUDARuntime
block|{
name|protected
label|:
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
name|public
label|:
name|CGCUDARuntime
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|)
operator|:
name|CGM
argument_list|(
argument|CGM
argument_list|)
block|{}
name|virtual
operator|~
name|CGCUDARuntime
argument_list|()
expr_stmt|;
name|virtual
name|RValue
name|EmitCUDAKernelCallExpr
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|CUDAKernelCallExpr
modifier|*
name|E
parameter_list|,
name|ReturnValueSlot
name|ReturnValue
parameter_list|)
function_decl|;
name|virtual
name|void
name|EmitDeviceStubBody
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|FunctionArgList
modifier|&
name|Args
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|/// Creates an instance of a CUDA runtime class.
name|CGCUDARuntime
modifier|*
name|CreateNVCUDARuntime
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

