begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PThreadEvent.h ------------------------------------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|//  Created by Greg Clayton on 6/16/07.
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
name|__PThreadEvent_h__
end_ifndef

begin_define
define|#
directive|define
name|__PThreadEvent_h__
end_define

begin_include
include|#
directive|include
file|"PThreadCondition.h"
end_include

begin_include
include|#
directive|include
file|"PThreadMutex.h"
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_decl_stmt
name|class
name|PThreadEvent
block|{
name|public
label|:
name|PThreadEvent
argument_list|(
argument|uint32_t bits =
literal|0
argument_list|,
argument|uint32_t validBits =
literal|0
argument_list|)
empty_stmt|;
operator|~
name|PThreadEvent
argument_list|()
expr_stmt|;
name|uint32_t
name|NewEventBit
parameter_list|()
function_decl|;
name|void
name|FreeEventBits
parameter_list|(
specifier|const
name|uint32_t
name|mask
parameter_list|)
function_decl|;
name|void
name|ReplaceEventBits
parameter_list|(
specifier|const
name|uint32_t
name|bits
parameter_list|)
function_decl|;
name|uint32_t
name|GetEventBits
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetEvents
parameter_list|(
specifier|const
name|uint32_t
name|mask
parameter_list|)
function_decl|;
name|void
name|ResetEvents
parameter_list|(
specifier|const
name|uint32_t
name|mask
parameter_list|)
function_decl|;
comment|// Wait for events to be set or reset. These functions take an optional
comment|// timeout value. If timeout is NULL an infinite timeout will be used.
name|uint32_t
name|WaitForSetEvents
argument_list|(
specifier|const
name|uint32_t
name|mask
argument_list|,
specifier|const
expr|struct
name|timespec
operator|*
name|timeout_abstime
operator|=
name|NULL
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|WaitForEventsToReset
argument_list|(
specifier|const
name|uint32_t
name|mask
argument_list|,
specifier|const
expr|struct
name|timespec
operator|*
name|timeout_abstime
operator|=
name|NULL
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|GetResetAckMask
argument_list|()
specifier|const
block|{
return|return
name|m_reset_ack_mask
return|;
block|}
name|uint32_t
name|SetResetAckMask
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
block|{
return|return
name|m_reset_ack_mask
operator|=
name|mask
return|;
block|}
name|uint32_t
name|WaitForResetAck
argument_list|(
specifier|const
name|uint32_t
name|mask
argument_list|,
specifier|const
expr|struct
name|timespec
operator|*
name|timeout_abstime
operator|=
name|NULL
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
comment|//----------------------------------------------------------------------
comment|// pthread condition and mutex variable to control access and allow
comment|// blocking between the main thread and the spotlight index thread.
comment|//----------------------------------------------------------------------
name|mutable
name|PThreadMutex
name|m_mutex
decl_stmt|;
name|mutable
name|PThreadCondition
name|m_set_condition
decl_stmt|;
name|mutable
name|PThreadCondition
name|m_reset_condition
decl_stmt|;
name|uint32_t
name|m_bits
decl_stmt|;
name|uint32_t
name|m_validBits
decl_stmt|;
name|uint32_t
name|m_reset_ack_mask
decl_stmt|;
name|private
label|:
name|PThreadEvent
argument_list|(
specifier|const
name|PThreadEvent
operator|&
argument_list|)
expr_stmt|;
comment|// Outlaw copy constructor
name|PThreadEvent
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PThreadEvent
operator|&
name|rhs
operator|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef __PThreadEvent_h__
end_comment

end_unit

