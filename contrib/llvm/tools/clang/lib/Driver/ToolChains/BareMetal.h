begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- BareMetal.h - Bare Metal Tool and ToolChain -------------*- C++ -*-===//
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
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_BAREMETAL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_BAREMETAL_H
end_define

begin_include
include|#
directive|include
file|"clang/Driver/Tool.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/ToolChain.h"
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
name|namespace
name|toolchains
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|BareMetal
range|:
name|public
name|ToolChain
block|{
name|public
operator|:
name|BareMetal
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
argument_list|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|)
block|;
operator|~
name|BareMetal
argument_list|()
name|override
block|;
specifier|static
name|bool
name|handlesTarget
argument_list|(
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
block|;
name|protected
operator|:
name|Tool
operator|*
name|buildLinker
argument_list|()
specifier|const
name|override
block|;
name|public
operator|:
name|bool
name|useIntegratedAs
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|isCrossCompiling
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|isPICDefault
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
name|bool
name|isPIEDefault
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
name|bool
name|isPICDefaultForced
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
name|bool
name|SupportsProfiling
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
name|bool
name|SupportsObjCGC
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
name|std
operator|::
name|string
name|getThreadModel
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isThreadModelSupported
argument_list|(
argument|const StringRef Model
argument_list|)
specifier|const
name|override
block|;
name|RuntimeLibType
name|GetDefaultRuntimeLibType
argument_list|()
specifier|const
name|override
block|{
return|return
name|ToolChain
operator|::
name|RLT_CompilerRT
return|;
block|}
name|CXXStdlibType
name|GetDefaultCXXStdlibType
argument_list|()
specifier|const
name|override
block|{
return|return
name|ToolChain
operator|::
name|CST_Libcxx
return|;
block|}
specifier|const
name|char
operator|*
name|getDefaultLinker
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"ld.lld"
return|;
block|}
name|std
operator|::
name|string
name|getRuntimesDir
argument_list|()
specifier|const
block|;
name|void
name|AddClangSystemIncludeArgs
argument_list|(
argument|const llvm::opt::ArgList&DriverArgs
argument_list|,
argument|llvm::opt::ArgStringList&CC1Args
argument_list|)
specifier|const
name|override
block|;
name|void
name|addClangTargetOptions
argument_list|(
argument|const llvm::opt::ArgList&DriverArgs
argument_list|,
argument|llvm::opt::ArgStringList&CC1Args
argument_list|,
argument|Action::OffloadKind DeviceOffloadKind
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|string
name|findLibCxxIncludePath
argument_list|(
argument|ToolChain::CXXStdlibType LibType
argument_list|)
specifier|const
block|;
name|void
name|AddClangCXXStdlibIncludeArgs
argument_list|(
argument|const llvm::opt::ArgList&DriverArgs
argument_list|,
argument|llvm::opt::ArgStringList&CC1Args
argument_list|)
specifier|const
name|override
block|;
name|void
name|AddCXXStdlibLibArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
name|override
block|;
name|void
name|AddLinkRuntimeLib
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
comment|// namespace toolchains
name|namespace
name|tools
block|{
name|namespace
name|baremetal
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Linker
range|:
name|public
name|Tool
block|{
name|public
operator|:
name|Linker
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|Tool
argument_list|(
literal|"baremetal::Linker"
argument_list|,
literal|"ld.lld"
argument_list|,
argument|TC
argument_list|)
block|{}
name|bool
name|isLinkJob
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
name|void
name|ConstructJob
argument_list|(
argument|Compilation&C
argument_list|,
argument|const JobAction&JA
argument_list|,
argument|const InputInfo&Output
argument_list|,
argument|const InputInfoList&Inputs
argument_list|,
argument|const llvm::opt::ArgList&TCArgs
argument_list|,
argument|const char *LinkingOutput
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
block|}
comment|// namespace baremetal
block|}
comment|// namespace tools
block|}
comment|// namespace driver
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

