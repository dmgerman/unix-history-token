begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_TYPES_H
end_define

begin_struct
struct|struct
name|hostapd_ip_addr
block|{
union|union
block|{
name|struct
name|in_addr
name|v4
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_IPV6
name|struct
name|in6_addr
name|v6
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_IPV6 */
block|}
name|u
union|;
name|int
name|af
decl_stmt|;
comment|/* AF_INET / AF_INET6 */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_TYPES_H */
end_comment

end_unit

