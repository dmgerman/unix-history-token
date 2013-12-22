begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 %s -emit-llvm -o - | grep zeroinitializer | count 1  The FE must not generate padding here between array elements.  PR 2533. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|flags
decl_stmt|;
union|union
block|{
name|int
name|x
decl_stmt|;
block|}
name|u
union|;
block|}
name|OptionDef
typedef|;
end_typedef

begin_decl_stmt
specifier|const
name|OptionDef
name|options
index|[]
init|=
block|{
comment|/* main options */
block|{
literal|"a"
block|,
literal|0
block|,
block|{
literal|3
block|}
block|}
block|,
block|{
literal|"b"
block|,
literal|0
block|,
block|{
literal|4
block|}
block|}
block|,
block|{
literal|0
block|, }
block|, }
decl_stmt|;
end_decl_stmt

end_unit

