begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* unwind-ia64.h -- dump IA-64 unwind info.    Copyright 2000, 2001 Free Software Foundation, Inc. 	Contributed by David Mosberger-Tang<davidm@hpl.hp.com>  This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<elf/ia64.h>
end_include

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_define
define|#
directive|define
name|UNW_VER
parameter_list|(
name|x
parameter_list|)
value|((x)>> 48)
end_define

begin_define
define|#
directive|define
name|UNW_FLAG_MASK
value|0x0000ffff00000000
end_define

begin_define
define|#
directive|define
name|UNW_FLAG_OSMASK
value|0x0000f00000000000
end_define

begin_define
define|#
directive|define
name|UNW_FLAG_EHANDLER
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x0000000100000000L)
end_define

begin_define
define|#
directive|define
name|UNW_FLAG_UHANDLER
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x0000000200000000L)
end_define

begin_define
define|#
directive|define
name|UNW_LENGTH
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x00000000ffffffffL)
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
modifier|*
name|unw_decode
name|PARAMS
argument_list|(
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

