begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Darwin.h - Darwin ToolChain Implementations ------------*- C++ -*-===//
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
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_DARWIN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_DARWIN_H
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
name|MachO
decl_stmt|;
block|}
comment|// end namespace toolchains
name|namespace
name|tools
block|{
name|namespace
name|darwin
block|{
name|llvm
operator|::
name|Triple
operator|::
name|ArchType
name|getArchTypeForMachOArchName
argument_list|(
argument|StringRef Str
argument_list|)
expr_stmt|;
name|void
name|setTripleTypeForMachOArchName
argument_list|(
name|llvm
operator|::
name|Triple
operator|&
name|T
argument_list|,
name|StringRef
name|Str
argument_list|)
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|MachOTool
range|:
name|public
name|Tool
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|protected
operator|:
name|void
name|AddMachOArch
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;
specifier|const
name|toolchains
operator|::
name|MachO
operator|&
name|getMachOToolChain
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|toolchains
operator|::
name|MachO
operator|&
operator|>
operator|(
name|getToolChain
argument_list|()
operator|)
return|;
block|}
name|public
operator|:
name|MachOTool
argument_list|(
argument|const char *Name
argument_list|,
argument|const char *ShortName
argument_list|,
argument|const ToolChain&TC
argument_list|,
argument|ResponseFileSupport ResponseSupport = RF_None
argument_list|,
argument|llvm::sys::WindowsEncodingMethod ResponseEncoding = llvm::sys::WEM_UTF8
argument_list|,
argument|const char *ResponseFlag =
literal|"@"
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
argument|ResponseSupport
argument_list|,
argument|ResponseEncoding
argument_list|,
argument|ResponseFlag
argument_list|)
block|{}
expr|}
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assembler
operator|:
name|public
name|MachOTool
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
name|MachOTool
argument_list|(
literal|"darwin::Assembler"
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
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Linker
operator|:
name|public
name|MachOTool
block|{
name|bool
name|NeedsTempPath
argument_list|(
argument|const InputInfoList&Inputs
argument_list|)
specifier|const
block|;
name|void
name|AddLinkArgs
argument_list|(
argument|Compilation&C
argument_list|,
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|,
argument|const InputInfoList&Inputs
argument_list|)
specifier|const
block|;
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
name|MachOTool
argument_list|(
literal|"darwin::Linker"
argument_list|,
literal|"linker"
argument_list|,
argument|TC
argument_list|,
argument|RF_FileList
argument_list|,
argument|llvm::sys::WEM_UTF8
argument_list|,
literal|"-filelist"
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
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Lipo
operator|:
name|public
name|MachOTool
block|{
name|public
operator|:
name|Lipo
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|MachOTool
argument_list|(
literal|"darwin::Lipo"
argument_list|,
literal|"lipo"
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
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Dsymutil
operator|:
name|public
name|MachOTool
block|{
name|public
operator|:
name|Dsymutil
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|MachOTool
argument_list|(
literal|"darwin::Dsymutil"
argument_list|,
literal|"dsymutil"
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
name|isDsymutilJob
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
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|VerifyDebug
operator|:
name|public
name|MachOTool
block|{
name|public
operator|:
name|VerifyDebug
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|MachOTool
argument_list|(
literal|"darwin::VerifyDebug"
argument_list|,
literal|"dwarfdump"
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
block|; }
comment|// end namespace darwin
block|}
comment|// end namespace tools
name|namespace
name|toolchains
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|MachO
range|:
name|public
name|ToolChain
block|{
name|protected
operator|:
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
name|Tool
operator|*
name|getTool
argument_list|(
argument|Action::ActionClass AC
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|tools
operator|::
name|darwin
operator|::
name|Lipo
operator|>
name|Lipo
block|;
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|tools
operator|::
name|darwin
operator|::
name|Dsymutil
operator|>
name|Dsymutil
block|;
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|tools
operator|::
name|darwin
operator|::
name|VerifyDebug
operator|>
name|VerifyDebug
block|;
name|public
operator|:
name|MachO
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
name|MachO
argument_list|()
name|override
block|;
comment|/// @name MachO specific toolchain API
comment|/// {
comment|/// Get the "MachO" arch name for a particular compiler invocation. For
comment|/// example, Apple treats different ARM variations as distinct architectures.
name|StringRef
name|getMachOArchName
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|)
specifier|const
block|;
comment|/// Add the linker arguments to link the ARC runtime library.
name|virtual
name|void
name|AddLinkARCArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|{}
comment|/// Add the linker arguments to link the compiler runtime library.
name|virtual
name|void
name|AddLinkRuntimeLibArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|AddFuzzerLinkArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|addStartObjectFileArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|{   }
name|virtual
name|void
name|addMinVersionArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|{}
comment|/// On some iOS platforms, kernel and kernel modules were built statically. Is
comment|/// this such a target?
name|virtual
name|bool
name|isKernelStatic
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Is the target either iOS or an iOS simulator?
name|bool
name|isTargetIOSBased
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|void
name|AddLinkRuntimeLib
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|,
argument|StringRef DarwinLibName
argument_list|,
argument|bool AlwaysLink = false
argument_list|,
argument|bool IsEmbedded = false
argument_list|,
argument|bool AddRPath = false
argument_list|)
specifier|const
block|;
comment|/// Add any profiling runtime libraries that are needed. This is essentially a
comment|/// MachO specific version of addProfileRT in Tools.cpp.
name|void
name|addProfileRTLibs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
name|override
block|{
comment|// There aren't any profiling libs for embedded targets currently.
block|}
comment|/// }
comment|/// @name ToolChain Implementation
comment|/// {
name|types
operator|::
name|ID
name|LookupTypeForExtension
argument_list|(
argument|StringRef Ext
argument_list|)
specifier|const
name|override
block|;
name|bool
name|HasNativeLLVMSupport
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
name|bool
name|IsBlocksDefault
argument_list|()
specifier|const
name|override
block|{
comment|// Always allow blocks on Apple; users interested in versioning are
comment|// expected to use /usr/include/Block.h.
return|return
name|true
return|;
block|}
name|bool
name|IsIntegratedAssemblerDefault
argument_list|()
specifier|const
name|override
block|{
comment|// Default integrated assembler to on for Apple's MachO targets.
return|return
name|true
return|;
block|}
name|bool
name|IsMathErrnoDefault
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
name|bool
name|IsEncodeExtendedBlockSignatureDefault
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|IsObjCNonFragileABIDefault
argument_list|()
specifier|const
name|override
block|{
comment|// Non-fragile ABI is default for everything but i386.
return|return
name|getTriple
argument_list|()
operator|.
name|getArch
argument_list|()
operator|!=
name|llvm
operator|::
name|Triple
operator|::
name|x86
return|;
block|}
name|bool
name|UseObjCMixedDispatch
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|IsUnwindTablesDefault
argument_list|()
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
name|SupportsProfiling
argument_list|()
specifier|const
name|override
block|;
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
name|bool
name|UseDwarfDebugFlags
argument_list|()
specifier|const
name|override
block|;
name|bool
name|UseSjLjExceptions
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|)
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
comment|/// }
expr|}
block|;
comment|/// Darwin - The base Darwin tool chain.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Darwin
operator|:
name|public
name|MachO
block|{
name|public
operator|:
comment|/// Whether the information on the target has been initialized.
comment|//
comment|// FIXME: This should be eliminated. What we want to do is make this part of
comment|// the "default target for arguments" selection process, once we get out of
comment|// the argument translation business.
name|mutable
name|bool
name|TargetInitialized
block|;    enum
name|DarwinPlatformKind
block|{
name|MacOS
block|,
name|IPhoneOS
block|,
name|IPhoneOSSimulator
block|,
name|TvOS
block|,
name|TvOSSimulator
block|,
name|WatchOS
block|,
name|WatchOSSimulator
block|}
block|;
name|mutable
name|DarwinPlatformKind
name|TargetPlatform
block|;
comment|/// The OS version we are targeting.
name|mutable
name|VersionTuple
name|TargetVersion
block|;
name|CudaInstallationDetector
name|CudaInstallation
block|;
name|private
operator|:
name|void
name|AddDeploymentTarget
argument_list|(
argument|llvm::opt::DerivedArgList&Args
argument_list|)
specifier|const
block|;
name|public
operator|:
name|Darwin
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
name|Darwin
argument_list|()
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
comment|/// @name Apple Specific Toolchain Implementation
comment|/// {
name|void
name|addMinVersionArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
name|override
block|;
name|void
name|addStartObjectFileArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isKernelStatic
argument_list|()
specifier|const
name|override
block|{
return|return
operator|(
operator|!
operator|(
name|isTargetIPhoneOS
argument_list|()
operator|&&
operator|!
name|isIPhoneOSVersionLT
argument_list|(
literal|6
argument_list|,
literal|0
argument_list|)
operator|)
operator|&&
operator|!
name|isTargetWatchOS
argument_list|()
operator|)
return|;
block|}
name|void
name|addProfileRTLibs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
name|override
block|;
name|protected
operator|:
comment|/// }
comment|/// @name Darwin specific Toolchain functions
comment|/// {
comment|// FIXME: Eliminate these ...Target functions and derive separate tool chains
comment|// for these targets and put version in constructor.
name|void
name|setTarget
argument_list|(
argument|DarwinPlatformKind Platform
argument_list|,
argument|unsigned Major
argument_list|,
argument|unsigned Minor
argument_list|,
argument|unsigned Micro
argument_list|)
specifier|const
block|{
comment|// FIXME: For now, allow reinitialization as long as values don't
comment|// change. This will go away when we move away from argument translation.
if|if
condition|(
name|TargetInitialized
operator|&&
name|TargetPlatform
operator|==
name|Platform
operator|&&
name|TargetVersion
operator|==
name|VersionTuple
argument_list|(
name|Major
argument_list|,
name|Minor
argument_list|,
name|Micro
argument_list|)
condition|)
return|return;
name|assert
argument_list|(
operator|!
name|TargetInitialized
operator|&&
literal|"Target already initialized!"
argument_list|)
block|;
name|TargetInitialized
operator|=
name|true
block|;
name|TargetPlatform
operator|=
name|Platform
block|;
name|TargetVersion
operator|=
name|VersionTuple
argument_list|(
name|Major
argument_list|,
name|Minor
argument_list|,
name|Micro
argument_list|)
block|;   }
name|bool
name|isTargetIPhoneOS
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|TargetInitialized
operator|&&
literal|"Target not initialized!"
argument_list|)
block|;
return|return
name|TargetPlatform
operator|==
name|IPhoneOS
operator|||
name|TargetPlatform
operator|==
name|TvOS
return|;
block|}
name|bool
name|isTargetIOSSimulator
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|TargetInitialized
operator|&&
literal|"Target not initialized!"
argument_list|)
block|;
return|return
name|TargetPlatform
operator|==
name|IPhoneOSSimulator
operator|||
name|TargetPlatform
operator|==
name|TvOSSimulator
return|;
block|}
name|bool
name|isTargetIOSBased
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|TargetInitialized
operator|&&
literal|"Target not initialized!"
argument_list|)
block|;
return|return
name|isTargetIPhoneOS
argument_list|()
operator|||
name|isTargetIOSSimulator
argument_list|()
return|;
block|}
name|bool
name|isTargetTvOS
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|TargetInitialized
operator|&&
literal|"Target not initialized!"
argument_list|)
block|;
return|return
name|TargetPlatform
operator|==
name|TvOS
return|;
block|}
name|bool
name|isTargetTvOSSimulator
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|TargetInitialized
operator|&&
literal|"Target not initialized!"
argument_list|)
block|;
return|return
name|TargetPlatform
operator|==
name|TvOSSimulator
return|;
block|}
name|bool
name|isTargetTvOSBased
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|TargetInitialized
operator|&&
literal|"Target not initialized!"
argument_list|)
block|;
return|return
name|TargetPlatform
operator|==
name|TvOS
operator|||
name|TargetPlatform
operator|==
name|TvOSSimulator
return|;
block|}
name|bool
name|isTargetWatchOS
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|TargetInitialized
operator|&&
literal|"Target not initialized!"
argument_list|)
block|;
return|return
name|TargetPlatform
operator|==
name|WatchOS
return|;
block|}
name|bool
name|isTargetWatchOSSimulator
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|TargetInitialized
operator|&&
literal|"Target not initialized!"
argument_list|)
block|;
return|return
name|TargetPlatform
operator|==
name|WatchOSSimulator
return|;
block|}
name|bool
name|isTargetWatchOSBased
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|TargetInitialized
operator|&&
literal|"Target not initialized!"
argument_list|)
block|;
return|return
name|TargetPlatform
operator|==
name|WatchOS
operator|||
name|TargetPlatform
operator|==
name|WatchOSSimulator
return|;
block|}
name|bool
name|isTargetMacOS
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|TargetInitialized
operator|&&
literal|"Target not initialized!"
argument_list|)
block|;
return|return
name|TargetPlatform
operator|==
name|MacOS
return|;
block|}
name|bool
name|isTargetInitialized
argument_list|()
specifier|const
block|{
return|return
name|TargetInitialized
return|;
block|}
name|VersionTuple
name|getTargetVersion
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|TargetInitialized
operator|&&
literal|"Target not initialized!"
argument_list|)
block|;
return|return
name|TargetVersion
return|;
block|}
name|bool
name|isIPhoneOSVersionLT
argument_list|(
argument|unsigned V0
argument_list|,
argument|unsigned V1 =
literal|0
argument_list|,
argument|unsigned V2 =
literal|0
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|isTargetIOSBased
argument_list|()
operator|&&
literal|"Unexpected call for non iOS target!"
argument_list|)
block|;
return|return
name|TargetVersion
operator|<
name|VersionTuple
argument_list|(
name|V0
argument_list|,
name|V1
argument_list|,
name|V2
argument_list|)
return|;
block|}
name|bool
name|isMacosxVersionLT
argument_list|(
argument|unsigned V0
argument_list|,
argument|unsigned V1 =
literal|0
argument_list|,
argument|unsigned V2 =
literal|0
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|isTargetMacOS
argument_list|()
operator|&&
literal|"Unexpected call for non OS X target!"
argument_list|)
block|;
return|return
name|TargetVersion
operator|<
name|VersionTuple
argument_list|(
name|V0
argument_list|,
name|V1
argument_list|,
name|V2
argument_list|)
return|;
block|}
name|StringRef
name|getPlatformFamily
argument_list|()
specifier|const
block|;
specifier|static
name|StringRef
name|getSDKName
argument_list|(
argument|StringRef isysroot
argument_list|)
block|;
name|StringRef
name|getOSLibraryNameSuffix
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// }
comment|/// @name ToolChain Implementation
comment|/// {
comment|// Darwin tools support multiple architecture (e.g., i386 and x86_64) and
comment|// most development is done against SDKs, so compiling for a different
comment|// architecture should not get any special treatment.
name|bool
name|isCrossCompiling
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
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
name|CXXStdlibType
name|GetDefaultCXXStdlibType
argument_list|()
specifier|const
name|override
block|;
name|ObjCRuntime
name|getDefaultObjCRuntime
argument_list|(
argument|bool isNonFragile
argument_list|)
specifier|const
name|override
block|;
name|bool
name|hasBlocksRuntime
argument_list|()
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
name|UseObjCMixedDispatch
argument_list|()
specifier|const
name|override
block|{
comment|// This is only used with the non-fragile ABI and non-legacy dispatch.
comment|// Mixed dispatch is used everywhere except OS X before 10.6.
return|return
operator|!
operator|(
name|isTargetMacOS
argument_list|()
operator|&&
name|isMacosxVersionLT
argument_list|(
literal|10
argument_list|,
literal|6
argument_list|)
operator|)
return|;
block|}
name|unsigned
name|GetDefaultStackProtectorLevel
argument_list|(
argument|bool KernelOrKext
argument_list|)
specifier|const
name|override
block|{
comment|// Stack protectors default to on for user code on 10.5,
comment|// and for everything in 10.6 and beyond
if|if
condition|(
name|isTargetIOSBased
argument_list|()
operator|||
name|isTargetWatchOSBased
argument_list|()
condition|)
return|return
literal|1
return|;
elseif|else
if|if
condition|(
name|isTargetMacOS
argument_list|()
operator|&&
operator|!
name|isMacosxVersionLT
argument_list|(
literal|10
argument_list|,
literal|6
argument_list|)
condition|)
return|return
literal|1
return|;
elseif|else
if|if
condition|(
name|isTargetMacOS
argument_list|()
operator|&&
operator|!
name|isMacosxVersionLT
argument_list|(
literal|10
argument_list|,
literal|5
argument_list|)
operator|&&
operator|!
name|KernelOrKext
condition|)
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
name|bool
name|SupportsObjCGC
argument_list|()
specifier|const
name|override
expr_stmt|;
name|void
name|CheckObjCARC
argument_list|()
specifier|const
name|override
expr_stmt|;
name|bool
name|UseSjLjExceptions
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|SupportsEmbeddedBitcode
argument_list|()
specifier|const
name|override
expr_stmt|;
name|SanitizerMask
name|getSupportedSanitizers
argument_list|()
specifier|const
name|override
expr_stmt|;
name|void
name|printVerboseInfo
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
name|override
decl_stmt|;
block|}
empty_stmt|;
comment|/// DarwinClang - The Darwin toolchain used by Clang.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|DarwinClang
range|:
name|public
name|Darwin
block|{
name|public
operator|:
name|DarwinClang
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
comment|/// @name Apple ToolChain Implementation
comment|/// {
name|RuntimeLibType
name|GetRuntimeLibType
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|)
specifier|const
name|override
block|;
name|void
name|AddLinkRuntimeLibArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
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
name|AddCCKextLibArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
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
name|void
name|AddLinkARCArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|GetDefaultDwarfVersion
argument_list|()
specifier|const
name|override
block|;
comment|// Until dtrace (via CTF) and LLDB can deal with distributed debug info,
comment|// Darwin defaults to standalone/full debug info.
name|bool
name|GetDefaultStandaloneDebug
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|llvm
operator|::
name|DebuggerKind
name|getDefaultDebuggerTuning
argument_list|()
specifier|const
name|override
block|{
return|return
name|llvm
operator|::
name|DebuggerKind
operator|::
name|LLDB
return|;
block|}
comment|/// }
name|private
operator|:
name|void
name|AddLinkSanitizerLibArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|,
argument|StringRef Sanitizer
argument_list|)
specifier|const
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
comment|// LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_DARWIN_H
end_comment

end_unit

