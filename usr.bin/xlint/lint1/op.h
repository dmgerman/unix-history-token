begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: op.h,v 1.2 1995/07/03 21:24:27 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Jochen Pohl  * All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Jochen Pohl for  *	The NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Various information about operators  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|m_binary
range|:
literal|1
decl_stmt|;
comment|/* binary op. */
name|u_int
name|m_logop
range|:
literal|1
decl_stmt|;
comment|/* logical op., result is int */
name|u_int
name|m_rqint
range|:
literal|1
decl_stmt|;
comment|/* operands must have integer type */
name|u_int
name|m_rqsclt
range|:
literal|1
decl_stmt|;
comment|/* operands must have scalar type */
name|u_int
name|m_rqatyp
range|:
literal|1
decl_stmt|;
comment|/* operands must have arithmetic type */
name|u_int
name|m_fold
range|:
literal|1
decl_stmt|;
comment|/* operands should be folded */
name|u_int
name|m_vctx
range|:
literal|1
decl_stmt|;
comment|/* value context for left operand */
name|u_int
name|m_tctx
range|:
literal|1
decl_stmt|;
comment|/* test context for left operand */
name|u_int
name|m_balance
range|:
literal|1
decl_stmt|;
comment|/* op. requires balancing */
name|u_int
name|m_sideeff
range|:
literal|1
decl_stmt|;
comment|/* op. has side effect */
name|u_int
name|m_tlansiu
range|:
literal|1
decl_stmt|;
comment|/* warning if left op. is unsign. in ANSI C */
name|u_int
name|m_transiu
range|:
literal|1
decl_stmt|;
comment|/* warning if right op. is unsign. in ANSI C */
name|u_int
name|m_tpconf
range|:
literal|1
decl_stmt|;
comment|/* test possible precedence confusion */
name|u_int
name|m_comp
range|:
literal|1
decl_stmt|;
comment|/* op. performs comparison */
name|u_int
name|m_enumop
range|:
literal|1
decl_stmt|;
comment|/* valid operation on enums */
name|u_int
name|m_badeop
range|:
literal|1
decl_stmt|;
comment|/* dubious operation on enums */
name|u_int
name|m_eqwarn
range|:
literal|1
decl_stmt|;
comment|/* warning if on operand stems from == */
specifier|const
name|char
modifier|*
name|m_name
decl_stmt|;
comment|/* name of op. */
block|}
name|mod_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|NOOP
init|=
literal|0
block|,
name|ARROW
block|,
name|POINT
block|,
name|NOT
block|,
name|COMPL
block|,
name|INC
block|,
name|DEC
block|,
name|INCBEF
block|,
name|DECBEF
block|,
name|INCAFT
block|,
name|DECAFT
block|,
name|UPLUS
block|,
name|UMINUS
block|,
name|STAR
block|,
name|AMPER
block|,
name|MULT
block|,
name|DIV
block|,
name|MOD
block|,
name|PLUS
block|,
name|MINUS
block|,
name|SHL
block|,
name|SHR
block|,
name|LT
block|,
name|LE
block|,
name|GT
block|,
name|GE
block|,
name|EQ
block|,
name|NE
block|,
name|AND
block|,
name|XOR
block|,
name|OR
block|,
name|LOGAND
block|,
name|LOGOR
block|,
name|QUEST
block|,
name|COLON
block|,
name|ASSIGN
block|,
name|MULASS
block|,
name|DIVASS
block|,
name|MODASS
block|,
name|ADDASS
block|,
name|SUBASS
block|,
name|SHLASS
block|,
name|SHRASS
block|,
name|ANDASS
block|,
name|XORASS
block|,
name|ORASS
block|,
name|NAME
block|,
name|CON
block|,
name|STRING
block|,
name|FSEL
block|,
name|CALL
block|,
name|COMMA
block|,
name|CVT
block|,
name|ICALL
block|,
name|LOAD
block|,
name|PUSH
block|,
name|RETURN
block|,
name|INIT
block|,
comment|/* pseudo op, not used in trees */
name|CASE
block|,
comment|/* pseudo op, not used in trees */
name|FARG
comment|/* pseudo op, not used in trees */
define|#
directive|define
name|NOPS
value|((int)FARG + 1)
block|}
name|op_t
typedef|;
end_typedef

end_unit

