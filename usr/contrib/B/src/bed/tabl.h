begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: tabl.h,v 2.0 84/06/18 15:47:24 guido Exp $ */
end_comment

begin_comment
comment|/*  * B editor -- Grammar table structure.  */
end_comment

begin_typedef
typedef|typedef
name|char
name|classelem
typedef|;
end_typedef

begin_comment
comment|/* change into short if symbol or lexical values can exceed 127! */
end_comment

begin_typedef
typedef|typedef
name|classelem
modifier|*
name|classptr
typedef|;
end_typedef

begin_struct
struct|struct
name|classinfo
block|{
name|classptr
name|c_class
decl_stmt|;
comment|/* List of possible classes */
comment|/* The following fields are initialized dynamically */
name|classptr
name|c_insert
decl_stmt|;
comment|/* List of pairs (char, class) for insertion */
name|classptr
name|c_append
decl_stmt|;
comment|/* Ditto for append to child already there */
name|classptr
name|c_join
decl_stmt|;
comment|/* Ditto for join of child with new node */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXCHILD
value|4
end_define

begin_comment
comment|/* Max. # of children per node. */
end_comment

begin_struct
struct|struct
name|table
block|{
name|short
name|r_symbol
decl_stmt|;
comment|/* Redundant, used for checking consistency */
name|string
name|r_name
decl_stmt|;
name|string
name|r_repr
index|[
name|MAXCHILD
operator|+
literal|1
index|]
decl_stmt|;
comment|/* There are entries [0..nch] inclusive. */
name|struct
name|classinfo
modifier|*
name|r_class
index|[
name|MAXCHILD
index|]
decl_stmt|;
comment|/* Must be indexed with [ich-1] !! */
name|node
name|r_node
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|table
modifier|*
name|table
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TABLEN
value|(Hole+1)
end_define

begin_decl_stmt
specifier|extern
name|char
name|code_array
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|invcode_array
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lastcode
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|Code
parameter_list|(
name|c
parameter_list|)
value|code_array[c]
end_define

begin_define
define|#
directive|define
name|Invcode
parameter_list|(
name|code
parameter_list|)
value|invcode_array[code]
end_define

end_unit

