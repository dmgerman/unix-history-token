begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* timespec -- System time interface     Copyright (C) 2000, 2002, 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|TIMESPEC_H
end_if

begin_define
define|#
directive|define
name|TIMESPEC_H
end_define

begin_comment
comment|/* You must include config.h before including this file.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|TIME_WITH_SYS_TIME
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_SYS_TIME_H
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_STRUCT_TIMESPEC
end_if

begin_comment
comment|/* Some systems don't define this struct, e.g., AIX 4.1, Ultrix 4.3.  */
end_comment

begin_struct
struct|struct
name|timespec
block|{
name|time_t
name|tv_sec
decl_stmt|;
name|long
name|tv_nsec
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ST_MTIM_NSEC
end_ifdef

begin_define
define|#
directive|define
name|ST_TIME_CMP_NS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|ns
parameter_list|)
value|((a).ns< (b).ns ? -1 : (a).ns> (b).ns)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ST_TIME_CMP_NS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|ns
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ST_TIME_CMP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|s
parameter_list|,
name|ns
parameter_list|)
define|\
value|((a).s< (b).s ? -1 : (a).s> (b).s ? 1 : ST_TIME_CMP_NS(a, b, ns))
end_define

begin_define
define|#
directive|define
name|ATIME_CMP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ST_TIME_CMP (a, b, st_atime, st_atim.ST_MTIM_NSEC)
end_define

begin_define
define|#
directive|define
name|CTIME_CMP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ST_TIME_CMP (a, b, st_ctime, st_ctim.ST_MTIM_NSEC)
end_define

begin_define
define|#
directive|define
name|MTIME_CMP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ST_TIME_CMP (a, b, st_mtime, st_mtim.ST_MTIM_NSEC)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ST_MTIM_NSEC
end_ifdef

begin_define
define|#
directive|define
name|TIMESPEC_NS
parameter_list|(
name|timespec
parameter_list|)
value|((timespec).ST_MTIM_NSEC)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TIMESPEC_NS
parameter_list|(
name|timespec
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_NANOSLEEP
end_if

begin_comment
comment|/* Don't specify a prototype here.  Some systems (e.g., OSF) declare    nanosleep with a conflicting one (const-less first parameter).  */
end_comment

begin_function_decl
name|int
name|nanosleep
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|gettime
parameter_list|(
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|settime
parameter_list|(
name|struct
name|timespec
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

