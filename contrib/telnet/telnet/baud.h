begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 EMC Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Try to guess whether speeds are "encoded" (4.2BSD) or just numeric (4.4BSD).  */
end_comment

begin_if
if|#
directive|if
name|B4800
operator|!=
literal|4800
end_if

begin_define
define|#
directive|define
name|DECODE_BAUD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DECODE_BAUD
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|B7200
end_ifndef

begin_define
define|#
directive|define
name|B7200
value|B4800
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|B14400
end_ifndef

begin_define
define|#
directive|define
name|B14400
value|B9600
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|B19200
end_ifndef

begin_define
define|#
directive|define
name|B19200
value|B14400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|B28800
end_ifndef

begin_define
define|#
directive|define
name|B28800
value|B19200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|B38400
end_ifndef

begin_define
define|#
directive|define
name|B38400
value|B28800
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|B57600
end_ifndef

begin_define
define|#
directive|define
name|B57600
value|B38400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|B76800
end_ifndef

begin_define
define|#
directive|define
name|B76800
value|B57600
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|B115200
end_ifndef

begin_define
define|#
directive|define
name|B115200
value|B76800
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|B115200
end_ifndef

begin_define
define|#
directive|define
name|B115200
value|B76800
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|B230400
end_ifndef

begin_define
define|#
directive|define
name|B230400
value|B115200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * A table of available terminal speeds  */
end_comment

begin_decl_stmt
name|struct
name|termspeeds
name|termspeeds
index|[]
init|=
block|{
block|{
literal|0
block|,
name|B0
block|}
block|,
block|{
literal|50
block|,
name|B50
block|}
block|,
block|{
literal|75
block|,
name|B75
block|}
block|,
block|{
literal|110
block|,
name|B110
block|}
block|,
block|{
literal|134
block|,
name|B134
block|}
block|,
block|{
literal|150
block|,
name|B150
block|}
block|,
block|{
literal|200
block|,
name|B200
block|}
block|,
block|{
literal|300
block|,
name|B300
block|}
block|,
block|{
literal|600
block|,
name|B600
block|}
block|,
block|{
literal|1200
block|,
name|B1200
block|}
block|,
block|{
literal|1800
block|,
name|B1800
block|}
block|,
block|{
literal|2400
block|,
name|B2400
block|}
block|,
block|{
literal|4800
block|,
name|B4800
block|}
block|,
ifdef|#
directive|ifdef
name|B7200
block|{
literal|7200
block|,
name|B7200
block|}
block|,
endif|#
directive|endif
block|{
literal|9600
block|,
name|B9600
block|}
block|,
ifdef|#
directive|ifdef
name|B14400
block|{
literal|14400
block|,
name|B14400
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B19200
block|{
literal|19200
block|,
name|B19200
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B28800
block|{
literal|28800
block|,
name|B28800
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B38400
block|{
literal|38400
block|,
name|B38400
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B57600
block|{
literal|57600
block|,
name|B57600
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B115200
block|{
literal|115200
block|,
name|B115200
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B230400
block|{
literal|230400
block|,
name|B230400
block|}
block|,
endif|#
directive|endif
block|{
operator|-
literal|1
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

