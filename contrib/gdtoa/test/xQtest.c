begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************  The author of this software is David M. Gay.  Copyright (C) 2002 by Lucent Technologies All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that the copyright notice and this permission notice and warranty disclaimer appear in supporting documentation, and that the name of Lucent or any of its entities not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  LUCENT DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL LUCENT OR ANY OF ITS ENTITIES BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ****************************************************************/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
switch|switch
condition|(
expr|sizeof
operator|(
name|long
name|double
operator|)
condition|)
block|{
case|case
literal|10
case|:
case|case
literal|12
case|:
name|printf
argument_list|(
literal|"cp x.ou1 x.out; cp xL.ou1 xL.out; cp Q.ou0 Q.out\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|16
case|:
name|printf
argument_list|(
literal|"cp x.ou0 x.out; cp xL.ou0 xL.out; cp Q.ou1 Q.out\n"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"cp x.ou0 x.out; cp xL.ou0 xL.out; cp Q.ou0 Q.out\n"
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

