begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"defines"
end_include

begin_include
include|#
directive|include
file|"locdefs"
end_include

begin_macro
name|prchars
argument_list|(
argument|fp
argument_list|,
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|FILEP
name|fp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|".byte 0%o,0%o\n"
argument_list|,
name|s
index|[
literal|0
index|]
argument_list|,
name|s
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|pruse
argument_list|(
argument|fp
argument_list|,
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|FILEP
name|fp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"\t%s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|prskip
argument_list|(
argument|fp
argument_list|,
argument|k
argument_list|)
end_macro

begin_decl_stmt
name|FILEP
name|fp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ftnint
name|k
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"\t.space\t%ld\n"
argument_list|,
name|k
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|prcomblock
argument_list|(
argument|fp
argument_list|,
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|FILEP
name|fp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|fp
argument_list|,
name|LABELFMT
argument_list|,
name|name
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

