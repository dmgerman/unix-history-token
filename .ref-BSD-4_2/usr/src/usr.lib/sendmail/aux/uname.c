begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_comment
comment|/* **  UNAME -- print UNIX system name (fake version) ** **	For UNIX 3.0 compatiblity. */
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
name|char
name|buf
index|[
literal|40
index|]
decl_stmt|;
name|gethostname
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
name|buf
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EX_OK
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

