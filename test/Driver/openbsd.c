begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -ccc-clang-archs "" -ccc-host-triple i686-pc-openbsd %s -### 2> %t.log&&
end_comment

begin_comment
comment|// RUN: grep 'clang-cc" "-triple" "i386-pc-openbsd"' %t.log&&
end_comment

begin_comment
comment|// RUN: grep 'as" "-o" ".*\.o" ".*\.s' %t.log&&
end_comment

begin_comment
comment|// RUN: grep 'ld" "--eh-frame-hdr" "-dynamic-linker" ".*ld.so" "-o" "a\.out" ".*crt0.o" ".*crtbegin.o" ".*\.o" "-lc" ".*crtend.o"' %t.log&&
end_comment

begin_comment
comment|// RUN: true
end_comment

end_unit

