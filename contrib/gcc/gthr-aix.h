begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Threads compatibility routines for libgcc2 and libobjc.  */
end_comment

begin_comment
comment|/* Compile this one with gcc.  */
end_comment

begin_comment
comment|/* Copyright (C) 2000 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files,    some of which are compiled with GCC, to produce an executable,    this library does not by itself cause the resulting executable    to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_GTHR_AIX_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_GTHR_AIX_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_THREAD_SAFE
end_ifdef

begin_include
include|#
directive|include
file|"gthr-posix.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"gthr-single.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_GTHR_AIX_H */
end_comment

end_unit

