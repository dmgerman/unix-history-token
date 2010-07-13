begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------- SemaTemplate.h - C++ Templates ---------------------*- C++ -*-===/
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
comment|//===----------------------------------------------------------------------===/
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file provides types used in the semantic analysis of C++ templates.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_SEMA_TEMPLATE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_TEMPLATE_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/DeclTemplate.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Data structure that captures multiple levels of template argument
comment|/// lists for use in template instantiation.
comment|///
comment|/// Multiple levels of template arguments occur when instantiating the
comment|/// definitions of member templates. For example:
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// struct X {
comment|///   template<T Value>
comment|///   struct Y {
comment|///     void f();
comment|///   };
comment|/// };
comment|/// \endcode
comment|///
comment|/// When instantiating X<int>::Y<17>::f, the multi-level template argument
comment|/// list will contain a template argument list (int) at depth 0 and a
comment|/// template argument list (17) at depth 1.
name|class
name|MultiLevelTemplateArgumentList
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|TemplateArgument
operator|*
operator|,
name|unsigned
operator|>
name|ArgList
expr_stmt|;
name|private
label|:
comment|/// \brief The template argument lists, stored from the innermost template
comment|/// argument list (first) to the outermost template argument list (last).
name|llvm
operator|::
name|SmallVector
operator|<
name|ArgList
operator|,
literal|4
operator|>
name|TemplateArgumentLists
expr_stmt|;
name|public
label|:
comment|/// \brief Construct an empty set of template argument lists.
name|MultiLevelTemplateArgumentList
argument_list|()
block|{ }
comment|/// \brief Construct a single-level template argument list.
name|explicit
name|MultiLevelTemplateArgumentList
parameter_list|(
specifier|const
name|TemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
block|{
name|addOuterTemplateArguments
argument_list|(
operator|&
name|TemplateArgs
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Determine the number of levels in this template argument
comment|/// list.
name|unsigned
name|getNumLevels
argument_list|()
specifier|const
block|{
return|return
name|TemplateArgumentLists
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the template argument at a given depth and index.
specifier|const
name|TemplateArgument
operator|&
name|operator
argument_list|()
operator|(
name|unsigned
name|Depth
operator|,
name|unsigned
name|Index
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Depth
operator|<
name|TemplateArgumentLists
operator|.
name|size
argument_list|()
argument_list|)
block|;
name|assert
argument_list|(
name|Index
operator|<
name|TemplateArgumentLists
index|[
name|getNumLevels
argument_list|()
operator|-
name|Depth
operator|-
literal|1
index|]
operator|.
name|second
argument_list|)
block|;
return|return
name|TemplateArgumentLists
index|[
name|getNumLevels
argument_list|()
operator|-
name|Depth
operator|-
literal|1
index|]
operator|.
name|first
index|[
name|Index
index|]
return|;
block|}
comment|/// \brief Determine whether there is a non-NULL template argument at the
comment|/// given depth and index.
comment|///
comment|/// There must exist a template argument list at the given depth.
name|bool
name|hasTemplateArgument
argument_list|(
name|unsigned
name|Depth
argument_list|,
name|unsigned
name|Index
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Depth
operator|<
name|TemplateArgumentLists
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|Index
operator|>=
name|TemplateArgumentLists
index|[
name|getNumLevels
argument_list|()
operator|-
name|Depth
operator|-
literal|1
index|]
operator|.
name|second
condition|)
return|return
name|false
return|;
return|return
operator|!
call|(
modifier|*
name|this
call|)
argument_list|(
name|Depth
argument_list|,
name|Index
argument_list|)
operator|.
name|isNull
argument_list|()
return|;
block|}
comment|/// \brief Add a new outermost level to the multi-level template argument
comment|/// list.
name|void
name|addOuterTemplateArguments
parameter_list|(
specifier|const
name|TemplateArgumentList
modifier|*
name|TemplateArgs
parameter_list|)
block|{
name|TemplateArgumentLists
operator|.
name|push_back
argument_list|(
name|ArgList
argument_list|(
name|TemplateArgs
operator|->
name|getFlatArgumentList
argument_list|()
argument_list|,
name|TemplateArgs
operator|->
name|flat_size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Add a new outmost level to the multi-level template argument
comment|/// list.
name|void
name|addOuterTemplateArguments
parameter_list|(
specifier|const
name|TemplateArgument
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|)
block|{
name|TemplateArgumentLists
operator|.
name|push_back
argument_list|(
name|ArgList
argument_list|(
name|Args
argument_list|,
name|NumArgs
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Retrieve the innermost template argument list.
specifier|const
name|ArgList
operator|&
name|getInnermost
argument_list|()
specifier|const
block|{
return|return
name|TemplateArgumentLists
operator|.
name|front
argument_list|()
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief The context in which partial ordering of function templates occurs.
enum|enum
name|TemplatePartialOrderingContext
block|{
comment|/// \brief Partial ordering of function templates for a function call.
name|TPOC_Call
block|,
comment|/// \brief Partial ordering of function templates for a call to a
comment|/// conversion function.
name|TPOC_Conversion
block|,
comment|/// \brief Partial ordering of function templates in other contexts, e.g.,
comment|/// taking the address of a function template or matching a function
comment|/// template specialization to a function template.
name|TPOC_Other
block|}
enum|;
comment|/// \brief Captures a template argument whose value has been deduced
comment|/// via c++ template argument deduction.
name|class
name|DeducedTemplateArgument
range|:
name|public
name|TemplateArgument
block|{
comment|/// \brief For a non-type template argument, whether the value was
comment|/// deduced from an array bound.
name|bool
name|DeducedFromArrayBound
block|;
name|public
operator|:
name|DeducedTemplateArgument
argument_list|()
operator|:
name|TemplateArgument
argument_list|()
block|,
name|DeducedFromArrayBound
argument_list|(
argument|false
argument_list|)
block|{ }
name|DeducedTemplateArgument
argument_list|(
argument|const TemplateArgument&Arg
argument_list|,
argument|bool DeducedFromArrayBound = false
argument_list|)
operator|:
name|TemplateArgument
argument_list|(
name|Arg
argument_list|)
block|,
name|DeducedFromArrayBound
argument_list|(
argument|DeducedFromArrayBound
argument_list|)
block|{ }
comment|/// \brief Construct an integral non-type template argument that
comment|/// has been deduced, possible from an array bound.
name|DeducedTemplateArgument
argument_list|(
argument|const llvm::APSInt&Value
argument_list|,
argument|QualType ValueType
argument_list|,
argument|bool DeducedFromArrayBound
argument_list|)
operator|:
name|TemplateArgument
argument_list|(
name|Value
argument_list|,
name|ValueType
argument_list|)
block|,
name|DeducedFromArrayBound
argument_list|(
argument|DeducedFromArrayBound
argument_list|)
block|{ }
comment|/// \brief For a non-type template argument, determine whether the
comment|/// template argument was deduced from an array bound.
name|bool
name|wasDeducedFromArrayBound
argument_list|()
specifier|const
block|{
return|return
name|DeducedFromArrayBound
return|;
block|}
comment|/// \brief Specify whether the given non-type template argument
comment|/// was deduced from an array bound.
name|void
name|setDeducedFromArrayBound
argument_list|(
argument|bool Deduced
argument_list|)
block|{
name|DeducedFromArrayBound
operator|=
name|Deduced
block|;     }
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_SEMA_TEMPLATE_H
end_comment

end_unit

