begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/PassAnalysisSupport.h - Analysis Pass Support code --*- C++ -*-===//
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
comment|// This file defines stuff that is used to define and "use" Analysis Passes.
end_comment

begin_comment
comment|// This file is automatically #included by Pass.h, so:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//           NO .CPP FILES SHOULD INCLUDE THIS FILE DIRECTLY
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Instead, #include Pass.h
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
name|LLVM_PASS_ANALYSIS_SUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PASS_ANALYSIS_SUPPORT_H
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
comment|// No need to include Pass.h, we are being included by it!
comment|//===----------------------------------------------------------------------===//
comment|// AnalysisUsage - Represent the analysis usage information of a pass.  This
comment|// tracks analyses that the pass REQUIRES (must be available when the pass
comment|// runs), REQUIRES TRANSITIVE (must be available throughout the lifetime of the
comment|// pass), and analyses that the pass PRESERVES (the pass does not invalidate the
comment|// results of these analyses).  This information is provided by a pass to the
comment|// Pass infrastructure through the getAnalysisUsage virtual function.
comment|//
name|class
name|AnalysisUsage
block|{
name|public
label|:
typedef|typedef
name|SmallVector
operator|<
name|AnalysisID
operator|,
literal|32
operator|>
name|VectorType
expr_stmt|;
name|private
label|:
comment|// Sets of analyses required and preserved by a pass
name|VectorType
name|Required
decl_stmt|,
name|RequiredTransitive
decl_stmt|,
name|Preserved
decl_stmt|;
name|bool
name|PreservesAll
decl_stmt|;
name|public
label|:
name|AnalysisUsage
argument_list|()
operator|:
name|PreservesAll
argument_list|(
argument|false
argument_list|)
block|{}
comment|// addRequired - Add the specified ID to the required set of the usage info
comment|// for a pass.
comment|//
name|AnalysisUsage
operator|&
name|addRequiredID
argument_list|(
argument|AnalysisID ID
argument_list|)
block|{
name|assert
argument_list|(
name|ID
operator|&&
literal|"Pass class not registered!"
argument_list|)
block|;
name|Required
operator|.
name|push_back
argument_list|(
name|ID
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|template
operator|<
name|class
name|PassClass
operator|>
name|AnalysisUsage
operator|&
name|addRequired
argument_list|()
block|{
return|return
name|addRequiredID
argument_list|(
name|Pass
operator|::
name|getClassPassInfo
operator|<
name|PassClass
operator|>
operator|(
operator|)
argument_list|)
return|;
block|}
name|AnalysisUsage
modifier|&
name|addRequiredTransitiveID
parameter_list|(
name|AnalysisID
name|ID
parameter_list|)
block|{
name|assert
argument_list|(
name|ID
operator|&&
literal|"Pass class not registered!"
argument_list|)
expr_stmt|;
name|Required
operator|.
name|push_back
argument_list|(
name|ID
argument_list|)
expr_stmt|;
name|RequiredTransitive
operator|.
name|push_back
argument_list|(
name|ID
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|template
operator|<
name|class
name|PassClass
operator|>
name|AnalysisUsage
operator|&
name|addRequiredTransitive
argument_list|()
block|{
name|AnalysisID
name|ID
operator|=
name|Pass
operator|::
name|getClassPassInfo
operator|<
name|PassClass
operator|>
operator|(
operator|)
block|;
return|return
name|addRequiredTransitiveID
argument_list|(
name|ID
argument_list|)
return|;
block|}
comment|// addPreserved - Add the specified ID to the set of analyses preserved by
comment|// this pass
comment|//
name|AnalysisUsage
modifier|&
name|addPreservedID
parameter_list|(
name|AnalysisID
name|ID
parameter_list|)
block|{
name|Preserved
operator|.
name|push_back
argument_list|(
name|ID
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|// addPreserved - Add the specified Pass class to the set of analyses
comment|// preserved by this pass.
comment|//
name|template
operator|<
name|class
name|PassClass
operator|>
name|AnalysisUsage
operator|&
name|addPreserved
argument_list|()
block|{
name|assert
argument_list|(
name|Pass
operator|::
name|getClassPassInfo
operator|<
name|PassClass
operator|>
operator|(
operator|)
operator|&&
literal|"Pass class not registered!"
argument_list|)
block|;
name|Preserved
operator|.
name|push_back
argument_list|(
name|Pass
operator|::
name|getClassPassInfo
operator|<
name|PassClass
operator|>
operator|(
operator|)
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|// addPreserved - Add the Pass with the specified argument string to the set
comment|// of analyses preserved by this pass. If no such Pass exists, do nothing.
comment|// This can be useful when a pass is trivially preserved, but may not be
comment|// linked in. Be careful about spelling!
comment|//
name|AnalysisUsage
modifier|&
name|addPreserved
parameter_list|(
specifier|const
name|StringRef
modifier|&
name|Arg
parameter_list|)
block|{
specifier|const
name|PassInfo
modifier|*
name|PI
init|=
name|Pass
operator|::
name|lookupPassInfo
argument_list|(
name|Arg
argument_list|)
decl_stmt|;
comment|// If the pass exists, preserve it. Otherwise silently do nothing.
if|if
condition|(
name|PI
condition|)
name|Preserved
operator|.
name|push_back
argument_list|(
name|PI
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|// setPreservesAll - Set by analyses that do not transform their input at all
name|void
name|setPreservesAll
parameter_list|()
block|{
name|PreservesAll
operator|=
name|true
expr_stmt|;
block|}
name|bool
name|getPreservesAll
argument_list|()
specifier|const
block|{
return|return
name|PreservesAll
return|;
block|}
comment|/// setPreservesCFG - This function should be called by the pass, iff they do
comment|/// not:
comment|///
comment|///  1. Add or remove basic blocks from the function
comment|///  2. Modify terminator instructions in any way.
comment|///
comment|/// This function annotates the AnalysisUsage info object to say that analyses
comment|/// that only depend on the CFG are preserved by this pass.
comment|///
name|void
name|setPreservesCFG
parameter_list|()
function_decl|;
specifier|const
name|VectorType
operator|&
name|getRequiredSet
argument_list|()
specifier|const
block|{
return|return
name|Required
return|;
block|}
specifier|const
name|VectorType
operator|&
name|getRequiredTransitiveSet
argument_list|()
specifier|const
block|{
return|return
name|RequiredTransitive
return|;
block|}
specifier|const
name|VectorType
operator|&
name|getPreservedSet
argument_list|()
specifier|const
block|{
return|return
name|Preserved
return|;
block|}
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// AnalysisResolver - Simple interface used by Pass objects to pull all
comment|// analysis information out of pass manager that is responsible to manage
comment|// the pass.
comment|//
name|class
name|PMDataManager
decl_stmt|;
name|class
name|AnalysisResolver
block|{
name|private
label|:
name|AnalysisResolver
argument_list|()
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
name|explicit
name|AnalysisResolver
argument_list|(
name|PMDataManager
operator|&
name|P
argument_list|)
operator|:
name|PM
argument_list|(
argument|P
argument_list|)
block|{ }
specifier|inline
name|PMDataManager
operator|&
name|getPMDataManager
argument_list|()
block|{
return|return
name|PM
return|;
block|}
comment|// Find pass that is implementing PI.
name|Pass
modifier|*
name|findImplPass
parameter_list|(
specifier|const
name|PassInfo
modifier|*
name|PI
parameter_list|)
block|{
name|Pass
modifier|*
name|ResultPass
init|=
literal|0
decl_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|AnalysisImpls
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|AnalysisImpls
index|[
name|i
index|]
operator|.
name|first
operator|==
name|PI
condition|)
block|{
name|ResultPass
operator|=
name|AnalysisImpls
index|[
name|i
index|]
operator|.
name|second
expr_stmt|;
break|break;
block|}
block|}
return|return
name|ResultPass
return|;
block|}
comment|// Find pass that is implementing PI. Initialize pass for Function F.
name|Pass
modifier|*
name|findImplPass
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
function_decl|;
name|void
name|addAnalysisImplsPair
parameter_list|(
specifier|const
name|PassInfo
modifier|*
name|PI
parameter_list|,
name|Pass
modifier|*
name|P
parameter_list|)
block|{
name|std
operator|::
name|pair
operator|<
specifier|const
name|PassInfo
operator|*
operator|,
name|Pass
operator|*
operator|>
name|pir
operator|=
name|std
operator|::
name|make_pair
argument_list|(
name|PI
argument_list|,
name|P
argument_list|)
expr_stmt|;
name|AnalysisImpls
operator|.
name|push_back
argument_list|(
name|pir
argument_list|)
expr_stmt|;
block|}
comment|/// clearAnalysisImpls - Clear cache that is used to connect a pass to the
comment|/// the analysis (PassInfo).
name|void
name|clearAnalysisImpls
parameter_list|()
block|{
name|AnalysisImpls
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|// getAnalysisIfAvailable - Return analysis result or null if it doesn't exist
name|Pass
modifier|*
name|getAnalysisIfAvailable
argument_list|(
name|AnalysisID
name|ID
argument_list|,
name|bool
name|Direction
argument_list|)
decl|const
decl_stmt|;
comment|// AnalysisImpls - This keeps track of which passes implements the interfaces
comment|// that are required by the current pass (to implement getAnalysis()).
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|PassInfo
operator|*
operator|,
name|Pass
operator|*
operator|>
expr|>
name|AnalysisImpls
expr_stmt|;
name|private
label|:
comment|// PassManager that is used to resolve analysis info
name|PMDataManager
modifier|&
name|PM
decl_stmt|;
block|}
empty_stmt|;
comment|/// getAnalysisIfAvailable<AnalysisType>() - Subclasses use this function to
comment|/// get analysis information that might be around, for example to update it.
comment|/// This is different than getAnalysis in that it can fail (if the analysis
comment|/// results haven't been computed), so should only be used if you can handle
comment|/// the case when the analysis is not available.  This method is often used by
comment|/// transformation APIs to update analysis results for a pass automatically as
comment|/// the transform is performed.
comment|///
name|template
operator|<
name|typename
name|AnalysisType
operator|>
name|AnalysisType
operator|*
name|Pass
operator|::
name|getAnalysisIfAvailable
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Resolver
operator|&&
literal|"Pass not resident in a PassManager object!"
argument_list|)
block|;
specifier|const
name|PassInfo
operator|*
name|PI
operator|=
name|getClassPassInfo
operator|<
name|AnalysisType
operator|>
operator|(
operator|)
block|;
if|if
condition|(
name|PI
operator|==
literal|0
condition|)
return|return
literal|0
return|;
return|return
name|dynamic_cast
operator|<
name|AnalysisType
operator|*
operator|>
operator|(
name|Resolver
operator|->
name|getAnalysisIfAvailable
argument_list|(
name|PI
argument_list|,
name|true
argument_list|)
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getAnalysis<AnalysisType>() - This function is used by subclasses to get
end_comment

begin_comment
comment|/// to the analysis information that they claim to use by overriding the
end_comment

begin_comment
comment|/// getAnalysisUsage function.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|AnalysisType
operator|>
name|AnalysisType
operator|&
name|Pass
operator|::
name|getAnalysis
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Resolver
operator|&&
literal|"Pass has not been inserted into a PassManager object!"
argument_list|)
block|;
return|return
name|getAnalysisID
operator|<
name|AnalysisType
operator|>
operator|(
name|getClassPassInfo
operator|<
name|AnalysisType
operator|>
operator|(
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|AnalysisType
operator|>
name|AnalysisType
operator|&
name|Pass
operator|::
name|getAnalysisID
argument_list|(
argument|const PassInfo *PI
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|PI
operator|&&
literal|"getAnalysis for unregistered pass!"
argument_list|)
block|;
name|assert
argument_list|(
name|Resolver
operator|&&
literal|"Pass has not been inserted into a PassManager object!"
argument_list|)
block|;
comment|// PI *must* appear in AnalysisImpls.  Because the number of passes used
comment|// should be a small number, we just do a linear search over a (dense)
comment|// vector.
name|Pass
operator|*
name|ResultPass
operator|=
name|Resolver
operator|->
name|findImplPass
argument_list|(
name|PI
argument_list|)
block|;
name|assert
argument_list|(
name|ResultPass
operator|&&
literal|"getAnalysis*() called on an analysis that was not "
literal|"'required' by pass!"
argument_list|)
block|;
comment|// Because the AnalysisType may not be a subclass of pass (for
comment|// AnalysisGroups), we must use dynamic_cast here to potentially adjust the
comment|// return pointer (because the class may multiply inherit, once from pass,
comment|// once from AnalysisType).
comment|//
name|AnalysisType
operator|*
name|Result
operator|=
name|dynamic_cast
operator|<
name|AnalysisType
operator|*
operator|>
operator|(
name|ResultPass
operator|)
block|;
name|assert
argument_list|(
name|Result
operator|&&
literal|"Pass does not implement interface required!"
argument_list|)
block|;
return|return
operator|*
name|Result
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getAnalysis<AnalysisType>() - This function is used by subclasses to get
end_comment

begin_comment
comment|/// to the analysis information that they claim to use by overriding the
end_comment

begin_comment
comment|/// getAnalysisUsage function.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|AnalysisType
operator|>
name|AnalysisType
operator|&
name|Pass
operator|::
name|getAnalysis
argument_list|(
argument|Function&F
argument_list|)
block|{
name|assert
argument_list|(
name|Resolver
operator|&&
literal|"Pass has not been inserted into a PassManager object!"
argument_list|)
block|;
return|return
name|getAnalysisID
operator|<
name|AnalysisType
operator|>
operator|(
name|getClassPassInfo
operator|<
name|AnalysisType
operator|>
operator|(
operator|)
operator|,
name|F
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|AnalysisType
operator|>
name|AnalysisType
operator|&
name|Pass
operator|::
name|getAnalysisID
argument_list|(
argument|const PassInfo *PI
argument_list|,
argument|Function&F
argument_list|)
block|{
name|assert
argument_list|(
name|PI
operator|&&
literal|"getAnalysis for unregistered pass!"
argument_list|)
block|;
name|assert
argument_list|(
name|Resolver
operator|&&
literal|"Pass has not been inserted into a PassManager object!"
argument_list|)
block|;
comment|// PI *must* appear in AnalysisImpls.  Because the number of passes used
comment|// should be a small number, we just do a linear search over a (dense)
comment|// vector.
name|Pass
operator|*
name|ResultPass
operator|=
name|Resolver
operator|->
name|findImplPass
argument_list|(
name|this
argument_list|,
name|PI
argument_list|,
name|F
argument_list|)
block|;
name|assert
argument_list|(
name|ResultPass
operator|&&
literal|"Unable to find requested analysis info"
argument_list|)
block|;
comment|// Because the AnalysisType may not be a subclass of pass (for
comment|// AnalysisGroups), we must use dynamic_cast here to potentially adjust the
comment|// return pointer (because the class may multiply inherit, once from pass,
comment|// once from AnalysisType).
comment|//
name|AnalysisType
operator|*
name|Result
operator|=
name|dynamic_cast
operator|<
name|AnalysisType
operator|*
operator|>
operator|(
name|ResultPass
operator|)
block|;
name|assert
argument_list|(
name|Result
operator|&&
literal|"Pass does not implement interface required!"
argument_list|)
block|;
return|return
operator|*
name|Result
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

