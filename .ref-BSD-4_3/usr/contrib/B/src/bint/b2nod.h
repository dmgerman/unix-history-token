begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b2nod.h,v 1.4 85/08/22 16:42:43 timo Exp $ */
end_comment

begin_comment
comment|/* Units */
end_comment

begin_typedef
typedef|typedef
name|intlet
name|typenode
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_Nodetype
parameter_list|(
name|len
parameter_list|)
value|((len)& 0377)
end_define

begin_define
define|#
directive|define
name|_Nbranches
parameter_list|(
name|len
parameter_list|)
value|((len)>> 8)
end_define

begin_define
define|#
directive|define
name|Nodetype
parameter_list|(
name|v
parameter_list|)
value|_Nodetype((v)->len)
end_define

begin_define
define|#
directive|define
name|Nbranches
parameter_list|(
name|v
parameter_list|)
value|_Nbranches((v)->len)
end_define

begin_define
define|#
directive|define
name|Branch
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|((Ats(v)+(n)))
end_define

begin_define
define|#
directive|define
name|Unit
parameter_list|(
name|n
parameter_list|)
value|(n>=HOW_TO&& n<=REFINEMENT)
end_define

begin_define
define|#
directive|define
name|Command
parameter_list|(
name|n
parameter_list|)
value|(n>=SUITE&& n<=EXTENDED_COMMAND)
end_define

begin_define
define|#
directive|define
name|Expression
parameter_list|(
name|n
parameter_list|)
value|((n>=TAG&& n<=TAB_DIS)||(n>=TAGformal&& n<=TAGzerprd))
end_define

begin_define
define|#
directive|define
name|Comparison
parameter_list|(
name|n
parameter_list|)
value|(n>=LESS_THAN&& n<=UNEQUAL)
end_define

begin_define
define|#
directive|define
name|HOW_TO
value|0
end_define

begin_define
define|#
directive|define
name|YIELD
value|1
end_define

begin_define
define|#
directive|define
name|TEST
value|2
end_define

begin_define
define|#
directive|define
name|REFINEMENT
value|3
end_define

begin_comment
comment|/* Commands */
end_comment

begin_define
define|#
directive|define
name|SUITE
value|4
end_define

begin_define
define|#
directive|define
name|PUT
value|5
end_define

begin_define
define|#
directive|define
name|INSERT
value|6
end_define

begin_define
define|#
directive|define
name|REMOVE
value|7
end_define

begin_define
define|#
directive|define
name|CHOOSE
value|8
end_define

begin_define
define|#
directive|define
name|DRAW
value|9
end_define

begin_define
define|#
directive|define
name|SET_RANDOM
value|10
end_define

begin_define
define|#
directive|define
name|DELETE
value|11
end_define

begin_define
define|#
directive|define
name|CHECK
value|12
end_define

begin_define
define|#
directive|define
name|SHARE
value|13
end_define

begin_define
define|#
directive|define
name|WRITE
value|14
end_define

begin_define
define|#
directive|define
name|READ
value|15
end_define

begin_define
define|#
directive|define
name|READ_RAW
value|16
end_define

begin_define
define|#
directive|define
name|IF
value|17
end_define

begin_define
define|#
directive|define
name|WHILE
value|18
end_define

begin_define
define|#
directive|define
name|FOR
value|19
end_define

begin_define
define|#
directive|define
name|SELECT
value|20
end_define

begin_define
define|#
directive|define
name|TEST_SUITE
value|21
end_define

begin_define
define|#
directive|define
name|ELSE
value|22
end_define

begin_define
define|#
directive|define
name|QUIT
value|23
end_define

begin_define
define|#
directive|define
name|RETURN
value|24
end_define

begin_define
define|#
directive|define
name|REPORT
value|25
end_define

begin_define
define|#
directive|define
name|SUCCEED
value|26
end_define

begin_define
define|#
directive|define
name|FAIL
value|27
end_define

begin_define
define|#
directive|define
name|USER_COMMAND
value|28
end_define

begin_define
define|#
directive|define
name|EXTENDED_COMMAND
value|29
end_define

begin_comment
comment|/* Expressions, targets, tests */
end_comment

begin_define
define|#
directive|define
name|TAG
value|30
end_define

begin_define
define|#
directive|define
name|COMPOUND
value|31
end_define

begin_comment
comment|/* Expressions, targets */
end_comment

begin_define
define|#
directive|define
name|COLLATERAL
value|32
end_define

begin_define
define|#
directive|define
name|SELECTION
value|33
end_define

begin_define
define|#
directive|define
name|BEHEAD
value|34
end_define

begin_define
define|#
directive|define
name|CURTAIL
value|35
end_define

begin_comment
comment|/* Expressions, tests */
end_comment

begin_define
define|#
directive|define
name|UNPARSED
value|36
end_define

begin_comment
comment|/* Expressions */
end_comment

begin_define
define|#
directive|define
name|MONF
value|37
end_define

begin_define
define|#
directive|define
name|DYAF
value|38
end_define

begin_define
define|#
directive|define
name|NUMBER
value|39
end_define

begin_define
define|#
directive|define
name|TEXT_DIS
value|40
end_define

begin_define
define|#
directive|define
name|TEXT_LIT
value|41
end_define

begin_define
define|#
directive|define
name|TEXT_CONV
value|42
end_define

begin_define
define|#
directive|define
name|ELT_DIS
value|43
end_define

begin_define
define|#
directive|define
name|LIST_DIS
value|44
end_define

begin_define
define|#
directive|define
name|RANGE_DIS
value|45
end_define

begin_define
define|#
directive|define
name|TAB_DIS
value|46
end_define

begin_comment
comment|/* Tests */
end_comment

begin_define
define|#
directive|define
name|AND
value|47
end_define

begin_define
define|#
directive|define
name|OR
value|48
end_define

begin_define
define|#
directive|define
name|NOT
value|49
end_define

begin_define
define|#
directive|define
name|SOME_IN
value|50
end_define

begin_define
define|#
directive|define
name|EACH_IN
value|51
end_define

begin_define
define|#
directive|define
name|NO_IN
value|52
end_define

begin_define
define|#
directive|define
name|SOME_PARSING
value|53
end_define

begin_define
define|#
directive|define
name|EACH_PARSING
value|54
end_define

begin_define
define|#
directive|define
name|NO_PARSING
value|55
end_define

begin_define
define|#
directive|define
name|MONPRD
value|56
end_define

begin_define
define|#
directive|define
name|DYAPRD
value|57
end_define

begin_define
define|#
directive|define
name|LESS_THAN
value|58
end_define

begin_define
define|#
directive|define
name|AT_MOST
value|59
end_define

begin_define
define|#
directive|define
name|GREATER_THAN
value|60
end_define

begin_define
define|#
directive|define
name|AT_LEAST
value|61
end_define

begin_define
define|#
directive|define
name|EQUAL
value|62
end_define

begin_define
define|#
directive|define
name|UNEQUAL
value|63
end_define

begin_define
define|#
directive|define
name|Nonode
value|64
end_define

begin_define
define|#
directive|define
name|TAGformal
value|65
end_define

begin_define
define|#
directive|define
name|TAGlocal
value|66
end_define

begin_define
define|#
directive|define
name|TAGglobal
value|67
end_define

begin_define
define|#
directive|define
name|TAGmystery
value|68
end_define

begin_define
define|#
directive|define
name|TAGrefinement
value|69
end_define

begin_define
define|#
directive|define
name|TAGzerfun
value|70
end_define

begin_define
define|#
directive|define
name|TAGzerprd
value|71
end_define

begin_define
define|#
directive|define
name|ACTUAL
value|72
end_define

begin_define
define|#
directive|define
name|FORMAL
value|73
end_define

begin_function_decl
name|value
name|node1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|node2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|node3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|node4
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|node5
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|node6
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|node8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|node9
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|typenode
name|nodetype
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure display(); */
end_comment

begin_comment
comment|/* Procedure fix_nodes(); */
end_comment

begin_define
define|#
directive|define
name|First_fieldnr
value|0
end_define

begin_define
define|#
directive|define
name|UNIT_NAME
value|First_fieldnr
end_define

begin_define
define|#
directive|define
name|HOW_FORMALS
value|First_fieldnr + 1
end_define

begin_comment
comment|/* HOW'TO */
end_comment

begin_define
define|#
directive|define
name|HOW_COMMENT
value|First_fieldnr + 2
end_define

begin_define
define|#
directive|define
name|HOW_SUITE
value|First_fieldnr + 3
end_define

begin_define
define|#
directive|define
name|HOW_REFINEMENT
value|First_fieldnr + 4
end_define

begin_define
define|#
directive|define
name|HOW_R_NAMES
value|First_fieldnr + 5
end_define

begin_define
define|#
directive|define
name|HOW_NLOCALS
value|First_fieldnr + 6
end_define

begin_define
define|#
directive|define
name|FPR_ADICITY
value|First_fieldnr + 1
end_define

begin_comment
comment|/* YIELD, TEST */
end_comment

begin_define
define|#
directive|define
name|FPR_FORMALS
value|First_fieldnr + 2
end_define

begin_define
define|#
directive|define
name|FPR_COMMENT
value|First_fieldnr + 3
end_define

begin_define
define|#
directive|define
name|FPR_SUITE
value|First_fieldnr + 4
end_define

begin_define
define|#
directive|define
name|FPR_REFINEMENT
value|First_fieldnr + 5
end_define

begin_define
define|#
directive|define
name|FPR_R_NAMES
value|First_fieldnr + 6
end_define

begin_define
define|#
directive|define
name|FPR_NLOCALS
value|First_fieldnr + 7
end_define

begin_define
define|#
directive|define
name|FML_KEYW
value|First_fieldnr
end_define

begin_comment
comment|/* FORMALS HOW'TO */
end_comment

begin_define
define|#
directive|define
name|FML_TAG
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|FML_NEXT
value|First_fieldnr + 2
end_define

begin_define
define|#
directive|define
name|SUI_LINO
value|First_fieldnr
end_define

begin_comment
comment|/* SUITE */
end_comment

begin_define
define|#
directive|define
name|SUI_CMD
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|SUI_COMMENT
value|First_fieldnr + 2
end_define

begin_define
define|#
directive|define
name|SUI_NEXT
value|First_fieldnr + 3
end_define

begin_define
define|#
directive|define
name|REF_NAME
value|First_fieldnr
end_define

begin_comment
comment|/* REFINEMENT */
end_comment

begin_define
define|#
directive|define
name|REF_COMMENT
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|REF_SUITE
value|First_fieldnr + 2
end_define

begin_define
define|#
directive|define
name|REF_NEXT
value|First_fieldnr + 3
end_define

begin_define
define|#
directive|define
name|REF_START
value|First_fieldnr + 4
end_define

begin_define
define|#
directive|define
name|PUT_EXPR
value|First_fieldnr
end_define

begin_comment
comment|/* PUT */
end_comment

begin_define
define|#
directive|define
name|PUT_TARGET
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|INS_EXPR
value|First_fieldnr
end_define

begin_comment
comment|/* INSERT */
end_comment

begin_define
define|#
directive|define
name|INS_TARGET
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|RMV_EXPR
value|First_fieldnr
end_define

begin_comment
comment|/* REMOVE */
end_comment

begin_define
define|#
directive|define
name|RMV_TARGET
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|CHS_TARGET
value|First_fieldnr
end_define

begin_comment
comment|/* CHOOSE */
end_comment

begin_define
define|#
directive|define
name|CHS_EXPR
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|DRW_TARGET
value|First_fieldnr
end_define

begin_comment
comment|/* DRAW */
end_comment

begin_define
define|#
directive|define
name|SET_EXPR
value|First_fieldnr
end_define

begin_comment
comment|/* SET'RANDOM */
end_comment

begin_define
define|#
directive|define
name|DEL_TARGET
value|First_fieldnr
end_define

begin_comment
comment|/* DELETE */
end_comment

begin_define
define|#
directive|define
name|CHK_TEST
value|First_fieldnr
end_define

begin_comment
comment|/* CHECK */
end_comment

begin_define
define|#
directive|define
name|SHR_TARGET
value|First_fieldnr
end_define

begin_comment
comment|/* SHARE */
end_comment

begin_define
define|#
directive|define
name|WRT_L_LINES
value|First_fieldnr
end_define

begin_comment
comment|/* WRITE */
end_comment

begin_define
define|#
directive|define
name|WRT_EXPR
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|WRT_R_LINES
value|First_fieldnr + 2
end_define

begin_define
define|#
directive|define
name|RD_TARGET
value|First_fieldnr
end_define

begin_comment
comment|/* READ */
end_comment

begin_define
define|#
directive|define
name|RD_EXPR
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|RDW_TARGET
value|First_fieldnr
end_define

begin_comment
comment|/* READ'RAW */
end_comment

begin_define
define|#
directive|define
name|IF_TEST
value|First_fieldnr
end_define

begin_comment
comment|/* IF */
end_comment

begin_define
define|#
directive|define
name|IF_COMMENT
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|IF_SUITE
value|First_fieldnr + 2
end_define

begin_define
define|#
directive|define
name|WHL_TEST
value|First_fieldnr
end_define

begin_comment
comment|/* WHILE */
end_comment

begin_define
define|#
directive|define
name|WHL_COMMENT
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|WHL_SUITE
value|First_fieldnr + 2
end_define

begin_define
define|#
directive|define
name|FOR_TARGET
value|First_fieldnr
end_define

begin_comment
comment|/* FOR */
end_comment

begin_define
define|#
directive|define
name|FOR_EXPR
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|FOR_COMMENT
value|First_fieldnr + 2
end_define

begin_define
define|#
directive|define
name|FOR_SUITE
value|First_fieldnr + 3
end_define

begin_define
define|#
directive|define
name|SLT_COMMENT
value|First_fieldnr
end_define

begin_comment
comment|/* SELECT */
end_comment

begin_define
define|#
directive|define
name|SLT_TSUITE
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|TSUI_LINO
value|First_fieldnr
end_define

begin_comment
comment|/* TEST SUITE */
end_comment

begin_define
define|#
directive|define
name|TSUI_TEST
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|TSUI_COMMENT
value|First_fieldnr + 2
end_define

begin_define
define|#
directive|define
name|TSUI_SUITE
value|First_fieldnr + 3
end_define

begin_define
define|#
directive|define
name|TSUI_NEXT
value|First_fieldnr + 4
end_define

begin_define
define|#
directive|define
name|ELSE_LINO
value|First_fieldnr
end_define

begin_comment
comment|/* ELSE */
end_comment

begin_define
define|#
directive|define
name|ELSE_COMMENT
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|ELSE_SUITE
value|First_fieldnr + 2
end_define

begin_define
define|#
directive|define
name|RTN_EXPR
value|First_fieldnr
end_define

begin_comment
comment|/* RETURN */
end_comment

begin_define
define|#
directive|define
name|RPT_TEST
value|First_fieldnr
end_define

begin_comment
comment|/* REPORT */
end_comment

begin_define
define|#
directive|define
name|UCMD_NAME
value|First_fieldnr
end_define

begin_comment
comment|/* USER COMMAND */
end_comment

begin_define
define|#
directive|define
name|UCMD_ACTUALS
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|UCMD_DEF
value|First_fieldnr + 2
end_define

begin_define
define|#
directive|define
name|ACT_KEYW
value|First_fieldnr
end_define

begin_comment
comment|/* ACTUALS USER COMMAND */
end_comment

begin_define
define|#
directive|define
name|ACT_EXPR
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|ACT_NEXT
value|First_fieldnr + 2
end_define

begin_define
define|#
directive|define
name|ACT_START
value|First_fieldnr + 3
end_define

begin_define
define|#
directive|define
name|ECMD_NAME
value|First_fieldnr
end_define

begin_comment
comment|/* EXTENDED COMMAND */
end_comment

begin_define
define|#
directive|define
name|ECMD_ACTUALS
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|COMP_FIELD
value|First_fieldnr
end_define

begin_comment
comment|/* COMPOUND */
end_comment

begin_define
define|#
directive|define
name|COLL_SEQ
value|First_fieldnr
end_define

begin_comment
comment|/* COLLATERAL */
end_comment

begin_define
define|#
directive|define
name|MON_NAME
value|First_fieldnr
end_define

begin_comment
comment|/* MONADIC FUNCTION */
end_comment

begin_define
define|#
directive|define
name|MON_RIGHT
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|MON_FCT
value|First_fieldnr + 2
end_define

begin_define
define|#
directive|define
name|DYA_NAME
value|First_fieldnr + 1
end_define

begin_comment
comment|/* DYADIC FUNCTION */
end_comment

begin_define
define|#
directive|define
name|DYA_LEFT
value|First_fieldnr
end_define

begin_define
define|#
directive|define
name|DYA_RIGHT
value|First_fieldnr + 2
end_define

begin_define
define|#
directive|define
name|DYA_FCT
value|First_fieldnr + 3
end_define

begin_define
define|#
directive|define
name|TAG_NAME
value|First_fieldnr
end_define

begin_comment
comment|/* TAG */
end_comment

begin_define
define|#
directive|define
name|TAG_ID
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|NUM_VALUE
value|First_fieldnr
end_define

begin_comment
comment|/* NUMBER */
end_comment

begin_define
define|#
directive|define
name|NUM_TEXT
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|XDIS_QUOTE
value|First_fieldnr
end_define

begin_comment
comment|/* TEXT DIS */
end_comment

begin_define
define|#
directive|define
name|XDIS_NEXT
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|XLIT_TEXT
value|First_fieldnr
end_define

begin_comment
comment|/* TEXT LIT */
end_comment

begin_define
define|#
directive|define
name|XLIT_NEXT
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|XCON_EXPR
value|First_fieldnr
end_define

begin_comment
comment|/* TEXT CONV */
end_comment

begin_define
define|#
directive|define
name|XCON_NEXT
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|LDIS_SEQ
value|First_fieldnr
end_define

begin_comment
comment|/* LIST DIS */
end_comment

begin_define
define|#
directive|define
name|RDIS_LWB
value|First_fieldnr
end_define

begin_comment
comment|/* RANGE DIS */
end_comment

begin_define
define|#
directive|define
name|RDIS_UPB
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|TDIS_SEQ
value|First_fieldnr
end_define

begin_comment
comment|/* TAB_DIS */
end_comment

begin_define
define|#
directive|define
name|SEL_TABLE
value|First_fieldnr
end_define

begin_comment
comment|/* SELECTION */
end_comment

begin_define
define|#
directive|define
name|SEL_KEY
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|TRIM_LEFT
value|First_fieldnr
end_define

begin_comment
comment|/* BEHEAD, CURTAIL */
end_comment

begin_define
define|#
directive|define
name|TRIM_RIGHT
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|UNP_SEQ
value|First_fieldnr
end_define

begin_comment
comment|/* UNPARSED */
end_comment

begin_define
define|#
directive|define
name|UNP_TEXT
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|AND_LEFT
value|First_fieldnr
end_define

begin_comment
comment|/* AND */
end_comment

begin_define
define|#
directive|define
name|AND_RIGHT
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|OR_LEFT
value|First_fieldnr
end_define

begin_comment
comment|/* OR */
end_comment

begin_define
define|#
directive|define
name|OR_RIGHT
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|NOT_RIGHT
value|First_fieldnr
end_define

begin_comment
comment|/* NOT */
end_comment

begin_define
define|#
directive|define
name|QUA_TARGET
value|First_fieldnr
end_define

begin_comment
comment|/* QUANTIFICATION */
end_comment

begin_define
define|#
directive|define
name|QUA_EXPR
value|First_fieldnr + 1
end_define

begin_define
define|#
directive|define
name|QUA_TEST
value|First_fieldnr + 2
end_define

begin_define
define|#
directive|define
name|REL_LEFT
value|First_fieldnr
end_define

begin_comment
comment|/* ORDER TEST */
end_comment

begin_define
define|#
directive|define
name|REL_RIGHT
value|First_fieldnr + 1
end_define

end_unit

