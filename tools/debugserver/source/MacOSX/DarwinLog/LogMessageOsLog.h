begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LogMessageOsLog.h ---------------------------------------*- C++ -*-===//
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
name|LogMessageOsLog_h
end_ifndef

begin_define
define|#
directive|define
name|LogMessageOsLog_h
end_define

begin_include
include|#
directive|include
file|"DarwinLogInterfaces.h"
end_include

begin_include
include|#
directive|include
file|"ActivityStreamSPI.h"
end_include

begin_include
include|#
directive|include
file|"LogMessage.h"
end_include

begin_decl_stmt
name|using
name|ActivityStreamEntry
init|= struct
name|os_activity_stream_entry_s
decl_stmt|;
end_decl_stmt

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_comment
comment|/// Provides a unified wrapper around os_log()-style log messages.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The lifetime of this class is intended to be very short.  The caller
end_comment

begin_comment
comment|/// must ensure that the passed in ActivityStore and ActivityStreamEntry
end_comment

begin_comment
comment|/// outlive this LogMessageOsLog entry.
end_comment

begin_comment
comment|// -----------------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|LogMessageOsLog
range|:
name|public
name|LogMessage
block|{
name|public
operator|:
specifier|static
name|void
name|SetFormatterFunction
argument_list|(
argument|os_log_copy_formatted_message_t format_func
argument_list|)
block|;
name|LogMessageOsLog
argument_list|(
specifier|const
name|ActivityStore
operator|&
name|activity_store
argument_list|,
name|ActivityStreamEntry
operator|&
name|entry
argument_list|)
block|;
comment|// API methods
name|bool
name|HasActivity
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|char
operator|*
name|GetActivity
argument_list|()
specifier|const
name|override
block|;
name|std
operator|::
name|string
name|GetActivityChain
argument_list|()
specifier|const
name|override
block|;
name|bool
name|HasCategory
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|char
operator|*
name|GetCategory
argument_list|()
specifier|const
name|override
block|;
name|bool
name|HasSubsystem
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|char
operator|*
name|GetSubsystem
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|char
operator|*
name|GetMessage
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
specifier|const
name|ActivityStore
operator|&
name|m_activity_store
block|;
name|ActivityStreamEntry
operator|&
name|m_entry
block|;
name|mutable
name|std
operator|::
name|string
name|m_message
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LogMessageOsLog_h */
end_comment

end_unit

