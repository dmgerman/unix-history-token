begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tilde.h: Externally available variables and function in libtilde.a. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__TILDE_H__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__TILDE_H__
end_define

begin_comment
comment|/* Function pointers can be declared as (Function *)foo. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FUNCTION_DEF
argument_list|)
end_if

begin_define
define|#
directive|define
name|__FUNCTION_DEF
end_define

begin_typedef
typedef|typedef
name|int
name|Function
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|VFunction
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|CPFunction
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
modifier|*
name|CPPFunction
parameter_list|()
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FUNCTION_DEF */
end_comment

begin_comment
comment|/* If non-null, this contains the address of a function to call if the    standard meaning for expanding a tilde fails.  The function is called    with the text (sans tilde, as in "foo"), and returns a malloc()'ed string    which is the expansion, or a NULL pointer if there is no expansion. */
end_comment

begin_decl_stmt
specifier|extern
name|CPFunction
modifier|*
name|tilde_expansion_failure_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When non-null, this is a NULL terminated array of strings which    are duplicates for a tilde prefix.  Bash uses this to expand    `=~' and `:~'. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|tilde_additional_prefixes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When non-null, this is a NULL terminated array of strings which match    the end of a username, instead of just "/".  Bash sets this to    `:' and `=~'. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|tilde_additional_suffixes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return a new string which is the result of tilde expanding STRING. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|tilde_expand
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Do the work of tilde expansion on FILENAME.  FILENAME starts with a    tilde.  If there is no expansion, call tilde_expansion_failure_hook. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|tilde_expand_word
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TILDE_H__ */
end_comment

end_unit

