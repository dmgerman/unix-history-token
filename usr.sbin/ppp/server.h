begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|extern
name|int
name|server
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|ServerLocalOpen
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|mode_t
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ServerTcpOpen
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ServerClose
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|UNKNOWN_SERVER
value|(-2)
end_define

begin_define
define|#
directive|define
name|NO_SERVER
value|(-1)
end_define

begin_define
define|#
directive|define
name|LOCAL_SERVER
value|(1)
end_define

begin_define
define|#
directive|define
name|INET_SERVER
value|(2)
end_define

begin_function_decl
specifier|extern
name|int
name|ServerType
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

