begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * KT-11 addresses and bits.  */
end_comment

begin_define
define|#
directive|define
name|UISD
value|((physadr)0177600)
end_define

begin_comment
comment|/* first user I-space descriptor register */
end_comment

begin_define
define|#
directive|define
name|UISA
value|((physadr)0177640)
end_define

begin_comment
comment|/* first user I-space address register */
end_comment

begin_define
define|#
directive|define
name|UDSA
value|((physadr)0177660)
end_define

begin_comment
comment|/* first user D-space address register */
end_comment

begin_define
define|#
directive|define
name|RO
value|02
end_define

begin_comment
comment|/* access abilities */
end_comment

begin_define
define|#
directive|define
name|RW
value|06
end_define

begin_define
define|#
directive|define
name|ED
value|010
end_define

begin_comment
comment|/* extend direction */
end_comment

begin_define
define|#
directive|define
name|TX
value|020
end_define

begin_comment
comment|/* Software: text segment */
end_comment

begin_define
define|#
directive|define
name|ABS
value|040
end_define

begin_comment
comment|/* Software: absolute address */
end_comment

begin_comment
comment|/*  * structure used to address  * a sequence of integers.  */
end_comment

begin_decl_stmt
name|physadr
name|ka6
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 11/40 KISA6; 11/45 KDSA6 */
end_comment

begin_comment
comment|/*  * address to access 11/70 UNIBUS map  */
end_comment

begin_define
define|#
directive|define
name|UBMAP
value|((physadr)0170200)
end_define

end_unit

