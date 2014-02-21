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
name|AMDGPUInstrPrinter
decl_stmt|;
name|class
name|AMDGPUTargetMachine
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
comment|// R600 Passes
name|FunctionPass
modifier|*
name|createR600VectorRegMerger
parameter_list|(
name|TargetMachine
modifier|&
name|tm
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createR600TextureIntrinsicsReplacer
parameter_list|()
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
name|createR600ClauseMergePass
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
name|FunctionPass
modifier|*
name|createAMDGPUCFGStructurizerPass
parameter_list|(
name|TargetMachine
modifier|&
name|tm
parameter_list|)
function_decl|;
comment|// SI Passes
name|FunctionPass
modifier|*
name|createSITypeRewriter
parameter_list|()
function_decl|;
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
name|createSIFixSGPRCopiesPass
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
name|createAMDGPUISelDag
parameter_list|(
name|TargetMachine
modifier|&
name|tm
parameter_list|)
function_decl|;
comment|/// \brief Creates an AMDGPU-specific Target Transformation Info pass.
name|ImmutablePass
modifier|*
name|createAMDGPUTargetTransformInfoPass
parameter_list|(
specifier|const
name|AMDGPUTargetMachine
modifier|*
name|TM
parameter_list|)
function_decl|;
specifier|extern
name|Target
name|TheAMDGPUTarget
decl_stmt|;
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

begin_comment
comment|/// OpenCL uses address spaces to differentiate between
end_comment

begin_comment
comment|/// various memory regions on the hardware. On the CPU
end_comment

begin_comment
comment|/// all of the address spaces point to the same memory,
end_comment

begin_comment
comment|/// however on the GPU, each address space points to
end_comment

begin_comment
comment|/// a seperate piece of memory that is unique from other
end_comment

begin_comment
comment|/// memory locations.
end_comment

begin_decl_stmt
name|namespace
name|AMDGPUAS
block|{
enum|enum
name|AddressSpaces
block|{
name|PRIVATE_ADDRESS
init|=
literal|0
block|,
comment|///< Address space for private memory.
name|GLOBAL_ADDRESS
init|=
literal|1
block|,
comment|///< Address space for global memory (RAT0, VTX0).
name|CONSTANT_ADDRESS
init|=
literal|2
block|,
comment|///< Address space for constant memory
name|LOCAL_ADDRESS
init|=
literal|3
block|,
comment|///< Address space for local memory.
name|REGION_ADDRESS
init|=
literal|4
block|,
comment|///< Address space for region memory.
name|ADDRESS_NONE
init|=
literal|5
block|,
comment|///< Address space for unknown memory.
name|PARAM_D_ADDRESS
init|=
literal|6
block|,
comment|///< Address space for direct addressible parameter memory (CONST0)
name|PARAM_I_ADDRESS
init|=
literal|7
block|,
comment|///< Address space for indirect addressible parameter memory (VTX1)
comment|// Do not re-order the CONSTANT_BUFFER_* enums.  Several places depend on this
comment|// order to be able to dynamically index a constant buffer, for example:
comment|//
comment|// ConstantBufferAS = CONSTANT_BUFFER_0 + CBIdx
name|CONSTANT_BUFFER_0
init|=
literal|8
block|,
name|CONSTANT_BUFFER_1
init|=
literal|9
block|,
name|CONSTANT_BUFFER_2
init|=
literal|10
block|,
name|CONSTANT_BUFFER_3
init|=
literal|11
block|,
name|CONSTANT_BUFFER_4
init|=
literal|12
block|,
name|CONSTANT_BUFFER_5
init|=
literal|13
block|,
name|CONSTANT_BUFFER_6
init|=
literal|14
block|,
name|CONSTANT_BUFFER_7
init|=
literal|15
block|,
name|CONSTANT_BUFFER_8
init|=
literal|16
block|,
name|CONSTANT_BUFFER_9
init|=
literal|17
block|,
name|CONSTANT_BUFFER_10
init|=
literal|18
block|,
name|CONSTANT_BUFFER_11
init|=
literal|19
block|,
name|CONSTANT_BUFFER_12
init|=
literal|20
block|,
name|CONSTANT_BUFFER_13
init|=
literal|21
block|,
name|CONSTANT_BUFFER_14
init|=
literal|22
block|,
name|CONSTANT_BUFFER_15
init|=
literal|23
block|,
name|LAST_ADDRESS
init|=
literal|24
block|}
enum|;
block|}
end_decl_stmt

begin_comment
comment|// namespace AMDGPUAS
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// AMDGPU_H
end_comment

end_unit

