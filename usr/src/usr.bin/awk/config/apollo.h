begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** apollo.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/*     compiled and tested on apollo SR10.3 */
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

begin_comment
comment|/* don't have IEEE hardware */
end_comment

begin_define
define|#
directive|define
name|FPE_TRAPS_ON
value|1
end_define

begin_define
define|#
directive|define
name|FPE_ZERODIVIDE
value|FPE_FLTDIV_FAULT
end_define

begin_define
define|#
directive|define
name|FPE_OVERFLOW
value|FPE_FLTOVF_FAULT
end_define

begin_comment
comment|/* compiler sets __STDC__ but really is not ansi */
end_comment

begin_undef
undef|#
directive|undef
name|__STDC__
end_undef

begin_include
include|#
directive|include
file|"config/Idefault.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_H  */
end_comment

end_unit

