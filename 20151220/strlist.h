begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: strlist.h,v 1.3 2009/01/16 21:15:34 dsl Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 - 2009 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by David Laight.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STRLIST_H
end_ifndef

begin_define
define|#
directive|define
name|_STRLIST_H
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|si_str
decl_stmt|;
name|unsigned
name|int
name|si_info
decl_stmt|;
block|}
name|strlist_item_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|sl_num
decl_stmt|;
name|unsigned
name|int
name|sl_max
decl_stmt|;
name|strlist_item_t
modifier|*
name|sl_items
decl_stmt|;
block|}
name|strlist_t
typedef|;
end_typedef

begin_function_decl
name|void
name|strlist_init
parameter_list|(
name|strlist_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|strlist_clean
parameter_list|(
name|strlist_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|strlist_add_str
parameter_list|(
name|strlist_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|strlist_num
parameter_list|(
name|sl
parameter_list|)
value|((sl)->sl_num)
end_define

begin_define
define|#
directive|define
name|strlist_str
parameter_list|(
name|sl
parameter_list|,
name|n
parameter_list|)
value|((sl)->sl_items[n].si_str)
end_define

begin_define
define|#
directive|define
name|strlist_info
parameter_list|(
name|sl
parameter_list|,
name|n
parameter_list|)
value|((sl)->sl_items[n].si_info)
end_define

begin_define
define|#
directive|define
name|strlist_set_info
parameter_list|(
name|sl
parameter_list|,
name|n
parameter_list|,
name|v
parameter_list|)
value|((void)((sl)->sl_items[n].si_info = (v)))
end_define

begin_define
define|#
directive|define
name|STRLIST_FOREACH
parameter_list|(
name|v
parameter_list|,
name|sl
parameter_list|,
name|index
parameter_list|)
define|\
value|if ((sl)->sl_items != NULL) \ 	for (index = 0; (v = strlist_str(sl, index)) != NULL; index++)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STRLIST_H */
end_comment

end_unit

