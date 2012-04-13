begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2010 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SAT_H_
end_define

begin_comment
comment|/**  * @file  * @brief This file contains constants and constructs defined in the SCSI  *        to ATA Translation (SAT) T10 standard.  For more information please  *        refer to www.t10.org.  */
end_comment

begin_comment
comment|/**  * @name SAT_PROTOCOLS  *  * These constants indicate the various protocol values that can be supported  * in a SAT translator.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|SAT_PROTOCOL_ATA_HARD_RESET
value|0
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_SOFT_RESET
value|1
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_NON_DATA
value|3
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_PIO_DATA_IN
value|4
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_PIO_DATA_OUT
value|5
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_DMA
value|6
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_DMA_QUEUED
value|7
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_DEVICE_DIAGNOSTIC
value|8
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_DEVICE_RESET
value|9
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_UDMA_DATA_IN
value|10
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_UDMA_DATA_OUT
value|11
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_FPDMA
value|12
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_RETURN_RESPONSE_INFO
value|15
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_PACKET
value|0x10
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_PACKET_NON_DATA
value|(SAT_PROTOCOL_PACKET | 0x0)
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_PACKET_DMA_DATA_IN
value|(SAT_PROTOCOL_PACKET | 0x1)
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_PACKET_DMA_DATA_OUT
value|(SAT_PROTOCOL_PACKET | 0x2)
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_PACKET_PIO_DATA_IN
value|(SAT_PROTOCOL_PACKET | 0x3)
end_define

begin_define
define|#
directive|define
name|SAT_PROTOCOL_PACKET_PIO_DATA_OUT
value|(SAT_PROTOCOL_PACKET | 0x4)
end_define

begin_comment
comment|/*@}*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SAT_H_
end_comment

end_unit

