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
name|LLVM_ANALYSIS_LIBCALL_AA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LIBCALL_AA_H
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
literal|0
argument_list|)
operator|:
name|FunctionPass
argument_list|(
operator|&
name|ID
argument_list|)
operator|,
name|LCI
argument_list|(
argument|LC
argument_list|)
block|{     }
name|explicit
name|LibCallAliasAnalysis
argument_list|(
specifier|const
name|void
operator|*
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
block|{     }
operator|~
name|LibCallAliasAnalysis
argument_list|()
expr_stmt|;
name|ModRefResult
name|getModRefInfo
parameter_list|(
name|CallSite
name|CS
parameter_list|,
name|Value
modifier|*
name|P
parameter_list|,
name|unsigned
name|Size
parameter_list|)
function_decl|;
name|ModRefResult
name|getModRefInfo
parameter_list|(
name|CallSite
name|CS1
parameter_list|,
name|CallSite
name|CS2
parameter_list|)
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
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|runOnFunction
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
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
comment|/// hasNoModRefInfoForCalls - We can provide mod/ref information against
comment|/// non-escaping allocations.
name|virtual
name|bool
name|hasNoModRefInfoForCalls
argument_list|()
specifier|const
block|{
return|return
name|false
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
name|CallSite
name|CS
parameter_list|,
name|Value
modifier|*
name|P
parameter_list|,
name|unsigned
name|Size
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

