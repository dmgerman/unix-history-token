begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang --autocomplete=-fsyn | FileCheck %s -check-prefix=FSYN
end_comment

begin_comment
comment|// FSYN: -fsyntax-only
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-s | FileCheck %s -check-prefix=STD
end_comment

begin_comment
comment|// STD: -std={{.*}}-stdlib=
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=foo | not FileCheck %s -check-prefix=NONE
end_comment

begin_comment
comment|// NONE: foo
end_comment

end_unit

