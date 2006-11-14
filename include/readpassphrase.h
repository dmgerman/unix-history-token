begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: /usr/local/www/cvsroot/OpenBSD/src/include/readpassphrase.h,v 1.2 2002/02/16 21:27:17 millert Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 Todd C. Miller<Todd.Miller@courtesan.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
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

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_READPASSPHRASE_H_ */
end_comment

end_unit

