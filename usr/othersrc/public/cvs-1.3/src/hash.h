begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)hash.h 1.18 92/03/31	 */
end_comment

begin_comment
comment|/*  * Copyright (c) 1992, Brian Berliner and Jeff Polk  *   * You may distribute under the terms of the GNU General Public License as  * specified in the README file that comes with the CVS 1.3 kit.  */
end_comment

begin_comment
comment|/*  * The number of buckets for the hash table contained in each list.  This  * should probably be prime.  */
end_comment

begin_define
define|#
directive|define
name|HASHSIZE
value|151
end_define

begin_comment
comment|/*  * Types of nodes  */
end_comment

begin_enum
enum|enum
name|ntype
block|{
name|UNKNOWN
block|,
name|HEADER
block|,
name|ENTRIES
block|,
name|FILES
block|,
name|LIST
block|,
name|RCSNODE
block|,
name|RCSVERS
block|,
name|DIRS
block|,
name|UPDATE
block|,
name|LOCK
block|,
name|NDBMNODE
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|ntype
name|Ntype
typedef|;
end_typedef

begin_struct
struct|struct
name|node
block|{
name|Ntype
name|type
decl_stmt|;
name|struct
name|node
modifier|*
name|next
decl_stmt|;
name|struct
name|node
modifier|*
name|prev
decl_stmt|;
name|struct
name|node
modifier|*
name|hashnext
decl_stmt|;
name|struct
name|node
modifier|*
name|hashprev
decl_stmt|;
name|char
modifier|*
name|key
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
name|void
function_decl|(
modifier|*
name|delproc
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|node
name|Node
typedef|;
end_typedef

begin_struct
struct|struct
name|list
block|{
name|Node
modifier|*
name|list
decl_stmt|;
name|Node
modifier|*
name|hasharray
index|[
name|HASHSIZE
index|]
decl_stmt|;
name|struct
name|list
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|list
name|List
typedef|;
end_typedef

begin_struct
struct|struct
name|entnode
block|{
name|char
modifier|*
name|version
decl_stmt|;
name|char
modifier|*
name|timestamp
decl_stmt|;
name|char
modifier|*
name|options
decl_stmt|;
name|char
modifier|*
name|tag
decl_stmt|;
name|char
modifier|*
name|date
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|entnode
name|Entnode
typedef|;
end_typedef

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
name|List
modifier|*
name|getlist
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Node
modifier|*
name|findnode
parameter_list|(
name|List
modifier|*
name|list
parameter_list|,
name|char
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Node
modifier|*
name|getnode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|addnode
parameter_list|(
name|List
modifier|*
name|list
parameter_list|,
name|Node
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|walklist
parameter_list|(
name|List
modifier|*
name|list
parameter_list|,
name|int
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dellist
parameter_list|(
name|List
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delnode
parameter_list|(
name|Node
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freenode
parameter_list|(
name|Node
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sortlist
parameter_list|(
name|List
modifier|*
name|list
parameter_list|,
name|int
function_decl|(
modifier|*
name|comp
function_decl|)
parameter_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|List
modifier|*
name|getlist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Node
modifier|*
name|findnode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Node
modifier|*
name|getnode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|addnode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|walklist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dellist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delnode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freenode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sortlist
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

end_unit

