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
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
block|}
end_decl_stmt

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
comment|// Global variable properties that must be passed to CUDA runtime.
enum|enum
name|DeviceVarFlags
block|{
name|ExternDeviceVar
init|=
literal|0x01
block|,
comment|// extern
name|ConstantDeviceVar
init|=
literal|0x02
block|,
comment|// __constant__
block|}
enum|;
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
comment|/// Emits a kernel launch stub.
name|virtual
name|void
name|emitDeviceStub
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
name|virtual
name|void
name|registerDeviceVar
argument_list|(
name|llvm
operator|::
name|GlobalVariable
operator|&
name|Var
argument_list|,
name|unsigned
name|Flags
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// Constructs and returns a module initialization function or nullptr if it's
comment|/// not needed. Must be called after all kernels have been emitted.
name|virtual
name|llvm
operator|::
name|Function
operator|*
name|makeModuleCtorFunction
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// Returns a module cleanup function or nullptr if it's not needed.
comment|/// Must be called after ModuleCtorFunction
name|virtual
name|llvm
operator|::
name|Function
operator|*
name|makeModuleDtorFunction
argument_list|()
operator|=
literal|0
expr_stmt|;
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

