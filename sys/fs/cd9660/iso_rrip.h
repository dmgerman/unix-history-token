begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley  * by Pace Willisson (pace@blitz.com).  The Rock Ridge Extension  * Support code is derived from software contributed to Berkeley  * by Atsushi Murai (amurai@spec.co.jp).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)iso_rrip.h	8.2 (Berkeley) 1/23/94  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *	Analyze function flag (similar to RR field bits)  */
end_comment

begin_define
define|#
directive|define
name|ISO_SUSP_ATTR
value|0x0001
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_DEVICE
value|0x0002
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_SLINK
value|0x0004
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_ALTNAME
value|0x0008
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_CLINK
value|0x0010
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_PLINK
value|0x0020
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_RELDIR
value|0x0040
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_TSTAMP
value|0x0080
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_IDFLAG
value|0x0100
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_EXTREF
value|0x0200
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_CONT
value|0x0400
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_OFFSET
value|0x0800
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_STOP
value|0x1000
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_UNKNOWN
value|0x8000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|iso_node
modifier|*
name|inop
decl_stmt|;
name|int
name|fields
decl_stmt|;
comment|/* interesting fields in this analysis */
name|daddr_t
name|iso_ce_blk
decl_stmt|;
comment|/* block of continuation area */
name|off_t
name|iso_ce_off
decl_stmt|;
comment|/* offset of continuation area */
name|int
name|iso_ce_len
decl_stmt|;
comment|/* length of continuation area */
name|struct
name|iso_mnt
modifier|*
name|imp
decl_stmt|;
comment|/* mount structure */
name|cd_ino_t
modifier|*
name|inump
decl_stmt|;
comment|/* inode number pointer */
name|char
modifier|*
name|outbuf
decl_stmt|;
comment|/* name/symbolic link output area */
name|u_short
modifier|*
name|outlen
decl_stmt|;
comment|/* length of above */
name|u_short
name|maxlen
decl_stmt|;
comment|/* maximum length of above */
name|int
name|cont
decl_stmt|;
comment|/* continuation of above */
block|}
name|ISO_RRIP_ANALYZE
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|iso_directory_record
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|cd9660_rrip_analyze
parameter_list|(
name|struct
name|iso_directory_record
modifier|*
name|isodir
parameter_list|,
name|struct
name|iso_node
modifier|*
name|inop
parameter_list|,
name|struct
name|iso_mnt
modifier|*
name|imp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_rrip_getname
parameter_list|(
name|struct
name|iso_directory_record
modifier|*
name|isodir
parameter_list|,
name|char
modifier|*
name|outbuf
parameter_list|,
name|u_short
modifier|*
name|outlen
parameter_list|,
name|cd_ino_t
modifier|*
name|inump
parameter_list|,
name|struct
name|iso_mnt
modifier|*
name|imp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_rrip_getsymname
parameter_list|(
name|struct
name|iso_directory_record
modifier|*
name|isodir
parameter_list|,
name|char
modifier|*
name|outbuf
parameter_list|,
name|u_short
modifier|*
name|outlen
parameter_list|,
name|struct
name|iso_mnt
modifier|*
name|imp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_rrip_offset
parameter_list|(
name|struct
name|iso_directory_record
modifier|*
name|isodir
parameter_list|,
name|struct
name|iso_mnt
modifier|*
name|imp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

end_unit

