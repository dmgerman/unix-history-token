begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Martin Matuska  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* !!ONLY FOR USE INTERNALLY TO LIBARCHIVE!! */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_PLATFORM_ACL_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_PLATFORM_ACL_H_INCLUDED
end_define

begin_comment
comment|/*  * Determine what ACL types are supported  */
end_comment

begin_if
if|#
directive|if
name|ARCHIVE_ACL_FREEBSD
operator|||
name|ARCHIVE_ACL_SUNOS
operator|||
name|ARCHIVE_ACL_LIBACL
end_if

begin_define
define|#
directive|define
name|ARCHIVE_ACL_POSIX1E
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ARCHIVE_ACL_FREEBSD_NFS4
operator|||
name|ARCHIVE_ACL_SUNOS_NFS4
operator|||
expr|\
name|ARCHIVE_ACL_DARWIN
operator|||
name|ARCHIVE_ACL_LIBRICHACL
end_if

begin_define
define|#
directive|define
name|ARCHIVE_ACL_NFS4
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ARCHIVE_ACL_POSIX1E
operator|||
name|ARCHIVE_ACL_NFS4
end_if

begin_define
define|#
directive|define
name|ARCHIVE_ACL_SUPPORT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARCHIVE_PLATFORM_ACL_H_INCLUDED */
end_comment

end_unit

