begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  * Copyright (c) 2012, Joyent, Inc. All rights reserved.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/sdt_impl.h>
end_include

begin_decl_stmt
specifier|static
name|dtrace_pattr_t
name|vtrace_attr
init|=
block|{
block|{
name|DTRACE_STABILITY_UNSTABLE
block|,
name|DTRACE_STABILITY_UNSTABLE
block|,
name|DTRACE_CLASS_ISA
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_UNKNOWN
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_UNKNOWN
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_UNKNOWN
block|}
block|,
block|{
name|DTRACE_STABILITY_UNSTABLE
block|,
name|DTRACE_STABILITY_UNSTABLE
block|,
name|DTRACE_CLASS_ISA
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|dtrace_pattr_t
name|info_attr
init|=
block|{
block|{
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_CLASS_ISA
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_UNKNOWN
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_UNKNOWN
block|}
block|,
block|{
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_CLASS_ISA
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_ISA
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|dtrace_pattr_t
name|fpu_attr
init|=
block|{
block|{
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_CLASS_ISA
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_UNKNOWN
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_UNKNOWN
block|}
block|,
block|{
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_CLASS_CPU
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_ISA
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|dtrace_pattr_t
name|fsinfo_attr
init|=
block|{
block|{
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_CLASS_ISA
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_UNKNOWN
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_UNKNOWN
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_UNKNOWN
block|}
block|,
block|{
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_CLASS_ISA
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|dtrace_pattr_t
name|stab_attr
init|=
block|{
block|{
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_CLASS_ISA
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_UNKNOWN
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_UNKNOWN
block|}
block|,
block|{
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_CLASS_ISA
block|}
block|,
block|{
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_CLASS_ISA
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|dtrace_pattr_t
name|sdt_attr
init|=
block|{
block|{
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_CLASS_ISA
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_UNKNOWN
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_UNKNOWN
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_ISA
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_ISA
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|dtrace_pattr_t
name|xpv_attr
init|=
block|{
block|{
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_STABILITY_EVOLVING
block|,
name|DTRACE_CLASS_PLATFORM
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_UNKNOWN
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_UNKNOWN
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_PLATFORM
block|}
block|,
block|{
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_STABILITY_PRIVATE
block|,
name|DTRACE_CLASS_PLATFORM
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|sdt_provider_t
name|sdt_providers
index|[]
init|=
block|{
block|{
literal|"vtrace"
block|,
literal|"__vtrace_"
block|,
operator|&
name|vtrace_attr
block|,
literal|0
block|}
block|,
block|{
literal|"sysinfo"
block|,
literal|"__cpu_sysinfo_"
block|,
operator|&
name|info_attr
block|,
name|DTRACE_PRIV_USER
block|}
block|,
block|{
literal|"vminfo"
block|,
literal|"__cpu_vminfo_"
block|,
operator|&
name|info_attr
block|,
name|DTRACE_PRIV_USER
block|}
block|,
block|{
literal|"fpuinfo"
block|,
literal|"__fpuinfo_"
block|,
operator|&
name|fpu_attr
block|,
literal|0
block|}
block|,
block|{
literal|"sched"
block|,
literal|"__sched_"
block|,
operator|&
name|stab_attr
block|,
name|DTRACE_PRIV_USER
block|}
block|,
block|{
literal|"proc"
block|,
literal|"__proc_"
block|,
operator|&
name|stab_attr
block|,
name|DTRACE_PRIV_USER
block|}
block|,
block|{
literal|"io"
block|,
literal|"__io_"
block|,
operator|&
name|stab_attr
block|,
literal|0
block|}
block|,
block|{
literal|"mib"
block|,
literal|"__mib_"
block|,
operator|&
name|stab_attr
block|,
literal|0
block|}
block|,
block|{
literal|"fsinfo"
block|,
literal|"__fsinfo_"
block|,
operator|&
name|fsinfo_attr
block|,
literal|0
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"__nfsv3_"
block|,
operator|&
name|stab_attr
block|,
literal|0
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"__nfsv4_"
block|,
operator|&
name|stab_attr
block|,
literal|0
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"__xpv_"
block|,
operator|&
name|xpv_attr
block|,
literal|0
block|}
block|,
block|{
literal|"sysevent"
block|,
literal|"__sysevent_"
block|,
operator|&
name|stab_attr
block|,
literal|0
block|}
block|,
block|{
literal|"sdt"
block|,
name|NULL
block|,
operator|&
name|sdt_attr
block|,
literal|0
block|}
block|,
block|{
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|sdt_argdesc_t
name|sdt_args
index|[]
init|=
block|{
block|{
literal|"sched"
block|,
literal|"wakeup"
block|,
literal|0
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"lwpsinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"wakeup"
block|,
literal|1
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"psinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"dequeue"
block|,
literal|0
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"lwpsinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"dequeue"
block|,
literal|1
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"psinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"dequeue"
block|,
literal|2
block|,
literal|1
block|,
literal|"disp_t *"
block|,
literal|"cpuinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"enqueue"
block|,
literal|0
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"lwpsinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"enqueue"
block|,
literal|1
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"psinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"enqueue"
block|,
literal|2
block|,
literal|1
block|,
literal|"disp_t *"
block|,
literal|"cpuinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"enqueue"
block|,
literal|3
block|,
literal|2
block|,
literal|"int"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"off-cpu"
block|,
literal|0
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"lwpsinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"off-cpu"
block|,
literal|1
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"psinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"tick"
block|,
literal|0
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"lwpsinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"tick"
block|,
literal|1
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"psinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"change-pri"
block|,
literal|0
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"lwpsinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"change-pri"
block|,
literal|1
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"psinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"change-pri"
block|,
literal|2
block|,
literal|1
block|,
literal|"pri_t"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"schedctl-nopreempt"
block|,
literal|0
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"lwpsinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"schedctl-nopreempt"
block|,
literal|1
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"psinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"schedctl-nopreempt"
block|,
literal|2
block|,
literal|1
block|,
literal|"int"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"schedctl-preempt"
block|,
literal|0
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"lwpsinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"schedctl-preempt"
block|,
literal|1
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"psinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"schedctl-yield"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"surrender"
block|,
literal|0
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"lwpsinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"surrender"
block|,
literal|1
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"psinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"cpucaps-sleep"
block|,
literal|0
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"lwpsinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"cpucaps-sleep"
block|,
literal|1
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"psinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"cpucaps-wakeup"
block|,
literal|0
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"lwpsinfo_t *"
block|}
block|,
block|{
literal|"sched"
block|,
literal|"cpucaps-wakeup"
block|,
literal|1
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"psinfo_t *"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"create"
block|,
literal|0
block|,
literal|0
block|,
literal|"proc_t *"
block|,
literal|"psinfo_t *"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"exec"
block|,
literal|0
block|,
literal|0
block|,
literal|"string"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"exec-failure"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"exit"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"fault"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"fault"
block|,
literal|1
block|,
literal|1
block|,
literal|"siginfo_t *"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"lwp-create"
block|,
literal|0
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"lwpsinfo_t *"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"lwp-create"
block|,
literal|1
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"psinfo_t *"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"signal-clear"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"signal-clear"
block|,
literal|1
block|,
literal|1
block|,
literal|"siginfo_t *"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"signal-discard"
block|,
literal|0
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"lwpsinfo_t *"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"signal-discard"
block|,
literal|1
block|,
literal|1
block|,
literal|"proc_t *"
block|,
literal|"psinfo_t *"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"signal-discard"
block|,
literal|2
block|,
literal|2
block|,
literal|"int"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"signal-handle"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"signal-handle"
block|,
literal|1
block|,
literal|1
block|,
literal|"siginfo_t *"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"signal-handle"
block|,
literal|2
block|,
literal|2
block|,
literal|"void (*)(void)"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"signal-send"
block|,
literal|0
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"lwpsinfo_t *"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"signal-send"
block|,
literal|1
block|,
literal|0
block|,
literal|"kthread_t *"
block|,
literal|"psinfo_t *"
block|}
block|,
block|{
literal|"proc"
block|,
literal|"signal-send"
block|,
literal|2
block|,
literal|1
block|,
literal|"int"
block|}
block|,
block|{
literal|"io"
block|,
literal|"start"
block|,
literal|0
block|,
literal|0
block|,
literal|"buf_t *"
block|,
literal|"bufinfo_t *"
block|}
block|,
block|{
literal|"io"
block|,
literal|"start"
block|,
literal|1
block|,
literal|0
block|,
literal|"buf_t *"
block|,
literal|"devinfo_t *"
block|}
block|,
block|{
literal|"io"
block|,
literal|"start"
block|,
literal|2
block|,
literal|0
block|,
literal|"buf_t *"
block|,
literal|"fileinfo_t *"
block|}
block|,
block|{
literal|"io"
block|,
literal|"done"
block|,
literal|0
block|,
literal|0
block|,
literal|"buf_t *"
block|,
literal|"bufinfo_t *"
block|}
block|,
block|{
literal|"io"
block|,
literal|"done"
block|,
literal|1
block|,
literal|0
block|,
literal|"buf_t *"
block|,
literal|"devinfo_t *"
block|}
block|,
block|{
literal|"io"
block|,
literal|"done"
block|,
literal|2
block|,
literal|0
block|,
literal|"buf_t *"
block|,
literal|"fileinfo_t *"
block|}
block|,
block|{
literal|"io"
block|,
literal|"wait-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"buf_t *"
block|,
literal|"bufinfo_t *"
block|}
block|,
block|{
literal|"io"
block|,
literal|"wait-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"buf_t *"
block|,
literal|"devinfo_t *"
block|}
block|,
block|{
literal|"io"
block|,
literal|"wait-start"
block|,
literal|2
block|,
literal|0
block|,
literal|"buf_t *"
block|,
literal|"fileinfo_t *"
block|}
block|,
block|{
literal|"io"
block|,
literal|"wait-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"buf_t *"
block|,
literal|"bufinfo_t *"
block|}
block|,
block|{
literal|"io"
block|,
literal|"wait-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"buf_t *"
block|,
literal|"devinfo_t *"
block|}
block|,
block|{
literal|"io"
block|,
literal|"wait-done"
block|,
literal|2
block|,
literal|0
block|,
literal|"buf_t *"
block|,
literal|"fileinfo_t *"
block|}
block|,
block|{
literal|"mib"
block|,
name|NULL
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"fsinfo"
block|,
name|NULL
block|,
literal|0
block|,
literal|0
block|,
literal|"vnode_t *"
block|,
literal|"fileinfo_t *"
block|}
block|,
block|{
literal|"fsinfo"
block|,
name|NULL
block|,
literal|1
block|,
literal|1
block|,
literal|"int"
block|,
literal|"int"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-getattr-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-getattr-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-getattr-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"GETATTR3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-getattr-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-getattr-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-getattr-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"GETATTR3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-setattr-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-setattr-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-setattr-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"SETATTR3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-setattr-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-setattr-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-setattr-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"SETATTR3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-lookup-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-lookup-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-lookup-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"LOOKUP3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-lookup-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-lookup-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-lookup-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"LOOKUP3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-access-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-access-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-access-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"ACCESS3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-access-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-access-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-access-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"ACCESS3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-commit-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-commit-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-commit-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"COMMIT3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-commit-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-commit-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-commit-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"COMMIT3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-create-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-create-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-create-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"CREATE3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-create-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-create-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-create-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"CREATE3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-fsinfo-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-fsinfo-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-fsinfo-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"FSINFO3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-fsinfo-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-fsinfo-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-fsinfo-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"FSINFO3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-fsstat-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-fsstat-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-fsstat-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"FSSTAT3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-fsstat-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-fsstat-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-fsstat-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"FSSTAT3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-link-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-link-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-link-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"LINK3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-link-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-link-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-link-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"LINK3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-mkdir-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-mkdir-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-mkdir-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"MKDIR3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-mkdir-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-mkdir-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-mkdir-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"MKDIR3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-mknod-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-mknod-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-mknod-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"MKNOD3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-mknod-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-mknod-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-mknod-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"MKNOD3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-null-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-null-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-null-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-null-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-pathconf-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-pathconf-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-pathconf-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"PATHCONF3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-pathconf-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-pathconf-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-pathconf-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"PATHCONF3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-read-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-read-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-read-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"READ3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-read-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-read-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-read-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"READ3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readdir-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readdir-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readdir-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"READDIR3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readdir-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readdir-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readdir-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"READDIR3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readdirplus-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readdirplus-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readdirplus-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"READDIRPLUS3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readdirplus-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readdirplus-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readdirplus-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"READDIRPLUS3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readlink-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readlink-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readlink-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"READLINK3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readlink-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readlink-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-readlink-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"READLINK3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-remove-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-remove-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-remove-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"REMOVE3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-remove-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-remove-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-remove-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"REMOVE3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-rename-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-rename-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-rename-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"RENAME3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-rename-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-rename-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-rename-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"RENAME3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-rmdir-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-rmdir-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-rmdir-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"RMDIR3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-rmdir-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-rmdir-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-rmdir-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"RMDIR3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-setattr-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-setattr-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-setattr-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"SETATTR3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-setattr-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-setattr-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-setattr-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"SETATTR3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-symlink-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-symlink-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-symlink-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"SYMLINK3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-symlink-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-symlink-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-symlink-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"SYMLINK3res *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-write-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-write-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-write-start"
block|,
literal|2
block|,
literal|3
block|,
literal|"WRITE3args *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-write-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-write-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"nfsv3oparg_t *"
block|,
literal|"nfsv3opinfo_t *"
block|}
block|,
block|{
literal|"nfsv3"
block|,
literal|"op-write-done"
block|,
literal|2
block|,
literal|3
block|,
literal|"WRITE3res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"null-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"null-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct svc_req *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"compound-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"compound-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"compound-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"COMPOUND4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"compound-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"compound-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"compound-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"COMPOUND4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-access-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-access-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-access-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"ACCESS4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-access-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-access-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-access-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"ACCESS4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-close-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-close-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-close-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"CLOSE4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-close-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-close-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-close-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"CLOSE4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-commit-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-commit-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-commit-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"COMMIT4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-commit-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-commit-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-commit-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"COMMIT4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-create-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-create-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-create-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"CREATE4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-create-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-create-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-create-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"CREATE4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-delegpurge-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-delegpurge-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-delegpurge-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"DELEGPURGE4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-delegpurge-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-delegpurge-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-delegpurge-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"DELEGPURGE4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-delegreturn-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-delegreturn-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-delegreturn-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"DELEGRETURN4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-delegreturn-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-delegreturn-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-delegreturn-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"DELEGRETURN4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-getattr-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-getattr-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-getattr-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"GETATTR4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-getattr-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-getattr-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-getattr-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"GETATTR4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-getfh-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-getfh-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-getfh-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-getfh-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-getfh-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"GETFH4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-link-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-link-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-link-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"LINK4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-link-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-link-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-link-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"LINK4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lock-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lock-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lock-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"LOCK4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lock-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lock-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lock-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"LOCK4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lockt-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lockt-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lockt-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"LOCKT4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lockt-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lockt-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lockt-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"LOCKT4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-locku-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-locku-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-locku-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"LOCKU4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-locku-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-locku-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-locku-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"LOCKU4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lookup-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lookup-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lookup-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"LOOKUP4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lookup-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lookup-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lookup-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"LOOKUP4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lookupp-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lookupp-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lookupp-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lookupp-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-lookupp-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"LOOKUPP4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-nverify-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-nverify-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-nverify-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"NVERIFY4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-nverify-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-nverify-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-nverify-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"NVERIFY4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"OPEN4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"OPEN4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-confirm-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-confirm-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-confirm-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"OPEN_CONFIRM4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-confirm-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-confirm-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-confirm-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"OPEN_CONFIRM4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-downgrade-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-downgrade-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-downgrade-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"OPEN_DOWNGRADE4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-downgrade-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-downgrade-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-open-downgrade-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"OPEN_DOWNGRADE4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-openattr-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-openattr-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-openattr-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"OPENATTR4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-openattr-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-openattr-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-openattr-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"OPENATTR4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-putfh-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-putfh-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-putfh-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"PUTFH4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-putfh-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-putfh-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-putfh-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"PUTFH4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-putpubfh-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-putpubfh-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-putpubfh-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-putpubfh-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-putpubfh-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"PUTPUBFH4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-putrootfh-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-putrootfh-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-putrootfh-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-putrootfh-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-putrootfh-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"PUTROOTFH4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-read-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-read-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-read-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"READ4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-read-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-read-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-read-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"READ4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-readdir-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-readdir-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-readdir-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"READDIR4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-readdir-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-readdir-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-readdir-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"READDIR4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-readlink-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-readlink-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-readlink-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-readlink-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-readlink-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"READLINK4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-release-lockowner-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-release-lockowner-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-release-lockowner-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"RELEASE_LOCKOWNER4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-release-lockowner-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-release-lockowner-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-release-lockowner-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"RELEASE_LOCKOWNER4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-remove-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-remove-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-remove-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"REMOVE4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-remove-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-remove-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-remove-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"REMOVE4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-rename-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-rename-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-rename-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"RENAME4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-rename-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-rename-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-rename-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"RENAME4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-renew-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-renew-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-renew-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"RENEW4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-renew-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-renew-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-renew-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"RENEW4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-restorefh-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-restorefh-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-restorefh-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-restorefh-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-restorefh-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"RESTOREFH4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-savefh-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-savefh-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-savefh-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-savefh-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-savefh-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"SAVEFH4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-secinfo-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-secinfo-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-secinfo-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"SECINFO4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-secinfo-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-secinfo-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-secinfo-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"SECINFO4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setattr-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setattr-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setattr-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"SETATTR4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setattr-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setattr-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setattr-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"SETATTR4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setclientid-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setclientid-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setclientid-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"SETCLIENTID4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setclientid-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setclientid-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setclientid-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"SETCLIENTID4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setclientid-confirm-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setclientid-confirm-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setclientid-confirm-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"SETCLIENTID_CONFIRM4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setclientid-confirm-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setclientid-confirm-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-setclientid-confirm-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"SETCLIENTID_CONFIRM4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-verify-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-verify-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-verify-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"VERIFY4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-verify-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-verify-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-verify-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"VERIFY4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-write-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-write-start"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-write-start"
block|,
literal|2
block|,
literal|1
block|,
literal|"WRITE4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-write-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-write-done"
block|,
literal|1
block|,
literal|0
block|,
literal|"struct compound_state *"
block|,
literal|"nfsv4opinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"op-write-done"
block|,
literal|2
block|,
literal|1
block|,
literal|"WRITE4res *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"cb-recall-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"rfs4_client_t *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"cb-recall-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"rfs4_deleg_state_t *"
block|,
literal|"nfsv4cbinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"cb-recall-start"
block|,
literal|2
block|,
literal|2
block|,
literal|"CB_RECALL4args *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"cb-recall-done"
block|,
literal|0
block|,
literal|0
block|,
literal|"rfs4_client_t *"
block|,
literal|"conninfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"cb-recall-done"
block|,
literal|1
block|,
literal|1
block|,
literal|"rfs4_deleg_state_t *"
block|,
literal|"nfsv4cbinfo_t *"
block|}
block|,
block|{
literal|"nfsv4"
block|,
literal|"cb-recall-done"
block|,
literal|2
block|,
literal|2
block|,
literal|"CB_RECALL4res *"
block|}
block|,
block|{
literal|"sysevent"
block|,
literal|"post"
block|,
literal|0
block|,
literal|0
block|,
literal|"evch_bind_t *"
block|,
literal|"syseventchaninfo_t *"
block|}
block|,
block|{
literal|"sysevent"
block|,
literal|"post"
block|,
literal|1
block|,
literal|1
block|,
literal|"sysevent_impl_t *"
block|,
literal|"syseventinfo_t *"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"add-to-physmap-end"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"add-to-physmap-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"domid_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"add-to-physmap-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"uint_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"add-to-physmap-start"
block|,
literal|2
block|,
literal|2
block|,
literal|"ulong_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"add-to-physmap-start"
block|,
literal|3
block|,
literal|3
block|,
literal|"ulong_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"decrease-reservation-end"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"decrease-reservation-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"domid_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"decrease-reservation-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"ulong_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"decrease-reservation-start"
block|,
literal|2
block|,
literal|2
block|,
literal|"uint_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"decrease-reservation-start"
block|,
literal|3
block|,
literal|3
block|,
literal|"ulong_t *"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"dom-create-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"xen_domctl_t *"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"dom-destroy-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"domid_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"dom-pause-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"domid_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"dom-unpause-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"domid_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"dom-create-end"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"dom-destroy-end"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"dom-pause-end"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"dom-unpause-end"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"evtchn-op-end"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"evtchn-op-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"evtchn-op-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"void *"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"increase-reservation-end"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"increase-reservation-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"domid_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"increase-reservation-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"ulong_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"increase-reservation-start"
block|,
literal|2
block|,
literal|2
block|,
literal|"uint_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"increase-reservation-start"
block|,
literal|3
block|,
literal|3
block|,
literal|"ulong_t *"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmap-end"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmap-entry"
block|,
literal|0
block|,
literal|0
block|,
literal|"ulong_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmap-entry"
block|,
literal|1
block|,
literal|1
block|,
literal|"ulong_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmap-entry"
block|,
literal|2
block|,
literal|2
block|,
literal|"ulong_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmap-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"domid_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmap-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmap-start"
block|,
literal|2
block|,
literal|2
block|,
literal|"privcmd_mmap_entry_t *"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmapbatch-end"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmapbatch-end"
block|,
literal|1
block|,
literal|1
block|,
literal|"struct seg *"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmapbatch-end"
block|,
literal|2
block|,
literal|2
block|,
literal|"caddr_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmapbatch-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"domid_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmapbatch-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmapbatch-start"
block|,
literal|2
block|,
literal|2
block|,
literal|"caddr_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmu-ext-op-end"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmu-ext-op-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmu-ext-op-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"struct mmuext_op *"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmu-update-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmu-update-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmu-update-start"
block|,
literal|2
block|,
literal|2
block|,
literal|"mmu_update_t *"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"mmu-update-end"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"populate-physmap-end"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"populate-physmap-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"domid_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"populate-physmap-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"ulong_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"populate-physmap-start"
block|,
literal|2
block|,
literal|2
block|,
literal|"ulong_t *"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"set-memory-map-end"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"set-memory-map-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"domid_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"set-memory-map-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"set-memory-map-start"
block|,
literal|2
block|,
literal|2
block|,
literal|"struct xen_memory_map *"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"setvcpucontext-end"
block|,
literal|0
block|,
literal|0
block|,
literal|"int"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"setvcpucontext-start"
block|,
literal|0
block|,
literal|0
block|,
literal|"domid_t"
block|}
block|,
block|{
literal|"xpv"
block|,
literal|"setvcpucontext-start"
block|,
literal|1
block|,
literal|1
block|,
literal|"vcpu_guest_context_t *"
block|}
block|,
block|{
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|int
name|sdt_mode
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|dtrace_id_t
name|id
parameter_list|,
name|void
modifier|*
name|parg
parameter_list|)
block|{
comment|/* 	 * We tell DTrace that we're in kernel mode, that the firing needs to 	 * be dropped for anything that doesn't have necessary privileges, and 	 * that it needs to be restricted for anything that has restricted 	 * (i.e., not all-zone) privileges. 	 */
return|return
operator|(
name|DTRACE_MODE_KERNEL
operator||
name|DTRACE_MODE_NOPRIV_DROP
operator||
name|DTRACE_MODE_LIMITEDPRIV_RESTRICT
operator|)
return|;
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|sdt_getargdesc
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|dtrace_id_t
name|id
parameter_list|,
name|void
modifier|*
name|parg
parameter_list|,
name|dtrace_argdesc_t
modifier|*
name|desc
parameter_list|)
block|{
name|sdt_probe_t
modifier|*
name|sdp
init|=
name|parg
decl_stmt|;
name|int
name|i
decl_stmt|;
name|desc
operator|->
name|dtargd_native
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
name|desc
operator|->
name|dtargd_xlate
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|sdt_args
index|[
name|i
index|]
operator|.
name|sda_provider
operator|!=
name|NULL
condition|;
name|i
operator|++
control|)
block|{
name|sdt_argdesc_t
modifier|*
name|a
init|=
operator|&
name|sdt_args
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|sdp
operator|->
name|sdp_provider
operator|->
name|sdtp_name
argument_list|,
name|a
operator|->
name|sda_provider
argument_list|)
operator|!=
literal|0
condition|)
continue|continue;
if|if
condition|(
name|a
operator|->
name|sda_name
operator|!=
name|NULL
operator|&&
name|strcmp
argument_list|(
name|sdp
operator|->
name|sdp_name
argument_list|,
name|a
operator|->
name|sda_name
argument_list|)
operator|!=
literal|0
condition|)
continue|continue;
if|if
condition|(
name|desc
operator|->
name|dtargd_ndx
operator|!=
name|a
operator|->
name|sda_ndx
condition|)
continue|continue;
if|if
condition|(
name|a
operator|->
name|sda_native
operator|!=
name|NULL
condition|)
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|desc
operator|->
name|dtargd_native
argument_list|,
name|a
operator|->
name|sda_native
argument_list|)
expr_stmt|;
if|if
condition|(
name|a
operator|->
name|sda_xlate
operator|!=
name|NULL
condition|)
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|desc
operator|->
name|dtargd_xlate
argument_list|,
name|a
operator|->
name|sda_xlate
argument_list|)
expr_stmt|;
name|desc
operator|->
name|dtargd_mapping
operator|=
name|a
operator|->
name|sda_mapping
expr_stmt|;
return|return;
block|}
name|desc
operator|->
name|dtargd_ndx
operator|=
name|DTRACE_ARGNONE
expr_stmt|;
block|}
end_function

end_unit

