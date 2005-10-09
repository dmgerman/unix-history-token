begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: base64.h,v 1.6 2003/08/29 16:59:52 mouring Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Portions Copyright (c) 1995 by International Business Machines, Inc.  *  * International Business Machines, Inc. (hereinafter called IBM) grants  * permission under its copyrights to use, copy, modify, and distribute this  * Software with or without fee, provided that the above copyright notice and  * all paragraphs of this notice appear in all copies, and that the name of IBM  * not be used in connection with the marketing of any product incorporating  * the Software or modifications thereof, without specific, written prior  * permission.  *  * To the extent it has a right to do so, IBM grants an immunity from suit  * under its patents, if any, for the use, sale or manufacture of products to  * the extent that such products are used for performing Domain Name System  * dynamic updates in TCP/IP networks by means of the Software.  No immunity is  * granted for any product per se or for any other function of any product.  *  * THE SOFTWARE IS PROVIDED "AS IS", AND IBM DISCLAIMS ALL WARRANTIES,  * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE.  IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL,  * DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER ARISING  * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE, EVEN  * IF IBM IS APPRISED OF THE POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_BASE64_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_BASE64_H
end_define

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE___B64_NTOP
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_B64_NTOP
end_ifndef

begin_function_decl
name|int
name|b64_ntop
parameter_list|(
name|u_char
specifier|const
modifier|*
name|src
parameter_list|,
name|size_t
name|srclength
parameter_list|,
name|char
modifier|*
name|target
parameter_list|,
name|size_t
name|targsize
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_B64_NTOP */
end_comment

begin_define
define|#
directive|define
name|__b64_ntop
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|b64_ntop(a,b,c,d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE___B64_NTOP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE___B64_PTON
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_B64_PTON
end_ifndef

begin_function_decl
name|int
name|b64_pton
parameter_list|(
name|char
specifier|const
modifier|*
name|src
parameter_list|,
name|u_char
modifier|*
name|target
parameter_list|,
name|size_t
name|targsize
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_B64_PTON */
end_comment

begin_define
define|#
directive|define
name|__b64_pton
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|b64_pton(a,b,c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE___B64_PTON */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_BASE64_H */
end_comment

end_unit

