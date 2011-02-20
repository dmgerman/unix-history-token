begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -test-load-source all -fspell-checking %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t
end_comment

begin_struct
struct|struct
name|X
block|{
name|int
name|wibble
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MACRO
parameter_list|(
name|X
parameter_list|)
value|X
end_define

begin_function
name|void
name|f
parameter_list|(
name|struct
name|X
modifier|*
name|x
parameter_list|)
block|{
comment|// CHECK: error: no member named 'wobble' in 'struct X'; did you mean 'wibble'?
comment|// CHECK-NOT: FIX-IT
comment|// CHECK: note: 'wibble' declared here
name|MACRO
argument_list|(
name|x
operator|->
name|wobble
operator|=
literal|17
argument_list|)
expr_stmt|;
comment|// CHECK: error: no member named 'wabble' in 'struct X'; did you mean 'wibble'?
comment|// CHECK: FIX-IT: Replace [17:6 - 17:12] with "wibble"
comment|// CHECK: note: 'wibble' declared here
name|x
operator|->
name|wabble
operator|=
literal|17
expr_stmt|;
block|}
end_function

end_unit

