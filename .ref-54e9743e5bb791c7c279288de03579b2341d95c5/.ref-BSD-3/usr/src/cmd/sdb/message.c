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
name|BADMOD
init|=
literal|"bad modifier"
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
name|NOPCS
init|=
literal|"no process"
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
name|EXBKPT
init|=
literal|"too many breakpoints"
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
name|SZBKPT
init|=
literal|"bkpt: command too long"
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

