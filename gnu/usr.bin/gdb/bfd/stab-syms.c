begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Table of stab names for the BFD library.    Copyright (C) 1990-1991 Free Software Foundation, Inc.    Written by Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
comment|/* Create a table of debugging stab-codes and corresponding names.  */
end_comment

begin_define
define|#
directive|define
name|__define_name
parameter_list|(
name|CODE
parameter_list|,
name|STRING
parameter_list|)
value|{(int)CODE, STRING},
end_define

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

begin_macro
name|CONST
end_macro

begin_struct
struct|struct
block|{
name|short
name|code
decl_stmt|;
name|char
name|string
index|[
literal|10
index|]
decl_stmt|;
block|}
name|aout_stab_names
index|[]
init|=
block|{
include|#
directive|include
file|"aout/stab.def"
comment|/* These are not really stab symbols, but it is    convenient to have them here for the sake of nm.    For completeness, we could also add N_TEXT etc, but those    are never needed, since nm treats those specially. */
name|__define_name
argument_list|(
argument|N_SETA
argument_list|,
literal|"SETA"
argument_list|)
comment|/* Absolute set element symbol */
name|__define_name
argument_list|(
argument|N_SETT
argument_list|,
literal|"SETT"
argument_list|)
comment|/* Text set element symbol */
name|__define_name
argument_list|(
argument|N_SETD
argument_list|,
literal|"SETD"
argument_list|)
comment|/* Data set element symbol */
name|__define_name
argument_list|(
argument|N_SETB
argument_list|,
literal|"SETB"
argument_list|)
comment|/* Bss set element symbol */
name|__define_name
argument_list|(
argument|N_SETV
argument_list|,
literal|"SETV"
argument_list|)
comment|/* Pointer to set vector in data area. */
name|__define_name
argument_list|(
argument|N_INDR
argument_list|,
literal|"INDR"
argument_list|)
name|__define_name
argument_list|(
argument|N_WARNING
argument_list|,
literal|"WARNING"
argument_list|)
block|}
struct|;
end_struct

begin_undef
undef|#
directive|undef
name|__define_stab
end_undef

begin_undef
undef|#
directive|undef
name|GNU_EXTRA_STABS
end_undef

begin_decl_stmt
name|CONST
name|char
modifier|*
name|DEFUN
argument_list|(
name|aout_stab_name
argument_list|,
operator|(
name|code
operator|)
argument_list|,
name|int
name|code
argument_list|)
block|{
specifier|register
name|int
name|i
init|=
sizeof|sizeof
argument_list|(
name|aout_stab_names
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|aout_stab_names
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
while|while
condition|(
operator|--
name|i
operator|>=
literal|0
condition|)
if|if
condition|(
name|aout_stab_names
index|[
name|i
index|]
operator|.
name|code
operator|==
name|code
condition|)
return|return
name|aout_stab_names
index|[
name|i
index|]
operator|.
name|string
return|;
return|return
literal|0
return|;
block|}
end_decl_stmt

end_unit

