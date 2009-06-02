begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -ccc-clang-archs "" -ccc-host-triple ppc64-pc-freebsd8 %s -### 2> %t.log&&
end_comment

begin_comment
comment|// RUN: cat %t.log&&
end_comment

begin_comment
comment|// RUN: grep 'clang-cc" "-triple" "powerpc64-pc-freebsd8"' %t.log&&
end_comment

begin_comment
comment|// RUN: grep 'as" "-o" ".*\.o" ".*\.s' %t.log&&
end_comment

begin_comment
comment|// RUN: grep 'ld" "--eh-frame-hdr" "-dynamic-linker" ".*ld-elf.*" "-o" "a\.out" ".*crt1.o" ".*crti.o" "crtbegin.o" ".*\.o" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed" "-lc" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed" ".*crtend.o" ".*crtn.o"' %t.log&&
end_comment

begin_comment
comment|// RUN: true
end_comment

end_unit

