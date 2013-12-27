begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------- AMDILNIDevice.h - Define NI Device for AMDIL -*- C++ -*------===//
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
comment|//===---------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMDILNIDEVICE_H
end_ifndef

begin_define
define|#
directive|define
name|AMDILNIDEVICE_H
end_define

begin_include
include|#
directive|include
file|"AMDGPUSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"AMDILEvergreenDevice.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AMDGPUSubtarget
decl_stmt|;
comment|//===---------------------------------------------------------------------===//
comment|// NI generation of devices and their respective sub classes
comment|//===---------------------------------------------------------------------===//
comment|/// \brief The AMDGPUNIDevice is the base class for all Northern Island series of
comment|/// cards.
comment|///
comment|/// It is very similiar to the AMDGPUEvergreenDevice, with the major
comment|/// exception being differences in wavefront size and hardware capabilities.  The
comment|/// NI devices are all 64 wide wavefronts and also add support for signed 24 bit
comment|/// integer operations
name|class
name|AMDGPUNIDevice
range|:
name|public
name|AMDGPUEvergreenDevice
block|{
name|public
operator|:
name|AMDGPUNIDevice
argument_list|(
name|AMDGPUSubtarget
operator|*
argument_list|)
block|;
name|virtual
operator|~
name|AMDGPUNIDevice
argument_list|()
block|;
name|virtual
name|size_t
name|getMaxLDSSize
argument_list|()
specifier|const
block|;
name|virtual
name|uint32_t
name|getGeneration
argument_list|()
specifier|const
block|; }
decl_stmt|;
comment|/// Just as the AMDGPUCypressDevice is the double capable version of the
comment|/// AMDGPUEvergreenDevice, the AMDGPUCaymanDevice is the double capable version
comment|/// of the AMDGPUNIDevice.  The other major difference is that the Cayman Device
comment|/// has 4 wide ALU's, whereas the rest of the NI family is a 5 wide.
name|class
name|AMDGPUCaymanDevice
range|:
name|public
name|AMDGPUNIDevice
block|{
name|public
operator|:
name|AMDGPUCaymanDevice
argument_list|(
name|AMDGPUSubtarget
operator|*
argument_list|)
block|;
name|virtual
operator|~
name|AMDGPUCaymanDevice
argument_list|()
block|;
name|private
operator|:
name|virtual
name|void
name|setCaps
argument_list|()
block|; }
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|int
name|MAX_LDS_SIZE_900
init|=
name|AMDGPUDevice
operator|::
name|MAX_LDS_SIZE_800
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
comment|// AMDILNIDEVICE_H
end_comment

end_unit

