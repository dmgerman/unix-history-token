begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|REAL_ARITHMETIC
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_ATOF
parameter_list|(
name|x
parameter_list|,
name|mode
parameter_list|)
value|strtod ((x), (char **)0)
end_define

begin_function_decl
specifier|extern
name|double
name|strtod
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

