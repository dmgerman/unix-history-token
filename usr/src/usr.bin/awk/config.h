begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** bsd43_vax.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* $Log: config.h,v $  * Revision 1.2  1992/06/02  05:07:35  rich  * Ported to 386bsd.  Changes from vax BSD4.3 include usage of  * fmod in libm.a, usage of void pointers, and usage of vfprintf  * in libc.a.  Floating point exceptions are not raised when  * they should be, which causes the last fpe test to fail.  *  * Revision 1.1  1992/06/02  03:45:42  rich  * Initial revision  *  * Revision 4.1  91/09/25  11:41:07  brennan  * VERSION 1.0  *   * Revision 3.2  91/08/13  09:04:09  brennan  * VERSION .9994  *   * Revision 3.1  91/06/07  10:39:33  brennan  * VERSION 0.995  *  */
end_comment

begin_comment
comment|/* BSD UNIX on 386BSD */
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
name|BSD43_VAX
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
name|FPE_ZERODIVIDE
value|FPE_FLTDIV_FAULT
end_define

begin_define
define|#
directive|define
name|FPE_OVERFLOW
value|FPE_FLTOVF_FAULT
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
name|HAVE_MATHERR
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_FMOD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VOID_PTR
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
comment|/* CONFIG_H  */
end_comment

end_unit

