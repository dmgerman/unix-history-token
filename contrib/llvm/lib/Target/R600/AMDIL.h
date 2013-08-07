begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDIL.h - Top-level interface for AMDIL representation --*- C++ -*-===//
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
comment|//==-----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// This file contains the entry points for global functions defined in the LLVM
end_comment

begin_comment
comment|/// AMDGPU back-end.
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
name|AMDIL_H
end_ifndef

begin_define
define|#
directive|define
name|AMDIL_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_define
define|#
directive|define
name|ARENA_SEGMENT_RESERVED_UAVS
value|12
end_define

begin_define
define|#
directive|define
name|DEFAULT_ARENA_UAV_ID
value|8
end_define

begin_define
define|#
directive|define
name|DEFAULT_RAW_UAV_ID
value|7
end_define

begin_define
define|#
directive|define
name|GLOBAL_RETURN_RAW_UAV_ID
value|11
end_define

begin_define
define|#
directive|define
name|HW_MAX_NUM_CB
value|8
end_define

begin_define
define|#
directive|define
name|MAX_NUM_UNIQUE_UAVS
value|8
end_define

begin_define
define|#
directive|define
name|OPENCL_MAX_NUM_ATOMIC_COUNTERS
value|8
end_define

begin_define
define|#
directive|define
name|OPENCL_MAX_READ_IMAGES
value|128
end_define

begin_define
define|#
directive|define
name|OPENCL_MAX_WRITE_IMAGES
value|8
end_define

begin_define
define|#
directive|define
name|OPENCL_MAX_SAMPLERS
value|16
end_define

begin_comment
comment|// The next two values can never be zero, as zero is the ID that is
end_comment

begin_comment
comment|// used to assert against.
end_comment

begin_define
define|#
directive|define
name|DEFAULT_LDS_ID
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_GDS_ID
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_SCRATCH_ID
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_VEC_SLOTS
value|8
end_define

begin_define
define|#
directive|define
name|OCL_DEVICE_RV710
value|0x0001
end_define

begin_define
define|#
directive|define
name|OCL_DEVICE_RV730
value|0x0002
end_define

begin_define
define|#
directive|define
name|OCL_DEVICE_RV770
value|0x0004
end_define

begin_define
define|#
directive|define
name|OCL_DEVICE_CEDAR
value|0x0008
end_define

begin_define
define|#
directive|define
name|OCL_DEVICE_REDWOOD
value|0x0010
end_define

begin_define
define|#
directive|define
name|OCL_DEVICE_JUNIPER
value|0x0020
end_define

begin_define
define|#
directive|define
name|OCL_DEVICE_CYPRESS
value|0x0040
end_define

begin_define
define|#
directive|define
name|OCL_DEVICE_CAICOS
value|0x0080
end_define

begin_define
define|#
directive|define
name|OCL_DEVICE_TURKS
value|0x0100
end_define

begin_define
define|#
directive|define
name|OCL_DEVICE_BARTS
value|0x0200
end_define

begin_define
define|#
directive|define
name|OCL_DEVICE_CAYMAN
value|0x0400
end_define

begin_define
define|#
directive|define
name|OCL_DEVICE_ALL
value|0x3FFF
end_define

begin_comment
comment|/// The number of function ID's that are reserved for
end_comment

begin_comment
comment|/// internal compiler usage.
end_comment

begin_decl_stmt
specifier|const
name|unsigned
name|int
name|RESERVED_FUNCS
init|=
literal|1024
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AMDGPUInstrPrinter
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
comment|// Instruction selection passes.
name|FunctionPass
modifier|*
name|createAMDGPUISelDag
parameter_list|(
name|TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createAMDGPUPeepholeOpt
parameter_list|(
name|TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
comment|// Pre emit passes.
name|FunctionPass
modifier|*
name|createAMDGPUCFGPreparationPass
parameter_list|(
name|TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createAMDGPUCFGStructurizerPass
parameter_list|(
name|TargetMachine
modifier|&
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
comment|// end namespace llvm;
end_comment

begin_comment
comment|// Include device information enumerations
end_comment

begin_include
include|#
directive|include
file|"AMDILDeviceInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// OpenCL uses address spaces to differentiate between
comment|/// various memory regions on the hardware. On the CPU
comment|/// all of the address spaces point to the same memory,
comment|/// however on the GPU, each address space points to
comment|/// a seperate piece of memory that is unique from other
comment|/// memory locations.
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
comment|// namespace AMDGPUAS
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// AMDIL_H
end_comment

end_unit

