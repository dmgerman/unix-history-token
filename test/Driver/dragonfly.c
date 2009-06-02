begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -ccc-host-triple amd64-pc-dragonfly %s -### 2> %t.log&&
end_comment

begin_comment
comment|// RUN: grep 'clang-cc" "-triple" "x86_64-pc-dragonfly"' %t.log&&
end_comment

begin_comment
comment|// RUN: grep 'as" "-o" ".*\.o" ".*\.s' %t.log&&
end_comment

begin_comment
comment|// RUN: grep 'ld" "-dynamic-linker" ".*ld-elf.*" "-o" "a\.out" ".*crt1.o" ".*crti.o" "crtbegin.o" ".*\.o" "-L.*/gcc.*" .* "-lc" "-lgcc" ".*crtend.o" ".*crtn.o"' %t.log&&
end_comment

begin_comment
comment|// RUN: true
end_comment

end_unit

