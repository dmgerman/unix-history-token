begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)tf.c	4.2 8/11/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tf.c: save and restore fill mode around table */
end_comment

begin_include
include|#
directive|include
file|"t..c"
end_include

begin_macro
name|savefill
argument_list|()
end_macro

begin_block
block|{
comment|/* remembers various things: fill mode, vs, ps in mac 35 (SF) */
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".de %d\n"
argument_list|,
name|SF
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".ps \\n(.s\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".vs \\n(.vu\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".in \\n(.iu\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".if \\n(.u .fi\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".if \\n(.j .ad\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".if \\n(.j=0 .na\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|"..\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".nf\n"
argument_list|)
expr_stmt|;
comment|/* set obx offset if useful */
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".nr #~ 0\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".if n .nr #~ 0.6n\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|rstofill
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".%d\n"
argument_list|,
name|SF
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|endoff
argument_list|()
end_macro

begin_block
block|{
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
name|MAXHEAD
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|linestop
index|[
name|i
index|]
condition|)
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".nr #%c 0\n"
argument_list|,
literal|'a'
operator|+
name|i
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
name|texct
condition|;
name|i
operator|++
control|)
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".rm %c+\n"
argument_list|,
name|texstr
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|"%s\n"
argument_list|,
name|last
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ifdivert
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".ds #d .d\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".if \\(ts\\n(.z\\(ts\\(ts .ds #d nl\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|saveline
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".if \\n+(b.=1 .nr d. \\n(.c-\\n(c.-1\n"
argument_list|)
expr_stmt|;
name|linstart
operator|=
name|iline
expr_stmt|;
block|}
end_block

begin_macro
name|restline
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".if \\n-(b.=0 .nr c. \\n(.c-\\n(d.-%d\n"
argument_list|,
name|iline
operator|-
name|linstart
argument_list|)
expr_stmt|;
name|linstart
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_macro
name|cleanfc
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|tabout
argument_list|,
literal|".fc\n"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

