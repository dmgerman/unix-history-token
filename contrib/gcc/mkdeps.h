begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Dependency generator for Makefile fragments.    Copyright (C) 2000, 2001 Free Software Foundation, Inc.    Contributed by Zack Weinberg, Mar 2000  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.   In other words, you are welcome to use, share and improve this program.  You are forbidden to forbid anyone else to use, share and improve  what you give them.   Help stamp out software-hoarding!  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_MKDEPS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_MKDEPS_H
end_define

begin_comment
comment|/* This is the data structure used by all the functions in mkdeps.c.    It's quite straightforward, but should be treated as opaque.  */
end_comment

begin_struct_decl
struct_decl|struct
name|deps
struct_decl|;
end_struct_decl

begin_comment
comment|/* Create a deps buffer.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|deps
modifier|*
name|deps_init
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Destroy a deps buffer.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|deps_free
name|PARAMS
argument_list|(
operator|(
expr|struct
name|deps
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add a target (appears on left side of the colon) to the deps list.  Takes    a boolean indicating whether to quote the target for MAKE.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|deps_add_target
name|PARAMS
argument_list|(
operator|(
expr|struct
name|deps
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sets the default target if none has been given already.  An empty    string as the default target in interpreted as stdin.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|deps_add_default_target
name|PARAMS
argument_list|(
operator|(
expr|struct
name|deps
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add a dependency (appears on the right side of the colon) to the    deps list.  Dependencies will be printed in the order that they    were entered with this function.  By convention, the first    dependency entered should be the primary source file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|deps_add_dep
name|PARAMS
argument_list|(
operator|(
expr|struct
name|deps
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write out a deps buffer to a specified file.  The third argument    is the number of columns to word-wrap at (0 means don't wrap).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|deps_write
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|deps
operator|*
operator|,
name|FILE
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For each dependency *except the first*, emit a dummy rule for that    file, causing it to depend on nothing.  This is used to work around    the intermediate-file deletion misfeature in Make, in some    automatic dependency schemes.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|deps_phony_targets
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|deps
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_MKDEPS_H */
end_comment

end_unit

