begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  HP-UX 68010 version.  */
end_comment

begin_comment
comment|/* See tm-m68k.h.  0 means 68000 without 68881 and no bitfields.   */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|0
end_define

begin_include
include|#
directive|include
file|"tm-hp9k320.h"
end_include

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_comment
comment|/* HP does not support a 68020 without a 68881 or a 68010 with a 68881.    However, -m68020 does not imply -m68881.  You must specify both    if you want both.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX_ASM
end_ifdef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"-D__HPUX_ASM__ %{m68881: -D__HAVE_68881__}\ %{m68020: -Dmc68020}%{mc68020: -Dmc68020}\ %{!traditional:-D_INCLUDE__STDC__}"
end_define

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{!m68020:%{!mc68020:+X}}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HPUX_ASM */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{m68881: -D__HAVE_68881__}\ %{m68020: -Dmc68020}%{mc68020: -Dmc68020}\ %{!traditional:-D_INCLUDE__STDC__}"
end_define

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%{m68000:-mc68000}%{mc68000:-mc68000}%{!mc68000:%{!m68000:-mc68020}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HPUX_ASM */
end_comment

end_unit

