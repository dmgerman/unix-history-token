begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Core target definitions for GNU compiler    for IBM RS/6000 PowerPC targeted to embedded ELF systems.    Copyright (C) 1995, 1996, 2000, 2003 Free Software Foundation, Inc.    Contributed by Cygnus Support.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 59 Temple Place - Suite 330, Boston,    MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Add -meabi to target flags.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_POWERPC | MASK_NEW_MNEMONICS | MASK_EABI)
end_define

begin_comment
comment|/* Invoke an initializer function to set up the GOT.  */
end_comment

begin_define
define|#
directive|define
name|NAME__MAIN
value|"__eabi"
end_define

begin_define
define|#
directive|define
name|INVOKE__main
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (PowerPC Embedded)");
end_define

begin_undef
undef|#
directive|undef
name|TARGET_OS_CPP_BUILTINS
end_undef

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do                                      \     {                                     \       builtin_define_std ("PPC");         \       builtin_define ("__embedded__");    \       builtin_assert ("system=embedded"); \       builtin_assert ("cpu=powerpc");     \       builtin_assert ("machine=powerpc"); \       TARGET_OS_SYSV_CPP_BUILTINS ();     \     }                                     \   while (0)
end_define

begin_undef
undef|#
directive|undef
name|TARGET_SPE_ABI
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_SPE
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_E500
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_ISEL
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_FPRS
end_undef

begin_define
define|#
directive|define
name|TARGET_SPE_ABI
value|rs6000_spe_abi
end_define

begin_define
define|#
directive|define
name|TARGET_SPE
value|rs6000_spe
end_define

begin_define
define|#
directive|define
name|TARGET_E500
value|(rs6000_cpu == PROCESSOR_PPC8540)
end_define

begin_define
define|#
directive|define
name|TARGET_ISEL
value|rs6000_isel
end_define

begin_define
define|#
directive|define
name|TARGET_FPRS
value|(!rs6000_float_gprs)
end_define

end_unit

