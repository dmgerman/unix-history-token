begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Copyright 1973 Bell Telephone Laboratories Inc  */
end_comment

begin_comment
comment|/*  * KT-11 registers  */
end_comment

begin_define
define|#
directive|define
name|UISD
value|0177600
end_define

begin_define
define|#
directive|define
name|UISA
value|0177640
end_define

begin_define
define|#
directive|define
name|RO
value|02
end_define

begin_define
define|#
directive|define
name|RW
value|06
end_define

begin_define
define|#
directive|define
name|WO
value|04
end_define

begin_define
define|#
directive|define
name|ED
value|010
end_define

begin_struct
struct|struct
block|{
name|int
name|r
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
modifier|*
name|ka6
decl_stmt|;
end_decl_stmt

end_unit

