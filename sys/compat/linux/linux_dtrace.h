begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008-2012 Alexander Leidinger<netchild@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_DTRACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_DTRACE_H_
end_define

begin_comment
comment|/**  * DTrace support macros for the linuxulator.  *  * Some wrapper macros to make it more easy to handle the linuxulator  * providers and to allow to make the name depend upon the bitsize.  *  * Basically this is the same as the normal SDT macros in sys/sdt.h. The  * difference is that the provider name is automatically inserted, and  * we do not use a different name for the probe-description.  */
end_comment

begin_define
define|#
directive|define
name|LIN_SDT_PROVIDER_DEFINE
parameter_list|(
name|x
parameter_list|)
value|SDT_PROVIDER_DEFINE(x)
end_define

begin_define
define|#
directive|define
name|LIN_SDT_PROVIDER_DECLARE
parameter_list|(
name|x
parameter_list|)
value|SDT_PROVIDER_DECLARE(x)
end_define

begin_define
define|#
directive|define
name|_LIN_SDT_PROBE_DECLARE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|SDT_PROBE_DECLARE(a, b, c, d)
end_define

begin_define
define|#
directive|define
name|LIN_SDT_PROBE_DECLARE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|_LIN_SDT_PROBE_DECLARE( \     LINUX_DTRACE, a, b, c)
end_define

begin_define
define|#
directive|define
name|_LIN_SDT_PROBE_DEFINE0
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|SDT_PROBE_DEFINE(a, \     b, c, d)
end_define

begin_define
define|#
directive|define
name|LIN_SDT_PROBE_DEFINE0
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|_LIN_SDT_PROBE_DEFINE0(\     LINUX_DTRACE, a, b, c)
end_define

begin_define
define|#
directive|define
name|_LIN_SDT_PROBE_DEFINE1
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|SDT_PROBE_DEFINE1(a, \     b, c, d, e)
end_define

begin_define
define|#
directive|define
name|LIN_SDT_PROBE_DEFINE1
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|_LIN_SDT_PROBE_DEFINE1(\     LINUX_DTRACE, a, b, c, d)
end_define

begin_define
define|#
directive|define
name|_LIN_SDT_PROBE_DEFINE2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
value|SDT_PROBE_DEFINE2(a, \     b, c, d, e, f)
end_define

begin_define
define|#
directive|define
name|LIN_SDT_PROBE_DEFINE2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|_LIN_SDT_PROBE_DEFINE2(\     LINUX_DTRACE, a, b, c, d, e)
end_define

begin_define
define|#
directive|define
name|_LIN_SDT_PROBE_DEFINE3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|)
value|SDT_PROBE_DEFINE3(a, \     b, c, d, e, f, g)
end_define

begin_define
define|#
directive|define
name|LIN_SDT_PROBE_DEFINE3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
value|_LIN_SDT_PROBE_DEFINE3(\     LINUX_DTRACE, a, b, c, d, e, f)
end_define

begin_define
define|#
directive|define
name|_LIN_SDT_PROBE_DEFINE4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|,
name|h
parameter_list|)
value|SDT_PROBE_DEFINE4(a, \     b, c, d, e, f, g, h)
end_define

begin_define
define|#
directive|define
name|LIN_SDT_PROBE_DEFINE4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|)
value|_LIN_SDT_PROBE_DEFINE4(\     LINUX_DTRACE, a, b, c, d, e, f, g)
end_define

begin_define
define|#
directive|define
name|_LIN_SDT_PROBE_DEFINE5
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|,
name|h
parameter_list|,
name|i
parameter_list|)
define|\
value|SDT_PROBE_DEFINE5(a, b, c, d, e, f, g, h, i)
end_define

begin_define
define|#
directive|define
name|LIN_SDT_PROBE_DEFINE5
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|,
name|h
parameter_list|)
value|_LIN_SDT_PROBE_DEFINE5(\     LINUX_DTRACE, a, b, c, d, e, f, g, h)
end_define

begin_define
define|#
directive|define
name|LIN_SDT_PROBE0
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|SDT_PROBE1(LINUX_DTRACE, a, b, \     c, 0)
end_define

begin_define
define|#
directive|define
name|LIN_SDT_PROBE1
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|SDT_PROBE1(LINUX_DTRACE, a, b, \     c, d)
end_define

begin_define
define|#
directive|define
name|LIN_SDT_PROBE2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|SDT_PROBE2(LINUX_DTRACE, a, b, \     c, d, e)
end_define

begin_define
define|#
directive|define
name|LIN_SDT_PROBE3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
value|SDT_PROBE3(LINUX_DTRACE, a, b, \     c, d, e, f)
end_define

begin_define
define|#
directive|define
name|LIN_SDT_PROBE4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|)
value|SDT_PROBE4(LINUX_DTRACE, a, b, \     c, d, e, f, g)
end_define

begin_define
define|#
directive|define
name|_LIN_SDT_PROBE5
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|,
name|h
parameter_list|,
name|i
parameter_list|)
value|SDT_PROBE(a, b, c, d, \     e, f, g, h, i)
end_define

begin_define
define|#
directive|define
name|LIN_SDT_PROBE5
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|,
name|h
parameter_list|)
value|_LIN_SDT_PROBE5(LINUX_DTRACE, \     a, b, c, d, e, f, g, h)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_DTRACE_H_ */
end_comment

end_unit

