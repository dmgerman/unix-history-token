begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Author: Wietse Venema<wietse@wzv.win.tue.nl> */
end_comment

begin_comment
comment|/* $Id: sysv_default.h,v 1.5 1996/10/27 23:51:14 assar Exp $ */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|default_console
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|default_altsh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|default_passreq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|default_timezone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|default_hz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|default_path
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|default_supath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|default_ulimit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|default_timeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|default_umask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|default_sleep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|default_maxtrys
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|sysv_defaults
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

