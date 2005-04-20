begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Mike Barcroft<mike@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FMTMSG_H_
end_ifndef

begin_define
define|#
directive|define
name|_FMTMSG_H_
end_define

begin_comment
comment|/* Source of condition is... */
end_comment

begin_define
define|#
directive|define
name|MM_HARD
value|0x0001
end_define

begin_comment
comment|/* ...hardware. */
end_comment

begin_define
define|#
directive|define
name|MM_SOFT
value|0x0002
end_define

begin_comment
comment|/* ...software. */
end_comment

begin_define
define|#
directive|define
name|MM_FIRM
value|0x0004
end_define

begin_comment
comment|/* ...fireware. */
end_comment

begin_comment
comment|/* Condition detected by... */
end_comment

begin_define
define|#
directive|define
name|MM_APPL
value|0x0010
end_define

begin_comment
comment|/* ...application. */
end_comment

begin_define
define|#
directive|define
name|MM_UTIL
value|0x0020
end_define

begin_comment
comment|/* ...utility. */
end_comment

begin_define
define|#
directive|define
name|MM_OPSYS
value|0x0040
end_define

begin_comment
comment|/* ...operating system. */
end_comment

begin_comment
comment|/* Display on... */
end_comment

begin_define
define|#
directive|define
name|MM_PRINT
value|0x0100
end_define

begin_comment
comment|/* ...standard error. */
end_comment

begin_define
define|#
directive|define
name|MM_CONSOLE
value|0x0200
end_define

begin_comment
comment|/* ...system console. */
end_comment

begin_define
define|#
directive|define
name|MM_RECOVER
value|0x1000
end_define

begin_comment
comment|/* Recoverable error. */
end_comment

begin_define
define|#
directive|define
name|MM_NRECOV
value|0x2000
end_define

begin_comment
comment|/* Non-recoverable error. */
end_comment

begin_comment
comment|/* Severity levels. */
end_comment

begin_define
define|#
directive|define
name|MM_NOSEV
value|0
end_define

begin_comment
comment|/* No severity level provided. */
end_comment

begin_define
define|#
directive|define
name|MM_HALT
value|1
end_define

begin_comment
comment|/* Error causing application to halt. */
end_comment

begin_define
define|#
directive|define
name|MM_ERROR
value|2
end_define

begin_comment
comment|/* Non-fault fault. */
end_comment

begin_define
define|#
directive|define
name|MM_WARNING
value|3
end_define

begin_comment
comment|/* Unusual non-error condition. */
end_comment

begin_define
define|#
directive|define
name|MM_INFO
value|4
end_define

begin_comment
comment|/* Informative message. */
end_comment

begin_comment
comment|/* Null options. */
end_comment

begin_define
define|#
directive|define
name|MM_NULLLBL
value|(char *)0
end_define

begin_define
define|#
directive|define
name|MM_NULLSEV
value|0
end_define

begin_define
define|#
directive|define
name|MM_NULLMC
value|0L
end_define

begin_define
define|#
directive|define
name|MM_NULLTXT
value|(char *)0
end_define

begin_define
define|#
directive|define
name|MM_NULLACT
value|(char *)0
end_define

begin_define
define|#
directive|define
name|MM_NULLTAG
value|(char *)0
end_define

begin_comment
comment|/* Return values. */
end_comment

begin_define
define|#
directive|define
name|MM_OK
value|0
end_define

begin_comment
comment|/* Success. */
end_comment

begin_define
define|#
directive|define
name|MM_NOMSG
value|1
end_define

begin_comment
comment|/* Failed to output to stderr. */
end_comment

begin_define
define|#
directive|define
name|MM_NOCON
value|2
end_define

begin_comment
comment|/* Failed to output to console. */
end_comment

begin_define
define|#
directive|define
name|MM_NOTOK
value|3
end_define

begin_comment
comment|/* Failed to output anything. */
end_comment

begin_function_decl
name|int
name|fmtmsg
parameter_list|(
name|long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FMTMSG_H_ */
end_comment

end_unit

