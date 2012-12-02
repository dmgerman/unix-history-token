begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|MODULE
end_define

begin_define
define|#
directive|define
name|INTEGER
parameter_list|(
name|X
parameter_list|)
value|int
end_define

begin_define
define|#
directive|define
name|FLOAT
value|float
end_define

begin_define
define|#
directive|define
name|DOUBLE
value|double
end_define

begin_empty
empty|#__public_macro INTEGER
end_empty

begin_empty
empty|#__private_macro FLOAT
end_empty

begin_empty
empty|#__private_macro MODULE
end_empty

begin_expr_stmt
name|int
argument_list|(
name|INTEGER
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
operator|!
name|__building_module
argument_list|(
name|macros
argument_list|)
end_if

begin_error
error|#
directive|error
error|Can't include this header without building the 'macros' module.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__MODULE__
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|__MODULE__
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

