begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Tyler C. Sarna.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIA_H
end_ifndef

begin_define
define|#
directive|define
name|_VIA_H
end_define

begin_comment
comment|/*  * VIA Technologies VT82C686A Southbridge Audio Driver  *  * Documentation links:  *  * ftp://ftp.alsa-project.org/pub/manuals/via/686a.pdf  * ftp://ftp.alsa-project.org/pub/manuals/general/ac97r21.pdf  * ftp://ftp.alsa-project.org/pub/manuals/ad/AD1881_0.pdf (example AC'97 codec)  */
end_comment

begin_define
define|#
directive|define
name|VIA_AC97STATUS
value|0x40
end_define

begin_define
define|#
directive|define
name|VIA_AC97STATUS_RDY
value|0x01
end_define

begin_define
define|#
directive|define
name|VIA_AC97STATUS_LOWPWR
value|0x02
end_define

begin_define
define|#
directive|define
name|VIA_AC97STATUS_2RDY
value|0x04
end_define

begin_define
define|#
directive|define
name|VIA_ACLINKCTRL
value|0x41
end_define

begin_define
define|#
directive|define
name|VIA_ACLINK_EN
value|0x80
end_define

begin_comment
comment|/* ac link enab */
end_comment

begin_define
define|#
directive|define
name|VIA_ACLINK_NRST
value|0x40
end_define

begin_comment
comment|/* ~(ac reset) */
end_comment

begin_define
define|#
directive|define
name|VIA_ACLINK_SYNC
value|0x20
end_define

begin_comment
comment|/* ac sync */
end_comment

begin_define
define|#
directive|define
name|VIA_ACLINK_VSR
value|0x08
end_define

begin_comment
comment|/* var. samp. rate */
end_comment

begin_define
define|#
directive|define
name|VIA_ACLINK_SGD
value|0x04
end_define

begin_comment
comment|/* SGD enab */
end_comment

begin_define
define|#
directive|define
name|VIA_ACLINK_FM
value|0x02
end_define

begin_comment
comment|/* FM enab */
end_comment

begin_define
define|#
directive|define
name|VIA_ACLINK_SB
value|0x01
end_define

begin_comment
comment|/* SB enab */
end_comment

begin_define
define|#
directive|define
name|VIA_ACLINK_DESIRED
value|(VIA_ACLINK_EN|VIA_ACLINK_NRST|VIA_ACLINK_VSR|VIA_ACLINK_SGD)
end_define

begin_define
define|#
directive|define
name|VIA_PCICONF_FUNC_EN
value|0x42
end_define

begin_define
define|#
directive|define
name|VIA_PLAY_STAT
value|0x00
end_define

begin_define
define|#
directive|define
name|VIA_RECORD_STAT
value|0x10
end_define

begin_define
define|#
directive|define
name|VIA_RPSTAT_INTR
value|0x03
end_define

begin_define
define|#
directive|define
name|VIA_PLAY_CONTROL
value|0x01
end_define

begin_define
define|#
directive|define
name|VIA_RECORD_CONTROL
value|0x11
end_define

begin_define
define|#
directive|define
name|VIA_RPCTRL_START
value|0x80
end_define

begin_define
define|#
directive|define
name|VIA_RPCTRL_TERMINATE
value|0x40
end_define

begin_define
define|#
directive|define
name|VIA_PLAY_MODE
value|0x02
end_define

begin_define
define|#
directive|define
name|VIA_RECORD_MODE
value|0x12
end_define

begin_define
define|#
directive|define
name|VIA_RPMODE_INTR_FLAG
value|0x01
end_define

begin_define
define|#
directive|define
name|VIA_RPMODE_INTR_EOL
value|0x02
end_define

begin_define
define|#
directive|define
name|VIA_RPMODE_STEREO
value|0x10
end_define

begin_define
define|#
directive|define
name|VIA_RPMODE_16BIT
value|0x20
end_define

begin_define
define|#
directive|define
name|VIA_RPMODE_AUTOSTART
value|0x80
end_define

begin_define
define|#
directive|define
name|VIA_PLAY_DMAOPS_BASE
value|0x04
end_define

begin_define
define|#
directive|define
name|VIA_RECORD_DMAOPS_BASE
value|0x14
end_define

begin_define
define|#
directive|define
name|VIA_PLAY_DMAOPS_COUNT
value|0x0C
end_define

begin_define
define|#
directive|define
name|VIA_RECORD_DMAOPS_COUNT
value|0x1C
end_define

begin_define
define|#
directive|define
name|VIA_CODEC_CTL
value|0x80
end_define

begin_define
define|#
directive|define
name|VIA_CODEC_READ
value|0x00800000
end_define

begin_define
define|#
directive|define
name|VIA_CODEC_BUSY
value|0x01000000
end_define

begin_define
define|#
directive|define
name|VIA_CODEC_PRIVALID
value|0x02000000
end_define

begin_define
define|#
directive|define
name|VIA_CODEC_INDEX
parameter_list|(
name|x
parameter_list|)
value|((x)<<16)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIA_H */
end_comment

end_unit

