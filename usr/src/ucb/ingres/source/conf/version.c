begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)version.c
literal|7.10
literal|10
argument|/
literal|27
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  VERSION.C -- define the current version ** **	This just factors out the current version into one file **	to make releases easier.  It is printed by the terminal **	monitor, but should probably be loaded with everything **	to guarantee a stamp in every file. ** **	This file defines the system version identification. */
end_comment

begin_decl_stmt
name|char
name|SysIdent
index|[]
init|=
literal|"INGRES version 7.10 (10/27/81)"
decl_stmt|;
end_decl_stmt

end_unit

