begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)rand.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_decl_stmt
specifier|static
name|long
name|randx
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_macro
name|srand
argument_list|(
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|unsigned
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|randx
operator|=
name|x
expr_stmt|;
block|}
end_block

begin_macro
name|rand
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
operator|(
name|randx
operator|=
name|randx
operator|*
literal|1103515245
operator|+
literal|12345
operator|)
operator|&
literal|0x7fffffff
operator|)
return|;
block|}
end_block

end_unit

