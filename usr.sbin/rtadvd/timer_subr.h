begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: timer.h,v 1.5 2002/05/31 13:30:38 jinmei Exp $	*/
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (C) 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|SSBUFLEN
value|1024
end_define

begin_define
define|#
directive|define
name|TS_CMP
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
name|TS_ADD
parameter_list|(
name|tsp
parameter_list|,
name|usp
parameter_list|,
name|vsp
parameter_list|)
define|\
value|do {								\ 		(vsp)->tv_sec = (tsp)->tv_sec + (usp)->tv_sec;		\ 		(vsp)->tv_nsec = (tsp)->tv_nsec + (usp)->tv_nsec;	\ 		if ((vsp)->tv_nsec>= 1000000000L) {			\ 			(vsp)->tv_sec++;				\ 			(vsp)->tv_nsec -= 1000000000L;			\ 		}							\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TS_SUB
parameter_list|(
name|tsp
parameter_list|,
name|usp
parameter_list|,
name|vsp
parameter_list|)
define|\
value|do {								\ 		(vsp)->tv_sec = (tsp)->tv_sec - (usp)->tv_sec;		\ 		(vsp)->tv_nsec = (tsp)->tv_nsec - (usp)->tv_nsec;	\ 		if ((vsp)->tv_nsec< 0) {				\ 			(vsp)->tv_sec--;				\ 			(vsp)->tv_nsec += 1000000000L;			\ 		}							\ 	} while (0)
end_define

begin_function_decl
name|struct
name|timespec
modifier|*
name|rtadvd_timer_rest
parameter_list|(
name|struct
name|rtadvd_timer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|sec2str
parameter_list|(
name|uint32_t
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

end_unit

