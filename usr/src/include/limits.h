begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)limits.h	5.6 (Berkeley) 6/22/90  */
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

begin_define
define|#
directive|define
name|_BSD_LINE_MAX
value|2048
end_define

end_unit

