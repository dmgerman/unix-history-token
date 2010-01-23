begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -fms-extensions %s
end_comment

begin_decl_stmt
name|__int8
name|x1
init|=
literal|3i
literal|8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__int16
name|x2
init|=
literal|4i
literal|16
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__int32
name|x3
init|=
literal|5i
literal|32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__int64
name|x5
init|=
literal|0x42i64
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__int64
name|x4
init|=
literal|70000000i
literal|128
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__int64
name|y
init|=
literal|0x42i64u
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{invalid suffix}}
end_comment

begin_decl_stmt
name|__int64
name|w
init|=
literal|0x43ui64
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__int64
name|z
init|=
literal|9Li64
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{invalid suffix}}
end_comment

begin_decl_stmt
name|__int64
name|q
init|=
literal|10lli64
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{invalid suffix}}
end_comment

begin_comment
comment|// radar 7562363
end_comment

begin_define
define|#
directive|define
name|ULLONG_MAX
value|0xffffffffffffffffui64
end_define

begin_define
define|#
directive|define
name|UINT
value|0xffffffffui32
end_define

begin_define
define|#
directive|define
name|USHORT
value|0xffffui16
end_define

begin_define
define|#
directive|define
name|UCHAR
value|0xffui8
end_define

begin_function
name|void
name|a
parameter_list|()
block|{
name|unsigned
name|long
name|long
name|m
init|=
name|ULLONG_MAX
decl_stmt|;
name|unsigned
name|int
name|n
init|=
name|UINT
decl_stmt|;
name|unsigned
name|short
name|s
init|=
name|USHORT
decl_stmt|;
name|unsigned
name|char
name|c
init|=
name|UCHAR
decl_stmt|;
block|}
end_function

end_unit

