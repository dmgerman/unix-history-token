begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDILDeviceInfo.h - Constants for describing devices --------------===//
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
comment|//==-----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMDILDEVICEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|AMDILDEVICEINFO_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AMDGPUDevice
decl_stmt|;
name|class
name|AMDGPUSubtarget
decl_stmt|;
name|namespace
name|AMDGPUDeviceInfo
block|{
comment|/// Each Capabilities can be executed using a hardware instruction,
comment|/// emulated with a sequence of software instructions, or not
comment|/// supported at all.
enum|enum
name|ExecutionMode
block|{
name|Unsupported
init|=
literal|0
block|,
comment|///< Unsupported feature on the card(Default value)
comment|/// This is the execution mode that is set if the feature is emulated in
comment|/// software.
name|Software
block|,
comment|/// This execution mode is set if the feature exists natively in hardware
name|Hardware
block|}
enum|;
enum|enum
name|Caps
block|{
name|HalfOps
init|=
literal|0x1
block|,
comment|///< Half float is supported or not.
name|DoubleOps
init|=
literal|0x2
block|,
comment|///< Double is supported or not.
name|ByteOps
init|=
literal|0x3
block|,
comment|///< Byte(char) is support or not.
name|ShortOps
init|=
literal|0x4
block|,
comment|///< Short is supported or not.
name|LongOps
init|=
literal|0x5
block|,
comment|///< Long is supported or not.
name|Images
init|=
literal|0x6
block|,
comment|///< Images are supported or not.
name|ByteStores
init|=
literal|0x7
block|,
comment|///< ByteStores available(!HD4XXX).
name|ConstantMem
init|=
literal|0x8
block|,
comment|///< Constant/CB memory.
name|LocalMem
init|=
literal|0x9
block|,
comment|///< Local/LDS memory.
name|PrivateMem
init|=
literal|0xA
block|,
comment|///< Scratch/Private/Stack memory.
name|RegionMem
init|=
literal|0xB
block|,
comment|///< OCL GDS Memory Extension.
name|FMA
init|=
literal|0xC
block|,
comment|///< Use HW FMA or SW FMA.
name|ArenaSegment
init|=
literal|0xD
block|,
comment|///< Use for Arena UAV per pointer 12-1023.
name|MultiUAV
init|=
literal|0xE
block|,
comment|///< Use for UAV per Pointer 0-7.
name|Reserved0
init|=
literal|0xF
block|,
comment|///< ReservedFlag
name|NoAlias
init|=
literal|0x10
block|,
comment|///< Cached loads.
name|Signed24BitOps
init|=
literal|0x11
block|,
comment|///< Peephole Optimization.
comment|/// Debug mode implies that no hardware features or optimizations
comment|/// are performned and that all memory access go through a single
comment|/// uav(Arena on HD5XXX/HD6XXX and Raw on HD4XXX).
name|Debug
init|=
literal|0x12
block|,
name|CachedMem
init|=
literal|0x13
block|,
comment|///< Cached mem is available or not.
name|BarrierDetect
init|=
literal|0x14
block|,
comment|///< Detect duplicate barriers.
name|Reserved1
init|=
literal|0x15
block|,
comment|///< Reserved flag
name|ByteLDSOps
init|=
literal|0x16
block|,
comment|///< Flag to specify if byte LDS ops are available.
name|ArenaVectors
init|=
literal|0x17
block|,
comment|///< Flag to specify if vector loads from arena work.
name|TmrReg
init|=
literal|0x18
block|,
comment|///< Flag to specify if Tmr register is supported.
name|NoInline
init|=
literal|0x19
block|,
comment|///< Flag to specify that no inlining should occur.
name|MacroDB
init|=
literal|0x1A
block|,
comment|///< Flag to specify that backend handles macrodb.
name|HW64BitDivMod
init|=
literal|0x1B
block|,
comment|///< Flag for backend to generate 64bit div/mod.
name|ArenaUAV
init|=
literal|0x1C
block|,
comment|///< Flag to specify that arena uav is supported.
name|PrivateUAV
init|=
literal|0x1D
block|,
comment|///< Flag to specify that private memory uses uav's.
comment|/// If more capabilities are required, then
comment|/// this number needs to be increased.
comment|/// All capabilities must come before this
comment|/// number.
name|MaxNumberCapabilities
init|=
literal|0x20
block|}
enum|;
comment|/// These have to be in order with the older generations
comment|/// having the lower number enumerations.
enum|enum
name|Generation
block|{
name|HD4XXX
init|=
literal|0
block|,
comment|///< 7XX based devices.
name|HD5XXX
block|,
comment|///< Evergreen based devices.
name|HD6XXX
block|,
comment|///< NI/Evergreen+ based devices.
name|HD7XXX
block|,
comment|///< Southern Islands based devices.
name|HDTEST
block|,
comment|///< Experimental feature testing device.
name|HDNUMGEN
block|}
enum|;
name|AMDGPUDevice
modifier|*
name|getDeviceFromName
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|,
name|AMDGPUSubtarget
operator|*
name|ptr
argument_list|,
name|bool
name|is64bit
operator|=
name|false
argument_list|,
name|bool
name|is64on32bit
operator|=
name|false
argument_list|)
decl_stmt|;
block|}
comment|// namespace AMDILDeviceInfo
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// AMDILDEVICEINFO_H
end_comment

end_unit

