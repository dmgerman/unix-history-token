begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* modechange.h -- definitions for file mode manipulation    Copyright (C) 1989, 1990 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Masks for the `flags' field in a `struct mode_change'. */
end_comment

begin_comment
comment|/* Affect the execute bits only if at least one execute bit is set already,    or if the file is a directory. */
end_comment

begin_define
define|#
directive|define
name|MODE_X_IF_ANY_X
value|01
end_define

begin_comment
comment|/* If set, copy some existing permissions for u, g, or o onto the other two.    Which of u, g, or o is copied is determined by which bits are set in the    `value' field. */
end_comment

begin_define
define|#
directive|define
name|MODE_COPY_EXISTING
value|02
end_define

begin_struct
struct|struct
name|mode_change
block|{
name|char
name|op
decl_stmt|;
comment|/* One of "=+-". */
name|char
name|flags
decl_stmt|;
comment|/* Special operations. */
name|unsigned
name|short
name|affected
decl_stmt|;
comment|/* Set for u/g/o/s/s/t, if to be affected. */
name|unsigned
name|short
name|value
decl_stmt|;
comment|/* Bits to add/remove. */
name|struct
name|mode_change
modifier|*
name|next
decl_stmt|;
comment|/* Link to next change in list. */
block|}
struct|;
end_struct

begin_comment
comment|/* Masks for mode_compile argument. */
end_comment

begin_define
define|#
directive|define
name|MODE_MASK_EQUALS
value|1
end_define

begin_define
define|#
directive|define
name|MODE_MASK_PLUS
value|2
end_define

begin_define
define|#
directive|define
name|MODE_MASK_MINUS
value|4
end_define

begin_comment
comment|/* Error return values for mode_compile. */
end_comment

begin_define
define|#
directive|define
name|MODE_INVALID
value|(struct mode_change *) 0
end_define

begin_define
define|#
directive|define
name|MODE_MEMORY_EXHAUSTED
value|(struct mode_change *) 1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|struct
name|mode_change
modifier|*
name|mode_compile
parameter_list|(
name|char
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|short
name|mode_adjust
parameter_list|(
name|unsigned
parameter_list|,
name|struct
name|mode_change
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mode_free
parameter_list|(
name|struct
name|mode_change
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|struct
name|mode_change
modifier|*
name|mode_compile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|short
name|mode_adjust
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mode_free
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

