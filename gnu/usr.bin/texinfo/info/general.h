begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* general.h -- Some generally useful defines. */
end_comment

begin_comment
comment|/* This file is part of GNU Info, a program for reading online documentation    stored in Info format.     Copyright (C) 1993 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_GENERAL_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GENERAL_H_
end_define

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|xmalloc
argument_list|()
decl_stmt|,
modifier|*
name|xrealloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_UNISTD_H
argument_list|)
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

begin_comment
comment|/* HAVE_UNISTD_H */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STRING_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_STRING_H */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|savestring
argument_list|)
end_if

begin_define
define|#
directive|define
name|savestring
parameter_list|(
name|x
parameter_list|)
value|(char *)strcpy ((char *)xmalloc (1 + strlen (x)), x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !savestring */
end_comment

begin_define
define|#
directive|define
name|info_toupper
parameter_list|(
name|x
parameter_list|)
value|(islower (x) ? toupper (x) : x)
end_define

begin_define
define|#
directive|define
name|info_tolower
parameter_list|(
name|x
parameter_list|)
value|(isupper (x) ? tolower (x) : x)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|whitespace
argument_list|)
end_if

begin_define
define|#
directive|define
name|whitespace
parameter_list|(
name|c
parameter_list|)
value|((c == ' ') || (c == '\t'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !whitespace */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|whitespace_or_newline
argument_list|)
end_if

begin_define
define|#
directive|define
name|whitespace_or_newline
parameter_list|(
name|c
parameter_list|)
value|(whitespace (c) || (c == '\n'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !whitespace_or_newline */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FUNCTION_DEF
argument_list|)
end_if

begin_define
define|#
directive|define
name|__FUNCTION_DEF
end_define

begin_typedef
typedef|typedef
name|int
name|Function
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|VFunction
parameter_list|()
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FUNCTION_DEF */
end_comment

begin_comment
comment|/* Add POINTER to the list of pointers found in ARRAY.  SLOTS is the number    of slots that have already been allocated.  INDEX is the index into the    array where POINTER should be added.  GROW is the number of slots to grow    ARRAY by, in the case that it needs growing.  TYPE is a cast of the type    of object stored in ARRAY (e.g., NODE_ENTRY *. */
end_comment

begin_define
define|#
directive|define
name|add_pointer_to_array
parameter_list|(
name|pointer
parameter_list|,
name|idx
parameter_list|,
name|array
parameter_list|,
name|slots
parameter_list|,
name|grow
parameter_list|,
name|type
parameter_list|)
define|\
value|do { \     if (idx + 2>= slots) \       array = (type *)(xrealloc (array, (slots += grow) * sizeof (type))); \     array[idx++] = (type)pointer; \     array[idx] = (type)NULL; \   } while (0)
end_define

begin_define
define|#
directive|define
name|maybe_free
parameter_list|(
name|x
parameter_list|)
value|do { if (x) free (x); } while (0)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_BZERO
argument_list|)
end_if

begin_define
define|#
directive|define
name|zero_mem
parameter_list|(
name|mem
parameter_list|,
name|length
parameter_list|)
value|memset (mem, 0, length)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|zero_mem
parameter_list|(
name|mem
parameter_list|,
name|length
parameter_list|)
value|bzero (mem, length)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !BZERO_MISSING */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_GENERAL_H_ */
end_comment

end_unit

