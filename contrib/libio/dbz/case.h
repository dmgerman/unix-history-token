begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
specifier|extern
name|int
name|cistrncmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|rfc822ize
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|casemap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* must call cistrncmp before invoking TOLOW... */
end_comment

begin_define
define|#
directive|define
name|TOLOW
parameter_list|(
name|c
parameter_list|)
value|(casemap[(c)+128])
end_define

begin_comment
comment|/* see case.c for why 128 */
end_comment

begin_comment
comment|/* ...but the use of it in CISTREQN is safe without the preliminary call (!) */
end_comment

begin_comment
comment|/* CISTREQN is an optimised case-insensitive strncmp(a,b,n)==0; n> 0 */
end_comment

begin_define
define|#
directive|define
name|CISTREQN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
define|\
value|(TOLOW((a)[0]) == TOLOW((b)[0])&& cistrncmp(a, b, n) == 0)
end_define

end_unit

