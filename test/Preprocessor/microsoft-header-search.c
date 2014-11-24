begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -I%S/Inputs/microsoft-header-search %s -fms-compatibility -verify
end_comment

begin_comment
comment|// expected-warning@Inputs/microsoft-header-search/a/findme.h:3 {{findme.h successfully included using MS search rules}}
end_comment

begin_comment
comment|// expected-warning@Inputs/microsoft-header-search/a/b/include3.h:3 {{#include resolved using non-portable MSVC search rules as}}
end_comment

begin_comment
comment|// expected-warning@Inputs/microsoft-header-search/falsepos.h:3 {{successfully resolved the falsepos.h header}}
end_comment

begin_include
include|#
directive|include
file|"Inputs/microsoft-header-search/include1.h"
end_include

end_unit

