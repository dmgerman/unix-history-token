begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -E -dM %s -o %t
end_comment

begin_comment
comment|// Space even without expansion tokens
end_comment

begin_comment
comment|// RUN: grep "#define A(x) " %t
end_comment

begin_define
define|#
directive|define
name|A
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|// Space before expansion list.
end_comment

begin_comment
comment|// RUN: grep "#define B(x,y) x y" %t
end_comment

begin_define
define|#
directive|define
name|B
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x y
end_define

begin_comment
comment|// No space in expansion list.
end_comment

begin_comment
comment|// RUN: grep "#define C(x,y) x y" %t
end_comment

begin_define
define|#
directive|define
name|C
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x y
end_define

begin_comment
comment|// No paste avoidance.
end_comment

begin_comment
comment|// RUN: grep "#define X() .." %t
end_comment

begin_define
define|#
directive|define
name|X
parameter_list|()
value|..
end_define

begin_comment
comment|// Simple test.
end_comment

begin_comment
comment|// RUN: grep "#define Y ." %t
end_comment

begin_comment
comment|// RUN: grep "#define Z X()Y" %t
end_comment

begin_define
define|#
directive|define
name|Y
value|.
end_define

begin_define
define|#
directive|define
name|Z
value|X()Y
end_define

begin_comment
comment|// gcc prints macros at end of translation unit, so last one wins.
end_comment

begin_comment
comment|// RUN: grep "#define foo 2" %t
end_comment

begin_comment
comment|// RUN: not grep "#define foo 1" %t
end_comment

begin_define
define|#
directive|define
name|foo
value|1
end_define

begin_undef
undef|#
directive|undef
name|foo
end_undef

begin_define
define|#
directive|define
name|foo
value|2
end_define

end_unit

