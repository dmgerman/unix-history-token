begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Singly-linked key+string list definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Singly-linked key+string list macros  */
end_comment

begin_define
define|#
directive|define
name|SLSNUM
parameter_list|(
name|slslist
parameter_list|)
value|(slslist)->nk
end_define

begin_comment
comment|/*  * Singly-linked key+string list block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_slsblk
block|{
name|char
modifier|*
name|key
decl_stmt|;
comment|/* points to key */
name|char
modifier|*
name|string
decl_stmt|;
comment|/* points to non-key string */
name|struct
name|_slsblk
modifier|*
name|next
decl_stmt|;
comment|/* ptr to next list block */
block|}
name|SLSBLK
typedef|;
end_typedef

begin_comment
comment|/*  * Singly-linked key+string list head block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_slslisthb
block|{
name|int
name|nk
decl_stmt|;
comment|/* number of keys in list */
name|int
name|maxkey
decl_stmt|;
comment|/* length of longest key */
name|int
name|maxstr
decl_stmt|;
comment|/* length of longest non-key string */
name|SLSBLK
modifier|*
name|head
decl_stmt|;
comment|/* pointer to first list block */
name|SLSBLK
modifier|*
name|curblk
decl_stmt|;
comment|/* pointer to current block */
name|SLSBLK
modifier|*
name|tail
decl_stmt|;
comment|/* pointer to last list block */
block|}
name|SLSLIST
typedef|;
end_typedef

begin_comment
comment|/*  * Functions defined for singly-linked key+string list operations  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|slsappend
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* append key+string */
end_comment

begin_function_decl
specifier|extern
name|SLSBLK
modifier|*
name|slsget
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get next key+string block */
end_comment

begin_function_decl
specifier|extern
name|SLSLIST
modifier|*
name|slsinit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* initialize key+string list */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|slsinsert
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* insert key+string */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|slsprepend
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* prepend key+string */
end_comment

begin_function_decl
specifier|extern
name|void
name|slsprint
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print key+string list */
end_comment

begin_function_decl
specifier|extern
name|void
name|slsrewind
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* rewind key+string list */
end_comment

begin_function_decl
specifier|extern
name|void
name|slsrm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove key+string list item */
end_comment

begin_function_decl
specifier|extern
name|int
name|slssort
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* sort key+string list */
end_comment

end_unit

