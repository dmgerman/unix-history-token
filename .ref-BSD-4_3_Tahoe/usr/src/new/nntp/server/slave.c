begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)slave.c	1.3	(Berkeley) 6/26/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_comment
comment|/*  * SLAVE  *  * note slave status, which is actually unimplemented.  */
end_comment

begin_macro
name|slave
argument_list|(
argument|argc
argument_list|,
argument|argv
argument_list|)
end_macro

begin_decl_stmt
name|int
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"%d Kinky, kinky.  I don't support such perversions.\r\n"
argument_list|,
name|OK_SLAVE
argument_list|)
expr_stmt|;
comment|/* Thanks Serge! */
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

