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
value|((void)0)
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|__eprintf
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in gnulib */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

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
name|lineno
parameter_list|)
define|\
value|(__eprintf ("Failed assertion `%s' at line %d of `%s'.\n",	\ 	      expression, lineno, file), 0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no __STDC__; i.e. -traditional.  */
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
value|(__eprintf ("Failed assertion `%s' at line %d of `%s'.\n",	\ 	      "expression", lineno, file), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no __STDC__; i.e. -traditional.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

