begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPU.h - MachineFunction passes hw codegen --------------*- C++ -*-=//
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
comment|/// \file
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMDGPU_H
end_ifndef

begin_define
define|#
directive|define
name|AMDGPU_H
end_define

begin_include
include|#
directive|include
file|"AMDGPUTargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/TargetRegistry.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FunctionPass
decl_stmt|;
name|class
name|AMDGPUTargetMachine
decl_stmt|;
comment|// R600 Passes
name|FunctionPass
modifier|*
name|createR600KernelParametersPass
parameter_list|(
specifier|const
name|DataLayout
modifier|*
name|TD
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createR600ExpandSpecialInstrsPass
parameter_list|(
name|TargetMachine
modifier|&
name|tm
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createR600EmitClauseMarkers
parameter_list|(
name|TargetMachine
modifier|&
name|tm
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createR600Packetizer
parameter_list|(
name|TargetMachine
modifier|&
name|tm
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createR600ControlFlowFinalizer
parameter_list|(
name|TargetMachine
modifier|&
name|tm
parameter_list|)
function_decl|;
comment|// SI Passes
name|FunctionPass
modifier|*
name|createSIAnnotateControlFlowPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createSILowerControlFlowPass
parameter_list|(
name|TargetMachine
modifier|&
name|tm
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createSICodeEmitterPass
parameter_list|(
name|formatted_raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createSIInsertWaits
parameter_list|(
name|TargetMachine
modifier|&
name|tm
parameter_list|)
function_decl|;
comment|// Passes common to R600 and SI
name|Pass
modifier|*
name|createAMDGPUStructurizeCFGPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createAMDGPUConvertToISAPass
parameter_list|(
name|TargetMachine
modifier|&
name|tm
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createAMDGPUIndirectAddressingPass
parameter_list|(
name|TargetMachine
modifier|&
name|tm
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_decl_stmt
name|namespace
name|ShaderType
block|{
enum|enum
name|Type
block|{
name|PIXEL
init|=
literal|0
block|,
name|VERTEX
init|=
literal|1
block|,
name|GEOMETRY
init|=
literal|2
block|,
name|COMPUTE
init|=
literal|3
block|}
enum|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// AMDGPU_H
end_comment

end_unit

