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
name|syl
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|parenlvl
decl_stmt|,
name|revloc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|pc
decl_stmt|;
end_decl_stmt

end_unit

