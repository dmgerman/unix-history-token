begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|junk
index|[]
init|=
literal|"\n@(#) LIBU77 VERSION 19980709\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|__G77_LIBU77_VERSION__
index|[]
init|=
literal|"0.5.25 20010315 (release)"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|void
name|g77__uvers__
parameter_list|()
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"__G77_LIBU77_VERSION__: %s"
argument_list|,
name|__G77_LIBU77_VERSION__
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
name|junk
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

