begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|T_MINUS
value|1
end_define

begin_define
define|#
directive|define
name|T_MOD
value|2
end_define

begin_define
define|#
directive|define
name|T_DIV
value|3
end_define

begin_define
define|#
directive|define
name|T_DIVD
value|4
end_define

begin_define
define|#
directive|define
name|T_MULT
value|5
end_define

begin_define
define|#
directive|define
name|T_ADD
value|6
end_define

begin_define
define|#
directive|define
name|T_SUB
value|7
end_define

begin_define
define|#
directive|define
name|T_EQ
value|8
end_define

begin_define
define|#
directive|define
name|T_NE
value|9
end_define

begin_define
define|#
directive|define
name|T_LT
value|10
end_define

begin_define
define|#
directive|define
name|T_GT
value|11
end_define

begin_define
define|#
directive|define
name|T_LE
value|12
end_define

begin_define
define|#
directive|define
name|T_GE
value|13
end_define

begin_define
define|#
directive|define
name|T_NOT
value|14
end_define

begin_define
define|#
directive|define
name|T_AND
value|15
end_define

begin_define
define|#
directive|define
name|T_OR
value|16
end_define

begin_define
define|#
directive|define
name|T_ASGN
value|17
end_define

begin_define
define|#
directive|define
name|T_PLUS
value|18
end_define

begin_define
define|#
directive|define
name|T_IN
value|19
end_define

begin_define
define|#
directive|define
name|T_LISTPP
value|20
end_define

begin_define
define|#
directive|define
name|T_PDEC
value|21
end_define

begin_define
define|#
directive|define
name|T_FDEC
value|22
end_define

begin_define
define|#
directive|define
name|T_PVAL
value|23
end_define

begin_define
define|#
directive|define
name|T_PVAR
value|24
end_define

begin_define
define|#
directive|define
name|T_PFUNC
value|25
end_define

begin_define
define|#
directive|define
name|T_PPROC
value|26
end_define

begin_define
define|#
directive|define
name|T_NIL
value|27
end_define

begin_define
define|#
directive|define
name|T_STRNG
value|28
end_define

begin_define
define|#
directive|define
name|T_CSTRNG
value|29
end_define

begin_define
define|#
directive|define
name|T_PLUSC
value|30
end_define

begin_define
define|#
directive|define
name|T_MINUSC
value|31
end_define

begin_define
define|#
directive|define
name|T_ID
value|32
end_define

begin_define
define|#
directive|define
name|T_INT
value|33
end_define

begin_define
define|#
directive|define
name|T_FINT
value|34
end_define

begin_define
define|#
directive|define
name|T_CINT
value|35
end_define

begin_define
define|#
directive|define
name|T_CFINT
value|36
end_define

begin_define
define|#
directive|define
name|T_TYPTR
value|37
end_define

begin_define
define|#
directive|define
name|T_TYPACK
value|38
end_define

begin_define
define|#
directive|define
name|T_TYSCAL
value|39
end_define

begin_define
define|#
directive|define
name|T_TYRANG
value|40
end_define

begin_define
define|#
directive|define
name|T_TYARY
value|41
end_define

begin_define
define|#
directive|define
name|T_TYFILE
value|42
end_define

begin_define
define|#
directive|define
name|T_TYSET
value|43
end_define

begin_define
define|#
directive|define
name|T_TYREC
value|44
end_define

begin_define
define|#
directive|define
name|T_TYFIELD
value|45
end_define

begin_define
define|#
directive|define
name|T_TYVARPT
value|46
end_define

begin_define
define|#
directive|define
name|T_TYVARNT
value|47
end_define

begin_define
define|#
directive|define
name|T_CSTAT
value|48
end_define

begin_define
define|#
directive|define
name|T_BLOCK
value|49
end_define

begin_define
define|#
directive|define
name|T_LABEL
value|50
end_define

begin_define
define|#
directive|define
name|T_PCALL
value|51
end_define

begin_define
define|#
directive|define
name|T_FCALL
value|52
end_define

begin_define
define|#
directive|define
name|T_CASE
value|53
end_define

begin_define
define|#
directive|define
name|T_WITH
value|54
end_define

begin_define
define|#
directive|define
name|T_WHILE
value|55
end_define

begin_define
define|#
directive|define
name|T_REPEAT
value|56
end_define

begin_define
define|#
directive|define
name|T_FORU
value|57
end_define

begin_define
define|#
directive|define
name|T_FORD
value|58
end_define

begin_define
define|#
directive|define
name|T_GOTO
value|59
end_define

begin_define
define|#
directive|define
name|T_IF
value|60
end_define

begin_define
define|#
directive|define
name|T_ASRT
value|61
end_define

begin_define
define|#
directive|define
name|T_CSET
value|62
end_define

begin_define
define|#
directive|define
name|T_RANG
value|63
end_define

begin_define
define|#
directive|define
name|T_VAR
value|64
end_define

begin_define
define|#
directive|define
name|T_ARGL
value|65
end_define

begin_define
define|#
directive|define
name|T_ARY
value|66
end_define

begin_define
define|#
directive|define
name|T_FIELD
value|67
end_define

begin_define
define|#
directive|define
name|T_PTR
value|68
end_define

begin_define
define|#
directive|define
name|T_WEXP
value|69
end_define

begin_define
define|#
directive|define
name|T_PROG
value|70
end_define

begin_define
define|#
directive|define
name|T_BINT
value|71
end_define

begin_define
define|#
directive|define
name|T_CBINT
value|72
end_define

begin_define
define|#
directive|define
name|T_IFEL
value|73
end_define

begin_define
define|#
directive|define
name|T_IFX
value|74
end_define

begin_define
define|#
directive|define
name|T_TYID
value|75
end_define

end_unit

