begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NSString.h ---------------------------------------------------*- C++
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
name|liblldb_NSString_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_NSString_h_
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
file|"lldb/Target/ObjCLanguageRuntime.h"
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
name|bool
name|NSStringSummaryProvider
parameter_list|(
name|ValueObject
modifier|&
name|valobj
parameter_list|,
name|Stream
modifier|&
name|stream
parameter_list|,
specifier|const
name|TypeSummaryOptions
modifier|&
name|options
parameter_list|)
function_decl|;
name|bool
name|NSTaggedString_SummaryProvider
argument_list|(
name|ValueObject
operator|&
name|valobj
argument_list|,
name|ObjCLanguageRuntime
operator|::
name|ClassDescriptorSP
name|descriptor
argument_list|,
name|Stream
operator|&
name|stream
argument_list|,
specifier|const
name|TypeSummaryOptions
operator|&
name|summary_options
argument_list|)
decl_stmt|;
name|bool
name|NSAttributedStringSummaryProvider
parameter_list|(
name|ValueObject
modifier|&
name|valobj
parameter_list|,
name|Stream
modifier|&
name|stream
parameter_list|,
specifier|const
name|TypeSummaryOptions
modifier|&
name|options
parameter_list|)
function_decl|;
name|bool
name|NSMutableAttributedStringSummaryProvider
parameter_list|(
name|ValueObject
modifier|&
name|valobj
parameter_list|,
name|Stream
modifier|&
name|stream
parameter_list|,
specifier|const
name|TypeSummaryOptions
modifier|&
name|options
parameter_list|)
function_decl|;
name|class
name|NSString_Additionals
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
comment|// liblldb_CF_h_
end_comment

end_unit

