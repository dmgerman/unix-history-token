begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Allow this file to be included multiple times    with different settings of NDEBUG.  */
end_comment

begin_undef
undef|#
directive|undef
name|assert
end_undef

begin_undef
undef|#
directive|undef
name|__assert
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|NDEBUG
end_ifdef

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|ignore
parameter_list|)
value|((void) 0)
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|expression
parameter_list|)
define|\
value|((void) ((expression) ? 0 : __assert (expression, __FILE__, __LINE__)))
end_define

begin_define
define|#
directive|define
name|__assert
parameter_list|(
name|expression
parameter_list|,
name|file
parameter_list|,
name|lineno
parameter_list|)
define|\
value|(printf ("%s:%u: failed assertion\n", file, lineno),	\    abort (), 0)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_comment
comment|/* Defined in libgcc.a */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
specifier|extern
name|void
name|__eprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
block|)
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_else
unit|}
else|#
directive|else
end_else

begin_function_decl
unit|extern
name|void
name|__eprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|expression
parameter_list|)
define|\
value|((void) ((expression) ? 0 : __assert (#expression, __FILE__, __LINE__)))
end_define

begin_define
define|#
directive|define
name|__assert
parameter_list|(
name|expression
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|(__eprintf ("%s:%u: failed assertion `%s'\n",		\ 	      file, line, expression), 0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no __STDC__ and not C++; i.e. -traditional.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|__eprintf
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Defined in libgcc.a */
end_comment

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|expression
parameter_list|)
define|\
value|((void) ((expression) ? 0 : __assert (expression, __FILE__, __LINE__)))
end_define

begin_define
define|#
directive|define
name|__assert
parameter_list|(
name|expression
parameter_list|,
name|file
parameter_list|,
name|lineno
parameter_list|)
define|\
value|(__eprintf ("%s:%u: failed assertion `%s'\n",		\ 	      file, lineno, "expression"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no __STDC__ and not C++; i.e. -traditional.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no __GNU__; i.e., /bin/cc.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

