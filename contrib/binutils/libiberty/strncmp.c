begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* strncmp -- compare two strings, stop after n bytes.    This function is in the public domain.  */
end_comment

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|size_t
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|strncmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
specifier|const
name|char
modifier|*
name|s1
decl_stmt|,
decl|*
name|s2
decl_stmt|;
end_function

begin_decl_stmt
specifier|register
name|size_t
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|unsigned
name|char
name|u1
decl_stmt|,
name|u2
decl_stmt|;
while|while
condition|(
name|n
operator|--
operator|>
literal|0
condition|)
block|{
name|u1
operator|=
operator|(
name|unsigned
name|char
operator|)
operator|*
name|s1
operator|++
expr_stmt|;
name|u2
operator|=
operator|(
name|unsigned
name|char
operator|)
operator|*
name|s2
operator|++
expr_stmt|;
if|if
condition|(
name|u1
operator|!=
name|u2
condition|)
return|return
name|u1
operator|-
name|u2
return|;
if|if
condition|(
name|u1
operator|==
literal|'\0'
condition|)
return|return
literal|0
return|;
block|}
return|return
literal|0
return|;
block|}
end_block

end_unit

