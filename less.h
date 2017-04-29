begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1984-2017  Mark Nudelman  *  * You may distribute under the terms of either the GNU General Public  * License or the Less License, as specified in the README file.  *  * For more information, see the README file.  */
end_comment

begin_define
define|#
directive|define
name|NEWBOT
value|1
end_define

begin_comment
comment|/*  * Standard include file for "less".  */
end_comment

begin_comment
comment|/*  * Defines for MSDOS_COMPILER.  */
end_comment

begin_define
define|#
directive|define
name|MSOFTC
value|1
end_define

begin_comment
comment|/* Microsoft C */
end_comment

begin_define
define|#
directive|define
name|BORLANDC
value|2
end_define

begin_comment
comment|/* Borland C */
end_comment

begin_define
define|#
directive|define
name|WIN32C
value|3
end_define

begin_comment
comment|/* Windows (Borland C or Microsoft C) */
end_comment

begin_define
define|#
directive|define
name|DJGPPC
value|4
end_define

begin_comment
comment|/* DJGPP C */
end_comment

begin_comment
comment|/*  * Include the file of compile-time options.  * The<> make cc search for it in -I., not srcdir.  */
end_comment

begin_include
include|#
directive|include
file|<defines.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_SEQUENT_
end_ifdef

begin_comment
comment|/*  * Kludge for Sequent Dynix systems that have sigsetmask, but  * it's not compatible with the way less calls it.  * {{ Do other systems need this? }}  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SIGSETMASK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Language details.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_ANSI_PROTOS
end_if

begin_define
define|#
directive|define
name|LESSPARAMS
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LESSPARAMS
parameter_list|(
name|a
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_VOID
end_if

begin_define
define|#
directive|define
name|VOID_POINTER
value|void *
end_define

begin_define
define|#
directive|define
name|VOID_PARAM
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VOID_POINTER
value|char *
end_define

begin_define
define|#
directive|define
name|VOID_PARAM
end_define

begin_define
define|#
directive|define
name|void
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_CONST
end_if

begin_define
define|#
directive|define
name|constant
value|const
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|constant
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|public
end_define

begin_comment
comment|/* PUBLIC FUNCTION */
end_comment

begin_comment
comment|/* Library function declarations */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_TYPES_H
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STDIO_H
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_FCNTL_H
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_CTYPE_H
end_if

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_WCTYPE_H
end_if

begin_include
include|#
directive|include
file|<wctype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_LIMITS_H
end_if

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STDLIB_H
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STRING_H
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS-specific includes */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_OSK
end_ifdef

begin_include
include|#
directive|include
file|<modes.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__TANDEM
end_ifdef

begin_include
include|#
directive|include
file|<floss.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MSDOS_COMPILER
operator|==
name|WIN32C
operator|||
name|OS2
end_if

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MSDOS_COMPILER
operator|==
name|DJGPPC
end_if

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_include
include|#
directive|include
file|<sys/exceptn.h>
end_include

begin_include
include|#
directive|include
file|<conio.h>
end_include

begin_include
include|#
directive|include
file|<pc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_STDLIB_H
end_if

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|VOID_POINTER
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Simple lowercase test which can be used during option processing  * (before options are parsed which might tell us what charset to use).  */
end_comment

begin_define
define|#
directive|define
name|ASCII_IS_UPPER
parameter_list|(
name|c
parameter_list|)
value|((c)>= 'A'&& (c)<= 'Z')
end_define

begin_define
define|#
directive|define
name|ASCII_IS_LOWER
parameter_list|(
name|c
parameter_list|)
value|((c)>= 'a'&& (c)<= 'z')
end_define

begin_define
define|#
directive|define
name|ASCII_TO_UPPER
parameter_list|(
name|c
parameter_list|)
value|((c) - 'a' + 'A')
end_define

begin_define
define|#
directive|define
name|ASCII_TO_LOWER
parameter_list|(
name|c
parameter_list|)
value|((c) - 'A' + 'a')
end_define

begin_undef
undef|#
directive|undef
name|IS_UPPER
end_undef

begin_undef
undef|#
directive|undef
name|IS_LOWER
end_undef

begin_undef
undef|#
directive|undef
name|TO_UPPER
end_undef

begin_undef
undef|#
directive|undef
name|TO_LOWER
end_undef

begin_undef
undef|#
directive|undef
name|IS_SPACE
end_undef

begin_undef
undef|#
directive|undef
name|IS_DIGIT
end_undef

begin_if
if|#
directive|if
name|HAVE_WCTYPE
end_if

begin_define
define|#
directive|define
name|IS_UPPER
parameter_list|(
name|c
parameter_list|)
value|iswupper(c)
end_define

begin_define
define|#
directive|define
name|IS_LOWER
parameter_list|(
name|c
parameter_list|)
value|iswlower(c)
end_define

begin_define
define|#
directive|define
name|TO_UPPER
parameter_list|(
name|c
parameter_list|)
value|towupper(c)
end_define

begin_define
define|#
directive|define
name|TO_LOWER
parameter_list|(
name|c
parameter_list|)
value|towlower(c)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_UPPER_LOWER
end_if

begin_define
define|#
directive|define
name|IS_UPPER
parameter_list|(
name|c
parameter_list|)
value|isupper((unsigned char) (c))
end_define

begin_define
define|#
directive|define
name|IS_LOWER
parameter_list|(
name|c
parameter_list|)
value|islower((unsigned char) (c))
end_define

begin_define
define|#
directive|define
name|TO_UPPER
parameter_list|(
name|c
parameter_list|)
value|toupper((unsigned char) (c))
end_define

begin_define
define|#
directive|define
name|TO_LOWER
parameter_list|(
name|c
parameter_list|)
value|tolower((unsigned char) (c))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IS_UPPER
parameter_list|(
name|c
parameter_list|)
value|ASCII_IS_UPPER(c)
end_define

begin_define
define|#
directive|define
name|IS_LOWER
parameter_list|(
name|c
parameter_list|)
value|ASCII_IS_LOWER(c)
end_define

begin_define
define|#
directive|define
name|TO_UPPER
parameter_list|(
name|c
parameter_list|)
value|ASCII_TO_UPPER(c)
end_define

begin_define
define|#
directive|define
name|TO_LOWER
parameter_list|(
name|c
parameter_list|)
value|ASCII_TO_LOWER(c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|isspace
end_ifdef

begin_define
define|#
directive|define
name|IS_SPACE
parameter_list|(
name|c
parameter_list|)
value|isspace((unsigned char)(c))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IS_SPACE
parameter_list|(
name|c
parameter_list|)
value|((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r' || (c) == '\f')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|isdigit
end_ifdef

begin_define
define|#
directive|define
name|IS_DIGIT
parameter_list|(
name|c
parameter_list|)
value|isdigit((unsigned char)(c))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IS_DIGIT
parameter_list|(
name|c
parameter_list|)
value|((c)>= '0'&& (c)<= '9')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IS_CSI_START
parameter_list|(
name|c
parameter_list|)
value|(((LWCHAR)(c)) == ESC || (((LWCHAR)(c)) == CSI))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OPT_OFF
value|0
end_define

begin_define
define|#
directive|define
name|OPT_ON
value|1
end_define

begin_define
define|#
directive|define
name|OPT_ONPLUS
value|2
end_define

begin_if
if|#
directive|if
operator|!
name|HAVE_MEMCPY
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|memcpy
end_ifndef

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|,
name|len
parameter_list|)
value|bcopy((from),(to),(len))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SNPRINTF
end_if

begin_define
define|#
directive|define
name|SNPRINTF1
parameter_list|(
name|str
parameter_list|,
name|size
parameter_list|,
name|fmt
parameter_list|,
name|v1
parameter_list|)
value|snprintf((str), (size), (fmt), (v1))
end_define

begin_define
define|#
directive|define
name|SNPRINTF2
parameter_list|(
name|str
parameter_list|,
name|size
parameter_list|,
name|fmt
parameter_list|,
name|v1
parameter_list|,
name|v2
parameter_list|)
value|snprintf((str), (size), (fmt), (v1), (v2))
end_define

begin_define
define|#
directive|define
name|SNPRINTF3
parameter_list|(
name|str
parameter_list|,
name|size
parameter_list|,
name|fmt
parameter_list|,
name|v1
parameter_list|,
name|v2
parameter_list|,
name|v3
parameter_list|)
value|snprintf((str), (size), (fmt), (v1), (v2), (v3))
end_define

begin_define
define|#
directive|define
name|SNPRINTF4
parameter_list|(
name|str
parameter_list|,
name|size
parameter_list|,
name|fmt
parameter_list|,
name|v1
parameter_list|,
name|v2
parameter_list|,
name|v3
parameter_list|,
name|v4
parameter_list|)
value|snprintf((str), (size), (fmt), (v1), (v2), (v3), (v4))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Use unsafe sprintf if we don't have snprintf. */
end_comment

begin_define
define|#
directive|define
name|SNPRINTF1
parameter_list|(
name|str
parameter_list|,
name|size
parameter_list|,
name|fmt
parameter_list|,
name|v1
parameter_list|)
value|sprintf((str), (fmt), (v1))
end_define

begin_define
define|#
directive|define
name|SNPRINTF2
parameter_list|(
name|str
parameter_list|,
name|size
parameter_list|,
name|fmt
parameter_list|,
name|v1
parameter_list|,
name|v2
parameter_list|)
value|sprintf((str), (fmt), (v1), (v2))
end_define

begin_define
define|#
directive|define
name|SNPRINTF3
parameter_list|(
name|str
parameter_list|,
name|size
parameter_list|,
name|fmt
parameter_list|,
name|v1
parameter_list|,
name|v2
parameter_list|,
name|v3
parameter_list|)
value|sprintf((str), (fmt), (v1), (v2), (v3))
end_define

begin_define
define|#
directive|define
name|SNPRINTF4
parameter_list|(
name|str
parameter_list|,
name|size
parameter_list|,
name|fmt
parameter_list|,
name|v1
parameter_list|,
name|v2
parameter_list|,
name|v3
parameter_list|,
name|v4
parameter_list|)
value|sprintf((str), (fmt), (v1), (v2), (v3), (v4))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BAD_LSEEK
value|((off_t)-1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_END
end_ifndef

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CHAR_BIT
end_ifndef

begin_define
define|#
directive|define
name|CHAR_BIT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Upper bound on the string length of an integer converted to string.  * 302 / 1000 is ceil (log10 (2.0)).  Subtract 1 for the sign bit;  * add 1 for integer division truncation; add 1 more for a minus sign.  */
end_comment

begin_define
define|#
directive|define
name|INT_STRLEN_BOUND
parameter_list|(
name|t
parameter_list|)
value|((sizeof(t) * CHAR_BIT - 1) * 302 / 1000 + 1 + 1)
end_define

begin_comment
comment|/*  * Special types and constants.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|LWCHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|off_t
name|POSITION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|off_t
name|LINENUM
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MIN_LINENUM_WIDTH
value|7
end_define

begin_comment
comment|/* Min printing width of a line number */
end_comment

begin_define
define|#
directive|define
name|MAX_UTF_CHAR_LEN
value|6
end_define

begin_comment
comment|/* Max bytes in one UTF-8 char */
end_comment

begin_define
define|#
directive|define
name|NULL_POSITION
value|((POSITION)(-1))
end_define

begin_comment
comment|/*  * Flags for open()  */
end_comment

begin_if
if|#
directive|if
name|MSDOS_COMPILER
operator|||
name|OS2
end_if

begin_define
define|#
directive|define
name|OPEN_READ
value|(O_RDONLY|O_BINARY)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_OSK
end_ifdef

begin_define
define|#
directive|define
name|OPEN_READ
value|(S_IREAD)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|O_RDONLY
end_ifdef

begin_define
define|#
directive|define
name|OPEN_READ
value|(O_RDONLY)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OPEN_READ
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|O_WRONLY
argument_list|)
operator|&&
name|defined
argument_list|(
name|O_APPEND
argument_list|)
end_if

begin_define
define|#
directive|define
name|OPEN_APPEND
value|(O_APPEND|O_WRONLY)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_OSK
end_ifdef

begin_define
define|#
directive|define
name|OPEN_APPEND
value|(S_IWRITE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OPEN_APPEND
value|(1)
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
comment|/*  * Set a file descriptor to binary mode.  */
end_comment

begin_if
if|#
directive|if
name|MSDOS_COMPILER
operator|==
name|MSOFTC
end_if

begin_define
define|#
directive|define
name|SET_BINARY
parameter_list|(
name|f
parameter_list|)
value|_setmode(f, _O_BINARY);
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|MSDOS_COMPILER
operator|||
name|OS2
end_if

begin_define
define|#
directive|define
name|SET_BINARY
parameter_list|(
name|f
parameter_list|)
value|setmode(f, O_BINARY)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SET_BINARY
parameter_list|(
name|f
parameter_list|)
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
comment|/*  * Does the shell treat "?" as a metacharacter?  */
end_comment

begin_if
if|#
directive|if
name|MSDOS_COMPILER
operator|||
name|OS2
operator|||
name|_OSK
end_if

begin_define
define|#
directive|define
name|SHELL_META_QUEST
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SHELL_META_QUEST
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPACES_IN_FILENAMES
value|1
end_define

begin_comment
comment|/*  * An IFILE represents an input file.  */
end_comment

begin_define
define|#
directive|define
name|IFILE
value|VOID_POINTER
end_define

begin_define
define|#
directive|define
name|NULL_IFILE
value|((IFILE)NULL)
end_define

begin_comment
comment|/*  * The structure used to represent a "screen position".  * This consists of a file position, and a screen line number.  * The meaning is that the line starting at the given file  * position is displayed on the ln-th line of the screen.  * (Screen lines before ln are empty.)  */
end_comment

begin_struct
struct|struct
name|scrpos
block|{
name|POSITION
name|pos
decl_stmt|;
name|int
name|ln
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * A mark is an ifile (input file) plus a position within the file.  */
end_comment

begin_struct
struct|struct
name|mark
block|{
name|IFILE
name|m_ifile
decl_stmt|;
name|struct
name|scrpos
name|m_scrpos
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
union|union
name|parg
block|{
name|char
modifier|*
name|p_string
decl_stmt|;
name|int
name|p_int
decl_stmt|;
name|LINENUM
name|p_linenum
decl_stmt|;
block|}
name|PARG
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULL_PARG
value|((PARG *)NULL)
end_define

begin_struct
struct|struct
name|textlist
block|{
name|char
modifier|*
name|string
decl_stmt|;
name|char
modifier|*
name|endstring
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wchar_range
block|{
name|LWCHAR
name|first
decl_stmt|,
name|last
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wchar_range_table
block|{
name|struct
name|wchar_range
modifier|*
name|table
decl_stmt|;
name|int
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EOI
value|(-1)
end_define

begin_define
define|#
directive|define
name|READ_INTR
value|(-2)
end_define

begin_comment
comment|/* A fraction is represented by an int n; the fraction is n/NUM_FRAC_DENOM */
end_comment

begin_define
define|#
directive|define
name|NUM_FRAC_DENOM
value|1000000
end_define

begin_define
define|#
directive|define
name|NUM_LOG_FRAC_DENOM
value|6
end_define

begin_comment
comment|/* How quiet should we be? */
end_comment

begin_define
define|#
directive|define
name|NOT_QUIET
value|0
end_define

begin_comment
comment|/* Ring bell at eof and for errors */
end_comment

begin_define
define|#
directive|define
name|LITTLE_QUIET
value|1
end_define

begin_comment
comment|/* Ring bell only for errors */
end_comment

begin_define
define|#
directive|define
name|VERY_QUIET
value|2
end_define

begin_comment
comment|/* Never ring bell */
end_comment

begin_comment
comment|/* How should we prompt? */
end_comment

begin_define
define|#
directive|define
name|PR_SHORT
value|0
end_define

begin_comment
comment|/* Prompt with colon */
end_comment

begin_define
define|#
directive|define
name|PR_MEDIUM
value|1
end_define

begin_comment
comment|/* Prompt with message */
end_comment

begin_define
define|#
directive|define
name|PR_LONG
value|2
end_define

begin_comment
comment|/* Prompt with longer message */
end_comment

begin_comment
comment|/* How should we handle backspaces? */
end_comment

begin_define
define|#
directive|define
name|BS_SPECIAL
value|0
end_define

begin_comment
comment|/* Do special things for underlining and bold */
end_comment

begin_define
define|#
directive|define
name|BS_NORMAL
value|1
end_define

begin_comment
comment|/* \b treated as normal char; actually output */
end_comment

begin_define
define|#
directive|define
name|BS_CONTROL
value|2
end_define

begin_comment
comment|/* \b treated as control char; prints as ^H */
end_comment

begin_comment
comment|/* How should we search? */
end_comment

begin_define
define|#
directive|define
name|SRCH_FORW
value|(1<< 0)
end_define

begin_comment
comment|/* Search forward from current position */
end_comment

begin_define
define|#
directive|define
name|SRCH_BACK
value|(1<< 1)
end_define

begin_comment
comment|/* Search backward from current position */
end_comment

begin_define
define|#
directive|define
name|SRCH_NO_MOVE
value|(1<< 2)
end_define

begin_comment
comment|/* Highlight, but don't move */
end_comment

begin_define
define|#
directive|define
name|SRCH_FIND_ALL
value|(1<< 4)
end_define

begin_comment
comment|/* Find and highlight all matches */
end_comment

begin_define
define|#
directive|define
name|SRCH_NO_MATCH
value|(1<< 8)
end_define

begin_comment
comment|/* Search for non-matching lines */
end_comment

begin_define
define|#
directive|define
name|SRCH_PAST_EOF
value|(1<< 9)
end_define

begin_comment
comment|/* Search past end-of-file, into next file */
end_comment

begin_define
define|#
directive|define
name|SRCH_FIRST_FILE
value|(1<< 10)
end_define

begin_comment
comment|/* Search starting at the first file */
end_comment

begin_define
define|#
directive|define
name|SRCH_NO_REGEX
value|(1<< 12)
end_define

begin_comment
comment|/* Don't use regular expressions */
end_comment

begin_define
define|#
directive|define
name|SRCH_FILTER
value|(1<< 13)
end_define

begin_comment
comment|/* Search is for '&' (filter) command */
end_comment

begin_define
define|#
directive|define
name|SRCH_AFTER_TARGET
value|(1<< 14)
end_define

begin_comment
comment|/* Start search after the target line */
end_comment

begin_define
define|#
directive|define
name|SRCH_REVERSE
parameter_list|(
name|t
parameter_list|)
value|(((t)& SRCH_FORW) ? \ 				(((t)& ~SRCH_FORW) | SRCH_BACK) : \ 				(((t)& ~SRCH_BACK) | SRCH_FORW))
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|NO_MCA
value|0
end_define

begin_define
define|#
directive|define
name|MCA_DONE
value|1
end_define

begin_define
define|#
directive|define
name|MCA_MORE
value|2
end_define

begin_define
define|#
directive|define
name|CC_OK
value|0
end_define

begin_comment
comment|/* Char was accepted& processed */
end_comment

begin_define
define|#
directive|define
name|CC_QUIT
value|1
end_define

begin_comment
comment|/* Char was a request to abort current cmd */
end_comment

begin_define
define|#
directive|define
name|CC_ERROR
value|2
end_define

begin_comment
comment|/* Char could not be accepted due to error */
end_comment

begin_define
define|#
directive|define
name|CC_PASS
value|3
end_define

begin_comment
comment|/* Char was rejected (internal) */
end_comment

begin_define
define|#
directive|define
name|CF_QUIT_ON_ERASE
value|0001
end_define

begin_comment
comment|/* Abort cmd if its entirely erased */
end_comment

begin_comment
comment|/* Special char bit-flags used to tell put_line() to do something special */
end_comment

begin_define
define|#
directive|define
name|AT_NORMAL
value|(0)
end_define

begin_define
define|#
directive|define
name|AT_UNDERLINE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AT_BOLD
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AT_BLINK
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AT_STANDOUT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AT_ANSI
value|(1<< 4)
end_define

begin_comment
comment|/* Content-supplied "ANSI" escape sequence */
end_comment

begin_define
define|#
directive|define
name|AT_BINARY
value|(1<< 5)
end_define

begin_comment
comment|/* LESS*BINFMT representation */
end_comment

begin_define
define|#
directive|define
name|AT_HILITE
value|(1<< 6)
end_define

begin_comment
comment|/* Internal highlights (e.g., for search) */
end_comment

begin_if
if|#
directive|if
literal|'0'
operator|==
literal|240
end_if

begin_define
define|#
directive|define
name|IS_EBCDIC_HOST
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|IS_EBCDIC_HOST
end_if

begin_comment
comment|/*  * Long definition for EBCDIC.  * Since the argument is usually a constant, this macro normally compiles  * into a constant.  */
end_comment

begin_define
define|#
directive|define
name|CONTROL
parameter_list|(
name|c
parameter_list|)
value|( \ 	(c)=='[' ? '\047' : \ 	(c)=='a' ? '\001' : \ 	(c)=='b' ? '\002' : \ 	(c)=='c' ? '\003' : \ 	(c)=='d' ? '\067' : \ 	(c)=='e' ? '\055' : \ 	(c)=='f' ? '\056' : \ 	(c)=='g' ? '\057' : \ 	(c)=='h' ? '\026' : \ 	(c)=='i' ? '\005' : \ 	(c)=='j' ? '\025' : \ 	(c)=='k' ? '\013' : \ 	(c)=='l' ? '\014' : \ 	(c)=='m' ? '\015' : \ 	(c)=='n' ? '\016' : \ 	(c)=='o' ? '\017' : \ 	(c)=='p' ? '\020' : \ 	(c)=='q' ? '\021' : \ 	(c)=='r' ? '\022' : \ 	(c)=='s' ? '\023' : \ 	(c)=='t' ? '\074' : \ 	(c)=='u' ? '\075' : \ 	(c)=='v' ? '\062' : \ 	(c)=='w' ? '\046' : \ 	(c)=='x' ? '\030' : \ 	(c)=='y' ? '\031' : \ 	(c)=='z' ? '\077' : \ 	(c)=='A' ? '\001' : \ 	(c)=='B' ? '\002' : \ 	(c)=='C' ? '\003' : \ 	(c)=='D' ? '\067' : \ 	(c)=='E' ? '\055' : \ 	(c)=='F' ? '\056' : \ 	(c)=='G' ? '\057' : \ 	(c)=='H' ? '\026' : \ 	(c)=='I' ? '\005' : \ 	(c)=='J' ? '\025' : \ 	(c)=='K' ? '\013' : \ 	(c)=='L' ? '\014' : \ 	(c)=='M' ? '\015' : \ 	(c)=='N' ? '\016' : \ 	(c)=='O' ? '\017' : \ 	(c)=='P' ? '\020' : \ 	(c)=='Q' ? '\021' : \ 	(c)=='R' ? '\022' : \ 	(c)=='S' ? '\023' : \ 	(c)=='T' ? '\074' : \ 	(c)=='U' ? '\075' : \ 	(c)=='V' ? '\062' : \ 	(c)=='W' ? '\046' : \ 	(c)=='X' ? '\030' : \ 	(c)=='Y' ? '\031' : \ 	(c)=='Z' ? '\077' : \ 	(c)=='|' ? '\031' : \ 	(c)=='\\' ? '\034' : \ 	(c)=='^' ? '\036' : \ 	(c)&077)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CONTROL
parameter_list|(
name|c
parameter_list|)
value|((c)&037)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IS_EBCDIC_HOST */
end_comment

begin_define
define|#
directive|define
name|ESC
value|CONTROL('[')
end_define

begin_define
define|#
directive|define
name|CSI
value|((unsigned char)'\233')
end_define

begin_define
define|#
directive|define
name|CHAR_END_COMMAND
value|0x40000000
end_define

begin_if
if|#
directive|if
name|_OSK_MWC32
end_if

begin_define
define|#
directive|define
name|LSIGNAL
parameter_list|(
name|sig
parameter_list|,
name|func
parameter_list|)
value|os9_signal(sig,func)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LSIGNAL
parameter_list|(
name|sig
parameter_list|,
name|func
parameter_list|)
value|signal(sig,func)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SIGPROCMASK
end_if

begin_if
if|#
directive|if
name|HAVE_SIGSET_T
end_if

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|HAVE_SIGPROCMASK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SIGPROCMASK
end_if

begin_if
if|#
directive|if
name|HAVE_SIGEMPTYSET
end_if

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|sigemptyset
end_undef

begin_define
define|#
directive|define
name|sigemptyset
parameter_list|(
name|mp
parameter_list|)
value|*(mp) = 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|S_INTERRUPT
value|01
end_define

begin_define
define|#
directive|define
name|S_STOP
value|02
end_define

begin_define
define|#
directive|define
name|S_WINCH
value|04
end_define

begin_define
define|#
directive|define
name|ABORT_SIGS
parameter_list|()
value|(sigs& (S_INTERRUPT|S_STOP))
end_define

begin_define
define|#
directive|define
name|QUIT_OK
value|0
end_define

begin_define
define|#
directive|define
name|QUIT_ERROR
value|1
end_define

begin_define
define|#
directive|define
name|QUIT_INTERRUPT
value|2
end_define

begin_define
define|#
directive|define
name|QUIT_SAVED_STATUS
value|(-1)
end_define

begin_define
define|#
directive|define
name|FOLLOW_DESC
value|0
end_define

begin_define
define|#
directive|define
name|FOLLOW_NAME
value|1
end_define

begin_comment
comment|/* filestate flags */
end_comment

begin_define
define|#
directive|define
name|CH_CANSEEK
value|001
end_define

begin_define
define|#
directive|define
name|CH_KEEPOPEN
value|002
end_define

begin_define
define|#
directive|define
name|CH_POPENED
value|004
end_define

begin_define
define|#
directive|define
name|CH_HELPFILE
value|010
end_define

begin_define
define|#
directive|define
name|CH_NODATA
value|020
end_define

begin_comment
comment|/* Special case for zero length files */
end_comment

begin_define
define|#
directive|define
name|ch_zero
parameter_list|()
value|((POSITION)0)
end_define

begin_define
define|#
directive|define
name|FAKE_HELPFILE
value|"@/\\less/\\help/\\file/\\@"
end_define

begin_define
define|#
directive|define
name|FAKE_EMPTYFILE
value|"@/\\less/\\empty/\\file/\\@"
end_define

begin_comment
comment|/* Flags for cvt_text */
end_comment

begin_define
define|#
directive|define
name|CVT_TO_LC
value|01
end_define

begin_comment
comment|/* Convert upper-case to lower-case */
end_comment

begin_define
define|#
directive|define
name|CVT_BS
value|02
end_define

begin_comment
comment|/* Do backspace processing */
end_comment

begin_define
define|#
directive|define
name|CVT_CRLF
value|04
end_define

begin_comment
comment|/* Remove CR after LF */
end_comment

begin_define
define|#
directive|define
name|CVT_ANSI
value|010
end_define

begin_comment
comment|/* Remove ANSI escape sequences */
end_comment

begin_if
if|#
directive|if
name|HAVE_TIME_T
end_if

begin_define
define|#
directive|define
name|time_type
value|time_t
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|time_type
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|mlist
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|loption
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|hilite_tree
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|"pattern.h"
end_include

begin_include
include|#
directive|include
file|"funcs.h"
end_include

begin_comment
comment|/* Functions not included in funcs.h */
end_comment

begin_function_decl
name|void
name|postoa
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linenumtoa
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inttoa
parameter_list|()
function_decl|;
end_function_decl

end_unit

