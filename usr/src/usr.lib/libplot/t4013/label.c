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
literal|"@(#)label.c	5.1 (Berkeley) 6/7/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_macro
name|label
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|i
operator|,
name|c
expr_stmt|;
name|putch
argument_list|(
literal|037
argument_list|)
expr_stmt|;
comment|/* alpha mode */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|c
operator|=
name|s
index|[
name|i
index|]
condition|;
name|i
operator|++
control|)
name|putch
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

