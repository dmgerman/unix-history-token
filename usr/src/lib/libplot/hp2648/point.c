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
literal|"@(#)point.c	4.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"hp2648.h"
end_include

begin_macro
name|point
argument_list|(
argument|xi
argument_list|,
argument|yi
argument_list|)
end_macro

begin_decl_stmt
name|int
name|xi
decl_stmt|,
name|yi
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|xsc
argument_list|(
name|xi
argument_list|)
operator|!=
name|currentx
operator|||
name|ysc
argument_list|(
name|yi
argument_list|)
operator|!=
name|currenty
condition|)
name|move
argument_list|(
name|xi
argument_list|,
name|yi
argument_list|)
expr_stmt|;
name|buffready
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'d'
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

