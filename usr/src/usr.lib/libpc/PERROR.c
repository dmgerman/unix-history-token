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
literal|"@(#)PERROR.c 1.2 1/10/83"
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
comment|/*  * Routine PERROR is called from the runtime library when a runtime  * I/O error occurs. Its arguments are a pointer to an error message and   * the name of the offending file.  */
end_comment

begin_function
name|long
name|PERROR
parameter_list|(
name|msg
parameter_list|,
name|fname
parameter_list|)
name|char
modifier|*
name|msg
decl_stmt|,
decl|*
name|fname
decl_stmt|;
end_function

begin_block
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
name|fputs
argument_list|(
name|msg
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|perror
argument_list|(
name|fname
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
literal|0
return|;
block|}
end_block

end_unit

