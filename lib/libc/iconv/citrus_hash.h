begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: citrus_hash.h,v 1.3 2004/01/02 21:49:35 itojun Exp $ */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause  *  * Copyright (c)2003 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_HASH_H_
end_ifndef

begin_define
define|#
directive|define
name|_CITRUS_HASH_H_
end_define

begin_define
define|#
directive|define
name|_CITRUS_HASH_ENTRY
parameter_list|(
name|type
parameter_list|)
value|LIST_ENTRY(type)
end_define

begin_define
define|#
directive|define
name|_CITRUS_HASH_HEAD
parameter_list|(
name|headname
parameter_list|,
name|type
parameter_list|,
name|hashsize
parameter_list|)
define|\
value|struct headname {					\ 	LIST_HEAD(, type)	chh_table[hashsize];	\ }
end_define

begin_define
define|#
directive|define
name|_CITRUS_HASH_INIT
parameter_list|(
name|head
parameter_list|,
name|hashsize
parameter_list|)
define|\
value|do {								\ 	int _ch_loop;						\ 								\ 	for (_ch_loop = 0; _ch_loop< hashsize; _ch_loop++)	\ 		LIST_INIT(&(head)->chh_table[_ch_loop]);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|_CITRUS_HASH_REMOVE
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|LIST_REMOVE(elm, field)
end_define

begin_define
define|#
directive|define
name|_CITRUS_HASH_INSERT
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|,
name|hashval
parameter_list|)
define|\
value|LIST_INSERT_HEAD(&(head)->chh_table[hashval], elm, field)
end_define

begin_define
define|#
directive|define
name|_CITRUS_HASH_SEARCH
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|,
name|matchfunc
parameter_list|,
name|key
parameter_list|,
name|hashval
parameter_list|)
define|\
value|do {									\ 	LIST_FOREACH((elm),&(head)->chh_table[hashval], field)		\ 		if (matchfunc((elm), key) == 0)				\ 			break;						\ } while (0)
end_define

begin_function_decl
name|__BEGIN_DECLS
name|int
name|_citrus_string_hash_func
parameter_list|(
specifier|const
name|char
modifier|*
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

end_unit

