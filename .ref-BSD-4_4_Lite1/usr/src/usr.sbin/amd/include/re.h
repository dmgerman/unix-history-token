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
name|char
name|regstart
decl_stmt|;
comment|/* Internal use only. */
name|char
name|reganch
decl_stmt|;
comment|/* Internal use only. */
name|char
modifier|*
name|regmust
decl_stmt|;
comment|/* Internal use only. */
name|int
name|regmlen
decl_stmt|;
comment|/* Internal use only. */
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
name|void
name|regsub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regerror
parameter_list|()
function_decl|;
end_function_decl

end_unit

