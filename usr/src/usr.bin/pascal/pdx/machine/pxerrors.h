begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)pxerrors.h	5.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|NERRORS
value|39
end_define

begin_decl_stmt
name|char
modifier|*
name|pxerrmsg
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ESIGNAL
value|SIGTRAP
end_define

begin_define
define|#
directive|define
name|ESTKOVER
value|37
end_define

begin_define
define|#
directive|define
name|EOVERFLOW
value|39
end_define

end_unit

