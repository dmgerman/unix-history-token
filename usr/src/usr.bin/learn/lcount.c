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
literal|"@(#)lcount.c	4.2	(Berkeley)	4/25/83"
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
file|"stdio.h"
end_include

begin_function
name|main
parameter_list|()
comment|/* count lines in something */
block|{
specifier|register
name|n
operator|,
name|c
expr_stmt|;
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
operator|!=
name|EOF
condition|)
if|if
condition|(
name|c
operator|==
literal|'\n'
condition|)
name|n
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|n
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

