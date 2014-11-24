begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_struct_decl
struct_decl|struct
name|s
struct_decl|;
end_struct_decl

begin_comment
comment|// expected-note 7 {{forward declaration of 'struct s'}}
end_comment

begin_comment
comment|// standard string matching
end_comment

begin_decl_stmt
name|struct
name|s
name|s1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{tentative definition has type 'struct s' that is never completed}}
end_comment

begin_decl_stmt
name|struct
name|s
name|s2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{tentative definition has type}}
end_comment

begin_comment
comment|// regex matching
end_comment

begin_decl_stmt
name|struct
name|s
name|r1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error    {{tentative definition has type 'struct s' that is never completed}}
end_comment

begin_decl_stmt
name|struct
name|s
name|r2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error-re {{tentative definition has type '{{.*[[:space:]]*.*}}' that is never completed}}
end_comment

begin_decl_stmt
name|struct
name|s
name|r3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error-re {{tentative definition has type '{{(.*)[[:space:]]*(.*)}}' that is never completed}}
end_comment

begin_decl_stmt
name|struct
name|s
name|r4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error-re {{{{^}}tentative}}
end_comment

begin_decl_stmt
name|struct
name|s
name|r5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error-re {{completed{{$}}}}
end_comment

end_unit

