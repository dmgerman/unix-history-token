begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright 2010 Nexenta Systems, Inc.  All rights reserved.  * Copyright (c) 1995 Alex Tatmanjants<alex@elvisti.kiev.ua>  *		at Electronni Visti IA, Kiev, Ukraine.  *			All rights reserved.  *  * Copyright (c) 2011 The FreeBSD Foundation  * All rights reserved.  * Portions of this software were developed by David Chisnall  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COLLATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_COLLATE_H_
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

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|"xlocale_private.h"
end_include

begin_comment
comment|/*  * Work around buildworld bootstrapping from older systems whose limits.h  * sets COLL_WEIGHTS_MAX to 0.  */
end_comment

begin_if
if|#
directive|if
name|COLL_WEIGHTS_MAX
operator|==
literal|0
end_if

begin_undef
undef|#
directive|undef
name|COLL_WEIGHTS_MAX
end_undef

begin_define
define|#
directive|define
name|COLL_WEIGHTS_MAX
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|COLLATE_STR_LEN
value|24
end_define

begin_comment
comment|/* should be 64-bit multiple */
end_comment

begin_define
define|#
directive|define
name|COLLATE_VERSION
value|"BSD 1.0\n"
end_define

begin_define
define|#
directive|define
name|COLLATE_MAX_PRIORITY
value|(0x7fffffff)
end_define

begin_comment
comment|/* max signed value */
end_comment

begin_define
define|#
directive|define
name|COLLATE_SUBST_PRIORITY
value|(0x40000000)
end_define

begin_comment
comment|/* bit indicates subst table */
end_comment

begin_define
define|#
directive|define
name|DIRECTIVE_UNDEF
value|0x00
end_define

begin_define
define|#
directive|define
name|DIRECTIVE_FORWARD
value|0x01
end_define

begin_define
define|#
directive|define
name|DIRECTIVE_BACKWARD
value|0x02
end_define

begin_define
define|#
directive|define
name|DIRECTIVE_POSITION
value|0x04
end_define

begin_define
define|#
directive|define
name|DIRECTIVE_UNDEFINED
value|0x08
end_define

begin_comment
comment|/* special last weight for UNDEFINED */
end_comment

begin_define
define|#
directive|define
name|DIRECTIVE_DIRECTION_MASK
value|(DIRECTIVE_FORWARD | DIRECTIVE_BACKWARD)
end_define

begin_comment
comment|/*  * The collate file format is as follows:  *  * char		version[COLLATE_STR_LEN];	// must be COLLATE_VERSION  * collate_info_t	info;			// see below, includes padding  * collate_char_pri_t	char_data[256];		// 8 bit char values  * collate_subst_t	subst[*];		// 0 or more substitutions  * collate_chain_pri_t	chains[*];		// 0 or more chains  * collate_large_pri_t	large[*];		// extended char priorities  *  * Note that all structures must be 32-bit aligned, as each structure  * contains 32-bit member fields.  The entire file is mmap'd, so its  * critical that alignment be observed.  It is not generally safe to  * use any 64-bit values in the structures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|collate_info
block|{
name|uint8_t
name|directive_count
decl_stmt|;
name|uint8_t
name|directive
index|[
name|COLL_WEIGHTS_MAX
index|]
decl_stmt|;
name|int32_t
name|pri_count
index|[
name|COLL_WEIGHTS_MAX
index|]
decl_stmt|;
name|int32_t
name|flags
decl_stmt|;
name|int32_t
name|chain_count
decl_stmt|;
name|int32_t
name|large_count
decl_stmt|;
name|int32_t
name|subst_count
index|[
name|COLL_WEIGHTS_MAX
index|]
decl_stmt|;
name|int32_t
name|undef_pri
index|[
name|COLL_WEIGHTS_MAX
index|]
decl_stmt|;
block|}
name|collate_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|collate_char
block|{
name|int32_t
name|pri
index|[
name|COLL_WEIGHTS_MAX
index|]
decl_stmt|;
block|}
name|collate_char_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|collate_chain
block|{
name|wchar_t
name|str
index|[
name|COLLATE_STR_LEN
index|]
decl_stmt|;
name|int32_t
name|pri
index|[
name|COLL_WEIGHTS_MAX
index|]
decl_stmt|;
block|}
name|collate_chain_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|collate_large
block|{
name|int32_t
name|val
decl_stmt|;
name|collate_char_t
name|pri
decl_stmt|;
block|}
name|collate_large_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|collate_subst
block|{
name|int32_t
name|key
decl_stmt|;
name|int32_t
name|pri
index|[
name|COLLATE_STR_LEN
index|]
decl_stmt|;
block|}
name|collate_subst_t
typedef|;
end_typedef

begin_struct
struct|struct
name|xlocale_collate
block|{
name|struct
name|xlocale_component
name|header
decl_stmt|;
name|int
name|__collate_load_error
decl_stmt|;
name|char
modifier|*
name|map
decl_stmt|;
name|size_t
name|maplen
decl_stmt|;
name|collate_info_t
modifier|*
name|info
decl_stmt|;
name|collate_char_t
modifier|*
name|char_pri_table
decl_stmt|;
name|collate_large_t
modifier|*
name|large_pri_table
decl_stmt|;
name|collate_chain_t
modifier|*
name|chain_pri_table
decl_stmt|;
name|collate_subst_t
modifier|*
name|subst_table
index|[
name|COLL_WEIGHTS_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|__BEGIN_DECLS
name|int
name|__collate_load_tables
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__collate_equiv_value
parameter_list|(
name|locale_t
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_collate_lookup
parameter_list|(
name|struct
name|xlocale_collate
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|int
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__collate_range_cmp
parameter_list|(
name|char
parameter_list|,
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__wcollate_range_cmp
parameter_list|(
name|wchar_t
parameter_list|,
name|wchar_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|_collate_wxfrm
parameter_list|(
name|struct
name|xlocale_collate
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|wchar_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|_collate_sxfrm
parameter_list|(
name|struct
name|xlocale_collate
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
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
comment|/* !_COLLATE_H_ */
end_comment

end_unit

