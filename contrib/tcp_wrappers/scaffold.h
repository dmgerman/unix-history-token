begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * @(#) scaffold.h 1.3 94/12/31 18:19:19   *    * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.   *   * $FreeBSD$   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_function_decl
specifier|extern
name|struct
name|addrinfo
modifier|*
name|find_inet_addr
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|struct
name|hostent
modifier|*
name|find_inet_addr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|check_dns
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|check_path
parameter_list|()
function_decl|;
end_function_decl

end_unit

