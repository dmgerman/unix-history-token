begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Clang.h - Clang Tool and ToolChain Implementations ====-*- C++ -*-===//
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
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_Clang_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_Clang_H
end_define

begin_include
include|#
directive|include
file|"MSVC.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/DebugInfoOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Driver.h"
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
file|"llvm/Support/raw_ostream.h"
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
name|namespace
name|tools
block|{
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
block|;
name|void
name|AddLanaiTargetArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
block|;
name|void
name|AddWebAssemblyTargetArgs
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
argument|types::ID InputType
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|,
argument|codegenoptions::DebugInfoKind *DebugInfoKind
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
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|raw_fd_ostream
operator|>
name|CompilationDatabase
operator|=
name|nullptr
block|;
name|void
name|DumpCompilationDatabase
argument_list|(
argument|Compilation&C
argument_list|,
argument|StringRef Filename
argument_list|,
argument|StringRef Target
argument_list|,
argument|const InputInfo&Output
argument_list|,
argument|const InputInfo&Input
argument_list|,
argument|const llvm::opt::ArgList&Args
argument_list|)
specifier|const
block|;
name|public
operator|:
name|Clang
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
block|;
operator|~
name|Clang
argument_list|()
name|override
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
name|void
name|AddX86TargetArgs
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
comment|/// Offload bundler tool.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|OffloadBundler
name|final
range|:
name|public
name|Tool
block|{
name|public
operator|:
name|OffloadBundler
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|Tool
argument_list|(
literal|"offload bundler"
argument_list|,
literal|"clang-offload-bundler"
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
block|;
name|void
name|ConstructJobMultipleOutputs
argument_list|(
argument|Compilation&C
argument_list|,
argument|const JobAction&JA
argument_list|,
argument|const InputInfoList&Outputs
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
comment|// LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_CLANG_H
end_comment

end_unit

