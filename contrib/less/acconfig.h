begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1984-2000  Mark Nudelman  *  * You may distribute under the terms of either the GNU General Public  * License or the Less License, as specified in the README file.  *  * For more information about less, or for information on how to   * contact the author, see the README file.  */
end_comment

begin_comment
comment|/*  * Regular expression library.  * Define exactly one of the following to be 1:  * HAVE_POSIX_REGCOMP: POSIX regcomp() and regex.h  * HAVE_PCRE: PCRE (Perl-compatible regular expression) library  * HAVE_RE_COMP: BSD re_comp()  * HAVE_REGCMP: System V regcmp()  * HAVE_V8_REGCOMP: Henry Spencer V8 regcomp() and regexp.h  * NO_REGEX: pattern matching is supported, but without metacharacters.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_POSIX_REGCOMP
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_PCRE
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_RE_COMP
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_REGCMP
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_V8_REGCOMP
end_undef

begin_undef
undef|#
directive|undef
name|NO_REGEX
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_REGEXEC2
end_undef

begin_comment
comment|/* Define HAVE_VOID if your compiler supports the "void" type. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_VOID
end_undef

begin_comment
comment|/* Define HAVE_CONST if your compiler supports the "const" modifier. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_CONST
end_undef

begin_comment
comment|/* Define HAVE_TIME_T if your system supports the "time_t" type. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_TIME_T
end_undef

begin_comment
comment|/* Define HAVE_STRERROR if you have the strerror() function. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_STRERROR
end_undef

begin_comment
comment|/* Define HAVE_FILENO if you have the fileno() macro. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_FILENO
end_undef

begin_comment
comment|/* Define HAVE_ERRNO if you have the errno variable */
end_comment

begin_comment
comment|/* Define MUST_DEFINE_ERRNO if you have errno but it is not define   * in errno.h */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ERRNO
end_undef

begin_undef
undef|#
directive|undef
name|MUST_DEFINE_ERRNO
end_undef

begin_comment
comment|/* Define HAVE_SYS_ERRLIST if you have the sys_errlist[] variable */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SYS_ERRLIST
end_undef

begin_comment
comment|/* Define HAVE_OSPEED if your termcap library has the ospeed variable */
end_comment

begin_comment
comment|/* Define MUST_DEFINE_OSPEED if you have ospeed but it is not defined  * in termcap.h. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_OSPEED
end_undef

begin_undef
undef|#
directive|undef
name|MUST_DEFINE_OSPEED
end_undef

begin_comment
comment|/* Define HAVE_LOCALE if you have locale.h and setlocale. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_LOCALE
end_undef

begin_comment
comment|/* Define HAVE_TERMIOS_FUNCS if you have tcgetattr/tcsetattr */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_TERMIOS_FUNCS
end_undef

begin_comment
comment|/* Define HAVE_UPPER_LOWER if you have isupper, islower, toupper, tolower */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_UPPER_LOWER
end_undef

begin_comment
comment|/* Define HAVE_SIGSET_T you have the sigset_t type */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SIGSET_T
end_undef

begin_comment
comment|/* Define HAVE_SIGEMPTYSET if you have the sigemptyset macro */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SIGEMPTYSET
end_undef

begin_comment
comment|/* Define EDIT_PGM to your editor. */
end_comment

begin_define
define|#
directive|define
name|EDIT_PGM
value|"vi"
end_define

end_unit

