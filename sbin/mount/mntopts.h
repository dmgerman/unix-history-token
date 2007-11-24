begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994  *      The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mntopts.h	8.7 (Berkeley) 3/29/95  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|mntopt
block|{
specifier|const
name|char
modifier|*
name|m_option
decl_stmt|;
comment|/* option name */
name|int
name|m_inverse
decl_stmt|;
comment|/* if a negative option, e.g. "dev" */
name|int
name|m_flag
decl_stmt|;
comment|/* bit to set, e.g. MNT_RDONLY */
name|int
name|m_altloc
decl_stmt|;
comment|/* 1 => set bit in altflags */
block|}
struct|;
end_struct

begin_comment
comment|/* User-visible MNT_ flags. */
end_comment

begin_define
define|#
directive|define
name|MOPT_ASYNC
value|{ "async",	0, MNT_ASYNC, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_NOATIME
value|{ "atime",	1, MNT_NOATIME, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_NODEV
value|{ "dev",	1, MNT_NODEV, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_NOEXEC
value|{ "exec",	1, MNT_NOEXEC, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_NOSUID
value|{ "suid",	1, MNT_NOSUID, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_NOSYMFOLLOW
value|{ "symfollow",  1, MNT_NOSYMFOLLOW, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_RDONLY
value|{ "rdonly",	0, MNT_RDONLY, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_SYNC
value|{ "sync",	0, MNT_SYNCHRONOUS, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_UNION
value|{ "union",	0, MNT_UNION, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_USERQUOTA
value|{ "userquota",	0, 0, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_GROUPQUOTA
value|{ "groupquota",	0, 0, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_NOCLUSTERR
value|{ "clusterr",	1, MNT_NOCLUSTERR, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_NOCLUSTERW
value|{ "clusterw",	1, MNT_NOCLUSTERW, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_SUIDDIR
value|{ "suiddir",	0, MNT_SUIDDIR, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_SNAPSHOT
value|{ "snapshot",	0, MNT_SNAPSHOT, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_MULTILABEL
value|{ "multilabel",	0, MNT_MULTILABEL, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_ACLS
value|{ "acls",	0, MNT_ACLS, 0 }
end_define

begin_comment
comment|/* Control flags. */
end_comment

begin_define
define|#
directive|define
name|MOPT_FORCE
value|{ "force",	0, MNT_FORCE, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_UPDATE
value|{ "update",	0, MNT_UPDATE, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_RO
value|{ "ro",		0, MNT_RDONLY, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_RW
value|{ "rw",		1, MNT_RDONLY, 0 }
end_define

begin_comment
comment|/* This is parsed by mount(8), but is ignored by specific mount_*(8)s. */
end_comment

begin_define
define|#
directive|define
name|MOPT_AUTO
value|{ "auto",	0, 0, 0 }
end_define

begin_comment
comment|/* A handy macro as terminator of MNT_ array. */
end_comment

begin_define
define|#
directive|define
name|MOPT_END
value|{ NULL,		0, 0, 0 }
end_define

begin_define
define|#
directive|define
name|MOPT_FSTAB_COMPAT
define|\
value|MOPT_RO,							\ 	MOPT_RW,							\ 	MOPT_AUTO
end_define

begin_comment
comment|/* Standard options which all mounts can understand. */
end_comment

begin_define
define|#
directive|define
name|MOPT_STDOPTS
define|\
value|MOPT_USERQUOTA,							\ 	MOPT_GROUPQUOTA,						\ 	MOPT_FSTAB_COMPAT,						\ 	MOPT_NOATIME,							\ 	MOPT_NODEV,							\ 	MOPT_NOEXEC,							\ 	MOPT_SUIDDIR,
comment|/* must be before MOPT_NOSUID */
value|\ 	MOPT_NOSUID,							\ 	MOPT_NOSYMFOLLOW,						\ 	MOPT_RDONLY,							\ 	MOPT_UNION,							\ 	MOPT_NOCLUSTERR,						\ 	MOPT_NOCLUSTERW,						\ 	MOPT_MULTILABEL,						\ 	MOPT_ACLS
end_define

begin_function_decl
name|void
name|getmntopts
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|mntopt
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rmslashes
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|checkpath
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
name|resolved_path
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|getmnt_silent
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|build_iovec
parameter_list|(
name|struct
name|iovec
modifier|*
modifier|*
name|iov
parameter_list|,
name|int
modifier|*
name|iovlen
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|val
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|build_iovec_argf
parameter_list|(
name|struct
name|iovec
modifier|*
modifier|*
name|iov
parameter_list|,
name|int
modifier|*
name|iovlen
parameter_list|,
specifier|const
name|char
modifier|*
name|name
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

end_unit

