begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/System/Alarm.h - Alarm Generation support  ----------*- C++ -*-===//
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
comment|// This file provides an operating system independent interface to alarm(2)
end_comment

begin_comment
comment|// type functionality. The Alarm class allows a one-shot alarm to be set up
end_comment

begin_comment
comment|// at some number of seconds in the future. When the alarm triggers, a method
end_comment

begin_comment
comment|// is called to process the event
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
name|LLVM_SYSTEM_ALARM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SYSTEM_ALARM_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|/// This function registers an alarm to trigger some number of \p seconds in
comment|/// the future. When that time arrives, the AlarmStatus function will begin
comment|/// to return 1 instead of 0. The user must poll the status of the alarm by
comment|/// making occasional calls to AlarmStatus. If the user sends an interrupt
comment|/// signal, AlarmStatus will begin returning -1, even if the alarm event
comment|/// occurred.
comment|/// @returns nothing
name|void
name|SetupAlarm
parameter_list|(
name|unsigned
name|seconds
comment|///< Number of seconds in future when alarm arrives
parameter_list|)
function_decl|;
comment|/// This function terminates the alarm previously set up
comment|/// @returns nothing
name|void
name|TerminateAlarm
parameter_list|()
function_decl|;
comment|/// This function acquires the status of the alarm.
comment|/// @returns -1=cancelled, 0=untriggered, 1=triggered
name|int
name|AlarmStatus
parameter_list|()
function_decl|;
comment|/// Sleep for n seconds. Warning: mixing calls to Sleep() and other *Alarm
comment|/// calls may be a bad idea on some platforms (source: Linux man page).
comment|/// @returns nothing.
name|void
name|Sleep
parameter_list|(
name|unsigned
name|n
parameter_list|)
function_decl|;
block|}
comment|// End sys namespace
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

