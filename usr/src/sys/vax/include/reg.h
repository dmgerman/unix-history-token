begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)reg.h	6.2 (Berkeley) %G%  */
end_comment

begin_expr_stmt
operator|*
name|Location
name|of
name|the
name|users
literal|'
end_expr_stmt

unit|stored  * registers relative to R0.  * Usage is u.u_ar0[XX].  */ #define	R0	(-18) #define	R1	(-17) #define	R2	(-16) #define	R3	(-15) #define	R4	(-14) #define	R5	(-13) #define	R6	(-12) #define	R7	(-11) #define	R8	(-10) #define	R9	(-9) #define	R10	(-8) #define	R11	(-7) #define	R12	(-21) #define	R13	(-20)  #define AP	(-21) #define	FP	(-20) #define	SP	(-5) #define	PS	(-1) #define	PC	(-2)
end_unit

