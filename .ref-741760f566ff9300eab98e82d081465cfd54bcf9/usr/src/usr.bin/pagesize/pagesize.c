begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1983 Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

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
literal|"@(#)pagesize.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_function
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|getpagesize
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

