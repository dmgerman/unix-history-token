begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Rs6000 running LynxOS.    Copyright (C) 1995, 1996, 2000, 2002, 2003, 2004, 2005    Free Software Foundation, Inc.    Contributed by David Henkel-Wallace, Cygnus Support (gumby@cygnus.com)    Rewritten by Adam Nemet, LynuxWorks Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Override the definition in sysv4.h.  */
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
value|fputs (" (PowerPC/LynxOS)", stderr);
end_define

begin_comment
comment|/* Undefine the definition to enable the LynxOS default from the    top-level lynx.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_SPECS
end_undef

begin_comment
comment|/* Get rid off the spec definitions from rs6000/sysv4.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
define|\
value|"%{msoft-float: -D_SOFT_FLOAT} \  %(cpp_cpu) \  %(cpp_os_lynx)"
end_define

begin_comment
comment|/* LynxOS only supports big-endian on PPC so we override the    definition from sysv4.h.  Since the LynxOS 4.0 compiler was set to    return every structure in memory regardless of their size we have    to emulate the same behavior here with disabling the SVR4 structure    returning.  */
end_comment

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
define|\
value|"%{G*} %{mno-sdata:-msdata=none} \  %{maltivec:-mabi=altivec} \  -maix-struct-return"
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
define|\
value|"%(asm_cpu) \  %{.s: %{mregnames} %{mno-regnames}} \  %{.S: %{mregnames} %{mno-regnames}}"
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%{!msdata=none:%{G*}} %{msdata=none:-G0} \  %(link_os_lynx)"
end_define

begin_comment
comment|/* Override the definition from sysv4.h.  */
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
value|do						\     {						\       builtin_define ("__BIG_ENDIAN__");	\       builtin_define ("__powerpc__");		\       builtin_assert ("cpu=powerpc");		\       builtin_assert ("machine=powerpc");	\       builtin_define ("__PPC__");		\     }						\   while (0)
end_define

begin_comment
comment|/* Override the rs6000.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_APP_ON
end_undef

begin_define
define|#
directive|define
name|ASM_APP_ON
value|"#APP\n"
end_define

begin_comment
comment|/* Override the rs6000.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_APP_OFF
end_undef

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|"#NO_APP\n"
end_define

begin_comment
comment|/* LynxOS does not do anything with .fixup plus let's not create    writable section for linkonce.r and linkonce.t.  */
end_comment

begin_undef
undef|#
directive|undef
name|RELOCATABLE_NEEDS_FIXUP
end_undef

begin_comment
comment|/* Override these from rs6000.h with the generic definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN
end_undef

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_comment
comment|/* The file rs6000.c defines TARGET_HAVE_TLS unconditionally to the    value of HAVE_AS_TLS.  HAVE_AS_TLS is true as gas support for TLS    is detected by configure.  Override the definition to false.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_AS_TLS
end_undef

begin_define
define|#
directive|define
name|HAVE_AS_TLS
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CRT_BEGIN
end_ifdef

begin_comment
comment|/* This function is part of crtbegin*.o which is at the beginning of    the link and is called from .fini which is usually toward the end    of the executable.  Make it longcall so that we don't limit the    text size of the executables to 32M.  */
end_comment

begin_function_decl
specifier|static
name|void
name|__do_global_dtors_aux
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(longcall
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRT_BEGIN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CRT_END
end_ifdef

begin_comment
comment|/* Similarly here.  This function resides in crtend*.o which is toward    to end of the link and is called from .init which is at the    beginning.  */
end_comment

begin_function_decl
specifier|static
name|void
name|__do_global_ctors_aux
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(longcall
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRT_END */
end_comment

end_unit

