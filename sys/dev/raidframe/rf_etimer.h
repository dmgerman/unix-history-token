begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_etimer.h,v 1.4 1999/08/13 03:26:55 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_TIMER_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_TIMER_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_options.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_utils.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_struct
struct|struct
name|RF_Etimer_s
block|{
name|struct
name|timeval
name|st
decl_stmt|;
name|struct
name|timeval
name|et
decl_stmt|;
name|struct
name|timeval
name|diff
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|RF_ETIMER_START
parameter_list|(
name|_t_
parameter_list|)
define|\
value|{                                               \                         int s;                                  \                         bzero(&(_t_), sizeof (_t_));            \                         s = splclock();                         \                         (_t_).st = mono_time;                   \                         splx(s);                                \                 }
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|RF_ETIMER_START
parameter_list|(
name|_t_
parameter_list|)
define|\
value|{                                               \                         int s;                                  \                         bzero(&(_t_), sizeof (_t_));            \                         s = splclock();                         \                         getmicrouptime(&(_t_).st);              \                         splx(s);                                \                 }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|RF_ETIMER_STOP
parameter_list|(
name|_t_
parameter_list|)
define|\
value|{                                               \                         int s;                                  \                         s = splclock();                         \                         (_t_).et = mono_time;                   \                         splx(s);                                \                 }
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|RF_ETIMER_STOP
parameter_list|(
name|_t_
parameter_list|)
define|\
value|{                                               \                         int s;                                  \                         s = splclock();                         \                         getmicrouptime(&(_t_).et);              \                         splx(s);                                \                 }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RF_ETIMER_EVAL
parameter_list|(
name|_t_
parameter_list|)
define|\
value|{                                                       \                 RF_TIMEVAL_DIFF(&(_t_).st,&(_t_).et,&(_t_).diff) \         }
end_define

begin_define
define|#
directive|define
name|RF_ETIMER_VAL_US
parameter_list|(
name|_t_
parameter_list|)
value|(RF_TIMEVAL_TO_US((_t_).diff))
end_define

begin_define
define|#
directive|define
name|RF_ETIMER_VAL_MS
parameter_list|(
name|_t_
parameter_list|)
value|(RF_TIMEVAL_TO_US((_t_).diff)/1000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_TIMER_H_ */
end_comment

end_unit

