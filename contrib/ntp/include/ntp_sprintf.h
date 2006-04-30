begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Handle ancient char* *s*printf*() systems  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SPRINTF_CHAR
end_ifdef

begin_define
define|#
directive|define
name|SPRINTF
parameter_list|(
name|x
parameter_list|)
value|strlen(sprintf
comment|/**/
value|x)
end_define

begin_define
define|#
directive|define
name|SNPRINTF
parameter_list|(
name|x
parameter_list|)
value|strlen(snprintf
comment|/**/
value|x)
end_define

begin_define
define|#
directive|define
name|VSNPRINTF
parameter_list|(
name|x
parameter_list|)
value|strlen(vsnprintf
comment|/**/
value|x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SPRINTF
parameter_list|(
name|x
parameter_list|)
value|((size_t)sprintf x)
end_define

begin_define
define|#
directive|define
name|SNPRINTF
parameter_list|(
name|x
parameter_list|)
value|((size_t)snprintf x)
end_define

begin_define
define|#
directive|define
name|VSNPRINTF
parameter_list|(
name|x
parameter_list|)
value|((size_t)vsnprintf x)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

