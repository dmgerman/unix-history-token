begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-apple-darwin9 %s -fsyntax-only -verify
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// Pragma pack handling with tag declarations
end_comment

begin_struct_decl
struct_decl|struct
name|X
struct_decl|;
end_struct_decl

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|2
name|)
end_pragma

begin_struct
struct|struct
name|X
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|Y
struct_decl|;
end_struct_decl

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_struct
struct|struct
name|Y
block|{
name|int
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|check
index|[
name|__alignof
argument_list|(
expr|struct
name|X
argument_list|)
operator|==
literal|2
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|check
index|[
name|__alignof
argument_list|(
expr|struct
name|Y
argument_list|)
operator|==
literal|4
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

end_unit

