begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* f77 interface to system routine */
end_comment

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_expr_stmt
name|system_
argument_list|(
name|s
argument_list|,
name|n
argument_list|)
specifier|register
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|ftnlen
name|n
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|abs
end_undef

begin_undef
undef|#
directive|undef
name|min
end_undef

begin_undef
undef|#
directive|undef
name|max
end_undef

begin_include
include|#
directive|include
file|"stdlib.h"
end_include

begin_macro
name|system_
argument_list|(
argument|register char *s
argument_list|,
argument|ftnlen n
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|char
name|buff
index|[
literal|1000
index|]
decl_stmt|;
specifier|register
name|char
modifier|*
name|bp
decl_stmt|,
modifier|*
name|blast
decl_stmt|;
name|blast
operator|=
name|buff
operator|+
operator|(
name|n
operator|<
literal|1000
condition|?
name|n
else|:
literal|1000
operator|)
expr_stmt|;
for|for
control|(
name|bp
operator|=
name|buff
init|;
name|bp
operator|<
name|blast
operator|&&
operator|*
name|s
operator|!=
literal|'\0'
condition|;
control|)
operator|*
name|bp
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
operator|*
name|bp
operator|=
literal|'\0'
expr_stmt|;
return|return
name|system
argument_list|(
name|buff
argument_list|)
return|;
block|}
end_block

end_unit

