begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015 The TCPDUMP project  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|netdissect_timeval_operations_h
end_ifndef

begin_define
define|#
directive|define
name|netdissect_timeval_operations_h
end_define

begin_comment
comment|/* Operations on timevals. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MICRO_PER_SEC
end_ifndef

begin_define
define|#
directive|define
name|_MICRO_PER_SEC
value|1000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_NANO_PER_SEC
end_ifndef

begin_define
define|#
directive|define
name|_NANO_PER_SEC
value|1000000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|netdissect_timevalclear
parameter_list|(
name|tvp
parameter_list|)
value|((tvp)->tv_sec = (tvp)->tv_usec = 0)
end_define

begin_define
define|#
directive|define
name|netdissect_timevalisset
parameter_list|(
name|tvp
parameter_list|)
value|((tvp)->tv_sec || (tvp)->tv_usec)
end_define

begin_define
define|#
directive|define
name|netdissect_timevalcmp
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|cmp
parameter_list|)
define|\
value|(((tvp)->tv_sec == (uvp)->tv_sec) ?    \ 	 ((tvp)->tv_usec cmp (uvp)->tv_usec) : \ 	 ((tvp)->tv_sec cmp (uvp)->tv_sec))
end_define

begin_define
define|#
directive|define
name|netdissect_timevaladd
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|vvp
parameter_list|,
name|nano_prec
parameter_list|)
define|\
value|do {                                                      \ 		(vvp)->tv_sec = (tvp)->tv_sec + (uvp)->tv_sec;    \ 		(vvp)->tv_usec = (tvp)->tv_usec + (uvp)->tv_usec; \ 		if (nano_prec) {                                  \ 			if ((vvp)->tv_usec>= _NANO_PER_SEC) {    \ 				(vvp)->tv_sec++;                  \ 				(vvp)->tv_usec -= _NANO_PER_SEC;  \ 			}                                         \ 		} else {                                          \ 			if ((vvp)->tv_usec>= _MICRO_PER_SEC) {   \ 				(vvp)->tv_sec++;                  \ 				(vvp)->tv_usec -= _MICRO_PER_SEC; \ 			}                                         \ 		}                                                 \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|netdissect_timevalsub
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|vvp
parameter_list|,
name|nano_prec
parameter_list|)
define|\
value|do {                                                       \ 		(vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;     \ 		(vvp)->tv_usec = (tvp)->tv_usec - (uvp)->tv_usec;  \ 		if ((vvp)->tv_usec< 0) {                          \ 		    (vvp)->tv_sec--;                               \ 		    (vvp)->tv_usec += (nano_prec ? _NANO_PER_SEC : \ 				       _MICRO_PER_SEC);            \ 		}                                                  \ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* netdissect_timeval_operations_h */
end_comment

end_unit

