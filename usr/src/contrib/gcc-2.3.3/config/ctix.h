begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    Convergent Technologies MiniFrame version,    using GAS and binutils with COFF encapsulation.     Written by Ronald Cole     Because the MiniFrame's C compiler is so completely lobotomized,    bootstrapping this is damn near impossible!    Write to me for information on obtaining the binaries...     bug reports to csusac!unify!rjc@ucdavis.edu     Copyright (C) 1990 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"3b1g.h"
end_include

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dmc68000 -Dmc68k -Dunix -Dctix"
end_define

begin_comment
comment|/* Where to look for robotussinized startfiles.  */
end_comment

begin_undef
undef|#
directive|undef
name|STANDARD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|STANDARD_STARTFILE_PREFIX
value|"/usr/local/lib/gnu/"
end_define

begin_comment
comment|/* Generate calls to the MiniFrame's library (for speed).  */
end_comment

begin_define
define|#
directive|define
name|DIVSI3_LIBCALL
value|"ldiv"
end_define

begin_define
define|#
directive|define
name|UDIVSI3_LIBCALL
value|"uldiv"
end_define

begin_define
define|#
directive|define
name|MODSI3_LIBCALL
value|"lrem"
end_define

begin_define
define|#
directive|define
name|UMODSI3_LIBCALL
value|"ulrem"
end_define

begin_define
define|#
directive|define
name|MULSI3_LIBCALL
value|"lmul"
end_define

begin_define
define|#
directive|define
name|UMULSI3_LIBCALL
value|"ulmul"
end_define

end_unit

