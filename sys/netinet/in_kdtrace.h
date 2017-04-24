begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Mark Johnston<markj@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_IN_KDTRACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_IN_KDTRACE_H_
end_define

begin_define
define|#
directive|define
name|IP_PROBE
parameter_list|(
name|probe
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|)
define|\
value|SDT_PROBE6(ip, , , probe, arg0, arg1, arg2, arg3, arg4, arg5)
end_define

begin_define
define|#
directive|define
name|UDP_PROBE
parameter_list|(
name|probe
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
define|\
value|SDT_PROBE5(udp, , , probe, arg0, arg1, arg2, arg3, arg4)
end_define

begin_define
define|#
directive|define
name|TCP_PROBE1
parameter_list|(
name|probe
parameter_list|,
name|arg0
parameter_list|)
define|\
value|SDT_PROBE1(tcp, , , probe, arg0)
end_define

begin_define
define|#
directive|define
name|TCP_PROBE2
parameter_list|(
name|probe
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|)
define|\
value|SDT_PROBE2(tcp, , , probe, arg0, arg1)
end_define

begin_define
define|#
directive|define
name|TCP_PROBE3
parameter_list|(
name|probe
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|SDT_PROBE3(tcp, , , probe, arg0, arg1, arg2)
end_define

begin_define
define|#
directive|define
name|TCP_PROBE4
parameter_list|(
name|probe
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|SDT_PROBE4(tcp, , , probe, arg0, arg1, arg2, arg3)
end_define

begin_define
define|#
directive|define
name|TCP_PROBE5
parameter_list|(
name|probe
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
define|\
value|SDT_PROBE5(tcp, , , probe, arg0, arg1, arg2, arg3, arg4)
end_define

begin_define
define|#
directive|define
name|TCP_PROBE6
parameter_list|(
name|probe
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|)
define|\
value|SDT_PROBE6(tcp, , , probe, arg0, arg1, arg2, arg3, arg4, arg5)
end_define

begin_expr_stmt
name|SDT_PROVIDER_DECLARE
argument_list|(
name|ip
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROVIDER_DECLARE
argument_list|(
name|tcp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROVIDER_DECLARE
argument_list|(
name|udp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|ip
argument_list|, , ,
name|receive
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|ip
argument_list|, , ,
name|send
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|tcp
argument_list|, , ,
name|accept__established
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|tcp
argument_list|, , ,
name|accept__refused
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|tcp
argument_list|, , ,
name|connect__established
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|tcp
argument_list|, , ,
name|connect__refused
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|tcp
argument_list|, , ,
name|connect__request
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|tcp
argument_list|, , ,
name|receive
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|tcp
argument_list|, , ,
name|send
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|tcp
argument_list|, , ,
name|siftr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|tcp
argument_list|, , ,
name|state__change
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|tcp
argument_list|, , ,
name|debug__input
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|tcp
argument_list|, , ,
name|debug__output
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|tcp
argument_list|, , ,
name|debug__user
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|tcp
argument_list|, , ,
name|debug__drop
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|tcp
argument_list|, , ,
name|receive__autoresize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|udp
argument_list|, , ,
name|receive
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|udp
argument_list|, , ,
name|send
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

