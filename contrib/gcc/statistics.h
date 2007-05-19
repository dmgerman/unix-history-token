begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Memory statistics helpers.    Copyright (C) 2004    Free Software Foundation, Inc.    Contributed by Cygnus Solutions.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_STATISTICS
end_ifndef

begin_define
define|#
directive|define
name|GCC_STATISTICS
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GATHER_STATISTICS
end_ifdef

begin_define
define|#
directive|define
name|MEM_STAT_DECL
value|, const char * ARG_UNUSED (_loc_name), int ARG_UNUSED (_loc_line), const char * ARG_UNUSED (_loc_function)
end_define

begin_define
define|#
directive|define
name|PASS_MEM_STAT
value|, _loc_name, _loc_line,  _loc_function
end_define

begin_define
define|#
directive|define
name|MEM_STAT_INFO
value|, __FILE__, __LINE__, __FUNCTION__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MEM_STAT_DECL
end_define

begin_define
define|#
directive|define
name|PASS_MEM_STAT
end_define

begin_define
define|#
directive|define
name|MEM_STAT_INFO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

