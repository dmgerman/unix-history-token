begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU compiler    for an DEC/Compaq Alpha    Copyright (C) 1999, 2001 Free Software Foundation, Inc.    Donn Terry, Softway Systems, Inc.      derived from code by Douglas B. Rupp (drupp@cs.washington.edu)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BITS_PER_WIDE_INT
value|64
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|HOST_WIDE_INT
value|long long
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOST_WIDE_INT
value|__int64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HOST_BITS_PER_WIDEST_INT
value|HOST_BITS_PER_LONGLONG
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|HOST_WIDEST_INT
value|long long
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOST_WIDEST_INT
value|__int64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_DEC
value|"%lld"
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_UNSIGNED
value|"%llu"
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_HEX
value|"0x%llx"
end_define

end_unit

