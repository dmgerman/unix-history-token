begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m- file for Sony's NEWS workstations, NEWS-OS 3.0.    Copyright (C) 1985, 1986, 1989 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Say this machine is a 68000 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|m68000
end_ifndef

begin_define
define|#
directive|define
name|m68000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The following three symbols give information on  the size of various data types.  */
end_comment

begin_define
define|#
directive|define
name|SHORTBITS
value|16
end_define

begin_comment
comment|/* Number of bits in a short */
end_comment

begin_define
define|#
directive|define
name|INTBITS
value|32
end_define

begin_comment
comment|/* Number of bits in an int */
end_comment

begin_define
define|#
directive|define
name|LONGBITS
value|32
end_define

begin_comment
comment|/* Number of bits in a long */
end_comment

begin_comment
comment|/* 68000 has lowest-numbered byte as most significant */
end_comment

begin_define
define|#
directive|define
name|BIG_ENDIAN
end_define

begin_comment
comment|/* One CRT0 Dummy variable */
end_comment

begin_define
define|#
directive|define
name|CRT0_DUMMIES
value|one_dummy,
end_define

begin_comment
comment|/* Define how to take a char and sign-extend into an int.    On machines where char is signed, this is a no-op.  */
end_comment

begin_define
define|#
directive|define
name|SIGN_EXTEND_CHAR
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_comment
comment|/* Use type int rather than a union, to represent Lisp_Object */
end_comment

begin_define
define|#
directive|define
name|NO_UNION_TYPE
end_define

begin_comment
comment|/* The News machine has alloca. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_comment
comment|/* Data type of load average, as read out of kmem.  */
end_comment

begin_define
define|#
directive|define
name|LOAD_AVE_TYPE
value|double
end_define

begin_comment
comment|/* Convert that into an integer that is 100 for a load average of 1.0  */
end_comment

begin_define
define|#
directive|define
name|LOAD_AVE_CVT
parameter_list|(
name|x
parameter_list|)
value|((int) ((x) * 100.0))
end_define

begin_comment
comment|/* Must use the system's termcap.  It does special things.  */
end_comment

begin_define
define|#
directive|define
name|LIBS_TERMCAP
value|-ltermcap
end_define

end_unit

