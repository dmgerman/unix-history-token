begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_GPT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_GPT_H_
end_define

begin_include
include|#
directive|include
file|<sys/uuid.h>
end_include

begin_struct
struct|struct
name|gpt_hdr
block|{
name|char
name|hdr_sig
index|[
literal|8
index|]
decl_stmt|;
define|#
directive|define
name|GPT_HDR_SIG
value|"EFI PART"
name|uint32_t
name|hdr_revision
decl_stmt|;
define|#
directive|define
name|GPT_HDR_REVISION
value|0x00010000
name|uint32_t
name|hdr_size
decl_stmt|;
name|uint32_t
name|hdr_crc_self
decl_stmt|;
name|uint32_t
name|__reserved
decl_stmt|;
name|uint64_t
name|hdr_lba_self
decl_stmt|;
name|uint64_t
name|hdr_lba_alt
decl_stmt|;
name|uint64_t
name|hdr_lba_start
decl_stmt|;
name|uint64_t
name|hdr_lba_end
decl_stmt|;
name|struct
name|uuid
name|hdr_uuid
decl_stmt|;
name|uint64_t
name|hdr_lba_table
decl_stmt|;
name|uint32_t
name|hdr_entries
decl_stmt|;
name|uint32_t
name|hdr_entsz
decl_stmt|;
name|uint32_t
name|hdr_crc_table
decl_stmt|;
comment|/* 	 * The header as defined in the EFI spec is not a multiple of 8 bytes 	 * and given that the alignment requirement is on an 8 byte boundary, 	 * padding will happen. We make the padding explicit so that we can 	 * correct the value returned by sizeof() when we put the size of the 	 * header in field hdr_size, or otherwise use offsetof(). 	 */
name|uint32_t
name|padding
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gpt_ent
block|{
name|struct
name|uuid
name|ent_type
decl_stmt|;
name|struct
name|uuid
name|ent_uuid
decl_stmt|;
name|uint64_t
name|ent_lba_start
decl_stmt|;
name|uint64_t
name|ent_lba_end
decl_stmt|;
name|uint64_t
name|ent_attr
decl_stmt|;
define|#
directive|define
name|GPT_ENT_ATTR_PLATFORM
value|(1ULL<< 0)
name|uint16_t
name|ent_name
index|[
literal|36
index|]
decl_stmt|;
comment|/* UTF-16. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_UNUSED
define|\
value|{0x00000000,0x0000,0x0000,0x00,0x00,{0x00,0x00,0x00,0x00,0x00,0x00}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_EFI
define|\
value|{0xc12a7328,0xf81f,0x11d2,0xba,0x4b,{0x00,0xa0,0xc9,0x3e,0xc9,0x3b}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_MBR
define|\
value|{0x024dee41,0x33e7,0x11d3,0x9d,0x69,{0x00,0x08,0xc7,0x81,0xf3,0x9f}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_FREEBSD
define|\
value|{0x516e7cb4,0x6ecf,0x11d6,0x8f,0xf8,{0x00,0x02,0x2d,0x09,0x71,0x2b}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_FREEBSD_SWAP
define|\
value|{0x516e7cb5,0x6ecf,0x11d6,0x8f,0xf8,{0x00,0x02,0x2d,0x09,0x71,0x2b}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_FREEBSD_UFS
define|\
value|{0x516e7cb6,0x6ecf,0x11d6,0x8f,0xf8,{0x00,0x02,0x2d,0x09,0x71,0x2b}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_FREEBSD_VINUM
define|\
value|{0x516e7cb8,0x6ecf,0x11d6,0x8f,0xf8,{0x00,0x02,0x2d,0x09,0x71,0x2b}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_FREEBSD_ZFS
define|\
value|{0x516e7cba,0x6ecf,0x11d6,0x8f,0xf8,{0x00,0x02,0x2d,0x09,0x71,0x2b}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_FREEBSD_BOOT
define|\
value|{0x83bd6b9d,0x7f41,0x11dc,0xbe,0x0b,{0x00,0x15,0x60,0xb8,0x4f,0x0f}}
end_define

begin_comment
comment|/*  * The following are unused but documented here to avoid reuse.  *  * GPT_ENT_TYPE_FREEBSD_UFS2	\  *	{0x516e7cb7,0x6ecf,0x11d6,0x8f,0xf8,{0x00,0x02,0x2d,0x09,0x71,0x2b}}  */
end_comment

begin_comment
comment|/*  * Foreign partition types that we're likely to encounter. Note that Linux  * apparently choose to share data partitions with MS. I don't what the  * advantage might be. I can see how sharing swap partitions is advantageous  * though.  */
end_comment

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_MS_RESERVED
define|\
value|{0xe3c9e316,0x0b5c,0x4db8,0x81,0x7d,{0xf9,0x2d,0xf0,0x02,0x15,0xae}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_MS_BASIC_DATA
define|\
value|{0xebd0a0a2,0xb9e5,0x4433,0x87,0xc0,{0x68,0xb6,0xb7,0x26,0x99,0xc7}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_MS_LDM_METADATA
define|\
value|{0x5808c8aa,0x7e8f,0x42e0,0x85,0xd2,{0xe1,0xe9,0x04,0x34,0xcf,0xb3}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_MS_LDM_DATA
define|\
value|{0xaf9b60a0,0x1431,0x4f62,0xbc,0x68,{0x33,0x11,0x71,0x4a,0x69,0xad}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_LINUX_DATA
value|GPT_ENT_TYPE_MS_BASIC_DATA
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_LINUX_RAID
define|\
value|{0xa19d880f,0x05fc,0x4d3b,0xa0,0x06,{0x74,0x3f,0x0f,0x84,0x91,0x1e}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_LINUX_SWAP
define|\
value|{0x0657fd6d,0xa4ab,0x43c4,0x84,0xe5,{0x09,0x33,0xc8,0x4b,0x4f,0x4f}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_LINUX_LVM
define|\
value|{0xe6d6d379,0xf507,0x44c2,0xa2,0x3c,{0x23,0x8f,0x2a,0x3d,0xf9,0x28}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_APPLE_BOOT
define|\
value|{0x426F6F74,0x0000,0x11aa,0xaa,0x11,{0x00,0x30,0x65,0x43,0xec,0xac}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_APPLE_HFS
define|\
value|{0x48465300,0x0000,0x11aa,0xaa,0x11,{0x00,0x30,0x65,0x43,0xec,0xac}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_APPLE_UFS
define|\
value|{0x55465300,0x0000,0x11aa,0xaa,0x11,{0x00,0x30,0x65,0x43,0xec,0xac}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_APPLE_ZFS
define|\
value|{0x6a898cc3,0x1dd2,0x11b2,0x99,0xa6,{0x08,0x00,0x20,0x73,0x66,0x31}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_APPLE_RAID
define|\
value|{0x52414944,0x0000,0x11aa,0xaa,0x22,{0x00,0x30,0x65,0x43,0xec,0xac}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_APPLE_RAID_OFFLINE
define|\
value|{0x52414944,0x5f4f,0x11aa,0xaa,0x22,{0x00,0x30,0x65,0x43,0xec,0xac}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_APPLE_LABEL
define|\
value|{0x4C616265,0x6c00,0x11aa,0xaa,0x11,{0x00,0x30,0x65,0x43,0xec,0xac}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_APPLE_TV_RECOVERY
define|\
value|{0x5265636f,0x7665,0x11AA,0xaa,0x11,{0x00,0x30,0x65,0x43,0xec,0xac}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_NETBSD_FFS
define|\
value|{0x49f48d5a,0xb10e,0x11dc,0xb9,0x9b,{0x00,0x19,0xd1,0x87,0x96,0x48}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_NETBSD_LFS
define|\
value|{0x49f48d82,0xb10e,0x11dc,0xb9,0x9b,{0x00,0x19,0xd1,0x87,0x96,0x48}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_NETBSD_SWAP
define|\
value|{0x49f48d32,0xb10e,0x11dc,0xB9,0x9B,{0x00,0x19,0xd1,0x87,0x96,0x48}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_NETBSD_RAID
define|\
value|{0x49f48daa,0xb10e,0x11dc,0xb9,0x9b,{0x00,0x19,0xd1,0x87,0x96,0x48}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_NETBSD_CCD
define|\
value|{0x2db519c4,0xb10f,0x11dc,0xb9,0x9b,{0x00,0x19,0xd1,0x87,0x96,0x48}}
end_define

begin_define
define|#
directive|define
name|GPT_ENT_TYPE_NETBSD_CGD
define|\
value|{0x2db519ec,0xb10f,0x11dc,0xb9,0x9b,{0x00,0x19,0xd1,0x87,0x96,0x48}}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_GPT_H_ */
end_comment

end_unit

