begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)psignal.c	4.1 (Berkeley) 2/10/83	*/
end_comment

begin_comment
comment|/*  * Print the name of the signal indicated  * along with the supplied message.  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_siglist
index|[]
decl_stmt|;
end_decl_stmt

begin_macro
name|psignal
argument_list|(
argument|sig
argument_list|,
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|unsigned
name|sig
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|c
decl_stmt|;
specifier|register
name|n
expr_stmt|;
name|c
operator|=
literal|"Unknown signal"
expr_stmt|;
if|if
condition|(
name|sig
operator|<
name|NSIG
condition|)
name|c
operator|=
name|sys_siglist
index|[
name|sig
index|]
expr_stmt|;
name|n
operator|=
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
condition|)
block|{
name|write
argument_list|(
literal|2
argument_list|,
name|s
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|write
argument_list|(
literal|2
argument_list|,
literal|": "
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
name|write
argument_list|(
literal|2
argument_list|,
name|c
argument_list|,
name|strlen
argument_list|(
name|c
argument_list|)
argument_list|)
expr_stmt|;
name|write
argument_list|(
literal|2
argument_list|,
literal|"\n"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

