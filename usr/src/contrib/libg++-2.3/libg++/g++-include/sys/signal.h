begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1989 Free Software Foundation     written by Doug Lea (dl@rocky.oswego.edu)  This file is part of the GNU C++ Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details. You should have received a copy of the GNU Library General Public License along with this library; if not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_comment
comment|/* Partly for systems that think signal.h is is sys/ */
end_comment

begin_comment
comment|/* But note that some systems that use sys/signal.h to define signal.h. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__libgxx_sys_signal_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__sys_signal_h_recursive
end_ifdef

begin_empty
empty|#include_next<sys/signal.h>
end_empty

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__sys_signal_h_recursive
end_define

begin_extern
extern|extern
literal|"C"
block|{
define|#
directive|define
name|signal
value|__hide_signal
empty|#include_next<sys/signal.h>
undef|#
directive|undef
name|signal
block|}
end_extern

begin_define
define|#
directive|define
name|__libgxx_sys_signal_h
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

