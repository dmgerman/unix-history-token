begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- WebAssembly.h - WebAssembly ToolChain Implementations --*- C++ -*-===//
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
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_WEBASSEMBLY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_WEBASSEMBLY_H
end_define

begin_include
include|#
directive|include
file|"Gnu.h"
end_include

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

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
name|namespace
name|tools
block|{
name|namespace
name|wasm
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Linker
range|:
name|public
name|GnuTool
block|{
name|public
operator|:
name|explicit
name|Linker
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
block|;
name|bool
name|isLinkJob
argument_list|()
specifier|const
name|override
block|;
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
name|override
block|;
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
comment|// end namespace wasm
block|}
comment|// end namespace tools
name|namespace
name|toolchains
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|WebAssembly
name|final
range|:
name|public
name|ToolChain
block|{
name|public
operator|:
name|WebAssembly
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
name|private
operator|:
name|bool
name|IsMathErrnoDefault
argument_list|()
specifier|const
name|override
block|;
name|bool
name|IsObjCNonFragileABIDefault
argument_list|()
specifier|const
name|override
block|;
name|bool
name|UseObjCMixedDispatch
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isPICDefault
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isPIEDefault
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isPICDefaultForced
argument_list|()
specifier|const
name|override
block|;
name|bool
name|IsIntegratedAssemblerDefault
argument_list|()
specifier|const
name|override
block|;
name|bool
name|hasBlocksRuntime
argument_list|()
specifier|const
name|override
block|;
name|bool
name|SupportsObjCGC
argument_list|()
specifier|const
name|override
block|;
name|bool
name|SupportsProfiling
argument_list|()
specifier|const
name|override
block|;
name|bool
name|HasNativeLLVMSupport
argument_list|()
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
name|RuntimeLibType
name|GetDefaultRuntimeLibType
argument_list|()
specifier|const
name|override
block|;
name|CXXStdlibType
name|GetCXXStdlibType
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|)
specifier|const
name|override
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
name|AddClangCXXStdlibIncludeArgs
argument_list|(
argument|const llvm::opt::ArgList&DriverArgs
argument_list|,
argument|llvm::opt::ArgStringList&CC1Args
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|char
operator|*
name|getDefaultLinker
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"lld"
return|;
block|}
name|Tool
operator|*
name|buildLinker
argument_list|()
specifier|const
name|override
block|; }
decl_stmt|;
block|}
comment|// end namespace toolchains
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

begin_comment
comment|// LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_WEBASSEMBLY_H
end_comment

end_unit

