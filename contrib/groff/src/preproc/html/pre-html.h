begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 2000, 2001 Free Software Foundation, Inc.      Written by Gaius Mulley (gaius@glam.ac.uk).  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_comment
comment|/*  *  defines functions implemented within pre-html.c  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PREHTMLH
argument_list|)
end_if

begin_define
define|#
directive|define
name|PREHTMLH
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PREHTMLC
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXTERN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|sys_fatal
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|EXTERN
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

