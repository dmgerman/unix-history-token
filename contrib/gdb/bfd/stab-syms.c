begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Table of stab names for the BFD library.    Copyright (C) 1990, 91, 92, 93, 94, 95, 1996 Free Software Foundation, Inc.    Written by Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_define
define|#
directive|define
name|ARCH_SIZE
value|32
end_define

begin_comment
comment|/* Value doesn't matter. */
end_comment

begin_include
include|#
directive|include
file|"libaout.h"
end_include

begin_include
include|#
directive|include
file|"aout/aout64.h"
end_include

begin_comment
comment|/* Ignore duplicate stab codes; just return the string for the first    one.  */
end_comment

begin_define
define|#
directive|define
name|__define_stab
parameter_list|(
name|NAME
parameter_list|,
name|CODE
parameter_list|,
name|STRING
parameter_list|)
value|__define_name(CODE, STRING)
end_define

begin_define
define|#
directive|define
name|__define_stab_duplicate
parameter_list|(
name|NAME
parameter_list|,
name|CODE
parameter_list|,
name|STRING
parameter_list|)
end_define

begin_comment
comment|/* These are not really stab symbols, but it is    convenient to have them here for the sake of nm.    For completeness, we could also add N_TEXT etc, but those    are never needed, since nm treats those specially. */
end_comment

begin_define
define|#
directive|define
name|EXTRA_SYMBOLS
define|\
value|__define_name (N_SETA, "SETA")
comment|/* Absolute set element symbol */
value|\   __define_name (N_SETT, "SETT")
comment|/* Text set element symbol */
value|\   __define_name (N_SETD, "SETD")
comment|/* Data set element symbol */
value|\   __define_name (N_SETB, "SETB")
comment|/* Bss set element symbol */
value|\   __define_name (N_SETV, "SETV")
comment|/* Pointer to set vector in data area. */
value|\   __define_name (N_INDR, "INDR") \   __define_name (N_WARNING, "WARNING")
end_define

begin_function
specifier|const
name|char
modifier|*
name|bfd_get_stab_name
parameter_list|(
name|code
parameter_list|)
name|int
name|code
decl_stmt|;
block|{
switch|switch
condition|(
name|code
condition|)
block|{
define|#
directive|define
name|__define_name
parameter_list|(
name|val
parameter_list|,
name|str
parameter_list|)
value|case val: return str;
include|#
directive|include
file|"aout/stab.def"
name|EXTRA_SYMBOLS
block|}
return|return
operator|(
specifier|const
name|char
operator|*
operator|)
literal|0
return|;
block|}
end_function

end_unit

