begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LibCallAliasAnalysis.h - Implement AliasAnalysis for libcalls ------===//
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
comment|// This file defines the LibCallAliasAnalysis class.
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
name|LLVM_ANALYSIS_LIBCALLALIASANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LIBCALLALIASANALYSIS_H
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
name|class
name|LibCallInfo
decl_stmt|;
struct_decl|struct
name|LibCallFunctionInfo
struct_decl|;
comment|/// LibCallAliasAnalysis - Alias analysis driven from LibCallInfo.
name|struct
name|LibCallAliasAnalysis
range|:
name|public
name|FunctionPass
decl_stmt|,
name|public
name|AliasAnalysis
block|{
specifier|static
name|char
name|ID
decl_stmt|;
comment|// Class identification
name|LibCallInfo
modifier|*
name|LCI
decl_stmt|;
name|explicit
name|LibCallAliasAnalysis
argument_list|(
name|LibCallInfo
operator|*
name|LC
operator|=
name|nullptr
argument_list|)
operator|:
name|FunctionPass
argument_list|(
name|ID
argument_list|)
operator|,
name|LCI
argument_list|(
argument|LC
argument_list|)
block|{
name|initializeLibCallAliasAnalysisPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;     }
name|explicit
name|LibCallAliasAnalysis
argument_list|(
name|char
operator|&
name|ID
argument_list|,
name|LibCallInfo
operator|*
name|LC
argument_list|)
operator|:
name|FunctionPass
argument_list|(
name|ID
argument_list|)
operator|,
name|LCI
argument_list|(
argument|LC
argument_list|)
block|{
name|initializeLibCallAliasAnalysisPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;     }
operator|~
name|LibCallAliasAnalysis
argument_list|()
expr_stmt|;
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
parameter_list|(
name|ImmutableCallSite
name|CS1
parameter_list|,
name|ImmutableCallSite
name|CS2
parameter_list|)
function|override
block|{
comment|// TODO: Could compare two direct calls against each other if we cared to.
return|return
name|AliasAnalysis
operator|::
name|getModRefInfo
argument_list|(
name|CS1
argument_list|,
name|CS2
argument_list|)
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
name|bool
name|runOnFunction
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function|override
block|{
name|InitializeAliasAnalysis
argument_list|(
name|this
argument_list|)
expr_stmt|;
comment|// set up super class
return|return
name|false
return|;
block|}
comment|/// getAdjustedAnalysisPointer - This method is used when a pass implements
comment|/// an analysis interface through multiple inheritance.  If needed, it
comment|/// should override this to adjust the this pointer as needed for the
comment|/// specified pass info.
name|void
modifier|*
name|getAdjustedAnalysisPointer
parameter_list|(
specifier|const
name|void
modifier|*
name|PI
parameter_list|)
function|override
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
operator|(
name|AliasAnalysis
operator|*
operator|)
name|this
return|;
return|return
name|this
return|;
block|}
name|private
label|:
name|ModRefResult
name|AnalyzeLibCallDetails
parameter_list|(
specifier|const
name|LibCallFunctionInfo
modifier|*
name|FI
parameter_list|,
name|ImmutableCallSite
name|CS
parameter_list|,
specifier|const
name|Location
modifier|&
name|Loc
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End of llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

