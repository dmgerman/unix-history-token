begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Robert N. M. Watson  * All rights reserved.  *  * Copyright (c) 1999 Ilmar S. Habibulin  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|POSIX1E_CAPABILITY_EXTATTR_NAME
value|"$posix1e.cap"
end_define

begin_define
define|#
directive|define
name|__CAP_MASK_LEN
value|2
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
name|u_int
name|cap_value_t
typedef|;
end_typedef

begin_struct
struct|struct
name|cap
block|{
name|u_int
name|c_effective
index|[
name|__CAP_MASK_LEN
index|]
decl_stmt|;
name|u_int
name|c_permitted
index|[
name|__CAP_MASK_LEN
index|]
decl_stmt|;
name|u_int
name|c_inheritable
index|[
name|__CAP_MASK_LEN
index|]
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

begin_define
define|#
directive|define
name|CAP_TYPE_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|CAP_MIN_TYPE
value|POSIX1E_CAPABILITY
end_define

begin_define
define|#
directive|define
name|POSIX1E_CAPABILITY
value|0x00
end_define

begin_define
define|#
directive|define
name|SYSTEM_CAPABILITY
value|0x01
end_define

begin_define
define|#
directive|define
name|CAP_MAX_TYPE
value|SYSTEM_CAPABILITY
end_define

begin_define
define|#
directive|define
name|SET_CAPABILITY
parameter_list|(
name|mask
parameter_list|,
name|cap
parameter_list|)
value|do { \ 	(mask)[(cap)& CAP_TYPE_MASK] |= (cap)& ~CAP_TYPE_MASK; \ 	} while (0)
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
value|do { \ 	(mask)[(cap)& CAP_TYPE_MASK]&= ~(cap)& ~CAP_TYPE_MASK; \ 	} while (0)
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
value|((mask)[(cap)& CAP_TYPE_MASK]& (cap)& ~CAP_TYPE_MASK)
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
value|((((scap).c_permitted[0] | (tcap).c_permitted[0]) \ 	 == (scap).c_permitted[0])&& \ 	 (((tcap.c_permitted[0] | (tcap).c_effective[0]) \ 	 == (tcap).c_permitted[0])&& \ 	 (((scap).c_permitted[1] | (tcap).c_permitted[1]) \ 	 == (scap).c_permitted[1])&& \ 	 (((tcap).c_permitted[1] | (tcap).c_effective[1]) \ 	 == (tcap).c_permitted[1]))
end_define

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
value|(0x00000100 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_DAC_EXECUTE
value|(0x00000200 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_DAC_WRITE
value|(0x00000400 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_DAC_READ_SEARCH
value|(0x00000800 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_FOWNER
value|(0x00001000 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_FSETID
value|(0x00002000 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_KILL
value|(0x00004000 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_LINK_DIR
value|(0x00008000 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_SETFCAP
value|(0x00010000 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_SETGID
value|(0x00020000 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_SETUID
value|(0x00040000 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_MAC_DOWNGRADE
value|(0x00080000 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_MAC_READ
value|(0x00100000 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_MAC_RELABEL_SUBJ
value|(0x00200000 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_MAC_UPGRADE
value|(0x00400000 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_MAC_WRITE
value|(0x00800000 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_INF_NOFLOAT_OBJ
value|(0x01000000 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_INF_NOFLOAT_SUBJ
value|(0x02000000 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_INF_RELABEL_OBJ
value|(0x04000000 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_INF_RELABEL_SUBJ
value|(0x08000000 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_AUDIT_CONTROL
value|(0x10000000 | POSIX1E_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_AUDIT_WRITE
value|(0x20000000 | POSIX1E_CAPABILITY)
end_define

begin_comment
comment|/*  * The following capability, borrowed from Linux, is unsafe  */
end_comment

begin_define
define|#
directive|define
name|CAP_SETPCAP
value|(0x00000100 | SYSTEM_CAPABILITY)
end_define

begin_comment
comment|/*  * The following capability, borrowed from Linux, is not appropriate  * in the BSD file environment  * #define	CAP_LINUX_IMMUTABLE	(0x00000200 | SYSTEM_CAPABILITY)  */
end_comment

begin_define
define|#
directive|define
name|CAP_BSD_SETFFLAG
value|(0x00000200 | SYSTEM_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_NET_BIND_SERVICE
value|(0x00000400 | SYSTEM_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_NET_BROADCAST
value|(0x00000800 | SYSTEM_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_NET_ADMIN
value|(0x00001000 | SYSTEM_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_NET_RAW
value|(0x00002000 | SYSTEM_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_IPC_LOCK
value|(0x00004000 | SYSTEM_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_IPC_OWNER
value|(0x00008000 | SYSTEM_CAPABILITY)
end_define

begin_comment
comment|/*  * The following capabilities, borrowed from Linux, are unsafe in a  * secure environment.  *  * #define	CAP_SYS_MODULE		(0x00010000 | SYSTEM_CAPABILITY)  * #define	CAP_SYS_RAWIO		(0x00020000 | SYSTEM_CAPABILITY)  * #define	CAP_SYS_CHROOT		(0x00040000 | SYSTEM_CAPABILITY)  * #define	CAP_SYS_PTRACE		(0x00080000 | SYSTEM_CAPABILITY)  */
end_comment

begin_define
define|#
directive|define
name|CAP_SYS_PACCT
value|(0x00100000 | SYSTEM_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_SYS_ADMIN
value|(0x00200000 | SYSTEM_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_SYS_BOOT
value|(0x00400000 | SYSTEM_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_SYS_NICE
value|(0x00800000 | SYSTEM_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_SYS_RESOURCE
value|(0x01000000 | SYSTEM_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_SYS_TIME
value|(0x02000000 | SYSTEM_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|CAP_SYS_TTY_CONFIG
value|(0x04000000 | SYSTEM_CAPABILITY)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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
name|proc
modifier|*
parameter_list|,
name|cap_value_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cap_check_xxx
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
name|void
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

