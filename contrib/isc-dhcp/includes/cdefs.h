begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* cdefs.h     Standard C definitions... */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 RadioMail Corporation.  All rights reserved.  * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")  * Copyright (c) 1996-2003 by Internet Software Consortium  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *   Internet Systems Consortium, Inc.  *   950 Charter Street  *   Redwood City, CA 94063  *<info@isc.org>  *   http://www.isc.org/  *  * This software was written for RadioMail Corporation by Ted Lemon  * under a contract with Vixie Enterprises.   Further modifications have  * been made for Internet Systems Consortium under a contract  * with Vixie Laboratories.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__ISC_DHCP_CDEFS_H__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__ISC_DHCP_CDEFS_H__
end_define

begin_comment
comment|/* Delete attributes if not gcc or not the right version of gcc. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|__GNUC__
operator|<
literal|2
operator|||
expr|\
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|5
operator|)
operator|||
name|defined
argument_list|(
name|darwin
argument_list|)
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|BROKEN_ANSI
argument_list|)
end_if

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|KandR
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ANSI_DECL
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|INLINE
value|inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|KandR
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|ANSI_DECL
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|INLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ || __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ISC_DHCP_CDEFS_H__ */
end_comment

end_unit

