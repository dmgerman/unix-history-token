begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent definitions for Intel 386 running NetBSD, for GDB.    Copyright 1986, 1987, 1989, 1992, 1994 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_NBSD_H
end_ifndef

begin_define
define|#
directive|define
name|NM_NBSD_H
end_define

begin_comment
comment|/* Get generic NetBSD native definitions. */
end_comment

begin_include
include|#
directive|include
file|"nm-nbsd.h"
end_include

begin_comment
comment|/* #define FLOAT_INFO	{ i386_float_info(); } */
end_comment

begin_define
define|#
directive|define
name|REGISTER_U_ADDR
parameter_list|(
name|addr
parameter_list|,
name|blockend
parameter_list|,
name|regno
parameter_list|)
define|\
value|(addr) = i386_register_u_addr ((blockend),(regno));
end_define

begin_decl_stmt
specifier|extern
name|int
name|i386_register_u_addr
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NM_NBSD_H */
end_comment

end_unit

