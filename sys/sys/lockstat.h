begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008-2009 Stacey Son<sson@FreeBSD.org>   *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * DTrace lockstat provider definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_LOCKSTAT_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_LOCKSTAT_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Spin Locks  */
end_comment

begin_define
define|#
directive|define
name|LS_MTX_SPIN_LOCK_ACQUIRE
value|0
end_define

begin_define
define|#
directive|define
name|LS_MTX_SPIN_UNLOCK_RELEASE
value|1
end_define

begin_define
define|#
directive|define
name|LS_MTX_SPIN_LOCK_SPIN
value|2
end_define

begin_comment
comment|/*  * Adaptive Locks  */
end_comment

begin_define
define|#
directive|define
name|LS_MTX_LOCK_ACQUIRE
value|3
end_define

begin_define
define|#
directive|define
name|LS_MTX_UNLOCK_RELEASE
value|4
end_define

begin_define
define|#
directive|define
name|LS_MTX_LOCK_SPIN
value|5
end_define

begin_define
define|#
directive|define
name|LS_MTX_LOCK_BLOCK
value|6
end_define

begin_define
define|#
directive|define
name|LS_MTX_TRYLOCK_ACQUIRE
value|7
end_define

begin_comment
comment|/*  * Reader/Writer Locks  */
end_comment

begin_define
define|#
directive|define
name|LS_RW_RLOCK_ACQUIRE
value|8
end_define

begin_define
define|#
directive|define
name|LS_RW_RUNLOCK_RELEASE
value|9
end_define

begin_define
define|#
directive|define
name|LS_RW_WLOCK_ACQUIRE
value|10
end_define

begin_define
define|#
directive|define
name|LS_RW_WUNLOCK_RELEASE
value|11
end_define

begin_define
define|#
directive|define
name|LS_RW_RLOCK_SPIN
value|12
end_define

begin_define
define|#
directive|define
name|LS_RW_RLOCK_BLOCK
value|13
end_define

begin_define
define|#
directive|define
name|LS_RW_WLOCK_SPIN
value|14
end_define

begin_define
define|#
directive|define
name|LS_RW_WLOCK_BLOCK
value|15
end_define

begin_define
define|#
directive|define
name|LS_RW_TRYUPGRADE_UPGRADE
value|16
end_define

begin_define
define|#
directive|define
name|LS_RW_DOWNGRADE_DOWNGRADE
value|17
end_define

begin_comment
comment|/*  * Shared/Exclusive Locks  */
end_comment

begin_define
define|#
directive|define
name|LS_SX_SLOCK_ACQUIRE
value|18
end_define

begin_define
define|#
directive|define
name|LS_SX_SUNLOCK_RELEASE
value|19
end_define

begin_define
define|#
directive|define
name|LS_SX_XLOCK_ACQUIRE
value|20
end_define

begin_define
define|#
directive|define
name|LS_SX_XUNLOCK_RELEASE
value|21
end_define

begin_define
define|#
directive|define
name|LS_SX_SLOCK_SPIN
value|22
end_define

begin_define
define|#
directive|define
name|LS_SX_SLOCK_BLOCK
value|23
end_define

begin_define
define|#
directive|define
name|LS_SX_XLOCK_SPIN
value|24
end_define

begin_define
define|#
directive|define
name|LS_SX_XLOCK_BLOCK
value|25
end_define

begin_define
define|#
directive|define
name|LS_SX_TRYUPGRADE_UPGRADE
value|26
end_define

begin_define
define|#
directive|define
name|LS_SX_DOWNGRADE_DOWNGRADE
value|27
end_define

begin_comment
comment|/*   * Thread Locks  */
end_comment

begin_define
define|#
directive|define
name|LS_THREAD_LOCK_SPIN
value|28
end_define

begin_comment
comment|/*  * Lockmanager Locks   *  According to locking(9) Lockmgr locks are "Largely deprecated"  *  so no support for these have been added in the lockstat provider.  */
end_comment

begin_define
define|#
directive|define
name|LS_NPROBES
value|29
end_define

begin_define
define|#
directive|define
name|LS_MTX_LOCK
value|"mtx_lock"
end_define

begin_define
define|#
directive|define
name|LS_MTX_UNLOCK
value|"mtx_unlock"
end_define

begin_define
define|#
directive|define
name|LS_MTX_SPIN_LOCK
value|"mtx_lock_spin"
end_define

begin_define
define|#
directive|define
name|LS_MTX_SPIN_UNLOCK
value|"mtx_unlock_spin"
end_define

begin_define
define|#
directive|define
name|LS_MTX_TRYLOCK
value|"mtx_trylock"
end_define

begin_define
define|#
directive|define
name|LS_RW_RLOCK
value|"rw_rlock"
end_define

begin_define
define|#
directive|define
name|LS_RW_WLOCK
value|"rw_wlock"
end_define

begin_define
define|#
directive|define
name|LS_RW_RUNLOCK
value|"rw_runlock"
end_define

begin_define
define|#
directive|define
name|LS_RW_WUNLOCK
value|"rw_wunlock"
end_define

begin_define
define|#
directive|define
name|LS_RW_TRYUPGRADE
value|"rw_try_upgrade"
end_define

begin_define
define|#
directive|define
name|LS_RW_DOWNGRADE
value|"rw_downgrade"
end_define

begin_define
define|#
directive|define
name|LS_SX_SLOCK
value|"sx_slock"
end_define

begin_define
define|#
directive|define
name|LS_SX_XLOCK
value|"sx_xlock"
end_define

begin_define
define|#
directive|define
name|LS_SX_SUNLOCK
value|"sx_sunlock"
end_define

begin_define
define|#
directive|define
name|LS_SX_XUNLOCK
value|"sx_xunlock"
end_define

begin_define
define|#
directive|define
name|LS_SX_TRYUPGRADE
value|"sx_try_upgrade"
end_define

begin_define
define|#
directive|define
name|LS_SX_DOWNGRADE
value|"sx_downgrade"
end_define

begin_define
define|#
directive|define
name|LS_THREAD_LOCK
value|"thread_lock"
end_define

begin_define
define|#
directive|define
name|LS_ACQUIRE
value|"acquire"
end_define

begin_define
define|#
directive|define
name|LS_RELEASE
value|"release"
end_define

begin_define
define|#
directive|define
name|LS_SPIN
value|"spin"
end_define

begin_define
define|#
directive|define
name|LS_BLOCK
value|"block"
end_define

begin_define
define|#
directive|define
name|LS_UPGRADE
value|"upgrade"
end_define

begin_define
define|#
directive|define
name|LS_DOWNGRADE
value|"downgrade"
end_define

begin_define
define|#
directive|define
name|LS_TYPE_ADAPTIVE
value|"adaptive"
end_define

begin_define
define|#
directive|define
name|LS_TYPE_SPIN
value|"spin"
end_define

begin_define
define|#
directive|define
name|LS_TYPE_THREAD
value|"thread"
end_define

begin_define
define|#
directive|define
name|LS_TYPE_RW
value|"rw"
end_define

begin_define
define|#
directive|define
name|LS_TYPE_SX
value|"sx"
end_define

begin_define
define|#
directive|define
name|LSA_ACQUIRE
value|(LS_TYPE_ADAPTIVE "-" LS_ACQUIRE)
end_define

begin_define
define|#
directive|define
name|LSA_RELEASE
value|(LS_TYPE_ADAPTIVE "-" LS_RELEASE)
end_define

begin_define
define|#
directive|define
name|LSA_SPIN
value|(LS_TYPE_ADAPTIVE "-" LS_SPIN)
end_define

begin_define
define|#
directive|define
name|LSA_BLOCK
value|(LS_TYPE_ADAPTIVE "-" LS_BLOCK)
end_define

begin_define
define|#
directive|define
name|LSS_ACQUIRE
value|(LS_TYPE_SPIN "-" LS_ACQUIRE)
end_define

begin_define
define|#
directive|define
name|LSS_RELEASE
value|(LS_TYPE_SPIN "-" LS_RELEASE)
end_define

begin_define
define|#
directive|define
name|LSS_SPIN
value|(LS_TYPE_SPIN "-" LS_SPIN)
end_define

begin_define
define|#
directive|define
name|LSR_ACQUIRE
value|(LS_TYPE_RW "-" LS_ACQUIRE)
end_define

begin_define
define|#
directive|define
name|LSR_RELEASE
value|(LS_TYPE_RW "-" LS_RELEASE)
end_define

begin_define
define|#
directive|define
name|LSR_BLOCK
value|(LS_TYPE_RW "-" LS_BLOCK)
end_define

begin_define
define|#
directive|define
name|LSR_SPIN
value|(LS_TYPE_RW "-" LS_SPIN)
end_define

begin_define
define|#
directive|define
name|LSR_UPGRADE
value|(LS_TYPE_RW "-" LS_UPGRADE)
end_define

begin_define
define|#
directive|define
name|LSR_DOWNGRADE
value|(LS_TYPE_RW "-" LS_DOWNGRADE)
end_define

begin_define
define|#
directive|define
name|LSX_ACQUIRE
value|(LS_TYPE_SX "-" LS_ACQUIRE)
end_define

begin_define
define|#
directive|define
name|LSX_RELEASE
value|(LS_TYPE_SX "-" LS_RELEASE)
end_define

begin_define
define|#
directive|define
name|LSX_BLOCK
value|(LS_TYPE_SX "-" LS_BLOCK)
end_define

begin_define
define|#
directive|define
name|LSX_SPIN
value|(LS_TYPE_SX "-" LS_SPIN)
end_define

begin_define
define|#
directive|define
name|LSX_UPGRADE
value|(LS_TYPE_SX "-" LS_UPGRADE)
end_define

begin_define
define|#
directive|define
name|LSX_DOWNGRADE
value|(LS_TYPE_SX "-" LS_DOWNGRADE)
end_define

begin_define
define|#
directive|define
name|LST_SPIN
value|(LS_TYPE_THREAD "-" LS_SPIN)
end_define

begin_comment
comment|/*  * The following must match the type definition of dtrace_probe.  It is  * defined this way to avoid having to rely on CDDL code.  */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|lockstat_probemap
index|[
name|LS_NPROBES
index|]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|lockstat_probe_func_t
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|uintptr_t
name|arg0
parameter_list|,
name|uintptr_t
name|arg1
parameter_list|,
name|uintptr_t
name|arg2
parameter_list|,
name|uintptr_t
name|arg3
parameter_list|,
name|uintptr_t
name|arg4
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|lockstat_probe_func_t
name|lockstat_probe_func
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|uint64_t
name|lockstat_nsecs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|KDTRACE_HOOKS
end_ifdef

begin_comment
comment|/*  * Macros to record lockstat probes.  */
end_comment

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD4
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
value|do {	\ 	uint32_t id;							\ 									\ 	if ((id = lockstat_probemap[(probe)])) 				\ 	    (*lockstat_probe_func)(id, (uintptr_t)(lp), (arg1),	(arg2),	\ 		(arg3), (arg4));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|)
define|\
value|LOCKSTAT_RECORD4(probe, lp, arg1, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD0
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|)
define|\
value|LOCKSTAT_RECORD4(probe, lp, 0, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD1
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|)
define|\
value|LOCKSTAT_RECORD4(probe, lp, arg1, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD2
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|LOCKSTAT_RECORD4(probe, lp, arg1, arg2, 0, 0)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD3
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|LOCKSTAT_RECORD4(probe, lp, arg1, arg2, arg3, 0)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_PROFILE_OBTAIN_LOCK_SUCCESS
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|c
parameter_list|,
name|wt
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
value|do {   \ 	uint32_t id;							     \ 									     \     	lock_profile_obtain_lock_success(&(lp)->lock_object, c, wt, f, l);   \ 	if ((id = lockstat_probemap[(probe)])) 			     	     \ 		(*lockstat_probe_func)(id, (uintptr_t)(lp), 0, 0, 0, 0);     \ } while (0)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_PROFILE_RELEASE_LOCK
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|)
value|do {			     \ 	uint32_t id;							     \ 									     \ 	lock_profile_release_lock(&(lp)->lock_object);			     \ 	if ((id = lockstat_probemap[(probe)])) 			     	     \ 		(*lockstat_probe_func)(id, (uintptr_t)(lp), 0, 0, 0, 0);     \ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !KDTRACE_HOOKS */
end_comment

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD0
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD1
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD2
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD3
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD4
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_PROFILE_OBTAIN_LOCK_SUCCESS
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|c
parameter_list|,
name|wt
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|lock_profile_obtain_lock_success(&(lp)->lock_object, c, wt, f, l)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_PROFILE_RELEASE_LOCK
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|)
define|\
value|lock_profile_release_lock(&(lp)->lock_object)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KDTRACE_HOOKS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_LOCKSTAT_H */
end_comment

end_unit

