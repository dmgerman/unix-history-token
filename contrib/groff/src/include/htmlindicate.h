begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 2000, 2001 Free Software Foundation, Inc.      Written by Gaius Mulley<gaius@glam.ac.uk>  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HTMLINDICATE_H
end_ifndef

begin_define
define|#
directive|define
name|HTMLINDICATE_H
end_define

begin_comment
comment|/*  *  graphic_start - emit a html graphic start indicator, but only  *                  if one has not already been issued.  *  *                  The boolean, is_inline, should be:  *  *                  FALSE if this is called via EQ, TS, PS, and  *                  TRUE if issued via delim $$  $ x over y $ etc.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|graphic_start
parameter_list|(
name|int
name|is_inline
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  graphic_end - emit a html graphic end indicator, but only  *                if a corresponding matching graphic-start has  *                been issued.  *  */
end_comment

begin_function_decl
specifier|extern
name|void
name|graphic_end
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  *  html_begin_suppress - suppresses output for the html device  *                        and resets the min/max registers for -Tps  *  *                        The boolean, is_inline, should be:  *  *                        FALSE if this is called via EQ, TS, PS, and  *                        TRUE if issued via delim $$  $ x over y $ etc.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|html_begin_suppress
parameter_list|(
name|int
name|is_inline
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  html_end_suppress - end the suppression of output.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|html_end_suppress
parameter_list|(
name|int
name|is_inline
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

