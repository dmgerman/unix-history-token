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

begin_enum
enum|enum
name|cmap_builtin
block|{
name|CMAP_BUILTIN
block|}
enum|;
end_enum

begin_decl_stmt
name|class
name|cmap
block|{
name|public
label|:
name|cmap
argument_list|()
expr_stmt|;
name|cmap
argument_list|(
name|cmap_builtin
argument_list|)
expr_stmt|;
name|int
name|operator
argument_list|()
operator|(
name|unsigned
name|char
operator|)
specifier|const
expr_stmt|;
name|unsigned
name|char
modifier|&
name|operator
function_decl|[]
parameter_list|(
name|unsigned
name|char
parameter_list|)
function_decl|;
name|friend
name|class
name|cmap_init
decl_stmt|;
name|private
label|:
name|unsigned
name|char
name|v
index|[
name|UCHAR_MAX
operator|+
literal|1
index|]
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|int
name|cmap
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
name|unsigned
name|char
operator|&
name|cmap
operator|::
name|operator
index|[]
operator|(
name|unsigned
name|char
name|c
operator|)
block|{
return|return
name|v
index|[
name|c
index|]
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|extern
name|cmap
name|cmlower
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cmap
name|cmupper
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|class
name|cmap_init
block|{
specifier|static
name|int
name|initialised
decl_stmt|;
name|public
label|:
name|cmap_init
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|_cmap_init
expr_stmt|;
end_expr_stmt

end_unit

