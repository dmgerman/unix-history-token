begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)kdb_message.c	7.3 (Berkeley) 12/15/86  */
end_comment

begin_include
include|#
directive|include
file|"../kdb/redef.h"
end_include

begin_decl_stmt
name|char
modifier|*
name|BADCOM
init|=
literal|"bad command"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|BADSYM
init|=
literal|"symbol not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|BADLOC
init|=
literal|"automatic variable not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|NOCFN
init|=
literal|"c routine not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|NOMATCH
init|=
literal|"cannot locate value"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|BADKET
init|=
literal|"unexpected ')'"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|NOADR
init|=
literal|"address expected"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|BADVAR
init|=
literal|"bad variable"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ADWRAP
init|=
literal|"address wrap around"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|BADEQ
init|=
literal|"unexpected `='"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|BADSYN
init|=
literal|"syntax error"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|NOEOR
init|=
literal|"newline expected"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|NOBKPT
init|=
literal|"no breakpoint set"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|SZBKPT
init|=
literal|"bkpt command too long"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|EXBKPT
init|=
literal|"too many breakpoints"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|BADMOD
init|=
literal|"bad modifier"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|BADRAD
init|=
literal|"invalid radix"
decl_stmt|;
end_decl_stmt

end_unit

