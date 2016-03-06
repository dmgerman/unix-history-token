begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ObjCARCAliasAnalysis.h - ObjC ARC Alias Analysis ---------*- C++ -*-===//
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
comment|/// This file declares a simple ARC-aware AliasAnalysis using special knowledge
end_comment

begin_comment
comment|/// of Objective C to enhance other optimization passes which rely on the Alias
end_comment

begin_comment
comment|/// Analysis infrastructure.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// WARNING: This file knows about certain library functions. It recognizes them
end_comment

begin_comment
comment|/// by name, and hardwires knowledge of their semantics.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// WARNING: This file knows about how certain Objective-C library functions are
end_comment

begin_comment
comment|/// used. Naive LLVM IR transformations which would otherwise be
end_comment

begin_comment
comment|/// behavior-preserving may break these assumptions.
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
name|LLVM_ANALYSIS_OBJCARCALIASANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_OBJCARCALIASANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/TargetLibraryInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|objcarc
block|{
comment|/// \brief This is a simple alias analysis implementation that uses knowledge
comment|/// of ARC constructs to answer queries.
comment|///
comment|/// TODO: This class could be generalized to know about other ObjC-specific
comment|/// tricks. Such as knowing that ivars in the non-fragile ABI are non-aliasing
comment|/// even though their offsets are dynamic.
name|class
name|ObjCARCAAResult
range|:
name|public
name|AAResultBase
operator|<
name|ObjCARCAAResult
operator|>
block|{
name|friend
name|AAResultBase
operator|<
name|ObjCARCAAResult
operator|>
block|;
specifier|const
name|DataLayout
operator|&
name|DL
block|;
name|public
operator|:
name|explicit
name|ObjCARCAAResult
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
operator|:
name|AAResultBase
argument_list|(
name|TLI
argument_list|)
block|,
name|DL
argument_list|(
argument|DL
argument_list|)
block|{}
name|ObjCARCAAResult
argument_list|(
name|ObjCARCAAResult
operator|&&
name|Arg
argument_list|)
operator|:
name|AAResultBase
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Arg
argument_list|)
argument_list|)
block|,
name|DL
argument_list|(
argument|Arg.DL
argument_list|)
block|{}
comment|/// Handle invalidation events from the new pass manager.
comment|///
comment|/// By definition, this result is stateless and so remains valid.
name|bool
name|invalidate
argument_list|(
argument|Function&
argument_list|,
argument|const PreservedAnalyses&
argument_list|)
block|{
return|return
name|false
return|;
block|}
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
name|bool
name|pointsToConstantMemory
argument_list|(
argument|const MemoryLocation&Loc
argument_list|,
argument|bool OrLocal
argument_list|)
block|;
name|using
name|AAResultBase
operator|::
name|getModRefBehavior
block|;
name|FunctionModRefBehavior
name|getModRefBehavior
argument_list|(
specifier|const
name|Function
operator|*
name|F
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
block|; }
decl_stmt|;
comment|/// Analysis pass providing a never-invalidated alias analysis result.
name|class
name|ObjCARCAA
block|{
name|public
label|:
typedef|typedef
name|ObjCARCAAResult
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
name|ObjCARCAAResult
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|AnalysisManager
operator|<
name|Function
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
literal|"ObjCARCAA"
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
comment|/// Legacy wrapper pass to provide the ObjCARCAAResult object.
name|class
name|ObjCARCAAWrapperPass
range|:
name|public
name|ImmutablePass
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|ObjCARCAAResult
operator|>
name|Result
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|ObjCARCAAWrapperPass
argument_list|()
block|;
name|ObjCARCAAResult
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
name|ObjCARCAAResult
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
name|doInitialization
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
block|}
comment|// namespace objcarc
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

