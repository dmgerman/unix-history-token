begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Adrian Chadd<adrian@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_IWN_IOCTL_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_IWN_IOCTL_H__
end_define

begin_comment
comment|/* XXX how should I pick appropriate ioctl numbers? */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWNSTATS
value|_IOWR('i', 145, struct ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCZIWNSTATS
value|_IOWR('i', 146, struct ifreq)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_IWN_IOCTL_H__ */
end_comment

end_unit

