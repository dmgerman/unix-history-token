begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- GlobalsModRef.h - Simple Mod/Ref AA for Globals ----------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// This is the interface for a simple mod/ref and alias analysis over globals.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ANALYSIS_GLOBALSMODREF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_GLOBALSMODREF_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/CallGraph.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Constants.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// An alias analysis result set for globals.
comment|///
comment|/// This focuses on handling aliasing properties of globals and interprocedural
comment|/// function call mod/ref information.
name|class
name|GlobalsAAResult
range|:
name|public
name|AAResultBase
operator|<
name|GlobalsAAResult
operator|>
block|{
name|friend
name|AAResultBase
operator|<
name|GlobalsAAResult
operator|>
block|;
name|class
name|FunctionInfo
block|;
specifier|const
name|DataLayout
operator|&
name|DL
block|;
comment|/// The globals that do not have their addresses taken.
name|SmallPtrSet
operator|<
specifier|const
name|GlobalValue
operator|*
block|,
literal|8
operator|>
name|NonAddressTakenGlobals
block|;
comment|/// IndirectGlobals - The memory pointed to by this global is known to be
comment|/// 'owned' by the global.
name|SmallPtrSet
operator|<
specifier|const
name|GlobalValue
operator|*
block|,
literal|8
operator|>
name|IndirectGlobals
block|;
comment|/// AllocsForIndirectGlobals - If an instruction allocates memory for an
comment|/// indirect global, this map indicates which one.
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
block|,
specifier|const
name|GlobalValue
operator|*
operator|>
name|AllocsForIndirectGlobals
block|;
comment|/// For each function, keep track of what globals are modified or read.
name|DenseMap
operator|<
specifier|const
name|Function
operator|*
block|,
name|FunctionInfo
operator|>
name|FunctionInfos
block|;
comment|/// A map of functions to SCC. The SCCs are described by a simple integer
comment|/// ID that is only useful for comparing for equality (are two functions
comment|/// in the same SCC or not?)
name|DenseMap
operator|<
specifier|const
name|Function
operator|*
block|,
name|unsigned
operator|>
name|FunctionToSCCMap
block|;
comment|/// Handle to clear this analysis on deletion of values.
block|struct
name|DeletionCallbackHandle
name|final
operator|:
name|CallbackVH
block|{
name|GlobalsAAResult
operator|*
name|GAR
block|;
name|std
operator|::
name|list
operator|<
name|DeletionCallbackHandle
operator|>
operator|::
name|iterator
name|I
block|;
name|DeletionCallbackHandle
argument_list|(
name|GlobalsAAResult
operator|&
name|GAR
argument_list|,
name|Value
operator|*
name|V
argument_list|)
operator|:
name|CallbackVH
argument_list|(
name|V
argument_list|)
block|,
name|GAR
argument_list|(
argument|&GAR
argument_list|)
block|{}
name|void
name|deleted
argument_list|()
name|override
block|;   }
block|;
comment|/// List of callbacks for globals being tracked by this analysis. Note that
comment|/// these objects are quite large, but we only anticipate having one per
comment|/// global tracked by this analysis. There are numerous optimizations we
comment|/// could perform to the memory utilization here if this becomes a problem.
name|std
operator|::
name|list
operator|<
name|DeletionCallbackHandle
operator|>
name|Handles
block|;
name|explicit
name|GlobalsAAResult
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|&
name|TLI
argument_list|)
block|;
name|public
operator|:
name|GlobalsAAResult
argument_list|(
name|GlobalsAAResult
operator|&&
name|Arg
argument_list|)
block|;
specifier|static
name|GlobalsAAResult
name|analyzeModule
argument_list|(
name|Module
operator|&
name|M
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|&
name|TLI
argument_list|,
name|CallGraph
operator|&
name|CG
argument_list|)
block|;
comment|//------------------------------------------------
comment|// Implement the AliasAnalysis API
comment|//
name|AliasResult
name|alias
argument_list|(
specifier|const
name|MemoryLocation
operator|&
name|LocA
argument_list|,
specifier|const
name|MemoryLocation
operator|&
name|LocB
argument_list|)
block|;
name|using
name|AAResultBase
operator|::
name|getModRefInfo
block|;
name|ModRefInfo
name|getModRefInfo
argument_list|(
argument|ImmutableCallSite CS
argument_list|,
argument|const MemoryLocation&Loc
argument_list|)
block|;
comment|/// getModRefBehavior - Return the behavior of the specified function if
comment|/// called from the specified call site.  The call site may be null in which
comment|/// case the most generic behavior of this function should be returned.
name|FunctionModRefBehavior
name|getModRefBehavior
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|)
block|;
comment|/// getModRefBehavior - Return the behavior of the specified function if
comment|/// called from the specified call site.  The call site may be null in which
comment|/// case the most generic behavior of this function should be returned.
name|FunctionModRefBehavior
name|getModRefBehavior
argument_list|(
argument|ImmutableCallSite CS
argument_list|)
block|;
name|private
operator|:
name|FunctionInfo
operator|*
name|getFunctionInfo
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|)
block|;
name|void
name|AnalyzeGlobals
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|void
name|AnalyzeCallGraph
argument_list|(
name|CallGraph
operator|&
name|CG
argument_list|,
name|Module
operator|&
name|M
argument_list|)
block|;
name|bool
name|AnalyzeUsesOfPointer
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|SmallPtrSetImpl
operator|<
name|Function
operator|*
operator|>
operator|*
name|Readers
operator|=
name|nullptr
argument_list|,
name|SmallPtrSetImpl
operator|<
name|Function
operator|*
operator|>
operator|*
name|Writers
operator|=
name|nullptr
argument_list|,
name|GlobalValue
operator|*
name|OkayStoreDest
operator|=
name|nullptr
argument_list|)
block|;
name|bool
name|AnalyzeIndirectGlobalMemory
argument_list|(
name|GlobalVariable
operator|*
name|GV
argument_list|)
block|;
name|void
name|CollectSCCMembership
argument_list|(
name|CallGraph
operator|&
name|CG
argument_list|)
block|;
name|bool
name|isNonEscapingGlobalNoAlias
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
specifier|const
name|Value
operator|*
name|V
argument_list|)
block|;
name|ModRefInfo
name|getModRefInfoForArgument
argument_list|(
argument|ImmutableCallSite CS
argument_list|,
argument|const GlobalValue *GV
argument_list|)
block|; }
decl_stmt|;
comment|/// Analysis pass providing a never-invalidated alias analysis result.
name|class
name|GlobalsAA
block|{
name|public
label|:
typedef|typedef
name|GlobalsAAResult
name|Result
typedef|;
comment|/// \brief Opaque, unique identifier for this analysis pass.
specifier|static
name|void
modifier|*
name|ID
parameter_list|()
block|{
return|return
operator|(
name|void
operator|*
operator|)
operator|&
name|PassID
return|;
block|}
name|GlobalsAAResult
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|AnalysisManager
operator|<
name|Module
operator|>
operator|*
name|AM
argument_list|)
decl_stmt|;
comment|/// \brief Provide access to a name for this pass for debugging purposes.
specifier|static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"GlobalsAA"
return|;
block|}
name|private
label|:
specifier|static
name|char
name|PassID
decl_stmt|;
block|}
empty_stmt|;
comment|/// Legacy wrapper pass to provide the GlobalsAAResult object.
name|class
name|GlobalsAAWrapperPass
range|:
name|public
name|ModulePass
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|GlobalsAAResult
operator|>
name|Result
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|GlobalsAAWrapperPass
argument_list|()
block|;
name|GlobalsAAResult
operator|&
name|getResult
argument_list|()
block|{
return|return
operator|*
name|Result
return|;
block|}
specifier|const
name|GlobalsAAResult
operator|&
name|getResult
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Result
return|;
block|}
name|bool
name|runOnModule
argument_list|(
argument|Module&M
argument_list|)
name|override
block|;
name|bool
name|doFinalization
argument_list|(
argument|Module&M
argument_list|)
name|override
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// createGlobalsAAWrapperPass - This pass provides alias and mod/ref info for
comment|// global values that do not have their addresses taken.
comment|//
name|ModulePass
modifier|*
name|createGlobalsAAWrapperPass
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

