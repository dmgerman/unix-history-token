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
literal|"@(#)version.c 1.1 8/27/80"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	this writes the declaration of the character string version      *	onto standard output.      *	useful for makeing Version.c give the correct date for pi.      */
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_function_decl
name|char
modifier|*
name|ctime
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|long
name|clock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|cstring
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|()
block|{
name|time
argument_list|(
operator|&
name|clock
argument_list|)
expr_stmt|;
name|cstring
operator|=
name|ctime
argument_list|(
operator|&
name|clock
argument_list|)
expr_stmt|;
name|cstring
index|[
literal|24
index|]
operator|=
literal|'\0'
expr_stmt|;
name|printf
argument_list|(
literal|"char	version[] = \"%s\";\n"
argument_list|,
name|cstring
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

