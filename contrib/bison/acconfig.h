begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_H
end_define

begin_expr_stmt
unit|@
name|TOP
expr|@
comment|/* Name of package.  */
undef|#
directive|undef
name|PACKAGE
comment|/* Version of package.  */
undef|#
directive|undef
name|VERSION
comment|/* Version string.  */
undef|#
directive|undef
name|VERSION_STRING
comment|/* Define if the compiler understands prototypes.  */
undef|#
directive|undef
name|PROTOTYPES
comment|/* Define to 1 if NLS is requested.  */
undef|#
directive|undef
name|ENABLE_NLS
comment|/* Define as 1 if you have catgets and don't want to use GNU gettext.  */
undef|#
directive|undef
name|HAVE_CATGETS
comment|/* Define as 1 if you have gettext and don't want to use GNU gettext.  */
undef|#
directive|undef
name|HAVE_GETTEXT
comment|/* Define if your locale.h file contains LC_MESSAGES.  */
undef|#
directive|undef
name|HAVE_LC_MESSAGES
comment|/* Define to 1 if you have the stpcpy function.  */
undef|#
directive|undef
name|HAVE_STPCPY
comment|/* The location of the simple parser (bison.simple).  */
undef|#
directive|undef
name|XPFILE
comment|/* The location of the semantic parser (bison.hairy).  */
undef|#
directive|undef
name|XPFILE1
comment|/* The location of the local directory.  */
undef|#
directive|undef
name|LOCALEDIR
comment|/* Define as 1 if realloc must be declared even if<stdlib.h> is    included.  */
undef|#
directive|undef
name|NEED_DECLARATION_REALLOC
comment|/* Define as 1 if calloc must be declared even if<stdlib.h> is    included.  */
undef|#
directive|undef
name|NEED_DECLARATION_CALLOC
expr|@
name|BOTTOM
expr|@
end_expr_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PROTOTYPES
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|p
parameter_list|)
value|p
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|p
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_H */
end_comment

end_unit

