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
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)setgid.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Backwards compatible setgid.  */
end_comment

begin_macro
name|setgid
argument_list|(
argument|gid
argument_list|)
end_macro

begin_decl_stmt
name|int
name|gid
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|setregid
argument_list|(
name|gid
argument_list|,
name|gid
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

