begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)getnum.c	1.1	(Berkeley)	6/8/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_macro
name|getnum
argument_list|()
end_macro

begin_block
block|{
name|int
name|c
decl_stmt|,
name|n
decl_stmt|;
name|n
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getchar
argument_list|()
operator|)
operator|>=
literal|'0'
operator|&&
name|c
operator|<=
literal|'9'
condition|)
name|n
operator|=
name|n
operator|*
literal|10
operator|+
name|c
operator|-
literal|'0'
expr_stmt|;
if|if
condition|(
name|c
operator|==
name|EOF
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
name|n
operator|)
return|;
block|}
end_block

end_unit

