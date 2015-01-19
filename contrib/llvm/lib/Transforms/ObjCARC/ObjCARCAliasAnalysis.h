begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ObjCARCAliasAnalysis.h - ObjC ARC Optimization -*- C++ -*-----------===//
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
name|LLVM_TRANSFORMS_OBJCARC_OBJCARCALIASANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_OBJCARC_OBJCARCALIASANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
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
name|ObjCARCAliasAnalysis
range|:
name|public
name|ImmutablePass
decl_stmt|,
name|public
name|AliasAnalysis
block|{
name|public
label|:
specifier|static
name|char
name|ID
decl_stmt|;
comment|// Class identification, replacement for typeinfo
name|ObjCARCAliasAnalysis
argument_list|()
operator|:
name|ImmutablePass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeObjCARCAliasAnalysisPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;     }
name|private
operator|:
name|void
name|initializePass
argument_list|()
name|override
block|{
name|InitializeAliasAnalysis
argument_list|(
name|this
argument_list|)
block|;     }
comment|/// This method is used when a pass implements an analysis interface through
comment|/// multiple inheritance.  If needed, it should override this to adjust the
comment|/// this pointer as needed for the specified pass info.
name|void
operator|*
name|getAdjustedAnalysisPointer
argument_list|(
argument|const void *PI
argument_list|)
name|override
block|{
if|if
condition|(
name|PI
operator|==
operator|&
name|AliasAnalysis
operator|::
name|ID
condition|)
return|return
name|static_cast
operator|<
name|AliasAnalysis
operator|*
operator|>
operator|(
name|this
operator|)
return|;
return|return
name|this
return|;
block|}
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
name|override
decl_stmt|;
name|AliasResult
name|alias
argument_list|(
specifier|const
name|Location
operator|&
name|LocA
argument_list|,
specifier|const
name|Location
operator|&
name|LocB
argument_list|)
name|override
decl_stmt|;
name|bool
name|pointsToConstantMemory
argument_list|(
specifier|const
name|Location
operator|&
name|Loc
argument_list|,
name|bool
name|OrLocal
argument_list|)
name|override
decl_stmt|;
name|ModRefBehavior
name|getModRefBehavior
argument_list|(
name|ImmutableCallSite
name|CS
argument_list|)
name|override
decl_stmt|;
name|ModRefBehavior
name|getModRefBehavior
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|)
name|override
decl_stmt|;
name|ModRefResult
name|getModRefInfo
argument_list|(
name|ImmutableCallSite
name|CS
argument_list|,
specifier|const
name|Location
operator|&
name|Loc
argument_list|)
name|override
decl_stmt|;
name|ModRefResult
name|getModRefInfo
argument_list|(
name|ImmutableCallSite
name|CS1
argument_list|,
name|ImmutableCallSite
name|CS2
argument_list|)
name|override
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace objcarc
end_comment

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_OBJCARC_OBJCARCALIASANALYSIS_H
end_comment

end_unit

