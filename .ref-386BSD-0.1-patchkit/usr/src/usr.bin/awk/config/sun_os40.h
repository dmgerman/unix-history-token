begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** sun_os40.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* $Log:	sun_os40.h,v $  * Revision 4.2  91/11/17  12:34:11  brennan  * added a declaration for sprintf()  *   * Revision 4.1  91/09/25  11:41:35  brennan  * VERSION 1.0  *   * Revision 3.4  91/08/26  13:04:38  brennan  * changed file name  *   * Revision 3.3  91/08/23  08:48:42  brennan  * discovered strtod() bug can also happen on sun3  *   * Revision 3.2  91/08/13  09:04:13  brennan  * VERSION .9994  *   * Revision 3.1  91/06/07  10:38:50  brennan  * VERSION 0.995  *  */
end_comment

begin_comment
comment|/* On some, not all, sun4's SunOS4.0.3 there is a bug in strtod().    strtod("0",0) sets errno to ERANGE sometimes! which announces    underflow which is not true.     If you get strange error messages:     mawk: line xx: 0 : decimal underflow     then your strtod() is broken and use this file as config.h     Otherwise use generic.h as config.h.     I've talked to Sun and they tell me its a known bug thats    fixed in 4.1     ----------------    It can happen on sun3's too. (8/23) */
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
end_define

begin_define
define|#
directive|define
name|STRTOD_UNDERFLOW_ON_ZERO_BUG
value|1
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* missing in /usr/include/*.h */
end_comment

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

