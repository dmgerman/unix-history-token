begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** sysV_ieeefp.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* $Log:	sysV_ieeefp.h,v $  * Revision 4.1  91/09/25  11:41:45  brennan  * VERSION 1.0  *   * Revision 1.3  91/09/10  09:19:41  brennan  * fixed comment typo  *   * Revision 1.2  91/08/13  09:04:17  brennan  * VERSION .9994  *   * Revision 1.1  91/07/03  06:36:41  brennan  * Initial revision  *  */
end_comment

begin_comment
comment|/* This is the config.h file for    SystemV R3+    with IEEE754 floating point    **and a math library that supports ieee754**     This should work on SysV R3+ systems on i386 or i486    compiled and tested on:	     */
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
name|TURN_OFF_FPE_TRAPS
parameter_list|()
value|(void) fpsetmask(0)
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

