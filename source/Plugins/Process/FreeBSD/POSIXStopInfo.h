begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- POSIXStopInfo.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_POSIXStopInfo_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_POSIXStopInfo_H_
end_define

begin_include
include|#
directive|include
file|"FreeBSDThread.h"
end_include

begin_include
include|#
directive|include
file|"Plugins/Process/POSIX/CrashReason.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/StopInfo.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// @class POSIXStopInfo
end_comment

begin_comment
comment|/// @brief Simple base class for all POSIX-specific StopInfo objects.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|POSIXStopInfo
range|:
name|public
name|lldb_private
operator|::
name|StopInfo
block|{
name|public
operator|:
name|POSIXStopInfo
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|uint32_t status
argument_list|)
operator|:
name|StopInfo
argument_list|(
argument|thread
argument_list|,
argument|status
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// @class POSIXLimboStopInfo
end_comment

begin_comment
comment|/// @brief Represents the stop state of a process ready to exit.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|POSIXLimboStopInfo
range|:
name|public
name|POSIXStopInfo
block|{
name|public
operator|:
name|POSIXLimboStopInfo
argument_list|(
name|FreeBSDThread
operator|&
name|thread
argument_list|)
operator|:
name|POSIXStopInfo
argument_list|(
argument|thread
argument_list|,
literal|0
argument_list|)
block|{}
operator|~
name|POSIXLimboStopInfo
argument_list|()
block|;
name|lldb
operator|::
name|StopReason
name|GetStopReason
argument_list|()
specifier|const
block|;
specifier|const
name|char
operator|*
name|GetDescription
argument_list|()
block|;
name|bool
name|ShouldStop
argument_list|(
name|lldb_private
operator|::
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
name|bool
name|ShouldNotify
argument_list|(
name|lldb_private
operator|::
name|Event
operator|*
name|event_ptr
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// @class POSIXCrashStopInfo
end_comment

begin_comment
comment|/// @brief Represents the stop state of process that is ready to crash.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|POSIXCrashStopInfo
range|:
name|public
name|POSIXStopInfo
block|{
name|public
operator|:
name|POSIXCrashStopInfo
argument_list|(
argument|FreeBSDThread&thread
argument_list|,
argument|uint32_t status
argument_list|,
argument|CrashReason reason
argument_list|,
argument|lldb::addr_t fault_addr
argument_list|)
block|;
operator|~
name|POSIXCrashStopInfo
argument_list|()
block|;
name|lldb
operator|::
name|StopReason
name|GetStopReason
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// @class POSIXNewThreadStopInfo
end_comment

begin_comment
comment|/// @brief Represents the stop state of process when a new thread is spawned.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|POSIXNewThreadStopInfo
range|:
name|public
name|POSIXStopInfo
block|{
name|public
operator|:
name|POSIXNewThreadStopInfo
argument_list|(
name|FreeBSDThread
operator|&
name|thread
argument_list|)
operator|:
name|POSIXStopInfo
argument_list|(
argument|thread
argument_list|,
literal|0
argument_list|)
block|{}
operator|~
name|POSIXNewThreadStopInfo
argument_list|()
block|;
name|lldb
operator|::
name|StopReason
name|GetStopReason
argument_list|()
specifier|const
block|;
specifier|const
name|char
operator|*
name|GetDescription
argument_list|()
block|;
name|bool
name|ShouldStop
argument_list|(
name|lldb_private
operator|::
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
name|bool
name|ShouldNotify
argument_list|(
name|lldb_private
operator|::
name|Event
operator|*
name|event_ptr
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

