begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- EHPersonalities.h - Compute EH-related information -----------------===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ANALYSIS_EHPERSONALITIES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_EHPERSONALITIES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/TinyPtrVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|enum
name|class
name|EHPersonality
block|{
name|Unknown
operator|,
name|GNU_Ada
operator|,
name|GNU_C
operator|,
name|GNU_CXX
operator|,
name|GNU_ObjC
operator|,
name|MSVC_X86SEH
operator|,
name|MSVC_Win64SEH
operator|,
name|MSVC_CXX
operator|,
name|CoreCLR
block|}
empty_stmt|;
comment|/// \brief See if the given exception handling personality function is one
comment|/// that we understand.  If so, return a description of it; otherwise return
comment|/// Unknown.
name|EHPersonality
name|classifyEHPersonality
parameter_list|(
specifier|const
name|Value
modifier|*
name|Pers
parameter_list|)
function_decl|;
comment|/// \brief Returns true if this personality function catches asynchronous
comment|/// exceptions.
specifier|inline
name|bool
name|isAsynchronousEHPersonality
parameter_list|(
name|EHPersonality
name|Pers
parameter_list|)
block|{
comment|// The two SEH personality functions can catch asynch exceptions. We assume
comment|// unknown personalities don't catch asynch exceptions.
switch|switch
condition|(
name|Pers
condition|)
block|{
case|case
name|EHPersonality
operator|::
name|MSVC_X86SEH
case|:
case|case
name|EHPersonality
operator|::
name|MSVC_Win64SEH
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"invalid enum"
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Returns true if this is a personality function that invokes
comment|/// handler funclets (which must return to it).
specifier|inline
name|bool
name|isFuncletEHPersonality
parameter_list|(
name|EHPersonality
name|Pers
parameter_list|)
block|{
switch|switch
condition|(
name|Pers
condition|)
block|{
case|case
name|EHPersonality
operator|::
name|MSVC_CXX
case|:
case|case
name|EHPersonality
operator|::
name|MSVC_X86SEH
case|:
case|case
name|EHPersonality
operator|::
name|MSVC_Win64SEH
case|:
case|case
name|EHPersonality
operator|::
name|CoreCLR
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"invalid enum"
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Return true if this personality may be safely removed if there
comment|/// are no invoke instructions remaining in the current function.
specifier|inline
name|bool
name|isNoOpWithoutInvoke
parameter_list|(
name|EHPersonality
name|Pers
parameter_list|)
block|{
switch|switch
condition|(
name|Pers
condition|)
block|{
case|case
name|EHPersonality
operator|::
name|Unknown
case|:
return|return
name|false
return|;
comment|// All known personalities currently have this behavior
default|default:
return|return
name|true
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"invalid enum"
argument_list|)
expr_stmt|;
block|}
name|bool
name|canSimplifyInvokeNoUnwind
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
typedef|typedef
name|TinyPtrVector
operator|<
name|BasicBlock
operator|*
operator|>
name|ColorVector
expr_stmt|;
comment|/// \brief If an EH funclet personality is in use (see isFuncletEHPersonality),
comment|/// this will recompute which blocks are in which funclet. It is possible that
comment|/// some blocks are in multiple funclets. Consider this analysis to be
comment|/// expensive.
name|DenseMap
operator|<
name|BasicBlock
operator|*
operator|,
name|ColorVector
operator|>
name|colorEHFunclets
argument_list|(
name|Function
operator|&
name|F
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

