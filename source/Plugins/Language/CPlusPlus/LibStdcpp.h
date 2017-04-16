begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LibStdcpp.h ---------------------------------------------*- C++ -*-===//
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
name|liblldb_LibStdCpp_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_LibStdCpp_h_
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
name|LibStdcppStringSummaryProvider
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
comment|// libcstdc++ c++11 std::string
name|bool
name|LibStdcppWStringSummaryProvider
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
comment|// libcstdc++ c++11 std::wstring
name|bool
name|LibStdcppSmartPointerSummaryProvider
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
comment|// libstdc++ std::shared_ptr<> and std::weak_ptr<>
name|bool
name|LibStdcppUniquePointerSummaryProvider
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
comment|// libstdc++ std::unique_ptr<>
name|SyntheticChildrenFrontEnd
modifier|*
name|LibstdcppMapIteratorSyntheticFrontEndCreator
argument_list|(
name|CXXSyntheticChildren
operator|*
argument_list|,
name|lldb
operator|::
name|ValueObjectSP
argument_list|)
decl_stmt|;
name|SyntheticChildrenFrontEnd
modifier|*
name|LibStdcppTupleSyntheticFrontEndCreator
argument_list|(
name|CXXSyntheticChildren
operator|*
argument_list|,
name|lldb
operator|::
name|ValueObjectSP
argument_list|)
decl_stmt|;
name|SyntheticChildrenFrontEnd
modifier|*
name|LibStdcppVectorIteratorSyntheticFrontEndCreator
argument_list|(
name|CXXSyntheticChildren
operator|*
argument_list|,
name|lldb
operator|::
name|ValueObjectSP
argument_list|)
decl_stmt|;
name|SyntheticChildrenFrontEnd
modifier|*
name|LibStdcppSharedPtrSyntheticFrontEndCreator
argument_list|(
name|CXXSyntheticChildren
operator|*
argument_list|,
name|lldb
operator|::
name|ValueObjectSP
argument_list|)
decl_stmt|;
name|SyntheticChildrenFrontEnd
modifier|*
name|LibStdcppUniquePtrSyntheticFrontEndCreator
argument_list|(
name|CXXSyntheticChildren
operator|*
argument_list|,
name|lldb
operator|::
name|ValueObjectSP
argument_list|)
decl_stmt|;
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
comment|// liblldb_LibStdCpp_h_
end_comment

end_unit

