begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jeffrey Mogul.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)swab.c	5.8 (Berkeley) 6/27/90"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_function
name|void
name|swab
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|n
parameter_list|)
specifier|register
name|char
modifier|*
name|from
decl_stmt|,
decl|*
name|to
decl_stmt|;
end_function

begin_decl_stmt
specifier|register
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|unsigned
name|long
name|temp
decl_stmt|;
name|n
operator|>>=
literal|1
expr_stmt|;
name|n
operator|++
expr_stmt|;
define|#
directive|define
name|STEP
value|temp = *from++,*to++ = *from++,*to++ = temp
comment|/* round to multiple of 8 */
while|while
condition|(
operator|(
operator|--
name|n
operator|)
operator|&
literal|07
condition|)
name|STEP
expr_stmt|;
name|n
operator|>>=
literal|3
expr_stmt|;
while|while
condition|(
operator|--
name|n
operator|>=
literal|0
condition|)
block|{
name|STEP
expr_stmt|;
name|STEP
expr_stmt|;
name|STEP
expr_stmt|;
name|STEP
expr_stmt|;
name|STEP
expr_stmt|;
name|STEP
expr_stmt|;
name|STEP
expr_stmt|;
name|STEP
expr_stmt|;
block|}
block|}
end_block

end_unit

