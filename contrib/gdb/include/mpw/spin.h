begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Progress macros that use SpinCursor in MPW.    Copyright (C) 1994 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPIN_H
end_ifndef

begin_define
define|#
directive|define
name|_SPIN_H
end_define

begin_comment
comment|/* For MPW, progress macros just need to "spin the cursor" frequently,    preferably several times per second on a 68K Mac.  */
end_comment

begin_comment
comment|/* In order to determine if we're meeting the goal, define this macro    and information about frequency of spinning will be collected and    displayed.  */
end_comment

begin_define
define|#
directive|define
name|SPIN_MEASUREMENT
end_define

begin_include
include|#
directive|include
file|<CursorCtl.h>
end_include

begin_comment
comment|/* Programs use this macro to indicate the start of a lengthy    activity.  STR identifies the particular activity, while N    indicates the expected duration, in unspecified units.  If N is    zero, then the expected time to completion is unknown.  */
end_comment

begin_undef
undef|#
directive|undef
name|START_PROGRESS
end_undef

begin_define
define|#
directive|define
name|START_PROGRESS
parameter_list|(
name|STR
parameter_list|,
name|N
parameter_list|)
value|mpw_start_progress (STR, N, __FILE__, __LINE__);
end_define

begin_comment
comment|/* Programs use this macro to indicate that progress has been made on a    lengthy activity.  */
end_comment

begin_undef
undef|#
directive|undef
name|PROGRESS
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|SPIN_MEASUREMENT
end_ifdef

begin_define
define|#
directive|define
name|PROGRESS
parameter_list|(
name|X
parameter_list|)
value|mpw_progress_measured (X, __FILE__, __LINE__);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROGRESS
parameter_list|(
name|X
parameter_list|)
value|mpw_progress (X);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Programs use this macro to indicate the end of a lengthy activity.    STR must match a STR passed to START_PROGRESS previously.  */
end_comment

begin_undef
undef|#
directive|undef
name|END_PROGRESS
end_undef

begin_define
define|#
directive|define
name|END_PROGRESS
parameter_list|(
name|STR
parameter_list|)
value|mpw_end_progress (STR, __FILE__, __LINE__);
end_define

begin_function_decl
specifier|extern
name|void
name|mpw_start_progress
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mpw_progress
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mpw_progress_measured
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mpw_end_progress
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SPIN_H */
end_comment

end_unit

