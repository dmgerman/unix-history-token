begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"	unixemts.c	4.1	82/05/12	"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_macro
name|doemt
argument_list|(
argument|code
argument_list|)
end_macro

begin_decl_stmt
name|int
name|code
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* just print a message if not caught */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"EMT 0%o caught\n"
argument_list|,
name|code
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

