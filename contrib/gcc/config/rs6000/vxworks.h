begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Vxworks PowerPC version.    Copyright (C) 1996, 2000, 2002, 2003 Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 59 Temple Place - Suite 330, Boston,    MA 02111-1307, USA.  */
end_comment

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
value|do						\     {						\       builtin_define ("__vxworks");		\       builtin_define ("__vxworks__");		\     }						\   while (0)
end_define

begin_comment
comment|/* We have to kill off the entire specs set created by rs6000/sysv4.h    and substitute our own set.  The top level vxworks.h has done some    of this for us.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_SPECS
end_undef

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
end_define

begin_comment
comment|/* none needed */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
define|\
value|"-DCPU_FAMILY=PPC -D__ppc -D__EABI__  \  %{t403: -DCPU=PPC403 -D_SOFT_FLOAT ; \    t405: -DCPU=PPC405 -D_SOFT_FLOAT ; \    t440: -DCPU=PPC440 -D_SOFT_FLOAT ; \    t603: -DCPU=PPC603               ; \    t604: -DCPU=PPC604               ; \    t860: -DCPU=PPC860 -D_SOFT_FLOAT ; \        : -DCPU=PPC604}  \  %{!msoft-float:-D__hardfp}	   \  %{fpic|fpie: -D__PIC__=1 -D__pic__=1 ; \    fPIC|fPIE: -D__PIC__=2 -D__pic__=2 } \  %(cpp_cpu)"
end_define

begin_define
define|#
directive|define
name|CC1_SPEC
define|\
value|"%{t403: -mcpu=403 -mstrict-align ;				\    t405: -mcpu=405 -mstrict-align ;				\    t440: -mcpu=440 -mstrict-align ;				\    t603: -mcpu=603 -mstrict-align ;				\    t604: -mcpu=604 -mstrict-align ;				\    t860: -mcpu=860                ;                             \        : -mcpu=604 -mstrict-align }				\  %{G*} %{mno-sdata:-msdata=none} %{msdata:-msdata=default}	\  %{mlittle|mlittle-endian:-mstrict-align}			\  %{profile: -p}							\  %{fvec:-maltivec} %{fvec-eabi:-maltivec -mabi=altivec}"
end_define

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%(asm_cpu) \ %{.s: %{mregnames} %{mno-regnames}} %{.S: %{mregnames} %{mno-regnames}} \ %{v:-V} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Yd,*} %{Wa,*:%*} \ %{mrelocatable} %{mrelocatable-lib} %{fpic:-K PIC} %{fPIC:-K PIC} -mbig"
end_define

begin_undef
undef|#
directive|undef
name|MULTILIB_DEFAULTS
end_undef

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "t604" }
end_define

begin_comment
comment|/* We can't use .ctors/.dtors sections.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_ASM_OUTPUT_CONSTRUCTOR
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_ASM_OUTPUT_DESTRUCTOR
end_undef

begin_comment
comment|/* Nor sdata.  */
end_comment

begin_undef
undef|#
directive|undef
name|SDATA_DEFAULT_SIZE
end_undef

begin_define
define|#
directive|define
name|SDATA_DEFAULT_SIZE
value|0
end_define

end_unit

