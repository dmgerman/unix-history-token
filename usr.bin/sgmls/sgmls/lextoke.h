begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* LEXTOKE.H: Symbols for tokenization lexical classes. */
end_comment

begin_define
define|#
directive|define
name|INV
value|0
end_define

begin_comment
comment|/* Invalid Chars      Not allowed in an SGML name. */
end_comment

begin_define
define|#
directive|define
name|REC
value|1
end_define

begin_comment
comment|/* Record Boundary    RS and RE. */
end_comment

begin_define
define|#
directive|define
name|SEP
value|2
end_define

begin_comment
comment|/* Separator          TAB. */
end_comment

begin_define
define|#
directive|define
name|SP
value|3
end_define

begin_comment
comment|/* SPACE */
end_comment

begin_define
define|#
directive|define
name|NMC
value|4
end_define

begin_comment
comment|/* NAMECHAR  . _      Period, underscore (plus NMS, NUM). */
end_comment

begin_define
define|#
directive|define
name|NMS
value|5
end_define

begin_comment
comment|/* NAMESTRT           Lower and uppercase letters */
end_comment

begin_define
define|#
directive|define
name|NU
value|6
end_define

begin_comment
comment|/* NUMERAL            Numerals */
end_comment

begin_define
define|#
directive|define
name|EOB
value|7
end_define

begin_comment
comment|/* NONCHAR   28       End disk buffer. */
end_comment

end_unit

