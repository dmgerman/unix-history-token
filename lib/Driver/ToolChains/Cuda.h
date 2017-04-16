begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Cuda.h - Cuda ToolChain Implementations ----------------*- C++ -*-===//
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
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_CUDA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_CUDA_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Cuda.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/VersionTuple.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Action.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Multilib.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/ToolChain.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Tool.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
comment|/// A class to find a viable CUDA installation
name|class
name|CudaInstallationDetector
block|{
name|private
label|:
specifier|const
name|Driver
modifier|&
name|D
decl_stmt|;
name|bool
name|IsValid
init|=
name|false
decl_stmt|;
name|CudaVersion
name|Version
init|=
name|CudaVersion
operator|::
name|UNKNOWN
decl_stmt|;
name|std
operator|::
name|string
name|InstallPath
expr_stmt|;
name|std
operator|::
name|string
name|BinPath
expr_stmt|;
name|std
operator|::
name|string
name|LibPath
expr_stmt|;
name|std
operator|::
name|string
name|LibDevicePath
expr_stmt|;
name|std
operator|::
name|string
name|IncludePath
expr_stmt|;
name|llvm
operator|::
name|StringMap
operator|<
name|std
operator|::
name|string
operator|>
name|LibDeviceMap
expr_stmt|;
comment|// CUDA architectures for which we have raised an error in
comment|// CheckCudaVersionSupportsArch.
name|mutable
name|llvm
operator|::
name|SmallSet
operator|<
name|CudaArch
operator|,
literal|4
operator|>
name|ArchsWithVersionTooLowErrors
expr_stmt|;
name|public
label|:
name|CudaInstallationDetector
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
name|HostTriple
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
expr_stmt|;
name|void
name|AddCudaIncludeArgs
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|DriverArgs
argument_list|,
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
operator|&
name|CC1Args
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Emit an error if Version does not support the given Arch.
comment|///
comment|/// If either Version or Arch is unknown, does not emit an error.  Emits at
comment|/// most one error per Arch.
name|void
name|CheckCudaVersionSupportsArch
argument_list|(
name|CudaArch
name|Arch
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Check whether we detected a valid Cuda install.
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|IsValid
return|;
block|}
comment|/// \brief Print information about the detected CUDA installation.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Get the detected Cuda install's version.
name|CudaVersion
name|version
argument_list|()
specifier|const
block|{
return|return
name|Version
return|;
block|}
comment|/// \brief Get the detected Cuda installation path.
name|StringRef
name|getInstallPath
argument_list|()
specifier|const
block|{
return|return
name|InstallPath
return|;
block|}
comment|/// \brief Get the detected path to Cuda's bin directory.
name|StringRef
name|getBinPath
argument_list|()
specifier|const
block|{
return|return
name|BinPath
return|;
block|}
comment|/// \brief Get the detected Cuda Include path.
name|StringRef
name|getIncludePath
argument_list|()
specifier|const
block|{
return|return
name|IncludePath
return|;
block|}
comment|/// \brief Get the detected Cuda library path.
name|StringRef
name|getLibPath
argument_list|()
specifier|const
block|{
return|return
name|LibPath
return|;
block|}
comment|/// \brief Get the detected Cuda device library path.
name|StringRef
name|getLibDevicePath
argument_list|()
specifier|const
block|{
return|return
name|LibDevicePath
return|;
block|}
comment|/// \brief Get libdevice file for given architecture
name|std
operator|::
name|string
name|getLibDeviceFile
argument_list|(
argument|StringRef Gpu
argument_list|)
specifier|const
block|{
return|return
name|LibDeviceMap
operator|.
name|lookup
argument_list|(
name|Gpu
argument_list|)
return|;
block|}
block|}
empty_stmt|;
name|namespace
name|tools
block|{
name|namespace
name|NVPTX
block|{
comment|// Run ptxas, the NVPTX assembler.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assembler
range|:
name|public
name|Tool
block|{
name|public
operator|:
name|Assembler
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|Tool
argument_list|(
literal|"NVPTX::Assembler"
argument_list|,
literal|"ptxas"
argument_list|,
argument|TC
argument_list|,
argument|RF_Full
argument_list|,
argument|llvm::sys::WEM_UTF8
argument_list|,
literal|"--options-file"
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
comment|// Runs fatbinary, which combines GPU object files ("cubin" files) and/or PTX
comment|// assembly into a single output file.
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
literal|"NVPTX::Linker"
argument_list|,
literal|"fatbinary"
argument_list|,
argument|TC
argument_list|,
argument|RF_Full
argument_list|,
argument|llvm::sys::WEM_UTF8
argument_list|,
literal|"--options-file"
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
comment|// end namespace NVPTX
block|}
comment|// end namespace tools
name|namespace
name|toolchains
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|CudaToolChain
range|:
name|public
name|ToolChain
block|{
name|public
operator|:
name|CudaToolChain
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
name|ToolChain
operator|&
name|HostTC
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
name|virtual
specifier|const
name|llvm
operator|::
name|Triple
operator|*
name|getAuxTriple
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|HostTC
operator|.
name|getTriple
argument_list|()
return|;
block|}
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
name|void
name|addClangTargetOptions
argument_list|(
argument|const llvm::opt::ArgList&DriverArgs
argument_list|,
argument|llvm::opt::ArgStringList&CC1Args
argument_list|)
specifier|const
name|override
block|;
comment|// Never try to use the integrated assembler with CUDA; always fork out to
comment|// ptxas.
name|bool
name|useIntegratedAs
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
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
name|void
name|addClangWarningOptions
argument_list|(
argument|llvm::opt::ArgStringList&CC1Args
argument_list|)
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
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CC1Args
argument_list|)
specifier|const
name|override
block|;
name|void
name|AddIAMCUIncludeArgs
argument_list|(
argument|const llvm::opt::ArgList&DriverArgs
argument_list|,
argument|llvm::opt::ArgStringList&CC1Args
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
specifier|const
name|ToolChain
operator|&
name|HostTC
block|;
name|CudaInstallationDetector
name|CudaInstallation
block|;
name|protected
operator|:
name|Tool
operator|*
name|buildAssembler
argument_list|()
specifier|const
name|override
block|;
comment|// ptxas
name|Tool
operator|*
name|buildLinker
argument_list|()
specifier|const
name|override
block|;
comment|// fatbinary (ok, not really a linker)
block|}
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
comment|// LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_CUDA_H
end_comment

end_unit

