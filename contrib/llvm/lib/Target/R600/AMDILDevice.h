begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- AMDILDevice.h - Define Device Data for AMDGPU -----*- C++ -*------===//
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
comment|/// \file
end_comment

begin_comment
comment|/// \brief Interface for the subtarget data classes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// This file will define the interface that each generation needs to
end_comment

begin_comment
comment|/// implement in order to correctly answer queries on the capabilities of the
end_comment

begin_comment
comment|/// specific hardware.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMDILDEVICEIMPL_H
end_ifndef

begin_define
define|#
directive|define
name|AMDILDEVICEIMPL_H
end_define

begin_include
include|#
directive|include
file|"AMDIL.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AMDGPUSubtarget
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// Interface for data that is specific to a single device
comment|//===----------------------------------------------------------------------===//
name|class
name|AMDGPUDevice
block|{
name|public
label|:
name|AMDGPUDevice
argument_list|(
name|AMDGPUSubtarget
operator|*
name|ST
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|AMDGPUDevice
argument_list|()
expr_stmt|;
comment|// Enum values for the various memory types.
enum|enum
block|{
name|RAW_UAV_ID
init|=
literal|0
block|,
name|ARENA_UAV_ID
init|=
literal|1
block|,
name|LDS_ID
init|=
literal|2
block|,
name|GDS_ID
init|=
literal|3
block|,
name|SCRATCH_ID
init|=
literal|4
block|,
name|CONSTANT_ID
init|=
literal|5
block|,
name|GLOBAL_ID
init|=
literal|6
block|,
name|MAX_IDS
init|=
literal|7
block|}
name|IO_TYPE_IDS
enum|;
comment|/// \returns The max LDS size that the hardware supports.  Size is in
comment|/// bytes.
name|virtual
name|size_t
name|getMaxLDSSize
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// \returns The max GDS size that the hardware supports if the GDS is
comment|/// supported by the hardware.  Size is in bytes.
name|virtual
name|size_t
name|getMaxGDSSize
argument_list|()
specifier|const
expr_stmt|;
comment|/// \returns The max number of hardware constant address spaces that
comment|/// are supported by this device.
name|virtual
name|size_t
name|getMaxNumCBs
argument_list|()
specifier|const
expr_stmt|;
comment|/// \returns The max number of bytes a single hardware constant buffer
comment|/// can support.  Size is in bytes.
name|virtual
name|size_t
name|getMaxCBSize
argument_list|()
specifier|const
expr_stmt|;
comment|/// \returns The max number of bytes allowed by the hardware scratch
comment|/// buffer.  Size is in bytes.
name|virtual
name|size_t
name|getMaxScratchSize
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Get the flag that corresponds to the device.
name|virtual
name|uint32_t
name|getDeviceFlag
argument_list|()
specifier|const
expr_stmt|;
comment|/// \returns The number of work-items that exist in a single hardware
comment|/// wavefront.
name|virtual
name|size_t
name|getWavefrontSize
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// \brief Get the generational name of this specific device.
name|virtual
name|uint32_t
name|getGeneration
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// \brief Get the stack alignment of this specific device.
name|virtual
name|uint32_t
name|getStackAlignment
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Get the resource ID for this specific device.
name|virtual
name|uint32_t
name|getResourceID
argument_list|(
name|uint32_t
name|DeviceID
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// \brief Get the max number of UAV's for this device.
name|virtual
name|uint32_t
name|getMaxNumUAVs
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// API utilizing more detailed capabilities of each family of
comment|// cards. If a capability is supported, then either usesHardware or
comment|// usesSoftware returned true.  If usesHardware returned true, then
comment|// usesSoftware must return false for the same capability.  Hardware
comment|// execution means that the feature is done natively by the hardware
comment|// and is not emulated by the softare.  Software execution means
comment|// that the feature could be done in the hardware, but there is
comment|// software that emulates it with possibly using the hardware for
comment|// support since the hardware does not fully comply with OpenCL
comment|// specs.
name|bool
name|isSupported
argument_list|(
name|AMDGPUDeviceInfo
operator|::
name|Caps
name|Mode
argument_list|)
decl|const
decl_stmt|;
name|bool
name|usesHardware
argument_list|(
name|AMDGPUDeviceInfo
operator|::
name|Caps
name|Mode
argument_list|)
decl|const
decl_stmt|;
name|bool
name|usesSoftware
argument_list|(
name|AMDGPUDeviceInfo
operator|::
name|Caps
name|Mode
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|std
operator|::
name|string
name|getDataLayout
argument_list|()
specifier|const
expr_stmt|;
specifier|static
specifier|const
name|unsigned
name|int
name|MAX_LDS_SIZE_700
init|=
literal|16384
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|int
name|MAX_LDS_SIZE_800
init|=
literal|32768
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|int
name|WavefrontSize
init|=
literal|64
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|int
name|HalfWavefrontSize
init|=
literal|32
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|int
name|QuarterWavefrontSize
init|=
literal|16
decl_stmt|;
name|protected
label|:
name|virtual
name|void
name|setCaps
parameter_list|()
function_decl|;
name|BitVector
name|mHWBits
decl_stmt|;
name|llvm
operator|::
name|BitVector
name|mSWBits
expr_stmt|;
name|AMDGPUSubtarget
modifier|*
name|mSTM
decl_stmt|;
name|uint32_t
name|DeviceFlag
decl_stmt|;
name|private
label|:
name|AMDGPUDeviceInfo
operator|::
name|ExecutionMode
name|getExecutionMode
argument_list|(
argument|AMDGPUDeviceInfo::Caps Caps
argument_list|)
specifier|const
expr_stmt|;
block|}
empty_stmt|;
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
comment|// AMDILDEVICEIMPL_H
end_comment

end_unit

