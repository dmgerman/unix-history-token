begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|MATCH_H
end_ifndef

begin_define
define|#
directive|define
name|MATCH_H
end_define

begin_comment
comment|/*  * Returns true if the given string matches the pattern (which may contain ?  * and * as wildcards), and zero if it does not match.  */
end_comment

begin_function_decl
name|int
name|match_pattern
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|pattern
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Tries to match the host name (which must be in all lowercase) against the  * comma-separated sequence of subpatterns (each possibly preceded by ! to  * indicate negation).  Returns true if there is a positive match; zero  * otherwise.  */
end_comment

begin_function_decl
name|int
name|match_hostname
parameter_list|(
specifier|const
name|char
modifier|*
name|host
parameter_list|,
specifier|const
name|char
modifier|*
name|pattern
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

