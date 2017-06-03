begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Uio.h ---------------------------------------------------*- C++ -*-===//
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
name|liblldb_Host_linux_Uio_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Host_linux_Uio_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/Config.h"
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_comment
comment|// We shall provide our own implementation of process_vm_readv if it is not
end_comment

begin_comment
comment|// present
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_PROCESS_VM_READV
end_if

begin_decl_stmt
name|ssize_t
name|process_vm_readv
argument_list|(
operator|::
name|pid_t
name|pid
argument_list|,
specifier|const
expr|struct
name|iovec
operator|*
name|local_iov
argument_list|,
name|unsigned
name|long
name|liovcnt
argument_list|,
specifier|const
expr|struct
name|iovec
operator|*
name|remote_iov
argument_list|,
name|unsigned
name|long
name|riovcnt
argument_list|,
name|unsigned
name|long
name|flags
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Host_linux_Uio_h_
end_comment

end_unit

