begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Project directory set definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Project directory type label block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_typblk
block|{
name|short
name|t_exist
decl_stmt|;
comment|/* type label exist for this dir? */
name|short
name|t_prior
decl_stmt|;
comment|/* type label priority */
block|}
name|TYPBLK
typedef|;
end_typedef

begin_comment
comment|/*  * Project directory attribute block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_pdset
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
name|TYPBLK
modifier|*
name|typblk
decl_stmt|;
comment|/* project directory's type labels */
block|}
name|PDSET
typedef|;
end_typedef

begin_comment
comment|/*  * Project directory type label statistics (for each set of type labels)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_types
block|{
name|char
modifier|*
name|t_name
decl_stmt|;
comment|/* type label name */
name|short
name|t_ntl
decl_stmt|;
comment|/* number of type labels */
name|short
name|t_itlp
decl_stmt|;
comment|/* initial type label priority */
name|short
name|t_sort
decl_stmt|;
comment|/* sort on this type label? */
block|}
name|TYPES
typedef|;
end_typedef

end_unit

