begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.8 $ ** **  InterNetNews replacement for C news system locking. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|static
name|char
name|COMMAND
index|[]
init|=
literal|"ctlinnd %s Expire process %ld"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|IsLocked
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  C News debugging function. /* ARGSUSED */
end_comment

begin_function
name|void
name|lockdebug
parameter_list|(
name|state
parameter_list|)
name|int
name|state
decl_stmt|;
block|{ }
end_function

begin_comment
comment|/* **  Lock the news system by telling the server to throttle input. */
end_comment

begin_function
name|void
name|newslock
parameter_list|()
block|{
name|char
name|buff
index|[
literal|72
index|]
decl_stmt|;
name|int
name|i
decl_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buff
argument_list|,
name|COMMAND
argument_list|,
literal|"throttle"
argument_list|,
operator|(
name|long
operator|)
name|getpid
argument_list|()
argument_list|)
expr_stmt|;
name|i
operator|=
name|system
argument_list|(
name|buff
argument_list|)
operator|>>
literal|8
expr_stmt|;
if|if
condition|(
name|i
condition|)
name|error
argument_list|(
literal|"Can't lock"
argument_list|)
expr_stmt|;
name|IsLocked
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|/* **  Unlock the system and reload the files. */
end_comment

begin_function
name|void
name|newsunlock
parameter_list|()
block|{
name|char
name|buff
index|[
literal|72
index|]
decl_stmt|;
name|int
name|i
decl_stmt|;
if|if
condition|(
name|IsLocked
condition|)
block|{
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buff
argument_list|,
name|COMMAND
argument_list|,
literal|"go"
argument_list|,
operator|(
name|long
operator|)
name|getpid
argument_list|()
argument_list|)
expr_stmt|;
name|i
operator|=
name|system
argument_list|(
name|buff
argument_list|)
operator|>>
literal|8
expr_stmt|;
if|if
condition|(
name|i
condition|)
name|error
argument_list|(
literal|"Can't reload"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buff
argument_list|,
literal|"ctlinnd go"
argument_list|)
expr_stmt|;
name|i
operator|=
name|system
argument_list|(
name|buff
argument_list|)
operator|>>
literal|8
expr_stmt|;
if|if
condition|(
name|i
condition|)
name|error
argument_list|(
literal|"Can't unlock"
argument_list|)
expr_stmt|;
name|IsLocked
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* **  Print an error message, then unlock the system. */
end_comment

begin_function
name|void
name|errunlock
parameter_list|(
name|text
parameter_list|,
name|arg
parameter_list|)
name|char
modifier|*
name|text
decl_stmt|;
name|char
modifier|*
name|arg
decl_stmt|;
block|{
name|warning
argument_list|(
name|text
argument_list|,
name|arg
argument_list|)
expr_stmt|;
name|newsunlock
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_function

end_unit

