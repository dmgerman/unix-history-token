begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/System/Host.h - Host machine characteristics --------*- C++ -*-===//
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
comment|// Methods for querying the nature of the host machine.
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
name|LLVM_SYSTEM_HOST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SYSTEM_HOST_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
specifier|inline
name|bool
name|isLittleEndianHost
parameter_list|()
block|{
union|union
block|{
name|int
name|i
decl_stmt|;
name|char
name|c
decl_stmt|;
block|}
union|;
name|i
operator|=
literal|1
expr_stmt|;
return|return
name|c
return|;
block|}
specifier|inline
name|bool
name|isBigEndianHost
parameter_list|()
block|{
return|return
operator|!
name|isLittleEndianHost
argument_list|()
return|;
block|}
comment|/// getHostTriple() - Return the target triple of the running
comment|/// system.
comment|///
comment|/// The target triple is a string in the format of:
comment|///   CPU_TYPE-VENDOR-OPERATING_SYSTEM
comment|/// or
comment|///   CPU_TYPE-VENDOR-KERNEL-OPERATING_SYSTEM
name|std
operator|::
name|string
name|getHostTriple
argument_list|()
expr_stmt|;
comment|/// getHostCPUName - Get the LLVM name for the host CPU. The particular format
comment|/// of the name is target dependent, and suitable for passing as -mcpu to the
comment|/// target which matches the host.
comment|///
comment|/// \return - The host CPU name, or empty if the CPU could not be determined.
name|std
operator|::
name|string
name|getHostCPUName
argument_list|()
expr_stmt|;
comment|/// getHostCPUFeatures - Get the LLVM names for the host CPU features.
comment|/// The particular format of the names are target dependent, and suitable for
comment|/// passing as -mattr to the target which matches the host.
comment|///
comment|/// \param Features - A string mapping feature names to either
comment|/// true (if enabled) or false (if disabled). This routine makes no guarantees
comment|/// about exactly which features may appear in this map, except that they are
comment|/// all valid LLVM feature names.
comment|///
comment|/// \return - True on success.
name|bool
name|getHostCPUFeatures
argument_list|(
name|StringMap
operator|<
name|bool
operator|>
operator|&
name|Features
argument_list|)
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

