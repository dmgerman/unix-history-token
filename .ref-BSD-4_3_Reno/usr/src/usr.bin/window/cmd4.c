begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Edward Wang at The University of California, Berkeley.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)cmd4.c	3.18 (Berkeley) 6/6/90"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_macro
name|c_colon
argument_list|()
end_macro

begin_block
block|{
name|char
name|oldterse
init|=
name|terse
decl_stmt|;
name|char
name|buf
index|[
literal|512
index|]
decl_stmt|;
name|setterse
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|wwputc
argument_list|(
literal|':'
argument_list|,
name|cmdwin
argument_list|)
expr_stmt|;
name|wwgets
argument_list|(
name|buf
argument_list|,
name|wwncol
operator|-
literal|3
argument_list|,
name|cmdwin
argument_list|)
expr_stmt|;
name|wwputc
argument_list|(
literal|'\n'
argument_list|,
name|cmdwin
argument_list|)
expr_stmt|;
name|wwcurtowin
argument_list|(
name|cmdwin
argument_list|)
expr_stmt|;
name|setterse
argument_list|(
name|oldterse
argument_list|)
expr_stmt|;
if|if
condition|(
name|dolongcmd
argument_list|(
name|buf
argument_list|,
operator|(
expr|struct
name|value
operator|*
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
name|error
argument_list|(
literal|"Out of memory."
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

