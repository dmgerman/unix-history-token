begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Default definitions for progress macros.    Copyright 1994 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* The default definitions below are intended to be replaced by real    definitions, if building the tools for an interactive programming    environment.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PROGRESS_H
end_ifndef

begin_define
define|#
directive|define
name|_PROGRESS_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|START_PROGRESS
end_ifndef

begin_define
define|#
directive|define
name|START_PROGRESS
parameter_list|(
name|STR
parameter_list|,
name|N
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PROGRESS
end_ifndef

begin_define
define|#
directive|define
name|PROGRESS
parameter_list|(
name|X
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|END_PROGRESS
end_ifndef

begin_define
define|#
directive|define
name|END_PROGRESS
parameter_list|(
name|STR
parameter_list|)
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
comment|/* _PROGRESS_H */
end_comment

end_unit

