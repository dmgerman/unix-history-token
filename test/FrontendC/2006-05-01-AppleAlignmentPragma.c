begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -o -
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_comment
comment|/* test that X is laid out correctly when this pragma is used. */
end_comment

begin_pragma
pragma|#
directive|pragma
name|options
name|align
name|=
name|mac68k
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|S
block|{
name|unsigned
name|A
decl_stmt|;
name|unsigned
name|short
name|B
decl_stmt|;
block|}
name|X
struct|;
end_struct

end_unit

