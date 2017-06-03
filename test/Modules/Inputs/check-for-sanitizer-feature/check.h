begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|address_sanitizer
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAS_ASAN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HAS_ASAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

