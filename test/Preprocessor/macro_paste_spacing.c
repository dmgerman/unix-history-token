begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck --strict-whitespace %s
end_comment

begin_define
define|#
directive|define
name|A
value|x ## y
end_define

begin_decl_stmt
name|blah
name|A
comment|// CHECK: {{^}}xy{{$}}
define|#
directive|define
name|B
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|[v ## w] [ v##w] [v##w ] [w ## x] [ w##x] [w##x ] [x ## y] [ x##y] [x##y ] [y ## z] [ y##z] [y##z ]
name|B
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
comment|// CHECK: [vw] [ vw] [vw ] [wx] [ wx] [wx ] [xy] [ xy] [xy ] [yz] [ yz] [yz ]
name|B
argument_list|(
name|x
argument_list|,)
comment|// CHECK: [vw] [ vw] [vw ] [wx] [ wx] [wx ] [x] [ x] [x ] [z] [ z] [z ]
name|B
argument_list|(,
name|y
argument_list|)
comment|// CHECK: [vw] [ vw] [vw ] [w] [ w] [w ] [y] [ y] [y ] [yz] [ yz] [yz ]
name|B
argument_list|(,)
comment|// CHECK: [vw] [ vw] [vw ] [w] [ w] [w ] [] [ ] [ ] [z] [ z] [z ]
define|#
directive|define
name|C
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|[x ## y ## z]
name|C
argument_list|(,,)
name|C
argument_list|(
name|a
argument_list|,,)
name|C
argument_list|(,
name|b
argument_list|,)
name|C
argument_list|(,,
name|c
argument_list|)
name|C
argument_list|(
name|a
argument_list|,
name|b
argument_list|,)
name|C
argument_list|(
name|a
argument_list|,,
name|c
argument_list|)
name|C
argument_list|(,
name|b
argument_list|,
name|c
argument_list|)
name|C
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
end_decl_stmt

begin_comment
comment|// CHECK: [] [a] [b] [c] [ab] [ac] [bc] [abc]
end_comment

end_unit

