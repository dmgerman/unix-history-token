begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define machine-dependencies for bison,    Copyright (C) 1984, 1989 Free Software Foundation, Inc.  This file is part of Bison, the GNU Compiler Compiler.  Bison is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  Bison is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with Bison; see the file COPYING.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|eta10
end_ifdef

begin_define
define|#
directive|define
name|MAXSHORT
value|2147483647
end_define

begin_define
define|#
directive|define
name|MINSHORT
value|-2147483648
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXSHORT
value|32767
end_define

begin_define
define|#
directive|define
name|MINSHORT
value|-32768
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GO32__
argument_list|)
end_if

begin_define
define|#
directive|define
name|BITS_PER_WORD
value|16
end_define

begin_define
define|#
directive|define
name|MAXTABLE
value|16383
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BITS_PER_WORD
value|32
end_define

begin_define
define|#
directive|define
name|MAXTABLE
value|32767
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WORDSIZE
parameter_list|(
name|n
parameter_list|)
value|(((n) + BITS_PER_WORD - 1) / BITS_PER_WORD)
end_define

begin_define
define|#
directive|define
name|SETBIT
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
value|((x)[(i)/BITS_PER_WORD] |= (1<<((i) % BITS_PER_WORD)))
end_define

begin_define
define|#
directive|define
name|RESETBIT
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
value|((x)[(i)/BITS_PER_WORD]&= ~(1<<((i) % BITS_PER_WORD)))
end_define

begin_define
define|#
directive|define
name|BITISSET
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
value|(((x)[(i)/BITS_PER_WORD]& (1<<((i) % BITS_PER_WORD))) != 0)
end_define

end_unit

