begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- FrontendOptions.h --------------------------------------*- C++ -*-===//
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
name|LLVM_CLANG_FRONTEND_FRONTENDOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_FRONTENDOPTIONS_H
end_define

begin_include
include|#
directive|include
file|"clang/Frontend/CommandLineSourceLoc.h"
end_include

begin_include
include|#
directive|include
file|"clang/Serialization/ModuleFileExtension.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/CodeCompleteOptions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBuffer
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|frontend
block|{
enum|enum
name|ActionKind
block|{
name|ASTDeclList
block|,
comment|///< Parse ASTs and list Decl nodes.
name|ASTDump
block|,
comment|///< Parse ASTs and dump them.
name|ASTPrint
block|,
comment|///< Parse ASTs and print them.
name|ASTView
block|,
comment|///< Parse ASTs and view them in Graphviz.
name|DumpRawTokens
block|,
comment|///< Dump out raw tokens.
name|DumpTokens
block|,
comment|///< Dump out preprocessed tokens.
name|EmitAssembly
block|,
comment|///< Emit a .s file.
name|EmitBC
block|,
comment|///< Emit a .bc file.
name|EmitHTML
block|,
comment|///< Translate input source into HTML.
name|EmitLLVM
block|,
comment|///< Emit a .ll file.
name|EmitLLVMOnly
block|,
comment|///< Generate LLVM IR, but do not emit anything.
name|EmitCodeGenOnly
block|,
comment|///< Generate machine code, but don't emit anything.
name|EmitObj
block|,
comment|///< Emit a .o file.
name|FixIt
block|,
comment|///< Parse and apply any fixits to the source.
name|GenerateModule
block|,
comment|///< Generate pre-compiled module from a module map.
name|GenerateModuleInterface
block|,
comment|///< Generate pre-compiled module from a C++ module
comment|///< interface file.
name|GeneratePCH
block|,
comment|///< Generate pre-compiled header.
name|GeneratePTH
block|,
comment|///< Generate pre-tokenized header.
name|InitOnly
block|,
comment|///< Only execute frontend initialization.
name|ModuleFileInfo
block|,
comment|///< Dump information about a module file.
name|VerifyPCH
block|,
comment|///< Load and verify that a PCH file is usable.
name|ParseSyntaxOnly
block|,
comment|///< Parse and perform semantic analysis.
name|PluginAction
block|,
comment|///< Run a plugin action, \see ActionName.
name|PrintDeclContext
block|,
comment|///< Print DeclContext and their Decls.
name|PrintPreamble
block|,
comment|///< Print the "preamble" of the input file
name|PrintPreprocessedInput
block|,
comment|///< -E mode.
name|RewriteMacros
block|,
comment|///< Expand macros but not \#includes.
name|RewriteObjC
block|,
comment|///< ObjC->C Rewriter.
name|RewriteTest
block|,
comment|///< Rewriter playground
name|RunAnalysis
block|,
comment|///< Run one or more source code analyses.
name|MigrateSource
block|,
comment|///< Run migrator.
name|RunPreprocessorOnly
comment|///< Just lex, no output.
block|}
enum|;
block|}
enum|enum
name|InputKind
block|{
name|IK_None
block|,
name|IK_Asm
block|,
name|IK_C
block|,
name|IK_CXX
block|,
name|IK_ObjC
block|,
name|IK_ObjCXX
block|,
name|IK_PreprocessedC
block|,
name|IK_PreprocessedCXX
block|,
name|IK_PreprocessedObjC
block|,
name|IK_PreprocessedObjCXX
block|,
name|IK_OpenCL
block|,
name|IK_CUDA
block|,
name|IK_PreprocessedCuda
block|,
name|IK_RenderScript
block|,
name|IK_AST
block|,
name|IK_LLVM_IR
block|}
enum|;
comment|/// \brief An input file for the front end.
name|class
name|FrontendInputFile
block|{
comment|/// \brief The file name, or "-" to read from standard input.
name|std
operator|::
name|string
name|File
expr_stmt|;
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|Buffer
expr_stmt|;
comment|/// \brief The kind of input, e.g., C source, AST file, LLVM IR.
name|InputKind
name|Kind
decl_stmt|;
comment|/// \brief Whether we're dealing with a 'system' input (vs. a 'user' input).
name|bool
name|IsSystem
decl_stmt|;
name|public
label|:
name|FrontendInputFile
argument_list|()
operator|:
name|Buffer
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Kind
argument_list|(
name|IK_None
argument_list|)
operator|,
name|IsSystem
argument_list|(
argument|false
argument_list|)
block|{ }
name|FrontendInputFile
argument_list|(
argument|StringRef File
argument_list|,
argument|InputKind Kind
argument_list|,
argument|bool IsSystem = false
argument_list|)
operator|:
name|File
argument_list|(
name|File
operator|.
name|str
argument_list|()
argument_list|)
operator|,
name|Buffer
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|IsSystem
argument_list|(
argument|IsSystem
argument_list|)
block|{ }
name|FrontendInputFile
argument_list|(
argument|llvm::MemoryBuffer *buffer
argument_list|,
argument|InputKind Kind
argument_list|,
argument|bool IsSystem = false
argument_list|)
operator|:
name|Buffer
argument_list|(
name|buffer
argument_list|)
operator|,
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|IsSystem
argument_list|(
argument|IsSystem
argument_list|)
block|{ }
name|InputKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|bool
name|isSystem
argument_list|()
specifier|const
block|{
return|return
name|IsSystem
return|;
block|}
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|File
operator|.
name|empty
argument_list|()
operator|&&
name|Buffer
operator|==
name|nullptr
return|;
block|}
name|bool
name|isFile
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isBuffer
argument_list|()
return|;
block|}
name|bool
name|isBuffer
argument_list|()
specifier|const
block|{
return|return
name|Buffer
operator|!=
name|nullptr
return|;
block|}
name|bool
name|isPreprocessed
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|IK_PreprocessedC
operator|||
name|Kind
operator|==
name|IK_PreprocessedCXX
operator|||
name|Kind
operator|==
name|IK_PreprocessedObjC
operator|||
name|Kind
operator|==
name|IK_PreprocessedObjCXX
operator|||
name|Kind
operator|==
name|IK_PreprocessedCuda
return|;
block|}
name|StringRef
name|getFile
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isFile
argument_list|()
argument_list|)
block|;
return|return
name|File
return|;
block|}
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|getBuffer
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isBuffer
argument_list|()
argument_list|)
block|;
return|return
name|Buffer
return|;
block|}
block|}
empty_stmt|;
comment|/// FrontendOptions - Options for controlling the behavior of the frontend.
name|class
name|FrontendOptions
block|{
name|public
label|:
name|unsigned
name|DisableFree
range|:
literal|1
decl_stmt|;
comment|///< Disable memory freeing on exit.
name|unsigned
name|RelocatablePCH
range|:
literal|1
decl_stmt|;
comment|///< When generating PCH files,
comment|/// instruct the AST writer to create
comment|/// relocatable PCH files.
name|unsigned
name|ShowHelp
range|:
literal|1
decl_stmt|;
comment|///< Show the -help text.
name|unsigned
name|ShowStats
range|:
literal|1
decl_stmt|;
comment|///< Show frontend performance
comment|/// metrics and statistics.
name|unsigned
name|ShowTimers
range|:
literal|1
decl_stmt|;
comment|///< Show timers for individual
comment|/// actions.
name|unsigned
name|ShowVersion
range|:
literal|1
decl_stmt|;
comment|///< Show the -version text.
name|unsigned
name|FixWhatYouCan
range|:
literal|1
decl_stmt|;
comment|///< Apply fixes even if there are
comment|/// unfixable errors.
name|unsigned
name|FixOnlyWarnings
range|:
literal|1
decl_stmt|;
comment|///< Apply fixes only for warnings.
name|unsigned
name|FixAndRecompile
range|:
literal|1
decl_stmt|;
comment|///< Apply fixes and recompile.
name|unsigned
name|FixToTemporaries
range|:
literal|1
decl_stmt|;
comment|///< Apply fixes to temporary files.
name|unsigned
name|ARCMTMigrateEmitARCErrors
range|:
literal|1
decl_stmt|;
comment|/// Emit ARC errors even if the
comment|/// migrator can fix them
name|unsigned
name|SkipFunctionBodies
range|:
literal|1
decl_stmt|;
comment|///< Skip over function bodies to
comment|/// speed up parsing in cases you do
comment|/// not need them (e.g. with code
comment|/// completion).
name|unsigned
name|UseGlobalModuleIndex
range|:
literal|1
decl_stmt|;
comment|///< Whether we can use the
comment|///< global module index if available.
name|unsigned
name|GenerateGlobalModuleIndex
range|:
literal|1
decl_stmt|;
comment|///< Whether we can generate the
comment|///< global module index if needed.
name|unsigned
name|ASTDumpDecls
range|:
literal|1
decl_stmt|;
comment|///< Whether we include declaration
comment|///< dumps in AST dumps.
name|unsigned
name|ASTDumpAll
range|:
literal|1
decl_stmt|;
comment|///< Whether we deserialize all decls
comment|///< when forming AST dumps.
name|unsigned
name|ASTDumpLookups
range|:
literal|1
decl_stmt|;
comment|///< Whether we include lookup table
comment|///< dumps in AST dumps.
name|unsigned
name|BuildingImplicitModule
range|:
literal|1
decl_stmt|;
comment|///< Whether we are performing an
comment|///< implicit module build.
name|unsigned
name|ModulesEmbedAllFiles
range|:
literal|1
decl_stmt|;
comment|///< Whether we should embed all used
comment|///< files into the PCM file.
name|unsigned
name|IncludeTimestamps
range|:
literal|1
decl_stmt|;
comment|///< Whether timestamps should be
comment|///< written to the produced PCH file.
name|CodeCompleteOptions
name|CodeCompleteOpts
decl_stmt|;
enum|enum
block|{
name|ARCMT_None
block|,
name|ARCMT_Check
block|,
name|ARCMT_Modify
block|,
name|ARCMT_Migrate
block|}
name|ARCMTAction
enum|;
enum|enum
block|{
name|ObjCMT_None
init|=
literal|0
block|,
comment|/// \brief Enable migration to modern ObjC literals.
name|ObjCMT_Literals
init|=
literal|0x1
block|,
comment|/// \brief Enable migration to modern ObjC subscripting.
name|ObjCMT_Subscripting
init|=
literal|0x2
block|,
comment|/// \brief Enable migration to modern ObjC readonly property.
name|ObjCMT_ReadonlyProperty
init|=
literal|0x4
block|,
comment|/// \brief Enable migration to modern ObjC readwrite property.
name|ObjCMT_ReadwriteProperty
init|=
literal|0x8
block|,
comment|/// \brief Enable migration to modern ObjC property.
name|ObjCMT_Property
init|=
operator|(
name|ObjCMT_ReadonlyProperty
operator||
name|ObjCMT_ReadwriteProperty
operator|)
block|,
comment|/// \brief Enable annotation of ObjCMethods of all kinds.
name|ObjCMT_Annotation
init|=
literal|0x10
block|,
comment|/// \brief Enable migration of ObjC methods to 'instancetype'.
name|ObjCMT_Instancetype
init|=
literal|0x20
block|,
comment|/// \brief Enable migration to NS_ENUM/NS_OPTIONS macros.
name|ObjCMT_NsMacros
init|=
literal|0x40
block|,
comment|/// \brief Enable migration to add conforming protocols.
name|ObjCMT_ProtocolConformance
init|=
literal|0x80
block|,
comment|/// \brief prefer 'atomic' property over 'nonatomic'.
name|ObjCMT_AtomicProperty
init|=
literal|0x100
block|,
comment|/// \brief annotate property with NS_RETURNS_INNER_POINTER
name|ObjCMT_ReturnsInnerPointerProperty
init|=
literal|0x200
block|,
comment|/// \brief use NS_NONATOMIC_IOSONLY for property 'atomic' attribute
name|ObjCMT_NsAtomicIOSOnlyProperty
init|=
literal|0x400
block|,
comment|/// \brief Enable inferring NS_DESIGNATED_INITIALIZER for ObjC methods.
name|ObjCMT_DesignatedInitializer
init|=
literal|0x800
block|,
comment|/// \brief Enable converting setter/getter expressions to property-dot syntx.
name|ObjCMT_PropertyDotSyntax
init|=
literal|0x1000
block|,
name|ObjCMT_MigrateDecls
init|=
operator|(
name|ObjCMT_ReadonlyProperty
operator||
name|ObjCMT_ReadwriteProperty
operator||
name|ObjCMT_Annotation
operator||
name|ObjCMT_Instancetype
operator||
name|ObjCMT_NsMacros
operator||
name|ObjCMT_ProtocolConformance
operator||
name|ObjCMT_NsAtomicIOSOnlyProperty
operator||
name|ObjCMT_DesignatedInitializer
operator|)
block|,
name|ObjCMT_MigrateAll
init|=
operator|(
name|ObjCMT_Literals
operator||
name|ObjCMT_Subscripting
operator||
name|ObjCMT_MigrateDecls
operator||
name|ObjCMT_PropertyDotSyntax
operator|)
block|}
enum|;
name|unsigned
name|ObjCMTAction
decl_stmt|;
name|std
operator|::
name|string
name|ObjCMTWhiteListPath
expr_stmt|;
name|std
operator|::
name|string
name|MTMigrateDir
expr_stmt|;
name|std
operator|::
name|string
name|ARCMTMigrateReportOut
expr_stmt|;
comment|/// The input files and their types.
name|std
operator|::
name|vector
operator|<
name|FrontendInputFile
operator|>
name|Inputs
expr_stmt|;
comment|/// The output file, if any.
name|std
operator|::
name|string
name|OutputFile
expr_stmt|;
comment|/// If given, the new suffix for fix-it rewritten files.
name|std
operator|::
name|string
name|FixItSuffix
expr_stmt|;
comment|/// If given, filter dumped AST Decl nodes by this substring.
name|std
operator|::
name|string
name|ASTDumpFilter
expr_stmt|;
comment|/// If given, enable code completion at the provided location.
name|ParsedSourceLocation
name|CodeCompletionAt
decl_stmt|;
comment|/// The frontend action to perform.
name|frontend
operator|::
name|ActionKind
name|ProgramAction
expr_stmt|;
comment|/// The name of the action to run when using a plugin action.
name|std
operator|::
name|string
name|ActionName
expr_stmt|;
comment|/// Args to pass to the plugins
name|std
operator|::
name|unordered_map
operator|<
name|std
operator|::
name|string
operator|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>>
name|PluginArgs
expr_stmt|;
comment|/// The list of plugin actions to run in addition to the normal action.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|AddPluginActions
expr_stmt|;
comment|/// The list of plugins to load.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Plugins
expr_stmt|;
comment|/// The list of module file extensions.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|shared_ptr
operator|<
name|ModuleFileExtension
operator|>>
name|ModuleFileExtensions
expr_stmt|;
comment|/// \brief The list of module map files to load before processing the input.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|ModuleMapFiles
expr_stmt|;
comment|/// \brief The list of additional prebuilt module files to load before
comment|/// processing the input.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|ModuleFiles
expr_stmt|;
comment|/// \brief The list of files to embed into the compiled module file.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|ModulesEmbedFiles
expr_stmt|;
comment|/// \brief The list of AST files to merge.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|ASTMergeFiles
expr_stmt|;
comment|/// \brief A list of arguments to forward to LLVM's option processing; this
comment|/// should only be used for debugging and experimental features.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|LLVMArgs
expr_stmt|;
comment|/// \brief File name of the file that will provide record layouts
comment|/// (in the format produced by -fdump-record-layouts).
name|std
operator|::
name|string
name|OverrideRecordLayoutsFile
expr_stmt|;
comment|/// \brief Auxiliary triple for CUDA compilation.
name|std
operator|::
name|string
name|AuxTriple
expr_stmt|;
comment|/// \brief If non-empty, search the pch input file as it was a header
comment|// included by this file.
name|std
operator|::
name|string
name|FindPchSource
expr_stmt|;
comment|/// Filename to write statistics to.
name|std
operator|::
name|string
name|StatsFile
expr_stmt|;
name|public
label|:
name|FrontendOptions
argument_list|()
operator|:
name|DisableFree
argument_list|(
name|false
argument_list|)
operator|,
name|RelocatablePCH
argument_list|(
name|false
argument_list|)
operator|,
name|ShowHelp
argument_list|(
name|false
argument_list|)
operator|,
name|ShowStats
argument_list|(
name|false
argument_list|)
operator|,
name|ShowTimers
argument_list|(
name|false
argument_list|)
operator|,
name|ShowVersion
argument_list|(
name|false
argument_list|)
operator|,
name|FixWhatYouCan
argument_list|(
name|false
argument_list|)
operator|,
name|FixOnlyWarnings
argument_list|(
name|false
argument_list|)
operator|,
name|FixAndRecompile
argument_list|(
name|false
argument_list|)
operator|,
name|FixToTemporaries
argument_list|(
name|false
argument_list|)
operator|,
name|ARCMTMigrateEmitARCErrors
argument_list|(
name|false
argument_list|)
operator|,
name|SkipFunctionBodies
argument_list|(
name|false
argument_list|)
operator|,
name|UseGlobalModuleIndex
argument_list|(
name|true
argument_list|)
operator|,
name|GenerateGlobalModuleIndex
argument_list|(
name|true
argument_list|)
operator|,
name|ASTDumpDecls
argument_list|(
name|false
argument_list|)
operator|,
name|ASTDumpLookups
argument_list|(
name|false
argument_list|)
operator|,
name|BuildingImplicitModule
argument_list|(
name|false
argument_list|)
operator|,
name|ModulesEmbedAllFiles
argument_list|(
name|false
argument_list|)
operator|,
name|IncludeTimestamps
argument_list|(
name|true
argument_list|)
operator|,
name|ARCMTAction
argument_list|(
name|ARCMT_None
argument_list|)
operator|,
name|ObjCMTAction
argument_list|(
name|ObjCMT_None
argument_list|)
operator|,
name|ProgramAction
argument_list|(
argument|frontend::ParseSyntaxOnly
argument_list|)
block|{}
comment|/// getInputKindForExtension - Return the appropriate input kind for a file
comment|/// extension. For example, "c" would return IK_C.
comment|///
comment|/// \return The input kind for the extension, or IK_None if the extension is
comment|/// not recognized.
specifier|static
name|InputKind
name|getInputKindForExtension
argument_list|(
argument|StringRef Extension
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
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

