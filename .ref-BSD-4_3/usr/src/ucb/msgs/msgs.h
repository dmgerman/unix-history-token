begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)msgs.h	5.1 (Berkeley) 6/4/85  */
end_comment

begin_comment
comment|/*  * Local definitions for msgs.  */
end_comment

begin_define
define|#
directive|define
name|USRMSGS
value|"/usr/msgs"
end_define

begin_comment
comment|/* msgs directory */
end_comment

begin_define
define|#
directive|define
name|MAIL
value|"/usr/ucb/Mail -f %s"
end_define

begin_comment
comment|/* could set destination also */
end_comment

begin_define
define|#
directive|define
name|PAGE
value|"/usr/ucb/more -%d"
end_define

begin_comment
comment|/* crt screen paging program */
end_comment

end_unit

