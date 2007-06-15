begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Reentrant time functions like localtime_r.     Copyright (C) 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TIME_R_H
end_ifndef

begin_define
define|#
directive|define
name|_TIME_R_H
end_define

begin_comment
comment|/* Include<time.h> first, since it may declare these functions with    signatures that disagree with POSIX, and we don't want to rename    those declarations.  */
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_if
if|#
directive|if
operator|!
name|HAVE_TIME_R_POSIX
end_if

begin_undef
undef|#
directive|undef
name|asctime_r
end_undef

begin_undef
undef|#
directive|undef
name|ctime_r
end_undef

begin_undef
undef|#
directive|undef
name|gmtime_r
end_undef

begin_undef
undef|#
directive|undef
name|localtime_r
end_undef

begin_define
define|#
directive|define
name|asctime_r
value|rpl_asctime_r
end_define

begin_define
define|#
directive|define
name|ctime_r
value|rpl_ctime_r
end_define

begin_define
define|#
directive|define
name|gmtime_r
value|rpl_gmtime_r
end_define

begin_define
define|#
directive|define
name|localtime_r
value|rpl_localtime_r
end_define

begin_function_decl
name|char
modifier|*
name|asctime_r
parameter_list|(
name|struct
name|tm
specifier|const
modifier|*
specifier|restrict
parameter_list|,
name|char
modifier|*
specifier|restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ctime_r
parameter_list|(
name|time_t
specifier|const
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tm
modifier|*
name|gmtime_r
parameter_list|(
name|time_t
specifier|const
modifier|*
specifier|restrict
parameter_list|,
name|struct
name|tm
modifier|*
specifier|restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tm
modifier|*
name|localtime_r
parameter_list|(
name|time_t
specifier|const
modifier|*
specifier|restrict
parameter_list|,
name|struct
name|tm
modifier|*
specifier|restrict
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

