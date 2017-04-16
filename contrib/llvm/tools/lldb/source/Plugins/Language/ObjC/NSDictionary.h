begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NSDictionary.h ---------------------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|liblldb_NSDictionary_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_NSDictionary_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/ValueObject.h"
end_include

begin_include
include|#
directive|include
file|"lldb/DataFormatters/TypeSummary.h"
end_include

begin_include
include|#
directive|include
file|"lldb/DataFormatters/TypeSynthetic.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Stream.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|formatters
block|{
name|template
operator|<
name|bool
name|name_entries
operator|>
name|bool
name|NSDictionarySummaryProvider
argument_list|(
name|ValueObject
operator|&
name|valobj
argument_list|,
name|Stream
operator|&
name|stream
argument_list|,
specifier|const
name|TypeSummaryOptions
operator|&
name|options
argument_list|)
expr_stmt|;
extern|extern template bool NSDictionarySummaryProvider<true>(ValueObject&
operator|,
extern|Stream&
operator|,
extern|const TypeSummaryOptions&
block|)
decl_stmt|;
extern|extern template bool NSDictionarySummaryProvider<false>(ValueObject&
operator|,
extern|Stream&
operator|,
extern|const TypeSummaryOptions&
block|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SyntheticChildrenFrontEnd
modifier|*
name|NSDictionarySyntheticFrontEndCreator
argument_list|(
name|CXXSyntheticChildren
operator|*
argument_list|,
name|lldb
operator|::
name|ValueObjectSP
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|NSDictionary_Additionals
block|{
name|public
label|:
name|class
name|AdditionalFormatterMatching
block|{
name|public
label|:
name|class
name|Matcher
block|{
name|public
label|:
name|virtual
operator|~
name|Matcher
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
name|bool
name|Match
parameter_list|(
name|ConstString
name|class_name
parameter_list|)
init|=
literal|0
function_decl|;
typedef|typedef
name|std
operator|::
name|unique_ptr
operator|<
name|Matcher
operator|>
name|UP
expr_stmt|;
block|}
empty_stmt|;
name|class
name|Prefix
range|:
name|public
name|Matcher
block|{
name|public
operator|:
name|Prefix
argument_list|(
argument|ConstString p
argument_list|)
block|;
name|virtual
operator|~
name|Prefix
argument_list|()
operator|=
expr|default
block|;
name|virtual
name|bool
name|Match
argument_list|(
argument|ConstString class_name
argument_list|)
name|override
block|;
name|private
operator|:
name|ConstString
name|m_prefix
block|;     }
decl_stmt|;
name|class
name|Full
range|:
name|public
name|Matcher
block|{
name|public
operator|:
name|Full
argument_list|(
argument|ConstString n
argument_list|)
block|;
name|virtual
operator|~
name|Full
argument_list|()
operator|=
expr|default
block|;
name|virtual
name|bool
name|Match
argument_list|(
argument|ConstString class_name
argument_list|)
name|override
block|;
name|private
operator|:
name|ConstString
name|m_name
block|;     }
decl_stmt|;
typedef|typedef
name|Matcher
operator|::
name|UP
name|MatcherUP
expr_stmt|;
name|MatcherUP
name|GetFullMatch
parameter_list|(
name|ConstString
name|n
parameter_list|)
block|{
return|return
name|llvm
operator|::
name|make_unique
operator|<
name|Full
operator|>
operator|(
name|n
operator|)
return|;
block|}
name|MatcherUP
name|GetPrefixMatch
parameter_list|(
name|ConstString
name|p
parameter_list|)
block|{
return|return
name|llvm
operator|::
name|make_unique
operator|<
name|Prefix
operator|>
operator|(
name|p
operator|)
return|;
block|}
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|FormatterType
operator|>
name|using
name|AdditionalFormatter
operator|=
name|std
operator|::
name|pair
operator|<
name|AdditionalFormatterMatching
operator|::
name|MatcherUP
operator|,
name|FormatterType
operator|>
expr_stmt|;
name|template
operator|<
name|typename
name|FormatterType
operator|>
name|using
name|AdditionalFormatters
operator|=
name|std
operator|::
name|vector
operator|<
name|AdditionalFormatter
operator|<
name|FormatterType
operator|>>
expr_stmt|;
specifier|static
name|AdditionalFormatters
operator|<
name|CXXFunctionSummaryFormat
operator|::
name|Callback
operator|>
operator|&
name|GetAdditionalSummaries
argument_list|()
expr_stmt|;
specifier|static
name|AdditionalFormatters
operator|<
name|CXXSyntheticChildren
operator|::
name|CreateFrontEndCallback
operator|>
operator|&
name|GetAdditionalSynthetics
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace formatters
end_comment

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_NSDictionary_h_
end_comment

end_unit

