begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)context.h	3.2 83/12/07  */
end_comment

begin_struct
struct|struct
name|context
block|{
name|struct
name|context
modifier|*
name|x_link
decl_stmt|;
comment|/* nested contexts */
name|char
name|x_type
decl_stmt|;
union|union
block|{
comment|/* input info */
struct|struct
block|{
name|char
modifier|*
name|X_filename
decl_stmt|;
name|FILE
modifier|*
name|X_fp
decl_stmt|;
name|short
name|X_lineno
decl_stmt|;
name|char
name|X_bol
decl_stmt|;
name|char
name|X_noerrwin
decl_stmt|;
name|struct
name|ww
modifier|*
name|X_errwin
decl_stmt|;
block|}
name|x_f
struct|;
struct|struct
block|{
name|char
modifier|*
name|X_buf
decl_stmt|;
name|char
modifier|*
name|X_bufp
decl_stmt|;
block|}
name|x_b
struct|;
block|}
name|x_un
union|;
name|int
name|x_token
decl_stmt|;
comment|/* holding place for token */
name|struct
name|value
name|x_val
decl_stmt|;
name|unsigned
name|x_erred
range|:
literal|1
decl_stmt|;
comment|/* parser error flags */
name|unsigned
name|x_synerred
range|:
literal|1
decl_stmt|;
name|unsigned
name|x_abort
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|x_buf
value|x_un.x_b.X_buf
end_define

begin_define
define|#
directive|define
name|x_bufp
value|x_un.x_b.X_bufp
end_define

begin_define
define|#
directive|define
name|x_filename
value|x_un.x_f.X_filename
end_define

begin_define
define|#
directive|define
name|x_fp
value|x_un.x_f.X_fp
end_define

begin_define
define|#
directive|define
name|x_lineno
value|x_un.x_f.X_lineno
end_define

begin_define
define|#
directive|define
name|x_bol
value|x_un.x_f.X_bol
end_define

begin_define
define|#
directive|define
name|x_errwin
value|x_un.x_f.X_errwin
end_define

begin_define
define|#
directive|define
name|x_noerrwin
value|x_un.x_f.X_noerrwin
end_define

begin_define
define|#
directive|define
name|X_FILE
value|1
end_define

begin_define
define|#
directive|define
name|X_BUF
value|2
end_define

begin_decl_stmt
name|struct
name|context
name|cx
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|context
modifier|*
name|x_alloc
parameter_list|()
function_decl|;
end_function_decl

end_unit

