begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Andrew Gallatin  * Copyright (c) 1994-1995 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<alpha/linux/linux.h>
end_include

begin_include
include|#
directive|include
file|<alpha/linux/linux_proto.h>
end_include

begin_include
include|#
directive|include
file|<compat/linux/linux_util.h>
end_include

begin_expr_stmt
name|DUMMY
argument_list|(
name|ptrace
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|syslog
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|vhangup
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|swapoff
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|sysinfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|adjtimex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|create_module
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|init_module
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|delete_module
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|get_kernel_syms
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|quotactl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|bdflush
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|sysfs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|setfsuid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|setfsgid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|query_module
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|nfsservctl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|prctl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|rt_sigpending
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|rt_sigtimedwait
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|rt_sigqueueinfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|capget
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|capset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|sendfile
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|getdtablesize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|gethostname
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|getpagesize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|madvise
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|mincore
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|old_adjtimex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|pciconfig_iobase
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|pciconfig_read
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|pciconfig_write
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|pivot_root
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|recvmsg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|sendmsg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|sethae
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|sigaltstack
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|sigpending
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|socketpair
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|utimes
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

