begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ho-hpux.h -- Header to compile the assembler under HP-UX    Copyright (C) 1988, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"ho-sysv.h"
end_include

begin_comment
comment|/* This header file contains the #defines specific    to HPUX changes sent me by cph@zurich.ai.mit.edu */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|hpux
end_ifndef

begin_define
define|#
directive|define
name|hpux
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|setbuffer
end_ifdef

begin_undef
undef|#
directive|undef
name|setbuffer
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* setbuffer */
end_comment

begin_define
define|#
directive|define
name|setbuffer
parameter_list|(
name|stream
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|)
end_define

begin_comment
comment|/* end of ho-hpux.h */
end_comment

end_unit

