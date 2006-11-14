begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: auxioreg.h,v 1.4 2001/10/22 07:31:41 mrg Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000 Matthew R. Green  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * The AUXIO registers; their offset in the Ebus2 address space, plus the  * bits for each register.  Note that the fdthree (FD), SUNW,CS4231 (AUDIO)  * and power (POWER) devices on the Ebus2 have their AUXIO regsiters mapped  * into their own "reg" properties, not the "auxio" device's "reg" properties.  */
end_comment

begin_define
define|#
directive|define
name|AUXIO_FD
value|0x00720000
end_define

begin_define
define|#
directive|define
name|AUXIO_FD_DENSENSE_INPUT
value|0x0
end_define

begin_define
define|#
directive|define
name|AUXIO_FD_DENSENSE_OUTPUT
value|0x1
end_define

begin_define
define|#
directive|define
name|AUXIO_AUDIO
value|0x00722000
end_define

begin_define
define|#
directive|define
name|AUXIO_AUDIO_POWERDOWN
value|0x0
end_define

begin_define
define|#
directive|define
name|AUXIO_POWER
value|0x00724000
end_define

begin_define
define|#
directive|define
name|AUXIO_POWER_SYSTEM_OFF
value|0x0
end_define

begin_define
define|#
directive|define
name|AUXIO_POWER_COURTESY_OFF
value|0x1
end_define

begin_define
define|#
directive|define
name|AUXIO_LED
value|0x00726000
end_define

begin_define
define|#
directive|define
name|AUXIO_LED_LED
value|1
end_define

begin_define
define|#
directive|define
name|AUXIO_PCI
value|0x00728000
end_define

begin_define
define|#
directive|define
name|AUXIO_PCI_SLOT0
value|0x0
end_define

begin_comment
comment|/* two bits each */
end_comment

begin_define
define|#
directive|define
name|AUXIO_PCI_SLOT1
value|0x2
end_define

begin_define
define|#
directive|define
name|AUXIO_PCI_SLOT2
value|0x4
end_define

begin_define
define|#
directive|define
name|AUXIO_PCI_SLOT3
value|0x6
end_define

begin_define
define|#
directive|define
name|AUXIO_PCI_MODE
value|0x8
end_define

begin_define
define|#
directive|define
name|AUXIO_FREQ
value|0x0072a000
end_define

begin_define
define|#
directive|define
name|AUXIO_FREQ_FREQ0
value|0x0
end_define

begin_define
define|#
directive|define
name|AUXIO_FREQ_FREQ1
value|0x1
end_define

begin_define
define|#
directive|define
name|AUXIO_FREQ_FREQ2
value|0x2
end_define

begin_define
define|#
directive|define
name|AUXIO_SCSI
value|0x0072c000
end_define

begin_define
define|#
directive|define
name|AUXIO_SCSI_INT_OSC_EN
value|0x0
end_define

begin_define
define|#
directive|define
name|AUXIO_SCSI_EXT_OSC_EN
value|0x1
end_define

begin_define
define|#
directive|define
name|AUXIO_TEMP
value|0x0072f000
end_define

begin_define
define|#
directive|define
name|AUXIO_TEMP_SELECT
value|0x0
end_define

begin_define
define|#
directive|define
name|AUXIO_TEMP_CLOCK
value|0x1
end_define

begin_define
define|#
directive|define
name|AUXIO_TEMP_ENABLE
value|0x2
end_define

begin_define
define|#
directive|define
name|AUXIO_TEMP_DATAOUT
value|0x3
end_define

begin_define
define|#
directive|define
name|AUXIO_TEMP_DATAINT
value|0x4
end_define

end_unit

