begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Ensure that '-target shave' picks a different compiler.
end_comment

begin_comment
comment|// Also check that '-I' is turned into '-i:' for the assembler.
end_comment

begin_comment
comment|// Note that since we don't know where movi tools are installed,
end_comment

begin_comment
comment|// the driver may or may not find a full path to them.
end_comment

begin_comment
comment|// That is, the 0th argument will be "/path/to/my/moviCompile"
end_comment

begin_comment
comment|// or just "moviCompile" depending on whether moviCompile is found.
end_comment

begin_comment
comment|// As such, we test only for a trailing quote in its rendering.
end_comment

begin_comment
comment|// The same goes for "moviAsm".
end_comment

begin_comment
comment|// RUN: %clang -target shave -c -### %s -Icommon 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=movicompile
end_comment

begin_comment
comment|// movicompile: moviCompile" "-DMYRIAD2"
end_comment

begin_comment
comment|// movicompile: moviAsm" "-no6thSlotCompression" "-cv:myriad2" "-noSPrefixing" "-a" "-i:common" "-elf"
end_comment

begin_comment
comment|// RUN: %clang -target shave -c -### %s -DEFINE_ME -UNDEFINE_ME 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=defines
end_comment

begin_comment
comment|// defines: "-D" "EFINE_ME" "-U" "NDEFINE_ME"
end_comment

begin_comment
comment|// RUN: %clang -target shave -c -### %s -Icommon -iquote quotepath -isystem syspath 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=includes
end_comment

begin_comment
comment|// includes: "-iquote" "quotepath" "-isystem" "syspath"
end_comment

end_unit

