begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent definitions for Intel 386 running the GNU Hurd    Copyright 1994, 1995, 1996, 2002 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_I386GNU_H
end_ifndef

begin_define
define|#
directive|define
name|NM_I386GNU_H
end_define

begin_comment
comment|/* Include common definitions for GNU systems.  */
end_comment

begin_include
include|#
directive|include
file|"config/nm-gnu.h"
end_include

begin_comment
comment|/* Thread flavors used in re-setting the T bit.  */
end_comment

begin_define
define|#
directive|define
name|THREAD_STATE_FLAVOR
value|i386_REGS_SEGS_STATE
end_define

begin_define
define|#
directive|define
name|THREAD_STATE_SIZE
value|i386_THREAD_STATE_COUNT
end_define

begin_define
define|#
directive|define
name|THREAD_STATE_SET_TRACED
parameter_list|(
name|state
parameter_list|)
define|\
value|((struct i386_thread_state *) (state))->efl |= 0x100
end_define

begin_define
define|#
directive|define
name|THREAD_STATE_CLEAR_TRACED
parameter_list|(
name|state
parameter_list|)
define|\
value|((((struct i386_thread_state *) (state))->efl&= ~0x100), 1)
end_define

begin_comment
comment|/* We can attach and detach.  */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* nm-i386gnu.h */
end_comment

end_unit

