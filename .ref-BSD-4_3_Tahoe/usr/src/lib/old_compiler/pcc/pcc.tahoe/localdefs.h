begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	localdefs.h	1.1	86/02/02	*/
end_comment

begin_comment
comment|/*  * Definitions of symbols local to PCC.  *  * This file is not included directly by PCC sources -- instead it is  *	preprocessed along with<pcc.h> to yield two files, pcclocal.h  *	and pcctokens.  The preprocessing strips off the PCC_ prefix  *	from all the symbols, since the PCC has no potential clashes...  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCC_LOCALTOKENS
end_ifndef

begin_define
define|#
directive|define
name|PCC_LOCALTOKENS
value|100
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_PASS1_
end_ifdef

begin_comment
comment|/*  * Leftover operators.  */
end_comment

begin_define
define|#
directive|define
name|PCC_ASOP
value|100
end_define

begin_comment
comment|/* assignment ops */
end_comment

begin_define
define|#
directive|define
name|PCC_RELOP
value|101
end_define

begin_comment
comment|/*<=,<,>=,> */
end_comment

begin_define
define|#
directive|define
name|PCC_EQUOP
value|102
end_define

begin_comment
comment|/* ==, != */
end_comment

begin_define
define|#
directive|define
name|PCC_DIVOP
value|103
end_define

begin_comment
comment|/* /, % */
end_comment

begin_define
define|#
directive|define
name|PCC_SHIFTOP
value|104
end_define

begin_comment
comment|/*<<,>> */
end_comment

begin_define
define|#
directive|define
name|PCC_INCOP
value|105
end_define

begin_comment
comment|/* ++, -- */
end_comment

begin_define
define|#
directive|define
name|PCC_UNOP
value|106
end_define

begin_comment
comment|/* !, ~ */
end_comment

begin_define
define|#
directive|define
name|PCC_STROP
value|107
end_define

begin_comment
comment|/* ., -> */
end_comment

begin_define
define|#
directive|define
name|PCC_LP
value|108
end_define

begin_comment
comment|/* ( */
end_comment

begin_define
define|#
directive|define
name|PCC_RP
value|109
end_define

begin_comment
comment|/* ) */
end_comment

begin_define
define|#
directive|define
name|PCC_LC
value|110
end_define

begin_comment
comment|/* { */
end_comment

begin_define
define|#
directive|define
name|PCC_RC
value|111
end_define

begin_comment
comment|/* } */
end_comment

begin_endif
endif|#
directive|endif
endif|_PASS1_
end_endif

begin_comment
comment|/*  * C keywords.  */
end_comment

begin_define
define|#
directive|define
name|PCC_STRUCT
value|112
end_define

begin_define
define|#
directive|define
name|PCC_IF
value|113
end_define

begin_define
define|#
directive|define
name|PCC_ELSE
value|114
end_define

begin_define
define|#
directive|define
name|PCC_SWITCH
value|115
end_define

begin_define
define|#
directive|define
name|PCC_BREAK
value|116
end_define

begin_define
define|#
directive|define
name|PCC_CONTINUE
value|117
end_define

begin_define
define|#
directive|define
name|PCC_WHILE
value|118
end_define

begin_define
define|#
directive|define
name|PCC_DO
value|119
end_define

begin_define
define|#
directive|define
name|PCC_FOR
value|120
end_define

begin_define
define|#
directive|define
name|PCC_DEFAULT
value|121
end_define

begin_define
define|#
directive|define
name|PCC_CASE
value|122
end_define

begin_define
define|#
directive|define
name|PCC_SIZEOF
value|123
end_define

begin_define
define|#
directive|define
name|PCC_ENUM
value|124
end_define

begin_define
define|#
directive|define
name|PCC_SM
value|125
end_define

begin_endif
endif|#
directive|endif
endif|PCC_LOCALTOKENS
end_endif

end_unit

