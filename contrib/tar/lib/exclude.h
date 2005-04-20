begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* exclude.h -- declarations for excluding file names    Copyright 1992, 1993, 1994, 1997, 1999, 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert<eggert@twinsun.com>  */
end_comment

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

begin_comment
comment|/* Exclude options, which can be ORed with fnmatch options.  */
end_comment

begin_comment
comment|/* Patterns must match the start of file names, instead of matching    anywhere after a '/'.  */
end_comment

begin_define
define|#
directive|define
name|EXCLUDE_ANCHORED
value|(1<< 5)
end_define

begin_comment
comment|/* Include instead of exclude.  */
end_comment

begin_define
define|#
directive|define
name|EXCLUDE_INCLUDE
value|(1<< 6)
end_define

begin_comment
comment|/* '?', '*', '[', and '\\' are special in patterns.  Without this    option, these characters are ordinary and fnmatch is not used.  */
end_comment

begin_define
define|#
directive|define
name|EXCLUDE_WILDCARDS
value|(1<< 7)
end_define

begin_struct_decl
struct_decl|struct
name|exclude
struct_decl|;
end_struct_decl

begin_decl_stmt
name|struct
name|exclude
modifier|*
name|new_exclude
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_exclude
name|PARAMS
argument_list|(
operator|(
expr|struct
name|exclude
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|add_exclude
name|PARAMS
argument_list|(
operator|(
expr|struct
name|exclude
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|add_exclude_file
name|PARAMS
argument_list|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|exclude
operator|*
argument_list|,
name|char
specifier|const
operator|*
argument_list|,
name|int
argument_list|)
operator|,
expr|struct
name|exclude
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|int
operator|,
name|char
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|excluded_filename
name|PARAMS
argument_list|(
operator|(
expr|struct
name|exclude
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

