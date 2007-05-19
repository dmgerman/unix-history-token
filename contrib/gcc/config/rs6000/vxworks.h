begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Vxworks PowerPC version.    Copyright (C) 1996, 2000, 2002, 2003, 2004, 2005    Free Software Foundation, Inc.    Contributed by CodeSourcery, LLC.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Note to future editors: VxWorks is mostly an EABI target.  We do    not use rs6000/eabi.h because we would have to override most of    it anyway.  However, if you change that file, consider making    analogous changes here too.  */
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
value|fprintf (stderr, " (PowerPC VxWorks)");
end_define

begin_comment
comment|/* CPP predefined macros.  */
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
value|do						\     {						\       builtin_define ("__ppc");			\       builtin_define ("__EABI__");		\       builtin_define ("__ELF__");		\       builtin_define ("__vxworks");		\       builtin_define ("__VXWORKS__");		\       if (!TARGET_SOFT_FLOAT)			\ 	builtin_define ("__hardfp");		\ 						\
comment|/* C89 namespace violation! */
value|\       builtin_define ("CPU_FAMILY=PPC");	\     }						\   while (0)
end_define

begin_comment
comment|/* Only big endian PPC is supported by VxWorks.  */
end_comment

begin_undef
undef|#
directive|undef
name|BYTES_BIG_ENDIAN
end_undef

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|1
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

begin_comment
comment|/* FIXME: The only reason we allow no -mcpu switch at all is because    config-ml.in insists on a "." multilib. */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
define|\
value|"%{!DCPU=*:		  \    %{mcpu=403 : -DCPU=PPC403  ; \      mcpu=405 : -DCPU=PPC405  ; \      mcpu=440 : -DCPU=PPC440  ; \      mcpu=603 : -DCPU=PPC603  ; \      mcpu=604 : -DCPU=PPC604  ; \      mcpu=860 : -DCPU=PPC860  ; \      mcpu=8540: -DCPU=PPC85XX ; \               : -DCPU=PPC604  }}" \ VXWORKS_ADDITIONAL_CPP_SPEC
end_define

begin_define
define|#
directive|define
name|CC1_SPEC
define|\
value|"%{G*} %{mno-sdata:-msdata=none} %{msdata:-msdata=default}	\  %{mlittle|mlittle-endian:-mstrict-align}			\  %{profile: -p}		\  %{fvec:-maltivec} %{fvec-eabi:-maltivec -mabi=altivec}"
end_define

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%(asm_cpu) \  %{.s: %{mregnames} %{mno-regnames}} %{.S: %{mregnames} %{mno-regnames}} \  %{v:-v} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Yd,*} %{Wa,*:%*} \  %{mrelocatable} %{mrelocatable-lib} %{fpic:-K PIC} %{fPIC:-K PIC} -mbig"
end_define

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|VXWORKS_LIB_SPEC
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|VXWORKS_LINK_SPEC
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
value|VXWORKS_STARTFILE_SPEC
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
value|VXWORKS_ENDFILE_SPEC
end_define

begin_comment
comment|/* There is no default multilib.  */
end_comment

begin_undef
undef|#
directive|undef
name|MULTILIB_DEFAULTS
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
define|\
value|(MASK_POWERPC | MASK_NEW_MNEMONICS | MASK_EABI | MASK_STRICT_ALIGN)
end_define

begin_undef
undef|#
directive|undef
name|PROCESSOR_DEFAULT
end_undef

begin_define
define|#
directive|define
name|PROCESSOR_DEFAULT
value|PROCESSOR_PPC604
end_define

begin_comment
comment|/* Nor sdata, for kernel mode.  We use this in    SUBSUBTARGET_INITIALIZE_OPTIONS, after rs6000_rtp has been initialized.  */
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
value|(TARGET_VXWORKS_RTP ? 8 : 0)
end_define

begin_undef
undef|#
directive|undef
name|STACK_BOUNDARY
end_undef

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|(16*BITS_PER_UNIT)
end_define

begin_comment
comment|/* Override sysv4.h, reset to the default.  */
end_comment

begin_undef
undef|#
directive|undef
name|PREFERRED_STACK_BOUNDARY
end_undef

begin_comment
comment|/* Enable SPE */
end_comment

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

begin_comment
comment|/* Make -mcpu=8540 imply SPE.  ISEL is automatically enabled, the    others must be done by hand.  Handle -mrtp.  Disable -fPIC    for -mrtp - the VxWorks PIC model is not compatible with it.  */
end_comment

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
value|do {						\     if (TARGET_E500)				\       {						\ 	rs6000_spe = 1;				\ 	rs6000_spe_abi = 1;			\ 	rs6000_float_gprs = 1;			\       }						\ 						\   if (!g_switch_set)				\     g_switch_value = SDATA_DEFAULT_SIZE;	\   VXWORKS_OVERRIDE_OPTIONS;			\   } while (0)
end_define

begin_comment
comment|/* No _mcount profiling on VxWorks.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
value|VXWORKS_FUNCTION_PROFILER(FILE,LABELNO)
end_define

end_unit

