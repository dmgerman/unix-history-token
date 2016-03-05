begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LanguageCategory.h----------------------------------------*- C++ -*-===//
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
name|lldb_LanguageCategory_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_LanguageCategory_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|"lldb/DataFormatters/FormatCache.h"
end_include

begin_include
include|#
directive|include
file|"lldb/DataFormatters/FormatClasses.h"
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
name|class
name|LanguageCategory
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|unique_ptr
operator|<
name|LanguageCategory
operator|>
name|UniquePointer
expr_stmt|;
name|LanguageCategory
argument_list|(
argument|lldb::LanguageType lang_type
argument_list|)
empty_stmt|;
name|bool
name|Get
argument_list|(
name|FormattersMatchData
operator|&
name|match_data
argument_list|,
name|lldb
operator|::
name|TypeFormatImplSP
operator|&
name|format_sp
argument_list|)
decl_stmt|;
name|bool
name|Get
argument_list|(
name|FormattersMatchData
operator|&
name|match_data
argument_list|,
name|lldb
operator|::
name|TypeSummaryImplSP
operator|&
name|format_sp
argument_list|)
decl_stmt|;
name|bool
name|Get
argument_list|(
name|FormattersMatchData
operator|&
name|match_data
argument_list|,
name|lldb
operator|::
name|SyntheticChildrenSP
operator|&
name|format_sp
argument_list|)
decl_stmt|;
name|bool
name|Get
argument_list|(
name|FormattersMatchData
operator|&
name|match_data
argument_list|,
name|lldb
operator|::
name|TypeValidatorImplSP
operator|&
name|format_sp
argument_list|)
decl_stmt|;
name|bool
name|GetHardcoded
argument_list|(
name|FormatManager
operator|&
name|fmt_mgr
argument_list|,
name|FormattersMatchData
operator|&
name|match_data
argument_list|,
name|lldb
operator|::
name|TypeFormatImplSP
operator|&
name|format_sp
argument_list|)
decl_stmt|;
name|bool
name|GetHardcoded
argument_list|(
name|FormatManager
operator|&
name|fmt_mgr
argument_list|,
name|FormattersMatchData
operator|&
name|match_data
argument_list|,
name|lldb
operator|::
name|TypeSummaryImplSP
operator|&
name|format_sp
argument_list|)
decl_stmt|;
name|bool
name|GetHardcoded
argument_list|(
name|FormatManager
operator|&
name|fmt_mgr
argument_list|,
name|FormattersMatchData
operator|&
name|match_data
argument_list|,
name|lldb
operator|::
name|SyntheticChildrenSP
operator|&
name|format_sp
argument_list|)
decl_stmt|;
name|bool
name|GetHardcoded
argument_list|(
name|FormatManager
operator|&
name|fmt_mgr
argument_list|,
name|FormattersMatchData
operator|&
name|match_data
argument_list|,
name|lldb
operator|::
name|TypeValidatorImplSP
operator|&
name|format_sp
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|TypeCategoryImplSP
name|GetCategory
argument_list|()
specifier|const
expr_stmt|;
name|FormatCache
modifier|&
name|GetFormatCache
parameter_list|()
function_decl|;
name|void
name|Enable
parameter_list|()
function_decl|;
name|void
name|Disable
parameter_list|()
function_decl|;
name|bool
name|IsEnabled
parameter_list|()
function_decl|;
name|private
label|:
name|lldb
operator|::
name|TypeCategoryImplSP
name|m_category_sp
expr_stmt|;
name|HardcodedFormatters
operator|::
name|HardcodedFormatFinder
name|m_hardcoded_formats
expr_stmt|;
name|HardcodedFormatters
operator|::
name|HardcodedSummaryFinder
name|m_hardcoded_summaries
expr_stmt|;
name|HardcodedFormatters
operator|::
name|HardcodedSyntheticFinder
name|m_hardcoded_synthetics
expr_stmt|;
name|HardcodedFormatters
operator|::
name|HardcodedValidatorFinder
name|m_hardcoded_validators
expr_stmt|;
name|lldb_private
operator|::
name|FormatCache
name|m_format_cache
expr_stmt|;
name|bool
name|m_enabled
decl_stmt|;
block|}
empty_stmt|;
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
comment|// lldb_LanguageCategory_h_
end_comment

end_unit

