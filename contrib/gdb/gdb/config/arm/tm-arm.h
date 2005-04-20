begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to target GDB to ARM targets.    Copyright 1986, 1987, 1988, 1989, 1991, 1993, 1994, 1995, 1996, 1997,    1998, 1999, 2000, 2001, 2002 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_ARM_H
end_ifndef

begin_define
define|#
directive|define
name|TM_ARM_H
end_define

begin_define
define|#
directive|define
name|GDB_MULTI_ARCH
value|1
end_define

begin_comment
comment|/* Specify that for the native compiler variables for a particular    lexical context are listed after the beginning LBRAC instead of    before in the executables list of symbols.  */
end_comment

begin_define
define|#
directive|define
name|VARIABLES_INSIDE_BLOCK
parameter_list|(
name|desc
parameter_list|,
name|gcc_p
parameter_list|)
value|(!(gcc_p))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_ARM_H */
end_comment

end_unit

