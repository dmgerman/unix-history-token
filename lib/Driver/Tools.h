begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Tools.h - Tool Implementations -------------------------*- C++ -*-===//
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
name|LLVM_CLANG_LIB_DRIVER_TOOLS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_DRIVER_TOOLS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/VersionTuple.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Tool.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Types.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Util.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/CodeGenOptions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Option/Option.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ObjCRuntime
decl_stmt|;
name|namespace
name|driver
block|{
name|class
name|Command
decl_stmt|;
name|class
name|Driver
decl_stmt|;
name|namespace
name|toolchains
block|{
name|class
name|MachO
decl_stmt|;
block|}
name|namespace
name|tools
block|{
name|namespace
name|visualstudio
block|{
name|class
name|Compiler
decl_stmt|;
block|}
name|using
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
expr_stmt|;
name|SmallString
operator|<
literal|128
operator|>
name|getCompilerRT
argument_list|(
argument|const ToolChain&TC
argument_list|,
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|StringRef Component
argument_list|,
argument|bool Shared = false
argument_list|)
expr_stmt|;
comment|/// \brief Clang compiler tool.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Clang
range|:
name|public
name|Tool
block|{
name|public
operator|:
specifier|static
specifier|const
name|char
operator|*
name|getBaseInputName
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
specifier|const
name|InputInfo
operator|&
name|Input
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|getBaseInputStem
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
specifier|const
name|InputInfoList
operator|&
name|Inputs
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|getDependencyFileName
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
specifier|const
name|InputInfoList
operator|&
name|Inputs
argument_list|)
block|;
name|private
operator|:
name|void
name|AddPreprocessingOptions
argument_list|(
argument|Compilation&C
argument_list|,
argument|const JobAction&JA
argument_list|,
argument|const Driver&D
argument_list|,
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|,
argument|const InputInfo&Output
argument_list|,
argument|const InputInfoList&Inputs
argument_list|,
argument|const ToolChain *AuxToolChain
argument_list|)
specifier|const
block|;
name|void
name|AddAArch64TargetArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;
name|void
name|AddARMTargetArgs
argument_list|(
argument|const llvm::Triple&Triple
argument_list|,
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|,
argument|bool KernelOrKext
argument_list|)
specifier|const
block|;
name|void
name|AddARM64TargetArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;
name|void
name|AddMIPSTargetArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;
name|void
name|AddPPCTargetArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;
name|void
name|AddR600TargetArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;
name|void
name|AddSparcTargetArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;
name|void
name|AddSystemZTargetArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;
name|void
name|AddX86TargetArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;
name|void
name|AddHexagonTargetArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;    enum
name|RewriteKind
block|{
name|RK_None
block|,
name|RK_Fragile
block|,
name|RK_NonFragile
block|}
block|;
name|ObjCRuntime
name|AddObjCRuntimeArgs
argument_list|(
argument|const llvm::opt::ArgList&args
argument_list|,
argument|llvm::opt::ArgStringList&cmdArgs
argument_list|,
argument|RewriteKind rewrite
argument_list|)
specifier|const
block|;
name|void
name|AddClangCLArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|,
argument|enum CodeGenOptions::DebugInfoKind *DebugInfoKind
argument_list|,
argument|bool *EmitCodeView
argument_list|)
specifier|const
block|;
name|visualstudio
operator|::
name|Compiler
operator|*
name|getCLFallback
argument_list|()
specifier|const
block|;
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|visualstudio
operator|::
name|Compiler
operator|>
name|CLFallback
block|;
name|public
operator|:
comment|// CAUTION! The first constructor argument ("clang") is not arbitrary,
comment|// as it is for other tools. Some operations on a Tool actually test
comment|// whether that tool is Clang based on the Tool's Name as a string.
name|Clang
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|Tool
argument_list|(
literal|"clang"
argument_list|,
literal|"clang frontend"
argument_list|,
argument|TC
argument_list|,
argument|RF_Full
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
name|canEmitIR
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
comment|/// \brief Clang integrated assembler tool.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|ClangAs
range|:
name|public
name|Tool
block|{
name|public
operator|:
name|ClangAs
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|Tool
argument_list|(
literal|"clang::as"
argument_list|,
literal|"clang integrated assembler"
argument_list|,
argument|TC
argument_list|,
argument|RF_Full
argument_list|)
block|{}
name|void
name|AddMIPSTargetArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;
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
name|hasIntegratedAssembler
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
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
name|namespace
name|hexagon
block|{
comment|// For Hexagon, we do not need to instantiate tools for PreProcess, PreCompile
comment|// and Compile.
comment|// We simply use "clang -cc1" for those actions.
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
literal|"hexagon::Assembler"
argument_list|,
literal|"hexagon-as"
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
name|RenderExtraToolArgs
argument_list|(
argument|const JobAction&JA
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
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
literal|"hexagon::Linker"
argument_list|,
literal|"hexagon-ld"
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
name|virtual
name|void
name|RenderExtraToolArgs
argument_list|(
argument|const JobAction&JA
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
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
comment|// end namespace hexagon.
name|namespace
name|amdgpu
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
literal|"amdgpu::Linker"
argument_list|,
literal|"lld"
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
comment|// end namespace amdgpu
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
name|namespace
name|arm
block|{
name|std
operator|::
name|string
name|getARMTargetCPU
argument_list|(
argument|StringRef CPU
argument_list|,
argument|StringRef Arch
argument_list|,
argument|const llvm::Triple&Triple
argument_list|)
expr_stmt|;
specifier|const
name|std
operator|::
name|string
name|getARMArch
argument_list|(
argument|StringRef Arch
argument_list|,
argument|const llvm::Triple&Triple
argument_list|)
expr_stmt|;
name|StringRef
name|getARMCPUForMArch
argument_list|(
name|StringRef
name|Arch
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
decl_stmt|;
name|StringRef
name|getLLVMArchSuffixForARM
argument_list|(
name|StringRef
name|CPU
argument_list|,
name|StringRef
name|Arch
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
decl_stmt|;
name|void
name|appendEBLinkFlags
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
name|ArgStringList
operator|&
name|CmdArgs
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
comment|// end namespace arm
name|namespace
name|mips
block|{
typedef|typedef
enum|enum
block|{
name|NanLegacy
init|=
literal|1
block|,
name|Nan2008
init|=
literal|2
block|}
name|NanEncoding
typedef|;
name|enum
name|class
name|FloatABI
block|{
name|Invalid
operator|,
name|Soft
operator|,
name|Hard
operator|,
block|}
empty_stmt|;
name|NanEncoding
name|getSupportedNanEncoding
parameter_list|(
name|StringRef
modifier|&
name|CPU
parameter_list|)
function_decl|;
name|void
name|getMipsCPUAndABI
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|,
name|StringRef
operator|&
name|CPUName
argument_list|,
name|StringRef
operator|&
name|ABIName
argument_list|)
decl_stmt|;
name|std
operator|::
name|string
name|getMipsABILibSuffix
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
expr_stmt|;
name|bool
name|hasMipsAbiArg
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
specifier|const
name|char
operator|*
name|Value
argument_list|)
decl_stmt|;
name|bool
name|isUCLibc
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
decl_stmt|;
name|bool
name|isNaN2008
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
decl_stmt|;
name|bool
name|isFPXXDefault
argument_list|(
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|,
name|StringRef
name|CPUName
argument_list|,
name|StringRef
name|ABIName
argument_list|,
name|mips
operator|::
name|FloatABI
name|FloatABI
argument_list|)
decl_stmt|;
name|bool
name|shouldUseFPXX
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|,
name|StringRef
name|CPUName
argument_list|,
name|StringRef
name|ABIName
argument_list|,
name|mips
operator|::
name|FloatABI
name|FloatABI
argument_list|)
decl_stmt|;
block|}
comment|// end namespace mips
name|namespace
name|ppc
block|{
name|bool
name|hasPPCAbiArg
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
specifier|const
name|char
operator|*
name|Value
argument_list|)
decl_stmt|;
block|}
comment|// end namespace ppc
comment|/// cloudabi -- Directly call GNU Binutils linker
name|namespace
name|cloudabi
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
literal|"cloudabi::Linker"
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
comment|// end namespace cloudabi
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
comment|/// openbsd -- Directly call GNU Binutils assembler and linker
name|namespace
name|openbsd
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assembler
operator|:
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
literal|"openbsd::Assembler"
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
literal|"openbsd::Linker"
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
block|; }
comment|// end namespace openbsd
comment|/// bitrig -- Directly call GNU Binutils assembler and linker
name|namespace
name|bitrig
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assembler
operator|:
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
literal|"bitrig::Assembler"
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
literal|"bitrig::Linker"
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
block|; }
comment|// end namespace bitrig
comment|/// freebsd -- Directly call GNU Binutils assembler and linker
name|namespace
name|freebsd
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assembler
operator|:
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
literal|"freebsd::Assembler"
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
literal|"freebsd::Linker"
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
block|; }
comment|// end namespace freebsd
comment|/// netbsd -- Directly call GNU Binutils assembler and linker
name|namespace
name|netbsd
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assembler
operator|:
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
literal|"netbsd::Assembler"
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
literal|"netbsd::Linker"
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
block|; }
comment|// end namespace netbsd
comment|/// Directly call GNU Binutils' assembler and linker.
name|namespace
name|gnutools
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assembler
operator|:
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
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Linker
operator|:
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
block|; }
comment|// end namespace gnutools
name|namespace
name|nacltools
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|AssemblerARM
operator|:
name|public
name|gnutools
operator|::
name|Assembler
block|{
name|public
operator|:
name|AssemblerARM
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|gnutools
operator|::
name|Assembler
argument_list|(
argument|TC
argument_list|)
block|{}
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
literal|"NaCl::Linker"
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
block|; }
comment|// end namespace nacltools
comment|/// minix -- Directly call GNU Binutils assembler and linker
name|namespace
name|minix
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assembler
operator|:
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
literal|"minix::Assembler"
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
literal|"minix::Linker"
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
block|; }
comment|// end namespace minix
comment|/// solaris -- Directly call Solaris assembler and linker
name|namespace
name|solaris
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assembler
operator|:
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
literal|"solaris::Assembler"
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
literal|"solaris::Linker"
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
block|; }
comment|// end namespace solaris
comment|/// dragonfly -- Directly call GNU Binutils assembler and linker
name|namespace
name|dragonfly
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assembler
operator|:
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
literal|"dragonfly::Assembler"
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
literal|"dragonfly::Linker"
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
block|; }
comment|// end namespace dragonfly
comment|/// Visual studio tools.
name|namespace
name|visualstudio
block|{
name|VersionTuple
name|getMSVCVersion
argument_list|(
argument|const Driver *D
argument_list|,
argument|const llvm::Triple&Triple
argument_list|,
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|bool IsWindowsMSVC
argument_list|)
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Linker
operator|:
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
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Compiler
operator|:
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
block|; }
comment|// end namespace visualstudio
comment|/// MinGW -- Directly call GNU Binutils assembler and linker
name|namespace
name|MinGW
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assembler
operator|:
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
literal|"MinGW::Assemble"
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
literal|"MinGW::Linker"
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
block|;
name|private
operator|:
name|void
name|AddLibGCC
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|ArgStringList&CmdArgs
argument_list|)
specifier|const
block|; }
block|; }
comment|// end namespace MinGW
name|namespace
name|arm
block|{ enum
name|class
name|FloatABI
block|{
name|Invalid
block|,
name|Soft
block|,
name|SoftFP
block|,
name|Hard
block|, }
block|;
name|FloatABI
name|getARMFloatABI
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
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
block|; }
comment|// end namespace arm
name|namespace
name|ppc
block|{ enum
name|class
name|FloatABI
block|{
name|Invalid
block|,
name|Soft
block|,
name|Hard
block|, }
block|;
name|FloatABI
name|getPPCFloatABI
argument_list|(
specifier|const
name|Driver
operator|&
name|D
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
block|; }
comment|// end namespace ppc
name|namespace
name|XCore
block|{
comment|// For XCore, we do not need to instantiate tools for PreProcess, PreCompile and
comment|// Compile.
comment|// We simply use "clang -cc1" for those actions.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assembler
operator|:
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
literal|"XCore::Assembler"
argument_list|,
literal|"XCore-as"
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
literal|"XCore::Linker"
argument_list|,
literal|"XCore-ld"
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
block|; }
comment|// end namespace XCore.
name|namespace
name|CrossWindows
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assembler
operator|:
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
literal|"CrossWindows::Assembler"
argument_list|,
literal|"as"
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
literal|"CrossWindows::Linker"
argument_list|,
literal|"ld"
argument_list|,
argument|TC
argument_list|,
argument|RF_Full
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
block|; }
comment|// end namespace CrossWindows
comment|/// SHAVE tools -- Directly call moviCompile and moviAsm
name|namespace
name|SHAVE
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Compiler
operator|:
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
literal|"moviCompile"
argument_list|,
literal|"movicompile"
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
name|Assembler
operator|:
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
literal|"moviAsm"
argument_list|,
literal|"moviAsm"
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
comment|// not sure.
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
comment|// end namespace SHAVE
comment|/// The Myriad toolchain uses tools that are in two different namespaces.
comment|/// The Compiler and Assembler as defined above are in the SHAVE namespace,
comment|/// whereas the linker, which accepts code for a mixture of Sparc and SHAVE,
comment|/// is in the Myriad namespace.
name|namespace
name|Myriad
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Linker
operator|:
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
literal|"shave::Linker"
argument_list|,
literal|"ld"
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
block|; }
comment|// end namespace Myriad
name|namespace
name|PS4cpu
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assemble
operator|:
name|public
name|Tool
block|{
name|public
operator|:
name|Assemble
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|Tool
argument_list|(
literal|"PS4cpu::Assemble"
argument_list|,
literal|"assembler"
argument_list|,
argument|TC
argument_list|,
argument|RF_Full
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
name|Link
operator|:
name|public
name|Tool
block|{
name|public
operator|:
name|Link
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|Tool
argument_list|(
literal|"PS4cpu::Link"
argument_list|,
literal|"linker"
argument_list|,
argument|TC
argument_list|,
argument|RF_Full
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
block|; }
comment|// end namespace PS4cpu
block|}
comment|// end namespace tools
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
comment|// LLVM_CLANG_LIB_DRIVER_TOOLS_H
end_comment

end_unit

