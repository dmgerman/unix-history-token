begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)pxinfo.h	5.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * This is the information we get after the initial trap that px does.  * By passing the "-d" flag, we cause px to call a procedure with the  * the following information:  *  *	address of the display  *	address of the display pointer  *	address of the beginning of the object code  *  *	the address of the program counter used in the interpreter procedure  *		(px actually keeps the pc in a register if it can, but stores  *		 it in this location each time around the interpreter loop.)  *	the address of the main interpreter loop (past the store of pc)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|trp_savemask
decl_stmt|;
name|short
name|trp_removed
decl_stmt|;
name|int
name|trp_oldfp
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
name|pcaddr
decl_stmt|;
name|ADDRESS
name|loopaddr
decl_stmt|;
block|}
name|TRAPARGS
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

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
name|pcaddr
decl_stmt|;
name|ADDRESS
name|loopaddr
decl_stmt|;
block|}
name|TRAPARGS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

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
name|PCADDR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ADDRESS
name|LOOPADDR
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_decl_stmt
name|ADDRESS
name|RETLOC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ADDRESS
name|INTFP
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

