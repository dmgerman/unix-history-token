begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  ARM on semi-hosted platform    Copyright (C) 1994, 1995, 1996, 1997, 2001, 2004, 2005    Free Software Foundation, Inc.    Contributed by Richard Earnshaw (richard.earnshaw@arm.com)     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"crt0.o%s"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LIB_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"-lc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_CPP_SPEC
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_CPP_SPEC
value|"-D__semi__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LINK_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{mbig-endian:-EB} -X"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_VERSION
end_ifndef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fputs (" (ARM/semi-hosted)", stderr);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEFAULT_FLOAT_ABI
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT_FLOAT_ABI
value|ARM_FLOAT_ABI_HARD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_APCS_FRAME)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_EXTRA_SPECS
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
define|\
value|{ "subtarget_extra_asm_spec",	SUBTARGET_EXTRA_ASM_SPEC },
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_EXTRA_ASM_SPEC
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_ASM_SPEC
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The compiler supports PIC code generation, even though the binutils    may not.  If we are asked to compile position independent code, we    always pass -k to the assembler.  If it doesn't recognize it, then    it will barf, which probably means that it doesn't know how to    assemble PIC code.  This is what we want, since otherwise tools    may incorrectly assume we support PIC compilation even if the    binutils can't.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_SPEC
end_ifndef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"\ %{fpic|fpie: -k} %{fPIC|fPIE: -k} \ %{mbig-endian:-EB} \ %{mcpu=*:-mcpu=%*} \ %{march=*:-march=%*} \ %{mapcs-float:-mfloat} \ %{msoft-float:-mfloat-abi=soft} %{mhard-float:-mfloat-abi=hard} \ %{mfloat-abi=*} %{mfpu=*} \ %{mthumb-interwork:-mthumb-interwork} \ %(subtarget_extra_asm_spec)"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

