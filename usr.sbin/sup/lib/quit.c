begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator   or   Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the rights  * to redistribute these changes.  */
end_comment

begin_comment
comment|/*  *  quit  --  print message and exit  *  *  Usage:  quit (status,format [,arg]...);  *	int status;  *	(... format and arg[s] make up a printf-arglist)  *  *  Quit is a way to easily print an arbitrary message and exit.  *  It is most useful for error exits from a program:  *	if (open (...)< 0) then quit (1,"Can't open...",file);  *  **********************************************************************  * HISTORY  * $Log: quit.c,v $  * Revision 1.1.1.1  1993/08/21  00:46:33  jkh  * Current sup with compression support.  *  * Revision 1.1.1.1  1993/05/21  14:52:17  cgd  * initial import of CMU's SUP to NetBSD  *  * Revision 1.2  88/12/13  13:52:41  gm0w  * 	Rewritten to use varargs.  * 	[88/12/13            gm0w]  *   **********************************************************************  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_macro
name|quit
argument_list|(
argument|status
argument_list|,
argument|fmt
argument_list|,
argument|va_alist
argument_list|)
end_macro

begin_decl_stmt
name|int
name|status
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_macro
name|va_dcl
end_macro

begin_block
block|{
name|va_list
name|args
decl_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|va_start
argument_list|(
name|args
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|fmt
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|status
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

