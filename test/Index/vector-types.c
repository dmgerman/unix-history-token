begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|x
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|int4_t
typedef|;
end_typedef

begin_comment
comment|// RUN: c-index-test -test-print-typekind %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: VarDecl=x:1:38 typekind=Vector [isPOD=1]
end_comment

begin_comment
comment|// CHECK: TypedefDecl=int4_t:2:46 (Definition) typekind=Typedef [canonical=Vector] [isPOD=1]
end_comment

end_unit

