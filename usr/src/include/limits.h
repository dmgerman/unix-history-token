begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)limits.h	5.4 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|_POSIX_ARG_MAX
value|4096
end_define

begin_define
define|#
directive|define
name|_POSIX_CHILD_MAX
value|6
end_define

begin_define
define|#
directive|define
name|_POSIX_LINK_MAX
value|8
end_define

begin_define
define|#
directive|define
name|_POSIX_MAX_CANON
value|255
end_define

begin_define
define|#
directive|define
name|_POSIX_MAX_INPUT
value|255
end_define

begin_define
define|#
directive|define
name|_POSIX_NAME_MAX
value|14
end_define

begin_define
define|#
directive|define
name|_POSIX_NGROUPS_MAX
value|0
end_define

begin_define
define|#
directive|define
name|_POSIX_OPEN_MAX
value|16
end_define

begin_define
define|#
directive|define
name|_POSIX_PATH_MAX
value|255
end_define

begin_define
define|#
directive|define
name|_POSIX_PIPE_BUF
value|512
end_define

begin_include
include|#
directive|include
file|<machine/machlimits.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslimits.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|LINE_MAX
value|2048
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

