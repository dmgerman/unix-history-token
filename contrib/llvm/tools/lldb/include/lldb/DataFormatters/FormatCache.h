begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FormatCache.h ---------------------------------------------*- C++ -*-===//
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
name|lldb_FormatCache_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_FormatCache_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<map>
end_include

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
file|"lldb/Core/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/DataFormatters/FormatClasses.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|FormatCache
block|{
name|private
label|:
struct|struct
name|Entry
block|{
name|private
label|:
name|bool
name|m_summary_cached
range|:
literal|1
decl_stmt|;
name|bool
name|m_synthetic_cached
range|:
literal|1
decl_stmt|;
name|lldb
operator|::
name|TypeSummaryImplSP
name|m_summary_sp
expr_stmt|;
name|lldb
operator|::
name|SyntheticChildrenSP
name|m_synthetic_sp
expr_stmt|;
name|public
label|:
name|Entry
argument_list|()
expr_stmt|;
name|Entry
argument_list|(
name|lldb
operator|::
name|TypeSummaryImplSP
argument_list|)
expr_stmt|;
name|Entry
argument_list|(
name|lldb
operator|::
name|SyntheticChildrenSP
argument_list|)
expr_stmt|;
name|Entry
argument_list|(
name|lldb
operator|::
name|TypeSummaryImplSP
argument_list|,
name|lldb
operator|::
name|SyntheticChildrenSP
argument_list|)
expr_stmt|;
name|bool
name|IsSummaryCached
parameter_list|()
function_decl|;
name|bool
name|IsSyntheticCached
parameter_list|()
function_decl|;
name|lldb
operator|::
name|TypeSummaryImplSP
name|GetSummary
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SyntheticChildrenSP
name|GetSynthetic
argument_list|()
expr_stmt|;
name|void
name|SetSummary
argument_list|(
name|lldb
operator|::
name|TypeSummaryImplSP
argument_list|)
decl_stmt|;
name|void
name|SetSynthetic
argument_list|(
name|lldb
operator|::
name|SyntheticChildrenSP
argument_list|)
decl_stmt|;
block|}
struct|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|ConstString
operator|,
name|Entry
operator|>
name|CacheMap
expr_stmt|;
name|CacheMap
name|m_map
decl_stmt|;
name|Mutex
name|m_mutex
decl_stmt|;
name|uint64_t
name|m_cache_hits
decl_stmt|;
name|uint64_t
name|m_cache_misses
decl_stmt|;
name|Entry
modifier|&
name|GetEntry
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|type
parameter_list|)
function_decl|;
name|public
label|:
name|FormatCache
argument_list|()
expr_stmt|;
name|bool
name|GetSummary
argument_list|(
specifier|const
name|ConstString
operator|&
name|type
argument_list|,
name|lldb
operator|::
name|TypeSummaryImplSP
operator|&
name|summary_sp
argument_list|)
decl_stmt|;
name|bool
name|GetSynthetic
argument_list|(
specifier|const
name|ConstString
operator|&
name|type
argument_list|,
name|lldb
operator|::
name|SyntheticChildrenSP
operator|&
name|synthetic_sp
argument_list|)
decl_stmt|;
name|void
name|SetSummary
argument_list|(
specifier|const
name|ConstString
operator|&
name|type
argument_list|,
name|lldb
operator|::
name|TypeSummaryImplSP
operator|&
name|summary_sp
argument_list|)
decl_stmt|;
name|void
name|SetSynthetic
argument_list|(
specifier|const
name|ConstString
operator|&
name|type
argument_list|,
name|lldb
operator|::
name|SyntheticChildrenSP
operator|&
name|synthetic_sp
argument_list|)
decl_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|uint64_t
name|GetCacheHits
parameter_list|()
block|{
return|return
name|m_cache_hits
return|;
block|}
name|uint64_t
name|GetCacheMisses
parameter_list|()
block|{
return|return
name|m_cache_misses
return|;
block|}
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
comment|// lldb_FormatCache_h_
end_comment

end_unit

