begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* profile.h - Defines data exported from profile.c to other passes.    Copyright (C) 1998, 1999, 2000, 2001 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_PROFILE_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_PROFILE_H
end_define

begin_struct
struct|struct
name|profile_info
block|{
comment|/* Used by final, for allocating the proper amount of storage for the        instrumented arc execution counts.  */
name|int
name|count_instrumented_edges
decl_stmt|;
comment|/* Used by final, for writing correct # of instrumented edges        in this function.  */
name|int
name|count_edges_instrumented_now
decl_stmt|;
comment|/* Checksum of the cfg. Used for 'identification' of code.        Used by final.  */
name|long
name|current_function_cfg_checksum
decl_stmt|;
comment|/* Max. value of counter in program corresponding to the profile data        for the current function.  */
name|gcov_type
name|max_counter_in_program
decl_stmt|;
comment|/* The number of profiles merged to form the profile data for the current        function.  */
name|int
name|count_profiles_merged
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|profile_info
name|profile_info
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

