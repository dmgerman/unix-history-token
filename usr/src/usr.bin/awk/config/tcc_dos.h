begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** tcc_dos.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* Turbo C under MSDOS */
end_comment

begin_comment
comment|/* $Log:	tcc_dos.h,v $  * Revision 4.2  91/10/29  09:37:54  brennan  * changes for 1.09  *   * Revision 4.1  91/09/25  11:41:51  brennan  * VERSION 1.0  *   * Revision 3.2  91/08/13  09:04:19  brennan  * VERSION .9994  *   * Revision 3.1  91/06/07  10:38:51  brennan  * VERSION 0.995  *  */
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
name|MSDOS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PROTOS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDARG_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Turbo C float lib bungles comparison of NaNs  so we    have to keep traps on */
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
value|131
end_define

begin_define
define|#
directive|define
name|FPE_OVERFLOW
value|132
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SMALL_MEMORY
end_ifndef

begin_comment
comment|/* allow large model override */
end_comment

begin_define
define|#
directive|define
name|HAVE_SMALL_MEMORY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SMALL_MEMORY
operator|==
literal|0
end_if

begin_comment
comment|/* how to test far pointers have the same segment */
end_comment

begin_include
include|#
directive|include
file|<dos.h>
end_include

begin_define
define|#
directive|define
name|SAMESEG
parameter_list|(
name|p
parameter_list|,
name|q
parameter_list|)
value|(FP_SEG(p)==FP_SEG(q))
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
comment|/* CONFIG_H  */
end_comment

end_unit

