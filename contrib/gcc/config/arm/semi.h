begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  ARM on semi-hosted platform    Copyright (C) 1994, 1995, 1996, 1997, 2001 Free Software Foundation, Inc.    Contributed by Richard Earnshaw (richard.earnshaw@arm.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|TARGET_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(ARM_FLAG_APCS_32 | ARM_FLAG_APCS_FRAME)
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
value|"\ %{fpic: -k} %{fPIC: -k} \ %{mbig-endian:-EB} \ %{mcpu=*:-m%*} \ %{march=*:-m%*} \ %{mapcs-float:-mfloat} \ %{msoft-float:-mno-fpu} \ %{mthumb-interwork:-mthumb-interwork} \ %(subtarget_extra_asm_spec)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CPP_APCS_PC_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_APCS_PC_DEFAULT_SPEC
value|"-D__APCS_32__"
end_define

end_unit

