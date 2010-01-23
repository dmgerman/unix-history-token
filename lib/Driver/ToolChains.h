begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ToolChains.h - ToolChain Implementations ---------------*- C++ -*-===//
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
name|CLANG_LIB_DRIVER_TOOLCHAINS_H_
end_ifndef

begin_define
define|#
directive|define
name|CLANG_LIB_DRIVER_TOOLCHAINS_H_
end_define

begin_include
include|#
directive|include
file|"clang/Driver/Action.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/ToolChain.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"Tools.h"
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
comment|/// Generic_GCC - A tool chain using the 'gcc' command to perform
comment|/// all subcommands; this relies on gcc translating the majority of
comment|/// command line options.
name|class
name|VISIBILITY_HIDDEN
name|Generic_GCC
range|:
name|public
name|ToolChain
block|{
name|protected
operator|:
name|mutable
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
block|,
name|Tool
operator|*
operator|>
name|Tools
block|;
name|public
operator|:
name|Generic_GCC
argument_list|(
specifier|const
name|HostInfo
operator|&
name|Host
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
block|;
operator|~
name|Generic_GCC
argument_list|()
block|;
name|virtual
name|DerivedArgList
operator|*
name|TranslateArgs
argument_list|(
argument|InputArgList&Args
argument_list|,
argument|const char *BoundArch
argument_list|)
specifier|const
block|;
name|virtual
name|Tool
operator|&
name|SelectTool
argument_list|(
argument|const Compilation&C
argument_list|,
argument|const JobAction&JA
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|IsUnwindTablesDefault
argument_list|()
specifier|const
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetDefaultRelocationModel
argument_list|()
specifier|const
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetForcedPicModel
argument_list|()
specifier|const
block|; }
decl_stmt|;
comment|/// Darwin - The base Darwin tool chain.
name|class
name|VISIBILITY_HIDDEN
name|Darwin
range|:
name|public
name|ToolChain
block|{
name|mutable
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
block|,
name|Tool
operator|*
operator|>
name|Tools
block|;
comment|/// Darwin version of tool chain.
name|unsigned
name|DarwinVersion
index|[
literal|3
index|]
block|;
comment|/// Whether this is this an iPhoneOS toolchain.
comment|//
comment|// FIXME: This should go away, such differences should be completely
comment|// determined by the target triple.
name|bool
name|IsIPhoneOS
block|;
comment|/// The default macosx-version-min of this tool chain; empty until
comment|/// initialized.
name|mutable
name|std
operator|::
name|string
name|MacosxVersionMin
block|;
comment|/// The default iphoneos-version-min of this tool chain.
name|std
operator|::
name|string
name|IPhoneOSVersionMin
block|;
specifier|const
name|char
operator|*
name|getMacosxVersionMin
argument_list|()
specifier|const
block|;
name|public
operator|:
name|Darwin
argument_list|(
argument|const HostInfo&Host
argument_list|,
argument|const llvm::Triple& Triple
argument_list|,
argument|const unsigned (&DarwinVersion)[
literal|3
argument|]
argument_list|,
argument|bool IsIPhoneOS
argument_list|)
block|;
operator|~
name|Darwin
argument_list|()
block|;
comment|/// @name Darwin Specific Toolchain API
comment|/// {
name|void
name|getDarwinVersion
argument_list|(
argument|unsigned (&Res)[
literal|3
argument|]
argument_list|)
specifier|const
block|{
name|Res
index|[
literal|0
index|]
operator|=
name|DarwinVersion
index|[
literal|0
index|]
block|;
name|Res
index|[
literal|1
index|]
operator|=
name|DarwinVersion
index|[
literal|1
index|]
block|;
name|Res
index|[
literal|2
index|]
operator|=
name|DarwinVersion
index|[
literal|2
index|]
block|;   }
name|void
name|getMacosxVersion
argument_list|(
argument|unsigned (&Res)[
literal|3
argument|]
argument_list|)
specifier|const
block|{
name|Res
index|[
literal|0
index|]
operator|=
literal|10
block|;
name|Res
index|[
literal|1
index|]
operator|=
name|DarwinVersion
index|[
literal|0
index|]
operator|-
literal|4
block|;
name|Res
index|[
literal|2
index|]
operator|=
name|DarwinVersion
index|[
literal|1
index|]
block|;   }
comment|/// getDarwinArchName - Get the "Darwin" arch name for a particular compiler
comment|/// invocation. For example, Darwin treats different ARM variations as
comment|/// distinct architectures.
name|llvm
operator|::
name|StringRef
name|getDarwinArchName
argument_list|(
argument|const ArgList&Args
argument_list|)
specifier|const
block|;
comment|/// getMacosxVersionMin - Get the effective -mmacosx-version-min, which is
comment|/// either the -mmacosx-version-min, or the current version if unspecified.
name|void
name|getMacosxVersionMin
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|unsigned (&Res)[
literal|3
argument|]
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|isMacosxVersionLT
argument_list|(
argument|unsigned (&A)[
literal|3
argument|]
argument_list|,
argument|unsigned (&B)[
literal|3
argument|]
argument_list|)
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|3
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|A
index|[
name|i
index|]
operator|>
name|B
index|[
name|i
index|]
condition|)
return|return
name|false
return|;
if|if
condition|(
name|A
index|[
name|i
index|]
operator|<
name|B
index|[
name|i
index|]
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
specifier|static
name|bool
name|isMacosxVersionLT
argument_list|(
argument|unsigned (&A)[
literal|3
argument|]
argument_list|,
argument|unsigned V0
argument_list|,
argument|unsigned V1=
literal|0
argument_list|,
argument|unsigned V2=
literal|0
argument_list|)
block|{
name|unsigned
name|B
index|[
literal|3
index|]
operator|=
block|{
name|V0
block|,
name|V1
block|,
name|V2
block|}
block|;
return|return
name|isMacosxVersionLT
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
specifier|const
name|char
operator|*
name|getMacosxVersionStr
argument_list|()
specifier|const
block|{
return|return
name|MacosxVersionMin
operator|.
name|c_str
argument_list|()
return|;
block|}
specifier|const
name|char
operator|*
name|getIPhoneOSVersionStr
argument_list|()
specifier|const
block|{
return|return
name|IPhoneOSVersionMin
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|/// AddLinkSearchPathArgs - Add the linker search paths to \arg CmdArgs.
comment|///
comment|/// \param Args - The input argument list.
comment|/// \param CmdArgs [out] - The command argument list to append the paths
comment|/// (prefixed by -L) to.
name|virtual
name|void
name|AddLinkSearchPathArgs
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|ArgStringList&CmdArgs
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// AddLinkRuntimeLibArgs - Add the linker arguments to link the compiler
comment|/// runtime library.
name|virtual
name|void
name|AddLinkRuntimeLibArgs
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|ArgStringList&CmdArgs
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|bool
name|isIPhoneOS
argument_list|()
specifier|const
block|{
return|return
name|IsIPhoneOS
return|;
block|}
comment|/// }
comment|/// @name ToolChain Implementation
comment|/// {
name|virtual
name|DerivedArgList
operator|*
name|TranslateArgs
argument_list|(
argument|InputArgList&Args
argument_list|,
argument|const char *BoundArch
argument_list|)
specifier|const
block|;
name|virtual
name|Tool
operator|&
name|SelectTool
argument_list|(
argument|const Compilation&C
argument_list|,
argument|const JobAction&JA
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|IsBlocksDefault
argument_list|()
specifier|const
block|{
comment|// Blocks default to on for 10.6 (darwin10) and beyond.
return|return
operator|(
name|DarwinVersion
index|[
literal|0
index|]
operator|>
literal|9
operator|)
return|;
block|}
name|virtual
name|bool
name|IsObjCNonFragileABIDefault
argument_list|()
specifier|const
block|{
comment|// Non-fragile ABI default to on for 10.5 (darwin9) and beyond on x86-64.
return|return
operator|(
name|DarwinVersion
index|[
literal|0
index|]
operator|>=
literal|9
operator|&&
name|getTriple
argument_list|()
operator|.
name|getArch
argument_list|()
operator|==
name|llvm
operator|::
name|Triple
operator|::
name|x86_64
operator|)
return|;
block|}
name|virtual
name|bool
name|IsUnwindTablesDefault
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|GetDefaultStackProtectorLevel
argument_list|()
specifier|const
block|{
comment|// Stack protectors default to on for 10.6 (darwin10) and beyond.
return|return
operator|(
name|DarwinVersion
index|[
literal|0
index|]
operator|>
literal|9
operator|)
operator|?
literal|1
operator|:
literal|0
return|;
block|}
name|virtual
specifier|const
name|char
operator|*
name|GetDefaultRelocationModel
argument_list|()
specifier|const
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetForcedPicModel
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|UseDwarfDebugFlags
argument_list|()
specifier|const
block|;
comment|/// }
block|}
decl_stmt|;
comment|/// DarwinClang - The Darwin toolchain used by Clang.
name|class
name|VISIBILITY_HIDDEN
name|DarwinClang
range|:
name|public
name|Darwin
block|{
name|public
operator|:
name|DarwinClang
argument_list|(
argument|const HostInfo&Host
argument_list|,
argument|const llvm::Triple& Triple
argument_list|,
argument|const unsigned (&DarwinVersion)[
literal|3
argument|]
argument_list|,
argument|bool IsIPhoneOS
argument_list|)
block|;
comment|/// @name Darwin ToolChain Implementation
comment|/// {
name|virtual
name|void
name|AddLinkSearchPathArgs
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|AddLinkRuntimeLibArgs
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;
comment|/// }
block|}
decl_stmt|;
comment|/// DarwinGCC - The Darwin toolchain used by GCC.
name|class
name|VISIBILITY_HIDDEN
name|DarwinGCC
range|:
name|public
name|Darwin
block|{
comment|/// GCC version to use.
name|unsigned
name|GCCVersion
index|[
literal|3
index|]
block|;
comment|/// The directory suffix for this tool chain.
name|std
operator|::
name|string
name|ToolChainDir
block|;
name|public
operator|:
name|DarwinGCC
argument_list|(
argument|const HostInfo&Host
argument_list|,
argument|const llvm::Triple& Triple
argument_list|,
argument|const unsigned (&DarwinVersion)[
literal|3
argument|]
argument_list|,
argument|const unsigned (&GCCVersion)[
literal|3
argument|]
argument_list|,
argument|bool IsIPhoneOS
argument_list|)
block|;
comment|/// @name Darwin ToolChain Implementation
comment|/// {
name|virtual
name|void
name|AddLinkSearchPathArgs
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|AddLinkRuntimeLibArgs
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;
comment|/// }
block|}
decl_stmt|;
comment|/// Darwin_Generic_GCC - Generic Darwin tool chain using gcc.
name|class
name|VISIBILITY_HIDDEN
name|Darwin_Generic_GCC
range|:
name|public
name|Generic_GCC
block|{
name|public
operator|:
name|Darwin_Generic_GCC
argument_list|(
specifier|const
name|HostInfo
operator|&
name|Host
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
operator|:
name|Generic_GCC
argument_list|(
argument|Host
argument_list|,
argument|Triple
argument_list|)
block|{}
name|virtual
specifier|const
name|char
operator|*
name|GetDefaultRelocationModel
argument_list|()
specifier|const
block|{
return|return
literal|"pic"
return|;
block|}
expr|}
block|;
name|class
name|VISIBILITY_HIDDEN
name|AuroraUX
operator|:
name|public
name|Generic_GCC
block|{
name|public
operator|:
name|AuroraUX
argument_list|(
specifier|const
name|HostInfo
operator|&
name|Host
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
block|;
name|virtual
name|Tool
operator|&
name|SelectTool
argument_list|(
argument|const Compilation&C
argument_list|,
argument|const JobAction&JA
argument_list|)
specifier|const
block|; }
block|;
name|class
name|VISIBILITY_HIDDEN
name|OpenBSD
operator|:
name|public
name|Generic_GCC
block|{
name|public
operator|:
name|OpenBSD
argument_list|(
specifier|const
name|HostInfo
operator|&
name|Host
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
block|;
name|virtual
name|Tool
operator|&
name|SelectTool
argument_list|(
argument|const Compilation&C
argument_list|,
argument|const JobAction&JA
argument_list|)
specifier|const
block|; }
block|;
name|class
name|VISIBILITY_HIDDEN
name|FreeBSD
operator|:
name|public
name|Generic_GCC
block|{
name|public
operator|:
name|FreeBSD
argument_list|(
argument|const HostInfo&Host
argument_list|,
argument|const llvm::Triple& Triple
argument_list|,
argument|bool Lib32
argument_list|)
block|;
name|virtual
name|Tool
operator|&
name|SelectTool
argument_list|(
argument|const Compilation&C
argument_list|,
argument|const JobAction&JA
argument_list|)
specifier|const
block|; }
block|;
name|class
name|VISIBILITY_HIDDEN
name|DragonFly
operator|:
name|public
name|Generic_GCC
block|{
name|public
operator|:
name|DragonFly
argument_list|(
specifier|const
name|HostInfo
operator|&
name|Host
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
block|;
name|virtual
name|Tool
operator|&
name|SelectTool
argument_list|(
argument|const Compilation&C
argument_list|,
argument|const JobAction&JA
argument_list|)
specifier|const
block|; }
block|;
name|class
name|VISIBILITY_HIDDEN
name|Linux
operator|:
name|public
name|Generic_GCC
block|{
name|public
operator|:
name|Linux
argument_list|(
specifier|const
name|HostInfo
operator|&
name|Host
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
block|; }
block|;   }
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

end_unit

