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

begin_expr_stmt
name|label_
argument_list|(
name|s
argument_list|,
name|len
argument_list|)
specifier|register
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|long
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|buf
index|[
literal|260
index|]
decl_stmt|;
specifier|register
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|cend
decl_stmt|;
name|cp
operator|=
name|buf
expr_stmt|;
name|cend
operator|=
name|cp
operator|+
operator|(
name|len
operator|<
literal|255
condition|?
name|len
else|:
literal|255
operator|)
expr_stmt|;
while|while
condition|(
name|cp
operator|<
name|cend
condition|)
operator|*
name|cp
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
operator|*
name|cp
operator|=
literal|0
expr_stmt|;
name|label
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

