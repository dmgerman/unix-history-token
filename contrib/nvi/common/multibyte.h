begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1992, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	$Id: multibyte.h,v 1.32 2012/10/07 01:35:58 zy Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MULTIBYTE_H
end_ifndef

begin_define
define|#
directive|define
name|MULTIBYTE_H
end_define

begin_comment
comment|/*  * Fundamental character types.  *  * CHAR_T	An integral type that can hold any character.  * ARG_CHAR_T	The type of a CHAR_T when passed as an argument using  *		traditional promotion rules.  It should also be able  *		to be compared against any CHAR_T for equality without  *		problems.  * UCHAR_T	The shortest unified character type (8-bit clean).  * RCHAR_T	The character type used by the internal regex engine.  *  * If no integral type can hold a character, don't even try the port.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|ARG_CHAR_T
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_WIDECHAR
end_ifdef

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_include
include|#
directive|include
file|<wctype.h>
end_include

begin_typedef
typedef|typedef
name|wchar_t
name|CHAR_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|wint_t
name|UCHAR_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|wchar_t
name|RCHAR_T
typedef|;
end_typedef

begin_define
define|#
directive|define
name|REOF
value|WEOF
end_define

begin_define
define|#
directive|define
name|STRLEN
value|wcslen
end_define

begin_define
define|#
directive|define
name|STRTOL
value|wcstol
end_define

begin_define
define|#
directive|define
name|STRTOUL
value|wcstoul
end_define

begin_define
define|#
directive|define
name|SPRINTF
value|swprintf
end_define

begin_define
define|#
directive|define
name|STRCMP
value|wcscmp
end_define

begin_define
define|#
directive|define
name|STRPBRK
value|wcspbrk
end_define

begin_define
define|#
directive|define
name|ISBLANK
value|iswblank
end_define

begin_define
define|#
directive|define
name|ISCNTRL
value|iswcntrl
end_define

begin_define
define|#
directive|define
name|ISDIGIT
value|iswdigit
end_define

begin_define
define|#
directive|define
name|ISXDIGIT
value|iswxdigit
end_define

begin_define
define|#
directive|define
name|ISGRAPH
value|iswgraph
end_define

begin_define
define|#
directive|define
name|ISLOWER
value|iswlower
end_define

begin_define
define|#
directive|define
name|ISPRINT
value|iswprint
end_define

begin_define
define|#
directive|define
name|ISPUNCT
value|iswpunct
end_define

begin_define
define|#
directive|define
name|ISSPACE
value|iswspace
end_define

begin_define
define|#
directive|define
name|ISUPPER
value|iswupper
end_define

begin_define
define|#
directive|define
name|TOLOWER
value|towlower
end_define

begin_define
define|#
directive|define
name|TOUPPER
value|towupper
end_define

begin_define
define|#
directive|define
name|STRSET
value|wmemset
end_define

begin_define
define|#
directive|define
name|STRCHR
value|wcschr
end_define

begin_define
define|#
directive|define
name|STRRCHR
value|wcsrchr
end_define

begin_define
define|#
directive|define
name|GETC
value|getwc
end_define

begin_define
define|#
directive|define
name|L
parameter_list|(
name|ch
parameter_list|)
value|L ## ch
end_define

begin_define
define|#
directive|define
name|WS
value|"%ls"
end_define

begin_define
define|#
directive|define
name|WVS
value|"%*ls"
end_define

begin_define
define|#
directive|define
name|WC
value|"%lc"
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|u_char
name|CHAR_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_char
name|UCHAR_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|RCHAR_T
typedef|;
end_typedef

begin_define
define|#
directive|define
name|REOF
value|EOF
end_define

begin_define
define|#
directive|define
name|STRLEN
value|strlen
end_define

begin_define
define|#
directive|define
name|STRTOL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(strtol(a,(char**)b,c))
end_define

begin_define
define|#
directive|define
name|STRTOUL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(strtoul(a,(char**)b,c))
end_define

begin_define
define|#
directive|define
name|SPRINTF
value|snprintf
end_define

begin_define
define|#
directive|define
name|STRCMP
value|strcmp
end_define

begin_define
define|#
directive|define
name|STRPBRK
value|strpbrk
end_define

begin_define
define|#
directive|define
name|ISBLANK
value|isblank
end_define

begin_define
define|#
directive|define
name|ISCNTRL
value|iscntrl
end_define

begin_define
define|#
directive|define
name|ISDIGIT
value|isdigit
end_define

begin_define
define|#
directive|define
name|ISXDIGIT
value|isxdigit
end_define

begin_define
define|#
directive|define
name|ISGRAPH
value|isgraph
end_define

begin_define
define|#
directive|define
name|ISLOWER
value|islower
end_define

begin_define
define|#
directive|define
name|ISPRINT
value|isprint
end_define

begin_define
define|#
directive|define
name|ISPUNCT
value|ispunct
end_define

begin_define
define|#
directive|define
name|ISSPACE
value|isspace
end_define

begin_define
define|#
directive|define
name|ISUPPER
value|isupper
end_define

begin_define
define|#
directive|define
name|TOLOWER
value|tolower
end_define

begin_define
define|#
directive|define
name|TOUPPER
value|toupper
end_define

begin_define
define|#
directive|define
name|STRSET
value|memset
end_define

begin_define
define|#
directive|define
name|STRCHR
value|strchr
end_define

begin_define
define|#
directive|define
name|STRRCHR
value|strrchr
end_define

begin_define
define|#
directive|define
name|GETC
value|getc
end_define

begin_define
define|#
directive|define
name|L
parameter_list|(
name|ch
parameter_list|)
value|ch
end_define

begin_define
define|#
directive|define
name|WS
value|"%s"
end_define

begin_define
define|#
directive|define
name|WVS
value|"%*s"
end_define

begin_define
define|#
directive|define
name|WC
value|"%c"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_WIDECHAR
argument_list|)
operator|&&
name|defined
argument_list|(
name|DEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|MEMCPY
value|wmemcpy
end_define

begin_define
define|#
directive|define
name|MEMMOVE
value|wmemmove
end_define

begin_define
define|#
directive|define
name|MEMCMP
value|wmemcmp
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MEMCPY
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|,
name|len
parameter_list|)
value|memcpy(p, t, (len) * sizeof(CHAR_T))
end_define

begin_define
define|#
directive|define
name|MEMMOVE
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|,
name|len
parameter_list|)
value|memmove(p, t, (len) * sizeof(CHAR_T))
end_define

begin_define
define|#
directive|define
name|MEMCMP
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|,
name|len
parameter_list|)
value|memcmp(p, t, (len) * sizeof(CHAR_T))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIZE
parameter_list|(
name|w
parameter_list|)
value|(sizeof(w) / sizeof(*w))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

