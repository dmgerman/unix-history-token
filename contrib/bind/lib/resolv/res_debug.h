begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RES_DEBUG_H_
end_ifndef

begin_define
define|#
directive|define
name|_RES_DEBUG_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG
end_ifndef

begin_define
define|#
directive|define
name|Dprint
parameter_list|(
name|cond
parameter_list|,
name|args
parameter_list|)
end_define

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|DprintQ
parameter_list|(
name|cond
parameter_list|,
name|args
parameter_list|,
name|query
parameter_list|,
name|size
parameter_list|)
end_define

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|Aerror
parameter_list|(
name|statp
parameter_list|,
name|file
parameter_list|,
name|string
parameter_list|,
name|error
parameter_list|,
name|address
parameter_list|)
end_define

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|Perror
parameter_list|(
name|statp
parameter_list|,
name|file
parameter_list|,
name|string
parameter_list|,
name|error
parameter_list|)
end_define

begin_comment
comment|/*empty*/
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Dprint
parameter_list|(
name|cond
parameter_list|,
name|args
parameter_list|)
value|if (cond) {fprintf args;} else {}
end_define

begin_define
define|#
directive|define
name|DprintQ
parameter_list|(
name|cond
parameter_list|,
name|args
parameter_list|,
name|query
parameter_list|,
name|size
parameter_list|)
value|if (cond) {\ 			fprintf args;\ 			res_pquery(statp, query, size, stdout);\ 		} else {}
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
comment|/* _RES_DEBUG_H_ */
end_comment

end_unit

