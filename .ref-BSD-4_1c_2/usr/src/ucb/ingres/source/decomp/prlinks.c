begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<aux.h>
end_include

begin_include
include|#
directive|include
file|<tree.h>
end_include

begin_include
include|#
directive|include
file|<symbol.h>
end_include

begin_include
include|#
directive|include
file|"globs.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)prlinks.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_macro
name|prlinks
argument_list|(
argument|label
argument_list|,
argument|linkmap
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|label
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|linkmap
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|lm
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
name|printf
argument_list|(
literal|"\n%s: "
argument_list|,
name|label
argument_list|)
expr_stmt|;
name|lm
operator|=
name|linkmap
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAXDOM
condition|;
name|i
operator|++
control|)
if|if
condition|(
operator|*
name|lm
operator|++
condition|)
name|printf
argument_list|(
literal|"dom %d,"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

