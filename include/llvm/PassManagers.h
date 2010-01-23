begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/PassManagers.h - Pass Infrastructure classes  -------*- C++ -*-===//
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
comment|// This file declares the LLVM Pass Manager infrastructure.
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
name|LLVM_PASSMANAGERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PASSMANAGERS_H
end_define

begin_include
include|#
directive|include
file|"llvm/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|<deque>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Overview:
end_comment

begin_comment
comment|// The Pass Manager Infrastructure manages passes. It's responsibilities are:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   o Manage optimization pass execution order
end_comment

begin_comment
comment|//   o Make required Analysis information available before pass P is run
end_comment

begin_comment
comment|//   o Release memory occupied by dead passes
end_comment

begin_comment
comment|//   o If Analysis information is dirtied by a pass then regenerate Analysis
end_comment

begin_comment
comment|//     information before it is consumed by another pass.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Pass Manager Infrastructure uses multiple pass managers.  They are
end_comment

begin_comment
comment|// PassManager, FunctionPassManager, MPPassManager, FPPassManager, BBPassManager.
end_comment

begin_comment
comment|// This class hierarchy uses multiple inheritance but pass managers do not
end_comment

begin_comment
comment|// derive from another pass manager.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PassManager and FunctionPassManager are two top-level pass manager that
end_comment

begin_comment
comment|// represents the external interface of this entire pass manager infrastucture.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Important classes :
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// [o] class PMTopLevelManager;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Two top level managers, PassManager and FunctionPassManager, derive from
end_comment

begin_comment
comment|// PMTopLevelManager. PMTopLevelManager manages information used by top level
end_comment

begin_comment
comment|// managers such as last user info.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// [o] class PMDataManager;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PMDataManager manages information, e.g. list of available analysis info,
end_comment

begin_comment
comment|// used by a pass manager to manage execution order of passes. It also provides
end_comment

begin_comment
comment|// a place to implement common pass manager APIs. All pass managers derive from
end_comment

begin_comment
comment|// PMDataManager.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// [o] class BBPassManager : public FunctionPass, public PMDataManager;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BBPassManager manages BasicBlockPasses.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// [o] class FunctionPassManager;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This is a external interface used by JIT to manage FunctionPasses. This
end_comment

begin_comment
comment|// interface relies on FunctionPassManagerImpl to do all the tasks.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// [o] class FunctionPassManagerImpl : public ModulePass, PMDataManager,
end_comment

begin_comment
comment|//                                     public PMTopLevelManager;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FunctionPassManagerImpl is a top level manager. It manages FPPassManagers
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// [o] class FPPassManager : public ModulePass, public PMDataManager;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FPPassManager manages FunctionPasses and BBPassManagers
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// [o] class MPPassManager : public Pass, public PMDataManager;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MPPassManager manages ModulePasses and FPPassManagers
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// [o] class PassManager;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This is a external interface used by various tools to manages passes. It
end_comment

begin_comment
comment|// relies on PassManagerImpl to do all the tasks.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// [o] class PassManagerImpl : public Pass, public PMDataManager,
end_comment

begin_comment
comment|//                             public PMDTopLevelManager
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PassManagerImpl is a top level pass manager responsible for managing
end_comment

begin_comment
comment|// MPPassManagers.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"llvm/Support/PrettyStackTrace.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|Timer
decl_stmt|;
comment|/// FunctionPassManager and PassManager, two top level managers, serve
comment|/// as the public interface of pass manager infrastructure.
enum|enum
name|TopLevelManagerType
block|{
name|TLM_Function
block|,
comment|// FunctionPassManager
name|TLM_Pass
comment|// PassManager
block|}
enum|;
comment|// enums for debugging strings
enum|enum
name|PassDebuggingString
block|{
name|EXECUTION_MSG
block|,
comment|// "Executing Pass '"
name|MODIFICATION_MSG
block|,
comment|// "' Made Modification '"
name|FREEING_MSG
block|,
comment|// " Freeing Pass '"
name|ON_BASICBLOCK_MSG
block|,
comment|// "'  on BasicBlock '" + PassName + "'...\n"
name|ON_FUNCTION_MSG
block|,
comment|// "' on Function '" + FunctionName + "'...\n"
name|ON_MODULE_MSG
block|,
comment|// "' on Module '" + ModuleName + "'...\n"
name|ON_LOOP_MSG
block|,
comment|// " 'on Loop ...\n'"
name|ON_CG_MSG
comment|// "' on Call Graph ...\n'"
block|}
enum|;
comment|/// PassManagerPrettyStackEntry - This is used to print informative information
comment|/// about what pass is running when/if a stack trace is generated.
name|class
name|PassManagerPrettyStackEntry
range|:
name|public
name|PrettyStackTraceEntry
block|{
name|Pass
operator|*
name|P
block|;
name|Value
operator|*
name|V
block|;
name|Module
operator|*
name|M
block|;
name|public
operator|:
name|explicit
name|PassManagerPrettyStackEntry
argument_list|(
name|Pass
operator|*
name|p
argument_list|)
operator|:
name|P
argument_list|(
name|p
argument_list|)
block|,
name|V
argument_list|(
literal|0
argument_list|)
block|,
name|M
argument_list|(
literal|0
argument_list|)
block|{}
comment|// When P is releaseMemory'd.
name|PassManagerPrettyStackEntry
argument_list|(
name|Pass
operator|*
name|p
argument_list|,
name|Value
operator|&
name|v
argument_list|)
operator|:
name|P
argument_list|(
name|p
argument_list|)
block|,
name|V
argument_list|(
operator|&
name|v
argument_list|)
block|,
name|M
argument_list|(
literal|0
argument_list|)
block|{}
comment|// When P is run on V
name|PassManagerPrettyStackEntry
argument_list|(
name|Pass
operator|*
name|p
argument_list|,
name|Module
operator|&
name|m
argument_list|)
operator|:
name|P
argument_list|(
name|p
argument_list|)
block|,
name|V
argument_list|(
literal|0
argument_list|)
block|,
name|M
argument_list|(
argument|&m
argument_list|)
block|{}
comment|// When P is run on M
comment|/// print - Emit information about this stack frame to OS.
name|virtual
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|; }
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// PMStack
comment|//
comment|/// PMStack
comment|/// Top level pass managers (see PassManager.cpp) maintain active Pass Managers
comment|/// using PMStack. Each Pass implements assignPassManager() to connect itself
comment|/// with appropriate manager. assignPassManager() walks PMStack to find
comment|/// suitable manager.
comment|///
comment|/// PMStack is just a wrapper around standard deque that overrides pop() and
comment|/// push() methods.
name|class
name|PMStack
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|deque
operator|<
name|PMDataManager
operator|*
operator|>
operator|::
name|reverse_iterator
name|iterator
expr_stmt|;
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|S
operator|.
name|rbegin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|S
operator|.
name|rend
argument_list|()
return|;
block|}
name|void
name|handleLastUserOverflow
parameter_list|()
function_decl|;
name|void
name|pop
parameter_list|()
function_decl|;
specifier|inline
name|PMDataManager
modifier|*
name|top
parameter_list|()
block|{
return|return
name|S
operator|.
name|back
argument_list|()
return|;
block|}
name|void
name|push
parameter_list|(
name|PMDataManager
modifier|*
name|PM
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|empty
parameter_list|()
block|{
return|return
name|S
operator|.
name|empty
argument_list|()
return|;
block|}
name|void
name|dump
parameter_list|()
function_decl|;
name|private
label|:
name|std
operator|::
name|deque
operator|<
name|PMDataManager
operator|*
operator|>
name|S
expr_stmt|;
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// PMTopLevelManager
comment|//
comment|/// PMTopLevelManager manages LastUser info and collects common APIs used by
comment|/// top level pass managers.
name|class
name|PMTopLevelManager
block|{
name|public
label|:
name|virtual
name|unsigned
name|getNumContainedManagers
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|PassManagers
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// Schedule pass P for execution. Make sure that passes required by
comment|/// P are run before P is run. Update analysis info maintained by
comment|/// the manager. Remove dead passes. This is a recursive function.
name|void
name|schedulePass
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|)
function_decl|;
comment|/// This is implemented by top level pass manager and used by
comment|/// schedulePass() to add analysis info passes that are not available.
name|virtual
name|void
name|addTopLevelPass
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Set pass P as the last user of the given analysis passes.
name|void
name|setLastUser
argument_list|(
name|SmallVector
operator|<
name|Pass
operator|*
argument_list|,
literal|12
operator|>
operator|&
name|AnalysisPasses
argument_list|,
name|Pass
operator|*
name|P
argument_list|)
decl_stmt|;
comment|/// Collect passes whose last user is P
name|void
name|collectLastUses
argument_list|(
name|SmallVector
operator|<
name|Pass
operator|*
argument_list|,
literal|12
operator|>
operator|&
name|LastUses
argument_list|,
name|Pass
operator|*
name|P
argument_list|)
decl_stmt|;
comment|/// Find the pass that implements Analysis AID. Search immutable
comment|/// passes and all pass managers. If desired pass is not found
comment|/// then return NULL.
name|Pass
modifier|*
name|findAnalysisPass
parameter_list|(
name|AnalysisID
name|AID
parameter_list|)
function_decl|;
comment|/// Find analysis usage information for the pass P.
name|AnalysisUsage
modifier|*
name|findAnalysisUsage
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|)
function_decl|;
name|explicit
name|PMTopLevelManager
parameter_list|(
name|enum
name|TopLevelManagerType
name|t
parameter_list|)
function_decl|;
name|virtual
operator|~
name|PMTopLevelManager
argument_list|()
expr_stmt|;
comment|/// Add immutable pass and initialize it.
specifier|inline
name|void
name|addImmutablePass
parameter_list|(
name|ImmutablePass
modifier|*
name|P
parameter_list|)
block|{
name|P
operator|->
name|initializePass
argument_list|()
expr_stmt|;
name|ImmutablePasses
operator|.
name|push_back
argument_list|(
name|P
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|SmallVector
operator|<
name|ImmutablePass
operator|*
operator|,
literal|8
operator|>
operator|&
name|getImmutablePasses
argument_list|()
block|{
return|return
name|ImmutablePasses
return|;
block|}
name|void
name|addPassManager
parameter_list|(
name|PMDataManager
modifier|*
name|Manager
parameter_list|)
block|{
name|PassManagers
operator|.
name|push_back
argument_list|(
name|Manager
argument_list|)
expr_stmt|;
block|}
comment|// Add Manager into the list of managers that are not directly
comment|// maintained by this top level pass manager
specifier|inline
name|void
name|addIndirectPassManager
parameter_list|(
name|PMDataManager
modifier|*
name|Manager
parameter_list|)
block|{
name|IndirectPassManagers
operator|.
name|push_back
argument_list|(
name|Manager
argument_list|)
expr_stmt|;
block|}
comment|// Print passes managed by this top level manager.
name|void
name|dumpPasses
argument_list|()
specifier|const
expr_stmt|;
name|void
name|dumpArguments
argument_list|()
specifier|const
expr_stmt|;
name|void
name|initializeAllAnalysisInfo
parameter_list|()
function_decl|;
comment|// Active Pass Managers
name|PMStack
name|activeStack
decl_stmt|;
name|protected
label|:
comment|/// Collection of pass managers
name|SmallVector
operator|<
name|PMDataManager
operator|*
operator|,
literal|8
operator|>
name|PassManagers
expr_stmt|;
name|private
label|:
comment|/// Collection of pass managers that are not directly maintained
comment|/// by this pass manager
name|SmallVector
operator|<
name|PMDataManager
operator|*
operator|,
literal|8
operator|>
name|IndirectPassManagers
expr_stmt|;
comment|// Map to keep track of last user of the analysis pass.
comment|// LastUser->second is the last user of Lastuser->first.
name|DenseMap
operator|<
name|Pass
operator|*
operator|,
name|Pass
operator|*
operator|>
name|LastUser
expr_stmt|;
comment|// Map to keep track of passes that are last used by a pass.
comment|// This inverse map is initialized at PM->run() based on
comment|// LastUser map.
name|DenseMap
operator|<
name|Pass
operator|*
operator|,
name|SmallPtrSet
operator|<
name|Pass
operator|*
operator|,
literal|8
operator|>
expr|>
name|InversedLastUser
expr_stmt|;
comment|/// Immutable passes are managed by top level manager.
name|SmallVector
operator|<
name|ImmutablePass
operator|*
operator|,
literal|8
operator|>
name|ImmutablePasses
expr_stmt|;
name|DenseMap
operator|<
name|Pass
operator|*
operator|,
name|AnalysisUsage
operator|*
operator|>
name|AnUsageMap
expr_stmt|;
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// PMDataManager
comment|/// PMDataManager provides the common place to manage the analysis data
comment|/// used by pass managers.
name|class
name|PMDataManager
block|{
name|public
label|:
name|explicit
name|PMDataManager
argument_list|(
argument|int Depth
argument_list|)
block|:
name|TPM
argument_list|(
name|NULL
argument_list|)
operator|,
name|Depth
argument_list|(
argument|Depth
argument_list|)
block|{
name|initializeAnalysisInfo
argument_list|()
block|;   }
name|virtual
operator|~
name|PMDataManager
argument_list|()
expr_stmt|;
name|virtual
name|Pass
modifier|*
name|getAsPass
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// Augment AvailableAnalysis by adding analysis made available by pass P.
name|void
name|recordAvailableAnalysis
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|)
function_decl|;
comment|/// verifyPreservedAnalysis -- Verify analysis presreved by pass P.
name|void
name|verifyPreservedAnalysis
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|)
function_decl|;
comment|/// Remove Analysis that is not preserved by the pass
name|void
name|removeNotPreservedAnalysis
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|)
function_decl|;
comment|/// Remove dead passes used by P.
name|void
name|removeDeadPasses
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|,
name|StringRef
name|Msg
parameter_list|,
name|enum
name|PassDebuggingString
parameter_list|)
function_decl|;
comment|/// Remove P.
name|void
name|freePass
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|,
name|StringRef
name|Msg
parameter_list|,
name|enum
name|PassDebuggingString
parameter_list|)
function_decl|;
comment|/// Add pass P into the PassVector. Update
comment|/// AvailableAnalysis appropriately if ProcessAnalysis is true.
name|void
name|add
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|,
name|bool
name|ProcessAnalysis
init|=
name|true
parameter_list|)
function_decl|;
comment|/// Add RequiredPass into list of lower level passes required by pass P.
comment|/// RequiredPass is run on the fly by Pass Manager when P requests it
comment|/// through getAnalysis interface.
name|virtual
name|void
name|addLowerLevelRequiredPass
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|,
name|Pass
modifier|*
name|RequiredPass
parameter_list|)
function_decl|;
name|virtual
name|Pass
modifier|*
name|getOnTheFlyPass
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|,
specifier|const
name|PassInfo
modifier|*
name|PI
parameter_list|,
name|Function
modifier|&
name|F
parameter_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Unable to find on the fly pass"
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
comment|/// Initialize available analysis information.
name|void
name|initializeAnalysisInfo
parameter_list|()
block|{
name|AvailableAnalysis
operator|.
name|clear
argument_list|()
expr_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|PMT_Last
condition|;
operator|++
name|i
control|)
name|InheritedAnalysis
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
block|}
comment|// Return true if P preserves high level analysis used by other
comment|// passes that are managed by this manager.
name|bool
name|preserveHigherLevelAnalysis
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|)
function_decl|;
comment|/// Populate RequiredPasses with analysis pass that are required by
comment|/// pass P and are available. Populate ReqPassNotAvailable with analysis
comment|/// pass that are required by pass P but are not available.
name|void
name|collectRequiredAnalysis
argument_list|(
name|SmallVector
operator|<
name|Pass
operator|*
argument_list|,
literal|8
operator|>
operator|&
name|RequiredPasses
argument_list|,
name|SmallVector
operator|<
name|AnalysisID
argument_list|,
literal|8
operator|>
operator|&
name|ReqPassNotAvailable
argument_list|,
name|Pass
operator|*
name|P
argument_list|)
decl_stmt|;
comment|/// All Required analyses should be available to the pass as it runs!  Here
comment|/// we fill in the AnalysisImpls member of the pass so that it can
comment|/// successfully use the getAnalysis() method to retrieve the
comment|/// implementations it needs.
name|void
name|initializeAnalysisImpl
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|)
function_decl|;
comment|/// Find the pass that implements Analysis AID. If desired pass is not found
comment|/// then return NULL.
name|Pass
modifier|*
name|findAnalysisPass
parameter_list|(
name|AnalysisID
name|AID
parameter_list|,
name|bool
name|Direction
parameter_list|)
function_decl|;
comment|// Access toplevel manager
name|PMTopLevelManager
modifier|*
name|getTopLevelManager
parameter_list|()
block|{
return|return
name|TPM
return|;
block|}
name|void
name|setTopLevelManager
parameter_list|(
name|PMTopLevelManager
modifier|*
name|T
parameter_list|)
block|{
name|TPM
operator|=
name|T
expr_stmt|;
block|}
name|unsigned
name|getDepth
argument_list|()
specifier|const
block|{
return|return
name|Depth
return|;
block|}
comment|// Print routines used by debug-pass
name|void
name|dumpLastUses
argument_list|(
name|Pass
operator|*
name|P
argument_list|,
name|unsigned
name|Offset
argument_list|)
decl|const
decl_stmt|;
name|void
name|dumpPassArguments
argument_list|()
specifier|const
expr_stmt|;
name|void
name|dumpPassInfo
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|,
name|enum
name|PassDebuggingString
name|S1
parameter_list|,
name|enum
name|PassDebuggingString
name|S2
parameter_list|,
name|StringRef
name|Msg
parameter_list|)
function_decl|;
name|void
name|dumpRequiredSet
argument_list|(
specifier|const
name|Pass
operator|*
name|P
argument_list|)
decl|const
decl_stmt|;
name|void
name|dumpPreservedSet
argument_list|(
specifier|const
name|Pass
operator|*
name|P
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|unsigned
name|getNumContainedPasses
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|PassVector
operator|.
name|size
argument_list|()
return|;
block|}
name|virtual
name|PassManagerType
name|getPassManagerType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Invalid use of getPassManagerType"
argument_list|)
block|;
return|return
name|PMT_Unknown
return|;
block|}
name|std
operator|::
name|map
operator|<
name|AnalysisID
operator|,
name|Pass
operator|*
operator|>
operator|*
name|getAvailableAnalysis
argument_list|()
block|{
return|return
operator|&
name|AvailableAnalysis
return|;
block|}
comment|// Collect AvailableAnalysis from all the active Pass Managers.
name|void
name|populateInheritedAnalysis
parameter_list|(
name|PMStack
modifier|&
name|PMS
parameter_list|)
block|{
name|unsigned
name|Index
init|=
literal|0
decl_stmt|;
for|for
control|(
name|PMStack
operator|::
name|iterator
name|I
operator|=
name|PMS
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|PMS
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
name|InheritedAnalysis
index|[
name|Index
operator|++
index|]
operator|=
operator|(
operator|*
name|I
operator|)
operator|->
name|getAvailableAnalysis
argument_list|()
expr_stmt|;
block|}
name|protected
label|:
comment|// Top level manager.
name|PMTopLevelManager
modifier|*
name|TPM
decl_stmt|;
comment|// Collection of pass that are managed by this manager
name|SmallVector
operator|<
name|Pass
operator|*
operator|,
literal|16
operator|>
name|PassVector
expr_stmt|;
comment|// Collection of Analysis provided by Parent pass manager and
comment|// used by current pass manager. At at time there can not be more
comment|// then PMT_Last active pass mangers.
name|std
operator|::
name|map
operator|<
name|AnalysisID
operator|,
name|Pass
operator|*
operator|>
operator|*
name|InheritedAnalysis
index|[
name|PMT_Last
index|]
expr_stmt|;
comment|/// isPassDebuggingExecutionsOrMore - Return true if -debug-pass=Executions
comment|/// or higher is specified.
name|bool
name|isPassDebuggingExecutionsOrMore
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|void
name|dumpAnalysisUsage
argument_list|(
name|StringRef
name|Msg
argument_list|,
specifier|const
name|Pass
operator|*
name|P
argument_list|,
specifier|const
name|AnalysisUsage
operator|::
name|VectorType
operator|&
name|Set
argument_list|)
decl|const
decl_stmt|;
comment|// Set of available Analysis. This information is used while scheduling
comment|// pass. If a pass requires an analysis which is not not available then
comment|// equired analysis pass is scheduled to run before the pass itself is
comment|// scheduled to run.
name|std
operator|::
name|map
operator|<
name|AnalysisID
operator|,
name|Pass
operator|*
operator|>
name|AvailableAnalysis
expr_stmt|;
comment|// Collection of higher level analysis used by the pass managed by
comment|// this manager.
name|SmallVector
operator|<
name|Pass
operator|*
operator|,
literal|8
operator|>
name|HigherLevelAnalysis
expr_stmt|;
name|unsigned
name|Depth
decl_stmt|;
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// FPPassManager
comment|//
comment|/// FPPassManager manages BBPassManagers and FunctionPasses.
comment|/// It batches all function passes and basic block pass managers together and
comment|/// sequence them to process one function at a time before processing next
comment|/// function.
name|class
name|FPPassManager
range|:
name|public
name|ModulePass
decl_stmt|,
name|public
name|PMDataManager
block|{
name|public
label|:
specifier|static
name|char
name|ID
decl_stmt|;
name|explicit
name|FPPassManager
argument_list|(
argument|int Depth
argument_list|)
block|:
name|ModulePass
argument_list|(
operator|&
name|ID
argument_list|)
operator|,
name|PMDataManager
argument_list|(
argument|Depth
argument_list|)
block|{ }
comment|/// run - Execute all of the passes scheduled for execution.  Keep track of
comment|/// whether any of the passes modifies the module, and if so, return true.
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
name|F
argument_list|)
expr_stmt|;
name|bool
name|runOnModule
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
comment|/// cleanup - After running all passes, clean up pass manager cache.
name|void
name|cleanup
parameter_list|()
function_decl|;
comment|/// doInitialization - Run all of the initializers for the function passes.
comment|///
name|bool
name|doInitialization
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
comment|/// doFinalization - Run all of the finalizers for the function passes.
comment|///
name|bool
name|doFinalization
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
name|virtual
name|PMDataManager
modifier|*
name|getAsPMDataManager
parameter_list|()
block|{
return|return
name|this
return|;
block|}
name|virtual
name|Pass
modifier|*
name|getAsPass
parameter_list|()
block|{
return|return
name|this
return|;
block|}
comment|/// Pass Manager itself does not invalidate any analysis info.
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|Info
argument_list|)
decl|const
block|{
name|Info
operator|.
name|setPreservesAll
argument_list|()
expr_stmt|;
block|}
comment|// Print passes managed by this manager
name|void
name|dumpPassStructure
parameter_list|(
name|unsigned
name|Offset
parameter_list|)
function_decl|;
name|virtual
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
literal|"Function Pass Manager"
return|;
block|}
name|FunctionPass
modifier|*
name|getContainedPass
parameter_list|(
name|unsigned
name|N
parameter_list|)
block|{
name|assert
argument_list|(
name|N
operator|<
name|PassVector
operator|.
name|size
argument_list|()
operator|&&
literal|"Pass number out of range!"
argument_list|)
expr_stmt|;
name|FunctionPass
modifier|*
name|FP
init|=
name|static_cast
operator|<
name|FunctionPass
operator|*
operator|>
operator|(
name|PassVector
index|[
name|N
index|]
operator|)
decl_stmt|;
return|return
name|FP
return|;
block|}
name|virtual
name|PassManagerType
name|getPassManagerType
argument_list|()
specifier|const
block|{
return|return
name|PMT_FunctionPassManager
return|;
block|}
block|}
empty_stmt|;
specifier|extern
name|Timer
modifier|*
name|StartPassTimer
parameter_list|(
name|Pass
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|StopPassTimer
parameter_list|(
name|Pass
modifier|*
parameter_list|,
name|Timer
modifier|*
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

