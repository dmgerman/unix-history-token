begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)unistd.h	5.5 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* compile-time symbolic constants */
end_comment

begin_define
define|#
directive|define
name|POSIX_JOB_CONTROL
end_define

begin_comment
comment|/* implementation supports job control */
end_comment

begin_define
define|#
directive|define
name|POSIX_SAVED_IDS
end_define

begin_comment
comment|/* saved set-user-ID and set-group-ID */
end_comment

begin_define
define|#
directive|define
name|POSIX_VERSION
value|198808L
end_define

begin_comment
comment|/* execution-time symbolic constants */
end_comment

begin_define
define|#
directive|define
name|POSIX_CHOWN_RESTRICTED
end_define

begin_comment
comment|/* chown requires appropriate privileges */
end_comment

begin_define
define|#
directive|define
name|POSIX_NO_TRUNC
end_define

begin_comment
comment|/* too-long path components generate errors */
end_comment

begin_define
define|#
directive|define
name|POSIX_VDISABLE
end_define

begin_comment
comment|/* may disable terminal special characters */
end_comment

begin_comment
comment|/* access function */
end_comment

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_comment
comment|/* test for existence of file */
end_comment

begin_define
define|#
directive|define
name|X_OK
value|0x01
end_define

begin_comment
comment|/* test for execute or search permission */
end_comment

begin_define
define|#
directive|define
name|W_OK
value|0x02
end_define

begin_comment
comment|/* test for write permission */
end_comment

begin_define
define|#
directive|define
name|R_OK
value|0x04
end_define

begin_comment
comment|/* test for read permission */
end_comment

begin_comment
comment|/* lseek function */
end_comment

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_comment
comment|/* set file offset to offset */
end_comment

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_comment
comment|/* set file offset to current plus offset */
end_comment

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_comment
comment|/* set file offset to EOF plus offset */
end_comment

begin_comment
comment|/* map a stream pointer to a file descriptor */
end_comment

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_comment
comment|/* standard input value, stdin */
end_comment

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_comment
comment|/* standard output value, stdout */
end_comment

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_comment
comment|/* standard error value, stdout */
end_comment

begin_comment
comment|/* fnmatch function */
end_comment

begin_define
define|#
directive|define
name|FNM_PATHNAME
value|0x01
end_define

begin_comment
comment|/* match pathnames, not filenames */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|FNM_QUOTE
value|0x02
end_define

begin_comment
comment|/* escape special chars with \ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_comment
comment|/* null pointer constant */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* configurable pathname variables */
end_comment

begin_define
define|#
directive|define
name|_PC_LINK_MAX
value|1
end_define

begin_define
define|#
directive|define
name|_PC_MAX_CANON
value|2
end_define

begin_define
define|#
directive|define
name|_PC_MAX_INPUT
value|3
end_define

begin_define
define|#
directive|define
name|_PC_NAME_MAX
value|4
end_define

begin_define
define|#
directive|define
name|_PC_PATH_MAX
value|5
end_define

begin_define
define|#
directive|define
name|_PC_PIPE_BUF
value|6
end_define

begin_define
define|#
directive|define
name|_PC_CHOWN_RESTRICTED
value|7
end_define

begin_define
define|#
directive|define
name|_PC_NO_TRUNC
value|8
end_define

begin_define
define|#
directive|define
name|_PC_VDISABLE
value|9
end_define

begin_comment
comment|/* configurable system variables */
end_comment

begin_define
define|#
directive|define
name|_SC_ARG_MAX
value|1
end_define

begin_define
define|#
directive|define
name|_SC_CHILD_MAX
value|2
end_define

begin_define
define|#
directive|define
name|_SC_CLK_TCK
value|3
end_define

begin_define
define|#
directive|define
name|_SC_NGROUPS_MAX
value|4
end_define

begin_define
define|#
directive|define
name|_SC_OPEN_MAX
value|5
end_define

begin_define
define|#
directive|define
name|_SC_JOB_CONTROL
value|6
end_define

begin_define
define|#
directive|define
name|_SC_SAVED_IDS
value|7
end_define

begin_define
define|#
directive|define
name|_SC_VERSION
value|8
end_define

end_unit

