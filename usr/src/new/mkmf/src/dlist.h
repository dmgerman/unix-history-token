begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: dlist.h,v 1.1 85/04/23 13:56:24 nicklin Exp $ */
end_comment

begin_comment
comment|/*  * Dependency list definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Dependency list block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_dlblk
block|{
name|int
name|d_type
decl_stmt|;
comment|/* source file type */
name|struct
name|slblk
modifier|*
name|d_src
decl_stmt|;
comment|/* points to a source list block */
name|struct
name|_iblk
modifier|*
name|d_incl
decl_stmt|;
comment|/* pointer to include block chain */
name|struct
name|_dlblk
modifier|*
name|d_next
decl_stmt|;
comment|/* ptr to next list block */
block|}
name|DLBLK
typedef|;
end_typedef

begin_comment
comment|/*  * Dependency list head block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_dlisthb
block|{
name|DLBLK
modifier|*
name|d_head
decl_stmt|;
comment|/* pointer to first list block */
name|DLBLK
modifier|*
name|d_tail
decl_stmt|;
comment|/* pointer to last list block */
block|}
name|DLIST
typedef|;
end_typedef

begin_comment
comment|/*  * Functions defined for dependency list operations  */
end_comment

begin_function_decl
specifier|extern
name|DLBLK
modifier|*
name|dlappend
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* append to list */
end_comment

begin_function_decl
specifier|extern
name|DLIST
modifier|*
name|dlinit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* initialize list */
end_comment

begin_function_decl
specifier|extern
name|void
name|dlprint
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print list */
end_comment

end_unit

