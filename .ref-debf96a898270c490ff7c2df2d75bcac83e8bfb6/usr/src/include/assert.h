begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	assert.h	4.2	85/01/21	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_define
define|#
directive|define
name|_assert
parameter_list|(
name|ex
parameter_list|)
value|{if (!(ex)){fprintf(stderr,"Assertion failed: file \"%s\", line %d\n", __FILE__, __LINE__);exit(1);}}
end_define

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|ex
parameter_list|)
value|_assert(ex)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_assert
parameter_list|(
name|ex
parameter_list|)
end_define

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|ex
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

