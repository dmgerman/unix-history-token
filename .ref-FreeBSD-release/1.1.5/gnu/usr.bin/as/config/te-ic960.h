begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is twe-ic960.h     Copyright (C) 1987-1992 Free Software Foundation, Inc.        This file is part of GAS, the GNU Assembler.        GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.        GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * This file is te-ic960.h and is intended to define ic960 environment  * specific differences.  */
end_comment

begin_define
define|#
directive|define
name|TE_IC960
value|1
end_define

begin_comment
comment|/* intel uses host byte order for headers */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CROSS_COMPILE
end_ifdef

begin_undef
undef|#
directive|undef
name|CROSS_COMPILE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CROSS_COMPILE */
end_comment

begin_define
define|#
directive|define
name|OBJ_COFF_OMIT_OPTIONAL_HEADER
end_define

begin_define
define|#
directive|define
name|LOCAL_LABEL
parameter_list|(
name|name
parameter_list|)
value|( (name[0] == 'L') \ 			   || (name[0] == '.' \&& (name[1] == 'C' || name[1] == 'I' || name[1] == '.')))
end_define

begin_include
include|#
directive|include
file|"obj-format.h"
end_include

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of te-ic960.h */
end_comment

end_unit

