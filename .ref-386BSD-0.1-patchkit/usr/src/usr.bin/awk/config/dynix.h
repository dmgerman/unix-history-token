begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** dynix.h  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/*$Log: */
end_comment

begin_comment
comment|/*  * should work on any Sequent running Final DYNIX  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRTOD
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_FMOD
value|0
end_define

begin_define
define|#
directive|define
name|vfprintf
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|,
name|a
parameter_list|)
value|_doprnt(f,a,s)
end_define

begin_define
define|#
directive|define
name|FPE_TRAPS_ON
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MATHERR
value|0
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/fpu.h>
end_include

begin_define
define|#
directive|define
name|FPE_ZERODIVIDE
value|FPE_FLTDIV_TRAP
end_define

begin_define
define|#
directive|define
name|FPE_OVERFLOW
value|FPE_FLTOVF_TRAP
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"config/Idefault.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

