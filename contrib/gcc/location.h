begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definition of location data type used in various part of GCC    Copyright (C) 2002 Free Software Foundation, Inc.    Contributed by Gabriel Dos Reis<gdr@codesourcery.com>  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.   In other words, you are welcome to use, share and improve this program.  You are forbidden to forbid anyone else to use, share and improve  what you give them.   Help stamp out software-hoarding!  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_LOCATION_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_LOCATION_H
end_define

begin_comment
comment|/* The data structure used to record a location in a translation unit.  */
end_comment

begin_decl_stmt
name|struct
name|location_s
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* The name of the source file involved.  */
specifier|const
name|char
modifier|*
name|file
decl_stmt|;
comment|/* The line-location in the source file.  */
name|int
name|line
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|struct
name|location_s
name|location_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

