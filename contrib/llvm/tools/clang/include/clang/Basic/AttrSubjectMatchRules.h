begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AttrSubjectMatchRules.h - Attribute subject match rules -*- C++ -*-===//
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
name|LLVM_CLANG_BASIC_ATTR_SUBJECT_MATCH_RULES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_ATTR_SUBJECT_MATCH_RULES_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|attr
block|{
comment|/// \brief A list of all the recognized kinds of attributes.
enum|enum
name|SubjectMatchRule
block|{
define|#
directive|define
name|ATTR_MATCH_RULE
parameter_list|(
name|X
parameter_list|,
name|Spelling
parameter_list|,
name|IsAbstract
parameter_list|)
value|X,
include|#
directive|include
file|"clang/Basic/AttrSubMatchRulesList.inc"
block|}
enum|;
specifier|const
name|char
modifier|*
name|getSubjectMatchRuleSpelling
parameter_list|(
name|SubjectMatchRule
name|Rule
parameter_list|)
function_decl|;
name|using
name|ParsedSubjectMatchRuleSet
init|=
name|llvm
operator|::
name|DenseMap
operator|<
name|int
decl_stmt|,
name|SourceRange
decl|>
decl_stmt|;
block|}
comment|// end namespace attr
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

