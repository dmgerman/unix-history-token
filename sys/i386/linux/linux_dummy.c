begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994-1995 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<i386/linux/linux.h>
end_include

begin_include
include|#
directive|include
file|<i386/linux/linux_proto.h>
end_include

begin_define
define|#
directive|define
name|DUMMY
parameter_list|(
name|s
parameter_list|)
define|\
value|int									\ linux_ ## s(struct proc *p, struct linux_ ## s ## _args *args)		\ {									\ 	return (unsupported_msg(p, #s));				\ }									\ struct __hack
end_define

begin_function
specifier|static
name|int
name|unsupported_msg
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
block|{
name|printf
argument_list|(
literal|"linux: syscall %s is obsoleted or not implemented (pid=%ld)\n"
argument_list|,
name|fname
argument_list|,
operator|(
name|long
operator|)
name|p
operator|->
name|p_pid
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|DUMMY
argument_list|(
name|setup
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|DUMMY
argument_list|(
argument|break
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|stat
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|mount
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|umount
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|stime
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|fstat
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|stty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|gtty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|ftime
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|prof
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|umount2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|lock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|mpx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|ulimit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|olduname
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|ksyslog
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|uname
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
name|idle
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|vm86old
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
name|afs_syscall
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
name|getsid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|sysctl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|getresuid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|vm86
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
name|getresgid
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
name|getpmsg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|putpmsg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|ugetrlimit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|mmap2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|truncate64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|ftruncate64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|stat64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|lstat64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|fstat64
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

