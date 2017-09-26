begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/PassInfo.h - Pass Info class ------------------------*- C++ -*-===//
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
comment|// This file defines and implements the PassInfo class.
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
name|LLVM_PASSINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PASSINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Pass
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
comment|//===---------------------------------------------------------------------------
comment|/// PassInfo class - An instance of this class exists for every pass known by
comment|/// the system, and can be obtained from a live Pass by calling its
comment|/// getPassInfo() method.  These objects are set up by the RegisterPass<>
comment|/// template.
comment|///
name|class
name|PassInfo
block|{
name|public
label|:
typedef|typedef
name|Pass
modifier|*
function_decl|(
modifier|*
name|NormalCtor_t
function_decl|)
parameter_list|()
function_decl|;
name|private
label|:
name|StringRef
name|PassName
decl_stmt|;
comment|// Nice name for Pass
name|StringRef
name|PassArgument
decl_stmt|;
comment|// Command Line argument to run this pass
specifier|const
name|void
modifier|*
name|PassID
decl_stmt|;
specifier|const
name|bool
name|IsCFGOnlyPass
decl_stmt|;
comment|// Pass only looks at the CFG.
specifier|const
name|bool
name|IsAnalysis
decl_stmt|;
comment|// True if an analysis pass.
specifier|const
name|bool
name|IsAnalysisGroup
decl_stmt|;
comment|// True if an analysis group.
name|std
operator|::
name|vector
operator|<
specifier|const
name|PassInfo
operator|*
operator|>
name|ItfImpl
expr_stmt|;
comment|// Interfaces implemented by this pass
name|NormalCtor_t
name|NormalCtor
decl_stmt|;
name|public
label|:
comment|/// PassInfo ctor - Do not call this directly, this should only be invoked
comment|/// through RegisterPass.
name|PassInfo
argument_list|(
argument|StringRef name
argument_list|,
argument|StringRef arg
argument_list|,
argument|const void *pi
argument_list|,
argument|NormalCtor_t normal
argument_list|,
argument|bool isCFGOnly
argument_list|,
argument|bool is_analysis
argument_list|)
block|:
name|PassName
argument_list|(
name|name
argument_list|)
operator|,
name|PassArgument
argument_list|(
name|arg
argument_list|)
operator|,
name|PassID
argument_list|(
name|pi
argument_list|)
operator|,
name|IsCFGOnlyPass
argument_list|(
name|isCFGOnly
argument_list|)
operator|,
name|IsAnalysis
argument_list|(
name|is_analysis
argument_list|)
operator|,
name|IsAnalysisGroup
argument_list|(
name|false
argument_list|)
operator|,
name|NormalCtor
argument_list|(
argument|normal
argument_list|)
block|{}
comment|/// PassInfo ctor - Do not call this directly, this should only be invoked
comment|/// through RegisterPass. This version is for use by analysis groups; it
comment|/// does not auto-register the pass.
name|PassInfo
argument_list|(
argument|StringRef name
argument_list|,
argument|const void *pi
argument_list|)
operator|:
name|PassName
argument_list|(
name|name
argument_list|)
operator|,
name|PassArgument
argument_list|(
literal|""
argument_list|)
operator|,
name|PassID
argument_list|(
name|pi
argument_list|)
operator|,
name|IsCFGOnlyPass
argument_list|(
name|false
argument_list|)
operator|,
name|IsAnalysis
argument_list|(
name|false
argument_list|)
operator|,
name|IsAnalysisGroup
argument_list|(
name|true
argument_list|)
operator|,
name|NormalCtor
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// getPassName - Return the friendly name for the pass, never returns null
comment|///
name|StringRef
name|getPassName
argument_list|()
specifier|const
block|{
return|return
name|PassName
return|;
block|}
comment|/// getPassArgument - Return the command line option that may be passed to
comment|/// 'opt' that will cause this pass to be run.  This will return null if there
comment|/// is no argument.
comment|///
name|StringRef
name|getPassArgument
argument_list|()
specifier|const
block|{
return|return
name|PassArgument
return|;
block|}
comment|/// getTypeInfo - Return the id object for the pass...
comment|/// TODO : Rename
specifier|const
name|void
operator|*
name|getTypeInfo
argument_list|()
specifier|const
block|{
return|return
name|PassID
return|;
block|}
comment|/// Return true if this PassID implements the specified ID pointer.
name|bool
name|isPassID
argument_list|(
specifier|const
name|void
operator|*
name|IDPtr
argument_list|)
decl|const
block|{
return|return
name|PassID
operator|==
name|IDPtr
return|;
block|}
comment|/// isAnalysisGroup - Return true if this is an analysis group, not a normal
comment|/// pass.
comment|///
name|bool
name|isAnalysisGroup
argument_list|()
specifier|const
block|{
return|return
name|IsAnalysisGroup
return|;
block|}
name|bool
name|isAnalysis
argument_list|()
specifier|const
block|{
return|return
name|IsAnalysis
return|;
block|}
comment|/// isCFGOnlyPass - return true if this pass only looks at the CFG for the
comment|/// function.
name|bool
name|isCFGOnlyPass
argument_list|()
specifier|const
block|{
return|return
name|IsCFGOnlyPass
return|;
block|}
comment|/// getNormalCtor - Return a pointer to a function, that when called, creates
comment|/// an instance of the pass and returns it.  This pointer may be null if there
comment|/// is no default constructor for the pass.
comment|///
name|NormalCtor_t
name|getNormalCtor
argument_list|()
specifier|const
block|{
return|return
name|NormalCtor
return|;
block|}
name|void
name|setNormalCtor
parameter_list|(
name|NormalCtor_t
name|Ctor
parameter_list|)
block|{
name|NormalCtor
operator|=
name|Ctor
expr_stmt|;
block|}
comment|/// createPass() - Use this method to create an instance of this pass.
name|Pass
operator|*
name|createPass
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
operator|!
name|isAnalysisGroup
argument_list|()
operator|||
name|NormalCtor
operator|)
operator|&&
literal|"No default implementation found for analysis group!"
argument_list|)
block|;
name|assert
argument_list|(
name|NormalCtor
operator|&&
literal|"Cannot call createPass on PassInfo without default ctor!"
argument_list|)
block|;
return|return
name|NormalCtor
argument_list|()
return|;
block|}
comment|/// addInterfaceImplemented - This method is called when this pass is
comment|/// registered as a member of an analysis group with the RegisterAnalysisGroup
comment|/// template.
comment|///
name|void
name|addInterfaceImplemented
parameter_list|(
specifier|const
name|PassInfo
modifier|*
name|ItfPI
parameter_list|)
block|{
name|ItfImpl
operator|.
name|push_back
argument_list|(
name|ItfPI
argument_list|)
expr_stmt|;
block|}
comment|/// getInterfacesImplemented - Return a list of all of the analysis group
comment|/// interfaces implemented by this pass.
comment|///
specifier|const
name|std
operator|::
name|vector
operator|<
specifier|const
name|PassInfo
operator|*
operator|>
operator|&
name|getInterfacesImplemented
argument_list|()
specifier|const
block|{
return|return
name|ItfImpl
return|;
block|}
name|private
label|:
name|void
name|operator
init|=
operator|(
specifier|const
name|PassInfo
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|PassInfo
argument_list|(
specifier|const
name|PassInfo
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

