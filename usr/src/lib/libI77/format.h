begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)format.h	5.1 (Berkeley) 6/7/85  */
end_comment

begin_comment
comment|/*  * format parser definitions  */
end_comment

begin_struct
struct|struct
name|syl
block|{
name|short
name|op
decl_stmt|,
name|p1
decl_stmt|,
name|p2
decl_stmt|,
name|rpcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*	do NOT change this defines or add new ones without  *	changing the value of the following define for OP_TYPE_TAB.  *	change format.h both in the compiler and libI77 simultaneously.  */
end_comment

begin_define
define|#
directive|define
name|RET
value|1
end_define

begin_define
define|#
directive|define
name|REVERT
value|2
end_define

begin_define
define|#
directive|define
name|GOTO
value|3
end_define

begin_define
define|#
directive|define
name|X
value|4
end_define

begin_define
define|#
directive|define
name|SLASH
value|5
end_define

begin_define
define|#
directive|define
name|STACK
value|6
end_define

begin_define
define|#
directive|define
name|I
value|7
end_define

begin_define
define|#
directive|define
name|ED
value|8
end_define

begin_define
define|#
directive|define
name|NED
value|9
end_define

begin_define
define|#
directive|define
name|IM
value|10
end_define

begin_define
define|#
directive|define
name|APOS
value|11
end_define

begin_define
define|#
directive|define
name|H
value|12
end_define

begin_define
define|#
directive|define
name|TL
value|13
end_define

begin_define
define|#
directive|define
name|TR
value|14
end_define

begin_define
define|#
directive|define
name|T
value|15
end_define

begin_define
define|#
directive|define
name|COLON
value|16
end_define

begin_define
define|#
directive|define
name|S
value|17
end_define

begin_define
define|#
directive|define
name|SP
value|18
end_define

begin_define
define|#
directive|define
name|SS
value|19
end_define

begin_define
define|#
directive|define
name|P
value|20
end_define

begin_define
define|#
directive|define
name|BNZ
value|21
end_define

begin_define
define|#
directive|define
name|B
value|22
end_define

begin_define
define|#
directive|define
name|F
value|23
end_define

begin_define
define|#
directive|define
name|E
value|24
end_define

begin_define
define|#
directive|define
name|EE
value|25
end_define

begin_define
define|#
directive|define
name|D
value|26
end_define

begin_define
define|#
directive|define
name|DE
value|27
end_define

begin_comment
comment|/*** NOT STANDARD FORTRAN ***/
end_comment

begin_define
define|#
directive|define
name|G
value|28
end_define

begin_define
define|#
directive|define
name|GE
value|29
end_define

begin_define
define|#
directive|define
name|L
value|30
end_define

begin_define
define|#
directive|define
name|A
value|31
end_define

begin_define
define|#
directive|define
name|AW
value|32
end_define

begin_define
define|#
directive|define
name|R
value|33
end_define

begin_comment
comment|/*** NOT STANDARD FORTRAN ***/
end_comment

begin_define
define|#
directive|define
name|DOLAR
value|34
end_define

begin_comment
comment|/*** NOT STANDARD FORTRAN ***/
end_comment

begin_define
define|#
directive|define
name|SU
value|35
end_define

begin_comment
comment|/*** NOT STANDARD FORTRAN ***/
end_comment

begin_define
define|#
directive|define
name|LAST_TERM
value|SU
end_define

begin_comment
comment|/* OP_TYPE_TAB is used in dofio.c . 	  Each value corresponds to a value above, and must be 	  ED for editing terms: I,IM,F,E,EE,D,DE,G,GE,L,A,AW 	  NED for nonediting terms which change the I/O stream: 			X,SLASH,APOS,H,TL,TR,T 	  and just the value of the term for all others.  	  E.g. SP is defined above as 17, so the element 17 of 	  OP_TYPE_TAB (counting from zero) is SP since SP does not 	  read or write data; 	  IM is defined as 10 so the element 10 of OP_TYPE_TAB 	  is ED since IM edits data from the i/o list.  */
end_comment

begin_define
define|#
directive|define
name|OP_TYPE_TAB
value|{0, RET, REVERT, GOTO, NED, NED, STACK, ED, ED, NED, \ 			ED, NED, NED, NED, NED, NED, COLON, S, SP, SS, P, \ 			BNZ, B, ED, ED, ED, ED, ED, ED, ED, ED, ED, ED, \ 			R, DOLAR, SU }
end_define

begin_define
define|#
directive|define
name|FMTUNKN
value|-1
end_define

begin_define
define|#
directive|define
name|FMTOK
value|1
end_define

begin_define
define|#
directive|define
name|FMTERR
value|0
end_define

begin_define
define|#
directive|define
name|FMT_COMP
value|0x101
end_define

begin_comment
comment|/* indicates pre-compiled formats */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|syl
modifier|*
name|syl_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|pc
decl_stmt|;
end_decl_stmt

end_unit

