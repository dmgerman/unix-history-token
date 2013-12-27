begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- AMDILEvergreenDevice.h - Define Evergreen Device for AMDIL -*- C++ -*--=//
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
name|AMDILEVERGREENDEVICE_H
end_ifndef

begin_define
define|#
directive|define
name|AMDILEVERGREENDEVICE_H
end_define

begin_include
include|#
directive|include
file|"AMDGPUSubtarget.h"
end_include

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
comment|// Evergreen generation of devices and their respective sub classes
comment|//===----------------------------------------------------------------------===//
comment|/// \brief The AMDGPUEvergreenDevice is the base device class for all of the Evergreen
comment|/// series of cards.
comment|///
comment|/// This class contains information required to differentiate
comment|/// the Evergreen device from the generic AMDGPUDevice. This device represents
comment|/// that capabilities of the 'Juniper' cards, also known as the HD57XX.
name|class
name|AMDGPUEvergreenDevice
range|:
name|public
name|AMDGPUDevice
block|{
name|public
operator|:
name|AMDGPUEvergreenDevice
argument_list|(
name|AMDGPUSubtarget
operator|*
name|ST
argument_list|)
block|;
name|virtual
operator|~
name|AMDGPUEvergreenDevice
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
name|getMaxGDSSize
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
name|getMaxNumUAVs
argument_list|()
specifier|const
block|;
name|virtual
name|uint32_t
name|getResourceID
argument_list|(
argument|uint32_t
argument_list|)
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
comment|/// The AMDGPUCypressDevice is similiar to the AMDGPUEvergreenDevice, except it has
comment|/// support for double precision operations. This device is used to represent
comment|/// both the Cypress and Hemlock cards, which are commercially known as HD58XX
comment|/// and HD59XX cards.
name|class
name|AMDGPUCypressDevice
range|:
name|public
name|AMDGPUEvergreenDevice
block|{
name|public
operator|:
name|AMDGPUCypressDevice
argument_list|(
name|AMDGPUSubtarget
operator|*
name|ST
argument_list|)
block|;
name|virtual
operator|~
name|AMDGPUCypressDevice
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
comment|/// \brief The AMDGPUCedarDevice is the class that represents all of the 'Cedar' based
comment|/// devices.
comment|///
comment|/// This class differs from the base AMDGPUEvergreenDevice in that the
comment|/// device is a ~quarter of the 'Juniper'. These are commercially known as the
comment|/// HD54XX and HD53XX series of cards.
name|class
name|AMDGPUCedarDevice
range|:
name|public
name|AMDGPUEvergreenDevice
block|{
name|public
operator|:
name|AMDGPUCedarDevice
argument_list|(
name|AMDGPUSubtarget
operator|*
name|ST
argument_list|)
block|;
name|virtual
operator|~
name|AMDGPUCedarDevice
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
comment|/// \brief The AMDGPURedwoodDevice is the class the represents all of the 'Redwood' based
comment|/// devices.
comment|///
comment|/// This class differs from the base class, in that these devices are
comment|/// considered about half of a 'Juniper' device. These are commercially known as
comment|/// the HD55XX and HD56XX series of cards.
name|class
name|AMDGPURedwoodDevice
range|:
name|public
name|AMDGPUEvergreenDevice
block|{
name|public
operator|:
name|AMDGPURedwoodDevice
argument_list|(
name|AMDGPUSubtarget
operator|*
name|ST
argument_list|)
block|;
name|virtual
operator|~
name|AMDGPURedwoodDevice
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
comment|// AMDILEVERGREENDEVICE_H
end_comment

end_unit

