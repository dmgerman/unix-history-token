begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/* $Header: syms.h,v 1.1 85/08/22 15:44:34 timo Exp $ */
end_comment

begin_comment
comment|/*  * B editor -- Grammar symbol definitions.  */
end_comment

begin_comment
comment|/*  * Values returned by function symbol(n).  * They are used directly as index in the grammar table.  * The NAMES of the #defined constants are of no importance outside this file.  */
end_comment

begin_define
define|#
directive|define
name|Put
value|1
end_define

begin_define
define|#
directive|define
name|Insert
value|2
end_define

begin_define
define|#
directive|define
name|Remove
value|3
end_define

begin_define
define|#
directive|define
name|Choose
value|4
end_define

begin_define
define|#
directive|define
name|Draw
value|5
end_define

begin_define
define|#
directive|define
name|Set_random
value|6
end_define

begin_define
define|#
directive|define
name|Delete
value|7
end_define

begin_define
define|#
directive|define
name|Check
value|8
end_define

begin_define
define|#
directive|define
name|Share
value|9
end_define

begin_define
define|#
directive|define
name|Write
value|10
end_define

begin_define
define|#
directive|define
name|Read
value|11
end_define

begin_define
define|#
directive|define
name|Read_raw
value|12
end_define

begin_define
define|#
directive|define
name|If
value|13
end_define

begin_define
define|#
directive|define
name|While
value|14
end_define

begin_define
define|#
directive|define
name|For
value|15
end_define

begin_define
define|#
directive|define
name|Select
value|16
end_define

begin_define
define|#
directive|define
name|Quit
value|18
end_define

begin_define
define|#
directive|define
name|Return
value|19
end_define

begin_define
define|#
directive|define
name|Report
value|20
end_define

begin_define
define|#
directive|define
name|Succeed
value|21
end_define

begin_define
define|#
directive|define
name|Fail
value|22
end_define

begin_define
define|#
directive|define
name|How_to
value|23
end_define

begin_define
define|#
directive|define
name|Yield
value|24
end_define

begin_define
define|#
directive|define
name|Test
value|25
end_define

begin_define
define|#
directive|define
name|Suite
value|26
end_define

begin_define
define|#
directive|define
name|Refinement
value|27
end_define

begin_define
define|#
directive|define
name|Compound
value|28
end_define

begin_define
define|#
directive|define
name|Collateral
value|29
end_define

begin_define
define|#
directive|define
name|Tag
value|30
end_define

begin_define
define|#
directive|define
name|Number
value|31
end_define

begin_define
define|#
directive|define
name|Selection
value|32
end_define

begin_define
define|#
directive|define
name|Behead
value|33
end_define

begin_define
define|#
directive|define
name|Curtail
value|34
end_define

begin_define
define|#
directive|define
name|And
value|35
end_define

begin_define
define|#
directive|define
name|Or
value|36
end_define

begin_define
define|#
directive|define
name|Not
value|37
end_define

begin_define
define|#
directive|define
name|Some_in
value|38
end_define

begin_define
define|#
directive|define
name|Each_in
value|39
end_define

begin_define
define|#
directive|define
name|No_in
value|40
end_define

begin_define
define|#
directive|define
name|Some_parsing
value|41
end_define

begin_define
define|#
directive|define
name|Each_parsing
value|42
end_define

begin_define
define|#
directive|define
name|No_parsing
value|43
end_define

begin_define
define|#
directive|define
name|Comment
value|44
end_define

begin_define
define|#
directive|define
name|Keyword
value|45
end_define

begin_define
define|#
directive|define
name|L_t_dis
value|46
end_define

begin_define
define|#
directive|define
name|List_body
value|47
end_define

begin_define
define|#
directive|define
name|Tab_body
value|48
end_define

begin_define
define|#
directive|define
name|Tab_entry
value|49
end_define

begin_define
define|#
directive|define
name|E_number
value|50
end_define

begin_define
define|#
directive|define
name|Com_target
value|51
end_define

begin_define
define|#
directive|define
name|Col_target
value|52
end_define

begin_define
define|#
directive|define
name|Sel_expr
value|53
end_define

begin_define
define|#
directive|define
name|Text1
value|54
end_define

begin_define
define|#
directive|define
name|Text2
value|55
end_define

begin_define
define|#
directive|define
name|Grouped
value|56
end_define

begin_define
define|#
directive|define
name|Blocked
value|57
end_define

begin_define
define|#
directive|define
name|Operators
value|58
end_define

begin_define
define|#
directive|define
name|Else_kw
value|59
end_define

begin_define
define|#
directive|define
name|Kw_plus
value|60
end_define

begin_define
define|#
directive|define
name|E_plus
value|61
end_define

begin_define
define|#
directive|define
name|Conversion
value|62
end_define

begin_define
define|#
directive|define
name|T1
value|63
end_define

begin_define
define|#
directive|define
name|T1_plus
value|64
end_define

begin_define
define|#
directive|define
name|T2
value|65
end_define

begin_define
define|#
directive|define
name|T2_plus
value|66
end_define

begin_define
define|#
directive|define
name|Cmt_cmd
value|67
end_define

begin_define
define|#
directive|define
name|F_kw_plus
value|69
end_define

begin_define
define|#
directive|define
name|F_e_plus
value|70
end_define

begin_define
define|#
directive|define
name|Plus_sign
value|71
end_define

begin_define
define|#
directive|define
name|Minus_sign
value|72
end_define

begin_define
define|#
directive|define
name|Long_comp
value|73
end_define

begin_define
define|#
directive|define
name|Short_comp
value|74
end_define

begin_define
define|#
directive|define
name|Cmt_comp
value|75
end_define

begin_define
define|#
directive|define
name|Long_unit
value|76
end_define

begin_define
define|#
directive|define
name|Short_unit
value|77
end_define

begin_define
define|#
directive|define
name|Cmt_head
value|78
end_define

begin_define
define|#
directive|define
name|Ref_join
value|79
end_define

begin_define
define|#
directive|define
name|And_kw
value|80
end_define

begin_define
define|#
directive|define
name|Or_kw
value|81
end_define

begin_define
define|#
directive|define
name|E_part
value|82
end_define

begin_define
define|#
directive|define
name|Unit_edit
value|83
end_define

begin_define
define|#
directive|define
name|Target_edit
value|84
end_define

begin_define
define|#
directive|define
name|Imm_cmd
value|85
end_define

begin_define
define|#
directive|define
name|Raw
value|86
end_define

begin_define
define|#
directive|define
name|Raw_input
value|87
end_define

begin_define
define|#
directive|define
name|Edit_unit
value|88
end_define

begin_define
define|#
directive|define
name|Edit_target
value|89
end_define

begin_define
define|#
directive|define
name|Colon
value|90
end_define

begin_define
define|#
directive|define
name|Equals
value|91
end_define

begin_define
define|#
directive|define
name|Test_suite
value|92
end_define

begin_define
define|#
directive|define
name|Expression
value|93
end_define

begin_comment
comment|/*  * The last three, `Suggestion', `Optional' and `Hole',  * with values 97, 98 and 99, are defined in "gram.h".  */
end_comment

end_unit

