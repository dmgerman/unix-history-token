begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Project directory type label definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Boolean operation definitions  *  * Note: Definitions B_ID, B_NOT, B_AND, B_OR, B_LPAREN, B_RPAREN, B_EOS  * must not be changed because they are used as indices for the operator  * precedence parsing table. B_ID is also used as the default initializer  * for the type expression token table.  */
end_comment

begin_define
define|#
directive|define
name|B_ID
value|0
end_define

begin_comment
comment|/* boolean expression identifier */
end_comment

begin_define
define|#
directive|define
name|B_NOT
value|1
end_define

begin_comment
comment|/* boolean "not" operation */
end_comment

begin_define
define|#
directive|define
name|B_AND
value|2
end_define

begin_comment
comment|/* boolean "and" operation */
end_comment

begin_define
define|#
directive|define
name|B_OR
value|3
end_define

begin_comment
comment|/* boolean "or" operation */
end_comment

begin_define
define|#
directive|define
name|B_LPAREN
value|4
end_define

begin_comment
comment|/* "(" */
end_comment

begin_define
define|#
directive|define
name|B_RPAREN
value|5
end_define

begin_comment
comment|/* ")" */
end_comment

begin_define
define|#
directive|define
name|B_EOS
value|6
end_define

begin_comment
comment|/* end of boolean string */
end_comment

begin_define
define|#
directive|define
name|B_WHITE
value|7
end_define

begin_comment
comment|/* tab or blank */
end_comment

begin_comment
comment|/*  * Project directory boolean type expression token struct  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_postfix
block|{
name|short
name|p_class
decl_stmt|;
comment|/* type of boolean expression token */
name|short
name|p_sw
decl_stmt|;
comment|/* TRUE/FALSE switch */
name|char
modifier|*
name|p_id
decl_stmt|;
comment|/* boolean expression identifier */
name|char
modifier|*
name|p_label
decl_stmt|;
comment|/* project directory type label */
block|}
name|POSTFIX
typedef|;
end_typedef

begin_comment
comment|/*  * Project directory postfix type expression struct  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_pdtyp
block|{
name|int
name|pfxsize
decl_stmt|;
comment|/* size of postfix expression */
name|POSTFIX
modifier|*
name|pfx
decl_stmt|;
comment|/* base of postfix expression */
name|short
modifier|*
name|eval
decl_stmt|;
comment|/* base of expr evaluation stack */
block|}
name|PDTYP
typedef|;
end_typedef

end_unit

