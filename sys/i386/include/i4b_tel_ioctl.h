begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_tel_ioctl.h telephony interface ioctls  *	------------------------------------------  *  * $FreeBSD$   *  *      last edit-date: [Sat Dec  5 18:37:36 1998]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_TEL_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_TEL_IOCTL_H_
end_define

begin_comment
comment|/* supported audio format conversions for /dev/i4btelXX devices */
end_comment

begin_define
define|#
directive|define
name|CVT_NONE
value|0
end_define

begin_comment
comment|/* no format conversion	*/
end_comment

begin_define
define|#
directive|define
name|CVT_ALAW2ULAW
value|1
end_define

begin_comment
comment|/* kernel A-law, userland mu-law */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	get / set audio format   *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|I4B_TEL_GETAUDIOFMT
value|_IOR('A', 0, int)
end_define

begin_define
define|#
directive|define
name|I4B_TEL_SETAUDIOFMT
value|_IOW('A', 1, int)
end_define

begin_define
define|#
directive|define
name|I4B_TEL_EMPTYINPUTQUEUE
value|_IOW('A', 2, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_TEL_IOCTL_H_ */
end_comment

end_unit

