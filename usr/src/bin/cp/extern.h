begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)extern.h	5.1 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|p_end
decl_stmt|;
comment|/* pointer to NULL at end of path */
name|char
name|p_path
index|[
name|MAXPATHLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* pointer to the start of a path */
block|}
name|PATH_T
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program name */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|path_set
parameter_list|(
name|PATH_T
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|path_append
parameter_list|(
name|PATH_T
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|path_basename
parameter_list|(
name|PATH_T
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|path_restore
parameter_list|(
name|PATH_T
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

end_unit

