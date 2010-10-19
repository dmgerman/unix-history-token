begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* te-sun3.h -- Sun-3 target environment declarations.    Copyright 1987, 1990, 1991, 1992, 2000, 2003    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_comment
comment|/* This header file contains the #defines specific    to SUN computer SUN 3 series computers.  (The only kind    we have around here, unfortunately.)     Rumor has it that this file will work on the Sun-2 if the assembler    is called with -m68010  This is not tested.  */
end_comment

begin_define
define|#
directive|define
name|TE_SUN3
value|1
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_DOLLAR
value|1
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_comment
comment|/* Could also be :    #define S_LOCAL_NAME(s)	(S_GET_NAME(s)[0] == '.'&&    S_GET_NAME(s)[1] == 'L' ||    S_GET_NAME(s)[1] == '.')    */
end_comment

begin_include
include|#
directive|include
file|"obj-format.h"
end_include

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of te-sun3.h */
end_comment

end_unit

