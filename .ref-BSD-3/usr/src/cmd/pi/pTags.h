begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|IntTAG
value|0
end_define

begin_define
define|#
directive|define
name|RealTAG
value|1
end_define

begin_define
define|#
directive|define
name|StringTAG
value|2
end_define

begin_define
define|#
directive|define
name|ListTAG
value|3
end_define

begin_define
define|#
directive|define
name|ThreadTAG
value|4
end_define

begin_define
define|#
directive|define
name|GlobTAG
value|5
end_define

begin_define
define|#
directive|define
name|PorFTAG
value|6
end_define

begin_define
define|#
directive|define
name|BConstTAG
value|7
end_define

begin_define
define|#
directive|define
name|BTypeTAG
value|8
end_define

begin_define
define|#
directive|define
name|BVarTAG
value|9
end_define

begin_define
define|#
directive|define
name|BFuncTAG
value|10
end_define

begin_define
define|#
directive|define
name|BProcTAG
value|11
end_define

begin_define
define|#
directive|define
name|LabelDTAG
value|12
end_define

begin_define
define|#
directive|define
name|ConstDTAG
value|13
end_define

begin_define
define|#
directive|define
name|TypedTAG
value|14
end_define

begin_define
define|#
directive|define
name|TypeDTAG
value|15
end_define

begin_define
define|#
directive|define
name|EnumTTAG
value|16
end_define

begin_define
define|#
directive|define
name|ScalDTAG
value|17
end_define

begin_define
define|#
directive|define
name|RangeTTAG
value|18
end_define

begin_define
define|#
directive|define
name|SetTTAG
value|19
end_define

begin_define
define|#
directive|define
name|FileTTAG
value|20
end_define

begin_define
define|#
directive|define
name|PtrTTAG
value|21
end_define

begin_define
define|#
directive|define
name|PackTTAG
value|22
end_define

begin_define
define|#
directive|define
name|ArrayTTAG
value|23
end_define

begin_define
define|#
directive|define
name|RecTTAG
value|24
end_define

begin_define
define|#
directive|define
name|FldlstTAG
value|25
end_define

begin_define
define|#
directive|define
name|FieldDTAG
value|26
end_define

begin_define
define|#
directive|define
name|VarntTAG
value|27
end_define

begin_define
define|#
directive|define
name|VCaseTAG
value|28
end_define

begin_define
define|#
directive|define
name|VarDTAG
value|29
end_define

begin_define
define|#
directive|define
name|ParamDTAG
value|30
end_define

begin_define
define|#
directive|define
name|ValPTAG
value|31
end_define

begin_define
define|#
directive|define
name|VarPTAG
value|32
end_define

begin_define
define|#
directive|define
name|AssignTAG
value|33
end_define

begin_define
define|#
directive|define
name|PCallTAG
value|34
end_define

begin_define
define|#
directive|define
name|IfTAG
value|35
end_define

begin_define
define|#
directive|define
name|WhileTAG
value|36
end_define

begin_define
define|#
directive|define
name|RepeatTAG
value|37
end_define

begin_define
define|#
directive|define
name|ForUTAG
value|38
end_define

begin_define
define|#
directive|define
name|ForDTAG
value|39
end_define

begin_define
define|#
directive|define
name|CaseSTAG
value|40
end_define

begin_define
define|#
directive|define
name|CasedTAG
value|41
end_define

begin_define
define|#
directive|define
name|GotoTAG
value|42
end_define

begin_define
define|#
directive|define
name|LabelTAG
value|43
end_define

begin_define
define|#
directive|define
name|WithTAG
value|44
end_define

begin_define
define|#
directive|define
name|AssertTAG
value|45
end_define

begin_define
define|#
directive|define
name|BinOpTAG
value|46
end_define

begin_define
define|#
directive|define
name|AndTAG
value|47
end_define

begin_define
define|#
directive|define
name|OrTAG
value|48
end_define

begin_define
define|#
directive|define
name|EqTAG
value|49
end_define

begin_define
define|#
directive|define
name|NeTAG
value|50
end_define

begin_define
define|#
directive|define
name|LtTAG
value|51
end_define

begin_define
define|#
directive|define
name|GtTAG
value|52
end_define

begin_define
define|#
directive|define
name|LeTAG
value|53
end_define

begin_define
define|#
directive|define
name|GeTAG
value|54
end_define

begin_define
define|#
directive|define
name|InTAG
value|55
end_define

begin_define
define|#
directive|define
name|AddTAG
value|56
end_define

begin_define
define|#
directive|define
name|SubTAG
value|57
end_define

begin_define
define|#
directive|define
name|MultTAG
value|58
end_define

begin_define
define|#
directive|define
name|DivdTAG
value|59
end_define

begin_define
define|#
directive|define
name|DivTAG
value|60
end_define

begin_define
define|#
directive|define
name|ModTAG
value|61
end_define

begin_define
define|#
directive|define
name|UnOpTAG
value|62
end_define

begin_define
define|#
directive|define
name|PlusTAG
value|63
end_define

begin_define
define|#
directive|define
name|MinusTAG
value|64
end_define

begin_define
define|#
directive|define
name|NotTAG
value|65
end_define

begin_define
define|#
directive|define
name|FCallTAG
value|66
end_define

begin_define
define|#
directive|define
name|SetTAG
value|67
end_define

begin_define
define|#
directive|define
name|RangeTAG
value|68
end_define

begin_define
define|#
directive|define
name|VarTAG
value|69
end_define

begin_define
define|#
directive|define
name|PtrTAG
value|70
end_define

begin_define
define|#
directive|define
name|SubscTAG
value|71
end_define

begin_define
define|#
directive|define
name|SelTAG
value|72
end_define

begin_define
define|#
directive|define
name|NilTAG
value|73
end_define

begin_define
define|#
directive|define
name|WidthTAG
value|74
end_define

begin_define
define|#
directive|define
name|OctTAG
value|75
end_define

begin_define
define|#
directive|define
name|HexTAG
value|76
end_define

end_unit

