begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Cameron Grant<gandalf@vilnya.demon.co.uk>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AU8820_REG_H
end_ifndef

begin_define
define|#
directive|define
name|_AU8820_REG_H
end_define

begin_define
define|#
directive|define
name|AU_BUFFSIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AU_REG_FIFOBASE
value|0x0e000
end_define

begin_define
define|#
directive|define
name|AU_REG_UNK2
value|0x105c0
end_define

begin_define
define|#
directive|define
name|AU_REG_UNK3
value|0x10600
end_define

begin_define
define|#
directive|define
name|AU_REG_UNK4
value|0x10604
end_define

begin_define
define|#
directive|define
name|AU_REG_UNK5
value|0x10608
end_define

begin_define
define|#
directive|define
name|AU_REG_RTBASE
value|0x10800
end_define

begin_define
define|#
directive|define
name|AU_REG_ADB
value|0x10a00
end_define

begin_define
define|#
directive|define
name|AU_REG_CODECCHN
value|0x11880
end_define

begin_define
define|#
directive|define
name|AU_REG_CODECST
value|0x11984
end_define

begin_define
define|#
directive|define
name|AU_CDC_RUN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AU_CDC_WROK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AU_CDC_RESET
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AU_REG_CODECIO
value|0x11988
end_define

begin_define
define|#
directive|define
name|AU_CDC_DATAMASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|AU_CDC_REGMASK
value|0x007f0000
end_define

begin_define
define|#
directive|define
name|AU_CDC_REGSET
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AU_CDC_READY
value|0x04000000
end_define

begin_define
define|#
directive|define
name|AU_REG_CODECEN
value|0x11990
end_define

begin_define
define|#
directive|define
name|AU_CDC_CHAN1EN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AU_CDC_CHAN2EN
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AU_REG_UNK1
value|0x1199c
end_define

begin_define
define|#
directive|define
name|AU_REG_IRQSRC
value|0x12800
end_define

begin_define
define|#
directive|define
name|AU_IRQ_FATAL
value|0x0001
end_define

begin_define
define|#
directive|define
name|AU_IRQ_PARITY
value|0x0002
end_define

begin_define
define|#
directive|define
name|AU_IRQ_PCMOUT
value|0x0020
end_define

begin_define
define|#
directive|define
name|AU_IRQ_UNKNOWN
value|0x1000
end_define

begin_define
define|#
directive|define
name|AU_IRQ_MIDI
value|0x2000
end_define

begin_define
define|#
directive|define
name|AU_REG_IRQEN
value|0x12804
end_define

begin_define
define|#
directive|define
name|AU_REG_IRQGLOB
value|0x1280c
end_define

begin_define
define|#
directive|define
name|AU_IRQ_ENABLE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AC97_MUTE
value|0x8000
end_define

begin_define
define|#
directive|define
name|AC97_REG_RESET
value|0x00
end_define

begin_define
define|#
directive|define
name|AC97_MIX_MASTER
value|0x02
end_define

begin_define
define|#
directive|define
name|AC97_MIX_PHONES
value|0x04
end_define

begin_define
define|#
directive|define
name|AC97_MIX_MONO
value|0x06
end_define

begin_define
define|#
directive|define
name|AC97_MIX_TONE
value|0x08
end_define

begin_define
define|#
directive|define
name|AC97_MIX_BEEP
value|0x0a
end_define

begin_define
define|#
directive|define
name|AC97_MIX_PHONE
value|0x0c
end_define

begin_define
define|#
directive|define
name|AC97_MIX_MIC
value|0x0e
end_define

begin_define
define|#
directive|define
name|AC97_MIX_LINE
value|0x10
end_define

begin_define
define|#
directive|define
name|AC97_MIX_CD
value|0x12
end_define

begin_define
define|#
directive|define
name|AC97_MIX_VIDEO
value|0x14
end_define

begin_define
define|#
directive|define
name|AC97_MIX_AUX
value|0x16
end_define

begin_define
define|#
directive|define
name|AC97_MIX_PCM
value|0x18
end_define

begin_define
define|#
directive|define
name|AC97_REG_RECSEL
value|0x1a
end_define

begin_define
define|#
directive|define
name|AC97_MIX_RGAIN
value|0x1c
end_define

begin_define
define|#
directive|define
name|AC97_MIX_MGAIN
value|0x1e
end_define

begin_define
define|#
directive|define
name|AC97_REG_GEN
value|0x20
end_define

begin_define
define|#
directive|define
name|AC97_REG_3D
value|0x22
end_define

begin_define
define|#
directive|define
name|AC97_REG_POWER
value|0x26
end_define

begin_define
define|#
directive|define
name|AC97_REG_ID1
value|0x7c
end_define

begin_define
define|#
directive|define
name|AC97_REG_ID2
value|0x7e
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

