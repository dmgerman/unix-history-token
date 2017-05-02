begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Config.h ------------------------------------------------*- C++ -*-===//
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
name|LLDB_HOST_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_HOST_CONFIG_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_comment
comment|// This block of code only exists to keep the Xcode project working in the
end_comment

begin_comment
comment|// absence of a configuration step.
end_comment

begin_define
define|#
directive|define
name|LLDB_CONFIG_TERMIOS_SUPPORTED
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_EVENT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PPOLL
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|This file is only used by the Xcode build.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef LLDB_HOST_CONFIG_H
end_comment

end_unit

