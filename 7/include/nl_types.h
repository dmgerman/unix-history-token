begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: nl_types.h,v 1.9 2000/10/03 19:53:32 sommerfeld Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by J.T. Conklin.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NL_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_NL_TYPES_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_NLS_PRIVATE
end_ifdef

begin_comment
comment|/*  * MESSAGE CATALOG FILE FORMAT.  *  * The NetBSD/FreeBSD message catalog format is similar to the format used by  * Svr4 systems.  The differences are:  *   * fixed byte order (big endian)  *   * fixed data field sizes  *  * A message catalog contains four data types: a catalog header, one  * or more set headers, one or more message headers, and one or more  * text strings.  */
end_comment

begin_define
define|#
directive|define
name|_NLS_MAGIC
value|0xff88ff89
end_define

begin_struct
struct|struct
name|_nls_cat_hdr
block|{
name|int32_t
name|__magic
decl_stmt|;
name|int32_t
name|__nsets
decl_stmt|;
name|int32_t
name|__mem
decl_stmt|;
name|int32_t
name|__msg_hdr_offset
decl_stmt|;
name|int32_t
name|__msg_txt_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_nls_set_hdr
block|{
name|int32_t
name|__setno
decl_stmt|;
comment|/* set number: 0< x<= NL_SETMAX */
name|int32_t
name|__nmsgs
decl_stmt|;
comment|/* number of messages in the set  */
name|int32_t
name|__index
decl_stmt|;
comment|/* index of first msg_hdr in msg_hdr table */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_nls_msg_hdr
block|{
name|int32_t
name|__msgno
decl_stmt|;
comment|/* msg number: 0< x<= NL_MSGMAX */
name|int32_t
name|__msglen
decl_stmt|;
name|int32_t
name|__offset
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NLS_PRIVATE */
end_comment

begin_define
define|#
directive|define
name|NL_SETD
value|0
end_define

begin_define
define|#
directive|define
name|NL_CAT_LOCALE
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|__nl_cat_d
block|{
name|void
modifier|*
name|__data
decl_stmt|;
name|int
name|__size
decl_stmt|;
block|}
typedef|*
name|nl_catd
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_NL_ITEM_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__nl_item
name|nl_item
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_NL_ITEM_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|__BEGIN_DECLS
name|nl_catd
name|catopen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|catgets
parameter_list|(
name|nl_catd
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|__format_arg
parameter_list|(
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|catclose
parameter_list|(
name|nl_catd
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
comment|/* _NL_TYPES_H_ */
end_comment

end_unit

