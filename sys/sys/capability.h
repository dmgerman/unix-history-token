begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000-2001 Robert N. M. Watson  * All rights reserved.  *  * Copyright (c) 1999 Ilmar S. Habibulin  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Developed by the TrustedBSD Project.  * Support for POSIX.1e process capabilities.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CAPABILITY_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CAPABILITY_H
end_define

begin_define
define|#
directive|define
name|POSIX1E_CAPABILITY_EXTATTR_NAMESPACE
value|EXTATTR_NAMESPACE_SYSTEM
end_define

begin_define
define|#
directive|define
name|POSIX1E_CAPABILITY_EXTATTR_NAME
value|"posix1e.cap"
end_define

begin_typedef
typedef|typedef
name|int
name|cap_flag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|cap_flag_value_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int64_t
name|cap_value_t
typedef|;
end_typedef

begin_struct
struct|struct
name|cap
block|{
name|u_int64_t
name|c_effective
decl_stmt|;
name|u_int64_t
name|c_permitted
decl_stmt|;
name|u_int64_t
name|c_inheritable
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cap
modifier|*
name|cap_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator||
name|defined
argument_list|(
name|_CAPABILITY_NEEDMACROS
argument_list|)
end_if

begin_define
define|#
directive|define
name|SET_CAPABILITY
parameter_list|(
name|mask
parameter_list|,
name|cap
parameter_list|)
value|do { \ 	(mask) |= cap; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|UNSET_CAPABILITY
parameter_list|(
name|mask
parameter_list|,
name|cap
parameter_list|)
value|do { \ 	(mask)&= ~(cap); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|IS_CAP_SET
parameter_list|(
name|mask
parameter_list|,
name|cap
parameter_list|)
define|\
value|((mask)& (cap))
end_define

begin_comment
comment|/*  * Is (tcap) a logical subset of (scap)?  */
end_comment

begin_define
define|#
directive|define
name|CAP_SUBSET
parameter_list|(
name|scap
parameter_list|,
name|tcap
parameter_list|)
define|\
value|((((scap).c_permitted | (tcap).c_permitted) == (scap).c_permitted)&& \ 	(((scap).c_effective | (tcap).c_effective) == (scap).c_effective)&& \ 	(((scap).c_inheritable | (tcap).c_inheritable) == (scap).c_inheritable))
end_define

begin_comment
comment|/*  * Put the union of the capability sets c1 and c2 into c2.  */
end_comment

begin_define
define|#
directive|define
name|CAP_UNITE
parameter_list|(
name|c1
parameter_list|,
name|c2
parameter_list|)
value|do { \ 	(c1).c_permitted |= (c2).c_permitted; \ 	(c1).c_effective |= (c2).c_effective; \ 	(c1).c_inheritable |= (c2).c_inheritable; \ 	} while (0)
end_define

begin_comment
comment|/*  * Test whether any bits in a cap set are set.  * XXX: due to capability setting constraints, it should actually be  * sufficient to check c_permitted.  */
end_comment

begin_define
define|#
directive|define
name|CAP_NONZERO
parameter_list|(
name|c
parameter_list|)
define|\
value|((c).c_permitted != 0 || (c).c_effective != 0 || (c).c_inheritable != 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Possible flags for a particular capability.  */
end_comment

begin_define
define|#
directive|define
name|CAP_EFFECTIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|CAP_INHERITABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|CAP_PERMITTED
value|0x04
end_define

begin_comment
comment|/*  * Possible values for each capability flag.  */
end_comment

begin_define
define|#
directive|define
name|CAP_CLEAR
value|0
end_define

begin_define
define|#
directive|define
name|CAP_SET
value|1
end_define

begin_comment
comment|/*  * Possible capability values, both BSD/LINUX and POSIX.1e.  */
end_comment

begin_define
define|#
directive|define
name|CAP_CHOWN
value|(0x0000000000000001)
end_define

begin_define
define|#
directive|define
name|CAP_DAC_EXECUTE
value|(0x0000000000000002)
end_define

begin_define
define|#
directive|define
name|CAP_DAC_WRITE
value|(0x0000000000000004)
end_define

begin_define
define|#
directive|define
name|CAP_DAC_READ_SEARCH
value|(0x0000000000000008)
end_define

begin_define
define|#
directive|define
name|CAP_FOWNER
value|(0x0000000000000010)
end_define

begin_define
define|#
directive|define
name|CAP_FSETID
value|(0x0000000000000020)
end_define

begin_define
define|#
directive|define
name|CAP_KILL
value|(0x0000000000000040)
end_define

begin_define
define|#
directive|define
name|CAP_LINK_DIR
value|(0x0000000000000080)
end_define

begin_define
define|#
directive|define
name|CAP_SETFCAP
value|(0x0000000000000100)
end_define

begin_define
define|#
directive|define
name|CAP_SETGID
value|(0x0000000000000200)
end_define

begin_define
define|#
directive|define
name|CAP_SETUID
value|(0x0000000000000400)
end_define

begin_define
define|#
directive|define
name|CAP_MAC_DOWNGRADE
value|(0x0000000000000800)
end_define

begin_define
define|#
directive|define
name|CAP_MAC_READ
value|(0x0000000000001000)
end_define

begin_define
define|#
directive|define
name|CAP_MAC_RELABEL_SUBJ
value|(0x0000000000002000)
end_define

begin_define
define|#
directive|define
name|CAP_MAC_UPGRADE
value|(0x0000000000004000)
end_define

begin_define
define|#
directive|define
name|CAP_MAC_WRITE
value|(0x0000000000008000)
end_define

begin_define
define|#
directive|define
name|CAP_INF_NOFLOAT_OBJ
value|(0x0000000000010000)
end_define

begin_define
define|#
directive|define
name|CAP_INF_NOFLOAT_SUBJ
value|(0x0000000000020000)
end_define

begin_define
define|#
directive|define
name|CAP_INF_RELABEL_OBJ
value|(0x0000000000040000)
end_define

begin_define
define|#
directive|define
name|CAP_INF_RELABEL_SUBJ
value|(0x0000000000080000)
end_define

begin_define
define|#
directive|define
name|CAP_AUDIT_CONTROL
value|(0x0000000000100000)
end_define

begin_define
define|#
directive|define
name|CAP_AUDIT_WRITE
value|(0x0000000000200000)
end_define

begin_comment
comment|/*  * The following is no longer functional.  * With our capability model, this serves no useful purpose. A process just  * has all the capabilities it needs, and if it are to be temporarily given  * up, they can be removed from the effective set.  * We do not support modifying the capabilities of other processes, as Linux  * (from which this one originated) does.  */
end_comment

begin_define
define|#
directive|define
name|CAP_SETPCAP
value|(0x0000000000400000)
end_define

begin_comment
comment|/* This is unallocated: */
end_comment

begin_define
define|#
directive|define
name|CAP_XXX_INVALID1
value|(0x0000000000800000)
end_define

begin_define
define|#
directive|define
name|CAP_SYS_SETFFLAG
value|(0x0000000001000000)
end_define

begin_comment
comment|/*  * The CAP_LINUX_IMMUTABLE flag approximately maps into the  * general file flag setting capability in BSD.  Therfore, for  * compatibility, map the constants.  */
end_comment

begin_define
define|#
directive|define
name|CAP_LINUX_IMMUTABLE
value|CAP_SYS_SETFFLAG
end_define

begin_define
define|#
directive|define
name|CAP_NET_BIND_SERVICE
value|(0x0000000002000000)
end_define

begin_define
define|#
directive|define
name|CAP_NET_BROADCAST
value|(0x0000000004000000)
end_define

begin_define
define|#
directive|define
name|CAP_NET_ADMIN
value|(0x0000000008000000)
end_define

begin_define
define|#
directive|define
name|CAP_NET_RAW
value|(0x0000000010000000)
end_define

begin_define
define|#
directive|define
name|CAP_IPC_LOCK
value|(0x0000000020000000)
end_define

begin_define
define|#
directive|define
name|CAP_IPC_OWNER
value|(0x0000000040000000)
end_define

begin_comment
comment|/*  * The following capabilities, borrowed from Linux, are unsafe in a  * secure environment.  */
end_comment

begin_define
define|#
directive|define
name|CAP_SYS_MODULE
value|(0x0000000080000000)
end_define

begin_define
define|#
directive|define
name|CAP_SYS_RAWIO
value|(0x0000000100000000)
end_define

begin_define
define|#
directive|define
name|CAP_SYS_CHROOT
value|(0x0000000200000000)
end_define

begin_define
define|#
directive|define
name|CAP_SYS_PTRACE
value|(0x0000000400000000)
end_define

begin_define
define|#
directive|define
name|CAP_SYS_PACCT
value|(0x0000000800000000)
end_define

begin_define
define|#
directive|define
name|CAP_SYS_ADMIN
value|(0x0000001000000000)
end_define

begin_comment
comment|/*  * Back to the safe ones, again.  */
end_comment

begin_define
define|#
directive|define
name|CAP_SYS_BOOT
value|(0x0000002000000000)
end_define

begin_define
define|#
directive|define
name|CAP_SYS_NICE
value|(0x0000004000000000)
end_define

begin_define
define|#
directive|define
name|CAP_SYS_RESOURCE
value|(0x0000008000000000)
end_define

begin_define
define|#
directive|define
name|CAP_SYS_TIME
value|(0x0000010000000000)
end_define

begin_define
define|#
directive|define
name|CAP_SYS_TTY_CONFIG
value|(0x0000020000000000)
end_define

begin_define
define|#
directive|define
name|CAP_MKNOD
value|(0x0000040000000000)
end_define

begin_define
define|#
directive|define
name|CAP_MAX_ID
value|CAP_MKNOD
end_define

begin_define
define|#
directive|define
name|CAP_ALL_ON
value|(CAP_CHOWN | CAP_DAC_EXECUTE | CAP_DAC_WRITE | \     CAP_DAC_READ_SEARCH | CAP_FOWNER | CAP_FSETID | CAP_KILL | CAP_LINK_DIR | \     CAP_SETFCAP | CAP_SETGID | CAP_SETUID | CAP_MAC_DOWNGRADE | \     CAP_MAC_READ | CAP_MAC_RELABEL_SUBJ | CAP_MAC_UPGRADE | \     CAP_MAC_WRITE | CAP_INF_NOFLOAT_OBJ | CAP_INF_NOFLOAT_SUBJ | \     CAP_INF_RELABEL_OBJ | CAP_INF_RELABEL_SUBJ | CAP_AUDIT_CONTROL | \     CAP_AUDIT_WRITE | CAP_SYS_SETFFLAG | CAP_NET_BIND_SERVICE | \     CAP_NET_BROADCAST | CAP_NET_ADMIN | CAP_NET_RAW | CAP_IPC_LOCK | \     CAP_IPC_OWNER | CAP_SYS_MODULE | CAP_SYS_RAWIO | CAP_SYS_CHROOT | \     CAP_SYS_PTRACE | CAP_SYS_PACCT | CAP_SYS_ADMIN | CAP_SYS_BOOT | \     CAP_SYS_NICE | CAP_SYS_RESOURCE | CAP_SYS_TIME | CAP_SYS_TTY_CONFIG | \     CAP_MKNOD)
end_define

begin_define
define|#
directive|define
name|CAP_ALL_OFF
value|(0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|cap_check
parameter_list|(
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|,
name|cap_value_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cap_change_on_inherit
parameter_list|(
name|struct
name|cap
modifier|*
name|cap_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cap_inherit
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cap_init_proc0
parameter_list|(
name|struct
name|cap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cap_init_proc1
parameter_list|(
name|struct
name|cap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_define
define|#
directive|define
name|_POSIX_CAP
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_SSIZE_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_SSIZE_T_
name|ssize_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_SSIZE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|__cap_get_proc
parameter_list|(
name|struct
name|cap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__cap_set_proc
parameter_list|(
name|struct
name|cap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__cap_get_fd
parameter_list|(
name|int
parameter_list|,
name|struct
name|cap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__cap_get_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|cap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__cap_set_fd
parameter_list|(
name|int
parameter_list|,
name|struct
name|cap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__cap_set_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|cap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cap_clear
parameter_list|(
name|cap_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|cap_copy_ext
parameter_list|(
name|void
modifier|*
parameter_list|,
name|cap_t
parameter_list|,
name|ssize_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cap_t
name|cap_copy_int
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cap_t
name|cap_dup
parameter_list|(
name|cap_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cap_free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cap_t
name|cap_from_text
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cap_t
name|cap_get_fd
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cap_t
name|cap_get_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cap_get_flag
parameter_list|(
name|cap_t
parameter_list|,
name|cap_value_t
parameter_list|,
name|cap_flag_t
parameter_list|,
name|cap_flag_value_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cap_t
name|cap_get_proc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cap_t
name|cap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cap_set_fd
parameter_list|(
name|int
parameter_list|,
name|cap_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cap_set_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|cap_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cap_set_flag
parameter_list|(
name|cap_t
parameter_list|,
name|cap_flag_t
parameter_list|,
name|int
parameter_list|,
name|cap_value_t
index|[]
parameter_list|,
name|cap_flag_value_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cap_set_proc
parameter_list|(
name|cap_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|cap_size
parameter_list|(
name|cap_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cap_to_text
parameter_list|(
name|cap_t
parameter_list|,
name|ssize_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Non-POSIX.1e functions  *  * Do the two cap_t's represent equal capability sets?  */
end_comment

begin_function_decl
name|int
name|cap_equal_np
parameter_list|(
name|cap_t
parameter_list|,
name|cap_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Is the first cap set a subset of the second? */
end_comment

begin_function_decl
name|int
name|cap_subset_np
parameter_list|(
name|cap_t
parameter_list|,
name|cap_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CAP_MAX_BUF_LEN
value|1024
end_define

begin_comment
comment|/* Maximum cap text buffer length */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_CAPABILITY_H */
end_comment

end_unit

