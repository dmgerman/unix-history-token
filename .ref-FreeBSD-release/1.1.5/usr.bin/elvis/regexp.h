begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions etc. for regexp(3) routines.  *  * Caveat:  this is V8 regexp(3) [actually, a reimplementation thereof],  * not the System V one.  */
end_comment

begin_define
define|#
directive|define
name|NSUBEXP
value|10
end_define

begin_typedef
typedef|typedef
struct|struct
name|regexp
block|{
name|char
modifier|*
name|startp
index|[
name|NSUBEXP
index|]
decl_stmt|;
name|char
modifier|*
name|endp
index|[
name|NSUBEXP
index|]
decl_stmt|;
name|int
name|minlen
decl_stmt|;
comment|/* length of shortest possible match */
name|char
name|first
decl_stmt|;
comment|/* first character, if known; else \0 */
name|char
name|bol
decl_stmt|;
comment|/* boolean: must start at beginning of line? */
name|char
name|program
index|[
literal|1
index|]
decl_stmt|;
comment|/* Unwarranted chumminess with compiler. */
block|}
name|regexp
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|regexp
modifier|*
name|regcomp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|regexec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|regsub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regerr
parameter_list|()
function_decl|;
end_function_decl

end_unit

