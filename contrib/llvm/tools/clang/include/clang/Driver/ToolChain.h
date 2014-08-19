begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ToolChain.h - Collections of tools for one platform ----*- C++ -*-===//
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
name|CLANG_DRIVER_TOOLCHAIN_H_
end_ifndef

begin_define
define|#
directive|define
name|CLANG_DRIVER_TOOLCHAIN_H_
end_define

begin_include
include|#
directive|include
file|"clang/Driver/Action.h"
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
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Path.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|opt
block|{
name|class
name|ArgList
decl_stmt|;
name|class
name|DerivedArgList
decl_stmt|;
name|class
name|InputArgList
decl_stmt|;
block|}
block|}
end_decl_stmt

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
name|Compilation
decl_stmt|;
name|class
name|Driver
decl_stmt|;
name|class
name|JobAction
decl_stmt|;
name|class
name|SanitizerArgs
decl_stmt|;
name|class
name|Tool
decl_stmt|;
comment|/// ToolChain - Access to tools for a single platform.
name|class
name|ToolChain
block|{
name|public
label|:
typedef|typedef
name|SmallVector
operator|<
name|std
operator|::
name|string
operator|,
literal|4
operator|>
name|path_list
expr_stmt|;
enum|enum
name|CXXStdlibType
block|{
name|CST_Libcxx
block|,
name|CST_Libstdcxx
block|}
enum|;
enum|enum
name|RuntimeLibType
block|{
name|RLT_CompilerRT
block|,
name|RLT_Libgcc
block|}
enum|;
name|private
label|:
specifier|const
name|Driver
modifier|&
name|D
decl_stmt|;
specifier|const
name|llvm
operator|::
name|Triple
name|Triple
expr_stmt|;
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
expr_stmt|;
comment|/// The list of toolchain specific path prefixes to search for
comment|/// files.
name|path_list
name|FilePaths
decl_stmt|;
comment|/// The list of toolchain specific path prefixes to search for
comment|/// programs.
name|path_list
name|ProgramPaths
decl_stmt|;
name|mutable
name|OwningPtr
operator|<
name|Tool
operator|>
name|Clang
expr_stmt|;
name|mutable
name|OwningPtr
operator|<
name|Tool
operator|>
name|Assemble
expr_stmt|;
name|mutable
name|OwningPtr
operator|<
name|Tool
operator|>
name|Link
expr_stmt|;
name|Tool
operator|*
name|getClang
argument_list|()
specifier|const
expr_stmt|;
name|Tool
operator|*
name|getAssemble
argument_list|()
specifier|const
expr_stmt|;
name|Tool
operator|*
name|getLink
argument_list|()
specifier|const
expr_stmt|;
name|Tool
operator|*
name|getClangAs
argument_list|()
specifier|const
expr_stmt|;
name|mutable
name|OwningPtr
operator|<
name|SanitizerArgs
operator|>
name|SanitizerArguments
expr_stmt|;
name|protected
label|:
name|ToolChain
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
name|T
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
name|virtual
name|Tool
operator|*
name|buildAssembler
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|Tool
operator|*
name|buildLinker
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|Tool
modifier|*
name|getTool
argument_list|(
name|Action
operator|::
name|ActionClass
name|AC
argument_list|)
decl|const
decl_stmt|;
comment|/// \name Utilities for implementing subclasses.
comment|///@{
specifier|static
name|void
name|addSystemInclude
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
argument_list|,
specifier|const
name|Twine
operator|&
name|Path
argument_list|)
decl_stmt|;
specifier|static
name|void
name|addExternCSystemInclude
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
argument_list|,
specifier|const
name|Twine
operator|&
name|Path
argument_list|)
decl_stmt|;
specifier|static
name|void
name|addExternCSystemIncludeIfExists
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
argument_list|,
specifier|const
name|Twine
operator|&
name|Path
argument_list|)
decl_stmt|;
specifier|static
name|void
name|addSystemIncludes
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
argument_list|,
name|ArrayRef
operator|<
name|StringRef
operator|>
name|Paths
argument_list|)
decl_stmt|;
comment|///@}
name|public
label|:
name|virtual
operator|~
name|ToolChain
argument_list|()
expr_stmt|;
comment|// Accessors
specifier|const
name|Driver
operator|&
name|getDriver
argument_list|()
specifier|const
expr_stmt|;
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
name|Triple
return|;
block|}
name|llvm
operator|::
name|Triple
operator|::
name|ArchType
name|getArch
argument_list|()
specifier|const
block|{
return|return
name|Triple
operator|.
name|getArch
argument_list|()
return|;
block|}
name|StringRef
name|getArchName
argument_list|()
specifier|const
block|{
return|return
name|Triple
operator|.
name|getArchName
argument_list|()
return|;
block|}
name|StringRef
name|getPlatform
argument_list|()
specifier|const
block|{
return|return
name|Triple
operator|.
name|getVendorName
argument_list|()
return|;
block|}
name|StringRef
name|getOS
argument_list|()
specifier|const
block|{
return|return
name|Triple
operator|.
name|getOSName
argument_list|()
return|;
block|}
comment|/// \brief Provide the default architecture name (as expected by -arch) for
comment|/// this toolchain. Note t
name|std
operator|::
name|string
name|getDefaultUniversalArchName
argument_list|()
specifier|const
expr_stmt|;
name|std
operator|::
name|string
name|getTripleString
argument_list|()
specifier|const
block|{
return|return
name|Triple
operator|.
name|getTriple
argument_list|()
return|;
block|}
name|path_list
modifier|&
name|getFilePaths
parameter_list|()
block|{
return|return
name|FilePaths
return|;
block|}
specifier|const
name|path_list
operator|&
name|getFilePaths
argument_list|()
specifier|const
block|{
return|return
name|FilePaths
return|;
block|}
name|path_list
modifier|&
name|getProgramPaths
parameter_list|()
block|{
return|return
name|ProgramPaths
return|;
block|}
specifier|const
name|path_list
operator|&
name|getProgramPaths
argument_list|()
specifier|const
block|{
return|return
name|ProgramPaths
return|;
block|}
specifier|const
name|SanitizerArgs
operator|&
name|getSanitizerArgs
argument_list|()
specifier|const
expr_stmt|;
comment|// Tool access.
comment|/// TranslateArgs - Create a new derived argument list for any argument
comment|/// translations this ToolChain may wish to perform, or 0 if no tool chain
comment|/// specific translations are needed.
comment|///
comment|/// \param BoundArch - The bound architecture name, or 0.
name|virtual
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
argument|const char *BoundArch
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// Choose a tool to use to handle the action \p JA.
name|Tool
modifier|*
name|SelectTool
argument_list|(
specifier|const
name|JobAction
operator|&
name|JA
argument_list|)
decl|const
decl_stmt|;
comment|// Helper methods
name|std
operator|::
name|string
name|GetFilePath
argument_list|(
argument|const char *Name
argument_list|)
specifier|const
expr_stmt|;
name|std
operator|::
name|string
name|GetProgramPath
argument_list|(
argument|const char *Name
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Dispatch to the specific toolchain for verbose printing.
comment|///
comment|/// This is used when handling the verbose option to print detailed,
comment|/// toolchain-specific information useful for understanding the behavior of
comment|/// the driver on a specific platform.
name|virtual
name|void
name|printVerboseInfo
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
block|{}
empty_stmt|;
comment|// Platform defaults information
comment|/// HasNativeLTOLinker - Check whether the linker and related tools have
comment|/// native LLVM support.
name|virtual
name|bool
name|HasNativeLLVMSupport
argument_list|()
specifier|const
expr_stmt|;
comment|/// LookupTypeForExtension - Return the default language type to use for the
comment|/// given extension.
name|virtual
name|types
operator|::
name|ID
name|LookupTypeForExtension
argument_list|(
argument|const char *Ext
argument_list|)
specifier|const
expr_stmt|;
comment|/// IsBlocksDefault - Does this tool chain enable -fblocks by default.
name|virtual
name|bool
name|IsBlocksDefault
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// IsIntegratedAssemblerDefault - Does this tool chain enable -integrated-as
comment|/// by default.
name|virtual
name|bool
name|IsIntegratedAssemblerDefault
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Check if the toolchain should use the integrated assembler.
name|bool
name|useIntegratedAs
argument_list|()
specifier|const
expr_stmt|;
comment|/// IsMathErrnoDefault - Does this tool chain use -fmath-errno by default.
name|virtual
name|bool
name|IsMathErrnoDefault
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// IsEncodeExtendedBlockSignatureDefault - Does this tool chain enable
comment|/// -fencode-extended-block-signature by default.
name|virtual
name|bool
name|IsEncodeExtendedBlockSignatureDefault
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// IsObjCNonFragileABIDefault - Does this tool chain set
comment|/// -fobjc-nonfragile-abi by default.
name|virtual
name|bool
name|IsObjCNonFragileABIDefault
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// UseObjCMixedDispatchDefault - When using non-legacy dispatch, should the
comment|/// mixed dispatch method be used?
name|virtual
name|bool
name|UseObjCMixedDispatch
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// GetDefaultStackProtectorLevel - Get the default stack protector level for
comment|/// this tool chain (0=off, 1=on, 2=all).
name|virtual
name|unsigned
name|GetDefaultStackProtectorLevel
argument_list|(
name|bool
name|KernelOrKext
argument_list|)
decl|const
block|{
return|return
literal|0
return|;
block|}
comment|/// GetDefaultRuntimeLibType - Get the default runtime library variant to use.
name|virtual
name|RuntimeLibType
name|GetDefaultRuntimeLibType
argument_list|()
specifier|const
block|{
return|return
name|ToolChain
operator|::
name|RLT_Libgcc
return|;
block|}
comment|/// IsUnwindTablesDefault - Does this tool chain use -funwind-tables
comment|/// by default.
name|virtual
name|bool
name|IsUnwindTablesDefault
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Test whether this toolchain defaults to PIC.
name|virtual
name|bool
name|isPICDefault
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// \brief Test whether this toolchain defaults to PIE.
name|virtual
name|bool
name|isPIEDefault
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// \brief Tests whether this toolchain forces its default for PIC, PIE or
comment|/// non-PIC.  If this returns true, any PIC related flags should be ignored
comment|/// and instead the results of \c isPICDefault() and \c isPIEDefault() are
comment|/// used exclusively.
name|virtual
name|bool
name|isPICDefaultForced
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// SupportsProfiling - Does this tool chain support -pg.
name|virtual
name|bool
name|SupportsProfiling
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// Does this tool chain support Objective-C garbage collection.
name|virtual
name|bool
name|SupportsObjCGC
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// Complain if this tool chain doesn't support Objective-C ARC.
name|virtual
name|void
name|CheckObjCARC
argument_list|()
specifier|const
block|{}
comment|/// UseDwarfDebugFlags - Embed the compile options to clang into the Dwarf
comment|/// compile unit information.
name|virtual
name|bool
name|UseDwarfDebugFlags
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// UseSjLjExceptions - Does this tool chain use SjLj exceptions.
name|virtual
name|bool
name|UseSjLjExceptions
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// ComputeLLVMTriple - Return the LLVM target triple to use, after taking
comment|/// command line arguments into account.
name|virtual
name|std
operator|::
name|string
name|ComputeLLVMTriple
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|types::ID InputType = types::TY_INVALID
argument_list|)
specifier|const
expr_stmt|;
comment|/// ComputeEffectiveClangTriple - Return the Clang triple to use for this
comment|/// target, which may take into account the command line arguments. For
comment|/// example, on Darwin the -mmacosx-version-min= command line argument (which
comment|/// sets the deployment target) determines the version in the triple passed to
comment|/// Clang.
name|virtual
name|std
operator|::
name|string
name|ComputeEffectiveClangTriple
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|types::ID InputType = types::TY_INVALID
argument_list|)
specifier|const
expr_stmt|;
comment|/// getDefaultObjCRuntime - Return the default Objective-C runtime
comment|/// for this platform.
comment|///
comment|/// FIXME: this really belongs on some sort of DeploymentTarget abstraction
name|virtual
name|ObjCRuntime
name|getDefaultObjCRuntime
argument_list|(
name|bool
name|isNonFragile
argument_list|)
decl|const
decl_stmt|;
comment|/// hasBlocksRuntime - Given that the user is compiling with
comment|/// -fblocks, does this tool chain guarantee the existence of a
comment|/// blocks runtime?
comment|///
comment|/// FIXME: this really belongs on some sort of DeploymentTarget abstraction
name|virtual
name|bool
name|hasBlocksRuntime
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// \brief Add the clang cc1 arguments for system include paths.
comment|///
comment|/// This routine is responsible for adding the necessary cc1 arguments to
comment|/// include headers from standard system header directories.
name|virtual
name|void
name|AddClangSystemIncludeArgs
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
comment|/// \brief Add options that need to be passed to cc1 for this target.
name|virtual
name|void
name|addClangTargetOptions
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
comment|// GetRuntimeLibType - Determine the runtime library type to use with the
comment|// given compilation arguments.
name|virtual
name|RuntimeLibType
name|GetRuntimeLibType
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
decl_stmt|;
comment|// GetCXXStdlibType - Determine the C++ standard library type to use with the
comment|// given compilation arguments.
name|virtual
name|CXXStdlibType
name|GetCXXStdlibType
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
decl_stmt|;
comment|/// AddClangCXXStdlibIncludeArgs - Add the clang -cc1 level arguments to set
comment|/// the include paths to use for the given C++ standard library type.
name|virtual
name|void
name|AddClangCXXStdlibIncludeArgs
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
comment|/// AddCXXStdlibLibArgs - Add the system specific linker arguments to use
comment|/// for the given C++ standard library type.
name|virtual
name|void
name|AddCXXStdlibLibArgs
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
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
operator|&
name|CmdArgs
argument_list|)
decl|const
decl_stmt|;
comment|/// AddCCKextLibArgs - Add the system specific linker arguments to use
comment|/// for kernel extensions (Darwin-specific).
name|virtual
name|void
name|AddCCKextLibArgs
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
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
operator|&
name|CmdArgs
argument_list|)
decl|const
decl_stmt|;
comment|/// AddFastMathRuntimeIfAvailable - If a runtime library exists that sets
comment|/// global flags for unsafe floating point math, add it and return true.
comment|///
comment|/// This checks for presence of the -Ofast, -ffast-math or -funsafe-math flags.
name|virtual
name|bool
name|AddFastMathRuntimeIfAvailable
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
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
operator|&
name|CmdArgs
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
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

