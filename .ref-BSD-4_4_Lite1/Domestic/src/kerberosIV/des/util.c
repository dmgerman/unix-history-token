begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /mit/kerberos/src/lib/des/RCS/util.c,v $  * $Author: jtkohl $  *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * Miscellaneous debug printing utilities  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid_util_c
index|[]
init|=
literal|"$Header: util.c,v 4.8 89/05/30 21:44:12 jtkohl Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<des.h>
end_include

begin_macro
name|des_cblock_print_file
argument_list|(
argument|x
argument_list|,
argument|fp
argument_list|)
end_macro

begin_decl_stmt
name|des_cblock
modifier|*
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|fp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|unsigned
name|char
modifier|*
name|y
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|x
decl_stmt|;
specifier|register
name|int
name|i
init|=
literal|0
decl_stmt|;
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|" 0x { "
argument_list|)
expr_stmt|;
while|while
condition|(
name|i
operator|++
operator|<
literal|8
condition|)
block|{
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%x"
argument_list|,
operator|*
name|y
operator|++
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|<
literal|8
condition|)
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|", "
argument_list|)
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|" }"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

