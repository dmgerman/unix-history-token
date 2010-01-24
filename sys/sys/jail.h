begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $FreeBSD$  *  */
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

begin_include
include|#
directive|include
file|<sys/osd.h>
end_include

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

begin_struct
specifier|static
specifier|const
struct|struct
name|prison_state
block|{
name|int
name|pr_state
decl_stmt|;
specifier|const
name|char
modifier|*
name|state_name
decl_stmt|;
block|}
name|prison_states
index|[]
init|=
block|{
define|#
directive|define
name|PRISON_STATE_INVALID
value|0
block|{
name|PRISON_STATE_INVALID
block|,
literal|"INVALID"
block|}
block|,
define|#
directive|define
name|PRISON_STATE_ALIVE
value|1
block|{
name|PRISON_STATE_ALIVE
block|,
literal|"ALIVE"
block|}
block|,
define|#
directive|define
name|PRISON_STATE_DYING
value|2
block|{
name|PRISON_STATE_DYING
block|,
literal|"DYING"
block|}
block|, }
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

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
name|jail_attach
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
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
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

begin_struct_decl
struct_decl|struct
name|cpuset
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * This structure describes a prison.  It is pointed to by all struct  * ucreds's of the inmates.  pr_ref keeps track of them and is used to  * delete the struture when the last inmate is dead.  *  * Lock key:  *   (a) allprison_lock  *   (p) locked by pr_mtx  *   (c) set only during creation before the structure is shared, no mutex  *       required to read  *   (d) set only during destruction of jail, no mutex needed  */
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

begin_struct
struct|struct
name|prison
block|{
name|LIST_ENTRY
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
name|pr_state
decl_stmt|;
comment|/* (p) prison state */
name|int
name|pr_nprocs
decl_stmt|;
comment|/* (p) process count */
name|char
name|pr_path
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
comment|/* (c) chroot path */
name|struct
name|cpuset
modifier|*
name|pr_cpuset
decl_stmt|;
comment|/* (p) cpuset */
name|struct
name|vnode
modifier|*
name|pr_root
decl_stmt|;
comment|/* (c) vnode to rdir */
name|char
name|pr_host
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
comment|/* (p) jail hostname */
name|char
name|pr_name
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
comment|/* (c) admin jail name */
name|void
modifier|*
name|pr_linux
decl_stmt|;
comment|/* (p) linux abi */
name|int
name|pr_securelevel
decl_stmt|;
comment|/* (p) securelevel */
name|struct
name|task
name|pr_task
decl_stmt|;
comment|/* (d) destroy task */
name|struct
name|mtx
name|pr_mtx
decl_stmt|;
name|void
modifier|*
modifier|*
name|pr_slots
decl_stmt|;
comment|/* (p) additional data */
name|int
name|pr_ip4s
decl_stmt|;
comment|/* (c) number of v4 IPs */
name|struct
name|in_addr
modifier|*
name|pr_ip4
decl_stmt|;
comment|/* (c) v4 IPs of jail */
name|int
name|pr_ip6s
decl_stmt|;
comment|/* (c) number of v6 IPs */
name|struct
name|in6_addr
modifier|*
name|pr_ip6
decl_stmt|;
comment|/* (c) v6 IPs of jail */
name|struct
name|osd
name|pr_osd
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
comment|/*  * Flag bits set via options or internally  */
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
name|PR_REMOVE
value|0x01000000
end_define

begin_comment
comment|/* In process of being removed */
end_comment

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
name|PR_MAXMETHOD
value|5
end_define

begin_comment
comment|/*  * Sysctl-set variables that determine global jail policy  *  * XXX MIB entries will need to be protected by a mutex.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|jail_set_hostname_allowed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|jail_socket_unixiproute_only
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|jail_sysvipc_allowed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|jail_getfsstat_jailrootonly
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|jail_allow_raw_sockets
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|jail_chflags_allowed
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|LIST_HEAD
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

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|kern_jail
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|jail
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
name|void
name|getcredhostname
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
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

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

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

begin_comment
comment|/*  * Kernel jail services.  */
end_comment

begin_struct_decl
struct_decl|struct
name|prison_service
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|prison_create_t
function_decl|)
parameter_list|(
name|struct
name|prison_service
modifier|*
name|psrv
parameter_list|,
name|struct
name|prison
modifier|*
name|pr
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|prison_destroy_t
function_decl|)
parameter_list|(
name|struct
name|prison_service
modifier|*
name|psrv
parameter_list|,
name|struct
name|prison
modifier|*
name|pr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|struct
name|prison_service
modifier|*
name|prison_service_register
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|prison_create_t
name|create
parameter_list|,
name|prison_destroy_t
name|destroy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prison_service_deregister
parameter_list|(
name|struct
name|prison_service
modifier|*
name|psrv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prison_service_data_set
parameter_list|(
name|struct
name|prison_service
modifier|*
name|psrv
parameter_list|,
name|struct
name|prison
modifier|*
name|pr
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|prison_service_data_get
parameter_list|(
name|struct
name|prison_service
modifier|*
name|psrv
parameter_list|,
name|struct
name|prison
modifier|*
name|pr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|prison_service_data_del
parameter_list|(
name|struct
name|prison_service
modifier|*
name|psrv
parameter_list|,
name|struct
name|prison
modifier|*
name|pr
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

