begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	dhfdm.c	4.1	11/9/80	*/
end_comment

begin_include
include|#
directive|include
file|"../conf/dh.h"
end_include

begin_if
if|#
directive|if
name|NDH11
operator|>
literal|0
end_if

begin_comment
comment|/*  * DM-BB fake driver  */
end_comment

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/tty.h"
end_include

begin_include
include|#
directive|include
file|"../h/conf.h"
end_include

begin_decl_stmt
name|struct
name|tty
name|dh11
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|dmopen
argument_list|(
argument|dev
argument_list|)
end_macro

begin_block
block|{
specifier|register
name|struct
name|tty
modifier|*
name|tp
decl_stmt|;
name|tp
operator|=
operator|&
name|dh11
index|[
name|minor
argument_list|(
name|dev
argument_list|)
index|]
expr_stmt|;
name|tp
operator|->
name|t_state
operator||=
name|CARR_ON
expr_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|dmctl
argument_list|(
argument|dev
argument_list|,
argument|bits
argument_list|,
argument|how
argument_list|)
end_macro

begin_block
block|{  }
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

