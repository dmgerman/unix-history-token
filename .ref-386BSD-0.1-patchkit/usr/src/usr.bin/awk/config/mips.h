begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** mips.h  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/*$Log:	mips.h,v $  * Revision 1.2  91/11/15  08:13:20  brennan  * declaration for sprintf  *   * Revision 1.1  91/10/28  09:58:05  brennan  * Initial revision  *  */
end_comment

begin_comment
comment|/* tested and works on:     MIPS M2000 	C 2.20 (4.52)  */
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

begin_comment
comment|/* this is missing and print.c needs it */
end_comment

begin_function_decl
name|char
modifier|*
name|sprintf
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

