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
specifier|register
name|int
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|".byte "
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|SZSHORT
condition|;
operator|++
name|i
control|)
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%o%c"
argument_list|,
operator|*
name|s
operator|++
argument_list|,
operator|(
name|i
operator|==
name|SZSHORT
operator|-
literal|1
condition|?
literal|'\n'
else|:
literal|','
operator|)
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
literal|"%s\n"
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
comment|/* works around bug in the pdp11 assembler that bombs on  . = .+x  for x>= 32768 */
for|for
control|(
init|;
name|k
operator|>
literal|30000
condition|;
name|k
operator|-=
literal|30000
control|)
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"\t. = .+30000.\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"\t. = .+%ld.\n"
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

