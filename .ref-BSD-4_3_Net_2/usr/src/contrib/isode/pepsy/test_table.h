begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* test_table.h */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/pepsy/RCS/test_table.h,v 7.2 91/02/22 09:50:10 mrose Interim $  *  *  * $Log:	test_table.h,v $  * Revision 7.2  91/02/22  09:50:10  mrose  * Interim 6.8  *   * Revision 7.1  90/11/04  19:21:15  mrose  * update  *   * Revision 7.0  90/07/01  19:54:46  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/*  * This contains the information about each test case necessary to test it  * e.g. size, name  */
end_comment

begin_struct
struct|struct
name|tst_typ
block|{
name|char
modifier|*
name|tst_name
decl_stmt|;
comment|/* Name for error messages */
name|unsigned
name|int
name|tst_size
decl_stmt|;
comment|/* Size of its data structure in bytes */
name|int
name|tst_entry
decl_stmt|;
comment|/* entry for decoding/encoding */
name|int
name|tst_tests
decl_stmt|;
comment|/* How many values of the t_test variable 				 * to try it with 				 */
define|#
directive|define
name|NOENTRY
value|-1
block|}
name|t_case
index|[]
init|=
block|{
comment|/* MPDU */
block|{
literal|"MPDU"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_MPDU
argument_list|)
block|,
name|_ZMPDUT1
block|,
literal|1
block|, }
block|,
define|#
directive|define
name|TY_MPDU
value|0
block|{
literal|"Embedded"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_Embedded
argument_list|)
block|,
name|_ZEmbeddedT1
block|,
literal|1
block|, }
block|,
define|#
directive|define
name|TY_EMBEDDED
value|1
block|{
literal|"Strings"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_Strings
argument_list|)
block|,
name|_ZStringsT1
block|,
literal|1
block|, }
block|,
define|#
directive|define
name|TY_STRINGS
value|2
block|{
literal|"Embedded Strings"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_Emb__Strings
argument_list|)
block|,
name|_ZEmb_StringsT1
block|,
literal|1
block|, }
block|,
define|#
directive|define
name|TY_EMB_STRINGS
value|3
block|{
literal|"Implicit tags"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_Impl__Tags
argument_list|)
block|,
name|_ZImpl_TagsT1
block|,
literal|1
block|, }
block|,
define|#
directive|define
name|TY_IMPLICIT
value|4
block|{
literal|"Explicit tags"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_Expl__Tags
argument_list|)
block|,
name|_ZExpl_TagsT1
block|,
literal|1
block|, }
block|,
define|#
directive|define
name|TY_EXPLICIT
value|5
block|{
literal|"SEQ OF and SET OF"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_Seqof__Test
argument_list|)
block|,
name|_ZSeqof_TestT1
block|,
literal|10
block|, }
block|,
define|#
directive|define
name|TY_SEQOF
value|6
block|{
literal|"Seqof Test 1"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|element_T1_4
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_ELEMENT4
value|7
block|{
literal|"Set of Test 1"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|member_T1_2
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_MEMBER2
value|8
block|{
literal|"Seq of Test 2"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|element_T1_6
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_ELEMENT6
value|9
block|{
literal|"Seq of Sequence test"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|element_T1_8
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_ELEMENT8
value|10
block|{
literal|"Set of Test 2"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|member_T1_4
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_MEMBER4
value|11
block|{
literal|"Set of Sequence"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|element_T1_9
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_ELEMENT9
value|12
block|{
literal|"Choice"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_Choice__Test
argument_list|)
block|,
name|_ZChoice_TestT1
block|,
literal|7
block|, }
block|,
define|#
directive|define
name|TY_CHOICE
value|13
block|{
literal|"Choice test 0"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|choice_T1_0
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_CHOICE0
value|14
block|{
literal|"Choice test 1"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|choice_T1_1
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_CHOICE1
value|15
block|{
literal|"Choice test 2"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|choice_T1_2
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_CHOICE2
value|16
block|{
literal|"Element 10"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|element_T1_10
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_ELEMENT10
value|17
block|{
literal|"Member 6"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|member_T1_6
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_MEMBER6
value|18
block|{
literal|"Element 11"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|element_T1_11
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_ELEMENT11
value|19
block|{
literal|"Choice test 3"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|choice_T1_3
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_CHOICE3
value|20
block|{
literal|"Optional test"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_Opt__Strings
argument_list|)
block|,
name|_ZOpt_StringsT1
block|,
literal|8
block|, }
block|,
define|#
directive|define
name|TY_OPTIONAL
value|21
block|{
literal|"Element 12"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|element_T1_12
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_ELEMENT12
value|22
block|{
literal|"Member 7"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|member_T1_7
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_MEMBER7
value|23
block|{
literal|"Choice test 4"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|choice_T1_4
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_CHOICE4
value|24
block|{
literal|"Default test"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_Def__Strings
argument_list|)
block|,
name|_ZDef_StringsT1
block|,
literal|12
block|, }
block|,
define|#
directive|define
name|TY_DEFAULT
value|25
block|{
literal|"Element 13"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|element_T1_13
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_ELEMENT13
value|26
block|{
literal|"Member 8"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|member_T1_8
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_MEMBER8
value|27
block|{
literal|"External References"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_E__ref
argument_list|)
block|,
name|_ZE_refT1
block|,
literal|6
block|,}
block|,
define|#
directive|define
name|TY_EXTREF
value|28
block|{
literal|"T2 Info"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T2_Info
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_T2_INFO
value|29
block|{
literal|"T2 MPDU"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T2_MPDU
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_T2_MPDU
value|30
block|{
literal|"T2 ELEMENT 0"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|element_T2_0
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_T2_ELEM0
value|31
block|{
literal|"Optimised"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_Optimised
argument_list|)
block|,
name|_ZOptimisedT1
block|,
literal|8
block|, }
block|,
define|#
directive|define
name|TY_OPTIMISED
value|32
block|{
literal|"MEMBER 9"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|member_T1_9
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_MEMBER9
value|33
block|{
literal|"EXTERNAL"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_Ext__typ
argument_list|)
block|,
name|_ZExt_typT1
block|,
literal|6
block|, }
block|,
define|#
directive|define
name|TY_EXTERNAL
value|34
block|{
literal|"Single EXTERNAL"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_SExt
argument_list|)
block|,
name|_ZSExtT1
block|,
literal|1
block|, }
block|,
define|#
directive|define
name|TY_SEXTERNAL
value|35
block|{
literal|"Explicit Tagged Objects"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_Etags
argument_list|)
block|,
name|_ZEtagsT1
block|,
literal|3
block|, }
block|,
define|#
directive|define
name|TY_ETAGOBJ
value|36
block|{
literal|"Single Objects"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_Stest
argument_list|)
block|,
name|_ZStestT1
block|,
literal|4
block|, }
block|,
define|#
directive|define
name|TY_STEST
value|37
block|{
literal|"Single Integer"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_Sint
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
define|#
directive|define
name|TY_SINT
value|38
block|{
literal|"Enumerated Type"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_Enum__type
argument_list|)
block|,
name|_ZEnum_typeT1
block|,
literal|4
block|, }
block|,
define|#
directive|define
name|TY_ETYPE
value|39
block|{
literal|"Tests of Enumerated type"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_T__enum
argument_list|)
block|,
name|_ZT_enumT1
block|,
literal|4
block|, }
block|,
define|#
directive|define
name|TY_ENUM_TEST
value|40
define|#
directive|define
name|TY_REAL
value|41
ifdef|#
directive|ifdef
name|PEPSY_REALS
block|{
literal|"Real"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_Real
argument_list|)
block|,
name|_ZRealT1
block|,
literal|3
block|, }
block|,
block|{
literal|"Tests of Real type"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|type_T1_T__real
argument_list|)
block|,
name|_ZT_realT1
block|,
literal|4
block|, }
block|,
block|{
literal|"Pepy Stuff"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|pepy_refs
argument_list|)
block|,
name|_ZT_pepyT1
block|,
literal|3
block|, }
block|,
block|{
literal|"Default Pepy"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|pepy_refs1
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
block|{
literal|"Optional Pepy"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|pepy_refs1
argument_list|)
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
block|{
literal|"Compound S-types"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|pepy_refs1
argument_list|)
block|,
name|_ZT3_SingleT1
block|,
literal|3
block|, }
block|,
else|#
directive|else
block|{
name|NULLCP
block|,
literal|0
block|,
name|NOENTRY
block|,
literal|3
block|, }
block|,
block|{
name|NULLCP
block|,
literal|0
block|,
name|NOENTRY
block|,
literal|4
block|, }
block|,
block|{
name|NULLCP
block|,
literal|0
block|,
name|NOENTRY
block|,
literal|3
block|, }
block|,
block|{
name|NULLCP
block|,
literal|0
block|,
name|NOENTRY
block|,
literal|3
block|, }
block|,
block|{
name|NULLCP
block|,
literal|0
block|,
name|NOENTRY
block|,
literal|0
block|, }
block|,
block|{
name|NULLCP
block|,
literal|0
block|,
name|NOENTRY
block|,
literal|3
block|, }
block|,
endif|#
directive|endif
define|#
directive|define
name|TY_REAL_TEST
value|42
define|#
directive|define
name|TY_PEPY
value|43
define|#
directive|define
name|TY_DEFPEPY
value|44
define|#
directive|define
name|TY_OPTPEPY
value|45
define|#
directive|define
name|TY_S_COMPD
value|46
block|{
literal|"Repeating pepy elements"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|repeats
argument_list|)
block|,
name|_ZT3_RepeatT1
block|,
literal|3
block|, }
block|,
define|#
directive|define
name|TY_REPEAT
value|47
ifdef|#
directive|ifdef
name|PEPSY_REALS
block|{
literal|"Value Passing Defined types"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|pepy_refs
argument_list|)
block|,
name|_ZT3_DefinedT1
block|,
literal|3
block|, }
block|,
else|#
directive|else
block|{
name|NULLCP
block|,
literal|0
block|,
name|NOENTRY
block|,
literal|3
block|, }
block|,
endif|#
directive|endif
define|#
directive|define
name|TY_VPDEFINED
value|48
block|{
literal|"function calling code"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|codedata
argument_list|)
block|,
name|_ZT3_CodeTestT1
block|,
literal|3
block|,}
block|,
define|#
directive|define
name|TY_FUNC
value|49
block|{
literal|"optional function calling"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|codedata
argument_list|)
block|,
name|NOENTRY
block|,
literal|3
block|,}
block|,
define|#
directive|define
name|TY_OPTFUNC
value|50
block|{
literal|"default function calling"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|codedata
argument_list|)
block|,
name|NOENTRY
block|,
literal|3
block|,}
block|,
define|#
directive|define
name|TY_DFTFUNC
value|51
ifdef|#
directive|ifdef
name|PEPSY_REALS
block|{
literal|"All Simple Types"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|codedata
argument_list|)
block|,
name|_ZT3_AllSimplesT1
block|,
literal|3
block|,}
block|,
else|#
directive|else
block|{
name|NULLCP
block|,
literal|0
block|,
name|NOENTRY
block|,
literal|3
block|, }
block|,
endif|#
directive|endif
define|#
directive|define
name|TY_ASIMPLE
value|52
block|{
literal|"Action Statements"
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|repeats
argument_list|)
block|,
name|_ZT3_UActionT1
block|,
literal|3
block|, }
block|,
define|#
directive|define
name|TY_ACTION
value|53
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXTCASE
value|(sizeof (t_case)/sizeof (t_case[0]))
end_define

end_unit

