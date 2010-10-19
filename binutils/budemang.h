begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* demangle.h -- A wrapper calling libiberty cplus_demangle    Copyright 2002, 2003 Free Software Foundation, Inc.     This file is part of GNU Binutils.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUDEMANG_H
end_ifndef

begin_define
define|#
directive|define
name|BUDEMANG_H
end_define

begin_function_decl
name|char
modifier|*
name|demangle
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

