begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   This software is available to you under a choice of one of two   licenses.  You may choose to be licensed under the terms of the GNU   General Public License (GPL) Version 2, available at<http://www.fsf.org/copyleft/gpl.html>, or the OpenIB.org BSD   license, available in the LICENSE.TXT file accompanying this   software.  These details are also available at<http://openib.org/license.html>.    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE   SOFTWARE.    Copyright (c) 2004 Topspin Communications.  All rights reserved.    $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SDP_INET_H
end_ifndef

begin_define
define|#
directive|define
name|_SDP_INET_H
end_define

begin_comment
comment|/*  * constants shared between user and kernel space.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SOLARIS_BUILD
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AF_INET_SDP
value|27
end_define

begin_comment
comment|/* SDP socket protocol family */
end_comment

begin_define
define|#
directive|define
name|AF_INET6_SDP
value|28
end_define

begin_comment
comment|/* SDP socket protocol family */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AF_INET_SDP
value|31
end_define

begin_comment
comment|/* This is an invalid family on native solaris                          * and will only work using QuickTransit */
end_comment

begin_comment
comment|//TODO XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx
end_comment

begin_define
define|#
directive|define
name|AF_INET6_SDP
value|32
end_define

begin_comment
comment|/* SDP socket protocol family */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AF_INET_STR
value|"AF_INET_SDP"
end_define

begin_comment
comment|/* SDP enabled environment variable */
end_comment

begin_define
define|#
directive|define
name|AF_INET6_STR
value|"AF_INET6_SDP"
end_define

begin_comment
comment|/* SDP enabled environment variable */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SDP_ZCOPY_THRESH
end_ifndef

begin_define
define|#
directive|define
name|SDP_ZCOPY_THRESH
value|80
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SDP_LAST_BIND_ERR
end_ifndef

begin_define
define|#
directive|define
name|SDP_LAST_BIND_ERR
value|81
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
comment|/* _SDP_INET_H */
end_comment

end_unit

