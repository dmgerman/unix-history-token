begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)main.h	5.3 (Berkeley) 1/3/88  */
end_comment

begin_comment
comment|/*  * Definitions for main program.  *  * The main program just handles the command arguments and then  * gives control to the command module.  It's also the center of  * error recovery, since non-fatal errors longjmp into the main routine.  */
end_comment

begin_decl_stmt
name|BOOLEAN
name|opt
index|[
literal|26
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if command line option given */
end_comment

begin_define
define|#
directive|define
name|option
parameter_list|(
name|c
parameter_list|)
value|opt[(c)-'a']
end_define

begin_define
define|#
directive|define
name|isterm
parameter_list|(
name|file
parameter_list|)
value|(option('i') || isatty(fileno(file)))
end_define

begin_function_decl
name|int
name|main
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* debugger main routine */
end_comment

begin_function_decl
name|int
name|init
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* read in source and object data */
end_comment

begin_function_decl
name|int
name|erecover
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* does non-local goto for error recovery */
end_comment

begin_function_decl
name|int
name|quit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* clean-up before exiting */
end_comment

end_unit

