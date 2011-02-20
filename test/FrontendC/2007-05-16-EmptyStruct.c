begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// PR 1417
end_comment

begin_comment
comment|// RUN: %llvmgcc -xc  %s -S -o - | grep "struct.anon = type \{\}"
end_comment

begin_struct
struct|struct
block|{ }
modifier|*
name|X
struct|;
end_struct

end_unit

