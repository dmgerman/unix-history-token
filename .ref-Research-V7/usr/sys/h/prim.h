begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|NOSLEEP
value|0400
end_define

begin_define
define|#
directive|define
name|FORCE
value|01000
end_define

begin_define
define|#
directive|define
name|NORM
value|02000
end_define

begin_define
define|#
directive|define
name|KEEP
value|04000
end_define

begin_define
define|#
directive|define
name|CLR
value|010000
end_define

begin_decl_stmt
name|int
name|bwaiting
decl_stmt|,
name|wcount
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|getepack
parameter_list|()
function_decl|;
end_function_decl

end_unit

