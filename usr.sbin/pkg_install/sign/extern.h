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

begin_decl_stmt
specifier|extern
name|int
name|read_header_and_diagnose
name|__P
argument_list|(
operator|(
name|FILE
operator|*
name|file
operator|,
expr|\
comment|/*@out@*/
expr|struct
name|mygzip_header
operator|*
name|h
operator|,
comment|/*@null@*/
expr|struct
name|signature
operator|*
operator|*
name|sign
operator|,
expr|\
specifier|const
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reap
name|__P
argument_list|(
operator|(
name|pid_t
name|pid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sign.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sign
name|__P
argument_list|(
operator|(
comment|/*@observer@*/
specifier|const
name|char
operator|*
name|filename
operator|,
name|int
name|type
operator|,
expr|\
comment|/*@null@*/
specifier|const
name|char
operator|*
name|userid
operator|,
name|char
operator|*
name|envp
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* check.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|check_signature
name|__P
argument_list|(
operator|(
comment|/*@dependent@*/
name|FILE
operator|*
name|file
operator|,
expr|\
comment|/*@null@*/
specifier|const
name|char
operator|*
name|userid
operator|,
name|char
operator|*
name|envp
index|[]
operator|,
expr|\
comment|/*@observer@*/
specifier|const
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|new_sha1_checker
name|__P
argument_list|(
operator|(
expr|struct
name|mygzip_header
operator|*
name|h
operator|,
expr|\ 	struct
name|signature
operator|*
name|sign
operator|,
specifier|const
name|char
operator|*
name|userid
operator|,
name|char
operator|*
name|envp
index|[]
operator|,
expr|\
specifier|const
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sha1_add
name|__P
argument_list|(
operator|(
name|void
operator|*
name|arg
operator|,
specifier|const
name|char
operator|*
name|buffer
operator|,
expr|\
name|size_t
name|length
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sha1_sign_ok
name|__P
argument_list|(
operator|(
name|void
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|retrieve_sha1_marker
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|filename
operator|,
expr|\ 	struct
name|signature
operator|*
operator|*
name|sign
operator|,
specifier|const
name|char
operator|*
name|userid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* x509.c */
end_comment

begin_define
define|#
directive|define
name|X509_DB_NAME
value|"/var/db/pkg/X509"
end_define

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|new_x509_checker
name|__P
argument_list|(
operator|(
expr|struct
name|mygzip_header
operator|*
name|h
operator|,
expr|\ 	struct
name|signature
operator|*
name|sign
operator|,
specifier|const
name|char
operator|*
name|userid
operator|,
name|char
operator|*
name|envp
index|[]
operator|,
expr|\
specifier|const
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|x509_add
name|__P
argument_list|(
operator|(
name|void
operator|*
name|arg
operator|,
specifier|const
name|char
operator|*
name|buffer
operator|,
expr|\
name|size_t
name|length
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|x509_sign_ok
name|__P
argument_list|(
operator|(
name|void
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|retrieve_x509_marker
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|filename
operator|,
expr|\ 	struct
name|signature
operator|*
operator|*
name|sign
operator|,
specifier|const
name|char
operator|*
name|userid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

