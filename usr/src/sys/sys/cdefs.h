begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)cdefs.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * This file is designed to ease the porting from standard C to ANSI C.  * It will eventually go away.  * Questions to K. Bostic.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
end_if

begin_define
define|#
directive|define
name|CONCAT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x ## y
end_define

begin_define
define|#
directive|define
name|PROTOTYPE
parameter_list|(
name|p
parameter_list|)
value|p
end_define

begin_define
define|#
directive|define
name|STRING
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|const
end_define

begin_define
define|#
directive|define
name|volatile
end_define

begin_define
define|#
directive|define
name|signed
end_define

begin_define
define|#
directive|define
name|CONCAT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x
comment|/**/
value|y
end_define

begin_define
define|#
directive|define
name|PROTOTYPE
parameter_list|(
name|p
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|STRING
parameter_list|(
name|x
parameter_list|)
value|"x"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

