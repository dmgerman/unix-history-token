begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, Sujal M. Patel  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Sujal M. Patel  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      $Id: pnpinfo.h,v 1.1 1996/01/08 00:48:32 smpatel Exp $  */
end_comment

begin_comment
comment|/* Maximum Number of PnP Devices.  6 should be plenty */
end_comment

begin_define
define|#
directive|define
name|MAX_CARDS
value|6
end_define

begin_comment
comment|/* Static ports */
end_comment

begin_define
define|#
directive|define
name|ADDRESS
value|0x279
end_define

begin_define
define|#
directive|define
name|WRITE_DATA
value|0xa79
end_define

begin_comment
comment|/* PnP Registers.  Write to ADDRESS and then use WRITE/READ_DATA */
end_comment

begin_define
define|#
directive|define
name|SET_RD_DATA
value|0x00
end_define

begin_define
define|#
directive|define
name|SERIAL_ISOLATION
value|0x01
end_define

begin_define
define|#
directive|define
name|WAKE
value|0x03
end_define

begin_define
define|#
directive|define
name|RESOURCE_DATA
value|0x04
end_define

begin_define
define|#
directive|define
name|STATUS
value|0x05
end_define

begin_define
define|#
directive|define
name|SET_CSN
value|0x06
end_define

begin_comment
comment|/* Small Resource Item names */
end_comment

begin_define
define|#
directive|define
name|PNP_VERSION
value|0x1
end_define

begin_define
define|#
directive|define
name|LOG_DEVICE_ID
value|0x2
end_define

begin_define
define|#
directive|define
name|COMP_DEVICE_ID
value|0x3
end_define

begin_define
define|#
directive|define
name|IRQ_FORMAT
value|0x4
end_define

begin_define
define|#
directive|define
name|DMA_FORMAT
value|0x5
end_define

begin_define
define|#
directive|define
name|START_DEPEND_FUNC
value|0x6
end_define

begin_define
define|#
directive|define
name|END_DEPEND_FUNC
value|0x7
end_define

begin_define
define|#
directive|define
name|IO_PORT_DESC
value|0x8
end_define

begin_define
define|#
directive|define
name|FIXED_IO_PORT_DESC
value|0x9
end_define

begin_define
define|#
directive|define
name|SM_RES_RESERVED
value|0xa-0xd
end_define

begin_define
define|#
directive|define
name|SM_VENDOR_DEFINED
value|0xe
end_define

begin_define
define|#
directive|define
name|END_TAG
value|0xf
end_define

begin_comment
comment|/* Large Resource Item names */
end_comment

begin_define
define|#
directive|define
name|MEMORY_RANGE_DESC
value|0x1
end_define

begin_define
define|#
directive|define
name|ID_STRING_ANSI
value|0x2
end_define

begin_define
define|#
directive|define
name|ID_STRING_UNICODE
value|0x3
end_define

begin_define
define|#
directive|define
name|LG_VENDOR_DEFINED
value|0x4
end_define

begin_define
define|#
directive|define
name|_32BIT_MEM_RANGE_DESC
value|0x5
end_define

begin_define
define|#
directive|define
name|_32BIT_FIXED_LOC_DESC
value|0x6
end_define

begin_define
define|#
directive|define
name|LG_RES_RESERVED
value|0x7-0x7f
end_define

end_unit

