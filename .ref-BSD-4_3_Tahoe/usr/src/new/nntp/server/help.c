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
literal|"@(#)help.c	1.7	(Berkeley) 6/26/87"
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
comment|/*  * HELP  *  * Provide a naive user with a brief help message.  *  */
end_comment

begin_macro
name|help
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
literal|"%d This server accepts the following commands:\r\n"
argument_list|,
name|INF_HELP
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"ARTICLE     BODY         GROUP\r\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"HEAD        LAST         LIST\r\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"NEXT        POST         QUIT\r\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"STAT        NEWGROUPS    HELP\r\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"IHAVE       NEWNEWS      SLAVE\r\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\r\nAdditionally, the following extention is supported:\r\n\r\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"XHDR        Retrieve a single header line from a range of articles.\r\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\r\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Bugs to Phil Lapsley (Internet: phil@berkeley.edu; UUCP: ...!ucbvax!phil)\r\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".\r\n"
argument_list|)
expr_stmt|;
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

