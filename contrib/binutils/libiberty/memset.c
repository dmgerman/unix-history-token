begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* memset    This implementation is in the public domain.  */
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

begin_decl_stmt
name|PTR
name|DEFUN
argument_list|(
name|memset
argument_list|,
operator|(
name|dest
operator|,
name|val
operator|,
name|len
operator|)
argument_list|,
name|PTR
name|dest
name|AND
specifier|register
name|int
name|val
name|AND
specifier|register
name|size_t
name|len
argument_list|)
block|{
specifier|register
name|unsigned
name|char
modifier|*
name|ptr
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|dest
decl_stmt|;
while|while
condition|(
name|len
operator|--
operator|>
literal|0
condition|)
operator|*
name|ptr
operator|++
operator|=
name|val
expr_stmt|;
return|return
name|dest
return|;
block|}
end_decl_stmt

end_unit

