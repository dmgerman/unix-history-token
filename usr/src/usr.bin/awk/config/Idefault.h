begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** Idefault.h copyright 1991, 1992.  Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* $Log:	Idefault.h,v $  * Revision 3.13  92/03/03  16:40:56  brennan  * remove HAVE_PRINTF_HD  *   * Revision 3.12  91/11/16  15:37:29  brennan  * add NO_BINMODE  *   * Revision 3.11  91/10/29  10:48:40  brennan  * version 1.09  *   * Revision 3.10  91/10/23  10:46:34  brennan  * MSDOS LM and SM  *   * Revision 3.9  91/10/14  09:52:48  brennan  * added HAVE_PRINTF_HD  *   * Revision 3.8  91/09/30  08:11:22  brennan  * added MAX__INT  *   * Revision 3.7  91/08/16  08:49:51  brennan  * Carl's addition of SW_FP_CHECK for XNX23A  *   * Revision 3.6  91/08/13  09:04:05  brennan  * VERSION .9994  *   * Revision 3.5  91/08/03  06:10:46  brennan  * changed CHECK_DIVZERO macro  *   * Revision 3.4  91/08/03  05:35:59  brennan  * changed name to Idefault.h   *   * Revision 3.3  91/06/28  04:36:28  brennan  * adjustments with __STDC__  *   * Revision 3.3  91/06/19  10:21:37  brennan  * changes for xenix_r2.h and gcc  *   * Revision 3.2  91/06/15  09:24:34  brennan  * Carl's diffs for V7  *   * 06/11/91  C. Mascott		add default D2BOOL  *  * Revision 3.1  91/06/07  10:38:46  brennan  * VERSION 0.995  *  */
end_comment

begin_comment
comment|/* The most common configuration is defined here:      no function prototypes    have void*    have matherr(), strtod(), fmod()    uses<varargs.h>     fpe_traps default to off    and nan comparison is done correctly     memory is not small     OS is some flavor of Unix  */
end_comment

begin_comment
comment|/* WARNING:  To port to a new configuration, don't make changes    here.  This file is included at the end of your new     config.h      Read the file   mawk/INSTALL */
end_comment

begin_comment
comment|/*------------- compiler ----------------------------*/
end_comment

begin_comment
comment|/* do not have function prototypes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PROTOS
end_ifndef

begin_define
define|#
directive|define
name|HAVE_PROTOS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* have type   void *    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_VOID_PTR
end_ifndef

begin_define
define|#
directive|define
name|HAVE_VOID_PTR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* logical test of double is OK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|D2BOOL
end_ifndef

begin_define
define|#
directive|define
name|D2BOOL
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*---------------- library ----------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_MATHERR
end_ifndef

begin_define
define|#
directive|define
name|HAVE_MATHERR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRTOD
end_ifndef

begin_define
define|#
directive|define
name|HAVE_STRTOD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FMOD
end_ifndef

begin_define
define|#
directive|define
name|HAVE_FMOD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* uses<varargs.h> instead of<stdarg.h> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STDARG_H
end_ifndef

begin_define
define|#
directive|define
name|HAVE_STDARG_H
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* has<string.h>,     doesn't have<stdlib.h>      has<fcntl.h> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRING_H
end_ifndef

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STDLIB_H
end_ifndef

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FCNTL_H
end_ifndef

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* have pipes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_REAL_PIPES
end_ifndef

begin_define
define|#
directive|define
name|HAVE_REAL_PIPES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FAKE_PIPES
end_ifndef

begin_define
define|#
directive|define
name|HAVE_FAKE_PIPES
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*------------- machine ------------------------*/
end_comment

begin_comment
comment|/* ints are 32bits, two complement */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX__INT
end_ifndef

begin_define
define|#
directive|define
name|MAX__INT
value|0x7fffffff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* default is IEEE754 and data space is not scarce */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FPE_TRAPS_ON
end_ifndef

begin_define
define|#
directive|define
name|FPE_TRAPS_ON
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NOINFO_SIGFPE
end_ifndef

begin_define
define|#
directive|define
name|NOINFO_SIGFPE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|FPE_TRAPS_ON
end_if

begin_undef
undef|#
directive|undef
name|NOINFO_SIGFPE
end_undef

begin_define
define|#
directive|define
name|NOINFO_SIGFPE
value|0
end_define

begin_comment
comment|/* make sure no one does 				     something stupid */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NOINFO_SIGFPE
end_if

begin_define
define|#
directive|define
name|CHECK_DIVZERO
parameter_list|(
name|x
parameter_list|)
value|if( (x) == 0.0 )rt_error(dz_msg);else
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SW_FP_CHECK is specific to V7 and XNX23A 	(1) is part of STDC_MATHERR def. 	(2) enables calls to XENIX-68K 2.3A clrerr(), iserr()  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SW_FP_CHECK
end_ifndef

begin_define
define|#
directive|define
name|SW_FP_CHECK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TURN_OFF_FPE_TRAPS
end_ifndef

begin_define
define|#
directive|define
name|TURN_OFF_FPE_TRAPS
parameter_list|()
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SMALL_MEMORY
end_ifndef

begin_define
define|#
directive|define
name|HAVE_SMALL_MEMORY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|__STDC__
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_undef
undef|#
directive|undef
name|HAVE_PROTOS
end_undef

begin_define
define|#
directive|define
name|HAVE_PROTOS
value|1
end_define

begin_undef
undef|#
directive|undef
name|HAVE_VOID_PTR
end_undef

begin_define
define|#
directive|define
name|HAVE_VOID_PTR
value|1
end_define

begin_undef
undef|#
directive|undef
name|HAVE_STDARG_H
end_undef

begin_define
define|#
directive|define
name|HAVE_STDARG_H
value|1
end_define

begin_undef
undef|#
directive|undef
name|HAVE_STRING_H
end_undef

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__STDC__
operator|&&
operator|!
name|__GNUC__
end_if

begin_comment
comment|/* with gcc __STDC__ can be defined, but stdlib.h is missing */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_STDLIB_H
end_undef

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* the painfull case: we need to catch fpe's and look at errno    after lib calls */
end_comment

begin_define
define|#
directive|define
name|STDC_MATHERR
value|((SW_FP_CHECK || FPE_TRAPS_ON)&& HAVE_MATHERR==0)
end_define

begin_comment
comment|/*-------------------MSDOS---------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_REARGV
end_ifndef

begin_define
define|#
directive|define
name|HAVE_REARGV
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|MAX__INT
end_undef

begin_define
define|#
directive|define
name|MAX__INT
value|0x7fff
end_define

begin_if
if|#
directive|if
name|HAVE_SMALL_MEMORY
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|LM_DOS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LM_DOS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SM_DOS
value|(!LM_DOS)
end_define

begin_undef
undef|#
directive|undef
name|HAVE_REAL_PIPES
end_undef

begin_define
define|#
directive|define
name|HAVE_REAL_PIPES
value|0
end_define

begin_undef
undef|#
directive|undef
name|HAVE_FAKE_PIPES
end_undef

begin_define
define|#
directive|define
name|HAVE_FAKE_PIPES
value|1
end_define

begin_if
if|#
directive|if
name|SM_DOS
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|NO_BINMODE
end_ifdef

begin_undef
undef|#
directive|undef
name|NO_BINMODE
end_undef

begin_define
define|#
directive|define
name|NO_BINMODE
value|1
end_define

begin_comment
comment|/* hopefully no one needs this */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NO_BINMODE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NO_BINMODE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_DOS */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not defined MSDOS */
end_comment

begin_define
define|#
directive|define
name|MSDOS
value|0
end_define

begin_define
define|#
directive|define
name|LM_DOS
value|0
end_define

begin_define
define|#
directive|define
name|SM_DOS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSDOS */
end_comment

begin_comment
comment|/*----------------------------------------------------------*/
end_comment

begin_if
if|#
directive|if
name|HAVE_PROTOS
end_if

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|name
parameter_list|,
name|args
parameter_list|)
value|name  args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|name
parameter_list|,
name|args
parameter_list|)
value|name()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ultrix pukes if __STDC__ is defined 0  */
end_comment

begin_comment
comment|/* SCO UNIX's cc (from Microsoft) sneezes if __STDC__ is re-#define-d */
end_comment

begin_if
if|#
directive|if
operator|(
name|__STDC__
operator|==
literal|0
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|M_I386
end_ifndef

begin_undef
undef|#
directive|undef
name|__STDC__
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* for Think C on the Macintosh, sizeof(size_t) != sizeof(unsigned  * Rather than unilaterally imposing size_t, when not all compilers would  * necessarily have it defined, we use the SIZE_T() macro where appropriate  * to typecast function arguments  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_T
end_ifndef

begin_define
define|#
directive|define
name|SIZE_T
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

