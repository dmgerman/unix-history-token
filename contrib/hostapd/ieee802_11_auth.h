begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|IEEE802_11_AUTH_H
end_ifndef

begin_define
define|#
directive|define
name|IEEE802_11_AUTH_H
end_define

begin_enum
enum|enum
block|{
name|HOSTAPD_ACL_REJECT
init|=
literal|0
block|,
name|HOSTAPD_ACL_ACCEPT
init|=
literal|1
block|,
name|HOSTAPD_ACL_PENDING
init|=
literal|2
block|,
name|HOSTAPD_ACL_ACCEPT_TIMEOUT
init|=
literal|3
block|}
enum|;
end_enum

begin_function_decl
name|int
name|hostapd_allowed_address
parameter_list|(
name|hostapd
modifier|*
name|hapd
parameter_list|,
name|u8
modifier|*
name|addr
parameter_list|,
name|u8
modifier|*
name|msg
parameter_list|,
name|size_t
name|len
parameter_list|,
name|u32
modifier|*
name|session_timeout
parameter_list|,
name|u32
modifier|*
name|acct_interim_interval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_acl_init
parameter_list|(
name|hostapd
modifier|*
name|hapd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hostapd_acl_deinit
parameter_list|(
name|hostapd
modifier|*
name|hapd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEEE802_11_AUTH_H */
end_comment

end_unit

