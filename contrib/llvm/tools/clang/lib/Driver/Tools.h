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
name|CLANG_LIB_DRIVER_TOOLS_H_
end_ifndef

begin_define
define|#
directive|define
name|CLANG_LIB_DRIVER_TOOLS_H_
end_define

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
name|Darwin
decl_stmt|;
block|}
name|namespace
name|tools
block|{
name|using
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
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
name|InputInfoList
operator|&
name|Inputs
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
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|,
argument|bool KernelOrKext
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
block|;      enum
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
operator|:
name|Tool
argument_list|(
literal|"clang"
argument_list|,
literal|"clang frontend"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasGoodDiagnostics
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|hasIntegratedAssembler
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
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
block|;   }
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
argument_list|)
block|{}
name|virtual
name|bool
name|hasGoodDiagnostics
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|hasIntegratedAssembler
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
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
block|;   }
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
name|Tool
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
name|Tool
argument_list|(
argument|Name
argument_list|,
argument|ShortName
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
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
block|;   }
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Preprocess
range|:
name|public
name|Common
block|{
name|public
operator|:
name|Preprocess
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|Common
argument_list|(
literal|"gcc::Preprocess"
argument_list|,
literal|"gcc preprocessor"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasGoodDiagnostics
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
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
block|;   }
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Precompile
range|:
name|public
name|Common
block|{
name|public
operator|:
name|Precompile
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|Common
argument_list|(
literal|"gcc::Precompile"
argument_list|,
literal|"gcc precompile"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasGoodDiagnostics
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
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
block|;   }
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Compile
range|:
name|public
name|Common
block|{
name|public
operator|:
name|Compile
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|Common
argument_list|(
literal|"gcc::Compile"
argument_list|,
literal|"gcc frontend"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasGoodDiagnostics
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
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
block|;   }
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assemble
range|:
name|public
name|Common
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
name|Common
argument_list|(
literal|"gcc::Assemble"
argument_list|,
literal|"assembler (via gcc)"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
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
block|;   }
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Link
range|:
name|public
name|Common
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
name|Common
argument_list|(
literal|"gcc::Link"
argument_list|,
literal|"linker (via gcc)"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isLinkJob
argument_list|()
specifier|const
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
block|;   }
decl_stmt|;
block|}
comment|// end namespace gcc
name|namespace
name|hexagon
block|{
comment|// For Hexagon, we do not need to instantiate tools for PreProcess, PreCompile and Compile.
comment|// We simply use "clang -cc1" for those actions.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assemble
range|:
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
literal|"hexagon::Assemble"
argument_list|,
literal|"hexagon-as"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
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
name|virtual
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
block|;   }
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Link
range|:
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
literal|"hexagon::Link"
argument_list|,
literal|"hexagon-ld"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isLinkJob
argument_list|()
specifier|const
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
name|virtual
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
block|;   }
decl_stmt|;
block|}
comment|// end namespace hexagon.
name|namespace
name|darwin
block|{
name|llvm
operator|::
name|Triple
operator|::
name|ArchType
name|getArchTypeForDarwinArchName
argument_list|(
argument|StringRef Str
argument_list|)
expr_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|DarwinTool
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
name|AddDarwinArch
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
name|Darwin
operator|&
name|getDarwinToolChain
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|toolchains
operator|::
name|Darwin
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
name|DarwinTool
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
argument_list|)
block|{}
expr|}
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assemble
operator|:
name|public
name|DarwinTool
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
name|DarwinTool
argument_list|(
literal|"darwin::Assemble"
argument_list|,
literal|"assembler"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
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
block|;   }
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Link
operator|:
name|public
name|DarwinTool
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
name|Link
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|DarwinTool
argument_list|(
literal|"darwin::Link"
argument_list|,
literal|"linker"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isLinkJob
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
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
block|;   }
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Lipo
operator|:
name|public
name|DarwinTool
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
name|DarwinTool
argument_list|(
literal|"darwin::Lipo"
argument_list|,
literal|"lipo"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
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
block|;   }
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Dsymutil
operator|:
name|public
name|DarwinTool
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
name|DarwinTool
argument_list|(
literal|"darwin::Dsymutil"
argument_list|,
literal|"dsymutil"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isDsymutilJob
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
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
block|;   }
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|VerifyDebug
operator|:
name|public
name|DarwinTool
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
name|DarwinTool
argument_list|(
literal|"darwin::VerifyDebug"
argument_list|,
literal|"dwarfdump"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
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
block|;   }
block|;  }
comment|/// openbsd -- Directly call GNU Binutils assembler and linker
name|namespace
name|openbsd
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
literal|"openbsd::Assemble"
argument_list|,
literal|"assembler"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
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
block|;   }
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
literal|"openbsd::Link"
argument_list|,
literal|"linker"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isLinkJob
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
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
block|;   }
block|; }
comment|// end namespace openbsd
comment|/// bitrig -- Directly call GNU Binutils assembler and linker
name|namespace
name|bitrig
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
literal|"bitrig::Assemble"
argument_list|,
literal|"assembler"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
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
block|;   }
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
literal|"bitrig::Link"
argument_list|,
literal|"linker"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isLinkJob
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
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
block|;   }
block|; }
comment|// end namespace bitrig
comment|/// freebsd -- Directly call GNU Binutils assembler and linker
name|namespace
name|freebsd
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
literal|"freebsd::Assemble"
argument_list|,
literal|"assembler"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
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
block|;   }
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
literal|"freebsd::Link"
argument_list|,
literal|"linker"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isLinkJob
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
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
block|;   }
block|; }
comment|// end namespace freebsd
comment|/// netbsd -- Directly call GNU Binutils assembler and linker
name|namespace
name|netbsd
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
literal|"netbsd::Assemble"
argument_list|,
literal|"assembler"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
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
block|;   }
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
literal|"netbsd::Link"
argument_list|,
literal|"linker"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isLinkJob
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
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
block|;   }
block|; }
comment|// end namespace netbsd
comment|/// Directly call GNU Binutils' assembler and linker.
name|namespace
name|gnutools
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
literal|"GNU::Assemble"
argument_list|,
literal|"assembler"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
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
block|;   }
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
literal|"GNU::Link"
argument_list|,
literal|"linker"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isLinkJob
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
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
block|;   }
block|; }
comment|/// minix -- Directly call GNU Binutils assembler and linker
name|namespace
name|minix
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
literal|"minix::Assemble"
argument_list|,
literal|"assembler"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
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
block|;   }
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
literal|"minix::Link"
argument_list|,
literal|"linker"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isLinkJob
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
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
block|;   }
block|; }
comment|// end namespace minix
comment|/// solaris -- Directly call Solaris assembler and linker
name|namespace
name|solaris
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
literal|"solaris::Assemble"
argument_list|,
literal|"assembler"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
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
block|;   }
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
literal|"solaris::Link"
argument_list|,
literal|"linker"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isLinkJob
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
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
block|;   }
block|; }
comment|// end namespace solaris
comment|/// auroraux -- Directly call GNU Binutils assembler and linker
name|namespace
name|auroraux
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
literal|"auroraux::Assemble"
argument_list|,
literal|"assembler"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
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
block|;   }
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
literal|"auroraux::Link"
argument_list|,
literal|"linker"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isLinkJob
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
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
block|;   }
block|; }
comment|// end namespace auroraux
comment|/// dragonfly -- Directly call GNU Binutils assembler and linker
name|namespace
name|dragonfly
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
literal|"dragonfly::Assemble"
argument_list|,
literal|"assembler"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
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
block|;   }
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
literal|"dragonfly::Link"
argument_list|,
literal|"linker"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isLinkJob
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
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
block|;   }
block|; }
comment|// end namespace dragonfly
comment|/// Visual studio tools.
name|namespace
name|visualstudio
block|{
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
literal|"visualstudio::Link"
argument_list|,
literal|"linker"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isLinkJob
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
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
block|;   }
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Compile
operator|:
name|public
name|Tool
block|{
name|public
operator|:
name|Compile
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|Tool
argument_list|(
literal|"visualstudio::Compile"
argument_list|,
literal|"compiler"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedAssembler
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|isLinkJob
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
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
block|;
name|Command
operator|*
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
block|;   }
block|; }
comment|// end namespace visualstudio
name|namespace
name|XCore
block|{
comment|// For XCore, we do not need to instantiate tools for PreProcess, PreCompile and Compile.
comment|// We simply use "clang -cc1" for those actions.
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
literal|"XCore::Assemble"
argument_list|,
literal|"XCore-as"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
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
block|;   }
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
literal|"XCore::Link"
argument_list|,
literal|"XCore-ld"
argument_list|,
argument|TC
argument_list|)
block|{}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isLinkJob
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
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
block|;   }
block|; }
comment|// end namespace XCore.
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
comment|// CLANG_LIB_DRIVER_TOOLS_H_
end_comment

end_unit

