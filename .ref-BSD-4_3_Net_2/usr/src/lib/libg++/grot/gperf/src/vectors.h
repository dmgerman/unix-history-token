begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Static class data members that are shared between several classes via    inheritance.     Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_struct
struct|struct
name|Vectors
block|{
specifier|const
name|int
name|ALPHA_SIZE
init|=
literal|128
decl_stmt|;
specifier|static
name|int
name|occurrences
index|[
name|ALPHA_SIZE
index|]
decl_stmt|;
comment|/* Counts occurrences of each key set character. */
specifier|static
name|int
name|asso_values
index|[
name|ALPHA_SIZE
index|]
decl_stmt|;
comment|/* Value associated with each character. */
block|}
struct|;
end_struct

end_unit

