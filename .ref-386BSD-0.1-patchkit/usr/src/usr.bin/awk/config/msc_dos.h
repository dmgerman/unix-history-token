begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** msc_dos.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* Microsoft C 6.0A under MSDOS */
end_comment

begin_comment
comment|/*$Log:	msc_dos.h,v $  * Revision 4.3  92/01/09  08:54:09  brennan  * changed SAMESEG macro  *   * Revision 4.2  91/10/29  09:36:59  brennan  * Large model macro  *  */
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
name|MSDOS_MSC
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

begin_define
define|#
directive|define
name|SAMESEG
parameter_list|(
name|p
parameter_list|,
name|q
parameter_list|)
define|\
value|(((unsigned long)(p)^(unsigned long)(q))<0x10000L)
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

