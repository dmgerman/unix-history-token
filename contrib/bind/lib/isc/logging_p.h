begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOGGING_P_H
end_ifndef

begin_define
define|#
directive|define
name|LOGGING_P_H
end_define

begin_typedef
typedef|typedef
struct|struct
name|log_file_desc
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|size_t
name|name_size
decl_stmt|;
name|FILE
modifier|*
name|stream
decl_stmt|;
name|unsigned
name|int
name|versions
decl_stmt|;
name|unsigned
name|long
name|max_size
decl_stmt|;
block|}
name|log_file_desc
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|log_output
block|{
name|int
name|facility
decl_stmt|;
name|log_file_desc
name|file
decl_stmt|;
block|}
name|log_output
typedef|;
end_typedef

begin_struct
struct|struct
name|log_channel
block|{
name|int
name|level
decl_stmt|;
comment|/* don't log messages> level */
name|log_channel_type
name|type
decl_stmt|;
name|log_output
name|out
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
name|int
name|references
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|log_channel_list
block|{
name|log_channel
name|channel
decl_stmt|;
name|struct
name|log_channel_list
modifier|*
name|next
decl_stmt|;
block|}
typedef|*
name|log_channel_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LOG_BUFFER_SIZE
value|20480
end_define

begin_struct
struct|struct
name|log_context
block|{
name|int
name|num_categories
decl_stmt|;
name|char
modifier|*
modifier|*
name|category_names
decl_stmt|;
name|log_channel_list
modifier|*
name|categories
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|int
name|level
decl_stmt|;
name|char
name|buffer
index|[
name|LOG_BUFFER_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOGGING_P_H */
end_comment

end_unit

