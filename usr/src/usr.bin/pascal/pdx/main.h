begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)main.h	5.1 (Berkeley) %G%  */
end_comment

begin_expr_stmt
operator|*
operator|*
name|Definitions
end_expr_stmt

begin_for
for|for main program.  *  * The main program just handles the command arguments and then  * gives control to the command module.  It's also the center of  * error recovery, since non-fatal errors longjmp into the main routine.  */  BOOLEAN opt[26];	/* true if command line option given */  #define option(c)	opt[(c)-'a'] #define isterm(file)	(option('i'
end_for

unit|) || isatty(fileno(file)))  main();			/* debugger main routine */ init();			/* read in source and object data */ erecover();		/* does non-local goto for error recovery */ quit();			/* clean-up before exiting */
end_unit

