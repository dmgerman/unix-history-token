begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file describes the Operator Information Area in the 3270.  */
end_comment

begin_define
define|#
directive|define
name|INCLUDED_OIA
end_define

begin_define
define|#
directive|define
name|OIA_READY_3274
value|0xF4
end_define

begin_define
define|#
directive|define
name|OIA_ONLINE_A
value|0xCC
end_define

begin_define
define|#
directive|define
name|OIA_OWNERSHIP_MYJOB
value|0xCF
end_define

begin_define
define|#
directive|define
name|OIA_OWNERSHIP_SYSTEM_OPERATOR
value|0xF0
end_define

begin_define
define|#
directive|define
name|OIA_OWNERSHIP_UNOWNED
value|0xF1
end_define

begin_define
define|#
directive|define
name|OIA_INSERT_ON
value|0x3a
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|ready
decl_stmt|,
comment|/* 01-01 Is 3274 ready? */
name|online
decl_stmt|,
comment|/* 02-02 Online in which mode (a, b) */
name|ownership
decl_stmt|,
comment|/* 03-03 Who owns us (job, operator, unowned) */
name|test2_4
index|[
literal|3
index|]
decl_stmt|,
comment|/* 04-06 Rest of TEST string */
name|reserved
index|[
literal|2
index|]
decl_stmt|,
comment|/* 07-08 */
name|x
decl_stmt|,
comment|/* 09-09 X - input inhibited */
name|xnull
decl_stmt|,
comment|/* 10-10 Space */
name|xwhy
index|[
literal|7
index|]
decl_stmt|,
comment|/* 11-17 Why are we inhibited? */
name|reserved2
index|[
literal|14
index|]
decl_stmt|,
comment|/* 18-31 */
name|num
index|[
literal|3
index|]
decl_stmt|,
comment|/* 32-34 Numeric lock */
name|upshift
decl_stmt|,
comment|/* 35-35 Shift state */
name|insert
decl_stmt|,
comment|/* 36-36 Insert mode */
name|apl
index|[
literal|3
index|]
decl_stmt|;
comment|/* 37-39 APL mode */
block|}
name|OIA
typedef|;
end_typedef

end_unit

