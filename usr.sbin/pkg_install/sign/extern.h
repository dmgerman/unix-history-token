begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $OpenBSD: extern.h,v 1.3 1999/10/07 16:30:32 espie Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1999 Marc Espie.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Marc Espie for the OpenBSD  * Project.  *  * THIS SOFTWARE IS PROVIDED BY THE OPENBSD PROJECT AND CONTRIBUTORS   * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT   * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR   * A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OPENBSD  * PROJECT OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT   * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,   * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY   * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT   * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE   * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Convention: all functions that operate on a FILE * also take a filename  * for diagnostic purposes.  The file can be connected to a pipe, so  *	- don't rewind  *	- don't reopen from filename.  */
end_comment

begin_struct_decl
struct_decl|struct
name|mygzip_header
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|signature
struct_decl|;
end_struct_decl

begin_comment
comment|/* main.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|verbose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|quiet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|userkey
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* common.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|read_header_and_diagnose
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|, \
comment|/*@out@*/
name|struct
name|mygzip_header
modifier|*
name|h
parameter_list|,
comment|/*@null@*/
name|struct
name|signature
modifier|*
modifier|*
name|sign
parameter_list|, \
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|reap
parameter_list|(
name|pid_t
name|pid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sign.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|sign
parameter_list|(
comment|/*@observer@*/
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|type
parameter_list|, \
comment|/*@null@*/
specifier|const
name|char
modifier|*
name|userid
parameter_list|,
name|char
modifier|*
name|envp
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* check.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|check_signature
parameter_list|(
comment|/*@dependent@*/
name|FILE
modifier|*
name|file
parameter_list|, \
comment|/*@null@*/
specifier|const
name|char
modifier|*
name|userid
parameter_list|,
name|char
modifier|*
name|envp
index|[]
parameter_list|, \
comment|/*@observer@*/
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PKG_BADSIG
value|0
end_define

begin_define
define|#
directive|define
name|PKG_GOODSIG
value|1
end_define

begin_define
define|#
directive|define
name|PKG_UNSIGNED
value|2
end_define

begin_define
define|#
directive|define
name|PKG_SIGNED
value|4
end_define

begin_define
define|#
directive|define
name|PKG_SIGERROR
value|8
end_define

begin_define
define|#
directive|define
name|PKG_SIGUNKNOWN
value|16
end_define

begin_typedef
typedef|typedef
comment|/*@observer@*/
name|char
modifier|*
name|pchar
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAXID
value|512
end_define

begin_comment
comment|/* sha1.c */
end_comment

begin_define
define|#
directive|define
name|SHA1_DB_NAME
value|"/var/db/pkg/SHA1"
end_define

begin_function_decl
specifier|extern
name|void
modifier|*
name|new_sha1_checker
parameter_list|(
name|struct
name|mygzip_header
modifier|*
name|h
parameter_list|, \
name|struct
name|signature
modifier|*
name|sign
parameter_list|,
specifier|const
name|char
modifier|*
name|userid
parameter_list|,
name|char
modifier|*
name|envp
index|[]
parameter_list|, \
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sha1_add
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
specifier|const
name|char
modifier|*
name|buffer
parameter_list|, \
name|size_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sha1_sign_ok
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|retrieve_sha1_marker
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|, \
name|struct
name|signature
modifier|*
modifier|*
name|sign
parameter_list|,
specifier|const
name|char
modifier|*
name|userid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* x509.c */
end_comment

begin_define
define|#
directive|define
name|X509_DB_NAME
value|"/var/db/pkg/X509"
end_define

begin_function_decl
specifier|extern
name|void
modifier|*
name|new_x509_checker
parameter_list|(
name|struct
name|mygzip_header
modifier|*
name|h
parameter_list|, \
name|struct
name|signature
modifier|*
name|sign
parameter_list|,
specifier|const
name|char
modifier|*
name|userid
parameter_list|,
name|char
modifier|*
name|envp
index|[]
parameter_list|, \
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|x509_add
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
specifier|const
name|char
modifier|*
name|buffer
parameter_list|, \
name|size_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|x509_sign_ok
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|retrieve_x509_marker
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|, \
name|struct
name|signature
modifier|*
modifier|*
name|sign
parameter_list|,
specifier|const
name|char
modifier|*
name|userid
parameter_list|)
function_decl|;
end_function_decl

end_unit

