begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* maketree.c -- make inffixed.h table for decoding fixed codes  * Copyright (C) 1998 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h   */
end_comment

begin_comment
comment|/* WARNING: this file should *not* be used by applications. It is    part of the implementation of the compression library and is    subject to change. Applications should only use zlib.h.  */
end_comment

begin_comment
comment|/* This program is included in the distribution for completeness.    You do not need to compile or run this program since inffixed.h    is already included in the distribution.  To use this program    you need to compile zlib with BUILDFIXED defined and then compile    and link this program with the zlib library.  Then the output of    this program can be piped to inffixed.h. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"zutil.h"
end_include

begin_include
include|#
directive|include
file|"inftrees.h"
end_include

begin_comment
comment|/* simplify the use of the inflate_huft type with some defines */
end_comment

begin_define
define|#
directive|define
name|exop
value|word.what.Exop
end_define

begin_define
define|#
directive|define
name|bits
value|word.what.Bits
end_define

begin_comment
comment|/* generate initialization table for an inflate_huft structure array */
end_comment

begin_function
name|void
name|maketree
parameter_list|(
name|uInt
name|b
parameter_list|,
name|inflate_huft
modifier|*
name|t
parameter_list|)
block|{
name|int
name|i
decl_stmt|,
name|e
decl_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
name|e
operator|=
name|t
index|[
name|i
index|]
operator|.
name|exop
expr_stmt|;
if|if
condition|(
name|e
operator|&&
operator|(
name|e
operator|&
operator|(
literal|16
operator|+
literal|64
operator|)
operator|)
operator|==
literal|0
condition|)
comment|/* table pointer */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"maketree: cannot initialize sub-tables!\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|%
literal|4
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"\n   "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" {{{%u,%u}},%u}"
argument_list|,
name|t
index|[
name|i
index|]
operator|.
name|exop
argument_list|,
name|t
index|[
name|i
index|]
operator|.
name|bits
argument_list|,
name|t
index|[
name|i
index|]
operator|.
name|base
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
name|i
operator|==
operator|(
literal|1
operator|<<
name|b
operator|)
condition|)
break|break;
name|putchar
argument_list|(
literal|','
argument_list|)
expr_stmt|;
block|}
name|puts
argument_list|(
literal|""
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* create the fixed tables in C initialization syntax */
end_comment

begin_function
name|void
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|r
decl_stmt|;
name|uInt
name|bl
decl_stmt|,
name|bd
decl_stmt|;
name|inflate_huft
modifier|*
name|tl
decl_stmt|,
modifier|*
name|td
decl_stmt|;
name|z_stream
name|z
decl_stmt|;
name|z
operator|.
name|zalloc
operator|=
name|zcalloc
expr_stmt|;
name|z
operator|.
name|opaque
operator|=
operator|(
name|voidpf
operator|)
literal|0
expr_stmt|;
name|z
operator|.
name|zfree
operator|=
name|zcfree
expr_stmt|;
name|r
operator|=
name|inflate_trees_fixed
argument_list|(
operator|&
name|bl
argument_list|,
operator|&
name|bd
argument_list|,
operator|&
name|tl
argument_list|,
operator|&
name|td
argument_list|,
operator|&
name|z
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"inflate_trees_fixed error %d\n"
argument_list|,
name|r
argument_list|)
expr_stmt|;
return|return;
block|}
name|puts
argument_list|(
literal|"/* inffixed.h -- table for decoding fixed codes"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|" * Generated automatically by the maketree.c program"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|" */"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"/* WARNING: this file should *not* be used by applications. It is"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"   part of the implementation of the compression library and is"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"   subject to change. Applications should only use zlib.h."
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|" */"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"local uInt fixed_bl = %d;\n"
argument_list|,
name|bl
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"local uInt fixed_bd = %d;\n"
argument_list|,
name|bd
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"local inflate_huft fixed_tl[] = {"
argument_list|)
expr_stmt|;
name|maketree
argument_list|(
name|bl
argument_list|,
name|tl
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"  };"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"local inflate_huft fixed_td[] = {"
argument_list|)
expr_stmt|;
name|maketree
argument_list|(
name|bd
argument_list|,
name|td
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"  };"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

