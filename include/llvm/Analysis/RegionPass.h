begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RegionPass.h - RegionPass class ------------------------------------===//
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
comment|// This file defines the RegionPass class. All region based analysis,
end_comment

begin_comment
comment|// optimization and transformation passes are derived from RegionPass.
end_comment

begin_comment
comment|// This class is implemented following the some ideas of the LoopPass.h class.
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
name|LLVM_ANALYSIS_REGIONPASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_REGIONPASS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/RegionInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/LegacyPassManagers.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|<deque>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|RGPassManager
decl_stmt|;
name|class
name|Function
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// @brief A pass that runs on each Region in a function.
comment|///
comment|/// RegionPass is managed by RGPassManager.
name|class
name|RegionPass
range|:
name|public
name|Pass
block|{
name|public
operator|:
name|explicit
name|RegionPass
argument_list|(
name|char
operator|&
name|pid
argument_list|)
operator|:
name|Pass
argument_list|(
argument|PT_Region
argument_list|,
argument|pid
argument_list|)
block|{}
comment|//===--------------------------------------------------------------------===//
comment|/// @name To be implemented by every RegionPass
comment|///
comment|//@{
comment|/// @brief Run the pass on a specific Region
comment|///
comment|/// Accessing regions not contained in the current region is not allowed.
comment|///
comment|/// @param R The region this pass is run on.
comment|/// @param RGM The RegionPassManager that manages this Pass.
comment|///
comment|/// @return True if the pass modifies this Region.
name|virtual
name|bool
name|runOnRegion
argument_list|(
name|Region
operator|*
name|R
argument_list|,
name|RGPassManager
operator|&
name|RGM
argument_list|)
operator|=
literal|0
block|;
comment|/// @brief Get a pass to print the LLVM IR in the region.
comment|///
comment|/// @param O      The output stream to print the Region.
comment|/// @param Banner The banner to separate different printed passes.
comment|///
comment|/// @return The pass to print the LLVM IR in the region.
name|Pass
operator|*
name|createPrinterPass
argument_list|(
argument|raw_ostream&O
argument_list|,
argument|const std::string&Banner
argument_list|)
specifier|const
block|;
name|using
name|llvm
operator|::
name|Pass
operator|::
name|doInitialization
block|;
name|using
name|llvm
operator|::
name|Pass
operator|::
name|doFinalization
block|;
name|virtual
name|bool
name|doInitialization
argument_list|(
argument|Region *R
argument_list|,
argument|RGPassManager&RGM
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|doFinalization
argument_list|()
block|{
return|return
name|false
return|;
block|}
comment|//@}
comment|//===--------------------------------------------------------------------===//
comment|/// @name PassManager API
comment|///
comment|//@{
name|void
name|preparePassManager
argument_list|(
name|PMStack
operator|&
name|PMS
argument_list|)
block|;
name|virtual
name|void
name|assignPassManager
argument_list|(
argument|PMStack&PMS
argument_list|,
argument|PassManagerType PMT = PMT_RegionPassManager
argument_list|)
block|;
name|virtual
name|PassManagerType
name|getPotentialPassManagerType
argument_list|()
specifier|const
block|{
return|return
name|PMT_RegionPassManager
return|;
block|}
comment|//@}
expr|}
block|;
comment|/// @brief The pass manager to schedule RegionPasses.
name|class
name|RGPassManager
operator|:
name|public
name|FunctionPass
block|,
name|public
name|PMDataManager
block|{
name|std
operator|::
name|deque
operator|<
name|Region
operator|*
operator|>
name|RQ
block|;
name|bool
name|skipThisRegion
block|;
name|bool
name|redoThisRegion
block|;
name|RegionInfo
operator|*
name|RI
block|;
name|Region
operator|*
name|CurrentRegion
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|explicit
name|RGPassManager
argument_list|()
block|;
comment|/// @brief Execute all of the passes scheduled for execution.
comment|///
comment|/// @return True if any of the passes modifies the function.
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
name|F
argument_list|)
block|;
comment|/// Pass Manager itself does not invalidate any analysis info.
comment|/// RGPassManager needs RegionInfo.
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&Info
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
literal|"Region Pass Manager"
return|;
block|}
name|virtual
name|PMDataManager
operator|*
name|getAsPMDataManager
argument_list|()
block|{
return|return
name|this
return|;
block|}
name|virtual
name|Pass
operator|*
name|getAsPass
argument_list|()
block|{
return|return
name|this
return|;
block|}
comment|/// @brief Print passes managed by this manager.
name|void
name|dumpPassStructure
argument_list|(
argument|unsigned Offset
argument_list|)
block|;
comment|/// @brief Get passes contained by this manager.
name|Pass
operator|*
name|getContainedPass
argument_list|(
argument|unsigned N
argument_list|)
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
block|;
name|Pass
operator|*
name|FP
operator|=
name|static_cast
operator|<
name|Pass
operator|*
operator|>
operator|(
name|PassVector
index|[
name|N
index|]
operator|)
block|;
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
name|PMT_RegionPassManager
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

