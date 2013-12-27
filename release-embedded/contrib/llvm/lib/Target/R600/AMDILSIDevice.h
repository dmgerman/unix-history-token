begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------- AMDILSIDevice.h - Define SI Device for AMDIL -*- C++ -*------===//
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
comment|//===---------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMDILSIDEVICE_H
end_ifndef

begin_define
define|#
directive|define
name|AMDILSIDEVICE_H
end_define

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
comment|// SI generation of devices and their respective sub classes
comment|//===---------------------------------------------------------------------===//
comment|/// \brief The AMDGPUSIDevice is the base class for all Southern Island series
comment|/// of cards.
name|class
name|AMDGPUSIDevice
range|:
name|public
name|AMDGPUEvergreenDevice
block|{
name|public
operator|:
name|AMDGPUSIDevice
argument_list|(
name|AMDGPUSubtarget
operator|*
argument_list|)
block|;
name|virtual
operator|~
name|AMDGPUSIDevice
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
block|;
name|virtual
name|std
operator|::
name|string
name|getDataLayout
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
comment|// AMDILSIDEVICE_H
end_comment

end_unit

