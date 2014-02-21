begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LogChannelDWARF.h --------------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_LogChannelDWARF_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_LogChannelDWARF_h_
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
file|"lldb/Core/Log.h"
end_include

begin_define
define|#
directive|define
name|DWARF_LOG_VERBOSE
value|(1u<< 0)
end_define

begin_define
define|#
directive|define
name|DWARF_LOG_DEBUG_INFO
value|(1u<< 1)
end_define

begin_define
define|#
directive|define
name|DWARF_LOG_DEBUG_LINE
value|(1u<< 2)
end_define

begin_define
define|#
directive|define
name|DWARF_LOG_DEBUG_PUBNAMES
value|(1u<< 3)
end_define

begin_define
define|#
directive|define
name|DWARF_LOG_DEBUG_PUBTYPES
value|(1u<< 4)
end_define

begin_define
define|#
directive|define
name|DWARF_LOG_DEBUG_ARANGES
value|(1u<< 5)
end_define

begin_define
define|#
directive|define
name|DWARF_LOG_LOOKUPS
value|(1u<< 6)
end_define

begin_define
define|#
directive|define
name|DWARF_LOG_TYPE_COMPLETION
value|(1u<< 7)
end_define

begin_define
define|#
directive|define
name|DWARF_LOG_DEBUG_MAP
value|(1u<< 8)
end_define

begin_define
define|#
directive|define
name|DWARF_LOG_ALL
value|(UINT32_MAX)
end_define

begin_define
define|#
directive|define
name|DWARF_LOG_DEFAULT
value|(DWARF_LOG_DEBUG_INFO)
end_define

begin_decl_stmt
name|class
name|LogChannelDWARF
range|:
name|public
name|lldb_private
operator|::
name|LogChannel
block|{
name|public
operator|:
name|LogChannelDWARF
argument_list|()
block|;
name|virtual
operator|~
name|LogChannelDWARF
argument_list|()
block|;
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
specifier|static
specifier|const
name|char
operator|*
name|GetPluginDescriptionStatic
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|LogChannel
operator|*
name|CreateInstance
argument_list|()
block|;
name|virtual
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
block|;
name|virtual
name|uint32_t
name|GetPluginVersion
argument_list|()
block|;
name|virtual
name|void
name|Disable
argument_list|(
specifier|const
name|char
operator|*
operator|*
name|categories
argument_list|,
name|lldb_private
operator|::
name|Stream
operator|*
name|feedback_strm
argument_list|)
block|;
name|void
name|Delete
argument_list|()
block|;
name|virtual
name|bool
name|Enable
argument_list|(
argument|lldb::StreamSP&log_stream_sp
argument_list|,
argument|uint32_t log_options
argument_list|,
argument|lldb_private::Stream *feedback_strm
argument_list|,
comment|// Feedback stream for argument errors etc
argument|const char **categories
argument_list|)
block|;
comment|// The categories to enable within this logging stream, if empty, enable default set
name|virtual
name|void
name|ListCategories
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|strm
argument_list|)
block|;
specifier|static
name|lldb_private
operator|::
name|Log
operator|*
name|GetLog
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|Log
operator|*
name|GetLogIfAll
argument_list|(
argument|uint32_t mask
argument_list|)
block|;
specifier|static
name|lldb_private
operator|::
name|Log
operator|*
name|GetLogIfAny
argument_list|(
argument|uint32_t mask
argument_list|)
block|;
specifier|static
name|void
name|LogIf
argument_list|(
argument|uint32_t mask
argument_list|,
argument|const char *format
argument_list|,
argument|...
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SymbolFileDWARF_LogChannelDWARF_h_
end_comment

end_unit

