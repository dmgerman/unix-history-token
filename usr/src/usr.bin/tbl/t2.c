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
literal|"@(#)t2.c	4.2 8/11/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* t2.c:  subroutine sequencing for one table */
end_comment

begin_include
include|#
directive|include
file|"t..c"
end_include

begin_macro
name|tableput
argument_list|()
end_macro

begin_block
block|{
name|saveline
argument_list|()
expr_stmt|;
name|savefill
argument_list|()
expr_stmt|;
name|ifdivert
argument_list|()
expr_stmt|;
name|cleanfc
argument_list|()
expr_stmt|;
name|getcomm
argument_list|()
expr_stmt|;
name|getspec
argument_list|()
expr_stmt|;
name|gettbl
argument_list|()
expr_stmt|;
name|getstop
argument_list|()
expr_stmt|;
name|checkuse
argument_list|()
expr_stmt|;
name|choochar
argument_list|()
expr_stmt|;
name|maktab
argument_list|()
expr_stmt|;
name|runout
argument_list|()
expr_stmt|;
name|release
argument_list|()
expr_stmt|;
name|rstofill
argument_list|()
expr_stmt|;
name|endoff
argument_list|()
expr_stmt|;
name|restline
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

