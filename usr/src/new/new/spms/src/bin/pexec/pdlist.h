begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Project directory list definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Singly-linked project directory list macros  */
end_comment

begin_define
define|#
directive|define
name|pdnum
parameter_list|(
name|pdlist
parameter_list|)
value|(pdlist)->nd
end_define

begin_comment
comment|/*  * Singly-linked project directory list block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_pdblk
block|{
name|char
modifier|*
name|ppath
decl_stmt|;
comment|/* project directory project pathname */
name|char
modifier|*
name|rpath
decl_stmt|;
comment|/* project directory regular pathname */
name|char
modifier|*
name|project
decl_stmt|;
comment|/* project directory's project */
name|struct
name|_pdblk
modifier|*
name|next
decl_stmt|;
comment|/* ptr to next list block */
block|}
name|PDBLK
typedef|;
end_typedef

begin_comment
comment|/*  * Singly-linked project directory list head block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_pdlisthb
block|{
name|int
name|nd
decl_stmt|;
comment|/* number of directories in list */
name|PDBLK
modifier|*
name|head
decl_stmt|;
comment|/* pointer to first list block */
block|}
name|PDLIST
typedef|;
end_typedef

begin_comment
comment|/*  * Functions defined for singly-linked project directory list operations  */
end_comment

begin_function_decl
specifier|extern
name|PDLIST
modifier|*
name|pdinit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* initialize project directory list */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|pdprepend
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* prepend project directory */
end_comment

begin_function_decl
specifier|extern
name|void
name|pdrm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove project directory list */
end_comment

begin_function_decl
specifier|extern
name|void
name|pdsort
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* sort project directory list */
end_comment

end_unit

