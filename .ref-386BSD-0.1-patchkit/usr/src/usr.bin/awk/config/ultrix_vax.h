begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** ultrix_vax.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* $Log:	ultrix_vax.h,v $  * Revision 4.1  91/09/25  11:42:07  brennan  * VERSION 1.0  *   * Revision 3.2  91/08/13  09:04:23  brennan  * VERSION .9994  *   * Revision 3.1  91/06/07  10:38:53  brennan  * VERSION 0.995  *  */
end_comment

begin_comment
comment|/* tested on: 	ULTRIX V4.1 (Rev. 200) System #3 on MicroVax 3600 	ULTRIX V3.1  on vax?? */
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
comment|/* want SysV style matherr(),    so set -YSYSTEM_FIVE compiler flag    in Makefile */
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

begin_comment
comment|/* CONFIG_H  */
end_comment

end_unit

