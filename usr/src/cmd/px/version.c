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
literal|"@(#)version.c 4.1 10/10/80"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	this writes the declaration of the current time stamp      *	onto standard output.      *	useful for makeing Ver.c give the correct date for pi.      */
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_function
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"long	createtime = %d;\n"
argument_list|,
name|time
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

