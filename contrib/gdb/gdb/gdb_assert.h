begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GDB-friendly replacement for<assert.h>.    Copyright 2000, 2001 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GDB_ASSERT_H
end_ifndef

begin_define
define|#
directive|define
name|GDB_ASSERT_H
end_define

begin_comment
comment|/* PRAGMATICS: "gdb_assert.h":gdb_assert() is a lower case (rather    than upper case) macro since that provides the closest fit to the    existing lower case macro<assert.h>:assert() that it is    replacing. */
end_comment

begin_define
define|#
directive|define
name|gdb_assert
parameter_list|(
name|expr
parameter_list|)
define|\
value|((void) ((expr) ? 0 :                                                       \ 	   (gdb_assert_fail (#expr, __FILE__, __LINE__, ASSERT_FUNCTION), 0)))
end_define

begin_comment
comment|/* Version 2.4 and later of GCC define a magical variable `__PRETTY_FUNCTION__'    which contains the name of the function currently being defined.    This is broken in G++ before version 2.6.    C9x has a similar variable called __func__, but prefer the GCC one since    it demangles C++ function names.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|GCC_VERSION
operator|>=
literal|2004
operator|)
end_if

begin_define
define|#
directive|define
name|ASSERT_FUNCTION
value|__PRETTY_FUNCTION__
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
name|__STDC_VERSION__
operator|&&
name|__STDC_VERSION__
operator|>=
literal|199901L
end_if

begin_define
define|#
directive|define
name|ASSERT_FUNCTION
value|__func__
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
comment|/* This prints an "Assertion failed" message, aksing the user if they    want to continue, dump core, or just exit.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ASSERT_FUNCTION
argument_list|)
end_if

begin_define
define|#
directive|define
name|gdb_assert_fail
parameter_list|(
name|assertion
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|,
name|function
parameter_list|)
define|\
value|internal_error (file, line, "%s: Assertion `%s' failed.",                   \ 		  function, assertion)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|gdb_assert_fail
parameter_list|(
name|assertion
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|,
name|function
parameter_list|)
define|\
value|internal_error (file, line, "Assertion `%s' failed.",                       \ 		  assertion)
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
comment|/* gdb_assert.h */
end_comment

end_unit

