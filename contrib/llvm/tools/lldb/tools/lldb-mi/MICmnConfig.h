begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnConfig.h -------------------------------------------*- C++ -*-===//
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
comment|//++
end_comment

begin_comment
comment|// File:        MICmnConfig.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    Common defines to guide feature inclusion at compile time.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Environment: Compilers:  Visual C++ 12.
end_comment

begin_comment
comment|//                          gcc (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
end_comment

begin_comment
comment|//              Libraries:  See MIReadmetxt.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Copyright:   None.
end_comment

begin_comment
comment|//--
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_comment
comment|// 1 = Yes compile MI Driver version, 0 = compile original LLDB driver code only.
end_comment

begin_comment
comment|// 0 was mainly just for testing purposes and so may be removed at a later time.
end_comment

begin_define
define|#
directive|define
name|MICONFIG_COMPILE_MIDRIVER_VERSION
value|1
end_define

begin_comment
comment|// 1 = Show debug process attach modal dialog, 0 = do not show
end_comment

begin_comment
comment|// For windows only ATM, other OS's code is an infinite loop which a debugger must change a value to continue
end_comment

begin_define
define|#
directive|define
name|MICONFIG_DEBUG_SHOW_ATTACH_DBG_DLG
value|0
end_define

begin_comment
comment|// 1 = Compile in and init LLDB driver code alongside MI version, 0 = do not compile in
end_comment

begin_define
define|#
directive|define
name|MICONFIG_COMPILE_MIDRIVER_WITH_LLDBDRIVER
value|1
end_define

begin_comment
comment|// 1 = Give runtime our own custom buffer, 0 = Use runtime managed buffer
end_comment

begin_define
define|#
directive|define
name|MICONFIG_CREATE_OWN_STDIN_BUFFER
value|0
end_define

begin_comment
comment|// 1 = Use the MI driver regardless of --interpreter, 0 = require --interpreter argument
end_comment

begin_comment
comment|// This depends on MICONFIG_COMPILE_MIDRIVER_WITH_LLDBDRIVER
end_comment

begin_define
define|#
directive|define
name|MICONFIG_DEFAULT_TO_MI_DRIVER
value|0
end_define

begin_comment
comment|// 1 = Check for stdin before we issue blocking read, 0 = issue blocking call always
end_comment

begin_define
define|#
directive|define
name|MICONFIG_POLL_FOR_STD_IN
value|1
end_define

begin_comment
comment|// 1 = Write to MI's Log file warnings about commands that did not handle arguments or
end_comment

begin_comment
comment|// options present to them by the driver's client, 0 = no warnings given
end_comment

begin_define
define|#
directive|define
name|MICONFIG_GIVE_WARNING_CMD_ARGS_NOT_HANDLED
value|1
end_define

begin_comment
comment|// 1 = Enable MI Driver in MI mode to create a local debug session, 0 = Report "Not implemented"
end_comment

begin_define
define|#
directive|define
name|MICONFIG_ENABLE_MI_DRIVER_MI_MODE_CMDLINE_ARG_EXECUTABLE_DEBUG_SESSION
value|0
end_define

end_unit

