begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)status.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * status.h -- status code table for internal commands  * by A.Fujita, FEB-02-1992  */
end_comment

begin_define
define|#
directive|define
name|ST_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|ST_EXIT
value|-1
end_define

begin_define
define|#
directive|define
name|ST_NOTFOUND
value|-2
end_define

begin_define
define|#
directive|define
name|ST_ERROR
value|1
end_define

end_unit

