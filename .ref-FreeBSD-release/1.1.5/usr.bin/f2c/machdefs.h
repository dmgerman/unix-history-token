begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|TYLENG
value|TYLONG
end_define

begin_comment
comment|/* char string length field */
end_comment

begin_define
define|#
directive|define
name|TYINT
value|TYLONG
end_define

begin_define
define|#
directive|define
name|SZADDR
value|4
end_define

begin_define
define|#
directive|define
name|SZSHORT
value|2
end_define

begin_define
define|#
directive|define
name|SZINT
value|4
end_define

begin_define
define|#
directive|define
name|SZLONG
value|4
end_define

begin_define
define|#
directive|define
name|SZLENG
value|SZLONG
end_define

begin_define
define|#
directive|define
name|SZDREAL
value|8
end_define

begin_comment
comment|/* Alignment restrictions */
end_comment

begin_define
define|#
directive|define
name|ALIADDR
value|SZADDR
end_define

begin_define
define|#
directive|define
name|ALISHORT
value|SZSHORT
end_define

begin_define
define|#
directive|define
name|ALILONG
value|4
end_define

begin_define
define|#
directive|define
name|ALIDOUBLE
value|8
end_define

begin_define
define|#
directive|define
name|ALIINT
value|ALILONG
end_define

begin_define
define|#
directive|define
name|ALILENG
value|ALILONG
end_define

begin_define
define|#
directive|define
name|BLANKCOMMON
value|"_BLNK__"
end_define

begin_comment
comment|/* Name for the unnamed 					   common block; this is unique 					   because of underscores */
end_comment

begin_define
define|#
directive|define
name|LABELFMT
value|"%s:\n"
end_define

begin_define
define|#
directive|define
name|MAXREGVAR
value|4
end_define

begin_define
define|#
directive|define
name|TYIREG
value|TYLONG
end_define

begin_define
define|#
directive|define
name|MSKIREG
value|(M(TYSHORT)|M(TYLONG))
end_define

begin_comment
comment|/* allowed types of DO indicies 					   which can be put in registers */
end_comment

end_unit

