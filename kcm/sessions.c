begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2009 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Portions Copyright (c) 2009 Apple Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"kcm_locl.h"
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<bsm/audit_session.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|kcm_session_add
parameter_list|(
name|pid_t
name|session_id
parameter_list|)
block|{
name|kcm_log
argument_list|(
literal|1
argument_list|,
literal|"monitor session: %d\n"
argument_list|,
name|session_id
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|kcm_session_setup_handler
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
literal|0
block|au_sdev_handle_t *h;     dispatch_queue_t bgq;      h = au_sdev_open(AU_SDEVF_ALLSESSIONS);     if (h == NULL) 	return;      bgq = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0);      dispatch_async(bgq, ^{ 	    for (;;) { 		auditinfo_addr_t aio; 		int event;  		if (au_sdev_read_aia(h,&event,&aio) != 0) 		    continue;
comment|/* 		 * Ignore everything but END. This should relly be 		 * CLOSE but since that is delayed until the credential 		 * is reused, we can't do that 		 * */
block|if (event != AUE_SESSION_END) 		    continue;  		dispatch_async(dispatch_get_main_queue(), ^{ 			kcm_cache_remove_session(aio.ai_asid); 		    }); 	    } 	});
endif|#
directive|endif
block|}
end_function

end_unit

