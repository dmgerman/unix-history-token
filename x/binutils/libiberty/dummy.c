begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_define
define|#
directive|define
name|clock_t
value|unsigned long
end_define

begin_define
define|#
directive|define
name|DEF
parameter_list|(
name|NAME
parameter_list|,
name|RETURN_TYPE
parameter_list|,
name|ARGLIST
parameter_list|,
name|ARGS
parameter_list|)
value|extern RETURN_TYPE NAME (ARGS);
end_define

begin_define
define|#
directive|define
name|DEFFUNC
parameter_list|(
name|NAME
parameter_list|,
name|RETURN_TYPE
parameter_list|,
name|ARGLIST
parameter_list|,
name|ARGS
parameter_list|)
value|extern RETURN_TYPE NAME (ARGS);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|void
value|int
end_define

begin_define
define|#
directive|define
name|size_t
value|unsigned long
end_define

begin_define
define|#
directive|define
name|clock_t
value|unsigned long
end_define

begin_define
define|#
directive|define
name|DEF
parameter_list|(
name|NAME
parameter_list|,
name|RETURN_TYPE
parameter_list|,
name|ARGLIST
parameter_list|,
name|ARGS
parameter_list|)
value|extern RETURN_TYPE NAME ();
end_define

begin_define
define|#
directive|define
name|DEFFUNC
parameter_list|(
name|NAME
parameter_list|,
name|RETURN_TYPE
parameter_list|,
name|ARGLIST
parameter_list|,
name|ARGS
parameter_list|)
value|extern RETURN_TYPE NAME ();
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEFVAR
parameter_list|(
name|NAME
parameter_list|,
name|DECL
parameter_list|,
name|USE
parameter_list|)
value|extern DECL;
end_define

begin_define
define|#
directive|define
name|NOTHING
end_define

begin_comment
comment|/*nothing*/
end_comment

begin_include
include|#
directive|include
file|"alloca-conf.h"
end_include

begin_include
include|#
directive|include
file|"functions.def"
end_include

begin_comment
comment|/* Always use our: getopt.o getopt1.o obstack.o spaces.o */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
comment|/* Create a dummy function call for each DEF-defined function. */
undef|#
directive|undef
name|DEF
undef|#
directive|undef
name|DEFVAR
undef|#
directive|undef
name|DEFFUNC
undef|#
directive|undef
name|AND
define|#
directive|define
name|AND
value|= 0;
comment|/* ARGS expands into a set of declaration.  NAME ARG_LIST expands    info a function call that uses those variables as actual parameters.    If the function has been DEF'ed correctly, we can pass the right    number and types of parameters, which is nice.  (E.g. gcc may    otherwise complain about the wrong number of parameters to certain    builtins.) */
define|#
directive|define
name|DEF
parameter_list|(
name|NAME
parameter_list|,
name|RETURN_TYPE
parameter_list|,
name|ARG_LIST
parameter_list|,
name|ARGS
parameter_list|)
value|{ ARGS; NAME ARG_LIST; }
define|#
directive|define
name|DEFVAR
parameter_list|(
name|NAME
parameter_list|,
name|DECL
parameter_list|,
name|USE
parameter_list|)
value|{ USE; }
define|#
directive|define
name|DEFFUNC
parameter_list|(
name|NAME
parameter_list|,
name|RETURN_TYPE
parameter_list|,
name|ARG_LIST
parameter_list|,
name|ARGS
parameter_list|)
value|{ ARGS; NAME ARG_LIST; }
include|#
directive|include
file|"functions.def"
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

