begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   BSD LICENSE  *  *   Copyright(c) 2017 Cavium, Inc.. All rights reserved.  *   All rights reserved.  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in  *       the documentation and/or other materials provided with the  *       distribution.  *     * Neither the name of Cavium, Inc. nor the names of its  *       contributors may be used to endorse or promote products derived  *       from this software without specific prior written permission.  *  *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *   OWNER(S) OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIO_IMAGE_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIO_IMAGE_H_
end_define

begin_define
define|#
directive|define
name|LIO_MAX_FW_FILENAME_LEN
value|256
end_define

begin_define
define|#
directive|define
name|LIO_FW_BASE_NAME
value|"lio_"
end_define

begin_define
define|#
directive|define
name|LIO_FW_NAME_SUFFIX
value|".bin"
end_define

begin_define
define|#
directive|define
name|LIO_FW_NAME_TYPE_NIC
value|"nic"
end_define

begin_define
define|#
directive|define
name|LIO_FW_NAME_TYPE_NONE
value|"none"
end_define

begin_define
define|#
directive|define
name|LIO_MAX_FIRMWARE_VERSION_LEN
value|16
end_define

begin_define
define|#
directive|define
name|LIO_MAX_BOOTCMD_LEN
value|1024
end_define

begin_define
define|#
directive|define
name|LIO_MAX_IMAGES
value|16
end_define

begin_define
define|#
directive|define
name|LIO_NIC_MAGIC
value|0x434E4943
end_define

begin_comment
comment|/* "CNIC" */
end_comment

begin_struct
struct|struct
name|lio_firmware_desc
block|{
name|__be64
name|addr
decl_stmt|;
name|__be32
name|len
decl_stmt|;
name|__be32
name|crc32
decl_stmt|;
comment|/* crc32 of image */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Following the header is a list of 64-bit aligned binary images,  * as described by the desc field.  * Numeric fields are in network byte order.  */
end_comment

begin_struct
struct|struct
name|lio_firmware_file_header
block|{
name|__be32
name|magic
decl_stmt|;
name|char
name|version
index|[
name|LIO_MAX_FIRMWARE_VERSION_LEN
index|]
decl_stmt|;
name|char
name|bootcmd
index|[
name|LIO_MAX_BOOTCMD_LEN
index|]
decl_stmt|;
name|__be32
name|num_images
decl_stmt|;
name|struct
name|lio_firmware_desc
name|desc
index|[
name|LIO_MAX_IMAGES
index|]
decl_stmt|;
name|__be32
name|pad
decl_stmt|;
name|__be32
name|crc32
decl_stmt|;
comment|/* header checksum */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIO_IMAGE_H_ */
end_comment

end_unit

