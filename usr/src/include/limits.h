begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)limits.h	5.7 (Berkeley) %G%  */
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

begin_define
define|#
directive|define
name|_POSIX2_BC_BASE_MAX
value|99
end_define

begin_define
define|#
directive|define
name|_POSIX2_BC_DIM_MAX
value|2048
end_define

begin_define
define|#
directive|define
name|_POSIX2_BC_SCALE_MAX
value|99
end_define

begin_define
define|#
directive|define
name|_POSIX2_BC_STRING_MAX
value|1000
end_define

begin_define
define|#
directive|define
name|_POSIX2_EQUIV_CLASS_MAX
value|2
end_define

begin_define
define|#
directive|define
name|_POSIX2_EXPR_NEST_MAX
value|32
end_define

begin_define
define|#
directive|define
name|_POSIX2_LINE_MAX
value|2048
end_define

begin_define
define|#
directive|define
name|_POSIX2_RE_DUP_MAX
value|255
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

end_unit

