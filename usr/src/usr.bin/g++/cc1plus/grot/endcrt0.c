begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"crt0.h"
end_include

begin_decl_stmt
specifier|static
name|long
name|__dtor_prev
init|=
literal|0
decl_stmt|,
name|__dtor_next
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|sparc
end_ifdef

begin_asm
asm|asm (".stabs \"___CTOR_LIST__\", 0x14, 0, 0, 0\n");
end_asm

begin_asm
asm|asm (".stabs \"___CTOR_LIST__\", 0x14, 0, 0, 0\n");
end_asm

begin_asm
asm|asm (".stabs \"___DTOR_LIST__\", 0x18, 0, 0, ___dtor_next\n");
end_asm

begin_asm
asm|asm (".stabs \"___DTOR_LIST__\", 0x18, 0, 0, ___dtor_prev\n");
end_asm

begin_asm
asm|asm (".stabs \"___ZTOR_LIST__\", 0x14, 0, 0, 0\n");
end_asm

begin_asm
asm|asm (".stabs \"___ZTOR_LIST__\", 0x14, 0, 0, 0\n");
end_asm

begin_endif
endif|#
directive|endif
end_endif

end_unit

