begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CC_LIMITS_H
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_CC_LIMITS_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UCHAR_MAX
end_ifndef

begin_define
define|#
directive|define
name|UCHAR_MAX
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_CC_LIMITS_H */
end_comment

begin_enum
enum|enum
name|cset_builtin
block|{
name|CSET_BUILTIN
block|}
enum|;
end_enum

begin_decl_stmt
name|class
name|cset
block|{
name|public
label|:
name|cset
argument_list|()
expr_stmt|;
name|cset
argument_list|(
name|cset_builtin
argument_list|)
expr_stmt|;
name|cset
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
name|cset
argument_list|(
argument|const unsigned char *
argument_list|)
empty_stmt|;
name|int
name|operator
argument_list|()
operator|(
name|unsigned
name|char
operator|)
specifier|const
expr_stmt|;
name|cset
operator|&
name|operator
operator||=
operator|(
specifier|const
name|cset
operator|&
operator|)
expr_stmt|;
name|cset
operator|&
name|operator
operator||=
operator|(
name|unsigned
name|char
operator|)
expr_stmt|;
name|friend
name|class
name|cset_init
decl_stmt|;
name|private
label|:
name|char
name|v
index|[
name|UCHAR_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|int
name|cset
operator|::
name|operator
argument_list|()
operator|(
name|unsigned
name|char
name|c
operator|)
specifier|const
block|{
return|return
name|v
index|[
name|c
index|]
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|cset
operator|&
name|cset
operator|::
name|operator
operator||=
operator|(
name|unsigned
name|char
name|c
operator|)
block|{
name|v
index|[
name|c
index|]
operator|=
literal|1
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|extern
name|cset
name|csalpha
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cset
name|csupper
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cset
name|cslower
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cset
name|csdigit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cset
name|csxdigit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cset
name|csspace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cset
name|cspunct
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cset
name|csalnum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cset
name|csprint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cset
name|csgraph
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cset
name|cscntrl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|class
name|cset_init
block|{
specifier|static
name|int
name|initialised
decl_stmt|;
name|public
label|:
name|cset_init
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|_cset_init
expr_stmt|;
end_expr_stmt

end_unit

