begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)pxinfo.h	5.1 (Berkeley) 6/6/85  */
end_comment

begin_comment
comment|/*  * This is the information we get after the initial trap that px does.  * By passing the "-d" flag, we cause px to call a procedure with the  * the following information:  *  *	address of the display  *	address of the display pointer  *	address of the beginning of the object code  *  *	the address of a variable containing the address of the first local  *		variable in the interpreter procedure  *		(this is used to find the frame where the pc is)  *	the address of the main interpreter loop  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|nargs
decl_stmt|;
name|ADDRESS
modifier|*
name|disp
decl_stmt|;
name|ADDRESS
modifier|*
name|dp
decl_stmt|;
name|ADDRESS
name|objstart
decl_stmt|;
name|ADDRESS
name|pcaddrp
decl_stmt|;
name|ADDRESS
name|loopaddr
decl_stmt|;
block|}
name|TRAPARGS
typedef|;
end_typedef

begin_decl_stmt
name|ADDRESS
modifier|*
name|DISPLAY
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ADDRESS
modifier|*
name|DP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ADDRESS
name|ENDOFF
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ADDRESS
name|PCADDRP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ADDRESS
name|LOOPADDR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ADDRESS
modifier|*
name|pcframe
decl_stmt|;
end_decl_stmt

end_unit

