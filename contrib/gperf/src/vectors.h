begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Static class data members that are shared between several classes via    inheritance.     Copyright (C) 1989-1998 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|vectors_h
end_ifndef

begin_define
define|#
directive|define
name|vectors_h
value|1
end_define

begin_decl_stmt
specifier|static
specifier|const
name|int
name|MAX_ALPHA_SIZE
init|=
literal|256
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|Vectors
block|{
specifier|static
name|int
name|ALPHA_SIZE
decl_stmt|;
comment|/* Size of alphabet. */
specifier|static
name|int
name|occurrences
index|[
name|MAX_ALPHA_SIZE
index|]
decl_stmt|;
comment|/* Counts occurrences of each key set character. */
specifier|static
name|int
name|asso_values
index|[
name|MAX_ALPHA_SIZE
index|]
decl_stmt|;
comment|/* Value associated with each character. */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

