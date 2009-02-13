begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Support for GCC on MIPS using WindISS simulator.    Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.    Contributed by CodeSourcery, LLC.   This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (MIPS WindISS)");
end_define

begin_comment
comment|/* Combination of mips.h and svr4.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|(DEFAULT_SWITCH_TAKES_ARG (CHAR)      \    || (CHAR) == 'G'                     \    || (CHAR) == 'h'                     \    || (CHAR) == 'x'                     \    || (CHAR) == 'z')
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_CPP_SPEC
define|\
value|"%{!DCPU=*: %{mips3|mips4|mips64:-DCPU=MIPS64;:-DCPU=MIPS32}} \   %{EL|mel:-DMIPSEL;:-DMIPSEB} \   %{msoft-float:-DSOFT_FLOAT} \   %{mips1:-D_WRS_R3K_EXC_SUPPORT}"
end_define

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"\ %{!G:-G 0} %{G*} %(endian_spec) %{mips1} %{mips2} %{mips3} %{mips4} \ %{mips32} %{mips32r2} %{mips64} \ %{mips16:%{!mno-mips16:-mips16}} %{mno-mips16:-no-mips16} \ %(subtarget_asm_optimizing_spec) \ %(subtarget_asm_debugging_spec) \ %{mabi=*} %{!mabi*: %(asm_abi_default_spec)} \ %{mgp32} %{mgp64} %{march=*} %{mxgot:-xgot} \ %{mtune=*} %{v} \ %(subtarget_asm_spec)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_comment
comment|/* LINK_SPEC is clobbered in svr4.h. ugh!  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"\ -m elf32mipswindiss \ %{!G:-G 0} %{G*} %{mips1} %{mips2} %{mips3} %{mips4} %{mips32} %{mips64} \ %{bestGnum}"
end_define

begin_comment
comment|/* Diab libs MIPS{,E,F,L,M,W,X,Y,Z}{,H,N,S}        .    E - Elf (small-data/const=8    F - Elf Far (small-data/const=0)    L - Little Elf    M - Little Elf Far    W - elf32 bigmips    X - elf32 bigmips (far?)    Y - elf32 littlemips    Z - elf32 littlemips (far?)     . - Integer routines    H - Hard float    N - No float    S - Soft float     Want {F,M}{,H,S}  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"--start-group -li -lcfp -lwindiss -lram -limpl -limpfp --end-group"
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"crt0.o%s crtbegin.o%s"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|"crtend.o%s"
end_define

begin_comment
comment|/* We have no shared libraries.  These two shouldn't be necessary.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SHLIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SHLIB_SPEC
value|""
end_define

begin_undef
undef|#
directive|undef
name|LINK_EH_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_EH_SPEC
value|""
end_define

begin_undef
undef|#
directive|undef
name|CRTSAVRES_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CRTSAVRES_DEFAULT_SPEC
value|""
end_define

begin_comment
comment|/* No sdata.  */
end_comment

begin_undef
undef|#
directive|undef
name|MIPS_DEFAULT_GVALUE
end_undef

begin_define
define|#
directive|define
name|MIPS_DEFAULT_GVALUE
value|0
end_define

end_unit

