begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)syslimits.h	7.3 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|ARG_MAX
value|20480
end_define

begin_comment
comment|/* max bytes for an exec function */
end_comment

begin_define
define|#
directive|define
name|CHILD_MAX
value|40
end_define

begin_comment
comment|/* max simultaneous processes */
end_comment

begin_define
define|#
directive|define
name|LINK_MAX
value|32767
end_define

begin_comment
comment|/* max file link count */
end_comment

begin_define
define|#
directive|define
name|MAX_CANON
value|255
end_define

begin_comment
comment|/* max bytes in terminal canonical input line */
end_comment

begin_define
define|#
directive|define
name|MAX_INPUT
value|255
end_define

begin_comment
comment|/* max bytes in terminal input */
end_comment

begin_define
define|#
directive|define
name|NAME_MAX
value|255
end_define

begin_comment
comment|/* max number of bytes in a file name */
end_comment

begin_define
define|#
directive|define
name|NGROUPS_MAX
value|16
end_define

begin_comment
comment|/* max number of supplemental group id's */
end_comment

begin_define
define|#
directive|define
name|OPEN_MAX
value|64
end_define

begin_comment
comment|/* max open files per process */
end_comment

begin_define
define|#
directive|define
name|PATH_MAX
value|1024
end_define

begin_comment
comment|/* max number of bytes in pathname */
end_comment

begin_define
define|#
directive|define
name|PIPE_BUF
value|512
end_define

begin_comment
comment|/* max number of bytes for atomic pipe writes */
end_comment

end_unit

