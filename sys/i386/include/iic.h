begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: iic.h,v 1.1.2.1 1998/07/17 00:54:01 son Exp $  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IIC_H
end_ifndef

begin_define
define|#
directive|define
name|__IIC_H
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|I2CSTART
value|_IO('i', 1)
end_define

begin_comment
comment|/* start condition */
end_comment

begin_define
define|#
directive|define
name|I2CSTOP
value|_IO('i', 2)
end_define

begin_comment
comment|/* stop condition */
end_comment

begin_define
define|#
directive|define
name|I2CADDRESS
value|_IOW('i', 3, long)
end_define

begin_comment
comment|/* address bus */
end_comment

begin_define
define|#
directive|define
name|I2CRSTCARD
value|_IOW('i', 4, long)
end_define

begin_comment
comment|/* reset the card */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

