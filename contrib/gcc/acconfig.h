begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define if you can safely include both<string.h> and<strings.h>.  */
end_comment

begin_undef
undef|#
directive|undef
name|STRING_WITH_STRINGS
end_undef

begin_comment
comment|/* Define if printf supports "%p".  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PRINTF_PTR
end_undef

begin_comment
comment|/* Define if you want expensive run-time checks. */
end_comment

begin_undef
undef|#
directive|undef
name|ENABLE_CHECKING
end_undef

begin_comment
comment|/* Define to 1 if NLS is requested.  */
end_comment

begin_undef
undef|#
directive|undef
name|ENABLE_NLS
end_undef

begin_comment
comment|/* Define as 1 if you have catgets and don't want to use GNU gettext.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_CATGETS
end_undef

begin_comment
comment|/* Define as 1 if you have gettext and don't want to use GNU gettext.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GETTEXT
end_undef

begin_comment
comment|/* Define if your cpp understands the stringify operator.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_CPP_STRINGIFY
end_undef

begin_comment
comment|/* Define if your compiler understands volatile.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_VOLATILE
end_undef

begin_comment
comment|/* Define if your assembler supports specifying the maximum number    of bytes to skip when using the GAS .p2align command. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GAS_MAX_SKIP_P2ALIGN
end_undef

begin_comment
comment|/* Define if your assembler supports .balign and .p2align.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GAS_BALIGN_AND_P2ALIGN
end_undef

begin_comment
comment|/* Define if your assembler supports .subsection and .subsection -1 starts    emitting at the beginning of your section */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GAS_SUBSECTION_ORDERING
end_undef

begin_comment
comment|/* Define if your assembler uses the old HImode fild and fist notation.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GAS_FILDS_FISTS
end_undef

begin_comment
comment|/* Define if you have a working<inttypes.h> header file.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_INTTYPES_H
end_undef

begin_comment
comment|/* Define if your locale.h file contains LC_MESSAGES.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_LC_MESSAGES
end_undef

begin_comment
comment|/* Define as 1 if you have the stpcpy function.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_STPCPY
end_undef

begin_comment
comment|/* Whether malloc must be declared even if<stdlib.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_MALLOC
end_undef

begin_comment
comment|/* Whether realloc must be declared even if<stdlib.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_REALLOC
end_undef

begin_comment
comment|/* Whether calloc must be declared even if<stdlib.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_CALLOC
end_undef

begin_comment
comment|/* Whether free must be declared even if<stdlib.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_FREE
end_undef

begin_comment
comment|/* Whether bcopy must be declared even if<string.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_BCOPY
end_undef

begin_comment
comment|/* Whether bcmp must be declared even if<string.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_BCMP
end_undef

begin_comment
comment|/* Whether bzero must be declared even if<string.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_BZERO
end_undef

begin_comment
comment|/* Whether index must be declared even if<string.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_INDEX
end_undef

begin_comment
comment|/* Whether rindex must be declared even if<string.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_RINDEX
end_undef

begin_comment
comment|/* Whether getenv must be declared even if<stdlib.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_GETENV
end_undef

begin_comment
comment|/* Whether atol must be declared even if<stdlib.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_ATOL
end_undef

begin_comment
comment|/* Whether atof must be declared even if<stdlib.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_ATOF
end_undef

begin_comment
comment|/* Whether sbrk must be declared even if<stdlib.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_SBRK
end_undef

begin_comment
comment|/* Whether abort must be declared even if<stdlib.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_ABORT
end_undef

begin_comment
comment|/* Whether strerror must be declared even if<string.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_STRERROR
end_undef

begin_comment
comment|/* Whether strsignal must be declared even if<string.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_STRSIGNAL
end_undef

begin_comment
comment|/* Whether strstr must be declared even if<string.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_STRSTR
end_undef

begin_comment
comment|/* Whether getcwd must be declared even if<unistd.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_GETCWD
end_undef

begin_comment
comment|/* Whether getwd must be declared even if<unistd.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_GETWD
end_undef

begin_comment
comment|/* Whether getrlimit must be declared even if<sys/resource.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_GETRLIMIT
end_undef

begin_comment
comment|/* Whether setrlimit must be declared even if<sys/resource.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_SETRLIMIT
end_undef

begin_comment
comment|/* Whether putc_unlocked must be declared even if<stdio.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_PUTC_UNLOCKED
end_undef

begin_comment
comment|/* Whether fputs_unlocked must be declared even if<stdio.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_FPUTS_UNLOCKED
end_undef

begin_comment
comment|/* Define to enable the use of a default assembler. */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_ASSEMBLER
end_undef

begin_comment
comment|/* Define to enable the use of a default linker. */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_LINKER
end_undef

begin_comment
comment|/* Define if host mkdir takes a single argument. */
end_comment

begin_undef
undef|#
directive|undef
name|MKDIR_TAKES_ONE_ARG
end_undef

begin_comment
comment|/* Define to the name of the distribution.  */
end_comment

begin_undef
undef|#
directive|undef
name|PACKAGE
end_undef

begin_comment
comment|/* Define to the version of the distribution.  */
end_comment

begin_undef
undef|#
directive|undef
name|VERSION
end_undef

begin_expr_stmt
unit|@
name|TOP
expr|@
end_expr_stmt

end_unit

