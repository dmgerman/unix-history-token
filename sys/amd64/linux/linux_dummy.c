begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Dmitry Chagin  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"opt_compat.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/sdt.h>
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
file|<amd64/linux/linux.h>
end_include

begin_include
include|#
directive|include
file|<amd64/linux/linux_proto.h>
end_include

begin_include
include|#
directive|include
file|<compat/linux/linux_dtrace.h>
end_include

begin_include
include|#
directive|include
file|<compat/linux/linux_util.h>
end_include

begin_comment
comment|/* DTrace init */
end_comment

begin_expr_stmt
name|LIN_SDT_PROVIDER_DECLARE
argument_list|(
name|LINUX_DTRACE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|UNIMPLEMENTED
argument_list|(
name|afs_syscall
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|UNIMPLEMENTED
argument_list|(
name|create_module
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* added in linux 1.0 removed in 2.6 */
end_comment

begin_expr_stmt
name|UNIMPLEMENTED
argument_list|(
name|epoll_ctl_old
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|UNIMPLEMENTED
argument_list|(
name|epoll_wait_old
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|UNIMPLEMENTED
argument_list|(
name|get_kernel_syms
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* added in linux 1.0 removed in 2.6 */
end_comment

begin_expr_stmt
name|UNIMPLEMENTED
argument_list|(
name|get_thread_area
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|UNIMPLEMENTED
argument_list|(
name|getpmsg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|UNIMPLEMENTED
argument_list|(
name|nfsservctl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* added in linux 2.2 removed in 3.1 */
end_comment

begin_expr_stmt
name|UNIMPLEMENTED
argument_list|(
name|putpmsg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|UNIMPLEMENTED
argument_list|(
name|query_module
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* added in linux 2.2 removed in 2.6 */
end_comment

begin_expr_stmt
name|UNIMPLEMENTED
argument_list|(
name|security
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|UNIMPLEMENTED
argument_list|(
name|set_thread_area
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|UNIMPLEMENTED
argument_list|(
name|tuxcall
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|UNIMPLEMENTED
argument_list|(
name|uselib
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|UNIMPLEMENTED
argument_list|(
name|vserver
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
name|sendfile
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
name|sysfs
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
name|pivot_root
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
name|swapoff
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
name|quotactl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|lookup_dcookie
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|remap_file_pages
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|semtimedop
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|mbind
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|get_mempolicy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|set_mempolicy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|mq_open
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|mq_unlink
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|mq_timedsend
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|mq_timedreceive
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|mq_notify
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|mq_getsetattr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|kexec_load
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 2.6.11: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|add_key
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|request_key
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|keyctl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 2.6.13: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|ioprio_set
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|ioprio_get
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|inotify_init
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|inotify_add_watch
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|inotify_rm_watch
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 2.6.16: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|migrate_pages
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|unshare
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 2.6.17: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|splice
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|tee
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|sync_file_range
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|vmsplice
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 2.6.18: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|move_pages
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 2.6.22: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|signalfd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 2.6.27: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|signalfd4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|inotify_init1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 2.6.31: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|perf_event_open
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 2.6.38: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|fanotify_init
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|fanotify_mark
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 2.6.39: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|name_to_handle_at
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|open_by_handle_at
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|clock_adjtime
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 3.0: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|setns
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|getcpu
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 3.2: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|process_vm_readv
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|process_vm_writev
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 3.5: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|kcmp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 3.8: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|finit_module
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|sched_setattr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|sched_getattr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 3.14: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|renameat2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 3.15: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|seccomp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|memfd_create
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|kexec_file_load
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 3.18: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|bpf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 3.19: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|execveat
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 4.2: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|userfaultfd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 4.3: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|membarrier
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 4.4: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|mlock2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 4.5: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|copy_file_range
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 4.6: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|preadv2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|pwritev2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* linux 4.8: */
end_comment

begin_expr_stmt
name|DUMMY
argument_list|(
name|pkey_mprotect
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|pkey_alloc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY
argument_list|(
name|pkey_free
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|DUMMY_XATTR
parameter_list|(
name|s
parameter_list|)
define|\
value|int								\ linux_ ## s ## xattr(						\     struct thread *td, struct linux_ ## s ## xattr_args *arg)	\ {								\ 								\ 	return (ENOATTR);					\ }
end_define

begin_expr_stmt
name|DUMMY_XATTR
argument_list|(
name|set
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY_XATTR
argument_list|(
name|lset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY_XATTR
argument_list|(
name|fset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY_XATTR
argument_list|(
name|get
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY_XATTR
argument_list|(
name|lget
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY_XATTR
argument_list|(
name|fget
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY_XATTR
argument_list|(
name|list
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY_XATTR
argument_list|(
name|llist
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY_XATTR
argument_list|(
name|flist
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY_XATTR
argument_list|(
name|remove
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY_XATTR
argument_list|(
name|lremove
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DUMMY_XATTR
argument_list|(
name|fremove
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

