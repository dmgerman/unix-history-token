begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to host GDB on an IBM RT/PC running BSD Unix.     Copyright 1986, 1987, 1989, 1991, 1992  Free Software Foundation, Inc.    Contributed by David Wood @ New York University (wood@lab.ultra.nyu.edu).  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Get rid of any system-imposed stack limit if possible.  */
end_comment

begin_define
define|#
directive|define
name|SET_STACK_LIMIT_HUGE
end_define

begin_comment
comment|/* This machine is most significant byte first */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* This OS has the wait structure */
end_comment

begin_define
define|#
directive|define
name|HAVE_WAIT_STRUCT
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HOSTING_ONLY
end_ifdef

begin_comment
comment|/*  * This next two defines are to get GDB up and running as a host to  * do remote debugging.  I know there is a gdb for the RT, but there wasn't  * an xconfig/rt* file.    */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR_BSD
end_define

begin_comment
comment|/* This may be correct, but hasn't been tested */
end_comment

begin_define
define|#
directive|define
name|REGISTER_U_ADDR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|(printf("GDB can not debug IBM RT/PC BSD executables (yet)\n"),\ 	quit(),0)
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"GDB for the RT is not included in the distribution"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

