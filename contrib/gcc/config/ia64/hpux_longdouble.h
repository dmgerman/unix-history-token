begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of long double support for GNU compiler.    Copyright (C) 2000, 2001 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Tell real.c that we are not using INTEL_EXTENDED_IEEE_FORMAT */
end_comment

begin_undef
undef|#
directive|undef
name|INTEL_EXTENDED_IEEE_FORMAT
end_undef

begin_define
define|#
directive|define
name|INTEL_EXTENDED_IEEE_FORMAT
value|0
end_define

begin_comment
comment|/* Define library calls for quad FP operations.  These are all part of the    IA32 and IA64 ABIs.  */
end_comment

begin_define
define|#
directive|define
name|ADDTF3_LIBCALL
value|"_U_Qfadd"
end_define

begin_define
define|#
directive|define
name|SUBTF3_LIBCALL
value|"_U_Qfsub"
end_define

begin_define
define|#
directive|define
name|MULTF3_LIBCALL
value|"_U_Qfmpy"
end_define

begin_define
define|#
directive|define
name|DIVTF3_LIBCALL
value|"_U_Qfdiv"
end_define

begin_define
define|#
directive|define
name|NEGTF2_LIBCALL
value|"_U_Qfneg"
end_define

begin_define
define|#
directive|define
name|ABSTF2_LIBCALL
value|"_U_Qfabs"
end_define

begin_define
define|#
directive|define
name|SMINTF3_LIBCALL
value|"_U_Qfmin"
end_define

begin_define
define|#
directive|define
name|SMAXTF3_LIBCALL
value|"_U_Qfmax"
end_define

begin_define
define|#
directive|define
name|EXTENDSFTF2_LIBCALL
value|"_U_Qfcnvff_sgl_to_quad"
end_define

begin_define
define|#
directive|define
name|EXTENDDFTF2_LIBCALL
value|"_U_Qfcnvff_dbl_to_quad"
end_define

begin_define
define|#
directive|define
name|TRUNCTFSF2_LIBCALL
value|"_U_Qfcnvff_quad_to_sgl"
end_define

begin_define
define|#
directive|define
name|TRUNCTFDF2_LIBCALL
value|"_U_Qfcnvff_quad_to_dbl"
end_define

begin_define
define|#
directive|define
name|FLOATSITF2_LIBCALL
value|"_U_Qfcnvxf_sgl_to_quad"
end_define

begin_define
define|#
directive|define
name|FLOATDITF2_LIBCALL
value|"_U_Qfcnvxf_dbl_to_quad"
end_define

begin_define
define|#
directive|define
name|FIX_TRUNCTFSI2_LIBCALL
value|"_U_Qfcnvfxt_quad_to_sgl"
end_define

begin_define
define|#
directive|define
name|FIX_TRUNCTFDI2_LIBCALL
value|"_U_Qfcnvfxt_quad_to_dbl"
end_define

begin_define
define|#
directive|define
name|EQTF2_LIBCALL
value|"_U_Qfeq"
end_define

begin_define
define|#
directive|define
name|NETF2_LIBCALL
value|"_U_Qfne"
end_define

begin_define
define|#
directive|define
name|GTTF2_LIBCALL
value|"_U_Qfgt"
end_define

begin_define
define|#
directive|define
name|GETF2_LIBCALL
value|"_U_Qfge"
end_define

begin_define
define|#
directive|define
name|LTTF2_LIBCALL
value|"_U_Qflt"
end_define

begin_define
define|#
directive|define
name|LETF2_LIBCALL
value|"_U_Qfle"
end_define

begin_undef
undef|#
directive|undef
name|INIT_TARGET_OPTABS
end_undef

begin_define
define|#
directive|define
name|INIT_TARGET_OPTABS
define|\
value|do {									\     add_optab->handlers[(int) TFmode].libfunc				\       = gen_rtx_SYMBOL_REF (Pmode, ADDTF3_LIBCALL);			\     sub_optab->handlers[(int) TFmode].libfunc				\       = gen_rtx_SYMBOL_REF (Pmode, SUBTF3_LIBCALL);			\     smul_optab->handlers[(int) TFmode].libfunc				\       = gen_rtx_SYMBOL_REF (Pmode, MULTF3_LIBCALL);			\     sdiv_optab->handlers[(int) TFmode].libfunc				\       = gen_rtx_SYMBOL_REF (Pmode, DIVTF3_LIBCALL);			\     smin_optab->handlers[(int) TFmode].libfunc				\       = gen_rtx_SYMBOL_REF (Pmode, SMINTF3_LIBCALL);			\     smax_optab->handlers[(int) TFmode].libfunc				\       = gen_rtx_SYMBOL_REF (Pmode, SMAXTF3_LIBCALL);			\     abs_optab->handlers[(int) TFmode].libfunc				\       = gen_rtx_SYMBOL_REF (Pmode, ABSTF2_LIBCALL);			\     neg_optab->handlers[(int) TFmode].libfunc				\       = gen_rtx_SYMBOL_REF (Pmode, NEGTF2_LIBCALL);			\     extendsftf2_libfunc = gen_rtx_SYMBOL_REF (Pmode, EXTENDSFTF2_LIBCALL); \     extenddftf2_libfunc = gen_rtx_SYMBOL_REF (Pmode, EXTENDDFTF2_LIBCALL); \     trunctfsf2_libfunc = gen_rtx_SYMBOL_REF (Pmode, TRUNCTFSF2_LIBCALL); \     trunctfdf2_libfunc = gen_rtx_SYMBOL_REF (Pmode, TRUNCTFDF2_LIBCALL); \     floatsitf_libfunc = gen_rtx_SYMBOL_REF (Pmode, FLOATSITF2_LIBCALL);  \     floatditf_libfunc = gen_rtx_SYMBOL_REF (Pmode, FLOATDITF2_LIBCALL);  \     fixtfsi_libfunc = gen_rtx_SYMBOL_REF (Pmode, FIX_TRUNCTFSI2_LIBCALL);\     fixtfdi_libfunc = gen_rtx_SYMBOL_REF (Pmode, FIX_TRUNCTFDI2_LIBCALL);\     fixunstfsi_libfunc = gen_rtx_SYMBOL_REF (Pmode, FIX_TRUNCTFSI2_LIBCALL);  \     fixunstfdi_libfunc = gen_rtx_SYMBOL_REF (Pmode, FIX_TRUNCTFDI2_LIBCALL);  \     eqtf2_libfunc = gen_rtx_SYMBOL_REF (Pmode, EQTF2_LIBCALL);		\     netf2_libfunc = gen_rtx_SYMBOL_REF (Pmode, NETF2_LIBCALL);		\     gttf2_libfunc = gen_rtx_SYMBOL_REF (Pmode, GTTF2_LIBCALL);		\     getf2_libfunc = gen_rtx_SYMBOL_REF (Pmode, GETF2_LIBCALL);		\     lttf2_libfunc = gen_rtx_SYMBOL_REF (Pmode, LTTF2_LIBCALL);		\     letf2_libfunc = gen_rtx_SYMBOL_REF (Pmode, LETF2_LIBCALL);		\ 									\   sdiv_optab->handlers[(int) SImode].libfunc = 0;                       \   udiv_optab->handlers[(int) SImode].libfunc = 0;                       \   smod_optab->handlers[(int) SImode].libfunc = 0;                       \   umod_optab->handlers[(int) SImode].libfunc = 0;                       \ 									\     INIT_SUBTARGET_OPTABS;						\   } while (0)
end_define

begin_comment
comment|/* This is meant to be redefined in the host dependent files */
end_comment

begin_define
define|#
directive|define
name|INIT_SUBTARGET_OPTABS
end_define

begin_comment
comment|/* Nonzero if a floating point comparison library call for    mode MODE that will return a boolean value.  Zero if one    of the libgcc2 functions is used.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_LIB_COMPARE_RETURNS_BOOL
parameter_list|(
name|MODE
parameter_list|,
name|COMPARISON
parameter_list|)
value|((MODE) == TFmode)
end_define

end_unit

