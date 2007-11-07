begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $OpenBSD: gzip.h,v 1.2 1999/10/04 21:46:28 espie Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1999 Marc Espie.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Marc Espie for the OpenBSD  * Project.  *  * THIS SOFTWARE IS PROVIDED BY THE OPENBSD PROJECT AND CONTRIBUTORS   * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT   * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR   * A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OPENBSD  * PROJECT OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT   * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,   * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY   * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT   * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE   * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|GZIP_MAGIC0
value|'\037'
end_define

begin_define
define|#
directive|define
name|GZIP_MAGIC1
value|'\213'
end_define

begin_comment
comment|/* flags values */
end_comment

begin_define
define|#
directive|define
name|CONTINUATION
value|0x02
end_define

begin_define
define|#
directive|define
name|EXTRA_FIELD
value|0x04
end_define

begin_comment
comment|/*  * Meaningful fields in a gzip header, see gzip proper for details.  * This structure should not be fiddled with outside of gzip_read_header  * and gzip_write_header   */
end_comment

begin_struct
struct|struct
name|mygzip_header
block|{
name|char
name|method
decl_stmt|;
name|char
name|flags
decl_stmt|;
name|char
name|stamp
index|[
literal|6
index|]
decl_stmt|;
name|char
name|part
index|[
literal|2
index|]
decl_stmt|;
comment|/* remaining extra, after know signs have been read */
name|unsigned
name|int
name|remaining
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TAGSIZE
value|8
end_define

begin_define
define|#
directive|define
name|TAGCHECK
value|6
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|SIGNTAG
index|[
literal|8
index|]
typedef|;
end_typedef

begin_comment
comment|/* stack of signatures */
end_comment

begin_struct
struct|struct
name|signature
block|{
name|SIGNTAG
name|tag
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|length
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
name|struct
name|signature
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* returns from gzip_read_header */
end_comment

begin_define
define|#
directive|define
name|GZIP_UNSIGNED
value|0
end_define

begin_comment
comment|/* gzip file, no signature */
end_comment

begin_define
define|#
directive|define
name|GZIP_SIGNED
value|1
end_define

begin_comment
comment|/* gzip file, signature parsed ok */
end_comment

begin_define
define|#
directive|define
name|GZIP_NOT_GZIP
value|2
end_define

begin_comment
comment|/* not a proper gzip file */
end_comment

begin_define
define|#
directive|define
name|GZIP_NOT_PGPSIGNED
value|3
end_define

begin_comment
comment|/* gzip file, unknown extension */
end_comment

begin_function_decl
specifier|extern
name|int
name|gzip_read_header
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
comment|/*@out@*/
name|struct
name|mygzip_header
modifier|*
name|h
parameter_list|, \
comment|/*@null@*/
name|struct
name|signature
modifier|*
modifier|*
name|sign
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* gzip_write_header returns 1 for success */
end_comment

begin_function_decl
specifier|extern
name|int
name|gzip_write_header
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
specifier|const
name|struct
name|mygzip_header
modifier|*
name|h
parameter_list|, \
comment|/*@null@*/
name|struct
name|signature
modifier|*
name|sign
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Writing header to memory. Returns size needed, or 0 if buffer too small  * buffer must be at least 14 characters  */
end_comment

begin_function_decl
specifier|extern
name|int
name|gzip_copy_header
parameter_list|(
specifier|const
name|struct
name|mygzip_header
modifier|*
name|h
parameter_list|, \
comment|/*@null@*/
name|struct
name|signature
modifier|*
name|sign
parameter_list|, \
name|void
function_decl|(
modifier|*
name|add
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_signature
parameter_list|(
comment|/*@null@*/
name|struct
name|signature
modifier|*
name|sign
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sign_fill_tag
parameter_list|(
name|struct
name|signature
modifier|*
name|sign
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|KNOWN_TAGS
value|4
end_define

begin_define
define|#
directive|define
name|TAG_PGP
value|0
end_define

begin_define
define|#
directive|define
name|TAG_SHA1
value|1
end_define

begin_define
define|#
directive|define
name|TAG_X509
value|2
end_define

begin_define
define|#
directive|define
name|TAG_OLD
value|3
end_define

begin_define
define|#
directive|define
name|TAG_ANY
value|-1
end_define

begin_define
define|#
directive|define
name|pgptag
value|(known_tags[TAG_PGP])
end_define

begin_define
define|#
directive|define
name|sha1tag
value|(known_tags[TAG_SHA1])
end_define

begin_define
define|#
directive|define
name|x509tag
value|(known_tags[TAG_X509])
end_define

begin_decl_stmt
specifier|extern
name|SIGNTAG
name|known_tags
index|[
name|KNOWN_TAGS
index|]
decl_stmt|;
end_decl_stmt

end_unit

