begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 - 2007 Søren Schmidt<sos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* ATAPI Rewriteable drive Capabilities and Mechanical Status Page */
end_comment

begin_struct
struct|struct
name|afd_capabilities
block|{
name|u_int16_t
name|data_length
decl_stmt|;
name|u_int8_t
name|medium_type
decl_stmt|;
define|#
directive|define
name|MFD_2DD_UN
value|0x10
define|#
directive|define
name|MFD_2DD
value|0x11
define|#
directive|define
name|MFD_HD_UN
value|0x20
define|#
directive|define
name|MFD_HD_12_98
value|0x22
define|#
directive|define
name|MFD_HD_12
value|0x23
define|#
directive|define
name|MFD_HD_144
value|0x24
define|#
directive|define
name|MFD_UHD
value|0x31
define|#
directive|define
name|MFD_UNKNOWN
value|0x00
define|#
directive|define
name|MFD_NO_DISC
value|0x70
define|#
directive|define
name|MFD_DOOR_OPEN
value|0x71
define|#
directive|define
name|MFD_FMT_ERROR
value|0x72
name|u_int8_t
name|reserved0
range|:
literal|7
decl_stmt|;
name|u_int8_t
name|wp
range|:
literal|1
decl_stmt|;
comment|/* write protect */
name|u_int8_t
name|unused
index|[
literal|4
index|]
decl_stmt|;
comment|/* capabilities page */
name|u_int8_t
name|page_code
range|:
literal|6
decl_stmt|;
define|#
directive|define
name|ATAPI_REWRITEABLE_CAP_PAGE
value|0x05
name|u_int8_t
name|reserved1_6
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|ps
range|:
literal|1
decl_stmt|;
comment|/* page save supported */
name|u_int8_t
name|page_length
decl_stmt|;
comment|/* page length */
name|u_int16_t
name|transfer_rate
decl_stmt|;
comment|/* in kilobits per second */
name|u_int8_t
name|heads
decl_stmt|;
comment|/* number of heads */
name|u_int8_t
name|sectors
decl_stmt|;
comment|/* number of sectors pr track */
name|u_int16_t
name|sector_size
decl_stmt|;
comment|/* number of bytes per sector */
name|u_int16_t
name|cylinders
decl_stmt|;
comment|/* number of cylinders */
name|u_int8_t
name|reserved10
index|[
literal|10
index|]
decl_stmt|;
name|u_int8_t
name|motor_delay
decl_stmt|;
comment|/* motor off delay */
name|u_int8_t
name|reserved21
index|[
literal|7
index|]
decl_stmt|;
name|u_int16_t
name|rpm
decl_stmt|;
comment|/* rotations per minute */
name|u_int8_t
name|reserved30
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|afd_capacity
block|{
name|u_int32_t
name|capacity
decl_stmt|;
name|u_int32_t
name|blocksize
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|afd_capacity_big
block|{
name|u_int64_t
name|capacity
decl_stmt|;
name|u_int32_t
name|blocksize
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|afd_softc
block|{
name|u_int64_t
name|mediasize
decl_stmt|;
name|u_int32_t
name|heads
decl_stmt|;
name|u_int32_t
name|sectors
decl_stmt|;
name|u_int32_t
name|sectorsize
decl_stmt|;
name|struct
name|disk
modifier|*
name|disk
decl_stmt|;
comment|/* virtual drives */
block|}
struct|;
end_struct

end_unit

