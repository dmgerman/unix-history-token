begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: slist.h,v 1.1 85/03/14 15:33:33 nicklin Exp $ */
end_comment

begin_comment
comment|/*  * Singly-linked list definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Singly-linked list macros  */
end_comment

begin_define
define|#
directive|define
name|SLNUM
parameter_list|(
name|slist
parameter_list|)
value|(slist)->nk
end_define

begin_comment
comment|/*  * Singly-linked list block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|slblk
block|{
name|char
modifier|*
name|key
decl_stmt|;
comment|/* points to a key */
name|struct
name|slblk
modifier|*
name|next
decl_stmt|;
comment|/* ptr to next list block */
block|}
name|SLBLK
typedef|;
end_typedef

begin_comment
comment|/*  * Singly-linked list head block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|slisthb
block|{
name|int
name|nk
decl_stmt|;
comment|/* number of keys in list */
name|int
name|maxkey
decl_stmt|;
comment|/* length of longest key */
name|SLBLK
modifier|*
name|head
decl_stmt|;
comment|/* pointer to first list block */
name|SLBLK
modifier|*
name|curblk
decl_stmt|;
comment|/* pointer to current block */
name|SLBLK
modifier|*
name|tail
decl_stmt|;
comment|/* pointer to last list block */
block|}
name|SLIST
typedef|;
end_typedef

begin_comment
comment|/*  * Functions defined for singly-linked list operations  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|slappend
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* append key */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|slget
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get next key */
end_comment

begin_function_decl
specifier|extern
name|SLIST
modifier|*
name|slinit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* initialize list */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|slinsert
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* insert key */
end_comment

begin_function_decl
specifier|extern
name|int
name|slpop
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* pop key */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|slprepend
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* prepend key */
end_comment

begin_function_decl
specifier|extern
name|void
name|slprint
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print list */
end_comment

begin_function_decl
specifier|extern
name|void
name|slrewind
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* rewind list */
end_comment

begin_function_decl
specifier|extern
name|void
name|slrm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove list item */
end_comment

begin_function_decl
specifier|extern
name|int
name|slsort
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* sort list */
end_comment

begin_function_decl
specifier|extern
name|void
name|slsplice
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* splice two lists */
end_comment

end_unit

