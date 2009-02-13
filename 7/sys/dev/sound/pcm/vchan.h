begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Cameron Grant<cg@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_function_decl
name|int
name|vchan_create
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|parent
parameter_list|,
name|int
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vchan_destroy
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vchan_initsys
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Default speed / format  */
end_comment

begin_define
define|#
directive|define
name|VCHAN_DEFAULT_SPEED
value|48000
end_define

begin_define
define|#
directive|define
name|VCHAN_DEFAULT_AFMT
value|(AFMT_S16_LE | AFMT_STEREO)
end_define

begin_define
define|#
directive|define
name|VCHAN_DEFAULT_STRFMT
value|"s16le"
end_define

begin_define
define|#
directive|define
name|VCHAN_PLAY
value|0
end_define

begin_define
define|#
directive|define
name|VCHAN_REC
value|1
end_define

begin_comment
comment|/*  * Offset by +/- 1 so we can distinguish bogus pointer.  */
end_comment

begin_define
define|#
directive|define
name|VCHAN_SYSCTL_DATA
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((void *)((intptr_t)(((((x) + 1)& 0xfff)<< 2) |	\ 		(((VCHAN_##y) + 1)& 0x3))))
end_define

begin_define
define|#
directive|define
name|VCHAN_SYSCTL_DATA_SIZE
value|sizeof(void *)
end_define

begin_define
define|#
directive|define
name|VCHAN_SYSCTL_UNIT
parameter_list|(
name|x
parameter_list|)
value|((int)(((intptr_t)(x)>> 2)& 0xfff) - 1)
end_define

begin_define
define|#
directive|define
name|VCHAN_SYSCTL_DIR
parameter_list|(
name|x
parameter_list|)
value|((int)((intptr_t)(x)& 0x3) - 1)
end_define

end_unit

