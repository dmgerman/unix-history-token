begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Kai Wang  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|BSDAR_VERSION
value|"1.1.0"
end_define

begin_comment
comment|/*  * ar(1) options.  */
end_comment

begin_define
define|#
directive|define
name|AR_A
value|0x0001
end_define

begin_comment
comment|/* position-after */
end_comment

begin_define
define|#
directive|define
name|AR_B
value|0x0002
end_define

begin_comment
comment|/* position-before */
end_comment

begin_define
define|#
directive|define
name|AR_C
value|0x0004
end_define

begin_comment
comment|/* creating new archive */
end_comment

begin_define
define|#
directive|define
name|AR_CC
value|0x0008
end_define

begin_comment
comment|/* do not overwrite when extracting */
end_comment

begin_define
define|#
directive|define
name|AR_J
value|0x0010
end_define

begin_comment
comment|/* bzip2 compression */
end_comment

begin_define
define|#
directive|define
name|AR_O
value|0x0020
end_define

begin_comment
comment|/* preserve original mtime when extracting */
end_comment

begin_define
define|#
directive|define
name|AR_S
value|0x0040
end_define

begin_comment
comment|/* write archive symbol table */
end_comment

begin_define
define|#
directive|define
name|AR_SS
value|0x0080
end_define

begin_comment
comment|/* do not write archive symbol table */
end_comment

begin_define
define|#
directive|define
name|AR_TR
value|0x0100
end_define

begin_comment
comment|/* only keep first 15 chars for member name */
end_comment

begin_define
define|#
directive|define
name|AR_U
value|0x0200
end_define

begin_comment
comment|/* only extract or update newer members.*/
end_comment

begin_define
define|#
directive|define
name|AR_V
value|0x0400
end_define

begin_comment
comment|/* verbose mode */
end_comment

begin_define
define|#
directive|define
name|AR_Z
value|0x0800
end_define

begin_comment
comment|/* gzip compression */
end_comment

begin_define
define|#
directive|define
name|AR_D
value|0x1000
end_define

begin_comment
comment|/* insert dummy mode, mtime, uid and gid */
end_comment

begin_define
define|#
directive|define
name|DEF_BLKSZ
value|10240
end_define

begin_comment
comment|/* default block size */
end_comment

begin_comment
comment|/*  * Convenient wrapper for general libarchive error handling.  */
end_comment

begin_define
define|#
directive|define
name|AC
parameter_list|(
name|CALL
parameter_list|)
value|do {					\ 	if ((CALL))					\ 		bsdar_errc(bsdar, EX_SOFTWARE, 0, "%s",	\ 		    archive_error_string(a));		\ } while (0)
end_define

begin_comment
comment|/*  * In-memory representation of archive member(object).  */
end_comment

begin_struct
struct|struct
name|ar_obj
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* member name */
name|void
modifier|*
name|maddr
decl_stmt|;
comment|/* mmap start address */
name|uid_t
name|uid
decl_stmt|;
comment|/* user id */
name|gid_t
name|gid
decl_stmt|;
comment|/* group id */
name|mode_t
name|md
decl_stmt|;
comment|/* octal file permissions */
name|size_t
name|size
decl_stmt|;
comment|/* member size */
name|time_t
name|mtime
decl_stmt|;
comment|/* modification time */
name|int
name|fd
decl_stmt|;
comment|/* file descriptor */
name|dev_t
name|dev
decl_stmt|;
comment|/* inode's device */
name|ino_t
name|ino
decl_stmt|;
comment|/* inode's number */
name|TAILQ_ENTRY
argument_list|(
argument|ar_obj
argument_list|)
name|objs
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure encapsulates the "global" data for "ar" program.  */
end_comment

begin_struct
struct|struct
name|bsdar
block|{
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* archive name. */
specifier|const
name|char
modifier|*
name|addlib
decl_stmt|;
comment|/* target of ADDLIB. */
specifier|const
name|char
modifier|*
name|posarg
decl_stmt|;
comment|/* position arg for modifiers -a, -b. */
name|char
name|mode
decl_stmt|;
comment|/* program mode */
name|int
name|options
decl_stmt|;
comment|/* command line options */
specifier|const
name|char
modifier|*
name|progname
decl_stmt|;
comment|/* program name */
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
comment|/* 	 * Fields for the archive string table. 	 */
name|char
modifier|*
name|as
decl_stmt|;
comment|/* buffer for archive string table. */
name|size_t
name|as_sz
decl_stmt|;
comment|/* current size of as table. */
name|size_t
name|as_cap
decl_stmt|;
comment|/* capacity of as table buffer. */
comment|/* 	 * Fields for the archive symbol table. 	 */
name|uint32_t
name|s_cnt
decl_stmt|;
comment|/* current number of symbols. */
name|uint32_t
modifier|*
name|s_so
decl_stmt|;
comment|/* symbol offset table. */
name|size_t
name|s_so_cap
decl_stmt|;
comment|/* capacity of so table buffer. */
name|char
modifier|*
name|s_sn
decl_stmt|;
comment|/* symbol name table */
name|size_t
name|s_sn_cap
decl_stmt|;
comment|/* capacity of sn table buffer. */
name|size_t
name|s_sn_sz
decl_stmt|;
comment|/* current size of sn table. */
comment|/* Current member's offset (relative to the end of pseudo members.) */
name|off_t
name|rela_off
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ar_obj
argument_list|)
name|v_obj
expr_stmt|;
comment|/* object(member) list */
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|bsdar_errc
argument_list|(
expr|struct
name|bsdar
operator|*
argument_list|,
name|int
name|_eval
argument_list|,
name|int
name|_code
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|bsdar_warnc
parameter_list|(
name|struct
name|bsdar
modifier|*
parameter_list|,
name|int
name|_code
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_mode_d
parameter_list|(
name|struct
name|bsdar
modifier|*
name|bsdar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_mode_m
parameter_list|(
name|struct
name|bsdar
modifier|*
name|bsdar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_mode_p
parameter_list|(
name|struct
name|bsdar
modifier|*
name|bsdar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_mode_q
parameter_list|(
name|struct
name|bsdar
modifier|*
name|bsdar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_mode_r
parameter_list|(
name|struct
name|bsdar
modifier|*
name|bsdar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_mode_s
parameter_list|(
name|struct
name|bsdar
modifier|*
name|bsdar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_mode_t
parameter_list|(
name|struct
name|bsdar
modifier|*
name|bsdar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_mode_x
parameter_list|(
name|struct
name|bsdar
modifier|*
name|bsdar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_mode_A
parameter_list|(
name|struct
name|bsdar
modifier|*
name|bsdar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_mode_script
parameter_list|(
name|struct
name|bsdar
modifier|*
name|ar
parameter_list|)
function_decl|;
end_function_decl

end_unit

