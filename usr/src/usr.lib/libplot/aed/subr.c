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
literal|"@(#)subr.c	5.2 (Berkeley) 4/30/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|"aed.h"
end_include

begin_comment
comment|/*  * The following table is used to convert numbers to hex.  We cannot use  * standard C library conversion because it generates lower case letters  * which are bad news to the AED512.  */
end_comment

begin_decl_stmt
specifier|static
name|char
name|hex
index|[]
init|=
literal|"0123456789ABCDEF"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*---------------------------------------------------------  *	This is a local routine that converts an integer to a string  *	of hexadecimal characters.  *  *	Results:	None.  *  *	Side Effects:  *	The string contains the value of the low-order nchars 4-bit chunks  *	of val, as represented in hexadecimal.  String is zero-filled.  *---------------------------------------------------------  */
end_comment

begin_macro
name|chex
argument_list|(
argument|val
argument_list|,
argument|string
argument_list|,
argument|nchars
argument_list|)
end_macro

begin_decl_stmt
name|int
name|val
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Integer value to be converted. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to area for converted result. */
end_comment

begin_decl_stmt
name|int
name|nchars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of characters to be converted. */
end_comment

begin_block
block|{
name|string
operator|=
operator|&
operator|(
name|string
index|[
name|nchars
index|]
operator|)
expr_stmt|;
operator|*
name|string
operator|=
literal|'\0'
expr_stmt|;
for|for
control|(
init|;
name|nchars
operator|>
literal|0
condition|;
name|nchars
operator|--
control|)
block|{
operator|*
operator|(
operator|--
name|string
operator|)
operator|=
name|hex
index|[
name|val
operator|&
literal|017
index|]
expr_stmt|;
name|val
operator|>>=
literal|4
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*---------------------------------------------------------  *	This local routine outputs an x-y coordinate pair in the standard  *	format required by the AED display.  *  *	Results:	None.  *	  *	Side Effects:  *	Characters are output to the AED512 in the standard way required  *	for values indicated by "xy20" in the user manual.  *  *	Errors:		None.  *---------------------------------------------------------  */
end_comment

begin_macro
name|outxy20
argument_list|(
argument|x
argument_list|,
argument|y
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The coordinates to be output.  Note: 				 * these are world coordinates, not screen 				 * ones.  We scale in this routine. 				 */
end_comment

begin_block
block|{
name|char
name|s1
index|[
literal|4
index|]
decl_stmt|,
name|s2
index|[
literal|4
index|]
decl_stmt|,
name|s3
index|[
literal|4
index|]
decl_stmt|;
name|x
operator|=
operator|(
operator|(
name|x
operator|-
name|xbot
operator|)
operator|*
name|scale
operator|)
operator|>>
literal|12
expr_stmt|;
name|y
operator|=
operator|(
operator|(
name|y
operator|-
name|ybot
operator|)
operator|*
name|scale
operator|)
operator|>>
literal|12
expr_stmt|;
name|chex
argument_list|(
operator|(
operator|(
name|y
operator|>>
literal|8
operator|)
operator|&
literal|03
operator|)
operator||
operator|(
operator|(
name|x
operator|>>
literal|6
operator|)
operator|&
literal|014
operator|)
argument_list|,
name|s1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|chex
argument_list|(
name|x
operator|&
literal|0377
argument_list|,
name|s2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|chex
argument_list|(
name|y
operator|&
literal|0377
argument_list|,
name|s3
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"%s%s%s"
argument_list|,
name|s1
argument_list|,
name|s2
argument_list|,
name|s3
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*---------------------------------------------------------  *	This routine sets the display's current color.  *  *	Results:	None.  *  *	Side Effects:  *	The current color in the display is set to pcolor, if it  *	isn't that already.  *---------------------------------------------------------  */
end_comment

begin_macro
name|setcolor
argument_list|(
argument|pcolor
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|pcolor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to a string giving the desired 				 * color in hexadecimal. 				 */
end_comment

begin_block
block|{
specifier|static
name|char
name|curcolor
index|[]
init|=
literal|"xx"
decl_stmt|;
if|if
condition|(
operator|(
name|pcolor
index|[
literal|0
index|]
operator|!=
name|curcolor
index|[
literal|0
index|]
operator|)
operator|||
operator|(
name|pcolor
index|[
literal|1
index|]
operator|!=
name|curcolor
index|[
literal|1
index|]
operator|)
condition|)
block|{
name|curcolor
index|[
literal|0
index|]
operator|=
name|pcolor
index|[
literal|0
index|]
expr_stmt|;
name|curcolor
index|[
literal|1
index|]
operator|=
name|pcolor
index|[
literal|1
index|]
expr_stmt|;
name|putc
argument_list|(
literal|'L'
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
name|curcolor
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

