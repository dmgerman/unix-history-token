begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|TEST_PDB_H
end_ifndef

begin_define
define|#
directive|define
name|TEST_PDB_H
end_define

begin_include
include|#
directive|include
file|"test-pdb-nested.h"
end_include

begin_function_decl
name|int
name|bar
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|inline
name|int
name|foo
parameter_list|(
name|int
name|n
parameter_list|)
block|{
return|return
name|baz
argument_list|(
name|n
argument_list|)
operator|+
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

