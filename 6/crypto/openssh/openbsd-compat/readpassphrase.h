begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: readpassphrase.h,v 1.5 2003/06/17 21:56:23 millert Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2000, 2002 Todd C. Miller<Todd.Miller@courtesan.com>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Sponsored in part by the Defense Advanced Research Projects  * Agency (DARPA) and Air Force Research Laboratory, Air Force  * Materiel Command, USAF, under agreement number F39502-99-1-0512.  */
end_comment

begin_comment
comment|/* OPENBSD ORIGINAL: include/readpassphrase.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_READPASSPHRASE_H_
end_ifndef

begin_define
define|#
directive|define
name|_READPASSPHRASE_H_
end_define

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_READPASSPHRASE
end_ifndef

begin_define
define|#
directive|define
name|RPP_ECHO_OFF
value|0x00
end_define

begin_comment
comment|/* Turn off echo (default). */
end_comment

begin_define
define|#
directive|define
name|RPP_ECHO_ON
value|0x01
end_define

begin_comment
comment|/* Leave echo on. */
end_comment

begin_define
define|#
directive|define
name|RPP_REQUIRE_TTY
value|0x02
end_define

begin_comment
comment|/* Fail if there is no tty. */
end_comment

begin_define
define|#
directive|define
name|RPP_FORCELOWER
value|0x04
end_define

begin_comment
comment|/* Force input to lower case. */
end_comment

begin_define
define|#
directive|define
name|RPP_FORCEUPPER
value|0x08
end_define

begin_comment
comment|/* Force input to upper case. */
end_comment

begin_define
define|#
directive|define
name|RPP_SEVENBIT
value|0x10
end_define

begin_comment
comment|/* Strip the high bit from input. */
end_comment

begin_define
define|#
directive|define
name|RPP_STDIN
value|0x20
end_define

begin_comment
comment|/* Read from stdin, not /dev/tty */
end_comment

begin_function_decl
name|char
modifier|*
name|readpassphrase
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_READPASSPHRASE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_READPASSPHRASE_H_ */
end_comment

end_unit

