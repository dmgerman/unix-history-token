begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|__STDC__
end_if

begin_define
define|#
directive|define
name|C_SYMBOL_NAME
parameter_list|(
name|name
parameter_list|)
value|_##name
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|C_SYMBOL_NAME
parameter_list|(
name|name
parameter_list|)
value|_
comment|/**/
value|name
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

