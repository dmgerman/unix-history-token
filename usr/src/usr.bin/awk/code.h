begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** code.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* $Log:	code.h,v $  * Revision 5.1  91/12/05  07:59:07  brennan  * 1.1 pre-release  *  */
end_comment

begin_comment
comment|/*  code.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CODE_H
end_ifndef

begin_define
define|#
directive|define
name|CODE_H
end_define

begin_include
include|#
directive|include
file|"memory.h"
end_include

begin_comment
comment|/* coding scope */
end_comment

begin_define
define|#
directive|define
name|SCOPE_MAIN
value|0
end_define

begin_define
define|#
directive|define
name|SCOPE_BEGIN
value|1
end_define

begin_define
define|#
directive|define
name|SCOPE_END
value|2
end_define

begin_define
define|#
directive|define
name|SCOPE_FUNCT
value|3
end_define

begin_decl_stmt
specifier|extern
name|INST
modifier|*
name|code_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|INST
modifier|*
name|main_start
decl_stmt|,
modifier|*
name|main_code_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|main_size
decl_stmt|;
end_decl_stmt

begin_struct
specifier|extern
struct|struct
name|be_code
block|{
name|INST
modifier|*
name|start
decl_stmt|,
modifier|*
name|ptr
decl_stmt|;
name|unsigned
name|size
decl_stmt|;
block|}
name|begin_code
struct|,
name|end_code
struct|;
end_struct

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|be_shrink
argument_list|,
operator|(
expr|struct
name|be_code
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|be_expand
argument_list|,
operator|(
expr|struct
name|be_code
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|INST_BYTES
parameter_list|(
name|x
parameter_list|)
value|(sizeof(INST)*(x))
end_define

begin_decl_stmt
specifier|extern
name|CELL
name|eval_stack
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|code1
parameter_list|(
name|x
parameter_list|)
value|code_ptr++ -> op = (x)
end_define

begin_define
define|#
directive|define
name|code2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(void)( code_ptr++ -> op = (x) ,\                          code_ptr++ -> ptr = (PTR)(y) )
end_define

begin_decl_stmt
specifier|extern
name|int
name|exit_code
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  the machine opcodes  */
end_comment

begin_comment
comment|/* to avoid confusion with a ptr FE_PUSHA must have op code 0 */
end_comment

begin_comment
comment|/* unfortunately enums are less portable than defines */
end_comment

begin_define
define|#
directive|define
name|FE_PUSHA
value|0
end_define

begin_define
define|#
directive|define
name|FE_PUSHI
value|1
end_define

begin_define
define|#
directive|define
name|F_PUSHA
value|2
end_define

begin_define
define|#
directive|define
name|F_PUSHI
value|3
end_define

begin_define
define|#
directive|define
name|NF_PUSHI
value|4
end_define

begin_define
define|#
directive|define
name|_HALT
value|5
end_define

begin_define
define|#
directive|define
name|_STOP
value|6
end_define

begin_define
define|#
directive|define
name|_PUSHC
value|7
end_define

begin_define
define|#
directive|define
name|_PUSHD
value|8
end_define

begin_define
define|#
directive|define
name|_PUSHS
value|9
end_define

begin_define
define|#
directive|define
name|_PUSHINT
value|10
end_define

begin_define
define|#
directive|define
name|_PUSHA
value|11
end_define

begin_define
define|#
directive|define
name|_PUSHI
value|12
end_define

begin_define
define|#
directive|define
name|L_PUSHA
value|13
end_define

begin_define
define|#
directive|define
name|L_PUSHI
value|14
end_define

begin_define
define|#
directive|define
name|AE_PUSHA
value|15
end_define

begin_define
define|#
directive|define
name|AE_PUSHI
value|16
end_define

begin_define
define|#
directive|define
name|A_PUSHA
value|17
end_define

begin_define
define|#
directive|define
name|LAE_PUSHA
value|18
end_define

begin_define
define|#
directive|define
name|LAE_PUSHI
value|19
end_define

begin_define
define|#
directive|define
name|LA_PUSHA
value|20
end_define

begin_define
define|#
directive|define
name|_POP
value|21
end_define

begin_define
define|#
directive|define
name|_DUP
value|22
end_define

begin_define
define|#
directive|define
name|_ADD
value|23
end_define

begin_define
define|#
directive|define
name|_SUB
value|24
end_define

begin_define
define|#
directive|define
name|_MUL
value|25
end_define

begin_define
define|#
directive|define
name|_DIV
value|26
end_define

begin_define
define|#
directive|define
name|_MOD
value|27
end_define

begin_define
define|#
directive|define
name|_POW
value|28
end_define

begin_define
define|#
directive|define
name|_NOT
value|29
end_define

begin_define
define|#
directive|define
name|_TEST
value|30
end_define

begin_define
define|#
directive|define
name|A_TEST
value|31
end_define

begin_define
define|#
directive|define
name|A_DEL
value|32
end_define

begin_define
define|#
directive|define
name|ALOOP
value|33
end_define

begin_define
define|#
directive|define
name|A_CAT
value|34
end_define

begin_define
define|#
directive|define
name|_UMINUS
value|35
end_define

begin_define
define|#
directive|define
name|_UPLUS
value|36
end_define

begin_define
define|#
directive|define
name|_ASSIGN
value|37
end_define

begin_define
define|#
directive|define
name|_ADD_ASG
value|38
end_define

begin_define
define|#
directive|define
name|_SUB_ASG
value|39
end_define

begin_define
define|#
directive|define
name|_MUL_ASG
value|40
end_define

begin_define
define|#
directive|define
name|_DIV_ASG
value|41
end_define

begin_define
define|#
directive|define
name|_MOD_ASG
value|42
end_define

begin_define
define|#
directive|define
name|_POW_ASG
value|43
end_define

begin_define
define|#
directive|define
name|F_ASSIGN
value|44
end_define

begin_define
define|#
directive|define
name|F_ADD_ASG
value|45
end_define

begin_define
define|#
directive|define
name|F_SUB_ASG
value|46
end_define

begin_define
define|#
directive|define
name|F_MUL_ASG
value|47
end_define

begin_define
define|#
directive|define
name|F_DIV_ASG
value|48
end_define

begin_define
define|#
directive|define
name|F_MOD_ASG
value|49
end_define

begin_define
define|#
directive|define
name|F_POW_ASG
value|50
end_define

begin_define
define|#
directive|define
name|_CAT
value|51
end_define

begin_define
define|#
directive|define
name|_BUILTIN
value|52
end_define

begin_define
define|#
directive|define
name|_PRINT
value|53
end_define

begin_define
define|#
directive|define
name|_POST_INC
value|54
end_define

begin_define
define|#
directive|define
name|_POST_DEC
value|55
end_define

begin_define
define|#
directive|define
name|_PRE_INC
value|56
end_define

begin_define
define|#
directive|define
name|_PRE_DEC
value|57
end_define

begin_define
define|#
directive|define
name|F_POST_INC
value|58
end_define

begin_define
define|#
directive|define
name|F_POST_DEC
value|59
end_define

begin_define
define|#
directive|define
name|F_PRE_INC
value|60
end_define

begin_define
define|#
directive|define
name|F_PRE_DEC
value|61
end_define

begin_define
define|#
directive|define
name|_JMP
value|62
end_define

begin_define
define|#
directive|define
name|_JNZ
value|63
end_define

begin_define
define|#
directive|define
name|_JZ
value|64
end_define

begin_define
define|#
directive|define
name|_EQ
value|65
end_define

begin_define
define|#
directive|define
name|_NEQ
value|66
end_define

begin_define
define|#
directive|define
name|_LT
value|67
end_define

begin_define
define|#
directive|define
name|_LTE
value|68
end_define

begin_define
define|#
directive|define
name|_GT
value|69
end_define

begin_define
define|#
directive|define
name|_GTE
value|70
end_define

begin_define
define|#
directive|define
name|_MATCH0
value|71
end_define

begin_define
define|#
directive|define
name|_MATCH1
value|72
end_define

begin_define
define|#
directive|define
name|_MATCH2
value|73
end_define

begin_define
define|#
directive|define
name|_EXIT
value|74
end_define

begin_define
define|#
directive|define
name|_EXIT0
value|75
end_define

begin_define
define|#
directive|define
name|_NEXT
value|76
end_define

begin_define
define|#
directive|define
name|_RANGE
value|77
end_define

begin_define
define|#
directive|define
name|_CALL
value|78
end_define

begin_define
define|#
directive|define
name|_RET
value|79
end_define

begin_define
define|#
directive|define
name|_RET0
value|80
end_define

begin_define
define|#
directive|define
name|SET_ALOOP
value|81
end_define

begin_define
define|#
directive|define
name|OL_GL
value|82
end_define

begin_define
define|#
directive|define
name|OL_GL_NR
value|83
end_define

begin_define
define|#
directive|define
name|_OMAIN
value|84
end_define

begin_define
define|#
directive|define
name|_JMAIN
value|85
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CODE_H */
end_comment

end_unit

