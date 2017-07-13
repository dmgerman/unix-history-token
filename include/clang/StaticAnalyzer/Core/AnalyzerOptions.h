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
name|LLVM_CLANG_STATICANALYZER_CORE_ANALYZEROPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_ANALYZEROPTIONS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
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
name|namespace
name|ento
block|{
name|class
name|CheckerBase
decl_stmt|;
block|}
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
parameter_list|)
value|PD_##NAME,
include|#
directive|include
file|"clang/StaticAnalyzer/Core/Analyses.def"
name|PD_NONE
block|,
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
comment|/// \brief Describes the different modes of inter-procedural analysis.
enum|enum
name|IPAKind
block|{
name|IPAK_NotSet
init|=
literal|0
block|,
comment|/// Perform only intra-procedural analysis.
name|IPAK_None
init|=
literal|1
block|,
comment|/// Inline C functions and blocks when their definitions are available.
name|IPAK_BasicInlining
init|=
literal|2
block|,
comment|/// Inline callees(C, C++, ObjC) when their definitions are available.
name|IPAK_Inlining
init|=
literal|3
block|,
comment|/// Enable inlining of dynamically dispatched methods.
name|IPAK_DynamicDispatch
init|=
literal|4
block|,
comment|/// Enable inlining of dynamically dispatched methods, bifurcate paths when
comment|/// exact type info is unavailable.
name|IPAK_DynamicDispatchBifurcate
init|=
literal|5
block|}
enum|;
name|class
name|AnalyzerOptions
range|:
name|public
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
specifier|static
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|getRegisteredCheckers
argument_list|(
argument|bool IncludeExperimental = false
argument_list|)
decl_stmt|;
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
operator|,
name|bool
operator|>
expr|>
name|CheckersControlList
expr_stmt|;
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
name|std
operator|::
name|string
name|AnalyzeSpecificFunction
expr_stmt|;
comment|/// \brief The maximum number of times the analyzer visits a block.
name|unsigned
name|maxBlockVisitOnPath
decl_stmt|;
comment|/// \brief Disable all analyzer checks.
comment|///
comment|/// This flag allows one to disable analyzer checks on the code processed by
comment|/// the given analysis consumer. Note, the code will get parsed and the
comment|/// command-line options will get checked.
name|unsigned
name|DisableAllChecks
range|:
literal|1
decl_stmt|;
name|unsigned
name|ShowCheckerHelp
range|:
literal|1
decl_stmt|;
name|unsigned
name|ShowEnabledCheckerList
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
name|AnalysisInliningMode
name|InliningMode
decl_stmt|;
name|private
label|:
comment|/// \brief Describes the kinds for high-level analyzer mode.
enum|enum
name|UserModeKind
block|{
name|UMK_NotSet
init|=
literal|0
block|,
comment|/// Perform shallow but fast analyzes.
name|UMK_Shallow
init|=
literal|1
block|,
comment|/// Perform deep analyzes.
name|UMK_Deep
init|=
literal|2
block|}
enum|;
comment|/// Controls the high-level analyzer mode, which influences the default
comment|/// settings for some of the lower-level config options (such as IPAMode).
comment|/// \sa getUserMode
name|UserModeKind
name|UserMode
decl_stmt|;
comment|/// Controls the mode of inter-procedural analysis.
name|IPAKind
name|IPAMode
decl_stmt|;
comment|/// Controls which C++ member functions will be considered for inlining.
name|CXXInlineableMemberKind
name|CXXMemberInliningMode
decl_stmt|;
comment|/// \sa includeImplicitDtorsInCFG
name|Optional
operator|<
name|bool
operator|>
name|IncludeImplicitDtorsInCFG
expr_stmt|;
comment|/// \sa includeTemporaryDtorsInCFG
name|Optional
operator|<
name|bool
operator|>
name|IncludeTemporaryDtorsInCFG
expr_stmt|;
comment|/// \sa IncludeLifetimeInCFG
name|Optional
operator|<
name|bool
operator|>
name|IncludeLifetimeInCFG
expr_stmt|;
comment|/// \sa mayInlineCXXStandardLibrary
name|Optional
operator|<
name|bool
operator|>
name|InlineCXXStandardLibrary
expr_stmt|;
comment|/// \sa mayInlineTemplateFunctions
name|Optional
operator|<
name|bool
operator|>
name|InlineTemplateFunctions
expr_stmt|;
comment|/// \sa mayInlineCXXAllocator
name|Optional
operator|<
name|bool
operator|>
name|InlineCXXAllocator
expr_stmt|;
comment|/// \sa mayInlineCXXContainerMethods
name|Optional
operator|<
name|bool
operator|>
name|InlineCXXContainerMethods
expr_stmt|;
comment|/// \sa mayInlineCXXSharedPtrDtor
name|Optional
operator|<
name|bool
operator|>
name|InlineCXXSharedPtrDtor
expr_stmt|;
comment|/// \sa mayInlineObjCMethod
name|Optional
operator|<
name|bool
operator|>
name|ObjCInliningMode
expr_stmt|;
comment|// Cache of the "ipa-always-inline-size" setting.
comment|// \sa getAlwaysInlineSize
name|Optional
operator|<
name|unsigned
operator|>
name|AlwaysInlineSize
expr_stmt|;
comment|/// \sa shouldSuppressNullReturnPaths
name|Optional
operator|<
name|bool
operator|>
name|SuppressNullReturnPaths
expr_stmt|;
comment|// \sa getMaxInlinableSize
name|Optional
operator|<
name|unsigned
operator|>
name|MaxInlinableSize
expr_stmt|;
comment|/// \sa shouldAvoidSuppressingNullArgumentPaths
name|Optional
operator|<
name|bool
operator|>
name|AvoidSuppressingNullArgumentPaths
expr_stmt|;
comment|/// \sa shouldSuppressInlinedDefensiveChecks
name|Optional
operator|<
name|bool
operator|>
name|SuppressInlinedDefensiveChecks
expr_stmt|;
comment|/// \sa shouldSuppressFromCXXStandardLibrary
name|Optional
operator|<
name|bool
operator|>
name|SuppressFromCXXStandardLibrary
expr_stmt|;
comment|/// \sa reportIssuesInMainSourceFile
name|Optional
operator|<
name|bool
operator|>
name|ReportIssuesInMainSourceFile
expr_stmt|;
comment|/// \sa StableReportFilename
name|Optional
operator|<
name|bool
operator|>
name|StableReportFilename
expr_stmt|;
comment|/// \sa getGraphTrimInterval
name|Optional
operator|<
name|unsigned
operator|>
name|GraphTrimInterval
expr_stmt|;
comment|/// \sa getMaxTimesInlineLarge
name|Optional
operator|<
name|unsigned
operator|>
name|MaxTimesInlineLarge
expr_stmt|;
comment|/// \sa getMinCFGSizeTreatFunctionsAsLarge
name|Optional
operator|<
name|unsigned
operator|>
name|MinCFGSizeTreatFunctionsAsLarge
expr_stmt|;
comment|/// \sa getMaxNodesPerTopLevelFunction
name|Optional
operator|<
name|unsigned
operator|>
name|MaxNodesPerTopLevelFunction
expr_stmt|;
comment|/// \sa shouldInlineLambdas
name|Optional
operator|<
name|bool
operator|>
name|InlineLambdas
expr_stmt|;
comment|/// \sa shouldWidenLoops
name|Optional
operator|<
name|bool
operator|>
name|WidenLoops
expr_stmt|;
comment|/// \sa shouldDisplayNotesAsEvents
name|Optional
operator|<
name|bool
operator|>
name|DisplayNotesAsEvents
expr_stmt|;
comment|/// A helper function that retrieves option for a given full-qualified
comment|/// checker name.
comment|/// Options for checkers can be specified via 'analyzer-config' command-line
comment|/// option.
comment|/// Example:
comment|/// @code-analyzer-config unix.Malloc:OptionName=CheckerOptionValue @endcode
comment|/// or @code-analyzer-config unix:OptionName=GroupOptionValue @endcode
comment|/// for groups of checkers.
comment|/// @param [in] CheckerName  Full-qualified checker name, like
comment|/// alpha.unix.StreamChecker.
comment|/// @param [in] OptionName  Name of the option to get.
comment|/// @param [in] Default  Default value if no option is specified.
comment|/// @param [in] SearchInParents If set to true and the searched option was not
comment|/// specified for the given checker the options for the parent packages will
comment|/// be searched as well. The inner packages take precedence over the outer
comment|/// ones.
comment|/// @retval CheckerOptionValue  An option for a checker if it was specified.
comment|/// @retval GroupOptionValue  An option for group if it was specified and no
comment|/// checker-specific options were found. The closer group to checker,
comment|/// the more priority it has. For example, @c coregroup.subgroup has more
comment|/// priority than @c coregroup for @c coregroup.subgroup.CheckerName checker.
comment|/// @retval Default  If nor checker option, nor group option was found.
name|StringRef
name|getCheckerOption
parameter_list|(
name|StringRef
name|CheckerName
parameter_list|,
name|StringRef
name|OptionName
parameter_list|,
name|StringRef
name|Default
parameter_list|,
name|bool
name|SearchInParents
init|=
name|false
parameter_list|)
function_decl|;
name|public
label|:
comment|/// Interprets an option's string value as a boolean. The "true" string is
comment|/// interpreted as true and the "false" string is interpreted as false.
comment|///
comment|/// If an option value is not provided, returns the given \p DefaultVal.
comment|/// @param [in] Name Name for option to retrieve.
comment|/// @param [in] DefaultVal Default value returned if no such option was
comment|/// specified.
comment|/// @param [in] C The optional checker parameter that can be used to restrict
comment|/// the search to the options of this particular checker (and its parents
comment|/// dependening on search mode).
comment|/// @param [in] SearchInParents If set to true and the searched option was not
comment|/// specified for the given checker the options for the parent packages will
comment|/// be searched as well. The inner packages take precedence over the outer
comment|/// ones.
name|bool
name|getBooleanOption
argument_list|(
name|StringRef
name|Name
argument_list|,
name|bool
name|DefaultVal
argument_list|,
specifier|const
name|ento
operator|::
name|CheckerBase
operator|*
name|C
operator|=
name|nullptr
argument_list|,
name|bool
name|SearchInParents
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// Variant that accepts a Optional value to cache the result.
comment|///
comment|/// @param [in,out] V Return value storage, returned if parameter contains
comment|/// an existing valid option, else it is used to store a return value
comment|/// @param [in] Name Name for option to retrieve.
comment|/// @param [in] DefaultVal Default value returned if no such option was
comment|/// specified.
comment|/// @param [in] C The optional checker parameter that can be used to restrict
comment|/// the search to the options of this particular checker (and its parents
comment|/// dependening on search mode).
comment|/// @param [in] SearchInParents If set to true and the searched option was not
comment|/// specified for the given checker the options for the parent packages will
comment|/// be searched as well. The inner packages take precedence over the outer
comment|/// ones.
name|bool
name|getBooleanOption
argument_list|(
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
argument_list|,
specifier|const
name|ento
operator|::
name|CheckerBase
operator|*
name|C
operator|=
name|nullptr
argument_list|,
name|bool
name|SearchInParents
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// Interprets an option's string value as an integer value.
comment|///
comment|/// If an option value is not provided, returns the given \p DefaultVal.
comment|/// @param [in] Name Name for option to retrieve.
comment|/// @param [in] DefaultVal Default value returned if no such option was
comment|/// specified.
comment|/// @param [in] C The optional checker parameter that can be used to restrict
comment|/// the search to the options of this particular checker (and its parents
comment|/// dependening on search mode).
comment|/// @param [in] SearchInParents If set to true and the searched option was not
comment|/// specified for the given checker the options for the parent packages will
comment|/// be searched as well. The inner packages take precedence over the outer
comment|/// ones.
name|int
name|getOptionAsInteger
argument_list|(
name|StringRef
name|Name
argument_list|,
name|int
name|DefaultVal
argument_list|,
specifier|const
name|ento
operator|::
name|CheckerBase
operator|*
name|C
operator|=
name|nullptr
argument_list|,
name|bool
name|SearchInParents
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// Query an option's string value.
comment|///
comment|/// If an option value is not provided, returns the given \p DefaultVal.
comment|/// @param [in] Name Name for option to retrieve.
comment|/// @param [in] DefaultVal Default value returned if no such option was
comment|/// specified.
comment|/// @param [in] C The optional checker parameter that can be used to restrict
comment|/// the search to the options of this particular checker (and its parents
comment|/// dependening on search mode).
comment|/// @param [in] SearchInParents If set to true and the searched option was not
comment|/// specified for the given checker the options for the parent packages will
comment|/// be searched as well. The inner packages take precedence over the outer
comment|/// ones.
name|StringRef
name|getOptionAsString
argument_list|(
name|StringRef
name|Name
argument_list|,
name|StringRef
name|DefaultVal
argument_list|,
specifier|const
name|ento
operator|::
name|CheckerBase
operator|*
name|C
operator|=
name|nullptr
argument_list|,
name|bool
name|SearchInParents
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// \brief Retrieves and sets the UserMode. This is a high-level option,
comment|/// which is used to set other low-level options. It is not accessible
comment|/// outside of AnalyzerOptions.
name|UserModeKind
name|getUserMode
parameter_list|()
function_decl|;
comment|/// \brief Returns the inter-procedural analysis mode.
name|IPAKind
name|getIPAMode
parameter_list|()
function_decl|;
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
comment|/// Returns whether or not implicit destructors for C++ objects should
comment|/// be included in the CFG.
comment|///
comment|/// This is controlled by the 'cfg-implicit-dtors' config option, which
comment|/// accepts the values "true" and "false".
name|bool
name|includeImplicitDtorsInCFG
parameter_list|()
function_decl|;
comment|/// Returns whether or not end-of-lifetime information should be included in
comment|/// the CFG.
comment|///
comment|/// This is controlled by the 'cfg-lifetime' config option, which accepts
comment|/// the values "true" and "false".
name|bool
name|includeLifetimeInCFG
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
comment|/// Returns whether or not allocator call may be considered for inlining.
comment|///
comment|/// This is controlled by the 'c++-allocator-inlining' config option, which
comment|/// accepts the values "true" and "false".
name|bool
name|mayInlineCXXAllocator
parameter_list|()
function_decl|;
comment|/// Returns whether or not methods of C++ container objects may be considered
comment|/// for inlining.
comment|///
comment|/// This is controlled by the 'c++-container-inlining' config option, which
comment|/// accepts the values "true" and "false".
name|bool
name|mayInlineCXXContainerMethods
parameter_list|()
function_decl|;
comment|/// Returns whether or not the destructor of C++ 'shared_ptr' may be
comment|/// considered for inlining.
comment|///
comment|/// This covers std::shared_ptr, std::tr1::shared_ptr, and boost::shared_ptr,
comment|/// and indeed any destructor named "~shared_ptr".
comment|///
comment|/// This is controlled by the 'c++-shared_ptr-inlining' config option, which
comment|/// accepts the values "true" and "false".
name|bool
name|mayInlineCXXSharedPtrDtor
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
name|shouldSuppressNullReturnPaths
parameter_list|()
function_decl|;
comment|/// Returns whether a bug report should \em not be suppressed if its path
comment|/// includes a call with a null argument, even if that call has a null return.
comment|///
comment|/// This option has no effect when #shouldSuppressNullReturnPaths() is false.
comment|///
comment|/// This is a counter-heuristic to avoid false negatives.
comment|///
comment|/// This is controlled by the 'avoid-suppressing-null-argument-paths' config
comment|/// option, which accepts the values "true" and "false".
name|bool
name|shouldAvoidSuppressingNullArgumentPaths
parameter_list|()
function_decl|;
comment|/// Returns whether or not diagnostics containing inlined defensive NULL
comment|/// checks should be suppressed.
comment|///
comment|/// This is controlled by the 'suppress-inlined-defensive-checks' config
comment|/// option, which accepts the values "true" and "false".
name|bool
name|shouldSuppressInlinedDefensiveChecks
parameter_list|()
function_decl|;
comment|/// Returns whether or not diagnostics reported within the C++ standard
comment|/// library should be suppressed.
comment|///
comment|/// This is controlled by the 'suppress-c++-stdlib' config option,
comment|/// which accepts the values "true" and "false".
name|bool
name|shouldSuppressFromCXXStandardLibrary
parameter_list|()
function_decl|;
comment|/// Returns whether or not the diagnostic report should be always reported
comment|/// in the main source file and not the headers.
comment|///
comment|/// This is controlled by the 'report-in-main-source-file' config option,
comment|/// which accepts the values "true" and "false".
name|bool
name|shouldReportIssuesInMainSourceFile
parameter_list|()
function_decl|;
comment|/// Returns whether or not the report filename should be random or not.
comment|///
comment|/// This is controlled by the 'stable-report-filename' config option,
comment|/// which accepts the values "true" and "false". Default = false
name|bool
name|shouldWriteStableReportFilename
parameter_list|()
function_decl|;
comment|/// Returns whether irrelevant parts of a bug report path should be pruned
comment|/// out of the final output.
comment|///
comment|/// This is controlled by the 'prune-paths' config option, which accepts the
comment|/// values "true" and "false".
name|bool
name|shouldPrunePaths
parameter_list|()
function_decl|;
comment|/// Returns true if 'static' initializers should be in conditional logic
comment|/// in the CFG.
name|bool
name|shouldConditionalizeStaticInitializers
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
comment|// Returns the bound on the number of basic blocks in an inlined function
comment|// (50 by default).
comment|//
comment|// This is controlled by "-analyzer-config max-inlinable-size" option.
name|unsigned
name|getMaxInlinableSize
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
comment|/// Returns the maximum times a large function could be inlined.
comment|///
comment|/// This is controlled by the 'max-times-inline-large' config option.
name|unsigned
name|getMaxTimesInlineLarge
parameter_list|()
function_decl|;
comment|/// Returns the number of basic blocks a function needs to have to be
comment|/// considered large for the 'max-times-inline-large' config option.
comment|///
comment|/// This is controlled by the 'min-cfg-size-treat-functions-as-large' config
comment|/// option.
name|unsigned
name|getMinCFGSizeTreatFunctionsAsLarge
parameter_list|()
function_decl|;
comment|/// Returns the maximum number of nodes the analyzer can generate while
comment|/// exploring a top level function (for each exploded graph).
comment|/// 150000 is default; 0 means no limit.
comment|///
comment|/// This is controlled by the 'max-nodes' config option.
name|unsigned
name|getMaxNodesPerTopLevelFunction
parameter_list|()
function_decl|;
comment|/// Returns true if lambdas should be inlined. Otherwise a sink node will be
comment|/// generated each time a LambdaExpr is visited.
name|bool
name|shouldInlineLambdas
parameter_list|()
function_decl|;
comment|/// Returns true if the analysis should try to widen loops.
comment|/// This is controlled by the 'widen-loops' config option.
name|bool
name|shouldWidenLoops
parameter_list|()
function_decl|;
comment|/// Returns true if the bug reporter should transparently treat extra note
comment|/// diagnostic pieces as event diagnostic pieces. Useful when the diagnostic
comment|/// consumer doesn't support the extra note pieces.
comment|///
comment|/// This is controlled by the 'extra-notes-as-events' option, which defaults
comment|/// to false when unset.
name|bool
name|shouldDisplayNotesAsEvents
parameter_list|()
function_decl|;
name|public
label|:
name|AnalyzerOptions
argument_list|()
operator|:
name|AnalysisStoreOpt
argument_list|(
name|RegionStoreModel
argument_list|)
operator|,
name|AnalysisConstraintsOpt
argument_list|(
name|RangeConstraintsModel
argument_list|)
operator|,
name|AnalysisDiagOpt
argument_list|(
name|PD_HTML
argument_list|)
operator|,
name|AnalysisPurgeOpt
argument_list|(
name|PurgeStmt
argument_list|)
operator|,
name|DisableAllChecks
argument_list|(
literal|0
argument_list|)
operator|,
name|ShowCheckerHelp
argument_list|(
literal|0
argument_list|)
operator|,
name|ShowEnabledCheckerList
argument_list|(
literal|0
argument_list|)
operator|,
name|AnalyzeAll
argument_list|(
literal|0
argument_list|)
operator|,
name|AnalyzerDisplayProgress
argument_list|(
literal|0
argument_list|)
operator|,
name|AnalyzeNestedBlocks
argument_list|(
literal|0
argument_list|)
operator|,
name|eagerlyAssumeBinOpBifurcation
argument_list|(
literal|0
argument_list|)
operator|,
name|TrimGraph
argument_list|(
literal|0
argument_list|)
operator|,
name|visualizeExplodedGraphWithGraphViz
argument_list|(
literal|0
argument_list|)
operator|,
name|visualizeExplodedGraphWithUbiGraph
argument_list|(
literal|0
argument_list|)
operator|,
name|UnoptimizedCFG
argument_list|(
literal|0
argument_list|)
operator|,
name|PrintStats
argument_list|(
literal|0
argument_list|)
operator|,
name|NoRetryExhausted
argument_list|(
literal|0
argument_list|)
operator|,
comment|// Cap the stack depth at 4 calls (5 stack frames, base + 4 calls).
name|InlineMaxStackDepth
argument_list|(
literal|5
argument_list|)
operator|,
name|InliningMode
argument_list|(
name|NoRedundancy
argument_list|)
operator|,
name|UserMode
argument_list|(
name|UMK_NotSet
argument_list|)
operator|,
name|IPAMode
argument_list|(
name|IPAK_NotSet
argument_list|)
operator|,
name|CXXMemberInliningMode
argument_list|()
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
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

