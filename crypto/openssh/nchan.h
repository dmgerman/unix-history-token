begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Markus Friedl.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* RCSID("$Id: nchan.h,v 1.5 1999/11/24 16:15:25 markus Exp $"); */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NCHAN_H
end_ifndef

begin_define
define|#
directive|define
name|NCHAN_H
end_define

begin_comment
comment|/*  * SSH Protocol 1.5 aka New Channel Protocol  * Thanks to Martina, Axel and everyone who left Erlangen, leaving me bored.  * Written by Markus Friedl in October 1999  *  * Protocol versions 1.3 and 1.5 differ in the handshake protocol used for the  * tear down of channels:  *  * 1.3:	strict request-ack-protocol:  * 	CLOSE	->  *<-  CLOSE_CONFIRM  *  * 1.5:	uses variations of:  * 	IEOF	->  *<-  OCLOSE  *<-  IEOF  * 	OCLOSE	->  * 	i.e. both sides have to close the channel  *  * See the debugging output from 'ssh -v' and 'sshd -d' of  * ssh-1.2.27 as an example.  *  */
end_comment

begin_comment
comment|/* ssh-proto-1.5 overloads prot-1.3-message-types */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_CHANNEL_INPUT_EOF
value|SSH_MSG_CHANNEL_CLOSE
end_define

begin_define
define|#
directive|define
name|SSH_MSG_CHANNEL_OUTPUT_CLOSE
value|SSH_MSG_CHANNEL_CLOSE_CONFIRMATION
end_define

begin_comment
comment|/* possible input states */
end_comment

begin_define
define|#
directive|define
name|CHAN_INPUT_OPEN
value|0x01
end_define

begin_define
define|#
directive|define
name|CHAN_INPUT_WAIT_DRAIN
value|0x02
end_define

begin_define
define|#
directive|define
name|CHAN_INPUT_WAIT_OCLOSE
value|0x04
end_define

begin_define
define|#
directive|define
name|CHAN_INPUT_CLOSED
value|0x08
end_define

begin_comment
comment|/* possible output states */
end_comment

begin_define
define|#
directive|define
name|CHAN_OUTPUT_OPEN
value|0x10
end_define

begin_define
define|#
directive|define
name|CHAN_OUTPUT_WAIT_DRAIN
value|0x20
end_define

begin_define
define|#
directive|define
name|CHAN_OUTPUT_WAIT_IEOF
value|0x40
end_define

begin_define
define|#
directive|define
name|CHAN_OUTPUT_CLOSED
value|0x80
end_define

begin_comment
comment|/* EVENTS for the input state */
end_comment

begin_function_decl
name|void
name|chan_rcvd_oclose
parameter_list|(
name|Channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chan_read_failed
parameter_list|(
name|Channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chan_ibuf_empty
parameter_list|(
name|Channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* EVENTS for the output state */
end_comment

begin_function_decl
name|void
name|chan_rcvd_ieof
parameter_list|(
name|Channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chan_write_failed
parameter_list|(
name|Channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chan_obuf_empty
parameter_list|(
name|Channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chan_init_iostates
parameter_list|(
name|Channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

