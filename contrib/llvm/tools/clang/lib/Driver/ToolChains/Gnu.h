begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Gnu.h - Gnu Tool and ToolChain Implementations ---------*- C++ -*-===//
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
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_GNU_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_GNU_H
end_define

begin_include
include|#
directive|include
file|"Cuda.h"
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

begin_include
include|#
directive|include
file|<set>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
struct|struct
name|DetectedMultilibs
block|{
comment|/// The set of multilibs that the detected installation supports.
name|MultilibSet
name|Multilibs
decl_stmt|;
comment|/// The primary multilib appropriate for the given flags.
name|Multilib
name|SelectedMultilib
decl_stmt|;
comment|/// On Biarch systems, this corresponds to the default multilib when
comment|/// targeting the non-default multilib. Otherwise, it is empty.
name|llvm
operator|::
name|Optional
operator|<
name|Multilib
operator|>
name|BiarchSibling
expr_stmt|;
block|}
struct|;
name|bool
name|findMIPSMultilibs
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
name|TargetTriple
argument_list|,
name|StringRef
name|Path
argument_list|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
name|DetectedMultilibs
operator|&
name|Result
argument_list|)
decl_stmt|;
name|namespace
name|tools
block|{
comment|/// \brief Base class for all GNU tools that provide the same behavior when
comment|/// it comes to response files support
name|class
name|LLVM_LIBRARY_VISIBILITY
name|GnuTool
range|:
name|public
name|Tool
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|GnuTool
argument_list|(
specifier|const
name|char
operator|*
name|Name
argument_list|,
specifier|const
name|char
operator|*
name|ShortName
argument_list|,
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|Tool
argument_list|(
argument|Name
argument_list|,
argument|ShortName
argument_list|,
argument|TC
argument_list|,
argument|RF_Full
argument_list|,
argument|llvm::sys::WEM_CurrentCodePage
argument_list|)
block|{}
block|}
decl_stmt|;
comment|/// Directly call GNU Binutils' assembler and linker.
name|namespace
name|gnutools
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assembler
range|:
name|public
name|GnuTool
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
name|GnuTool
argument_list|(
literal|"GNU::Assembler"
argument_list|,
literal|"assembler"
argument_list|,
argument|TC
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
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Linker
range|:
name|public
name|GnuTool
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
name|GnuTool
argument_list|(
literal|"GNU::Linker"
argument_list|,
literal|"linker"
argument_list|,
argument|TC
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
block|}
comment|// end namespace gnutools
comment|/// gcc - Generic GCC tool implementations.
name|namespace
name|gcc
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Common
range|:
name|public
name|GnuTool
block|{
name|public
operator|:
name|Common
argument_list|(
specifier|const
name|char
operator|*
name|Name
argument_list|,
specifier|const
name|char
operator|*
name|ShortName
argument_list|,
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|GnuTool
argument_list|(
argument|Name
argument_list|,
argument|ShortName
argument_list|,
argument|TC
argument_list|)
block|{}
comment|// A gcc tool has an "integrated" assembler that it will call to produce an
comment|// object. Let it use that assembler so that we don't have to deal with
comment|// assembly syntax incompatibilities.
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
comment|/// RenderExtraToolArgs - Render any arguments necessary to force
comment|/// the particular tool mode.
name|virtual
name|void
name|RenderExtraToolArgs
argument_list|(
argument|const JobAction&JA
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
operator|=
literal|0
block|; }
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Preprocessor
range|:
name|public
name|Common
block|{
name|public
operator|:
name|Preprocessor
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|Common
argument_list|(
literal|"gcc::Preprocessor"
argument_list|,
literal|"gcc preprocessor"
argument_list|,
argument|TC
argument_list|)
block|{}
name|bool
name|hasGoodDiagnostics
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
name|RenderExtraToolArgs
argument_list|(
argument|const JobAction&JA
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
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
name|Common
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
name|Common
argument_list|(
literal|"gcc::Compiler"
argument_list|,
literal|"gcc frontend"
argument_list|,
argument|TC
argument_list|)
block|{}
name|bool
name|hasGoodDiagnostics
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
name|void
name|RenderExtraToolArgs
argument_list|(
argument|const JobAction&JA
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Linker
range|:
name|public
name|Common
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
name|Common
argument_list|(
literal|"gcc::Linker"
argument_list|,
literal|"linker (via gcc)"
argument_list|,
argument|TC
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
name|RenderExtraToolArgs
argument_list|(
argument|const JobAction&JA
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
block|}
comment|// end namespace gcc
block|}
comment|// end namespace tools
name|namespace
name|toolchains
block|{
comment|/// Generic_GCC - A tool chain using the 'gcc' command to perform
comment|/// all subcommands; this relies on gcc translating the majority of
comment|/// command line options.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Generic_GCC
range|:
name|public
name|ToolChain
block|{
name|public
operator|:
comment|/// \brief Struct to store and manipulate GCC versions.
comment|///
comment|/// We rely on assumptions about the form and structure of GCC version
comment|/// numbers: they consist of at most three '.'-separated components, and each
comment|/// component is a non-negative integer except for the last component. For
comment|/// the last component we are very flexible in order to tolerate release
comment|/// candidates or 'x' wildcards.
comment|///
comment|/// Note that the ordering established among GCCVersions is based on the
comment|/// preferred version string to use. For example we prefer versions without
comment|/// a hard-coded patch number to those with a hard coded patch number.
comment|///
comment|/// Currently this doesn't provide any logic for textual suffixes to patches
comment|/// in the way that (for example) Debian's version format does. If that ever
comment|/// becomes necessary, it can be added.
expr|struct
name|GCCVersion
block|{
comment|/// \brief The unparsed text of the version.
name|std
operator|::
name|string
name|Text
block|;
comment|/// \brief The parsed major, minor, and patch numbers.
name|int
name|Major
block|,
name|Minor
block|,
name|Patch
block|;
comment|/// \brief The text of the parsed major, and major+minor versions.
name|std
operator|::
name|string
name|MajorStr
block|,
name|MinorStr
block|;
comment|/// \brief Any textual suffix on the patch number.
name|std
operator|::
name|string
name|PatchSuffix
block|;
specifier|static
name|GCCVersion
name|Parse
argument_list|(
argument|StringRef VersionText
argument_list|)
block|;
name|bool
name|isOlderThan
argument_list|(
argument|int RHSMajor
argument_list|,
argument|int RHSMinor
argument_list|,
argument|int RHSPatch
argument_list|,
argument|StringRef RHSPatchSuffix = StringRef()
argument_list|)
specifier|const
block|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|GCCVersion
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|isOlderThan
argument_list|(
name|RHS
operator|.
name|Major
argument_list|,
name|RHS
operator|.
name|Minor
argument_list|,
name|RHS
operator|.
name|Patch
argument_list|,
name|RHS
operator|.
name|PatchSuffix
argument_list|)
return|;
block|}
name|bool
name|operator
operator|>
operator|(
specifier|const
name|GCCVersion
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|RHS
operator|<
operator|*
name|this
return|;
block|}
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|GCCVersion
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|>
name|RHS
operator|)
return|;
block|}
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|GCCVersion
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|<
name|RHS
operator|)
return|;
block|}
expr|}
block|;
comment|/// \brief This is a class to find a viable GCC installation for Clang to
comment|/// use.
comment|///
comment|/// This class tries to find a GCC installation on the system, and report
comment|/// information about it. It starts from the host information provided to the
comment|/// Driver, and has logic for fuzzing that where appropriate.
name|class
name|GCCInstallationDetector
block|{
name|bool
name|IsValid
block|;
name|llvm
operator|::
name|Triple
name|GCCTriple
block|;
specifier|const
name|Driver
operator|&
name|D
block|;
comment|// FIXME: These might be better as path objects.
name|std
operator|::
name|string
name|GCCInstallPath
block|;
name|std
operator|::
name|string
name|GCCParentLibPath
block|;
comment|/// The primary multilib appropriate for the given flags.
name|Multilib
name|SelectedMultilib
block|;
comment|/// On Biarch systems, this corresponds to the default multilib when
comment|/// targeting the non-default multilib. Otherwise, it is empty.
name|llvm
operator|::
name|Optional
operator|<
name|Multilib
operator|>
name|BiarchSibling
block|;
name|GCCVersion
name|Version
block|;
comment|// We retain the list of install paths that were considered and rejected in
comment|// order to print out detailed information in verbose mode.
name|std
operator|::
name|set
operator|<
name|std
operator|::
name|string
operator|>
name|CandidateGCCInstallPaths
block|;
comment|/// The set of multilibs that the detected installation supports.
name|MultilibSet
name|Multilibs
block|;
name|public
operator|:
name|explicit
name|GCCInstallationDetector
argument_list|(
specifier|const
name|Driver
operator|&
name|D
argument_list|)
operator|:
name|IsValid
argument_list|(
name|false
argument_list|)
block|,
name|D
argument_list|(
argument|D
argument_list|)
block|{}
name|void
name|init
argument_list|(
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|TargetTriple
argument_list|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|ExtraTripleAliases
operator|=
name|None
argument_list|)
block|;
comment|/// \brief Check whether we detected a valid GCC install.
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|IsValid
return|;
block|}
comment|/// \brief Get the GCC triple for the detected install.
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
name|GCCTriple
return|;
block|}
comment|/// \brief Get the detected GCC installation path.
name|StringRef
name|getInstallPath
argument_list|()
specifier|const
block|{
return|return
name|GCCInstallPath
return|;
block|}
comment|/// \brief Get the detected GCC parent lib path.
name|StringRef
name|getParentLibPath
argument_list|()
specifier|const
block|{
return|return
name|GCCParentLibPath
return|;
block|}
comment|/// \brief Get the detected Multilib
specifier|const
name|Multilib
operator|&
name|getMultilib
argument_list|()
specifier|const
block|{
return|return
name|SelectedMultilib
return|;
block|}
comment|/// \brief Get the whole MultilibSet
specifier|const
name|MultilibSet
operator|&
name|getMultilibs
argument_list|()
specifier|const
block|{
return|return
name|Multilibs
return|;
block|}
comment|/// Get the biarch sibling multilib (if it exists).
comment|/// \return true iff such a sibling exists
name|bool
name|getBiarchSibling
argument_list|(
argument|Multilib&M
argument_list|)
specifier|const
block|;
comment|/// \brief Get the detected GCC version string.
specifier|const
name|GCCVersion
operator|&
name|getVersion
argument_list|()
specifier|const
block|{
return|return
name|Version
return|;
block|}
comment|/// \brief Print information about the detected GCC installation.
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
name|private
operator|:
specifier|static
name|void
name|CollectLibDirsAndTriples
argument_list|(
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|TargetTriple
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|BiarchTriple
argument_list|,
name|SmallVectorImpl
operator|<
name|StringRef
operator|>
operator|&
name|LibDirs
argument_list|,
name|SmallVectorImpl
operator|<
name|StringRef
operator|>
operator|&
name|TripleAliases
argument_list|,
name|SmallVectorImpl
operator|<
name|StringRef
operator|>
operator|&
name|BiarchLibDirs
argument_list|,
name|SmallVectorImpl
operator|<
name|StringRef
operator|>
operator|&
name|BiarchTripleAliases
argument_list|)
block|;
name|bool
name|ScanGCCForMultilibs
argument_list|(
argument|const llvm::Triple&TargetTriple
argument_list|,
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|StringRef Path
argument_list|,
argument|bool NeedsBiarchSuffix = false
argument_list|)
block|;
name|void
name|ScanLibDirForGCCTriple
argument_list|(
argument|const llvm::Triple&TargetArch
argument_list|,
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|const std::string&LibDir
argument_list|,
argument|StringRef CandidateTriple
argument_list|,
argument|bool NeedsBiarchSuffix = false
argument_list|)
block|;
name|void
name|scanLibDirForGCCTripleSolaris
argument_list|(
argument|const llvm::Triple&TargetArch
argument_list|,
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|const std::string&LibDir
argument_list|,
argument|StringRef CandidateTriple
argument_list|,
argument|bool NeedsBiarchSuffix = false
argument_list|)
block|;
name|bool
name|ScanGentooGccConfig
argument_list|(
argument|const llvm::Triple&TargetTriple
argument_list|,
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|StringRef CandidateTriple
argument_list|,
argument|bool NeedsBiarchSuffix = false
argument_list|)
block|;   }
block|;
name|protected
operator|:
name|GCCInstallationDetector
name|GCCInstallation
block|;
name|CudaInstallationDetector
name|CudaInstallation
block|;
name|public
operator|:
name|Generic_GCC
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
name|Generic_GCC
argument_list|()
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
block|;
name|bool
name|IsIntegratedAssemblerDefault
argument_list|()
specifier|const
name|override
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
name|protected
operator|:
name|Tool
operator|*
name|getTool
argument_list|(
argument|Action::ActionClass AC
argument_list|)
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
name|Tool
operator|*
name|buildLinker
argument_list|()
specifier|const
name|override
block|;
comment|/// \name ToolChain Implementation Helper Functions
comment|/// @{
comment|/// \brief Check whether the target triple's architecture is 64-bits.
name|bool
name|isTarget64Bit
argument_list|()
specifier|const
block|{
return|return
name|getTriple
argument_list|()
operator|.
name|isArch64Bit
argument_list|()
return|;
block|}
comment|/// \brief Check whether the target triple's architecture is 32-bits.
name|bool
name|isTarget32Bit
argument_list|()
specifier|const
block|{
return|return
name|getTriple
argument_list|()
operator|.
name|isArch32Bit
argument_list|()
return|;
block|}
comment|// FIXME: This should be final, but the Solaris tool chain does weird
comment|// things we can't easily represent.
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
name|virtual
name|std
operator|::
name|string
name|findLibCxxIncludePath
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|addLibStdCxxIncludePaths
argument_list|(
argument|const llvm::opt::ArgList&DriverArgs
argument_list|,
argument|llvm::opt::ArgStringList&CC1Args
argument_list|)
specifier|const
block|;
name|bool
name|addLibStdCXXIncludePaths
argument_list|(
argument|Twine Base
argument_list|,
argument|Twine Suffix
argument_list|,
argument|StringRef GCCTriple
argument_list|,
argument|StringRef GCCMultiarchTriple
argument_list|,
argument|StringRef TargetMultiarchTriple
argument_list|,
argument|Twine IncludeSuffix
argument_list|,
argument|const llvm::opt::ArgList&DriverArgs
argument_list|,
argument|llvm::opt::ArgStringList&CC1Args
argument_list|)
specifier|const
block|;
comment|/// @}
name|private
operator|:
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|tools
operator|::
name|gcc
operator|::
name|Preprocessor
operator|>
name|Preprocess
block|;
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|tools
operator|::
name|gcc
operator|::
name|Compiler
operator|>
name|Compile
block|; }
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Generic_ELF
operator|:
name|public
name|Generic_GCC
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|Generic_ELF
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
operator|:
name|Generic_GCC
argument_list|(
argument|D
argument_list|,
argument|Triple
argument_list|,
argument|Args
argument_list|)
block|{}
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
block|; }
block|;  }
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
comment|// LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_GNU_H
end_comment

end_unit

