begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)kdb_message.c	7.4 (Berkeley) %G%  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|kdbBADCOM
init|=
literal|"bad command"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbBADSYM
init|=
literal|"symbol not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbBADLOC
init|=
literal|"automatic variable not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbNOCFN
init|=
literal|"c routine not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbNOMATCH
init|=
literal|"cannot locate value"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbBADKET
init|=
literal|"unexpected ')'"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbNOADR
init|=
literal|"address expected"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbBADVAR
init|=
literal|"bad variable"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbADWRAP
init|=
literal|"address wrap around"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbBADEQ
init|=
literal|"unexpected `='"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbBADSYN
init|=
literal|"syntax error"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbNOEOR
init|=
literal|"newline expected"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbNOBKPT
init|=
literal|"no breakpoint set"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbSZBKPT
init|=
literal|"bkpt command too long"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbEXBKPT
init|=
literal|"too many breakpoints"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbBADMOD
init|=
literal|"bad modifier"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbBADRAD
init|=
literal|"invalid radix"
decl_stmt|;
end_decl_stmt

end_unit

