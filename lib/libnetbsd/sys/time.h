begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)time.h	8.5 (Berkeley) 5/4/95  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBNETBSD_SYS_TIME_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBNETBSD_SYS_TIME_H_
end_define

begin_empty
empty|#include_next<sys/time.h>
end_empty

begin_comment
comment|/* Operations on timespecs. */
end_comment

begin_define
define|#
directive|define
name|timespecclear
parameter_list|(
name|tsp
parameter_list|)
value|(tsp)->tv_sec = (time_t)((tsp)->tv_nsec = 0L)
end_define

begin_define
define|#
directive|define
name|timespecisset
parameter_list|(
name|tsp
parameter_list|)
value|((tsp)->tv_sec || (tsp)->tv_nsec)
end_define

begin_define
define|#
directive|define
name|timespeccmp
parameter_list|(
name|tsp
parameter_list|,
name|usp
parameter_list|,
name|cmp
parameter_list|)
define|\
value|(((tsp)->tv_sec == (usp)->tv_sec) ?				\ 	    ((tsp)->tv_nsec cmp (usp)->tv_nsec) :			\ 	    ((tsp)->tv_sec cmp (usp)->tv_sec))
end_define

begin_define
define|#
directive|define
name|timespecadd
parameter_list|(
name|tsp
parameter_list|,
name|usp
parameter_list|,
name|vsp
parameter_list|)
define|\
value|do {								\ 		(vsp)->tv_sec = (tsp)->tv_sec + (usp)->tv_sec;		\ 		(vsp)->tv_nsec = (tsp)->tv_nsec + (usp)->tv_nsec;	\ 		if ((vsp)->tv_nsec>= 1000000000L) {			\ 			(vsp)->tv_sec++;				\ 			(vsp)->tv_nsec -= 1000000000L;			\ 		}							\ 	} while (
comment|/* CONSTCOND */
value|0)
end_define

begin_define
define|#
directive|define
name|timespecsub
parameter_list|(
name|tsp
parameter_list|,
name|usp
parameter_list|,
name|vsp
parameter_list|)
define|\
value|do {								\ 		(vsp)->tv_sec = (tsp)->tv_sec - (usp)->tv_sec;		\ 		(vsp)->tv_nsec = (tsp)->tv_nsec - (usp)->tv_nsec;	\ 		if ((vsp)->tv_nsec< 0) {				\ 			(vsp)->tv_sec--;				\ 			(vsp)->tv_nsec += 1000000000L;			\ 		}							\ 	} while (
comment|/* CONSTCOND */
value|0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

