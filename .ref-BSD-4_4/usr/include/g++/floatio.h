begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	%W% (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Floating point scanf/printf (input/output) definitions.  */
end_comment

begin_comment
comment|/* 11-bit exponent (VAX G floating point) is 308 decimal digits */
end_comment

begin_define
define|#
directive|define
name|MAXEXP
value|308
end_define

begin_comment
comment|/* 128 bit fraction takes up 39 decimal digits; max reasonable precision */
end_comment

begin_define
define|#
directive|define
name|MAXFRACT
value|39
end_define

end_unit

