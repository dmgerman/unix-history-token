begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved. The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|Msccsid
index|[]
init|=
literal|"@(#)Mesgfix	5.2 (Berkeley) 1/8/86"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)message.c	4.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_decl_stmt
name|char
modifier|*
name|message
index|[]
init|=
block|{
literal|"Last update on Saturday, January 11, 1986."
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

