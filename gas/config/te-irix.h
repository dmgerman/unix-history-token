begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* IRIX targets    Copyright 2002, 2003 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_comment
comment|/* This file is te-irix.h and is intended to provide support for    IRIX targets.  Created by Alexandre Oliva<aoliva@redhat.com>.  */
end_comment

begin_define
define|#
directive|define
name|TE_IRIX
value|1
end_define

begin_comment
comment|/* these define interfaces */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_HEADER
end_ifdef

begin_include
include|#
directive|include
include|OBJ_HEADER
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"obj-format.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

