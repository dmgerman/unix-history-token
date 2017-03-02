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
comment|//--
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_comment
comment|// 1 = Show debug process attach modal dialog, 0 = do not show
end_comment

begin_comment
comment|// For windows only ATM, other OS's code is an infinite loop which a debugger
end_comment

begin_comment
comment|// must change a value to continue
end_comment

begin_define
define|#
directive|define
name|MICONFIG_DEBUG_SHOW_ATTACH_DBG_DLG
value|0
end_define

begin_comment
comment|// 1 = Write to MI's Log file warnings about commands that did not handle
end_comment

begin_comment
comment|// arguments or
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

end_unit

