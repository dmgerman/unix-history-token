begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|PIDFILE
value|"/var/run/natd.pid"
end_define

begin_function_decl
specifier|extern
name|void
name|Quit
parameter_list|(
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Warn
parameter_list|(
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|SendNeedFragIcmp
parameter_list|(
name|int
name|sock
parameter_list|,
name|struct
name|ip
modifier|*
name|failedDgram
parameter_list|,
name|int
name|mtu
parameter_list|)
function_decl|;
end_function_decl

end_unit

