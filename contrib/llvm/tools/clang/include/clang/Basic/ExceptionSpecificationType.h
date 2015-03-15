begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ExceptionSpecificationType.h ---------------------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the ExceptionSpecificationType enumeration and various
end_comment

begin_comment
comment|/// utility functions.
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
name|LLVM_CLANG_BASIC_EXCEPTIONSPECIFICATIONTYPE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_EXCEPTIONSPECIFICATIONTYPE_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief The various types of exception specifications that exist in C++11.
enum|enum
name|ExceptionSpecificationType
block|{
name|EST_None
block|,
comment|///< no exception specification
name|EST_DynamicNone
block|,
comment|///< throw()
name|EST_Dynamic
block|,
comment|///< throw(T1, T2)
name|EST_MSAny
block|,
comment|///< Microsoft throw(...) extension
name|EST_BasicNoexcept
block|,
comment|///< noexcept
name|EST_ComputedNoexcept
block|,
comment|///< noexcept(expression)
name|EST_Unevaluated
block|,
comment|///< not evaluated yet, for special member function
name|EST_Uninstantiated
block|,
comment|///< not instantiated yet
name|EST_Unparsed
comment|///< not parsed yet
block|}
enum|;
specifier|inline
name|bool
name|isDynamicExceptionSpec
parameter_list|(
name|ExceptionSpecificationType
name|ESpecType
parameter_list|)
block|{
return|return
name|ESpecType
operator|>=
name|EST_DynamicNone
operator|&&
name|ESpecType
operator|<=
name|EST_MSAny
return|;
block|}
specifier|inline
name|bool
name|isNoexceptExceptionSpec
parameter_list|(
name|ExceptionSpecificationType
name|ESpecType
parameter_list|)
block|{
return|return
name|ESpecType
operator|==
name|EST_BasicNoexcept
operator|||
name|ESpecType
operator|==
name|EST_ComputedNoexcept
return|;
block|}
specifier|inline
name|bool
name|isUnresolvedExceptionSpec
parameter_list|(
name|ExceptionSpecificationType
name|ESpecType
parameter_list|)
block|{
return|return
name|ESpecType
operator|==
name|EST_Unevaluated
operator|||
name|ESpecType
operator|==
name|EST_Uninstantiated
return|;
block|}
comment|/// \brief Possible results from evaluation of a noexcept expression.
enum|enum
name|CanThrowResult
block|{
name|CT_Cannot
block|,
name|CT_Dependent
block|,
name|CT_Can
block|}
enum|;
specifier|inline
name|CanThrowResult
name|mergeCanThrow
parameter_list|(
name|CanThrowResult
name|CT1
parameter_list|,
name|CanThrowResult
name|CT2
parameter_list|)
block|{
comment|// CanThrowResult constants are ordered so that the maximum is the correct
comment|// merge result.
return|return
name|CT1
operator|>
name|CT2
condition|?
name|CT1
else|:
name|CT2
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_BASIC_EXCEPTIONSPECIFICATIONTYPE_H
end_comment

end_unit

