begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Copyright (c) 1984-1987 by the Regents of the  *	University of California and by Gregory Glenn Minshall.  *  *	Permission to use, copy, modify, and distribute these  *	programs and their documentation for any purpose and  *	without fee is hereby granted, provided that this  *	copyright and permission appear on all copies and  *	supporting documentation, the name of the Regents of  *	the University of California not be used in advertising  *	or publicity pertaining to distribution of the programs  *	without specific prior permission, and notice be given in  *	supporting documentation that copying and distribution is  *	by permission of the Regents of the University of California  *	and by Gregory Glenn Minshall.  Neither the Regents of the  *	University of California nor Gregory Glenn Minshall make  *	representations about the suitability of this software  *	for any purpose.  It is provided "as is" without  *	express or implied warranty.  */
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
literal|"@(#)mkastods.c	1.4 (Berkeley) %G%"
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
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|unix
argument_list|)
end_if

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(unix) */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(unix) */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"../api/asc_ebc.h"
end_include

begin_include
include|#
directive|include
file|"../api/ebc_disp.h"
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
comment|/* For each ascii code, find the display code that matches */
name|printf
argument_list|(
literal|"unsigned char asc_disp[256] = {"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NASCII
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|i
operator|%
literal|8
operator|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\t0x%02x,"
argument_list|,
name|ebc_disp
index|[
name|asc_ebc
index|[
name|i
index|]
index|]
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
sizeof|sizeof
name|disp_ebc
init|;
name|i
operator|<
literal|256
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|i
operator|%
literal|8
operator|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\t0x%02x,"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n};\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

