begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Floating point definitions for GDB.     Copyright 1986, 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995,    1996, 1997, 1998, 1999, 2000, 2001, 2003 Free Software Foundation,    Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOUBLEST_H
end_ifndef

begin_define
define|#
directive|define
name|DOUBLEST_H
end_define

begin_struct_decl
struct_decl|struct
name|type
struct_decl|;
end_struct_decl

begin_comment
comment|/* Setup definitions for host and target floating point formats.  We need to    consider the format for `float', `double', and `long double' for both target    and host.  We need to do this so that we know what kind of conversions need    to be done when converting target numbers to and from the hosts DOUBLEST    data type.  */
end_comment

begin_comment
comment|/* This is used to indicate that we don't know the format of the floating point    number.  Typically, this is useful for native ports, where the actual format    is irrelevant, since no conversions will be taking place.  */
end_comment

begin_include
include|#
directive|include
file|"floatformat.h"
end_include

begin_comment
comment|/* For struct floatformat */
end_comment

begin_comment
comment|/* Use `long double' if the host compiler supports it.  (Note that this is not    necessarily any longer than `double'.  On SunOS/gcc, it's the same as    double.)  This is necessary because GDB internally converts all floating    point values to the widest type supported by the host.     There are problems however, when the target `long double' is longer than the    host's `long double'.  In general, we'll probably reduce the precision of    any such values and print a warning.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LONG_DOUBLE
end_ifdef

begin_typedef
typedef|typedef
name|long
name|double
name|DOUBLEST
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|double
name|DOUBLEST
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|floatformat_to_doublest
parameter_list|(
specifier|const
name|struct
name|floatformat
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
name|in
parameter_list|,
name|DOUBLEST
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|floatformat_from_doublest
parameter_list|(
specifier|const
name|struct
name|floatformat
modifier|*
parameter_list|,
specifier|const
name|DOUBLEST
modifier|*
name|in
parameter_list|,
name|void
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|floatformat_is_negative
parameter_list|(
specifier|const
name|struct
name|floatformat
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|floatformat_is_nan
parameter_list|(
specifier|const
name|struct
name|floatformat
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|floatformat_mantissa
parameter_list|(
specifier|const
name|struct
name|floatformat
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* These functions have been replaced by extract_typed_floating and    store_typed_floating.     Most calls are passing in TYPE_LENGTH (TYPE) so can be changed to    just pass the TYPE.  The remainder pass in the length of a    register, those calls should instead pass in the floating point    type that corresponds to that length.  */
end_comment

begin_function_decl
specifier|extern
name|DOUBLEST
name|deprecated_extract_floating
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|deprecated_store_floating
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|int
name|len
parameter_list|,
name|DOUBLEST
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given TYPE, return its floatformat.  TYPE_FLOATFORMAT() may return    NULL.  type_floatformat() detects that and returns a floatformat    based on the type size when FLOATFORMAT is NULL.  */
end_comment

begin_function_decl
specifier|const
name|struct
name|floatformat
modifier|*
name|floatformat_from_type
parameter_list|(
specifier|const
name|struct
name|type
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DOUBLEST
name|extract_typed_floating
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|,
specifier|const
name|struct
name|type
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|store_typed_floating
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
specifier|const
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|DOUBLEST
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|convert_typed_floating
parameter_list|(
specifier|const
name|void
modifier|*
name|from
parameter_list|,
specifier|const
name|struct
name|type
modifier|*
name|from_type
parameter_list|,
name|void
modifier|*
name|to
parameter_list|,
specifier|const
name|struct
name|type
modifier|*
name|to_type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

