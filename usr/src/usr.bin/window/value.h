begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)value.h	3.1 83/11/22  */
end_comment

begin_struct
struct|struct
name|value
block|{
name|char
name|v_type
decl_stmt|;
name|struct
name|value
modifier|*
name|v_link
decl_stmt|;
union|union
block|{
name|int
name|V_num
decl_stmt|;
name|char
modifier|*
name|V_str
decl_stmt|;
name|int
name|V_tok
decl_stmt|;
block|}
name|v_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|v_num
value|v_un.V_num
end_define

begin_define
define|#
directive|define
name|v_str
value|v_un.V_str
end_define

begin_define
define|#
directive|define
name|v_tok
value|v_un.V_tok
end_define

begin_define
define|#
directive|define
name|V_NUM
value|1
end_define

begin_define
define|#
directive|define
name|V_STR
value|2
end_define

begin_define
define|#
directive|define
name|V_TOK
value|3
end_define

begin_define
define|#
directive|define
name|V_ERR
value|4
end_define

end_unit

