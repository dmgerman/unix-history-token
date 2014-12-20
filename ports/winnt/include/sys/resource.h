begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ports/winnt/include/sys/resource.h  *  * routines declared in Unix systems' sys/resource.h  */
end_comment

begin_define
define|#
directive|define
name|PRIO_PROCESS
value|0
end_define

begin_define
define|#
directive|define
name|NTP_PRIO
value|(-12)
end_define

begin_function_decl
name|int
name|setpriority
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* winnt\libntp\setpriority.c */
end_comment

end_unit

