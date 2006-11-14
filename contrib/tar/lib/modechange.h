begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* modechange.h -- definitions for file mode manipulation    Copyright (C) 1989, 1990, 1997 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Masks for the `flags' field in a `struct mode_change'. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|MODECHANGE_H_
end_if

begin_define
define|#
directive|define
name|MODECHANGE_H_
end_define

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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
name|mode_t
name|affected
decl_stmt|;
comment|/* Set for u/g/o/s/s/t, if to be affected. */
name|mode_t
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

begin_define
define|#
directive|define
name|MODE_MASK_ALL
value|(MODE_MASK_EQUALS | MODE_MASK_PLUS | MODE_MASK_MINUS)
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

begin_define
define|#
directive|define
name|MODE_BAD_REFERENCE
value|(struct mode_change *) 2
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|defined
name|PROTOTYPES
operator|||
operator|(
name|defined
name|__STDC__
operator|&&
name|__STDC__
operator|)
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|Args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|mode_change
modifier|*
name|mode_compile
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mode_change
modifier|*
name|mode_create_from_ref
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mode_t
name|mode_adjust
name|PARAMS
argument_list|(
operator|(
name|mode_t
operator|,
specifier|const
expr|struct
name|mode_change
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mode_free
name|PARAMS
argument_list|(
operator|(
expr|struct
name|mode_change
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

