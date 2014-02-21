begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Core target definitions for GNU compiler    for PowerPC embedded targeted systems with SPE support.    Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.    Contributed by Aldy Hernandez (aldyh@redhat.com).     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
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
value|(MASK_POWERPC | MASK_NEW_MNEMONICS | MASK_EABI	\   | MASK_STRICT_ALIGN)
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
value|fprintf (stderr, " (PowerPC Embedded SPE)");
end_define

begin_undef
undef|#
directive|undef
name|SUBSUBTARGET_OVERRIDE_OPTIONS
end_undef

begin_define
define|#
directive|define
name|SUBSUBTARGET_OVERRIDE_OPTIONS
define|\
value|if (rs6000_select[1].string == NULL) \     rs6000_cpu = PROCESSOR_PPC8540; \   if (!rs6000_explicit_options.abi) \     rs6000_spe_abi = 1; \   if (!rs6000_explicit_options.float_gprs) \     rs6000_float_gprs = 1; \
comment|/* See note below.  */
value|\
comment|/*if (!rs6000_explicit_options.long_double)*/
value|\
comment|/*  rs6000_long_double_type_size = 128;*/
value|\   if (!rs6000_explicit_options.spe) \     rs6000_spe = 1; \   if (!rs6000_explicit_options.isel) \     rs6000_isel = 1; \   if (target_flags& MASK_64BIT) \     error ("-m64 not supported in this configuration")
end_define

begin_comment
comment|/* The e500 ABI says that either long doubles are 128 bits, or if    implemented in any other size, the compiler/linker should error out.    We have no emulation libraries for 128 bit long doubles, and I hate    the dozens of failures on the regression suite.  So I'm breaking ABI    specifications, until I properly fix the emulation.     Enable these later. #undef CPP_LONGDOUBLE_DEFAULT_SPEC #define CPP_LONGDOUBLE_DEFAULT_SPEC "-D__LONG_DOUBLE_128__=1" */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_DEFAULT_SPEC
value|"-mppc -mspe -me500"
end_define

end_unit

