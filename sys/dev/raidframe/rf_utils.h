begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_utils.h,v 1.4 1999/08/13 03:26:55 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/***************************************  *  * rf_utils.c -- header file for utils.c  *  ***************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_UTILS_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_UTILS_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_alloclist.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_threadstuff.h>
end_include

begin_function_decl
name|char
modifier|*
name|rf_find_non_white
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rf_find_white
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_RowCol_t
modifier|*
modifier|*
name|rf_make_2d_array
parameter_list|(
name|int
name|b
parameter_list|,
name|int
name|k
parameter_list|,
name|RF_AllocListElem_t
modifier|*
name|allocList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_RowCol_t
modifier|*
name|rf_make_1d_array
parameter_list|(
name|int
name|c
parameter_list|,
name|RF_AllocListElem_t
modifier|*
name|allocList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_free_2d_array
parameter_list|(
name|RF_RowCol_t
modifier|*
modifier|*
name|a
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|k
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_free_1d_array
parameter_list|(
name|RF_RowCol_t
modifier|*
name|a
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_gcd
parameter_list|(
name|int
name|m
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_atoi
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_htoi
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|RF_USEC_PER_SEC
value|1000000
end_define

begin_define
define|#
directive|define
name|RF_TIMEVAL_TO_US
parameter_list|(
name|_t_
parameter_list|)
value|(((_t_).tv_sec) \                 * RF_USEC_PER_SEC + (_t_).tv_usec)
end_define

begin_define
define|#
directive|define
name|RF_TIMEVAL_DIFF
parameter_list|(
name|_start_
parameter_list|,
name|_end_
parameter_list|,
name|_diff_
parameter_list|)
value|{ \ 	if ((_end_)->tv_usec< (_start_)->tv_usec) { \ 		(_diff_)->tv_usec = ((_end_)->tv_usec + RF_USEC_PER_SEC) \ 				- (_start_)->tv_usec; \ 		(_diff_)->tv_sec = ((_end_)->tv_sec-1) - (_start_)->tv_sec; \ 	} \ 	else { \ 		(_diff_)->tv_usec = (_end_)->tv_usec - (_start_)->tv_usec; \ 		(_diff_)->tv_sec  = (_end_)->tv_sec  - (_start_)->tv_sec; \ 	} \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_UTILS_H_ */
end_comment

end_unit

