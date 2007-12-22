begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* readfile.h */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|"bptypes.h"
end_include

begin_include
include|#
directive|include
file|"hash.h"
end_include

begin_function_decl
specifier|extern
name|boolean
name|hwlookcmp
parameter_list|(
name|hash_datum
modifier|*
parameter_list|,
name|hash_datum
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|boolean
name|iplookcmp
parameter_list|(
name|hash_datum
modifier|*
parameter_list|,
name|hash_datum
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|boolean
name|nmcmp
parameter_list|(
name|hash_datum
modifier|*
parameter_list|,
name|hash_datum
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|readtab
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rdtab_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

