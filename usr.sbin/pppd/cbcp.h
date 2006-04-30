begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|CBCP_H
end_ifndef

begin_define
define|#
directive|define
name|CBCP_H
end_define

begin_typedef
typedef|typedef
struct|struct
name|cbcp_state
block|{
name|int
name|us_unit
decl_stmt|;
comment|/* Interface unit number */
name|u_char
name|us_id
decl_stmt|;
comment|/* Current id */
name|u_char
name|us_allowed
decl_stmt|;
name|int
name|us_type
decl_stmt|;
name|char
modifier|*
name|us_number
decl_stmt|;
comment|/* Telefone Number */
block|}
name|cbcp_state
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|cbcp_state
name|cbcp
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|protent
name|cbcp_protent
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CBCP_MINLEN
value|4
end_define

begin_define
define|#
directive|define
name|CBCP_REQ
value|1
end_define

begin_define
define|#
directive|define
name|CBCP_RESP
value|2
end_define

begin_define
define|#
directive|define
name|CBCP_ACK
value|3
end_define

begin_define
define|#
directive|define
name|CB_CONF_NO
value|1
end_define

begin_define
define|#
directive|define
name|CB_CONF_USER
value|2
end_define

begin_define
define|#
directive|define
name|CB_CONF_ADMIN
value|3
end_define

begin_define
define|#
directive|define
name|CB_CONF_LIST
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

