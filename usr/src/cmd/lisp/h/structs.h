begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sccs id %W% %G% */
end_comment

begin_comment
comment|/*   * this file contains auxiliary structure definitions which are used by  * just a few files.  */
end_comment

begin_comment
comment|/* transfer table structures. */
end_comment

begin_define
define|#
directive|define
name|TRENTS
value|510
end_define

begin_struct
struct|struct
name|trent
block|{
name|lispval
function_decl|(
modifier|*
name|fcn
function_decl|)
parameter_list|()
function_decl|;
comment|/* function to call 			*/
name|lispval
name|name
decl_stmt|;
comment|/* symbol which is the function to call */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|trtab
block|{
name|struct
name|trtab
modifier|*
name|nxtt
decl_stmt|;
comment|/* pointer to next transfer table */
name|struct
name|trent
name|trentrs
index|[
name|TRENTS
index|]
decl_stmt|;
comment|/* entries			  */
name|int
name|sentinal
decl_stmt|;
comment|/* must be zero			  */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|heads
block|{
name|struct
name|heads
modifier|*
name|link
decl_stmt|;
name|char
modifier|*
name|pntr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|types
block|{
name|char
modifier|*
name|next_free
decl_stmt|;
name|int
name|space_left
decl_stmt|,
name|space
decl_stmt|,
name|type
decl_stmt|,
name|type_len
decl_stmt|;
comment|/*  note type_len is in units of int */
name|lispval
modifier|*
name|items
decl_stmt|,
modifier|*
name|pages
decl_stmt|,
modifier|*
name|type_name
decl_stmt|;
name|struct
name|heads
modifier|*
name|first
decl_stmt|;
block|}
struct|;
end_struct

end_unit

