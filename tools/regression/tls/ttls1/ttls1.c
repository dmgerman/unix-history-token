begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|__thread
name|xx1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__thread
name|xx2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__thread
name|xxa
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__thread
name|a
index|[
literal|10
index|]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|xxyy
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|printf
argument_list|(
literal|"xx1=%d, xx2=%d, xxa[5]=%d, a[5]=%d, xxyy()=%d\n"
argument_list|,
name|xx1
argument_list|,
name|xx2
argument_list|,
name|xxa
index|[
literal|5
index|]
argument_list|,
name|a
index|[
literal|5
index|]
argument_list|,
name|xxyy
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

