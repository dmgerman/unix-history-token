begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU C-compiler for PC532 running Minix    Copyright (C) 1987,1990 Free Software Foundation, Inc.    Contributed by Jyrki Kuoppala<jkp@cs.hut.fi>, August 1990  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* We have USG-style include files and time functions */
end_comment

begin_define
define|#
directive|define
name|USG
end_define

begin_include
include|#
directive|include
file|"xm-ns32k.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HZ
end_ifndef

begin_define
define|#
directive|define
name|HZ
value|60
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

