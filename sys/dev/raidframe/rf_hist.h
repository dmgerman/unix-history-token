begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_hist.h,v 1.3 1999/02/05 00:06:12 oster Exp $	*/
end_comment

begin_comment
comment|/*  * rf_hist.h  *  * Histgram operations for RAIDframe stats  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Jim Zelenka  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_HIST_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_HIST_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_define
define|#
directive|define
name|RF_HIST_RESOLUTION
value|5
end_define

begin_define
define|#
directive|define
name|RF_HIST_MIN_VAL
value|0
end_define

begin_define
define|#
directive|define
name|RF_HIST_MAX_VAL
value|1000
end_define

begin_define
define|#
directive|define
name|RF_HIST_RANGE
value|(RF_HIST_MAX_VAL - RF_HIST_MIN_VAL)
end_define

begin_define
define|#
directive|define
name|RF_HIST_NUM_BUCKETS
value|(RF_HIST_RANGE / RF_HIST_RESOLUTION + 1)
end_define

begin_typedef
typedef|typedef
name|RF_uint32
name|RF_Hist_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RF_HIST_ADD
parameter_list|(
name|_hist_
parameter_list|,
name|_val_
parameter_list|)
value|{ \ 	RF_Hist_t val; \ 	val = ((RF_Hist_t)(_val_)) / 1000; \ 	if (val>= RF_HIST_MAX_VAL) \ 		_hist_[RF_HIST_NUM_BUCKETS-1]++; \ 	else \ 		_hist_[(val - RF_HIST_MIN_VAL) / RF_HIST_RESOLUTION]++; \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_HIST_H_ */
end_comment

end_unit

