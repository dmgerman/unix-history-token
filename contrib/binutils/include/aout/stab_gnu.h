begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gnu_stab.h  Definitions for GNU extensions to STABS     Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNU_STAB__
end_ifndef

begin_comment
comment|/* Indicate the GNU stab.h is in use.  */
end_comment

begin_define
define|#
directive|define
name|__GNU_STAB__
end_define

begin_define
define|#
directive|define
name|__define_stab
parameter_list|(
name|NAME
parameter_list|,
name|CODE
parameter_list|,
name|STRING
parameter_list|)
value|NAME=CODE,
end_define

begin_define
define|#
directive|define
name|__define_stab_duplicate
parameter_list|(
name|NAME
parameter_list|,
name|CODE
parameter_list|,
name|STRING
parameter_list|)
value|NAME=CODE,
end_define

begin_enum
enum|enum
name|__stab_debug_code
block|{
include|#
directive|include
file|"aout/stab.def"
name|LAST_UNUSED_STAB_CODE
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|__define_stab
end_undef

begin_comment
comment|/* Definitions of "desc" field for N_SO stabs in Solaris2.  */
end_comment

begin_define
define|#
directive|define
name|N_SO_AS
value|1
end_define

begin_define
define|#
directive|define
name|N_SO_C
value|2
end_define

begin_define
define|#
directive|define
name|N_SO_ANSI_C
value|3
end_define

begin_define
define|#
directive|define
name|N_SO_CC
value|4
end_define

begin_comment
comment|/* C++ */
end_comment

begin_define
define|#
directive|define
name|N_SO_FORTRAN
value|5
end_define

begin_define
define|#
directive|define
name|N_SO_PASCAL
value|6
end_define

begin_comment
comment|/* Solaris2: Floating point type values in basic types.  */
end_comment

begin_define
define|#
directive|define
name|NF_NONE
value|0
end_define

begin_define
define|#
directive|define
name|NF_SINGLE
value|1
end_define

begin_comment
comment|/* IEEE 32-bit */
end_comment

begin_define
define|#
directive|define
name|NF_DOUBLE
value|2
end_define

begin_comment
comment|/* IEEE 64-bit */
end_comment

begin_define
define|#
directive|define
name|NF_COMPLEX
value|3
end_define

begin_comment
comment|/* Fortran complex */
end_comment

begin_define
define|#
directive|define
name|NF_COMPLEX16
value|4
end_define

begin_comment
comment|/* Fortran double complex */
end_comment

begin_define
define|#
directive|define
name|NF_COMPLEX32
value|5
end_define

begin_comment
comment|/* Fortran complex*16 */
end_comment

begin_define
define|#
directive|define
name|NF_LDOUBLE
value|6
end_define

begin_comment
comment|/* Long double (whatever that is) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNU_STAB_ */
end_comment

end_unit

