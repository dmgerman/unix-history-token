begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 KIYOHARA Takashi<kiyohara@kk.iij4u.or.jp>  * Copyright (c) 2000 Takanori Watanabe<takawata@jp.FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PC98_PC98_CANBUSVARS_H_
end_ifndef

begin_define
define|#
directive|define
name|_PC98_PC98_CANBUSVARS_H_
end_define

begin_comment
comment|/* CanBe I/O register */
end_comment

begin_define
define|#
directive|define
name|CANBE_IOPORT_INDEX
value|0xf4a
end_define

begin_define
define|#
directive|define
name|CANBE_IOPORT_DATA
value|0xf4b
end_define

begin_comment
comment|/*  * following registor purpose for spending -- unknown.  */
end_comment

begin_define
define|#
directive|define
name|CANBE_IOPORT1
value|0x0c24
end_define

begin_define
define|#
directive|define
name|CANBE_IOPORT2
value|0x0c2b
end_define

begin_define
define|#
directive|define
name|CANBE_IOPORT3
value|0x0c2d
end_define

begin_comment
comment|/* CanBe register number */
end_comment

begin_define
define|#
directive|define
name|CANBE_SOUND_INTR_ADDR
value|0x01
end_define

begin_define
define|#
directive|define
name|CANBE_RC_RESET
value|0x03
end_define

begin_define
define|#
directive|define
name|CANBE_MUTE_CTRL
value|0x04
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|CANBE_RC_RECV_CODE
value|0x11
end_define

begin_define
define|#
directive|define
name|CANBE_POWER_CTRL
value|0x13
end_define

begin_define
define|#
directive|define
name|CANBE_RC_USED_INTR
value|0x14
end_define

begin_comment
comment|/* CanBe sound interrupt address value */
end_comment

begin_define
define|#
directive|define
name|CANBE_SOUND_INTR_VAL0
value|0x00
end_define

begin_define
define|#
directive|define
name|CANBE_SOUND_INTR_VAL1
value|0x02
end_define

begin_define
define|#
directive|define
name|CANBE_SOUND_INTR_VAL2
value|0x03
end_define

begin_define
define|#
directive|define
name|CANBE_SOUND_INTR_VAL3
value|0x08
end_define

begin_comment
comment|/* CanBe remote controler reset */
end_comment

begin_define
define|#
directive|define
name|CANBE_MIKE_THRUE
value|0x04
end_define

begin_define
define|#
directive|define
name|CANBE_CTRLR_RESET
value|0x01
end_define

begin_comment
comment|/* CanBe mute control */
end_comment

begin_define
define|#
directive|define
name|CANBE_MUTE
value|0x01
end_define

begin_comment
comment|/* CanBe remote controler data status */
end_comment

begin_define
define|#
directive|define
name|CANBE_RC_BUSY
value|0x02
end_define

begin_define
define|#
directive|define
name|CANBE_RC_STATUS
value|0x01
end_define

begin_comment
comment|/* CanBe remote controler receive code */
end_comment

begin_define
define|#
directive|define
name|CANBE_RC_DATA_CHUP
value|0x00
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_CHDOWN
value|0x01
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_VOLUP
value|0x02
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_VOLDOWN
value|0x03
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_EJECT
value|0x04
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_PLAY
value|0x05
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_MUTE
value|0x09
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_VIDEO
value|0x0a
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_NEXT
value|0x0c
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_PREVIOUS
value|0x0d
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_M_S
value|0x1d
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_UP
value|0x40
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_DOWN
value|0x41
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_LEFT
value|0x42
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_RIGHT
value|0x43
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_SIZE
value|0x4d
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_ESC
value|0x4e
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_CR
value|0x4f
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_TV
value|0x53
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_FREEZE
value|0x5d
end_define

begin_define
define|#
directive|define
name|CANBE_RC_DATA_CAPTURE
value|0x5e
end_define

begin_comment
comment|/* CanBe power off data */
end_comment

begin_define
define|#
directive|define
name|CANBE_POWEROFF_DATA
value|{		\ 	0x80, 0x06, 0x00, 0x00,		\ 	0x80, 0x07, 0x00, 0x01,		\ 	0x80, 0x01, 0x00, 0x00		\ }
end_define

begin_comment
comment|/* CanBe remote controler used intr */
end_comment

begin_define
define|#
directive|define
name|CANBE_RC_INTR
value|0x04
end_define

begin_define
define|#
directive|define
name|CANBE_RC_INTR_INT41
value|0x03
end_define

begin_comment
comment|/* irq 10 */
end_comment

begin_define
define|#
directive|define
name|CANBE_RC_INTR_INT1
value|0x02
end_define

begin_comment
comment|/* irq  5 */
end_comment

begin_define
define|#
directive|define
name|CANBE_RC_INTR_INT2
value|0x01
end_define

begin_comment
comment|/* irq  6 */
end_comment

begin_define
define|#
directive|define
name|CANBE_RC_INTR_INT0
value|0x00
end_define

begin_comment
comment|/* irq  3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PC98_PC98_CANBUSVARS_H_ */
end_comment

end_unit

