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
literal|"@(#)ERROR.c 1.10 1/10/83"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|/*  * Routine ERROR is called from the runtime library when a runtime  * error occurs. Its arguments are a pointer to an error message and   * an error specific piece of data.  */
end_comment

begin_function
name|long
name|ERROR
parameter_list|(
name|msg
parameter_list|,
name|d1
parameter_list|,
name|d2
parameter_list|)
name|char
modifier|*
name|msg
decl_stmt|;
name|long
name|d1
decl_stmt|,
name|d2
decl_stmt|;
block|{
name|PFLUSH
argument_list|()
expr_stmt|;
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|msg
argument_list|,
name|d1
argument_list|,
name|d2
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGTRAP
argument_list|)
expr_stmt|;
return|return
name|d1
return|;
block|}
end_function

end_unit

