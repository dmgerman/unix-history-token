begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)fnmatch.h	5.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|FNM_NOMATCH
value|1
end_define

begin_comment
comment|/* Match failed. */
end_comment

begin_define
define|#
directive|define
name|FNM_NOESCAPE
value|0x01
end_define

begin_comment
comment|/* Disable backslash escaping. */
end_comment

begin_define
define|#
directive|define
name|FNM_PATHNAME
value|0x02
end_define

begin_comment
comment|/* Slash must be matched by slash. */
end_comment

begin_define
define|#
directive|define
name|FNM_PERIOD
value|0x04
end_define

begin_comment
comment|/* Period must be matched by period. */
end_comment

end_unit

