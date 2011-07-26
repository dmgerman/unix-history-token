begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: cd9660_archimedes.h,v 1.1 2009/01/10 22:06:29 bjh21 Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998, 2009 Ben Harris  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * cd9660_archimedes.c - support for RISC OS "ARCHIMEDES" extension  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|ISO_ARCHIMEDES
block|{
name|char
name|magic
index|[
literal|10
index|]
decl_stmt|;
comment|/* "ARCHIMEDES" */
name|unsigned
name|char
name|loadaddr
index|[
literal|4
index|]
decl_stmt|;
comment|/* Load address, little-endian */
name|unsigned
name|char
name|execaddr
index|[
literal|4
index|]
decl_stmt|;
comment|/* Exec address, little-endian */
name|unsigned
name|char
name|ro_attr
decl_stmt|;
comment|/* RISC OS attributes */
define|#
directive|define
name|RO_ACCESS_UR
value|0x01
comment|/* Owner read */
define|#
directive|define
name|RO_ACCESS_UW
value|0x02
comment|/* Owner write */
define|#
directive|define
name|RO_ACCESS_L
value|0x04
comment|/* Locked */
define|#
directive|define
name|RO_ACCESS_OR
value|0x10
comment|/* Public read */
define|#
directive|define
name|RO_ACCESS_OW
value|0x20
comment|/* Public write */
name|unsigned
name|char
name|cdfs_attr
decl_stmt|;
comment|/* Extra attributes for CDFS */
define|#
directive|define
name|CDFS_PLING
value|0x01
comment|/* Filename begins with '!' */
name|char
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|archimedes_convert_tree
parameter_list|(
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

