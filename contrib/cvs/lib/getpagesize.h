begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Emulation of getpagesize() for systems that need it.    Copyright (C) 1991 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_UNISTD_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_SC_PAGESIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|sysconf(_SC_PAGESIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_SC_PAGE_SIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|sysconf(_SC_PAGE_SIZE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SC_PAGE_SIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SC_PAGESIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|getpagesize
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PAGESIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|PAGESIZE
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !PAGESIZE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EXEC_PAGESIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|EXEC_PAGESIZE
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !EXEC_PAGESIZE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NBPG
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CLSIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|CLSIZE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !CLSIZE */
end_comment

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|(NBPG * CLSIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !NBPG */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NBPC
argument_list|)
end_if

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|NBPC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NBPC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NBPG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !EXEC_PAGESIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !PAGESIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !getpagesize */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|getpagesize
argument_list|)
end_if

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|4096
end_define

begin_comment
comment|/* Just punt and use reasonable value */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

