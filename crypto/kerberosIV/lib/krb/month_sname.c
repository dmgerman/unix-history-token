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
literal|"$Id: month_sname.c,v 1.5 1997/03/23 03:53:14 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Given an integer 1-12, month_sname() returns a string  * containing the first three letters of the corresponding  * month.  Returns 0 if the argument is out of range.  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|month_sname
parameter_list|(
name|int
name|n
parameter_list|)
block|{
specifier|static
specifier|const
name|char
modifier|*
name|name
index|[]
init|=
block|{
literal|"Jan"
block|,
literal|"Feb"
block|,
literal|"Mar"
block|,
literal|"Apr"
block|,
literal|"May"
block|,
literal|"Jun"
block|,
literal|"Jul"
block|,
literal|"Aug"
block|,
literal|"Sep"
block|,
literal|"Oct"
block|,
literal|"Nov"
block|,
literal|"Dec"
block|}
decl_stmt|;
return|return
operator|(
operator|(
name|n
operator|<
literal|1
operator|||
name|n
operator|>
literal|12
operator|)
condition|?
literal|0
else|:
name|name
index|[
name|n
operator|-
literal|1
index|]
operator|)
return|;
block|}
end_function

end_unit

