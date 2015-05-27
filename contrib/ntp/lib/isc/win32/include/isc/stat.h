begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2007, 2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: stat.h,v 1.9 2009/10/01 23:48:08 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_STAT_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_STAT_H
value|1
end_define

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_comment
comment|/* open() under unix allows setting of read/write permissions  * at the owner, group and other levels.  These don't exist in NT  * We'll just map them all to the NT equivalent  */
end_comment

begin_define
define|#
directive|define
name|S_IREAD
value|_S_IREAD
end_define

begin_comment
comment|/* read permission, owner */
end_comment

begin_define
define|#
directive|define
name|S_IWRITE
value|_S_IWRITE
end_define

begin_comment
comment|/* write permission, owner */
end_comment

begin_define
define|#
directive|define
name|S_IEXEC
value|_S_IEXEC
end_define

begin_comment
comment|/* execute/search permission, owner */
end_comment

begin_define
define|#
directive|define
name|S_IRUSR
value|_S_IREAD
end_define

begin_comment
comment|/* Owner read permission */
end_comment

begin_define
define|#
directive|define
name|S_IWUSR
value|_S_IWRITE
end_define

begin_comment
comment|/* Owner write permission */
end_comment

begin_define
define|#
directive|define
name|S_IRGRP
value|_S_IREAD
end_define

begin_comment
comment|/* Group read permission */
end_comment

begin_define
define|#
directive|define
name|S_IWGRP
value|_S_IWRITE
end_define

begin_comment
comment|/* Group write permission */
end_comment

begin_define
define|#
directive|define
name|S_IROTH
value|_S_IREAD
end_define

begin_comment
comment|/* Other read permission */
end_comment

begin_define
define|#
directive|define
name|S_IWOTH
value|_S_IWRITE
end_define

begin_comment
comment|/* Other write permission */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFMT
end_ifndef

begin_define
define|#
directive|define
name|S_IFMT
value|_S_IFMT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFDIR
end_ifndef

begin_define
define|#
directive|define
name|S_IFDIR
value|_S_IFDIR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFCHR
end_ifndef

begin_define
define|#
directive|define
name|S_IFCHR
value|_S_IFCHR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFREG
end_ifndef

begin_define
define|#
directive|define
name|S_IFREG
value|_S_IFREG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISREG
end_ifndef

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|O_RDONLY
value|_O_RDONLY
end_define

begin_define
define|#
directive|define
name|O_WRONLY
value|_O_WRONLY
end_define

begin_define
define|#
directive|define
name|O_RDWR
value|_O_RDWR
end_define

begin_define
define|#
directive|define
name|O_APPEND
value|_O_APPEND
end_define

begin_define
define|#
directive|define
name|O_CREAT
value|_O_CREAT
end_define

begin_define
define|#
directive|define
name|O_TRUNC
value|_O_TRUNC
end_define

begin_define
define|#
directive|define
name|O_EXCL
value|_O_EXCL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_STAT_H */
end_comment

end_unit

