begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Thread package specific definitions of stream lock type.    Copyright (C) 1996, 1997 Free Software Foundation, Inc.    This file is part of the GNU C Library.     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with the GNU C Library; see the file COPYING.LIB.  If not,    write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBIO_LOCK_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBIO_LOCK_H
value|1
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
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
value|NULL
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
end_define

begin_define
define|#
directive|define
name|_IO_cleanup_region_end
parameter_list|(
name|_doit
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_IO_lock_init
parameter_list|(
name|_name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_IO_lock_fini
parameter_list|(
name|_name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_IO_lock_lock
parameter_list|(
name|_name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_IO_lock_unlock
parameter_list|(
name|_name
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* libio-lock.h */
end_comment

begin_comment
comment|/* this will be used later*/
end_comment

end_unit

