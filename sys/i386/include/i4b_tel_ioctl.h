begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2002  Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_tel_ioctl.h telephony interface ioctls  *	------------------------------------------  *  * $FreeBSD$  *  *      last edit-date: [Sun Mar 17 10:10:39 2002]  *  *---------------------------------------------------------------------------*/
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
comment|/*===========================================================================*  *	/dev/i4btel<n> devices (audio data)  *===========================================================================*/
end_comment

begin_comment
comment|/* supported audio format conversions */
end_comment

begin_define
define|#
directive|define
name|CVT_NONE
value|0
end_define

begin_comment
comment|/* no A-law/u-law conversion     */
end_comment

begin_define
define|#
directive|define
name|CVT_ALAW2ULAW
value|1
end_define

begin_comment
comment|/* ISDN line: A-law, user: u-law */
end_comment

begin_define
define|#
directive|define
name|CVT_ULAW2ALAW
value|2
end_define

begin_comment
comment|/* ISDN line: u-law, user: A-law */
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

begin_comment
comment|/*---------------------------------------------------------------------------*  *	request version and release info from kernel part  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|I4B_TEL_VR_REQ
value|_IOR('A', 3, msg_vr_req_t)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	send tones out of the tel interface  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|I4B_TEL_MAXTONES
value|32
end_define

begin_struct
struct|struct
name|i4b_tel_tones
block|{
name|int
name|frequency
index|[
name|I4B_TEL_MAXTONES
index|]
decl_stmt|;
name|int
name|duration
index|[
name|I4B_TEL_MAXTONES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I4B_TEL_TONES
value|_IOR('A', 4, struct i4b_tel_tones)
end_define

begin_comment
comment|/*===========================================================================*  *	/dev/i4bteld<n> devices (dialer interface)  *===========================================================================*/
end_comment

begin_comment
comment|/* dialer commands */
end_comment

begin_define
define|#
directive|define
name|CMD_DIAL
value|'D'
end_define

begin_comment
comment|/* dial the following number string */
end_comment

begin_define
define|#
directive|define
name|CMD_HUP
value|'H'
end_define

begin_comment
comment|/* hangup */
end_comment

begin_define
define|#
directive|define
name|CMD_KEYP
value|'K'
end_define

begin_comment
comment|/* send keypad string */
end_comment

begin_comment
comment|/* dialer responses */
end_comment

begin_define
define|#
directive|define
name|RSP_CONN
value|'0'
end_define

begin_comment
comment|/* connect */
end_comment

begin_define
define|#
directive|define
name|RSP_BUSY
value|'1'
end_define

begin_comment
comment|/* busy */
end_comment

begin_define
define|#
directive|define
name|RSP_HUP
value|'2'
end_define

begin_comment
comment|/* hangup */
end_comment

begin_define
define|#
directive|define
name|RSP_NOA
value|'3'
end_define

begin_comment
comment|/* no answer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_TEL_IOCTL_H_ */
end_comment

end_unit

