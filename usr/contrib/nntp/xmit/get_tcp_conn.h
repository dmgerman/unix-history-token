begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** Return codes from get_tcp_conn(). */
end_comment

begin_define
define|#
directive|define
name|FAIL
value|(-1)
end_define

begin_comment
comment|/* routine failed */
end_comment

begin_define
define|#
directive|define
name|NOHOST
value|(FAIL-1)
end_define

begin_comment
comment|/* no such host */
end_comment

begin_define
define|#
directive|define
name|NOSERVICE
value|(FAIL-2)
end_define

begin_comment
comment|/* no such service */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

