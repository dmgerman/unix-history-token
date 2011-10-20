begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_struct
struct|struct
name|s
block|{
name|unsigned
name|long
name|int
name|field
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OFFS
define|\
value|(((char *)&((struct s *) 0)->field[0]) - (char *) 0)
end_define

begin_decl_stmt
name|int
name|foo
index|[
name|OFFS
index|]
decl_stmt|;
end_decl_stmt

end_unit

