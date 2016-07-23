begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"preamble-with-implicit-import-A.h"
end_include

begin_comment
comment|// Typo is defined in B, which is not imported.
end_comment

begin_function_decl
name|void
name|useTypeFromB
parameter_list|(
name|Typo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

