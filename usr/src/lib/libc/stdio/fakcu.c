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
literal|"@(#)fakcu.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Null cleanup routine to resolve reference in exit()   * if not using stdio.  */
end_comment

begin_macro
name|_cleanup
argument_list|()
end_macro

begin_block
block|{ }
end_block

end_unit

