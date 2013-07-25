begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- AMDIL7XXDevice.h - Define 7XX Device Device for AMDIL ---*- C++ -*--===//
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
comment|/// \file
end_comment

begin_comment
comment|/// \brief Interface for the subtarget data classes.
end_comment

begin_comment
comment|///
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
name|AMDIL7XXDEVICEIMPL_H
end_ifndef

begin_define
define|#
directive|define
name|AMDIL7XXDEVICEIMPL_H
end_define

begin_include
include|#
directive|include
file|"AMDILDevice.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AMDGPUSubtarget
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// 7XX generation of devices and their respective sub classes
comment|//===----------------------------------------------------------------------===//
comment|/// \brief The AMDGPU7XXDevice class represents the generic 7XX device.
comment|///
comment|/// All 7XX devices are derived from this class. The AMDGPU7XX device will only
comment|/// support the minimal features that are required to be considered OpenCL 1.0
comment|/// compliant and nothing more.
name|class
name|AMDGPU7XXDevice
range|:
name|public
name|AMDGPUDevice
block|{
name|public
operator|:
name|AMDGPU7XXDevice
argument_list|(
name|AMDGPUSubtarget
operator|*
name|ST
argument_list|)
block|;
name|virtual
operator|~
name|AMDGPU7XXDevice
argument_list|()
block|;
name|virtual
name|size_t
name|getMaxLDSSize
argument_list|()
specifier|const
block|;
name|virtual
name|size_t
name|getWavefrontSize
argument_list|()
specifier|const
block|;
name|virtual
name|uint32_t
name|getGeneration
argument_list|()
specifier|const
block|;
name|virtual
name|uint32_t
name|getResourceID
argument_list|(
argument|uint32_t DeviceID
argument_list|)
specifier|const
block|;
name|virtual
name|uint32_t
name|getMaxNumUAVs
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|virtual
name|void
name|setCaps
argument_list|()
block|; }
decl_stmt|;
comment|/// \brief The AMDGPU770Device class represents the RV770 chip and it's
comment|/// derivative cards.
comment|///
comment|/// The difference between this device and the base class is this device device
comment|/// adds support for double precision and has a larger wavefront size.
name|class
name|AMDGPU770Device
range|:
name|public
name|AMDGPU7XXDevice
block|{
name|public
operator|:
name|AMDGPU770Device
argument_list|(
name|AMDGPUSubtarget
operator|*
name|ST
argument_list|)
block|;
name|virtual
operator|~
name|AMDGPU770Device
argument_list|()
block|;
name|virtual
name|size_t
name|getWavefrontSize
argument_list|()
specifier|const
block|;
name|private
operator|:
name|virtual
name|void
name|setCaps
argument_list|()
block|; }
decl_stmt|;
comment|/// \brief The AMDGPU710Device class derives from the 7XX base class.
comment|///
comment|/// This class is a smaller derivative, so we need to overload some of the
comment|/// functions in order to correctly specify this information.
name|class
name|AMDGPU710Device
range|:
name|public
name|AMDGPU7XXDevice
block|{
name|public
operator|:
name|AMDGPU710Device
argument_list|(
name|AMDGPUSubtarget
operator|*
name|ST
argument_list|)
block|;
name|virtual
operator|~
name|AMDGPU710Device
argument_list|()
block|;
name|virtual
name|size_t
name|getWavefrontSize
argument_list|()
specifier|const
block|; }
decl_stmt|;
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

