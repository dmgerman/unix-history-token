begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R88E_ROM_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|R88E_ROM_DEFS_H
end_define

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8192c/r92c_rom_defs.h>
end_include

begin_define
define|#
directive|define
name|R88E_GROUP_2G
value|6
end_define

begin_define
define|#
directive|define
name|R88E_EFUSE_MAX_LEN
value|256
end_define

begin_define
define|#
directive|define
name|R88E_EFUSE_MAP_LEN
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* R88E_ROM_DEFS_H */
end_comment

end_unit

