begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -Wduplicate-enum
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -x c++ -fsyntax-only -verify -Wduplicate-enum
end_comment

begin_enum
enum|enum
name|A
block|{
name|A1
init|=
literal|0
block|,
comment|// expected-note {{element A1 also has value 0}}
name|A2
init|=
operator|-
literal|1
block|,
name|A3
block|,
comment|// expected-warning {{element A3 has been implicitly assigned 0 which another element has been assigned}}
name|A4
block|}
enum|;
end_enum

begin_enum
enum|enum
name|B
block|{
name|B1
init|=
operator|-
literal|1
block|,
comment|// expected-note {{element B1 also has value -1}}
name|B2
block|,
comment|// expected-warning {{element B2 has been implicitly assigned 0 which another element has been assigned}}
name|B3
block|,
name|B4
init|=
operator|-
literal|2
block|,
name|B5
block|,
comment|// expected-warning {{element B5 has been implicitly assigned -1 which another element has been assigned}}
name|B6
comment|// expected-note {{element B6 also has value 0}}
block|}
enum|;
end_enum

begin_enum
enum|enum
name|C
block|{
name|C1
block|,
name|C2
init|=
operator|-
literal|1
block|,
name|C3
block|}
enum|;
end_enum

begin_comment
comment|// expected-warning{{element C1 has been implicitly assigned 0 which another element has been assigned}} \
end_comment

begin_comment
comment|// expected-note {{element C3 also has value 0}}
end_comment

begin_enum
enum|enum
name|D
block|{
name|D1
block|,
name|D2
block|,
name|D3
block|,
comment|// expected-warning{{element D3 has been implicitly assigned 2 which another element has been assigned}}
name|D4
init|=
name|D2
block|,
comment|// no warning
name|D5
init|=
literal|2
comment|// expected-note {{element D5 also has value 2}}
block|}
enum|;
end_enum

begin_enum
enum|enum
name|E
block|{
name|E1
block|,
name|E2
init|=
name|E1
block|,
name|E3
init|=
name|E2
block|}
enum|;
end_enum

begin_enum
enum|enum
name|F
block|{
name|F1
block|,
name|F2
block|,
name|FCount
block|,
name|FMax
init|=
name|FCount
operator|-
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|G
block|{
name|G1
block|,
name|G2
block|,
name|GMax
init|=
name|G2
block|,
name|GCount
init|=
name|GMax
operator|+
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|H1
init|=
literal|0
block|,
name|H2
init|=
operator|-
literal|1
block|,
name|H3
block|,
name|H4
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|I1
init|=
operator|-
literal|1
block|,
name|I2
block|,
name|I3
block|,
name|I4
init|=
operator|-
literal|2
block|,
name|I5
block|,
name|I6
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|J1
block|,
name|J2
init|=
operator|-
literal|1
block|,
name|J3
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|K1
block|,
name|K2
block|,
name|K3
block|,
name|K4
init|=
name|K2
block|,
name|K5
init|=
literal|2
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|L1
block|,
name|L2
init|=
name|L1
block|,
name|L3
init|=
name|L2
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|M1
block|,
name|M2
block|,
name|MCount
block|,
name|MMax
init|=
name|MCount
operator|-
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|N1
block|,
name|N2
block|,
name|NMax
init|=
name|N2
block|,
name|NCount
init|=
name|NMax
operator|+
literal|1
block|}
enum|;
end_enum

begin_comment
comment|// PR15693
end_comment

begin_enum
enum|enum
name|enum1
block|{
name|VALUE
comment|// expected-note{{previous definition is here}}
block|}
enum|;
end_enum

begin_enum
enum|enum
name|enum2
block|{
name|VALUE
comment|// expected-error{{redefinition of enumerator 'VALUE'}}
block|}
enum|;
end_enum

end_unit

