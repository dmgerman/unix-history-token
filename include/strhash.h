begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_STRHASH_H_INCLUDE
end_ifndef

begin_define
define|#
directive|define
name|_STRHASH_H_INCLUDE
end_define

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  *  *                      Copyright 1990  *               Terry Jones& Jordan Hubbard  *  *		  PCS Computer Systeme, GmbH.  *	             Munich, West Germany  *  *  *  All rights reserved.  *  *  This is unsupported software and is subject to change without notice.  *  the author makes no representations about the suitability of this software  *  for any purpose. It is supplied "as is" without express or implied  *  warranty.  *  *  Permission to use, copy, modify, and distribute this software and its  *  documentation for any purpose and without fee is hereby granted, provided  *  that the above copyright notice appear in all copies and that both that  *  copyright notice and this permission notice appear in supporting  *  documentation, and that the name of the author not be used in  *  advertising or publicity pertaining to distribution of the software  *  without specific, written prior permission.  *  */
end_comment

begin_comment
comment|/*  * This is the definition file for hash.c. The plunderer from down-under  * did the code, I just helped define the spec. That's why his name gets  * to go first.  */
end_comment

begin_define
define|#
directive|define
name|HASH_SZ
value|97
end_define

begin_typedef
typedef|typedef
struct|struct
name|_node
block|{
name|char
modifier|*
name|key
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|struct
name|_node
modifier|*
name|next
decl_stmt|;
block|}
name|hash_node
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|size
decl_stmt|;
name|hash_node
modifier|*
modifier|*
name|buckets
decl_stmt|;
block|}
name|hash_table
typedef|;
end_typedef

begin_function_decl
name|hash_table
modifier|*
name|hash_create
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hash_destroy
parameter_list|(
name|hash_table
modifier|*
name|table
parameter_list|,
name|char
modifier|*
name|key
parameter_list|,
name|void
function_decl|(
modifier|*
name|nukefunc
function_decl|)
parameter_list|(
name|char
modifier|*
name|k
parameter_list|,
name|void
modifier|*
name|d
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|hash_search
parameter_list|(
name|hash_table
modifier|*
name|table
parameter_list|,
name|char
modifier|*
name|key
parameter_list|,
name|void
modifier|*
name|datum
parameter_list|,
name|void
function_decl|(
modifier|*
name|replace_func
function_decl|)
parameter_list|(
name|void
modifier|*
name|d
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hash_traverse
parameter_list|(
name|hash_table
modifier|*
name|table
parameter_list|,
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|char
modifier|*
name|k
parameter_list|,
name|void
modifier|*
name|d
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hash_purge
parameter_list|(
name|hash_table
modifier|*
name|table
parameter_list|,
name|void
function_decl|(
modifier|*
name|purge_func
function_decl|)
parameter_list|(
name|char
modifier|*
name|k
parameter_list|,
name|void
modifier|*
name|d
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HASH_STATS
end_ifdef

begin_function_decl
specifier|extern
name|void
name|hash_stats
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STRHASH_H_INCLUDE */
end_comment

end_unit

