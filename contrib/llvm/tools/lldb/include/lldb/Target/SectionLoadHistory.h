begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SectionLoadHistory.h ------------------------------------*- C++ -*-===//
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
name|liblldb_SectionLoadHistory_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_SectionLoadHistory_h_
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
file|"lldb/Host/Mutex.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|SectionLoadHistory
block|{
name|public
label|:
enum|enum
block|{
comment|// Pass eStopIDNow to any function that takes a stop ID to get
comment|// the current value.
name|eStopIDNow
init|=
name|UINT32_MAX
block|}
enum|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|SectionLoadHistory
argument_list|()
operator|:
name|m_stop_id_to_section_load_list
argument_list|()
operator|,
name|m_mutex
argument_list|(
argument|Mutex::eMutexTypeRecursive
argument_list|)
block|{     }
operator|~
name|SectionLoadHistory
argument_list|()
block|{
comment|// Call clear since this takes a lock and clears the section load list
comment|// in case another thread is currently using this section load list
name|Clear
argument_list|()
block|;     }
name|SectionLoadList
operator|&
name|GetCurrentSectionLoadList
argument_list|()
expr_stmt|;
name|bool
name|IsEmpty
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|uint32_t
name|GetLastStopID
argument_list|()
specifier|const
expr_stmt|;
comment|// Get the section load address given a process stop ID
name|lldb
operator|::
name|addr_t
name|GetSectionLoadAddress
argument_list|(
argument|uint32_t stop_id
argument_list|,
argument|const lldb::SectionSP&section_sp
argument_list|)
expr_stmt|;
name|bool
name|ResolveLoadAddress
argument_list|(
name|uint32_t
name|stop_id
argument_list|,
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|,
name|Address
operator|&
name|so_addr
argument_list|)
decl_stmt|;
name|bool
name|SetSectionLoadAddress
argument_list|(
name|uint32_t
name|stop_id
argument_list|,
specifier|const
name|lldb
operator|::
name|SectionSP
operator|&
name|section_sp
argument_list|,
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|,
name|bool
name|warn_multiple
operator|=
name|false
argument_list|)
decl_stmt|;
comment|// The old load address should be specified when unloading to ensure we get
comment|// the correct instance of the section as a shared library could be loaded
comment|// at more than one location.
name|bool
name|SetSectionUnloaded
argument_list|(
name|uint32_t
name|stop_id
argument_list|,
specifier|const
name|lldb
operator|::
name|SectionSP
operator|&
name|section_sp
argument_list|,
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|)
decl_stmt|;
comment|// Unload all instances of a section. This function can be used on systems
comment|// that don't support multiple copies of the same shared library to be
comment|// loaded at the same time.
name|size_t
name|SetSectionUnloaded
argument_list|(
name|uint32_t
name|stop_id
argument_list|,
specifier|const
name|lldb
operator|::
name|SectionSP
operator|&
name|section_sp
argument_list|)
decl_stmt|;
name|void
name|Dump
parameter_list|(
name|Stream
modifier|&
name|s
parameter_list|,
name|Target
modifier|*
name|target
parameter_list|)
function_decl|;
name|protected
label|:
name|SectionLoadList
modifier|*
name|GetSectionLoadListForStopID
parameter_list|(
name|uint32_t
name|stop_id
parameter_list|,
name|bool
name|read_only
parameter_list|)
function_decl|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint32_t
operator|,
name|lldb
operator|::
name|SectionLoadListSP
operator|>
name|StopIDToSectionLoadList
expr_stmt|;
name|StopIDToSectionLoadList
name|m_stop_id_to_section_load_list
decl_stmt|;
name|mutable
name|Mutex
name|m_mutex
decl_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|SectionLoadHistory
argument_list|)
expr_stmt|;
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
comment|// liblldb_SectionLoadHistory_h_
end_comment

end_unit

