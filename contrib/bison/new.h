begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Storage allocation interface for bison,    Copyright (C) 1984, 1989 Free Software Foundation, Inc.  This file is part of Bison, the GNU Compiler Compiler.  Bison is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  Bison is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with Bison; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|NEW
parameter_list|(
name|t
parameter_list|)
value|((t *) xmalloc((unsigned) sizeof(t)))
end_define

begin_define
define|#
directive|define
name|NEW2
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|)
value|((t *) xmalloc((unsigned) ((n) * sizeof(t))))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|x
parameter_list|)
value|(x ? (void) free((char *) (x)) : (void)0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|x
parameter_list|)
value|((x) != 0&& (free ((char *) (x)), 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|xrealloc
parameter_list|()
function_decl|;
end_function_decl

end_unit

