begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Machine specific defines for the PA machine    Copyright 1987, 1991, 1992, 1993, 1995, 2000    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_comment
comment|/* HP PA-RISC and OSF/1 support was contributed by the Center for 	Software Science at the University of Utah.  */
end_comment

begin_comment
comment|/* Labels are not required to have a colon for a suffix.  */
end_comment

begin_define
define|#
directive|define
name|LABELS_WITHOUT_COLONS
value|1
end_define

begin_comment
comment|/* These define interfaces.  */
end_comment

begin_include
include|#
directive|include
file|"obj-format.h"
end_include

end_unit

