begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASSERT_H
end_ifndef

begin_define
define|#
directive|define
name|ASSERT_H
end_define

begin_function_decl
name|void
name|assertion_failed
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|inline
name|void
name|do_assert
parameter_list|(
name|int
name|expr
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|)
block|{
if|if
condition|(
operator|!
name|expr
condition|)
name|assertion_failed
argument_list|(
name|line
argument_list|,
name|file
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASSERT_H */
end_comment

begin_undef
undef|#
directive|undef
name|assert
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|NDEBUG
end_ifdef

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|ignore
parameter_list|)
end_define

begin_comment
comment|/* as nothing */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|expr
parameter_list|)
value|do_assert(expr, __LINE__, __FILE__)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

