begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NSDictionary.h ---------------------------------------------------*- C++ -*-===//
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
file|"lldb/Core/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Stream.h"
end_include

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
file|<map>
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
extern|extern template bool         NSDictionarySummaryProvider<true> (ValueObject&
operator|,
extern|Stream&
operator|,
extern|const TypeSummaryOptions&
block|)
decl_stmt|;
extern|extern template bool         NSDictionarySummaryProvider<false> (ValueObject&
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
specifier|static
name|std
operator|::
name|map
operator|<
name|ConstString
operator|,
name|CXXFunctionSummaryFormat
operator|::
name|Callback
operator|>
operator|&
name|GetAdditionalSummaries
argument_list|()
expr_stmt|;
specifier|static
name|std
operator|::
name|map
operator|<
name|ConstString
operator|,
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

