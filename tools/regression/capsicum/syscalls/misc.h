begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Pawel Jakub Dawidek under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MISC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MISC_H_
end_define

begin_define
define|#
directive|define
name|OK
parameter_list|()
value|do {							\ 	int _serrno = errno;						\ 	printf("ok # line %u\n", __LINE__);				\ 	fflush(stdout);							\ 	errno = _serrno;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|NOK
parameter_list|()
value|do {							\ 	int _serrno = errno;						\ 	printf("not ok # line %u\n", __LINE__);				\ 	fflush(stdout);							\ 	errno = _serrno;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|CHECK
parameter_list|(
name|cond
parameter_list|)
value|do {						\ 	if ((cond))							\ 		OK();							\ 	else								\ 		NOK();							\ } while (0)
end_define

begin_comment
comment|/*  * This can be removed once pdwait4(2) is implemented.  */
end_comment

begin_function_decl
name|int
name|pdwait
parameter_list|(
name|int
name|pfd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|descriptor_send
parameter_list|(
name|int
name|sock
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|descriptor_recv
parameter_list|(
name|int
name|sock
parameter_list|,
name|int
modifier|*
name|fdp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MISC_H_ */
end_comment

end_unit

