begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Robert Nordier  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BTX_H_
end_ifndef

begin_define
define|#
directive|define
name|_BTX_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|BTX_PGSIZE
value|0x1000
end_define

begin_comment
comment|/* Page size */
end_comment

begin_define
define|#
directive|define
name|BTX_PGBASE
value|0x5000
end_define

begin_comment
comment|/* Start of page tables */
end_comment

begin_define
define|#
directive|define
name|BTX_MAXCWR
value|0x3bc
end_define

begin_comment
comment|/* Max. btx_pgctl adjustment */
end_comment

begin_comment
comment|/*  * BTX image header.  */
end_comment

begin_struct
struct|struct
name|btx_hdr
block|{
name|uint8_t
name|btx_machid
decl_stmt|;
comment|/* Machine ID */
name|uint8_t
name|btx_hdrsz
decl_stmt|;
comment|/* Header size */
name|uint8_t
name|btx_magic
index|[
literal|3
index|]
decl_stmt|;
comment|/* Magic */
name|uint8_t
name|btx_majver
decl_stmt|;
comment|/* Major version */
name|uint8_t
name|btx_minver
decl_stmt|;
comment|/* Minor version */
name|uint8_t
name|btx_flags
decl_stmt|;
comment|/* Flags */
name|uint16_t
name|btx_pgctl
decl_stmt|;
comment|/* Paging control */
name|uint16_t
name|btx_textsz
decl_stmt|;
comment|/* Text size */
name|uint32_t
name|btx_entry
decl_stmt|;
comment|/* Client entry address */
block|}
struct|;
end_struct

begin_comment
comment|/* btx_machid */
end_comment

begin_define
define|#
directive|define
name|BTX_I386
value|0xeb
end_define

begin_comment
comment|/* Intel i386 or compatible */
end_comment

begin_comment
comment|/* btx_magic */
end_comment

begin_define
define|#
directive|define
name|BTX_MAG0
value|'B'
end_define

begin_define
define|#
directive|define
name|BTX_MAG1
value|'T'
end_define

begin_define
define|#
directive|define
name|BTX_MAG2
value|'X'
end_define

begin_comment
comment|/* btx_flags */
end_comment

begin_define
define|#
directive|define
name|BTX_MAPONE
value|0x80
end_define

begin_comment
comment|/* Start mapping at page 1 */
end_comment

begin_define
define|#
directive|define
name|BTX_MAPPED
parameter_list|(
name|btx
parameter_list|)
value|(((btx).btx_pgctl | (BTX_PGSIZE / 4 - 1)) + 1)
end_define

begin_define
define|#
directive|define
name|BTX_ORIGIN
parameter_list|(
name|btx
parameter_list|)
value|(BTX_PGBASE + BTX_MAPPED(btx) * 4)
end_define

begin_define
define|#
directive|define
name|BTX_ENTRY
parameter_list|(
name|btx
parameter_list|)
value|(BTX_ORIGIN(btx) + 2 + (btx).btx_hdrsz)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BTX_H_ */
end_comment

end_unit

