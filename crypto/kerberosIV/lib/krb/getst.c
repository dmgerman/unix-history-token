begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    Copyright (C) 1989 by the Massachusetts Institute of Technology     Export of this software from the United States of America is assumed    to require a specific license from the United States Government.    It is the responsibility of any person or organization contemplating    export to obtain such a license before exporting.  WITHIN THAT CONSTRAINT, permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty.    */
end_comment

begin_include
include|#
directive|include
file|"krb_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: getst.c,v 1.6 1997/03/23 03:53:11 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * getst() takes a file descriptor, a string and a count.  It reads  * from the file until either it has read "count" characters, or until  * it reads a null byte.  When finished, what has been read exists in  * the given string "s".  If "count" characters were actually read, the  * last is changed to a null, so the returned string is always null-  * terminated.  getst() returns the number of characters read, including  * the null terminator.  */
end_comment

begin_function
name|int
name|getst
parameter_list|(
name|int
name|fd
parameter_list|,
name|char
modifier|*
name|s
parameter_list|,
name|int
name|n
parameter_list|)
block|{
name|int
name|count
init|=
name|n
decl_stmt|;
while|while
condition|(
name|read
argument_list|(
name|fd
argument_list|,
name|s
argument_list|,
literal|1
argument_list|)
operator|>
literal|0
operator|&&
operator|--
name|count
condition|)
if|if
condition|(
operator|*
name|s
operator|++
operator|==
literal|'\0'
condition|)
return|return
operator|(
name|n
operator|-
name|count
operator|)
return|;
operator|*
name|s
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|n
operator|-
name|count
operator|)
return|;
block|}
end_function

end_unit

