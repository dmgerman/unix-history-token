begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"mille.h"
end_include

begin_comment
comment|/*  *	This routine rolls ndie nside-sided dice.  *  * @(#)roll.c	1.1 (Berkeley) 4/1/82  *  */
end_comment

begin_macro
name|roll
argument_list|(
argument|ndie
argument_list|,
argument|nsides
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|int
name|ndie
decl_stmt|,
name|nsides
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|reg
name|int
name|tot
decl_stmt|;
specifier|extern
name|unsigned
name|int
name|random
parameter_list|()
function_decl|;
name|tot
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|ndie
operator|--
condition|)
name|tot
operator|+=
name|random
argument_list|()
operator|%
name|nsides
operator|+
literal|1
expr_stmt|;
return|return
name|tot
return|;
block|}
end_block

end_unit

