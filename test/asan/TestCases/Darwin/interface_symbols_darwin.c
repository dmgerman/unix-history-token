begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check the presence of interface symbols in the ASan runtime dylib.
end_comment

begin_comment
comment|// If you're changing this file, please also change
end_comment

begin_comment
comment|// ../Linux/interface_symbols.c
end_comment

begin_comment
comment|// RUN: %clang_asan -dead_strip -O2 %s -o %t.exe
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// note: we can not use -D on Darwin.
end_comment

begin_comment
comment|// RUN: nm -g `%clang_asan %s -fsanitize=address -### 2>&1 | grep "libclang_rt.asan_osx_dynamic.dylib" | sed -e 's/.*"\(.*libclang_rt.asan_osx_dynamic.dylib\)".*/\1/'` \
end_comment

begin_comment
comment|// RUN:  | grep " [TU] "                                                       \
end_comment

begin_comment
comment|// RUN:  | grep -o "\(__asan_\|__ubsan_\|__sancov_\|__sanitizer_\)[^ ]*"       \
end_comment

begin_comment
comment|// RUN:  | grep -v "__sanitizer_syscall"                                       \
end_comment

begin_comment
comment|// RUN:  | grep -v "__sanitizer_weak_hook"                                     \
end_comment

begin_comment
comment|// RUN:  | grep -v "__sanitizer_mz"                                            \
end_comment

begin_comment
comment|// RUN:  | grep -v "__ubsan_handle_dynamic_type_cache_miss"                    \
end_comment

begin_comment
comment|// RUN:  | sed -e "s/__asan_version_mismatch_check_v[0-9]+/__asan_version_mismatch_check/" \
end_comment

begin_comment
comment|// RUN:> %t.exports
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: grep -e "INTERFACE_\(WEAK_\)\?FUNCTION"                                \
end_comment

begin_comment
comment|// RUN:  %p/../../../../lib/asan/asan_interface.inc                            \
end_comment

begin_comment
comment|// RUN:  %p/../../../../lib/ubsan/ubsan_interface.inc                          \
end_comment

begin_comment
comment|// RUN:  %p/../../../../lib/sanitizer_common/sanitizer_common_interface.inc    \
end_comment

begin_comment
comment|// RUN:  %p/../../../../lib/sanitizer_common/sanitizer_common_interface_posix.inc \
end_comment

begin_comment
comment|// RUN:  %p/../../../../lib/sanitizer_common/sanitizer_coverage_interface.inc  \
end_comment

begin_comment
comment|// RUN:  | grep -v "__sanitizer_weak_hook"                                     \
end_comment

begin_comment
comment|// RUN:  | sed -e "s/.*(//" -e "s/).*//"> %t.imports
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: cat %t.imports | sort | uniq> %t.imports-sorted
end_comment

begin_comment
comment|// RUN: cat %t.exports | sort | uniq> %t.exports-sorted
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_comment
comment|// RUN: echo "=== NOTE === If you see a mismatch below, please update sanitizer_interface.inc files."
end_comment

begin_comment
comment|// RUN: diff %t.imports-sorted %t.exports-sorted
end_comment

begin_comment
comment|// UNSUPPORTED: ios
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

