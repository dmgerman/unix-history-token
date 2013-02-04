begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- AnalyzerOptions.h - Analysis Engine Options ------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This header defines various options for the static analyzer that are set
end_comment

begin_comment
comment|// by the frontend and are consulted throughout the analyzer.
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
name|LLVM_CLANG_ANALYZEROPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYZEROPTIONS_H
end_define

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
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTConsumer
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
comment|/// Analysis - Set of available source code analyses.
enum|enum
name|Analyses
block|{
define|#
directive|define
name|ANALYSIS
parameter_list|(
name|NAME
parameter_list|,
name|CMDFLAG
parameter_list|,
name|DESC
parameter_list|,
name|SCOPE
parameter_list|)
value|NAME,
include|#
directive|include
file|"clang/StaticAnalyzer/Core/Analyses.def"
name|NumAnalyses
block|}
enum|;
comment|/// AnalysisStores - Set of available analysis store models.
enum|enum
name|AnalysisStores
block|{
define|#
directive|define
name|ANALYSIS_STORE
parameter_list|(
name|NAME
parameter_list|,
name|CMDFLAG
parameter_list|,
name|DESC
parameter_list|,
name|CREATFN
parameter_list|)
value|NAME##Model,
include|#
directive|include
file|"clang/StaticAnalyzer/Core/Analyses.def"
name|NumStores
block|}
enum|;
comment|/// AnalysisConstraints - Set of available constraint models.
enum|enum
name|AnalysisConstraints
block|{
define|#
directive|define
name|ANALYSIS_CONSTRAINTS
parameter_list|(
name|NAME
parameter_list|,
name|CMDFLAG
parameter_list|,
name|DESC
parameter_list|,
name|CREATFN
parameter_list|)
value|NAME##Model,
include|#
directive|include
file|"clang/StaticAnalyzer/Core/Analyses.def"
name|NumConstraints
block|}
enum|;
comment|/// AnalysisDiagClients - Set of available diagnostic clients for rendering
comment|///  analysis results.
enum|enum
name|AnalysisDiagClients
block|{
define|#
directive|define
name|ANALYSIS_DIAGNOSTICS
parameter_list|(
name|NAME
parameter_list|,
name|CMDFLAG
parameter_list|,
name|DESC
parameter_list|,
name|CREATFN
parameter_list|,
name|AUTOCREAT
parameter_list|)
value|PD_##NAME,
include|#
directive|include
file|"clang/StaticAnalyzer/Core/Analyses.def"
name|NUM_ANALYSIS_DIAG_CLIENTS
block|}
enum|;
comment|/// AnalysisPurgeModes - Set of available strategies for dead symbol removal.
enum|enum
name|AnalysisPurgeMode
block|{
define|#
directive|define
name|ANALYSIS_PURGE
parameter_list|(
name|NAME
parameter_list|,
name|CMDFLAG
parameter_list|,
name|DESC
parameter_list|)
value|NAME,
include|#
directive|include
file|"clang/StaticAnalyzer/Core/Analyses.def"
name|NumPurgeModes
block|}
enum|;
comment|/// AnalysisIPAMode - Set of inter-procedural modes.
enum|enum
name|AnalysisIPAMode
block|{
define|#
directive|define
name|ANALYSIS_IPA
parameter_list|(
name|NAME
parameter_list|,
name|CMDFLAG
parameter_list|,
name|DESC
parameter_list|)
value|NAME,
include|#
directive|include
file|"clang/StaticAnalyzer/Core/Analyses.def"
name|NumIPAModes
block|}
enum|;
comment|/// AnalysisInlineFunctionSelection - Set of inlining function selection heuristics.
enum|enum
name|AnalysisInliningMode
block|{
define|#
directive|define
name|ANALYSIS_INLINING_MODE
parameter_list|(
name|NAME
parameter_list|,
name|CMDFLAG
parameter_list|,
name|DESC
parameter_list|)
value|NAME,
include|#
directive|include
file|"clang/StaticAnalyzer/Core/Analyses.def"
name|NumInliningModes
block|}
enum|;
comment|/// \brief Describes the different kinds of C++ member functions which can be
comment|/// considered for inlining by the analyzer.
comment|///
comment|/// These options are cumulative; enabling one kind of member function will
comment|/// enable all kinds with lower enum values.
enum|enum
name|CXXInlineableMemberKind
block|{
comment|// Uninitialized = 0,
comment|/// A dummy mode in which no C++ inlining is enabled.
name|CIMK_None
init|=
literal|1
block|,
comment|/// Refers to regular member function and operator calls.
name|CIMK_MemberFunctions
block|,
comment|/// Refers to constructors (implicit or explicit).
comment|///
comment|/// Note that a constructor will not be inlined if the corresponding
comment|/// destructor is non-trivial.
name|CIMK_Constructors
block|,
comment|/// Refers to destructors (implicit or explicit).
name|CIMK_Destructors
block|}
enum|;
name|class
name|AnalyzerOptions
range|:
name|public
name|llvm
operator|::
name|RefCountedBase
operator|<
name|AnalyzerOptions
operator|>
block|{
name|public
operator|:
typedef|typedef
name|llvm
operator|::
name|StringMap
operator|<
name|std
operator|::
name|string
operator|>
name|ConfigTable
expr_stmt|;
comment|/// \brief Pair of checker name and enable/disable.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
block|,
name|bool
operator|>
block|>
name|CheckersControlList
decl_stmt|;
comment|/// \brief A key-value table of use-specified configuration values.
name|ConfigTable
name|Config
decl_stmt|;
name|AnalysisStores
name|AnalysisStoreOpt
decl_stmt|;
name|AnalysisConstraints
name|AnalysisConstraintsOpt
decl_stmt|;
name|AnalysisDiagClients
name|AnalysisDiagOpt
decl_stmt|;
name|AnalysisPurgeMode
name|AnalysisPurgeOpt
decl_stmt|;
comment|// \brief The interprocedural analysis mode.
name|AnalysisIPAMode
name|IPAMode
decl_stmt|;
name|std
operator|::
name|string
name|AnalyzeSpecificFunction
expr_stmt|;
comment|/// \brief The maximum number of exploded nodes the analyzer will generate.
name|unsigned
name|MaxNodes
decl_stmt|;
comment|/// \brief The maximum number of times the analyzer visits a block.
name|unsigned
name|maxBlockVisitOnPath
decl_stmt|;
name|unsigned
name|ShowCheckerHelp
range|:
literal|1
decl_stmt|;
name|unsigned
name|AnalyzeAll
range|:
literal|1
decl_stmt|;
name|unsigned
name|AnalyzerDisplayProgress
range|:
literal|1
decl_stmt|;
name|unsigned
name|AnalyzeNestedBlocks
range|:
literal|1
decl_stmt|;
comment|/// \brief The flag regulates if we should eagerly assume evaluations of
comment|/// conditionals, thus, bifurcating the path.
comment|///
comment|/// This flag indicates how the engine should handle expressions such as: 'x =
comment|/// (y != 0)'.  When this flag is true then the subexpression 'y != 0' will be
comment|/// eagerly assumed to be true or false, thus evaluating it to the integers 0
comment|/// or 1 respectively.  The upside is that this can increase analysis
comment|/// precision until we have a better way to lazily evaluate such logic.  The
comment|/// downside is that it eagerly bifurcates paths.
name|unsigned
name|eagerlyAssumeBinOpBifurcation
range|:
literal|1
decl_stmt|;
name|unsigned
name|TrimGraph
range|:
literal|1
decl_stmt|;
name|unsigned
name|visualizeExplodedGraphWithGraphViz
range|:
literal|1
decl_stmt|;
name|unsigned
name|visualizeExplodedGraphWithUbiGraph
range|:
literal|1
decl_stmt|;
name|unsigned
name|UnoptimizedCFG
range|:
literal|1
decl_stmt|;
name|unsigned
name|PrintStats
range|:
literal|1
decl_stmt|;
comment|/// \brief Do not re-analyze paths leading to exhausted nodes with a different
comment|/// strategy. We get better code coverage when retry is enabled.
name|unsigned
name|NoRetryExhausted
range|:
literal|1
decl_stmt|;
comment|/// \brief The inlining stack depth limit.
name|unsigned
name|InlineMaxStackDepth
decl_stmt|;
comment|/// \brief The mode of function selection used during inlining.
name|unsigned
name|InlineMaxFunctionSize
decl_stmt|;
comment|/// \brief The mode of function selection used during inlining.
name|AnalysisInliningMode
name|InliningMode
decl_stmt|;
name|private
label|:
comment|/// Controls which C++ member functions will be considered for inlining.
name|CXXInlineableMemberKind
name|CXXMemberInliningMode
decl_stmt|;
comment|/// \sa includeTemporaryDtorsInCFG
name|llvm
operator|::
name|Optional
operator|<
name|bool
operator|>
name|IncludeTemporaryDtorsInCFG
expr_stmt|;
comment|/// \sa mayInlineCXXStandardLibrary
name|llvm
operator|::
name|Optional
operator|<
name|bool
operator|>
name|InlineCXXStandardLibrary
expr_stmt|;
comment|/// \sa mayInlineTemplateFunctions
name|llvm
operator|::
name|Optional
operator|<
name|bool
operator|>
name|InlineTemplateFunctions
expr_stmt|;
comment|/// \sa mayInlineObjCMethod
name|llvm
operator|::
name|Optional
operator|<
name|bool
operator|>
name|ObjCInliningMode
expr_stmt|;
comment|// Cache of the "ipa-always-inline-size" setting.
comment|// \sa getAlwaysInlineSize
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
name|AlwaysInlineSize
expr_stmt|;
comment|/// \sa shouldPruneNullReturnPaths
name|llvm
operator|::
name|Optional
operator|<
name|bool
operator|>
name|PruneNullReturnPaths
expr_stmt|;
comment|/// \sa shouldAvoidSuppressingNullArgumentPaths
name|llvm
operator|::
name|Optional
operator|<
name|bool
operator|>
name|AvoidSuppressingNullArgumentPaths
expr_stmt|;
comment|/// \sa getGraphTrimInterval
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
name|GraphTrimInterval
expr_stmt|;
comment|/// Interprets an option's string value as a boolean.
comment|///
comment|/// Accepts the strings "true" and "false".
comment|/// If an option value is not provided, returns the given \p DefaultVal.
name|bool
name|getBooleanOption
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|bool
name|DefaultVal
parameter_list|)
function_decl|;
comment|/// Variant that accepts a Optional value to cache the result.
name|bool
name|getBooleanOption
argument_list|(
name|llvm
operator|::
name|Optional
operator|<
name|bool
operator|>
operator|&
name|V
argument_list|,
name|StringRef
name|Name
argument_list|,
name|bool
name|DefaultVal
argument_list|)
decl_stmt|;
comment|/// Interprets an option's string value as an integer value.
name|int
name|getOptionAsInteger
argument_list|(
name|llvm
operator|::
name|StringRef
name|Name
argument_list|,
name|int
name|DefaultVal
argument_list|)
decl_stmt|;
name|public
label|:
comment|/// Returns the option controlling which C++ member functions will be
comment|/// considered for inlining.
comment|///
comment|/// This is controlled by the 'c++-inlining' config option.
comment|///
comment|/// \sa CXXMemberInliningMode
name|bool
name|mayInlineCXXMemberFunction
parameter_list|(
name|CXXInlineableMemberKind
name|K
parameter_list|)
function_decl|;
comment|/// Returns true if ObjectiveC inlining is enabled, false otherwise.
name|bool
name|mayInlineObjCMethod
parameter_list|()
function_decl|;
comment|/// Returns whether or not the destructors for C++ temporary objects should
comment|/// be included in the CFG.
comment|///
comment|/// This is controlled by the 'cfg-temporary-dtors' config option, which
comment|/// accepts the values "true" and "false".
name|bool
name|includeTemporaryDtorsInCFG
parameter_list|()
function_decl|;
comment|/// Returns whether or not C++ standard library functions may be considered
comment|/// for inlining.
comment|///
comment|/// This is controlled by the 'c++-stdlib-inlining' config option, which
comment|/// accepts the values "true" and "false".
name|bool
name|mayInlineCXXStandardLibrary
parameter_list|()
function_decl|;
comment|/// Returns whether or not templated functions may be considered for inlining.
comment|///
comment|/// This is controlled by the 'c++-template-inlining' config option, which
comment|/// accepts the values "true" and "false".
name|bool
name|mayInlineTemplateFunctions
parameter_list|()
function_decl|;
comment|/// Returns whether or not paths that go through null returns should be
comment|/// suppressed.
comment|///
comment|/// This is a heuristic for avoiding bug reports with paths that go through
comment|/// inlined functions that are more defensive than their callers.
comment|///
comment|/// This is controlled by the 'suppress-null-return-paths' config option,
comment|/// which accepts the values "true" and "false".
name|bool
name|shouldPruneNullReturnPaths
parameter_list|()
function_decl|;
comment|/// Returns whether a bug report should \em not be suppressed if its path
comment|/// includes a call with a null argument, even if that call has a null return.
comment|///
comment|/// This option has no effect when #shouldPruneNullReturnPaths() is false.
comment|///
comment|/// This is a counter-heuristic to avoid false negatives.
comment|///
comment|/// This is controlled by the 'avoid-suppressing-null-argument-paths' config
comment|/// option, which accepts the values "true" and "false".
name|bool
name|shouldAvoidSuppressingNullArgumentPaths
parameter_list|()
function_decl|;
comment|// Returns the size of the functions (in basic blocks), which should be
comment|// considered to be small enough to always inline.
comment|//
comment|// This is controlled by "ipa-always-inline-size" analyzer-config option.
name|unsigned
name|getAlwaysInlineSize
parameter_list|()
function_decl|;
comment|/// Returns true if the analyzer engine should synthesize fake bodies
comment|/// for well-known functions.
name|bool
name|shouldSynthesizeBodies
parameter_list|()
function_decl|;
comment|/// Returns how often nodes in the ExplodedGraph should be recycled to save
comment|/// memory.
comment|///
comment|/// This is controlled by the 'graph-trim-interval' config option. To disable
comment|/// node reclamation, set the option to "0".
name|unsigned
name|getGraphTrimInterval
parameter_list|()
function_decl|;
name|public
label|:
name|AnalyzerOptions
argument_list|()
operator|:
name|CXXMemberInliningMode
argument_list|()
block|{
name|AnalysisStoreOpt
operator|=
name|RegionStoreModel
block|;
name|AnalysisConstraintsOpt
operator|=
name|RangeConstraintsModel
block|;
name|AnalysisDiagOpt
operator|=
name|PD_HTML
block|;
name|AnalysisPurgeOpt
operator|=
name|PurgeStmt
block|;
name|IPAMode
operator|=
name|DynamicDispatchBifurcate
block|;
name|ShowCheckerHelp
operator|=
literal|0
block|;
name|AnalyzeAll
operator|=
literal|0
block|;
name|AnalyzerDisplayProgress
operator|=
literal|0
block|;
name|AnalyzeNestedBlocks
operator|=
literal|0
block|;
name|eagerlyAssumeBinOpBifurcation
operator|=
literal|0
block|;
name|TrimGraph
operator|=
literal|0
block|;
name|visualizeExplodedGraphWithGraphViz
operator|=
literal|0
block|;
name|visualizeExplodedGraphWithUbiGraph
operator|=
literal|0
block|;
name|UnoptimizedCFG
operator|=
literal|0
block|;
name|PrintStats
operator|=
literal|0
block|;
name|NoRetryExhausted
operator|=
literal|0
block|;
comment|// Cap the stack depth at 4 calls (5 stack frames, base + 4 calls).
name|InlineMaxStackDepth
operator|=
literal|5
block|;
name|InlineMaxFunctionSize
operator|=
literal|200
block|;
name|InliningMode
operator|=
name|NoRedundancy
block|;   }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|IntrusiveRefCntPtr
operator|<
name|AnalyzerOptions
operator|>
name|AnalyzerOptionsRef
expr_stmt|;
end_typedef

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

