begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	ttyent.h	4.1	84/04/27	*/
end_comment

begin_struct
struct|struct
name|ttyent
block|{
comment|/* see getttyent(3) */
name|char
modifier|*
name|ty_name
decl_stmt|;
comment|/* terminal device name */
name|char
modifier|*
name|ty_getty
decl_stmt|;
comment|/* name for gettytab (5) */
name|char
modifier|*
name|ty_type
decl_stmt|;
comment|/* terminal type for termcap (3X) */
name|int
name|ty_status
decl_stmt|;
comment|/* status flags (see below for defines) */
name|char
modifier|*
name|ty_comment
decl_stmt|;
comment|/* unused - for comments */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TTY_ON
value|0x1
end_define

begin_comment
comment|/* enable logins (startup getty) */
end_comment

begin_define
define|#
directive|define
name|TTY_SECURE
value|0x2
end_define

begin_comment
comment|/* allow root to login */
end_comment

begin_function_decl
specifier|extern
name|struct
name|ttyent
modifier|*
name|getttyent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ttyent
modifier|*
name|getttynam
parameter_list|()
function_decl|;
end_function_decl

end_unit

