begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* acconfig.h    This file is in the public domain.     Descriptive text for the C preprocessor macros that    the distributed Autoconf macros can define.    No software package will use all of them; autoheader copies the ones    your configure.in uses into your configuration header file templates.     The entries are in sort -df order: alphabetical, case insensitive,    ignoring punctuation (such as underscores).  Although this order    can split up related entries, it makes it easier to check whether    a given entry is in the file.     Leave the following blank line there!!  Autoheader needs it.  */
end_comment

begin_escape
end_escape

begin_expr_stmt
unit|@
name|TOP
expr|@
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
comment|/* Define as 1 if you have the stpcpy function.  */
undef|#
directive|undef
name|HAVE_STPCPY
comment|/* Define to the name of the distribution.  */
undef|#
directive|undef
name|PACKAGE
comment|/* Define to the version of the distribution.  */
undef|#
directive|undef
name|VERSION
expr|@
name|BOTTOM
expr|@
end_expr_stmt

begin_comment
comment|/* For gettext (NLS) */
end_comment

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|gettext (String)
end_define

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_escape
end_escape

begin_comment
comment|/* Leave that blank line there!!  Autoheader needs it.    If you're adding to this file, keep in mind:    The entries are in sort -df order: alphabetical, case insensitive,    ignoring punctuation (such as underscores).  */
end_comment

end_unit

