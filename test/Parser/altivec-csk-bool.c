begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -target-feature +altivec -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64le-unknown-linux-gnu -target-feature +altivec -fsyntax-only %s
end_comment

begin_comment
comment|// PR16456: Verify that bool, true, false are treated as context-sensitive
end_comment

begin_comment
comment|// keywords (and therefore available for use as identifiers) when in
end_comment

begin_comment
comment|// Altivec mode.
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|false_value
init|=
literal|0
block|,
name|true_value
init|=
literal|1
block|}
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|true
value|true_value
end_define

begin_define
define|#
directive|define
name|false
value|false_value
end_define

end_unit

