begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CAT
end_ifdef

begin_include
include|#
directive|include
file|<nl_types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|UNIV
name|nl_catd
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Don't use prototypes here in case nl_types.h declares a conflicting prototype. */
end_comment

begin_function_decl
name|nl_catd
name|catopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|catclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|catgets
parameter_list|()
function_decl|;
end_function_decl

end_unit

