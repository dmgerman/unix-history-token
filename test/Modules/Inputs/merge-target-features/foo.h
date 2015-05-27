begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|FOO_H
end_ifndef

begin_define
define|#
directive|define
name|FOO_H
end_define

begin_function
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
operator|+
literal|42
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// FOO_H
end_comment

end_unit

