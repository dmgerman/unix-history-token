begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator   or   Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the rights  * to redistribute these changes.  */
end_comment

begin_comment
comment|/*  path  --  break filename into directory and file  *  *  path (filename,direc,file);  *  char *filename,*direc,*file;  *  filename is input; direc and file are output (user-supplied).  *  file will not have any trailing /; direc might.  *  *  Note these rules:  *  1.  trailing / are ignored (except as first character)  *  2.  x/y is x;y where y contains no / (x may contain /)  *  3.  /y  is /;y where y contains no /  *  4.  y   is .;y where y contains no /  *  5.      is .;. (null filename)  *  6.  /   is /;. (the root directory)  *  * Algorithm is this:  *  1.  delete trailing / except in first position  *  2.  if any /, find last one; change to null; y++  *      else y = x;		(x is direc; y is file)  *  3.  if y is null, y = .  *  4.  if x equals y, x = .  *      else if x is null, x = /  *  *  HISTORY  * 20-Nov-79  Steven Shafer (sas) at Carnegie-Mellon University  *	Copied verbatim from PDP-11.  Still as messy as ever.  *	Some people have asked for a modification (I think that's a better  *	idea than a new routine) which will change the directory name  *	into an absolute pathname if it isn't one already.  The change  *	involves doing a getwd() and prepending that if appropriate, with  *	a "/" in between that and the directory part of the path.  *	If you want to be cute, you can also resolve ".."s at that time.  *  */
end_comment

begin_macro
name|path
argument_list|(
argument|original
argument_list|,
argument|direc
argument_list|,
argument|file
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|original
decl_stmt|,
modifier|*
name|direc
decl_stmt|,
modifier|*
name|file
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|y
decl_stmt|;
comment|/* x is direc */
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
comment|/* copy and note the end */
name|p
operator|=
name|original
expr_stmt|;
name|y
operator|=
name|direc
expr_stmt|;
while|while
condition|(
operator|*
name|y
operator|++
operator|=
operator|*
name|p
operator|++
condition|)
empty_stmt|;
comment|/* copy string */
comment|/* y now points to first char after null */
operator|--
name|y
expr_stmt|;
comment|/* y now points to null */
operator|--
name|y
expr_stmt|;
comment|/* y now points to last char of string before null */
comment|/* chop off trailing / except as first character */
while|while
condition|(
name|y
operator|>
name|direc
operator|&&
operator|*
name|y
operator|==
literal|'/'
condition|)
operator|--
name|y
expr_stmt|;
comment|/* backpedal past / */
comment|/* y now points to char before first trailing / or null */
operator|*
operator|(
operator|++
name|y
operator|)
operator|=
literal|0
expr_stmt|;
comment|/* chop off end of string */
comment|/* y now points to null */
comment|/* find last /, if any.  If found, change to null and bump y */
while|while
condition|(
name|y
operator|>
name|direc
operator|&&
operator|*
name|y
operator|!=
literal|'/'
condition|)
operator|--
name|y
expr_stmt|;
comment|/* y now points to / or direc.  Note *direc may be / */
if|if
condition|(
operator|*
name|y
operator|==
literal|'/'
condition|)
block|{
operator|*
name|y
operator|++
operator|=
literal|0
expr_stmt|;
block|}
comment|/* find file name part */
if|if
condition|(
operator|*
name|y
condition|)
name|strcpy
argument_list|(
name|file
argument_list|,
name|y
argument_list|)
expr_stmt|;
else|else
name|strcpy
argument_list|(
name|file
argument_list|,
literal|"."
argument_list|)
expr_stmt|;
comment|/* find directory part */
if|if
condition|(
name|direc
operator|==
name|y
condition|)
name|strcpy
argument_list|(
name|direc
argument_list|,
literal|"."
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|*
name|direc
operator|==
literal|0
condition|)
name|strcpy
argument_list|(
name|direc
argument_list|,
literal|"/"
argument_list|)
expr_stmt|;
comment|/* else direc already has proper value */
block|}
end_block

end_unit

