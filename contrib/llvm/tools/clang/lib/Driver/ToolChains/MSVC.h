begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- MSVC.h - MSVC ToolChain Implementations ----------------*- C++ -*-===//
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
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_MSVC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_MSVC_H
end_define

begin_include
include|#
directive|include
file|"Cuda.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Compilation.h"
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
comment|/// Visual studio tools.
name|namespace
name|visualstudio
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
literal|"visualstudio::Linker"
argument_list|,
literal|"linker"
argument_list|,
argument|TC
argument_list|,
argument|RF_Full
argument_list|,
argument|llvm::sys::WEM_UTF16
argument_list|)
block|{}
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
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Compiler
range|:
name|public
name|Tool
block|{
name|public
operator|:
name|Compiler
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|Tool
argument_list|(
literal|"visualstudio::Compiler"
argument_list|,
literal|"compiler"
argument_list|,
argument|TC
argument_list|,
argument|RF_Full
argument_list|,
argument|llvm::sys::WEM_UTF16
argument_list|)
block|{}
name|bool
name|hasIntegratedAssembler
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
name|true
return|;
block|}
name|bool
name|isLinkJob
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
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|Command
operator|>
name|GetCommand
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
block|; }
decl_stmt|;
block|}
comment|// end namespace visualstudio
block|}
comment|// end namespace tools
name|namespace
name|toolchains
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|MSVCToolChain
range|:
name|public
name|ToolChain
block|{
name|public
operator|:
name|MSVCToolChain
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
name|llvm
operator|::
name|opt
operator|::
name|DerivedArgList
operator|*
name|TranslateArgs
argument_list|(
argument|const llvm::opt::DerivedArgList&Args
argument_list|,
argument|StringRef BoundArch
argument_list|,
argument|Action::OffloadKind DeviceOffloadKind
argument_list|)
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
name|IsUnwindTablesDefault
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
block|;    enum
name|class
name|SubDirectoryType
block|{
name|Bin
block|,
name|Include
block|,
name|Lib
block|,   }
block|;
name|std
operator|::
name|string
name|getSubDirectoryPath
argument_list|(
argument|SubDirectoryType Type
argument_list|,
argument|llvm::Triple::ArchType TargetArch
argument_list|)
specifier|const
block|;
comment|// Convenience overload.
comment|// Uses the current target arch.
name|std
operator|::
name|string
name|getSubDirectoryPath
argument_list|(
argument|SubDirectoryType Type
argument_list|)
specifier|const
block|{
return|return
name|getSubDirectoryPath
argument_list|(
name|Type
argument_list|,
name|getArch
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|getIsVS2017OrNewer
argument_list|()
specifier|const
block|{
return|return
name|IsVS2017OrNewer
return|;
block|}
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
name|void
name|AddCudaIncludeArgs
argument_list|(
argument|const llvm::opt::ArgList&DriverArgs
argument_list|,
argument|llvm::opt::ArgStringList&CC1Args
argument_list|)
specifier|const
name|override
block|;
name|bool
name|getWindowsSDKLibraryPath
argument_list|(
argument|std::string&path
argument_list|)
specifier|const
block|;
comment|/// \brief Check if Universal CRT should be used if available
name|bool
name|getUniversalCRTLibraryPath
argument_list|(
argument|std::string&path
argument_list|)
specifier|const
block|;
name|bool
name|useUniversalCRT
argument_list|()
specifier|const
block|;
name|VersionTuple
name|computeMSVCVersion
argument_list|(
argument|const Driver *D
argument_list|,
argument|const llvm::opt::ArgList&Args
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|string
name|ComputeEffectiveClangTriple
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|types::ID InputType
argument_list|)
specifier|const
name|override
block|;
name|SanitizerMask
name|getSupportedSanitizers
argument_list|()
specifier|const
name|override
block|;
name|void
name|printVerboseInfo
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
name|override
block|;
name|protected
operator|:
name|void
name|AddSystemIncludeWithSubfolder
argument_list|(
argument|const llvm::opt::ArgList&DriverArgs
argument_list|,
argument|llvm::opt::ArgStringList&CC1Args
argument_list|,
argument|const std::string&folder
argument_list|,
argument|const Twine&subfolder1
argument_list|,
argument|const Twine&subfolder2 =
literal|""
argument_list|,
argument|const Twine&subfolder3 =
literal|""
argument_list|)
specifier|const
block|;
name|Tool
operator|*
name|buildLinker
argument_list|()
specifier|const
name|override
block|;
name|Tool
operator|*
name|buildAssembler
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
name|std
operator|::
name|string
name|VCToolChainPath
block|;
name|bool
name|IsVS2017OrNewer
operator|=
name|false
block|;
name|CudaInstallationDetector
name|CudaInstallation
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
comment|// LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_MSVC_H
end_comment

end_unit

