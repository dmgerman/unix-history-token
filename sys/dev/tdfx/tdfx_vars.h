begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000-2001 by Coleman Kane<cokane@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Gardner Buchanan.  * 4. The name of Gardner Buchanan may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *   $FreeBSD$  */
end_comment

begin_comment
comment|/* tdfx_vars.h -- constants and structs used in the tdfx driver 	Copyright (C) 2000-2001 by Coleman Kane<cokane@FreeBSD.org> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TDFX_VARS_H
end_ifndef

begin_define
define|#
directive|define
name|TDFX_VARS_H
end_define

begin_include
include|#
directive|include
file|<sys/memrange.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|PCI_DEVICE_ALLIANCE_AT3D
value|0x643d1142
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_3DFX_VOODOO1
value|0x0001121a
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_3DFX_VOODOO2
value|0x0002121a
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_3DFX_BANSHEE
value|0x0003121a
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_3DFX_VOODOO3
value|0x0005121a
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_FREEBSD
value|0x0
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_FREEBSD
value|0x2
end_define

begin_define
define|#
directive|define
name|PCI_COMMAND_FREEBSD
value|0x4
end_define

begin_define
define|#
directive|define
name|PCI_REVISION_ID_FREEBSD
value|0x8
end_define

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_0_FREEBSD
value|0x10
end_define

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_1_FREEBSD
value|0x14
end_define

begin_define
define|#
directive|define
name|PCI_PRIBUS_FREEBSD
value|0x18
end_define

begin_define
define|#
directive|define
name|PCI_IOBASE_0_FREEBSD
value|0x2c
end_define

begin_define
define|#
directive|define
name|PCI_IOLIMIT_0_FREEBSD
value|0x30
end_define

begin_define
define|#
directive|define
name|SST1_PCI_SPECIAL1_FREEBSD
value|0x40
end_define

begin_define
define|#
directive|define
name|SST1_PCI_SPECIAL2_FREEBSD
value|0x44
end_define

begin_define
define|#
directive|define
name|SST1_PCI_SPECIAL3_FREEBSD
value|0x48
end_define

begin_define
define|#
directive|define
name|SST1_PCI_SPECIAL4_FREEBSD
value|0x54
end_define

begin_define
define|#
directive|define
name|VGA_INPUT_STATUS_1C
value|0x3DA
end_define

begin_define
define|#
directive|define
name|VGA_MISC_OUTPUT_READ
value|0x3cc
end_define

begin_define
define|#
directive|define
name|VGA_MISC_OUTPUT_WRITE
value|0x3c2
end_define

begin_define
define|#
directive|define
name|SC_INDEX
value|0x3c4
end_define

begin_define
define|#
directive|define
name|SC_DATA
value|0x3c5
end_define

begin_define
define|#
directive|define
name|PCI_MAP_REG_START
value|0x10
end_define

begin_define
define|#
directive|define
name|UNIT
parameter_list|(
name|m
parameter_list|)
value|(m& 0xf)
end_define

begin_comment
comment|/* IOCTL Calls */
end_comment

begin_define
define|#
directive|define
name|TDFX_IOC_TYPE_PIO
value|0
end_define

begin_define
define|#
directive|define
name|TDFX_IOC_TYPE_QUERY
value|'3'
end_define

begin_define
define|#
directive|define
name|TDFX_IOC_QRY_BOARDS
value|2
end_define

begin_define
define|#
directive|define
name|TDFX_IOC_QRY_FETCH
value|3
end_define

begin_define
define|#
directive|define
name|TDFX_IOC_QRY_UPDATE
value|4
end_define

begin_struct
struct|struct
name|tdfx_softc
block|{
name|int
name|cardno
decl_stmt|;
name|vm_offset_t
name|addr
decl_stmt|,
name|addr2
decl_stmt|;
name|struct
name|resource
modifier|*
name|memrange
decl_stmt|,
modifier|*
name|memrange2
decl_stmt|,
modifier|*
name|piorange
decl_stmt|;
name|int
name|memrid
decl_stmt|,
name|memrid2
decl_stmt|,
name|piorid
decl_stmt|;
name|long
name|range
decl_stmt|;
name|int
name|vendor
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|addr0
decl_stmt|,
name|addr1
decl_stmt|;
name|short
name|pio0
decl_stmt|,
name|pio0max
decl_stmt|;
name|unsigned
name|char
name|bus
decl_stmt|;
name|unsigned
name|char
name|dv
decl_stmt|;
name|struct
name|file
modifier|*
name|curFile
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|cdev
modifier|*
name|devt
decl_stmt|;
name|struct
name|mem_range_desc
name|mrdesc
decl_stmt|;
name|int
name|busy
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tdfx_pio_data
block|{
name|short
name|port
decl_stmt|;
name|short
name|size
decl_stmt|;
name|int
name|device
decl_stmt|;
name|void
modifier|*
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TDFX_VARS_H */
end_comment

end_unit

