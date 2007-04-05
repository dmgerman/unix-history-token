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

begin_struct
struct|struct
name|jail
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

begin_define
define|#
directive|define
name|XPRISON_VERSION
value|1
end_define

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
name|char
name|pr_path
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
comment|/* (c) chroot path */
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
name|u_int32_t
name|pr_ip
decl_stmt|;
comment|/* (c) ip addr host */
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
name|u_int32_t
name|prison_getip
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
name|prison_ip
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|flag
parameter_list|,
name|u_int32_t
modifier|*
name|ip
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
name|void
name|prison_remote_ip
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|flags
parameter_list|,
name|u_int32_t
modifier|*
name|ip
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

