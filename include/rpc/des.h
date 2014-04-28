begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  @(#)des.h	2.2 88/08/10 4.0 RPCSRC; from 2.7 88/02/08 SMI  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,  *   this list of conditions and the following disclaimer in the documentation  *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its  *   contributors may be used to endorse or promote products derived  *   from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Generic DES driver interface  * Keep this file hardware independent!  * Copyright (c) 1986 by Sun Microsystems, Inc.  */
end_comment

begin_define
define|#
directive|define
name|DES_MAXLEN
value|65536
end_define

begin_comment
comment|/* maximum # of bytes to encrypt  */
end_comment

begin_define
define|#
directive|define
name|DES_QUICKLEN
value|16
end_define

begin_comment
comment|/* maximum # of bytes to encrypt quickly */
end_comment

begin_enum
enum|enum
name|desdir
block|{
name|ENCRYPT
block|,
name|DECRYPT
block|}
enum|;
end_enum

begin_enum
enum|enum
name|desmode
block|{
name|CBC
block|,
name|ECB
block|}
enum|;
end_enum

begin_comment
comment|/*  * parameters to ioctl call  */
end_comment

begin_struct
struct|struct
name|desparams
block|{
name|u_char
name|des_key
index|[
literal|8
index|]
decl_stmt|;
comment|/* key (with low bit parity) */
name|enum
name|desdir
name|des_dir
decl_stmt|;
comment|/* direction */
name|enum
name|desmode
name|des_mode
decl_stmt|;
comment|/* mode */
name|u_char
name|des_ivec
index|[
literal|8
index|]
decl_stmt|;
comment|/* input vector */
name|unsigned
name|des_len
decl_stmt|;
comment|/* number of bytes to crypt */
union|union
block|{
name|u_char
name|UDES_data
index|[
name|DES_QUICKLEN
index|]
decl_stmt|;
name|u_char
modifier|*
name|UDES_buf
decl_stmt|;
block|}
name|UDES
union|;
define|#
directive|define
name|des_data
value|UDES.UDES_data
comment|/* direct data here if quick */
define|#
directive|define
name|des_buf
value|UDES.UDES_buf
comment|/* otherwise, pointer to data */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_comment
comment|/*  * These ioctls are only implemented in SunOS. Maybe someday  * if somebody writes a driver for DES hardware that works  * with FreeBSD, we can being that back.  */
end_comment

begin_comment
comment|/*  * Encrypt an arbitrary sized buffer  */
end_comment

begin_define
define|#
directive|define
name|DESIOCBLOCK
value|_IOWR('d', 6, struct desparams)
end_define

begin_comment
comment|/*   * Encrypt of small amount of data, quickly  */
end_comment

begin_define
define|#
directive|define
name|DESIOCQUICK
value|_IOWR('d', 7, struct desparams)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Software DES.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|_des_crypt
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|desparams
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

