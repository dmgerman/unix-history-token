begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tcap.h -- termcap library functions and variables. */
end_comment

begin_comment
comment|/* Copyright (C) 1996 Free Software Foundation, Inc.     This file contains the Readline Library (the Library), a set of    routines for providing Emacs style line input to programs that ask    for it.     The Library is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     The Library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_RLTCAP_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_RLTCAP_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CONFIG_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TERMCAP_H
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SPEED_T_IN_SYS_TYPES
argument_list|)
end_if

begin_include
include|#
directive|include
file|"rltty.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<termcap.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* On Solaris2, sys/types.h #includes sys/reg.h, which #defines PC.    Unfortunately, PC is a global variable used by the termcap library. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC
end_ifdef

begin_undef
undef|#
directive|undef
name|PC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
name|PC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|UP
decl_stmt|,
modifier|*
name|BC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|ospeed
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|tgetent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tgetflag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tgetnum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|tgetstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tputs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|tgoto
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TERMCAP_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RLTCAP_H_ */
end_comment

end_unit

