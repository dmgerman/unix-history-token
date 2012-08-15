begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// "System header" for testing that -Wformat-extra-args does not apply to
end_comment

begin_comment
comment|// arguments specified in system headers.
end_comment

begin_define
define|#
directive|define
name|PRINT2
parameter_list|(
name|fmt
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|printf((fmt), (a1), (a2))
end_define

begin_define
define|#
directive|define
name|PRINT1
parameter_list|(
name|fmt
parameter_list|,
name|a1
parameter_list|)
define|\
value|PRINT2((fmt), (a1), 0)
end_define

end_unit

