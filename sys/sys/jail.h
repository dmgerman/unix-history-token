begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Poul-Henning Kamp.  * Copyright (c) 2009 James Gritton.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_JAIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_JAIL_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|jail_v0
block|{
name|u_int32_t
name|version
decl_stmt|;
name|char
modifier|*
name|path
decl_stmt|;
name|char
modifier|*
name|hostname
decl_stmt|;
name|u_int32_t
name|ip_number
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|jail
block|{
name|uint32_t
name|version
decl_stmt|;
name|char
modifier|*
name|path
decl_stmt|;
name|char
modifier|*
name|hostname
decl_stmt|;
name|char
modifier|*
name|jailname
decl_stmt|;
name|uint32_t
name|ip4s
decl_stmt|;
name|uint32_t
name|ip6s
decl_stmt|;
name|struct
name|in_addr
modifier|*
name|ip4
decl_stmt|;
name|struct
name|in6_addr
modifier|*
name|ip6
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|JAIL_API_VERSION
value|2
end_define

begin_comment
comment|/*  * For all xprison structs, always keep the pr_version an int and  * the first variable so userspace can easily distinguish them.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_struct
struct|struct
name|xprison_v1
block|{
name|int
name|pr_version
decl_stmt|;
name|int
name|pr_id
decl_stmt|;
name|char
name|pr_path
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
name|pr_host
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
name|u_int32_t
name|pr_ip
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|xprison
block|{
name|int
name|pr_version
decl_stmt|;
name|int
name|pr_id
decl_stmt|;
name|int
name|pr_state
decl_stmt|;
name|cpusetid_t
name|pr_cpusetid
decl_stmt|;
name|char
name|pr_path
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
name|pr_host
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
name|char
name|pr_name
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
name|uint32_t
name|pr_ip4s
decl_stmt|;
name|uint32_t
name|pr_ip6s
decl_stmt|;
if|#
directive|if
literal|0
comment|/* 	 * sizeof(xprison) will be malloced + size needed for all 	 * IPv4 and IPv6 addesses. Offsets are based numbers of addresses. 	 */
block|struct in_addr	 pr_ip4[]; 	struct in6_addr	 pr_ip6[];
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XPRISON_VERSION
value|3
end_define

begin_define
define|#
directive|define
name|PRISON_STATE_INVALID
value|0
end_define

begin_define
define|#
directive|define
name|PRISON_STATE_ALIVE
value|1
end_define

begin_define
define|#
directive|define
name|PRISON_STATE_DYING
value|2
end_define

begin_comment
comment|/*  * Flags for jail_set and jail_get.  */
end_comment

begin_define
define|#
directive|define
name|JAIL_CREATE
value|0x01
end_define

begin_comment
comment|/* Create jail if it doesn't exist */
end_comment

begin_define
define|#
directive|define
name|JAIL_UPDATE
value|0x02
end_define

begin_comment
comment|/* Update parameters of existing jail */
end_comment

begin_define
define|#
directive|define
name|JAIL_ATTACH
value|0x04
end_define

begin_comment
comment|/* Attach to jail upon creation */
end_comment

begin_define
define|#
directive|define
name|JAIL_DYING
value|0x08
end_define

begin_comment
comment|/* Allow getting a dying jail */
end_comment

begin_define
define|#
directive|define
name|JAIL_SET_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|JAIL_GET_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|JAIL_SYS_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|JAIL_SYS_NEW
value|1
end_define

begin_define
define|#
directive|define
name|JAIL_SYS_INHERIT
value|2
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_struct_decl
struct_decl|struct
name|iovec
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|jail
parameter_list|(
name|struct
name|jail
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|jail_set
parameter_list|(
name|struct
name|iovec
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|jail_get
parameter_list|(
name|struct
name|iovec
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|jail_attach
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|jail_remove
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/_task.h>
end_include

begin_define
define|#
directive|define
name|JAIL_MAX
value|999999
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_PRISON
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_WANT_PRISON
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/osd.h>
end_include

begin_define
define|#
directive|define
name|HOSTUUIDLEN
value|64
end_define

begin_define
define|#
directive|define
name|OSRELEASELEN
value|32
end_define

begin_struct_decl
struct_decl|struct
name|racct
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|prison_racct
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * This structure describes a prison.  It is pointed to by all struct  * ucreds's of the inmates.  pr_ref keeps track of them and is used to  * delete the struture when the last inmate is dead.  *  * Lock key:  *   (a) allprison_lock  *   (p) locked by pr_mtx  *   (c) set only during creation before the structure is shared, no mutex  *       required to read  */
end_comment

begin_struct
struct|struct
name|prison
block|{
name|TAILQ_ENTRY
argument_list|(
argument|prison
argument_list|)
name|pr_list
expr_stmt|;
comment|/* (a) all prisons */
name|int
name|pr_id
decl_stmt|;
comment|/* (c) prison id */
name|int
name|pr_ref
decl_stmt|;
comment|/* (p) refcount */
name|int
name|pr_uref
decl_stmt|;
comment|/* (p) user (alive) refcount */
name|unsigned
name|pr_flags
decl_stmt|;
comment|/* (p) PR_* flags */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|prison
argument_list|)
name|pr_children
expr_stmt|;
comment|/* (a) list of child jails */
name|LIST_ENTRY
argument_list|(
argument|prison
argument_list|)
name|pr_sibling
expr_stmt|;
comment|/* (a) next in parent's list */
name|struct
name|prison
modifier|*
name|pr_parent
decl_stmt|;
comment|/* (c) containing jail */
name|struct
name|mtx
name|pr_mtx
decl_stmt|;
name|struct
name|task
name|pr_task
decl_stmt|;
comment|/* (c) destroy task */
name|struct
name|osd
name|pr_osd
decl_stmt|;
comment|/* (p) additional data */
name|struct
name|cpuset
modifier|*
name|pr_cpuset
decl_stmt|;
comment|/* (p) cpuset */
name|struct
name|vnet
modifier|*
name|pr_vnet
decl_stmt|;
comment|/* (c) network stack */
name|struct
name|vnode
modifier|*
name|pr_root
decl_stmt|;
comment|/* (c) vnode to rdir */
name|int
name|pr_ip4s
decl_stmt|;
comment|/* (p) number of v4 IPs */
name|int
name|pr_ip6s
decl_stmt|;
comment|/* (p) number of v6 IPs */
name|struct
name|in_addr
modifier|*
name|pr_ip4
decl_stmt|;
comment|/* (p) v4 IPs of jail */
name|struct
name|in6_addr
modifier|*
name|pr_ip6
decl_stmt|;
comment|/* (p) v6 IPs of jail */
name|struct
name|prison_racct
modifier|*
name|pr_prison_racct
decl_stmt|;
comment|/* (c) racct jail proxy */
name|void
modifier|*
name|pr_sparep
index|[
literal|3
index|]
decl_stmt|;
name|int
name|pr_childcount
decl_stmt|;
comment|/* (a) number of child jails */
name|int
name|pr_childmax
decl_stmt|;
comment|/* (p) maximum child jails */
name|unsigned
name|pr_allow
decl_stmt|;
comment|/* (p) PR_ALLOW_* flags */
name|int
name|pr_securelevel
decl_stmt|;
comment|/* (p) securelevel */
name|int
name|pr_enforce_statfs
decl_stmt|;
comment|/* (p) statfs permission */
name|int
name|pr_devfs_rsnum
decl_stmt|;
comment|/* (p) devfs ruleset */
name|int
name|pr_spare
index|[
literal|3
index|]
decl_stmt|;
name|int
name|pr_osreldate
decl_stmt|;
comment|/* (c) kern.osreldate value */
name|unsigned
name|long
name|pr_hostid
decl_stmt|;
comment|/* (p) jail hostid */
name|char
name|pr_name
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
comment|/* (p) admin jail name */
name|char
name|pr_path
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
comment|/* (c) chroot path */
name|char
name|pr_hostname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
comment|/* (p) jail hostname */
name|char
name|pr_domainname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
comment|/* (p) jail domainname */
name|char
name|pr_hostuuid
index|[
name|HOSTUUIDLEN
index|]
decl_stmt|;
comment|/* (p) jail hostuuid */
name|char
name|pr_osrelease
index|[
name|OSRELEASELEN
index|]
decl_stmt|;
comment|/* (c) kern.osrelease value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|prison_racct
block|{
name|LIST_ENTRY
argument_list|(
argument|prison_racct
argument_list|)
name|prr_next
expr_stmt|;
name|char
name|prr_name
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
name|u_int
name|prr_refcount
decl_stmt|;
name|struct
name|racct
modifier|*
name|prr_racct
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL || _WANT_PRISON */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Flag bits set via options */
end_comment

begin_define
define|#
directive|define
name|PR_PERSIST
value|0x00000001
end_define

begin_comment
comment|/* Can exist without processes */
end_comment

begin_define
define|#
directive|define
name|PR_HOST
value|0x00000002
end_define

begin_comment
comment|/* Virtualize hostname et al */
end_comment

begin_define
define|#
directive|define
name|PR_IP4_USER
value|0x00000004
end_define

begin_comment
comment|/* Restrict IPv4 addresses */
end_comment

begin_define
define|#
directive|define
name|PR_IP6_USER
value|0x00000008
end_define

begin_comment
comment|/* Restrict IPv6 addresses */
end_comment

begin_define
define|#
directive|define
name|PR_VNET
value|0x00000010
end_define

begin_comment
comment|/* Virtual network stack */
end_comment

begin_define
define|#
directive|define
name|PR_IP4_SADDRSEL
value|0x00000080
end_define

begin_comment
comment|/* Do IPv4 src addr sel. or use the */
end_comment

begin_comment
comment|/* primary jail address. */
end_comment

begin_define
define|#
directive|define
name|PR_IP6_SADDRSEL
value|0x00000100
end_define

begin_comment
comment|/* Do IPv6 src addr sel. or use the */
end_comment

begin_comment
comment|/* primary jail address. */
end_comment

begin_comment
comment|/* Internal flag bits */
end_comment

begin_define
define|#
directive|define
name|PR_IP4
value|0x02000000
end_define

begin_comment
comment|/* IPv4 restricted or disabled */
end_comment

begin_comment
comment|/* by this jail or an ancestor */
end_comment

begin_define
define|#
directive|define
name|PR_IP6
value|0x04000000
end_define

begin_comment
comment|/* IPv6 restricted or disabled */
end_comment

begin_comment
comment|/* by this jail or an ancestor */
end_comment

begin_comment
comment|/* Flags for pr_allow */
end_comment

begin_define
define|#
directive|define
name|PR_ALLOW_SET_HOSTNAME
value|0x0001
end_define

begin_define
define|#
directive|define
name|PR_ALLOW_SYSVIPC
value|0x0002
end_define

begin_define
define|#
directive|define
name|PR_ALLOW_RAW_SOCKETS
value|0x0004
end_define

begin_define
define|#
directive|define
name|PR_ALLOW_CHFLAGS
value|0x0008
end_define

begin_define
define|#
directive|define
name|PR_ALLOW_MOUNT
value|0x0010
end_define

begin_define
define|#
directive|define
name|PR_ALLOW_QUOTAS
value|0x0020
end_define

begin_define
define|#
directive|define
name|PR_ALLOW_SOCKET_AF
value|0x0040
end_define

begin_define
define|#
directive|define
name|PR_ALLOW_MOUNT_DEVFS
value|0x0080
end_define

begin_define
define|#
directive|define
name|PR_ALLOW_MOUNT_NULLFS
value|0x0100
end_define

begin_define
define|#
directive|define
name|PR_ALLOW_MOUNT_ZFS
value|0x0200
end_define

begin_define
define|#
directive|define
name|PR_ALLOW_MOUNT_PROCFS
value|0x0400
end_define

begin_define
define|#
directive|define
name|PR_ALLOW_MOUNT_TMPFS
value|0x0800
end_define

begin_define
define|#
directive|define
name|PR_ALLOW_MOUNT_FDESCFS
value|0x1000
end_define

begin_define
define|#
directive|define
name|PR_ALLOW_MOUNT_LINPROCFS
value|0x2000
end_define

begin_define
define|#
directive|define
name|PR_ALLOW_MOUNT_LINSYSFS
value|0x4000
end_define

begin_define
define|#
directive|define
name|PR_ALLOW_ALL
value|0x7fff
end_define

begin_comment
comment|/*  * OSD methods  */
end_comment

begin_define
define|#
directive|define
name|PR_METHOD_CREATE
value|0
end_define

begin_define
define|#
directive|define
name|PR_METHOD_GET
value|1
end_define

begin_define
define|#
directive|define
name|PR_METHOD_SET
value|2
end_define

begin_define
define|#
directive|define
name|PR_METHOD_CHECK
value|3
end_define

begin_define
define|#
directive|define
name|PR_METHOD_ATTACH
value|4
end_define

begin_define
define|#
directive|define
name|PR_METHOD_REMOVE
value|5
end_define

begin_define
define|#
directive|define
name|PR_MAXMETHOD
value|6
end_define

begin_comment
comment|/*  * Lock/unlock a prison.  * XXX These exist not so much for general convenience, but to be useable in  *     the FOREACH_PRISON_DESCENDANT_LOCKED macro which can't handle them in  *     non-function form as currently defined.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|prison_lock
parameter_list|(
name|struct
name|prison
modifier|*
name|pr
parameter_list|)
block|{
name|mtx_lock
argument_list|(
operator|&
name|pr
operator|->
name|pr_mtx
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|prison_unlock
parameter_list|(
name|struct
name|prison
modifier|*
name|pr
parameter_list|)
block|{
name|mtx_unlock
argument_list|(
operator|&
name|pr
operator|->
name|pr_mtx
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Traverse a prison's immediate children. */
end_comment

begin_define
define|#
directive|define
name|FOREACH_PRISON_CHILD
parameter_list|(
name|ppr
parameter_list|,
name|cpr
parameter_list|)
define|\
value|LIST_FOREACH(cpr,&(ppr)->pr_children, pr_sibling)
end_define

begin_comment
comment|/*  * Preorder traversal of all of a prison's descendants.  * This ugly loop allows the macro to be followed by a single block  * as expected in a looping primitive.  */
end_comment

begin_define
define|#
directive|define
name|FOREACH_PRISON_DESCENDANT
parameter_list|(
name|ppr
parameter_list|,
name|cpr
parameter_list|,
name|descend
parameter_list|)
define|\
value|for ((cpr) = (ppr), (descend) = 1;				\ 	    ((cpr) = (((descend)&& !LIST_EMPTY(&(cpr)->pr_children))	\ 	      ? LIST_FIRST(&(cpr)->pr_children)				\ 	      : ((cpr) == (ppr)						\ 		 ? NULL							\ 		 : (((descend) = LIST_NEXT(cpr, pr_sibling) != NULL)	\ 		    ? LIST_NEXT(cpr, pr_sibling)			\ 		    : (cpr)->pr_parent))));)				\ 		if (!(descend))						\ 			;						\ 		else
end_define

begin_comment
comment|/*  * As above, but lock descendants on the way down and unlock on the way up.  */
end_comment

begin_define
define|#
directive|define
name|FOREACH_PRISON_DESCENDANT_LOCKED
parameter_list|(
name|ppr
parameter_list|,
name|cpr
parameter_list|,
name|descend
parameter_list|)
define|\
value|for ((cpr) = (ppr), (descend) = 1;				\ 	    ((cpr) = (((descend)&& !LIST_EMPTY(&(cpr)->pr_children))	\ 	      ? LIST_FIRST(&(cpr)->pr_children)				\ 	      : ((cpr) == (ppr)						\ 		 ? NULL							\ 		 : ((prison_unlock(cpr),				\ 		    (descend) = LIST_NEXT(cpr, pr_sibling) != NULL)	\ 		    ? LIST_NEXT(cpr, pr_sibling)			\ 		    : (cpr)->pr_parent))));)				\ 		if ((descend) ? (prison_lock(cpr), 0) : 1)		\ 			;						\ 		else
end_define

begin_comment
comment|/*  * As above, but also keep track of the level descended to.  */
end_comment

begin_define
define|#
directive|define
name|FOREACH_PRISON_DESCENDANT_LOCKED_LEVEL
parameter_list|(
name|ppr
parameter_list|,
name|cpr
parameter_list|,
name|descend
parameter_list|,
name|level
parameter_list|)
define|\
value|for ((cpr) = (ppr), (descend) = 1, (level) = 0;			\ 	    ((cpr) = (((descend)&& !LIST_EMPTY(&(cpr)->pr_children))	\ 	      ? (level++, LIST_FIRST(&(cpr)->pr_children))		\ 	      : ((cpr) == (ppr)						\ 		 ? NULL							\ 		 : ((prison_unlock(cpr),				\ 		    (descend) = LIST_NEXT(cpr, pr_sibling) != NULL)	\ 		    ? LIST_NEXT(cpr, pr_sibling)			\ 		    : (level--, (cpr)->pr_parent)))));)			\ 		if ((descend) ? (prison_lock(cpr), 0) : 1)		\ 			;						\ 		else
end_define

begin_comment
comment|/*  * Attributes of the physical system, and the root of the jail tree.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|prison
name|prison0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|prisonlist
argument_list|,
name|prison
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|prisonlist
name|allprison
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sx
name|allprison_lock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Sysctls to describe jail parameters.  */
end_comment

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_security_jail_param
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|SYSCTL_JAIL_PARAM
parameter_list|(
name|module
parameter_list|,
name|param
parameter_list|,
name|type
parameter_list|,
name|fmt
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_PROC(_security_jail_param ## module, OID_AUTO, param,	\ 	(type) | CTLFLAG_MPSAFE, NULL, 0, sysctl_jail_param, fmt, descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_JAIL_PARAM_STRING
parameter_list|(
name|module
parameter_list|,
name|param
parameter_list|,
name|access
parameter_list|,
name|len
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_PROC(_security_jail_param ## module, OID_AUTO, param,	\ 	CTLTYPE_STRING | CTLFLAG_MPSAFE | (access), NULL, len,		\ 	sysctl_jail_param, "A", descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_JAIL_PARAM_STRUCT
parameter_list|(
name|module
parameter_list|,
name|param
parameter_list|,
name|access
parameter_list|,
name|len
parameter_list|,
name|fmt
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_PROC(_security_jail_param ## module, OID_AUTO, param,	\ 	CTLTYPE_STRUCT | CTLFLAG_MPSAFE | (access), NULL, len,		\ 	sysctl_jail_param, fmt, descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_JAIL_PARAM_NODE
parameter_list|(
name|module
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_NODE(_security_jail_param, OID_AUTO, module, 0, 0, descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_JAIL_PARAM_SUBNODE
parameter_list|(
name|parent
parameter_list|,
name|module
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_NODE(_security_jail_param_##parent, OID_AUTO, module, 0, 0, descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_JAIL_PARAM_SYS_NODE
parameter_list|(
name|module
parameter_list|,
name|access
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_JAIL_PARAM_NODE(module, descr);				\     SYSCTL_JAIL_PARAM(_##module, , CTLTYPE_INT | (access), "E,jailsys",	\ 	descr)
end_define

begin_comment
comment|/*  * Kernel support functions for jail().  */
end_comment

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|statfs
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|jailed
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|jailed_without_vnet
parameter_list|(
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getcredhostname
parameter_list|(
name|struct
name|ucred
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getcreddomainname
parameter_list|(
name|struct
name|ucred
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getcredhostuuid
parameter_list|(
name|struct
name|ucred
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getcredhostid
parameter_list|(
name|struct
name|ucred
modifier|*
parameter_list|,
name|unsigned
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prison0_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_allow
parameter_list|(
name|struct
name|ucred
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_check
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred1
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_owns_vnet
parameter_list|(
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_canseemount
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prison_enforce_statfs
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|statfs
modifier|*
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|prison
modifier|*
name|prison_find
parameter_list|(
name|int
name|prid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|prison
modifier|*
name|prison_find_child
parameter_list|(
name|struct
name|prison
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|prison
modifier|*
name|prison_find_name
parameter_list|(
name|struct
name|prison
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_flag
parameter_list|(
name|struct
name|ucred
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prison_free
parameter_list|(
name|struct
name|prison
modifier|*
name|pr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prison_free_locked
parameter_list|(
name|struct
name|prison
modifier|*
name|pr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prison_hold
parameter_list|(
name|struct
name|prison
modifier|*
name|pr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prison_hold_locked
parameter_list|(
name|struct
name|prison
modifier|*
name|pr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prison_proc_hold
parameter_list|(
name|struct
name|prison
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prison_proc_free
parameter_list|(
name|struct
name|prison
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_ischild
parameter_list|(
name|struct
name|prison
modifier|*
parameter_list|,
name|struct
name|prison
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_equal_ip4
parameter_list|(
name|struct
name|prison
modifier|*
parameter_list|,
name|struct
name|prison
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_get_ip4
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|in_addr
modifier|*
name|ia
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_local_ip4
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|in_addr
modifier|*
name|ia
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_remote_ip4
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|in_addr
modifier|*
name|ia
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_check_ip4
parameter_list|(
specifier|const
name|struct
name|ucred
modifier|*
parameter_list|,
specifier|const
name|struct
name|in_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_check_ip4_locked
parameter_list|(
specifier|const
name|struct
name|prison
modifier|*
parameter_list|,
specifier|const
name|struct
name|in_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_saddrsel_ip4
parameter_list|(
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_restrict_ip4
parameter_list|(
name|struct
name|prison
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_qcmp_v4
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_function_decl
name|int
name|prison_equal_ip6
parameter_list|(
name|struct
name|prison
modifier|*
parameter_list|,
name|struct
name|prison
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_get_ip6
parameter_list|(
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|in6_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_local_ip6
parameter_list|(
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|in6_addr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_remote_ip6
parameter_list|(
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|in6_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_check_ip6
parameter_list|(
specifier|const
name|struct
name|ucred
modifier|*
parameter_list|,
specifier|const
name|struct
name|in6_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_check_ip6_locked
parameter_list|(
specifier|const
name|struct
name|prison
modifier|*
parameter_list|,
specifier|const
name|struct
name|in6_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_saddrsel_ip6
parameter_list|(
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|in6_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_restrict_ip6
parameter_list|(
name|struct
name|prison
modifier|*
parameter_list|,
name|struct
name|in6_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_qcmp_v6
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|prison_check_af
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|af
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_if
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|prison_name
parameter_list|(
name|struct
name|prison
modifier|*
parameter_list|,
name|struct
name|prison
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prison_priv_check
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_jail_param
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prison_racct_foreach
parameter_list|(
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|struct
name|racct
modifier|*
name|racct
parameter_list|,
name|void
modifier|*
name|arg2
parameter_list|,
name|void
modifier|*
name|arg3
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|pre
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|post
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg2
parameter_list|,
name|void
modifier|*
name|arg3
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|prison_racct
modifier|*
name|prison_racct_find
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prison_racct_hold
parameter_list|(
name|struct
name|prison_racct
modifier|*
name|prr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prison_racct_free
parameter_list|(
name|struct
name|prison_racct
modifier|*
name|prr
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* !_SYS_JAIL_H_ */
end_comment

end_unit

