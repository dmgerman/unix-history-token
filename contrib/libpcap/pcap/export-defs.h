begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* -*- Mode: c; tab-width: 8; indent-tabs-mode: 1; c-basic-offset: 8; -*- */
end_comment

begin_comment
comment|/*  * Copyright (c) 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the Computer Systems  *	Engineering Group at Lawrence Berkeley Laboratory.  * 4. Neither the name of the University nor of the Laboratory may be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lib_pcap_export_defs_h
end_ifndef

begin_define
define|#
directive|define
name|lib_pcap_export_defs_h
end_define

begin_comment
comment|/*  * PCAP_API_DEF must be used when defining *data* exported from  * libpcap.  It can be used when defining *functions* exported  * from libpcap, but it doesn't have to be used there.  It  * should not be used in declarations in headers.  *  * PCAP_API must be used when *declaring* data or functions  * exported from libpcap; PCAP_API_DEF won't work on all platforms.  */
end_comment

begin_comment
comment|/*  * Check whether this is GCC major.minor or a later release, or some  * compiler that claims to be "just like GCC" of that version or a  * later release.  */
end_comment

begin_define
define|#
directive|define
name|IS_AT_LEAST_GNUC_VERSION
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|)
define|\
value|(defined(__GNUC__)&& \ 	    (__GNUC__> (major) || \ 	     (__GNUC__ == (major)&& __GNUC_MINOR__>= (minor))))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|BUILDING_PCAP
end_ifdef

begin_comment
comment|/*      * We're compiling libpcap, so we should export functions in our      * API.      */
end_comment

begin_define
define|#
directive|define
name|PCAP_API_DEF
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PCAP_API_DEF
value|__declspec(dllimport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_elif

begin_comment
comment|/* XXX - does this need special treatment? */
end_comment

begin_define
define|#
directive|define
name|PCAP_API_DEF
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* UN*X */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BUILDING_PCAP
end_ifdef

begin_comment
comment|/*      * We're compiling libpcap, so we should export functions in our API.      * The compiler might be configured not to export functions from a      * shared library by default, so we might have to explicitly mark      * functions as exported.      */
end_comment

begin_if
if|#
directive|if
name|IS_AT_LEAST_GNUC_VERSION
argument_list|(
literal|3
operator|,
literal|4
argument_list|)
end_if

begin_comment
comment|/*        * GCC 3.4 or later, or some compiler asserting compatibility with        * GCC 3.4 or later, so we have __attribute__((visibility()).        */
end_comment

begin_define
define|#
directive|define
name|PCAP_API_DEF
value|__attribute__((visibility("default")))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__SUNPRO_C
argument_list|)
operator|&&
operator|(
name|__SUNPRO_C
operator|>=
literal|0x550
operator|)
end_elif

begin_comment
comment|/*        * Sun C 5.5 or later, so we have __global.        * (Sun C 5.9 and later also have __attribute__((visibility()),        * but there's no reason to prefer it with Sun C.)        */
end_comment

begin_define
define|#
directive|define
name|PCAP_API_DEF
value|__global
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*        * We don't have anything to say.        */
end_comment

begin_define
define|#
directive|define
name|PCAP_API_DEF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*      * We're not building libpcap.      */
end_comment

begin_define
define|#
directive|define
name|PCAP_API_DEF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WIN32/MSDOS/UN*X */
end_comment

begin_define
define|#
directive|define
name|PCAP_API
value|PCAP_API_DEF extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lib_pcap_export_defs_h */
end_comment

end_unit

