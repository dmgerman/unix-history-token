begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Mathew Kanner  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIDIQ_H
end_ifndef

begin_define
define|#
directive|define
name|MIDIQ_H
end_define

begin_define
define|#
directive|define
name|MIDIQ_MOVE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|bcopy(b,a,c)
end_define

begin_define
define|#
directive|define
name|MIDIQ_HEAD
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct name {                           \         int h, t, s;                    \         type * b;                        \ }
end_define

begin_define
define|#
directive|define
name|MIDIQ_INIT
parameter_list|(
name|head
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|)
value|do {                \         (head).h=(head).t=0;                          \         (head).s=size;                                 \         (head).b=buf;                                  \ } while (0)
end_define

begin_define
define|#
directive|define
name|MIDIQ_EMPTY
parameter_list|(
name|head
parameter_list|)
value|((head).h == (head).t )
end_define

begin_define
define|#
directive|define
name|MIDIQ_LENBASE
parameter_list|(
name|head
parameter_list|)
value|((head).h - (head).t< 0 ? \                                         (head).h - (head).t + (head).s : \                                         (head).h - (head).t)
end_define

begin_define
define|#
directive|define
name|MIDIQ_FULL
parameter_list|(
name|head
parameter_list|)
value|((head).h == -1)
end_define

begin_define
define|#
directive|define
name|MIDIQ_AVAIL
parameter_list|(
name|head
parameter_list|)
value|(MIDIQ_FULL(head) ? 0 : (head).s - MIDIQ_LENBASE(head))
end_define

begin_define
define|#
directive|define
name|MIDIQ_LEN
parameter_list|(
name|head
parameter_list|)
value|((head).s - MIDIQ_AVAIL(head))
end_define

begin_define
define|#
directive|define
name|MIDIQ_DEBUG
value|0
end_define

begin_comment
comment|/*  * No protection against overflow, underflow  */
end_comment

begin_define
define|#
directive|define
name|MIDIQ_ENQ
parameter_list|(
name|head
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|)
value|do {                                                                 \ 		if(MIDIQ_DEBUG)\                 	printf("#1 %p %p bytes copied %jd tran req s %d h %d t %d\n",            \&(head).b[(head).h], (buf),                                        \ 			       (intmax_t)(sizeof(*(head).b) *                                     \ 					  MIN( (size), (head).s - (head).h) ),                   \ 			       (size), (head).h, (head).t);               \                 MIDIQ_MOVE(&(head).b[(head).h], (buf), sizeof(*(head).b) * MIN((size), (head).s - (head).h));                       \                 if( (head).s - (head).h< (size) ) {                                                    \ 			if(MIDIQ_DEBUG) \                         	printf("#2 %p %p bytes copied %jd\n",  (head).b, (buf) + (head).s - (head).h, (intmax_t)sizeof(*(head).b) * ((size) - (head).s + (head).h) );      \                         MIDIQ_MOVE((head).b, (buf) + (head).s - (head).h, sizeof(*(head).b) * ((size) - (head).s + (head).h) );      \ 		} \                 (head).h+=(size);                                                                         \                 (head).h%=(head).s;                                                                     \ 		if(MIDIQ_EMPTY(head)) (head).h=-1; \ 		if(MIDIQ_DEBUG)\                 	printf("#E h %d t %d\n", (head).h, (head).t);                       \ } while (0)
end_define

begin_define
define|#
directive|define
name|MIDIQ_DEQ_I
parameter_list|(
name|head
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|,
name|move
parameter_list|,
name|update
parameter_list|)
value|do {                                                                 \ 		if(MIDIQ_FULL(head)) (head).h=(head).t; \ 		if(MIDIQ_DEBUG)\                 	printf("#1 %p %p bytes copied %jd tran req s %d h %d t %d\n",&(head).b[(head).t], (buf), (intmax_t)sizeof(*(head).b) * MIN((size), (head).s - (head).t), (size), (head).h, (head).t);                       \                 if (move) MIDIQ_MOVE((buf),&(head).b[(head).t], sizeof(*(head).b) * MIN((size), (head).s - (head).t));                       \                 if( (head).s - (head).t< (size) ) {                                                    \ 			if(MIDIQ_DEBUG) \                         	printf("#2 %p %p bytes copied %jd\n",  (head).b, (buf) + (head).s - (head).t, (intmax_t)sizeof(*(head).b) * ((size) - (head).s + (head).t) );      \                         if (move) MIDIQ_MOVE((buf) + (head).s - (head).t, (head).b, sizeof(*(head).b) * ((size) - (head).s + (head).t) );      \ 		} \ 		if (update) { \                 (head).t+=(size);                                                                         \                 (head).t%=(head).s;                                                                     \ 		} else { \ 		  if (MIDIQ_EMPTY(head)) (head).h=-1; \ 		} \ 		if(MIDIQ_DEBUG)\                 	printf("#E h %d t %d\n", (head).h, (head).t);                       \ } while (0)
end_define

begin_define
define|#
directive|define
name|MIDIQ_SIZE
parameter_list|(
name|head
parameter_list|)
value|((head).s)
end_define

begin_define
define|#
directive|define
name|MIDIQ_CLEAR
parameter_list|(
name|head
parameter_list|)
value|((head).h = (head).t = 0)
end_define

begin_define
define|#
directive|define
name|MIDIQ_BUF
parameter_list|(
name|head
parameter_list|)
value|((head).b)
end_define

begin_define
define|#
directive|define
name|MIDIQ_DEQ
parameter_list|(
name|head
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|)
value|MIDIQ_DEQ_I(head, buf, size, 1, 1)
end_define

begin_define
define|#
directive|define
name|MIDIQ_PEEK
parameter_list|(
name|head
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|)
value|MIDIQ_DEQ_I(head, buf, size, 1, 0)
end_define

begin_define
define|#
directive|define
name|MIDIQ_POP
parameter_list|(
name|head
parameter_list|,
name|size
parameter_list|)
value|MIDIQ_DEQ_I(head,&head, size, 0, 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

