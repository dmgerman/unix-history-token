begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- HostInfo.h - Host specific information -----------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|CLANG_DRIVER_HOSTINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|CLANG_DRIVER_HOSTINFO_H_
end_define

begin_include
include|#
directive|include
file|"clang/Driver/Types.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
name|class
name|ArgList
decl_stmt|;
name|class
name|Driver
decl_stmt|;
name|class
name|ToolChain
decl_stmt|;
comment|/// HostInfo - Config information about a particular host which may
comment|/// interact with driver behavior.
comment|///
comment|/// The host information is used for controlling the parts of the
comment|/// driver which interact with the platform the driver is ostensibly
comment|/// being run from. For testing purposes, the HostInfo used by the
comment|/// driver may differ from the actual host.
name|class
name|HostInfo
block|{
specifier|const
name|Driver
modifier|&
name|TheDriver
decl_stmt|;
specifier|const
name|llvm
operator|::
name|Triple
name|Triple
expr_stmt|;
name|protected
label|:
name|HostInfo
argument_list|(
specifier|const
name|Driver
operator|&
name|D
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|_Triple
argument_list|)
expr_stmt|;
name|public
label|:
name|virtual
operator|~
name|HostInfo
argument_list|()
expr_stmt|;
specifier|const
name|Driver
operator|&
name|getDriver
argument_list|()
specifier|const
block|{
return|return
name|TheDriver
return|;
block|}
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|getTriple
argument_list|()
specifier|const
block|{
return|return
name|Triple
return|;
block|}
name|std
operator|::
name|string
name|getArchName
argument_list|()
specifier|const
block|{
return|return
name|Triple
operator|.
name|getArchName
argument_list|()
return|;
block|}
name|std
operator|::
name|string
name|getPlatformName
argument_list|()
specifier|const
block|{
return|return
name|Triple
operator|.
name|getVendorName
argument_list|()
return|;
block|}
name|std
operator|::
name|string
name|getOSName
argument_list|()
specifier|const
block|{
return|return
name|Triple
operator|.
name|getOSName
argument_list|()
return|;
block|}
comment|/// useDriverDriver - Whether the driver should act as a driver
comment|/// driver for this host and support -arch, -Xarch, etc.
name|virtual
name|bool
name|useDriverDriver
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// lookupTypeForExtension - Return the default language type to use
comment|/// for the given extension.
name|virtual
name|types
operator|::
name|ID
name|lookupTypeForExtension
argument_list|(
argument|const char *Ext
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// getToolChain - Construct the toolchain to use for this host.
comment|///
comment|/// \param Args - The argument list, which may be used to alter the
comment|/// default toolchain, for example in the presence of -m32 or -m64.
comment|///
comment|/// \param ArchName - The architecture to return a toolchain for, or
comment|/// 0 if unspecified. This will only ever be non-zero for hosts
comment|/// which support a driver driver.
comment|// FIXME: Pin down exactly what the HostInfo is allowed to use Args
comment|// for here. Currently this is for -m32 / -m64 defaulting.
name|virtual
name|ToolChain
modifier|*
name|getToolChain
argument_list|(
specifier|const
name|ArgList
operator|&
name|Args
argument_list|,
specifier|const
name|char
operator|*
name|ArchName
operator|=
literal|0
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
specifier|const
name|HostInfo
modifier|*
name|createDarwinHostInfo
argument_list|(
specifier|const
name|Driver
operator|&
name|D
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
decl_stmt|;
specifier|const
name|HostInfo
modifier|*
name|createFreeBSDHostInfo
argument_list|(
specifier|const
name|Driver
operator|&
name|D
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
decl_stmt|;
specifier|const
name|HostInfo
modifier|*
name|createDragonFlyHostInfo
argument_list|(
specifier|const
name|Driver
operator|&
name|D
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
decl_stmt|;
specifier|const
name|HostInfo
modifier|*
name|createLinuxHostInfo
argument_list|(
specifier|const
name|Driver
operator|&
name|D
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
decl_stmt|;
specifier|const
name|HostInfo
modifier|*
name|createUnknownHostInfo
argument_list|(
specifier|const
name|Driver
operator|&
name|D
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
decl_stmt|;
block|}
comment|// end namespace driver
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

