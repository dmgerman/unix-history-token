begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Frv map GCC names to FR-V ABI.    Copyright (C) 2000 Free Software Foundation, Inc.    Contributed by Red Hat, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* For each of the functions in the library that has a corresponding name in    the ABI, add an equivalence between the GCC name and the ABI name.  This is    in a separate file from frv.h so that fp-bit.c can be made to include it.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__FRV_UNDERSCORE__
end_ifdef

begin_define
define|#
directive|define
name|RENAME_LIBRARY
parameter_list|(
name|OLD
parameter_list|,
name|NEW
parameter_list|)
define|\
value|__asm__ (".globl\t_" #NEW "\n"						\ 	 "_" #NEW "=_" #OLD "\n"					\ 	 "\t.type\t_" #NEW ",@function\n");
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RENAME_LIBRARY
parameter_list|(
name|OLD
parameter_list|,
name|NEW
parameter_list|)
define|\
value|__asm__ (".globl\t" #NEW "\n"						\ 	 #NEW "=" #OLD "\n"						\ 	 "\t.type\t" #NEW ",@function\n");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CREATE_DOUBLE_SHIFT
parameter_list|(
name|OLD
parameter_list|,
name|NEW
parameter_list|)
define|\
value|__asm__ (".text\n"							\ 	 "\t.globl\t" #NEW "\n"						\ 	 "\t.type\t" #NEW ",@function\n"				\ 	 #NEW ":\n"							\ 	 "\tor\tgr11, gr0, gr10\n"					\ 	 "\tbra\t" #OLD "\n");
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|L_sf_to_df
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__extendsfdf2,__ftod)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_sf_to_si
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__fixsfsi,__ftoi)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_sf_to_usi
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__fixunssfsi,__ftoui)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_df_to_si
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__fixdfsi,__dtoi)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixunssfsi
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__fixunssfsi,__ftoui)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixunsdfsi
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__fixunsdfsi,__dtoui)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixsfdi
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__fixsfdi,__ftoll)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixdfdi
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__fixdfdi,__dtoll)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixunssfdi
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__fixunssfdi,__ftoull)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixunsdfdi
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__fixunsdfdi,__dtoull)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_si_to_sf
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__floatsisf,__itof)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_di_to_sf
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__floatdisf,__lltof)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_df_to_sf
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__truncdfsf2,__dtof)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_si_to_df
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__floatsidf,__itod)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_floatdisf
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__floatdisf,__lltof)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_floatdidf
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__floatdidf,__lltod)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_addsub_df
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
define|\
value|RENAME_LIBRARY(__adddf3,__addd)
end_define

begin_macro
name|RENAME_LIBRARY
argument_list|(
argument|__subdf3
argument_list|,
argument|__subd
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_mul_df
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__muldf3,__muld)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_div_df
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__divdf3,__divd)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_addsub_sf
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
define|\
value|RENAME_LIBRARY(__addsf3,__addf) \ 	RENAME_LIBRARY(__subsf3,__subf)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_mul_sf
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__mulsf3,__mulf)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_div_sf
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__divsf3,__divf)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_ashldi3
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|CREATE_DOUBLE_SHIFT (__ashldi3,__sllll)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_lshrdi3
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|CREATE_DOUBLE_SHIFT (__lshrdi3,__srlll)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_ashrdi3
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|CREATE_DOUBLE_SHIFT (__ashrdi3,__srall)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_adddi3
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__adddi3,__addll)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_subdi3
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__subdi3,__subll)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_muldi3
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
define|\
value|RENAME_LIBRARY(__muldi3,__mulll)
end_define

begin_macro
name|RENAME_LIBRARY
argument_list|(
argument|__muldi3
argument_list|,
argument|__umulll
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_divdi3
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__divdi3,__divll)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_udivdi3
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__udivdi3,__udivll)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_moddi3
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__moddi3,__modll)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_umoddi3
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_LIBRARY_RENAMES
value|RENAME_LIBRARY(__umoddi3,__umodll)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

end_unit

