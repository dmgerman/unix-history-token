begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*  *  *	UNIX debugger  *  */
end_comment

begin_include
include|#
directive|include
file|"mac.h"
end_include

begin_include
include|#
directive|include
file|"mode.h"
end_include

begin_decl_stmt
name|MSG
name|version
init|=
literal|"\nVERSION sys117	DATE 1978 Dec 27 16:37:44\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADMOD
init|=
literal|"bad modifier"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADCOM
init|=
literal|"bad command"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADSYM
init|=
literal|"symbol not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADLOC
init|=
literal|"automatic variable not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|NOCFN
init|=
literal|"c routine not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|NOMATCH
init|=
literal|"cannot locate value"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|NOBKPT
init|=
literal|"no breakpoint set"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADKET
init|=
literal|"unexpected ')'"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|NOADR
init|=
literal|"address expected"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|NOPCS
init|=
literal|"no process"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADVAR
init|=
literal|"bad variable"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADTXT
init|=
literal|"text address not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADDAT
init|=
literal|"data address not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|ODDADR
init|=
literal|"odd address"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|EXBKPT
init|=
literal|"too many breakpoints"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|A68BAD
init|=
literal|"bad a68 frame"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|A68LNK
init|=
literal|"bad a68 link"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|ADWRAP
init|=
literal|"address wrap around"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADEQ
init|=
literal|"unexpected `='"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADWAIT
init|=
literal|"wait error: process disappeared!"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|ENDPCS
init|=
literal|"process terminated"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|NOFORK
init|=
literal|"try again"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADSYN
init|=
literal|"syntax error"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|NOEOR
init|=
literal|"newline expected"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|SZBKPT
init|=
literal|"bkpt: command too long"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADFIL
init|=
literal|"bad file format"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADNAM
init|=
literal|"not enough space for symbols"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|LONGFIL
init|=
literal|"filename too long"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|NOTOPEN
init|=
literal|"cannot open"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADMAG
init|=
literal|"bad core magic number"
decl_stmt|;
end_decl_stmt

end_unit

