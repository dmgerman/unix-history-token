begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_general.h,v 1.6 2000/12/15 02:12:58 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * rf_general.h -- some general-use definitions  */
end_comment

begin_comment
comment|/*#define NOASSERT*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_GENERAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_GENERAL_H_
end_define

begin_comment
comment|/* error reporting and handling */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_comment
comment|/* printf, sprintf, and friends */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RF_ERRORMSG
parameter_list|(
name|s
parameter_list|)
value|printf((s))
end_define

begin_define
define|#
directive|define
name|RF_ERRORMSG1
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|)
value|printf((s),(a))
end_define

begin_define
define|#
directive|define
name|RF_ERRORMSG2
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|printf((s),(a),(b))
end_define

begin_define
define|#
directive|define
name|RF_ERRORMSG3
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|printf((s),(a),(b),(c))
end_define

begin_function_decl
name|void
name|rf_print_panic_message
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_print_assert_panic_message
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|rf_panicbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|RF_PANIC
parameter_list|()
value|{rf_print_panic_message(__LINE__,__FILE__); panic(rf_panicbuf);}
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|RF_ASSERT
end_ifdef

begin_undef
undef|#
directive|undef
name|RF_ASSERT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RF_ASSERT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOASSERT
end_ifndef

begin_define
define|#
directive|define
name|RF_ASSERT
parameter_list|(
name|_x_
parameter_list|)
value|{ \   if (!(_x_)) { \     rf_print_assert_panic_message(__LINE__, __FILE__, #_x_); \     panic(rf_panicbuf); \   } \ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !NOASSERT */
end_comment

begin_define
define|#
directive|define
name|RF_ASSERT
parameter_list|(
name|x
parameter_list|)
value|{
comment|/*noop*/
value|}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NOASSERT */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _KERNEL */
end_comment

begin_define
define|#
directive|define
name|RF_ASSERT
parameter_list|(
name|x
parameter_list|)
value|{
comment|/*noop*/
value|}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/* random stuff */
end_comment

begin_define
define|#
directive|define
name|RF_MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)> (b)) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|RF_MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)< (b)) ? (a) : (b))
end_define

begin_comment
comment|/* divide-by-zero check */
end_comment

begin_define
define|#
directive|define
name|RF_DB0_CHECK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|( ((b)==0) ? 0 : (a)/(b) )
end_define

begin_comment
comment|/* get time of day */
end_comment

begin_define
define|#
directive|define
name|RF_GETTIME
parameter_list|(
name|_t
parameter_list|)
value|microtime(&(_t))
end_define

begin_comment
comment|/*  * zero memory- not all bzero calls go through here, only  * those which in the kernel may have a user address  */
end_comment

begin_define
define|#
directive|define
name|RF_BZERO
parameter_list|(
name|_bp
parameter_list|,
name|_b
parameter_list|,
name|_l
parameter_list|)
value|bzero(_b,_l)
end_define

begin_comment
comment|/* XXX This is likely 						 * incorrect. GO */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|NBPG
value|PAGE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RF_UL
parameter_list|(
name|x
parameter_list|)
value|((unsigned long) (x))
end_define

begin_define
define|#
directive|define
name|RF_PGMASK
value|RF_UL(NBPG-1)
end_define

begin_define
define|#
directive|define
name|RF_BLIP
parameter_list|(
name|x
parameter_list|)
value|(NBPG - (RF_UL(x)& RF_PGMASK))
end_define

begin_comment
comment|/* bytes left in page */
end_comment

begin_define
define|#
directive|define
name|RF_PAGE_ALIGNED
parameter_list|(
name|x
parameter_list|)
value|((RF_UL(x)& RF_PGMASK) == 0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|RF_STRING
parameter_list|(
name|_str_
parameter_list|)
value|#_str_
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_define
define|#
directive|define
name|RF_STRING
parameter_list|(
name|_str_
parameter_list|)
value|"_str_"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_GENERAL_H_ */
end_comment

end_unit

