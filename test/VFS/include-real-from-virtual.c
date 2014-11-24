begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir -p %t
end_comment

begin_comment
comment|// RUN: echo "void baz(void);"> %t/real.h
end_comment

begin_comment
comment|// RUN: sed -e "s:INPUT_DIR:%S/Inputs:g" -e "s:OUT_DIR:%t:g" %S/Inputs/vfsoverlay.yaml> %t.yaml
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Werror -ivfsoverlay %t.yaml -I %t -fsyntax-only %s
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

begin_include
include|#
directive|include
file|"include_real.h"
end_include

begin_function
name|void
name|foo
parameter_list|()
block|{
name|baz
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

