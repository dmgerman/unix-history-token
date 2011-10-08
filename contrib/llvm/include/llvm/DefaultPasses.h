begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/DefaultPasses.h - Default Pass Support code --------*- C++ -*-===//
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
comment|// This file defines the infrastructure for registering the standard pass list.
end_comment

begin_comment
comment|// This defines sets of standard optimizations that plugins can modify and
end_comment

begin_comment
comment|// front ends can use.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_DEFAULT_PASS_SUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEFAULT_PASS_SUPPORT_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PassManagerBase
decl_stmt|;
comment|/// Unique identifiers for the default standard passes.  The addresses of
comment|/// these symbols are used to uniquely identify passes from the default list.
name|namespace
name|DefaultStandardPasses
block|{
specifier|extern
name|unsigned
name|char
name|AggressiveDCEID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|ArgumentPromotionID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|BasicAliasAnalysisID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|CFGSimplificationID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|ConstantMergeID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|CorrelatedValuePropagationID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|DeadArgEliminationID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|DeadStoreEliminationID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|EarlyCSEID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|FunctionAttrsID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|FunctionInliningID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|GVNID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|GlobalDCEID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|GlobalOptimizerID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|GlobalsModRefID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|IPSCCPID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|IndVarSimplifyID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|InlinerPlaceholderID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|InstructionCombiningID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|JumpThreadingID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|LICMID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|LoopDeletionID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|LoopIdiomID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|LoopRotateID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|LoopUnrollID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|LoopUnswitchID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|MemCpyOptID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|PruneEHID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|ReassociateID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|SCCPID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|ScalarReplAggregatesID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|SimplifyLibCallsID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|StripDeadPrototypesID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|TailCallEliminationID
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|TypeBasedAliasAnalysisID
decl_stmt|;
block|}
comment|/// StandardPass - The class responsible for maintaining the lists of standard
name|class
name|StandardPass
block|{
name|friend
name|class
name|RegisterStandardPassLists
decl_stmt|;
name|public
label|:
comment|/// Predefined standard sets of passes
enum|enum
name|StandardSet
block|{
name|AliasAnalysis
block|,
name|Function
block|,
name|Module
block|,
name|LTO
block|}
enum|;
comment|/// Flags to specify whether a pass should be enabled.  Passes registered
comment|/// with the standard sets may specify a minimum optimization level and one
comment|/// or more flags that must be set when constructing the set for the pass to
comment|/// be used.
enum|enum
name|OptimizationFlags
block|{
comment|/// Optimize for size was requested.
name|OptimizeSize
init|=
literal|1
operator|<<
literal|0
block|,
comment|/// Allow passes which may make global module changes.
name|UnitAtATime
init|=
literal|1
operator|<<
literal|1
block|,
comment|/// UnrollLoops - Allow loop unrolling.
name|UnrollLoops
init|=
literal|1
operator|<<
literal|2
block|,
comment|/// Allow library calls to be simplified.
name|SimplifyLibCalls
init|=
literal|1
operator|<<
literal|3
block|,
comment|/// Whether the module may have code using exceptions.
name|HaveExceptions
init|=
literal|1
operator|<<
literal|4
block|,
comment|// Run an inliner pass as part of this set.
name|RunInliner
init|=
literal|1
operator|<<
literal|5
block|}
enum|;
enum|enum
name|OptimizationFlagComponents
block|{
comment|/// The low bits are used to store the optimization level.  When requesting
comment|/// passes, this should store the requested optimisation level.  When
comment|/// setting passes, this should set the minimum optimization level at which
comment|/// the pass will run.
name|OptimizationLevelMask
init|=
literal|0xf
block|,
comment|/// The maximum optimisation level at which the pass is run.
name|MaxOptimizationLevelMask
init|=
literal|0xf0
block|,
comment|// Flags that must be set
name|RequiredFlagMask
init|=
literal|0xff00
block|,
comment|// Flags that may not be set.
name|DisallowedFlagMask
init|=
literal|0xff0000
block|,
name|MaxOptimizationLevelShift
init|=
literal|4
block|,
name|RequiredFlagShift
init|=
literal|8
block|,
name|DisallowedFlagShift
init|=
literal|16
block|}
enum|;
comment|/// Returns the optimisation level from a set of flags.
specifier|static
name|unsigned
name|OptimizationLevel
parameter_list|(
name|unsigned
name|flags
parameter_list|)
block|{
return|return
name|flags
operator|&
name|OptimizationLevelMask
return|;
block|}
comment|/// Returns the maximum optimization level for this set of flags
specifier|static
name|unsigned
name|MaxOptimizationLevel
parameter_list|(
name|unsigned
name|flags
parameter_list|)
block|{
return|return
operator|(
name|flags
operator|&
name|MaxOptimizationLevelMask
operator|)
operator|>>
literal|4
return|;
block|}
comment|/// Constructs a set of flags from the specified minimum and maximum
comment|/// optimisation level
specifier|static
name|unsigned
name|OptimzationFlags
parameter_list|(
name|unsigned
name|minLevel
init|=
literal|0
parameter_list|,
name|unsigned
name|maxLevel
init|=
literal|0xf
parameter_list|,
name|unsigned
name|requiredFlags
init|=
literal|0
parameter_list|,
name|unsigned
name|disallowedFlags
init|=
literal|0
parameter_list|)
block|{
return|return
operator|(
operator|(
name|minLevel
operator|&
name|OptimizationLevelMask
operator|)
operator||
operator|(
operator|(
name|maxLevel
operator|<<
name|MaxOptimizationLevelShift
operator|)
operator|&
name|MaxOptimizationLevelMask
operator|)
operator||
operator|(
operator|(
name|requiredFlags
operator|<<
name|RequiredFlagShift
operator|)
operator|&
name|RequiredFlagMask
operator|)
operator||
operator|(
operator|(
name|disallowedFlags
operator|<<
name|DisallowedFlagShift
operator|)
operator|&
name|DisallowedFlagMask
operator|)
operator|)
return|;
block|}
comment|/// Returns the flags that must be set for this to match
specifier|static
name|unsigned
name|RequiredFlags
parameter_list|(
name|unsigned
name|flags
parameter_list|)
block|{
return|return
operator|(
name|flags
operator|&
name|RequiredFlagMask
operator|)
operator|>>
name|RequiredFlagShift
return|;
block|}
comment|/// Returns the flags that must not be set for this to match
specifier|static
name|unsigned
name|DisallowedFlags
parameter_list|(
name|unsigned
name|flags
parameter_list|)
block|{
return|return
operator|(
name|flags
operator|&
name|DisallowedFlagMask
operator|)
operator|>>
name|DisallowedFlagShift
return|;
block|}
comment|/// Register a standard pass in the specified set.  If flags is non-zero,
comment|/// then the pass will only be returned when the specified flags are set.
name|template
operator|<
name|typename
name|passName
operator|>
name|class
name|RegisterStandardPass
block|{
name|public
operator|:
name|RegisterStandardPass
argument_list|(
argument|StandardSet set
argument_list|,
argument|unsigned char *runBefore=
literal|0
argument_list|,
argument|unsigned flags=
literal|0
argument_list|,
argument|unsigned char *ID=
literal|0
argument_list|)
block|{
comment|// Use the pass's ID if one is not specified
name|RegisterDefaultPass
argument_list|(
name|PassInfo
operator|::
name|NormalCtor_t
argument_list|(
name|callDefaultCtor
operator|<
name|passName
operator|>
argument_list|)
argument_list|,
name|ID
operator|?
name|ID
operator|:
operator|(
name|unsigned
name|char
operator|*
operator|)
operator|&
name|passName
operator|::
name|ID
argument_list|,
name|runBefore
argument_list|,
name|set
argument_list|,
name|flags
argument_list|)
block|;     }
block|}
expr_stmt|;
comment|/// Adds the passes from the specified set to the provided pass manager
specifier|static
name|void
name|AddPassesFromSet
parameter_list|(
name|PassManagerBase
modifier|*
name|PM
parameter_list|,
name|StandardSet
name|set
parameter_list|,
name|unsigned
name|flags
init|=
literal|0
parameter_list|,
name|bool
name|VerifyEach
init|=
name|false
parameter_list|,
name|Pass
modifier|*
name|inliner
init|=
literal|0
parameter_list|)
function_decl|;
name|private
label|:
comment|/// Registers the default passes.  This is set by RegisterStandardPassLists
comment|/// and is called lazily.
specifier|static
name|void
function_decl|(
modifier|*
name|RegisterDefaultPasses
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/// Creates the verifier pass that is inserted when a VerifyEach is passed to
comment|/// AddPassesFromSet()
specifier|static
name|Pass
modifier|*
function_decl|(
modifier|*
name|CreateVerifierPass
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/// Registers the pass
specifier|static
name|void
name|RegisterDefaultPass
argument_list|(
name|PassInfo
operator|::
name|NormalCtor_t
name|constructor
argument_list|,
name|unsigned
name|char
operator|*
name|newPass
argument_list|,
name|unsigned
name|char
operator|*
name|oldPass
argument_list|,
name|StandardSet
name|set
argument_list|,
name|unsigned
name|flags
operator|=
literal|0
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

