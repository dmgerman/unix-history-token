begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*  *	Copyright 1973 Bell Telephone Laboratories Inc  */
end_comment

begin_comment
comment|/*  *	DM-BB fake driver  */
end_comment

begin_include
include|#
directive|include
file|"../tty.h"
end_include

begin_include
include|#
directive|include
file|"../conf.h"
end_include

begin_decl_stmt
name|struct
name|tty
name|dh11
index|[]
decl_stmt|;
end_decl_stmt

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
name|dev
operator|.
name|d_minor
index|]
expr_stmt|;
name|tp
operator|->
name|t_state
operator|=
operator||
name|CARR_ON
expr_stmt|;
block|}
end_block

begin_macro
name|dmclose
argument_list|(
argument|dev
argument_list|)
end_macro

begin_block
block|{ }
end_block

end_unit

