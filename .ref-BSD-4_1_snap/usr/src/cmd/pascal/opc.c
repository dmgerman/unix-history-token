begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)opc.c 1.1 8/27/80"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"OPnames.h"
end_include

begin_function
name|main
parameter_list|()
block|{
specifier|register
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|256
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|otext
index|[
name|i
index|]
condition|)
name|printf
argument_list|(
literal|"#define O_%s %04o\n"
argument_list|,
name|otext
index|[
name|i
index|]
operator|+
literal|1
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

