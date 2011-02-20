begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
name|void
name|f
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(unavailable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|g
parameter_list|()
value|f()
end_define

begin_define
define|#
directive|define
name|h
parameter_list|()
value|f()
end_define

begin_define
define|#
directive|define
name|x
value|x
end_define

end_unit

