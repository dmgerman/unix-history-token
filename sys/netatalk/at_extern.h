begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr_at
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_NET_IF_ARP_H_
end_ifdef

begin_decl_stmt
specifier|extern
name|timeout_t
name|aarpprobe
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|aarpresolve
parameter_list|(
name|struct
name|arpcom
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockaddr_at
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|aarpinput
parameter_list|(
name|struct
name|arpcom
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|at_broadcast
parameter_list|(
name|struct
name|sockaddr_at
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_NETATALK_AARP_H_
end_ifdef

begin_function_decl
specifier|extern
name|void
name|aarptfree
parameter_list|(
name|struct
name|aarptab
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|ifnet
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|aarp_clean
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|at_control
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_short
name|at_cksum
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|skip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ddp_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|at_ifaddr
modifier|*
name|at_ifawithnet
parameter_list|(
name|struct
name|sockaddr_at
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_NETATALK_DDP_VAR_H_
end_ifdef

begin_function_decl
specifier|extern
name|int
name|ddp_output
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_NETATALK_DDP_VAR_H_
argument_list|)
operator|&&
name|defined
argument_list|(
name|_NETATALK_AT_VAR_H_
argument_list|)
end_if

begin_function_decl
specifier|extern
name|struct
name|ddpcb
modifier|*
name|ddp_search
parameter_list|(
name|struct
name|sockaddr_at
modifier|*
parameter_list|,
name|struct
name|sockaddr_at
modifier|*
parameter_list|,
name|struct
name|at_ifaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_NET_ROUTE_H_
end_ifdef

begin_function_decl
name|int
name|ddp_route
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|route
modifier|*
name|ro
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

