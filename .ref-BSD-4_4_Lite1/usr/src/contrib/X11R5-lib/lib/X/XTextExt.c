begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: XTextExt.c,v 11.26 91/01/06 11:48:29 rws Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  */
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_include
include|#
directive|include
file|"Xlibint.h"
end_include

begin_define
define|#
directive|define
name|min_byte2
value|min_char_or_byte2
end_define

begin_define
define|#
directive|define
name|max_byte2
value|max_char_or_byte2
end_define

begin_comment
comment|/*   * CI_GET_ROWZERO_CHAR_INFO_2D - do the same thing as CI_GET_CHAR_INFO_1D,  * except that the font has more than one row.  This is special case of more  * general version used in XTextExt16.c since row == 0.  This is used when  * max_byte2 is not zero.  A further optimization would do the check for  * min_byte1 being zero ahead of time.  */
end_comment

begin_define
define|#
directive|define
name|CI_GET_ROWZERO_CHAR_INFO_2D
parameter_list|(
name|fs
parameter_list|,
name|col
parameter_list|,
name|def
parameter_list|,
name|cs
parameter_list|)
define|\
value|{ \     cs = def; \     if (fs->min_byte1 == 0&& \ 	col>= fs->min_byte2&& col<= fs->max_byte2) { \ 	if (fs->per_char == NULL) { \ 	    cs =&fs->min_bounds; \ 	} else { \ 	    cs =&fs->per_char[(col - fs->min_byte2)]; \ 	    if (CI_NONEXISTCHAR(cs)) cs = def; \ 	} \     } \ }
end_define

begin_comment
comment|/*  * XTextExtents - compute the extents of string given as a sequences of eight  * bit bytes.  Since we know that the input characters will always be from the  * first row of the font (i.e. byte1 == 0), we can do some optimizations beyond  * what is done in XTextExtents16.  */
end_comment

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|XTextExtents
argument_list|(
argument|XFontStruct *fs
argument_list|,
argument|_Xconst char *string
argument_list|,
argument|int nchars
argument_list|,
argument|int *dir
argument_list|,
comment|/* RETURN font information */
argument|int *font_ascent
argument_list|,
comment|/* RETURN font information */
argument|int *font_descent
argument_list|,
comment|/* RETURN font information */
argument|register XCharStruct *overall
argument_list|)
end_macro

begin_comment
comment|/* RETURN character information */
end_comment

begin_else
else|#
directive|else
end_else

begin_macro
name|XTextExtents
argument_list|(
argument|fs
argument_list|,
argument|string
argument_list|,
argument|nchars
argument_list|,
argument|dir
argument_list|,
argument|font_ascent
argument_list|,
argument|font_descent
argument_list|,
argument|overall
argument_list|)
end_macro

begin_decl_stmt
name|XFontStruct
modifier|*
name|fs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nchars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|dir
decl_stmt|,
modifier|*
name|font_ascent
decl_stmt|,
modifier|*
name|font_descent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RETURN font information */
end_comment

begin_decl_stmt
specifier|register
name|XCharStruct
modifier|*
name|overall
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RETURN character information */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|int
name|i
decl_stmt|;
comment|/* iterator */
name|Bool
name|singlerow
init|=
operator|(
name|fs
operator|->
name|max_byte1
operator|==
literal|0
operator|)
decl_stmt|;
comment|/* optimization */
name|int
name|nfound
init|=
literal|0
decl_stmt|;
comment|/* number of characters found */
name|XCharStruct
modifier|*
name|def
decl_stmt|;
comment|/* info about default char */
name|unsigned
name|char
modifier|*
name|us
decl_stmt|;
comment|/* be 8bit clean */
if|if
condition|(
name|singlerow
condition|)
block|{
comment|/* optimization */
name|CI_GET_DEFAULT_INFO_1D
argument_list|(
name|fs
argument_list|,
name|def
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|CI_GET_DEFAULT_INFO_2D
argument_list|(
name|fs
argument_list|,
name|def
argument_list|)
expr_stmt|;
block|}
operator|*
name|dir
operator|=
name|fs
operator|->
name|direction
expr_stmt|;
operator|*
name|font_ascent
operator|=
name|fs
operator|->
name|ascent
expr_stmt|;
operator|*
name|font_descent
operator|=
name|fs
operator|->
name|descent
expr_stmt|;
comment|/*      * Iterate over the input string getting the appropriate * char struct.      * The default (which may be null if there is no def_char) will be returned      * if the character doesn't exist.  On the first time * through the loop,      * assign the values to overall; otherwise, compute * the new values.      */
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|us
operator|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|string
init|;
name|i
operator|<
name|nchars
condition|;
name|i
operator|++
operator|,
name|us
operator|++
control|)
block|{
specifier|register
name|unsigned
name|uc
init|=
operator|(
name|unsigned
operator|)
operator|*
name|us
decl_stmt|;
comment|/* since about to do macro */
specifier|register
name|XCharStruct
modifier|*
name|cs
decl_stmt|;
if|if
condition|(
name|singlerow
condition|)
block|{
comment|/* optimization */
name|CI_GET_CHAR_INFO_1D
argument_list|(
name|fs
argument_list|,
name|uc
argument_list|,
name|def
argument_list|,
name|cs
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|CI_GET_ROWZERO_CHAR_INFO_2D
argument_list|(
name|fs
argument_list|,
name|uc
argument_list|,
name|def
argument_list|,
name|cs
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|cs
condition|)
block|{
if|if
condition|(
name|nfound
operator|++
operator|==
literal|0
condition|)
block|{
operator|*
name|overall
operator|=
operator|*
name|cs
expr_stmt|;
block|}
else|else
block|{
name|overall
operator|->
name|ascent
operator|=
name|max
argument_list|(
name|overall
operator|->
name|ascent
argument_list|,
name|cs
operator|->
name|ascent
argument_list|)
expr_stmt|;
name|overall
operator|->
name|descent
operator|=
name|max
argument_list|(
name|overall
operator|->
name|descent
argument_list|,
name|cs
operator|->
name|descent
argument_list|)
expr_stmt|;
name|overall
operator|->
name|lbearing
operator|=
name|min
argument_list|(
name|overall
operator|->
name|lbearing
argument_list|,
name|overall
operator|->
name|width
operator|+
name|cs
operator|->
name|lbearing
argument_list|)
expr_stmt|;
name|overall
operator|->
name|rbearing
operator|=
name|max
argument_list|(
name|overall
operator|->
name|rbearing
argument_list|,
name|overall
operator|->
name|width
operator|+
name|cs
operator|->
name|rbearing
argument_list|)
expr_stmt|;
name|overall
operator|->
name|width
operator|+=
name|cs
operator|->
name|width
expr_stmt|;
block|}
block|}
block|}
comment|/*      * if there were no characters, then set everything to 0      */
if|if
condition|(
name|nfound
operator|==
literal|0
condition|)
block|{
name|overall
operator|->
name|width
operator|=
name|overall
operator|->
name|ascent
operator|=
name|overall
operator|->
name|descent
operator|=
name|overall
operator|->
name|lbearing
operator|=
name|overall
operator|->
name|rbearing
operator|=
literal|0
expr_stmt|;
block|}
return|return;
block|}
end_block

begin_comment
comment|/*  * XTextWidth - compute the width of a string of eightbit bytes.  This is a   * subset of XTextExtents.  */
end_comment

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_function
name|int
name|XTextWidth
parameter_list|(
name|XFontStruct
modifier|*
name|fs
parameter_list|,
name|_Xconst
name|char
modifier|*
name|string
parameter_list|,
name|int
name|count
parameter_list|)
else|#
directive|else
function|int XTextWidth
parameter_list|(
name|fs
parameter_list|,
name|string
parameter_list|,
name|count
parameter_list|)
name|XFontStruct
modifier|*
name|fs
decl_stmt|;
name|char
modifier|*
name|string
decl_stmt|;
name|int
name|count
decl_stmt|;
endif|#
directive|endif
block|{
name|int
name|i
decl_stmt|;
comment|/* iterator */
name|Bool
name|singlerow
init|=
operator|(
name|fs
operator|->
name|max_byte1
operator|==
literal|0
operator|)
decl_stmt|;
comment|/* optimization */
name|XCharStruct
modifier|*
name|def
decl_stmt|;
comment|/* info about default char */
name|unsigned
name|char
modifier|*
name|us
decl_stmt|;
comment|/* be 8bit clean */
name|int
name|width
init|=
literal|0
decl_stmt|;
comment|/* RETURN value */
if|if
condition|(
name|singlerow
condition|)
block|{
comment|/* optimization */
name|CI_GET_DEFAULT_INFO_1D
argument_list|(
name|fs
argument_list|,
name|def
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|CI_GET_DEFAULT_INFO_2D
argument_list|(
name|fs
argument_list|,
name|def
argument_list|)
expr_stmt|;
block|}
comment|/*      * Iterate over all character in the input string; only consider characters      * that exist.      */
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|us
operator|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|string
init|;
name|i
operator|<
name|count
condition|;
name|i
operator|++
operator|,
name|us
operator|++
control|)
block|{
specifier|register
name|unsigned
name|uc
init|=
operator|(
name|unsigned
operator|)
operator|*
name|us
decl_stmt|;
comment|/* since about to do macro */
specifier|register
name|XCharStruct
modifier|*
name|cs
decl_stmt|;
if|if
condition|(
name|singlerow
condition|)
block|{
comment|/* optimization */
name|CI_GET_CHAR_INFO_1D
argument_list|(
name|fs
argument_list|,
name|uc
argument_list|,
name|def
argument_list|,
name|cs
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|CI_GET_ROWZERO_CHAR_INFO_2D
argument_list|(
name|fs
argument_list|,
name|uc
argument_list|,
name|def
argument_list|,
name|cs
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|cs
condition|)
name|width
operator|+=
name|cs
operator|->
name|width
expr_stmt|;
block|}
return|return
name|width
return|;
block|}
end_function

end_unit

