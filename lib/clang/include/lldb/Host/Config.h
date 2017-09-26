begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// $FreeBSD$
end_comment

begin_comment
comment|//===-- Config.h -----------------------------------------------*- C++ -*-===//
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

begin_define
define|#
directive|define
name|LLDB_CONFIG_TERMIOS_SUPPORTED
end_define

begin_comment
comment|/* #undef LLDB_DISABLE_POSIX */
end_comment

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
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PROCESS_VM_READV
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_NR_PROCESS_VM_READV
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef LLDB_HOST_CONFIG_H
end_comment

end_unit

