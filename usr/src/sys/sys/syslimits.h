begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)syslimits.h	8.1 (Berkeley) %G%  */
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
comment|/* max bytes in term canon input line */
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
comment|/* max bytes in a file name */
end_comment

begin_define
define|#
directive|define
name|NGROUPS_MAX
value|16
end_define

begin_comment
comment|/* max supplemental group id's */
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
comment|/* max bytes in pathname */
end_comment

begin_define
define|#
directive|define
name|PIPE_BUF
value|512
end_define

begin_comment
comment|/* max bytes for atomic pipe writes */
end_comment

begin_define
define|#
directive|define
name|BC_BASE_MAX
value|99
end_define

begin_comment
comment|/* max ibase/obase values in bc(1) */
end_comment

begin_define
define|#
directive|define
name|BC_DIM_MAX
value|2048
end_define

begin_comment
comment|/* max array elements in bc(1) */
end_comment

begin_define
define|#
directive|define
name|BC_SCALE_MAX
value|99
end_define

begin_comment
comment|/* max scale value in bc(1) */
end_comment

begin_define
define|#
directive|define
name|BC_STRING_MAX
value|1000
end_define

begin_comment
comment|/* max const string length in bc(1) */
end_comment

begin_define
define|#
directive|define
name|COLL_WEIGHTS_MAX
value|0
end_define

begin_comment
comment|/* max weights for order keyword */
end_comment

begin_define
define|#
directive|define
name|EXPR_NEST_MAX
value|32
end_define

begin_comment
comment|/* max expressions nested in expr(1) */
end_comment

begin_define
define|#
directive|define
name|LINE_MAX
value|2048
end_define

begin_comment
comment|/* max bytes in an input line */
end_comment

begin_define
define|#
directive|define
name|RE_DUP_MAX
value|255
end_define

begin_comment
comment|/* max RE's in interval notation */
end_comment

end_unit

