begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Thread package specific definitions of stream lock type.    Copyright (C) 1996, 1997 Free Software Foundation, Inc.    This file is part of the GNU C Library.     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with the GNU C Library; see the file COPYING.LIB.  If not,    write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_typedef
typedef|typedef
name|pthread_mutex_t
name|_IO_lock_t
typedef|;
end_typedef

begin_comment
comment|/* We need recursive (counting) mutexes.  */
end_comment

begin_define
define|#
directive|define
name|_IO_lock_initializer
value|PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
end_define

begin_define
define|#
directive|define
name|_IO_cleanup_region_start
parameter_list|(
name|_fct
parameter_list|,
name|_fp
parameter_list|)
define|\
value|__libc_cleanup_region_start (_fct, _fp)
end_define

begin_define
define|#
directive|define
name|_IO_cleanup_region_end
parameter_list|(
name|_doit
parameter_list|)
define|\
value|__libc_cleanup_region_end (_doit)
end_define

begin_define
define|#
directive|define
name|_IO_lock_init
parameter_list|(
name|_name
parameter_list|)
define|\
value|__libc_lock_init_recursive (_name)
end_define

begin_define
define|#
directive|define
name|_IO_lock_fini
parameter_list|(
name|_name
parameter_list|)
define|\
value|__libc_lock_fini_recursive (_name)
end_define

end_unit

