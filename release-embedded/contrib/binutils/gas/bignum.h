begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bignum.h-arbitrary precision integers    Copyright 1987, 1992, 2003, 2005 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/***********************************************************************\  *									*  *	Arbitrary-precision integer arithmetic.				*  *	For speed, we work in groups of bits, even though this		*  *	complicates algorithms.						*  *	Each group of bits is called a 'littlenum'.			*  *	A bunch of littlenums representing a (possibly large)		*  *	integer is called a 'bignum'.					*  *	Bignums are>= 0.						*  *									*  \***********************************************************************/
end_comment

begin_define
define|#
directive|define
name|LITTLENUM_NUMBER_OF_BITS
value|(16)
end_define

begin_define
define|#
directive|define
name|LITTLENUM_RADIX
value|(1<< LITTLENUM_NUMBER_OF_BITS)
end_define

begin_define
define|#
directive|define
name|LITTLENUM_MASK
value|(0xFFFF)
end_define

begin_define
define|#
directive|define
name|LITTLENUM_SHIFT
value|(1)
end_define

begin_define
define|#
directive|define
name|CHARS_PER_LITTLENUM
value|(1<< LITTLENUM_SHIFT)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BITS_PER_CHAR
end_ifndef

begin_define
define|#
directive|define
name|BITS_PER_CHAR
value|(8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|short
name|LITTLENUM_TYPE
typedef|;
end_typedef

end_unit

