begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REGRESS_THREAD_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|REGRESS_THREAD_H_INCLUDED_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|EVENT__HAVE_PTHREADS
end_ifdef

begin_define
define|#
directive|define
name|THREAD_T
value|pthread_t
end_define

begin_define
define|#
directive|define
name|THREAD_FN
value|void *
end_define

begin_define
define|#
directive|define
name|THREAD_RETURN
parameter_list|()
value|return (NULL)
end_define

begin_define
define|#
directive|define
name|THREAD_START
parameter_list|(
name|threadvar
parameter_list|,
name|fn
parameter_list|,
name|arg
parameter_list|)
define|\
value|pthread_create(&(threadvar), NULL, fn, arg)
end_define

begin_define
define|#
directive|define
name|THREAD_JOIN
parameter_list|(
name|th
parameter_list|)
value|pthread_join(th, NULL)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|THREAD_T
value|HANDLE
end_define

begin_define
define|#
directive|define
name|THREAD_FN
value|unsigned __stdcall
end_define

begin_define
define|#
directive|define
name|THREAD_RETURN
parameter_list|()
value|return (0)
end_define

begin_define
define|#
directive|define
name|THREAD_START
parameter_list|(
name|threadvar
parameter_list|,
name|fn
parameter_list|,
name|arg
parameter_list|)
value|do {		\ 	uintptr_t threadhandle = _beginthreadex(NULL,0,fn,(arg),0,NULL); \ 	(threadvar) = (HANDLE) threadhandle; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|THREAD_JOIN
parameter_list|(
name|th
parameter_list|)
value|WaitForSingleObject(th, INFINITE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

