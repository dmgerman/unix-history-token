begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** atarist.h   ++jrb		bammi@cadence.com  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/*     This is for atariST/StE/TT series with gcc    Tested with gcc-1.40 + libs @ Patchlevel 73  */
end_comment

begin_comment
comment|/*$Log:	atarist.h,v $  * Revision 1.1  91/10/29  10:48:52  brennan  * Initial revision  *  */
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
name|HAVE_STDLIB_H
value|1
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
name|NOINFO_SIGFPE
value|1
end_define

begin_include
include|#
directive|include
file|<compiler.h>
end_include

begin_define
define|#
directive|define
name|SIZE_T
parameter_list|(
name|X
parameter_list|)
value|((size_t)(X))
end_define

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

