begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* date.c */
end_comment

begin_include
include|#
directive|include
file|"tws.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|struct
name|tws
modifier|*
name|t
decl_stmt|;
name|char
name|buf
index|[
literal|1024
index|]
decl_stmt|;
while|while
condition|(
name|gets
argument_list|(
name|buf
argument_list|)
condition|)
block|{
name|t
operator|=
name|dparsetime
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|dasctime
argument_list|(
name|t
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

