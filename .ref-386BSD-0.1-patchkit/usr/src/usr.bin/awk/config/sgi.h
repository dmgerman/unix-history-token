begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** sgi.h  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/*   SGI  IRIX4.0.1 */
end_comment

begin_comment
comment|/* $Log:	sgi.h,v $  * Revision 1.1  92/02/25  08:10:22  brennan  * Initial revision  *  */
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

