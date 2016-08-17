begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Ptrace.h ------------------------------------------------*- C++ -*-===//
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
comment|// This file defines ptrace functions& structures
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_Host_linux_Ptrace_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Host_linux_Ptrace_h_
end_define

begin_include
include|#
directive|include
file|<sys/ptrace.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__GLIBC__
end_ifndef

begin_typedef
typedef|typedef
name|int
name|__ptrace_request
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEBUG_PTRACE_MAXBYTES
value|20
end_define

begin_comment
comment|// Support ptrace extensions even when compiled without required kernel support
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PTRACE_GETREGS
end_ifndef

begin_define
define|#
directive|define
name|PTRACE_GETREGS
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTRACE_SETREGS
end_ifndef

begin_define
define|#
directive|define
name|PTRACE_SETREGS
value|13
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTRACE_GETFPREGS
end_ifndef

begin_define
define|#
directive|define
name|PTRACE_GETFPREGS
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTRACE_SETFPREGS
end_ifndef

begin_define
define|#
directive|define
name|PTRACE_SETFPREGS
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTRACE_GETREGSET
end_ifndef

begin_define
define|#
directive|define
name|PTRACE_GETREGSET
value|0x4204
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTRACE_SETREGSET
end_ifndef

begin_define
define|#
directive|define
name|PTRACE_SETREGSET
value|0x4205
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTRACE_GET_THREAD_AREA
end_ifndef

begin_define
define|#
directive|define
name|PTRACE_GET_THREAD_AREA
value|25
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTRACE_ARCH_PRCTL
end_ifndef

begin_define
define|#
directive|define
name|PTRACE_ARCH_PRCTL
value|30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ARCH_GET_FS
end_ifndef

begin_define
define|#
directive|define
name|ARCH_SET_GS
value|0x1001
end_define

begin_define
define|#
directive|define
name|ARCH_SET_FS
value|0x1002
end_define

begin_define
define|#
directive|define
name|ARCH_GET_FS
value|0x1003
end_define

begin_define
define|#
directive|define
name|ARCH_GET_GS
value|0x1004
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LLDB_PTRACE_NT_ARM_TLS
value|0x401
end_define

begin_comment
comment|// ARM TLS register
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Host_linux_Ptrace_h_
end_comment

end_unit

