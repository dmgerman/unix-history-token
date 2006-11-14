begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* man.h: Defines and external function declarations for man.c.    $Id: man.h,v 1.3 2004/04/11 17:56:46 karl Exp $     This file is part of GNU Info, a program for reading online documentation    stored in Info format.     Copyright (C) 1993, 1997, 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Author: Brian J. Fox (bfox@ai.mit.edu) Sat May  6 16:19:13 1995. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFO_MAN_H
end_ifndef

begin_define
define|#
directive|define
name|INFO_MAN_H
end_define

begin_define
define|#
directive|define
name|MANPAGE_FILE_BUFFER_NAME
value|"*manpages*"
end_define

begin_function_decl
specifier|extern
name|NODE
modifier|*
name|make_manpage_node
parameter_list|(
name|char
modifier|*
name|pagename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|NODE
modifier|*
name|get_manpage_node
parameter_list|(
name|FILE_BUFFER
modifier|*
name|file_buffer
parameter_list|,
name|char
modifier|*
name|pagename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE_BUFFER
modifier|*
name|create_manpage_file_buffer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|locate_manpage_xref
parameter_list|(
name|NODE
modifier|*
name|node
parameter_list|,
name|long
name|int
name|start
parameter_list|,
name|int
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|REFERENCE
modifier|*
modifier|*
name|xrefs_of_manpage
parameter_list|(
name|NODE
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|REFERENCE
modifier|*
modifier|*
name|manpage_xrefs_in_binding
parameter_list|(
name|NODE
modifier|*
name|node
parameter_list|,
name|SEARCH_BINDING
modifier|*
name|binding
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INFO_MAN_H */
end_comment

end_unit

