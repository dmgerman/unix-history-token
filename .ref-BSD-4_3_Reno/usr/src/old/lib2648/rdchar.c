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
literal|"@(#)rdchar.c	5.1 (Berkeley) 4/26/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * rdchar: returns a readable representation of an ASCII char, using ^ notation.  */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_function
name|char
modifier|*
name|rdchar
parameter_list|(
name|c
parameter_list|)
name|char
name|c
decl_stmt|;
block|{
specifier|static
name|char
name|ret
index|[
literal|4
index|]
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
comment|/* 	 * Due to a bug in isprint, this prints spaces as ^`, but this is OK 	 * because we want something to show up on the screen. 	 */
name|ret
index|[
literal|0
index|]
operator|=
operator|(
operator|(
name|c
operator|&
literal|0377
operator|)
operator|>
literal|0177
operator|)
condition|?
literal|'\''
else|:
literal|' '
expr_stmt|;
name|c
operator|&=
literal|0177
expr_stmt|;
name|ret
index|[
literal|1
index|]
operator|=
name|isprint
argument_list|(
name|c
argument_list|)
condition|?
literal|' '
else|:
literal|'^'
expr_stmt|;
name|ret
index|[
literal|2
index|]
operator|=
name|isprint
argument_list|(
name|c
argument_list|)
condition|?
name|c
else|:
name|c
operator|^
literal|0100
expr_stmt|;
name|ret
index|[
literal|3
index|]
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|p
operator|=
name|ret
init|;
operator|*
name|p
operator|==
literal|' '
condition|;
name|p
operator|++
control|)
empty_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

end_unit

