begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $FreeBSD$  *  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_decl_stmt
name|int
name|jail
name|__P
argument_list|(
operator|(
expr|struct
name|jail
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _KERNEL */
end_comment

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

begin_comment
comment|/*  * This structure describes a prison.  It is pointed to by all struct  * ucreds's of the inmates.  pr_ref keeps track of them and is used to  * delete the struture when the last inmate is dead.  *  * XXX: Note: this structure needs a mutex to protect the reference count  * and other mutable fields (pr_host, pr_linux).  */
end_comment

begin_struct
struct|struct
name|prison
block|{
name|int
name|pr_ref
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
name|void
modifier|*
name|pr_linux
decl_stmt|;
name|int
name|pr_securelevel
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Sysctl-set variables that determine global jail policy  */
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
name|sockaddr
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|jailed
name|__P
argument_list|(
operator|(
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|prison_check
name|__P
argument_list|(
operator|(
expr|struct
name|ucred
operator|*
name|cred1
operator|,
expr|struct
name|ucred
operator|*
name|cred2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prison_free
name|__P
argument_list|(
operator|(
expr|struct
name|prison
operator|*
name|pr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prison_hold
name|__P
argument_list|(
operator|(
expr|struct
name|prison
operator|*
name|pr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|prison_if
name|__P
argument_list|(
operator|(
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|sockaddr
operator|*
name|sa
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|prison_ip
name|__P
argument_list|(
operator|(
expr|struct
name|ucred
operator|*
name|cred
operator|,
name|int
name|flag
operator|,
name|u_int32_t
operator|*
name|ip
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prison_remote_ip
name|__P
argument_list|(
operator|(
expr|struct
name|ucred
operator|*
name|cred
operator|,
name|int
name|flags
operator|,
name|u_int32_t
operator|*
name|ip
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* !_SYS_JAIL_H_ */
end_comment

end_unit

