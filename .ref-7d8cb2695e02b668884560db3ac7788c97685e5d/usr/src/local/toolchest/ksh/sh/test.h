begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)test.h	1.1 */
end_comment

begin_comment
comment|/*  *	UNIX shell  *  *	David Korn  *	AT&T Bell Laboratories  *  */
end_comment

begin_comment
comment|/*  *  These are the valid test operators  */
end_comment

begin_define
define|#
directive|define
name|TEST_ARITH
value|0100
end_define

begin_comment
comment|/* arithmetic operators */
end_comment

begin_define
define|#
directive|define
name|TEST_BINOP
value|0200
end_define

begin_comment
comment|/* binary operator */
end_comment

begin_define
define|#
directive|define
name|TEST_SEQ
value|1
end_define

begin_define
define|#
directive|define
name|TEST_SNE
value|2
end_define

begin_define
define|#
directive|define
name|TEST_EQ
value|TEST_ARITH|3
end_define

begin_define
define|#
directive|define
name|TEST_NE
value|TEST_ARITH|4
end_define

begin_define
define|#
directive|define
name|TEST_GT
value|TEST_ARITH|5
end_define

begin_define
define|#
directive|define
name|TEST_GE
value|TEST_ARITH|6
end_define

begin_define
define|#
directive|define
name|TEST_LT
value|TEST_ARITH|7
end_define

begin_define
define|#
directive|define
name|TEST_LE
value|TEST_ARITH|8
end_define

begin_define
define|#
directive|define
name|TEST_EF
value|9
end_define

begin_define
define|#
directive|define
name|TEST_OT
value|10
end_define

begin_define
define|#
directive|define
name|TEST_NT
value|11
end_define

begin_define
define|#
directive|define
name|TEST_OR
value|TEST_BINOP|12
end_define

begin_define
define|#
directive|define
name|TEST_AND
value|TEST_BINOP|13
end_define

begin_decl_stmt
specifier|extern
name|MSG
name|btest
decl_stmt|;
end_decl_stmt

end_unit

