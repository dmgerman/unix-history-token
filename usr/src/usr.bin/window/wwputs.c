begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)wwputs.c	1.2 83/07/17"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ww.h"
end_include

begin_expr_stmt
name|wwputs
argument_list|(
name|s
argument_list|,
name|w
argument_list|)
specifier|register
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|ww
modifier|*
name|w
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|p
init|=
name|s
decl_stmt|;
while|while
condition|(
operator|*
name|p
operator|++
condition|)
empty_stmt|;
name|wwwrite
argument_list|(
name|w
argument_list|,
name|s
argument_list|,
name|p
operator|-
name|s
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

