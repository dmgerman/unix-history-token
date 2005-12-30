begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Common DLPI Test Suite header file  *  */
end_comment

begin_comment
comment|/*  * Maximum control/data buffer size (in long's !!) for getmsg().  */
end_comment

begin_define
define|#
directive|define
name|MAXDLBUF
value|8192
end_define

begin_comment
comment|/*  * Maximum number of seconds we'll wait for any  * particular DLPI acknowledgment from the provider  * after issuing a request.  */
end_comment

begin_define
define|#
directive|define
name|MAXWAIT
value|15
end_define

begin_comment
comment|/*  * Maximum address buffer length.  */
end_comment

begin_define
define|#
directive|define
name|MAXDLADDR
value|1024
end_define

begin_comment
comment|/*  * Handy macro.  */
end_comment

begin_define
define|#
directive|define
name|OFFADDR
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|(u_char*)((char*)(s) + (int)(n))
end_define

begin_comment
comment|/*  * externs go here  */
end_comment

begin_function_decl
specifier|extern
name|void
name|sigalrm
parameter_list|()
function_decl|;
end_function_decl

end_unit

