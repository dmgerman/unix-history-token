begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Basic binding.
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -ccc-print-bindings %s 2> %t
end_comment

begin_comment
comment|// RUN: grep '"clang", inputs: \[".*bindings.c"\], output: ".*\.s"' %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Assemble", inputs: \[".*\.s"\], output: ".*\.o"' %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Link", inputs: \[".*\.o"\], output: "a.out"' %t
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -ccc-print-bindings -ccc-no-clang %s 2> %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Compile", inputs: \[".*bindings.c"\], output: ".*\.s"' %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Assemble", inputs: \[".*\.s"\], output: ".*\.o"' %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Link", inputs: \[".*\.o"\], output: "a.out"' %t
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -ccc-print-bindings -ccc-no-clang -no-integrated-cpp %s 2> %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Preprocess", inputs: \[".*bindings.c"\], output: ".*\.i"' %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Compile", inputs: \[".*\.i"\], output: ".*\.s"' %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Assemble", inputs: \[".*\.s"\], output: ".*\.o"' %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Link", inputs: \[".*\.o"\], output: "a.out"' %t
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -ccc-print-bindings -ccc-no-clang -no-integrated-cpp -pipe %s 2> %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Preprocess", inputs: \[".*bindings.c"\], output: (pipe)' %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Compile", inputs: \[(pipe)\], output: (pipe)' %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Assemble", inputs: \[(pipe)\], output: ".*\.o"' %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Link", inputs: \[".*\.o"\], output: "a.out"' %t
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -ccc-print-bindings -ccc-no-clang -x c-header %s 2> %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Precompile", inputs: \[".*bindings.c"\], output: ".*bindings.c.gch' %t
end_comment

begin_comment
comment|// Clang control options
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -ccc-print-bindings -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: grep '"clang", inputs: \[".*bindings.c"\], output: (nothing)' %t
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -ccc-print-bindings -ccc-no-clang -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Compile", inputs: \[".*bindings.c"\], output: (nothing)' %t
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -ccc-print-bindings -ccc-no-clang-cxx -fsyntax-only -x c++ %s 2> %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Compile", inputs: \[".*bindings.c"\], output: (nothing)' %t
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -ccc-print-bindings -ccc-clang-cxx -fsyntax-only -x c++ %s 2> %t
end_comment

begin_comment
comment|// RUN: grep '"clang", inputs: \[".*bindings.c"\], output: (nothing)' %t
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -ccc-print-bindings -ccc-no-clang-cpp -fsyntax-only -no-integrated-cpp %s 2> %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Preprocess", inputs: \[".*bindings.c"\], output: ".*\.i"' %t
end_comment

begin_comment
comment|// RUN: grep '"clang", inputs: \[".*\.i"\], output: (nothing)' %t
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-apple-darwin9 -ccc-print-bindings -ccc-clang-archs i386 %s -S -arch ppc 2> %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Compile", inputs: \[".*bindings.c"\], output: "bindings.s"' %t
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-apple-darwin9 -ccc-print-bindings -ccc-clang-archs powerpc %s -S -arch ppc 2> %t
end_comment

begin_comment
comment|// RUN: grep '"clang", inputs: \[".*bindings.c"\], output: "bindings.s"' %t
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple powerpc-unknown-unknown -ccc-print-bindings -ccc-clang-archs "" %s -S 2> %t
end_comment

begin_comment
comment|// RUN: grep '"clang", inputs: \[".*bindings.c"\], output: "bindings.s"' %t
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple powerpc-unknown-unknown -ccc-print-bindings -ccc-clang-archs "i386" %s -S 2> %t
end_comment

begin_comment
comment|// RUN: grep '"gcc::Compile", inputs: \[".*bindings.c"\], output: "bindings.s"' %t
end_comment

begin_comment
comment|// Darwin bindings
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-apple-darwin9 -ccc-print-bindings %s 2> %t
end_comment

begin_comment
comment|// RUN: grep '"clang", inputs: \[".*bindings.c"\], output: ".*\.s"' %t
end_comment

begin_comment
comment|// RUN: grep '"darwin::Assemble", inputs: \[".*\.s"\], output: ".*\.o"' %t
end_comment

begin_comment
comment|// RUN: grep '"darwin::Link", inputs: \[".*\.o"\], output: "a.out"' %t
end_comment

end_unit

