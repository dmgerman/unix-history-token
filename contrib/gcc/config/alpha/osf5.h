begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for DEC Alpha on Tru64 5.    Copyright (C) 2000, 2001 Free Software Foundation, Inc.     This file is part of GNU CC.     GNU CC is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GNU CC is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GNU CC; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_comment
comment|/* Tru64 UNIX V5 has a 16 byte long double type and requires __X_FLOAT to be    defined to get the appropriate prototypes for the long double functions    in<math.h>.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_XFLOAT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_XFLOAT_SPEC
value|"-D__X_FLOAT"
end_define

begin_comment
comment|/* In Tru64 UNIX V5.1, Compaq introduced a new assembler    (/usr/lib/cmplrs/cc/adu) which currently (versions between 3.04.29 and    3.04.32) breaks mips-tfile.  Passing the undocumented -oldas flag reverts    to using the old assembler (/usr/lib/cmplrs/cc/as[01]).     The V5.0 and V5.0A assemblers silently ignore -oldas, so it can be    specified here.     It is clearly not desirable to depend on this undocumented flag, and    Compaq wants -oldas to go away soon, but until they have released a    new adu that works with mips-tfile, this is the only option.     In some versions of the DTK, the assembler driver invokes ld after    assembly.  This has been fixed in current versions, but adding -c    works as expected for all versions.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OLDAS_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_OLDAS_SPEC
value|"-oldas -c"
end_define

begin_comment
comment|/* The linker appears to perform invalid code optimizations that result    in the ldgp emitted for the exception_receiver pattern being incorrectly    linked.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_LD_BUGGY_LDGP
end_undef

begin_define
define|#
directive|define
name|TARGET_LD_BUGGY_LDGP
value|1
end_define

end_unit

