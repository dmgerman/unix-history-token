begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** xenix_r2.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/*     This has been compiled and tested on    SCO XENIX R2.3.1 SysV on a i386     The floating point support is poor.    Even with a coprocessor there is no access to IEEE754    functionality.     There is no way to tell what caused SIGFPE  */
end_comment

begin_comment
comment|/*$Log:	xenix_r2.h,v $  * Revision 4.1  91/09/25  11:42:13  brennan  * VERSION 1.0  *   * Revision 1.2  91/08/13  09:04:24  brennan  * VERSION .9994  *   * Revision 1.1  91/06/19  10:17:08  brennan  * Initial revision  *  */
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
name|FPE_TRAPS_ON
value|1
end_define

begin_define
define|#
directive|define
name|NOINFO_SIGFPE
value|1
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
unit|I would guess that on a 286 you would want to
define|#
directive|define
name|HAVE_SMALL_MEMORY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* CONFIG_H */
end_comment

end_unit

