begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fimplicit-module-maps -fmodules-cache-path=%t -I %S/Inputs %s -verify
end_comment

begin_struct
struct|struct
name|S1
block|{
comment|// expected-note{{'struct S1' begins here}}
include|#
directive|include
file|"dummy.h"
comment|// expected-error{{import of module 'dummy' appears within 'struct S1'}}
block|}
end_struct

end_unit

