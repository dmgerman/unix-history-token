begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: cast128_subkey.h,v 1.3 2000/03/27 04:36:30 sumikawa Exp $	*/
end_comment

begin_comment
comment|/*  * heavily modified by Tomomi Suzuki<suzuki@grelot.elec.ryukoku.ac.jp>  */
end_comment

begin_comment
comment|/*  * The CAST-128 Encryption Algorithm (RFC 2144)  *  * original implementation<Hideo "Sir MaNMOS" Morisita>  * 1997/08/21  */
end_comment

begin_comment
comment|/*  * Copyright (C) 1997 Hideo "Sir MANMOS" Morishita  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY Hideo "Sir MaNMOS" Morishita ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Hideo "Sir MaNMOS" Morishita BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RFC2144_CAST_128_SUBKEY_H
end_ifndef

begin_define
define|#
directive|define
name|RFC2144_CAST_128_SUBKEY_H
end_define

begin_define
define|#
directive|define
name|x0x1x2x3
value|buf[0]
end_define

begin_define
define|#
directive|define
name|x4x5x6x7
value|buf[1]
end_define

begin_define
define|#
directive|define
name|x8x9xAxB
value|buf[2]
end_define

begin_define
define|#
directive|define
name|xCxDxExF
value|buf[3]
end_define

begin_define
define|#
directive|define
name|z0z1z2z3
value|buf[4]
end_define

begin_define
define|#
directive|define
name|z4z5z6z7
value|buf[5]
end_define

begin_define
define|#
directive|define
name|z8z9zAzB
value|buf[6]
end_define

begin_define
define|#
directive|define
name|zCzDzEzF
value|buf[7]
end_define

begin_define
define|#
directive|define
name|byte0
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24))
end_define

begin_define
define|#
directive|define
name|byte1
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|byte2
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|byte3
parameter_list|(
name|x
parameter_list|)
value|(((x))& 0xff)
end_define

begin_define
define|#
directive|define
name|x0
value|byte0(buf[0])
end_define

begin_define
define|#
directive|define
name|x1
value|byte1(buf[0])
end_define

begin_define
define|#
directive|define
name|x2
value|byte2(buf[0])
end_define

begin_define
define|#
directive|define
name|x3
value|byte3(buf[0])
end_define

begin_define
define|#
directive|define
name|x4
value|byte0(buf[1])
end_define

begin_define
define|#
directive|define
name|x5
value|byte1(buf[1])
end_define

begin_define
define|#
directive|define
name|x6
value|byte2(buf[1])
end_define

begin_define
define|#
directive|define
name|x7
value|byte3(buf[1])
end_define

begin_define
define|#
directive|define
name|x8
value|byte0(buf[2])
end_define

begin_define
define|#
directive|define
name|x9
value|byte1(buf[2])
end_define

begin_define
define|#
directive|define
name|xA
value|byte2(buf[2])
end_define

begin_define
define|#
directive|define
name|xB
value|byte3(buf[2])
end_define

begin_define
define|#
directive|define
name|xC
value|byte0(buf[3])
end_define

begin_define
define|#
directive|define
name|xD
value|byte1(buf[3])
end_define

begin_define
define|#
directive|define
name|xE
value|byte2(buf[3])
end_define

begin_define
define|#
directive|define
name|xF
value|byte3(buf[3])
end_define

begin_define
define|#
directive|define
name|z0
value|byte0(buf[4])
end_define

begin_define
define|#
directive|define
name|z1
value|byte1(buf[4])
end_define

begin_define
define|#
directive|define
name|z2
value|byte2(buf[4])
end_define

begin_define
define|#
directive|define
name|z3
value|byte3(buf[4])
end_define

begin_define
define|#
directive|define
name|z4
value|byte0(buf[5])
end_define

begin_define
define|#
directive|define
name|z5
value|byte1(buf[5])
end_define

begin_define
define|#
directive|define
name|z6
value|byte2(buf[5])
end_define

begin_define
define|#
directive|define
name|z7
value|byte3(buf[5])
end_define

begin_define
define|#
directive|define
name|z8
value|byte0(buf[6])
end_define

begin_define
define|#
directive|define
name|z9
value|byte1(buf[6])
end_define

begin_define
define|#
directive|define
name|zA
value|byte2(buf[6])
end_define

begin_define
define|#
directive|define
name|zB
value|byte3(buf[6])
end_define

begin_define
define|#
directive|define
name|zC
value|byte0(buf[7])
end_define

begin_define
define|#
directive|define
name|zD
value|byte1(buf[7])
end_define

begin_define
define|#
directive|define
name|zE
value|byte2(buf[7])
end_define

begin_define
define|#
directive|define
name|zF
value|byte3(buf[7])
end_define

begin_define
define|#
directive|define
name|circular_leftshift
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|( ((x)<< (y)) | ((x)>> (32-(y))) )
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

