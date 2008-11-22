begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* A more useful interface to strtol.     Copyright (C) 1995, 1996, 1998, 1999, 2001, 2002, 2003, 2004 Free    Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XSTRTOL_H_
end_ifndef

begin_define
define|#
directive|define
name|XSTRTOL_H_
value|1
end_define

begin_include
include|#
directive|include
file|"exitfail.h"
end_include

begin_if
if|#
directive|if
name|HAVE_INTTYPES_H
end_if

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STDINT_H
end_if

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_STRTOL_ERROR
end_ifndef

begin_enum
enum|enum
name|strtol_error
block|{
name|LONGINT_OK
init|=
literal|0
block|,
comment|/* These two values can be ORed together, to indicate that both        errors occurred.  */
name|LONGINT_OVERFLOW
init|=
literal|1
block|,
name|LONGINT_INVALID_SUFFIX_CHAR
init|=
literal|2
block|,
name|LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW
init|=
operator|(
name|LONGINT_INVALID_SUFFIX_CHAR
operator||
name|LONGINT_OVERFLOW
operator|)
block|,
name|LONGINT_INVALID
init|=
literal|4
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|strtol_error
name|strtol_error
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_DECLARE_XSTRTOL
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|strtol_error name (const char *, char **, int, type *, const char *);
end_define

begin_macro
name|_DECLARE_XSTRTOL
argument_list|(
argument|xstrtol
argument_list|,
argument|long int
argument_list|)
end_macro

begin_macro
name|_DECLARE_XSTRTOL
argument_list|(
argument|xstrtoul
argument_list|,
argument|unsigned long int
argument_list|)
end_macro

begin_macro
name|_DECLARE_XSTRTOL
argument_list|(
argument|xstrtoimax
argument_list|,
argument|intmax_t
argument_list|)
end_macro

begin_macro
name|_DECLARE_XSTRTOL
argument_list|(
argument|xstrtoumax
argument_list|,
argument|uintmax_t
argument_list|)
end_macro

begin_define
define|#
directive|define
name|_STRTOL_ERROR
parameter_list|(
name|Exit_code
parameter_list|,
name|Str
parameter_list|,
name|Argument_type_string
parameter_list|,
name|Err
parameter_list|)
define|\
value|do									\     {									\       switch ((Err))							\ 	{								\ 	default:							\ 	  abort ();							\ 									\ 	case LONGINT_INVALID:						\ 	  error ((Exit_code), 0, "invalid %s `%s'",			\ 		 (Argument_type_string), (Str));			\ 	  break;							\ 									\ 	case LONGINT_INVALID_SUFFIX_CHAR:				\ 	case LONGINT_INVALID_SUFFIX_CHAR | LONGINT_OVERFLOW:		\ 	  error ((Exit_code), 0, "invalid character following %s in `%s'", \ 		 (Argument_type_string), (Str));			\ 	  break;							\ 									\ 	case LONGINT_OVERFLOW:						\ 	  error ((Exit_code), 0, "%s `%s' too large",			\ 		 (Argument_type_string), (Str));			\ 	  break;							\ 	}								\     }									\   while (0)
end_define

begin_define
define|#
directive|define
name|STRTOL_FATAL_ERROR
parameter_list|(
name|Str
parameter_list|,
name|Argument_type_string
parameter_list|,
name|Err
parameter_list|)
define|\
value|_STRTOL_ERROR (exit_failure, Str, Argument_type_string, Err)
end_define

begin_define
define|#
directive|define
name|STRTOL_FAIL_WARN
parameter_list|(
name|Str
parameter_list|,
name|Argument_type_string
parameter_list|,
name|Err
parameter_list|)
define|\
value|_STRTOL_ERROR (0, Str, Argument_type_string, Err)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not XSTRTOL_H_ */
end_comment

end_unit

