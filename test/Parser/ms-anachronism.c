begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows-msvc -fms-extensions -fsyntax-only -verify %s
end_comment

begin_struct
struct|struct
block|{}
name|__cdecl
name|s
struct|;
end_struct

begin_comment
comment|// expected-warning {{'__cdecl' only applies to function types; type here is 'struct}}
end_comment

end_unit

