begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Jean-Marc Zucconi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_JOYSTICK_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_JOYSTICK_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_struct
struct|struct
name|joystick
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
name|int
name|b1
decl_stmt|;
name|int
name|b2
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|JOY_SETTIMEOUT
value|_IOW('J', 1, int)
end_define

begin_comment
comment|/* set timeout */
end_comment

begin_define
define|#
directive|define
name|JOY_GETTIMEOUT
value|_IOR('J', 2, int)
end_define

begin_comment
comment|/* get timeout */
end_comment

begin_define
define|#
directive|define
name|JOY_SET_X_OFFSET
value|_IOW('J', 3, int)
end_define

begin_comment
comment|/* set offset on X-axis */
end_comment

begin_define
define|#
directive|define
name|JOY_SET_Y_OFFSET
value|_IOW('J', 4, int)
end_define

begin_comment
comment|/* set offset on X-axis */
end_comment

begin_define
define|#
directive|define
name|JOY_GET_X_OFFSET
value|_IOR('J', 5, int)
end_define

begin_comment
comment|/* get offset on X-axis */
end_comment

begin_define
define|#
directive|define
name|JOY_GET_Y_OFFSET
value|_IOR('J', 6, int)
end_define

begin_comment
comment|/* get offset on Y-axis */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_JOYSTICK_H_ */
end_comment

end_unit

