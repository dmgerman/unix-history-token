begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Emulation of getpagesize() for systems that need it.    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  NAME  	getpagesize -- return the number of bytes in page of memory  SYNOPSIS  	int getpagesize (void)  DESCRIPTION  	Returns the number of bytes in a page of memory.  This is the 	granularity of many of the system memory management routines. 	No guarantee is made as to whether or not it is the same as the 	basic memory management hardware page size.  BUGS  	Is intended as a reasonable replacement for systems where this 	is not provided as a system call.  The value of 4096 may or may 	not be correct for the systems where it is returned as the default 	value.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYSCONF
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_define
define|#
directive|define
name|GNU_OUR_PAGESIZE
value|sysconf(_SC_PAGESIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|PAGESIZE
end_ifdef

begin_define
define|#
directive|define
name|GNU_OUR_PAGESIZE
value|PAGESIZE
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no PAGESIZE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EXEC_PAGESIZE
end_ifdef

begin_define
define|#
directive|define
name|GNU_OUR_PAGESIZE
value|EXEC_PAGESIZE
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no EXEC_PAGESIZE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NBPG
end_ifdef

begin_define
define|#
directive|define
name|GNU_OUR_PAGESIZE
value|(NBPG * CLSIZE)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CLSIZE
end_ifndef

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
comment|/* CLSIZE */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no NBPG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NBPC
end_ifdef

begin_define
define|#
directive|define
name|GNU_OUR_PAGESIZE
value|NBPC
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no NBPC */
end_comment

begin_define
define|#
directive|define
name|GNU_OUR_PAGESIZE
value|4096
end_define

begin_comment
comment|/* Just punt and use reasonable value */
end_comment

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
comment|/* NBPG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EXEC_PAGESIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PAGESIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYSCONF */
end_comment

begin_function
name|int
name|getpagesize
parameter_list|()
block|{
return|return
operator|(
name|GNU_OUR_PAGESIZE
operator|)
return|;
block|}
end_function

end_unit

