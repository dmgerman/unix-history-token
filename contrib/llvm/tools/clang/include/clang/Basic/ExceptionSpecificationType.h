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
comment|//
end_comment

begin_comment
comment|// This file defines the ExceptionSpecificationType enumeration and various
end_comment

begin_comment
comment|// utility functions.
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
comment|/// \brief The various types of exception specifications that exist in C++0x.
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
comment|///< noexcept(expression)
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

