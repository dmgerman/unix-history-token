begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999,2000 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DVDIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DVDIO_H_
end_define

begin_struct
struct|struct
name|dvd_layer
block|{
name|u_int8_t
name|book_type
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|book_version
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|disc_size
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|max_rate
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|nlayers
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|track_path
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|layer_type
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|linear_density
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|track_density
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|bca
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|start_sector
decl_stmt|;
name|u_int32_t
name|end_sector
decl_stmt|;
name|u_int32_t
name|end_sector_l0
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dvd_struct
block|{
name|u_char
name|format
decl_stmt|;
name|u_char
name|layer_num
decl_stmt|;
name|u_char
name|cpst
decl_stmt|;
name|u_char
name|rmi
decl_stmt|;
name|u_int8_t
name|agid
range|:
literal|2
decl_stmt|;
name|u_int32_t
name|length
decl_stmt|;
name|u_char
name|data
index|[
literal|2048
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dvd_authinfo
block|{
name|unsigned
name|char
name|format
decl_stmt|;
name|u_int8_t
name|agid
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|asf
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|cpm
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|cp_sec
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|cgms
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|reg_type
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|vend_rsts
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|user_rsts
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|region
decl_stmt|;
name|u_int8_t
name|rpc_scheme
decl_stmt|;
name|u_int32_t
name|lba
decl_stmt|;
name|u_char
name|keychal
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DVD_STRUCT_PHYSICAL
value|0x00
end_define

begin_define
define|#
directive|define
name|DVD_STRUCT_COPYRIGHT
value|0x01
end_define

begin_define
define|#
directive|define
name|DVD_STRUCT_DISCKEY
value|0x02
end_define

begin_define
define|#
directive|define
name|DVD_STRUCT_BCA
value|0x03
end_define

begin_define
define|#
directive|define
name|DVD_STRUCT_MANUFACT
value|0x04
end_define

begin_define
define|#
directive|define
name|DVD_STRUCT_CMI
value|0x05
end_define

begin_define
define|#
directive|define
name|DVD_STRUCT_PROTDISCID
value|0x06
end_define

begin_define
define|#
directive|define
name|DVD_STRUCT_DISCKEYBLOCK
value|0x07
end_define

begin_define
define|#
directive|define
name|DVD_STRUCT_DDS
value|0x08
end_define

begin_define
define|#
directive|define
name|DVD_STRUCT_MEDIUM_STAT
value|0x09
end_define

begin_define
define|#
directive|define
name|DVD_STRUCT_SPARE_AREA
value|0x0A
end_define

begin_define
define|#
directive|define
name|DVD_STRUCT_RMD_LAST
value|0x0C
end_define

begin_define
define|#
directive|define
name|DVD_STRUCT_RMD_RMA
value|0x0D
end_define

begin_define
define|#
directive|define
name|DVD_STRUCT_PRERECORDED
value|0x0E
end_define

begin_define
define|#
directive|define
name|DVD_STRUCT_UNIQUEID
value|0x0F
end_define

begin_define
define|#
directive|define
name|DVD_STRUCT_DCB
value|0x30
end_define

begin_define
define|#
directive|define
name|DVD_STRUCT_LIST
value|0xFF
end_define

begin_define
define|#
directive|define
name|DVD_REPORT_AGID
value|0
end_define

begin_define
define|#
directive|define
name|DVD_REPORT_CHALLENGE
value|1
end_define

begin_define
define|#
directive|define
name|DVD_REPORT_KEY1
value|2
end_define

begin_define
define|#
directive|define
name|DVD_REPORT_TITLE_KEY
value|4
end_define

begin_define
define|#
directive|define
name|DVD_REPORT_ASF
value|5
end_define

begin_define
define|#
directive|define
name|DVD_REPORT_RPC
value|8
end_define

begin_define
define|#
directive|define
name|DVD_INVALIDATE_AGID
value|0x3f
end_define

begin_define
define|#
directive|define
name|DVD_SEND_CHALLENGE
value|1
end_define

begin_define
define|#
directive|define
name|DVD_SEND_KEY2
value|3
end_define

begin_define
define|#
directive|define
name|DVD_SEND_RPC
value|6
end_define

begin_define
define|#
directive|define
name|DVDIOCREPORTKEY
value|_IOWR('c', 200, struct dvd_authinfo)
end_define

begin_define
define|#
directive|define
name|DVDIOCSENDKEY
value|_IOWR('c', 201, struct dvd_authinfo)
end_define

begin_define
define|#
directive|define
name|DVDIOCREADSTRUCTURE
value|_IOWR('c', 202, struct dvd_struct)
end_define

begin_endif
endif|#
directive|endif
endif|_SYS_DVDIO_H_
end_endif

end_unit

