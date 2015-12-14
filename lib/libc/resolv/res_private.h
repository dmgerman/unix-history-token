begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|res_private_h
end_ifndef

begin_define
define|#
directive|define
name|res_private_h
end_define

begin_struct
struct|struct
name|__res_state_ext
block|{
name|union
name|res_sockaddr_union
name|nsaddrs
index|[
name|MAXNS
index|]
decl_stmt|;
struct|struct
name|sort_list
block|{
name|int
name|af
decl_stmt|;
union|union
block|{
name|struct
name|in_addr
name|ina
decl_stmt|;
name|struct
name|in6_addr
name|in6a
decl_stmt|;
block|}
name|addr
union|,
name|mask
union|;
block|}
name|sort_list
index|[
name|MAXRESOLVSORT
index|]
struct|;
name|char
name|nsuffix
index|[
literal|64
index|]
decl_stmt|;
name|char
name|nsuffix2
index|[
literal|64
index|]
decl_stmt|;
name|struct
name|timespec
name|conf_mtim
decl_stmt|;
comment|/* mod time of loaded resolv.conf */
name|time_t
name|conf_stat
decl_stmt|;
comment|/* time of last stat(resolv.conf) */
name|u_short
name|reload_period
decl_stmt|;
comment|/* seconds between stat(resolv.conf) */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|res_ourserver_p
parameter_list|(
specifier|const
name|res_state
name|statp
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \file */
end_comment

end_unit

