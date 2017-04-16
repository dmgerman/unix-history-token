begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NSSet.h ---------------------------------------------------*- C++
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
name|liblldb_NSSet_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_NSSet_h_
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
name|cf_style
operator|>
name|bool
name|NSSetSummaryProvider
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
name|SyntheticChildrenFrontEnd
modifier|*
name|NSSetSyntheticFrontEndCreator
argument_list|(
name|CXXSyntheticChildren
operator|*
argument_list|,
name|lldb
operator|::
name|ValueObjectSP
argument_list|)
decl_stmt|;
name|class
name|NSSet_Additionals
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
empty_stmt|;
block|}
comment|// namespace formatters
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_NSSet_h_
end_comment

end_unit

