begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of lexical codes needed by both lextaba.c and lexrf.c. */
end_comment

begin_define
define|#
directive|define
name|FCE
value|27
end_define

begin_comment
comment|/* FRE  Free character in use as an entity reference */
end_comment

begin_define
define|#
directive|define
name|FRE
value|0
end_define

begin_comment
comment|/* FREECHAR that is not in a CON delimiter-in-context. */
end_comment

begin_define
define|#
directive|define
name|LITC
value|21
end_define

begin_comment
comment|/* LIT LITA PIC or EE in use as a literal terminator */
end_comment

begin_define
define|#
directive|define
name|MINLITC
value|13
end_define

begin_comment
comment|/* LIT LITA as literal terminator in minimum data */
end_comment

begin_define
define|#
directive|define
name|MSC3
value|15
end_define

begin_comment
comment|/* ]    Also MSC[2]. */
end_comment

begin_define
define|#
directive|define
name|NET
value|17
end_define

begin_comment
comment|/* /    When enabled. */
end_comment

begin_define
define|#
directive|define
name|ETI
value|16
end_define

begin_comment
comment|/* /    Actually ETAGO[2] */
end_comment

begin_define
define|#
directive|define
name|SPCR
value|19
end_define

begin_comment
comment|/* Space in use as SR8. */
end_comment

begin_define
define|#
directive|define
name|TGO2
value|25
end_define

begin_comment
comment|/*<    TAGO; also MDO[1], PIO[1] */
end_comment

begin_define
define|#
directive|define
name|CDE
value|11
end_define

begin_comment
comment|/* NONSGML   delcdata CDATA/SDATA delimiter */
end_comment

end_unit

