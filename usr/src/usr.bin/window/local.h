begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)local.h	3.6 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Things of local interest.  */
end_comment

begin_define
define|#
directive|define
name|RUNCOM
value|".windowrc"
end_define

begin_define
define|#
directive|define
name|ESCAPEC
value|ctrl('p')
end_define

begin_define
define|#
directive|define
name|NLINE
value|48
end_define

begin_comment
comment|/* default text buffer size */
end_comment

begin_define
define|#
directive|define
name|SHELL
value|"/bin/csh"
end_define

begin_comment
comment|/* if no environment SHELL */
end_comment

end_unit

