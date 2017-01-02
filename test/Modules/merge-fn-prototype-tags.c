begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c -I%S/Inputs/merge-fn-prototype-tags -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fmodule-map-file=%S/Inputs/merge-fn-prototype-tags/module.modulemap -fmodules-cache-path=%t -x c -I%S/Inputs/merge-fn-prototype-tags -verify %s
end_comment

begin_include
include|#
directive|include
file|"c.h"
end_include

begin_function
name|void
name|mmalloc_attach
parameter_list|()
block|{
name|struct
name|stat
name|sbuf
decl_stmt|;
block|}
end_function

begin_comment
comment|// expected-no-diagnostics
end_comment

end_unit

