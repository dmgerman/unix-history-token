begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** sysV.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/*     This is for sysVR3+    without IEEE754 floating point     Even with IEEE754 hardware e.g. a 80x87 or 486    you might need this, because the math library doesn't    support the hardware.     tested on SCO UNIX VR3.2v2.0  */
end_comment

begin_comment
comment|/*$Log:	sysV.h,v $  * Revision 4.1  91/09/25  11:41:40  brennan  * VERSION 1.0  *   * Revision 1.2  91/08/13  09:04:15  brennan  * VERSION .9994  *   * Revision 1.1  91/08/03  05:49:52  brennan  * Initial revision  *  */
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

