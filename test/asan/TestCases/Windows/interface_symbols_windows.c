begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that the interface exported by asan static lib matches the list of
end_comment

begin_comment
comment|// functions mentioned in sanitizer_interface.inc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Just make sure we can compile this.
end_comment

begin_comment
comment|// RUN: %clang_cl_asan -O0 %s -Fe%t
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// note: The mangling decoration (i.e. @4 )is removed because calling convention
end_comment

begin_comment
comment|//       differ from 32-bit and 64-bit.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: dumpbin /EXPORTS %t | sed "s/=.*//"                                    \
end_comment

begin_comment
comment|// RUN:   | grep -o "\(__asan_\|__ubsan_\|__sanitizer_\|__sancov_\)[^ ]*"      \
end_comment

begin_comment
comment|// RUN:   | grep -v "__asan_wrap"                                              \
end_comment

begin_comment
comment|// RUN:   | sed -e s/@.*//> %t.exports
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// [BEWARE: be really careful with the sed commands, as this test can be run
end_comment

begin_comment
comment|//  from different environemnts with different shells and seds]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: grep -e "INTERFACE_FUNCTION"                                           \
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
comment|// RUN:  %p/../../../../lib/sanitizer_common/sanitizer_coverage_interface.inc  \
end_comment

begin_comment
comment|// RUN:  | sed -e "s/.*(//" -e "s/).*//"> %t.imports1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: grep -e "INTERFACE_WEAK_FUNCTION"                                      \
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
comment|// RUN:  %p/../../../../lib/sanitizer_common/sanitizer_coverage_interface.inc  \
end_comment

begin_comment
comment|// RUN:  | sed -e "s/.*(//" -e "s/).*/__dll/"> %t.imports2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Add functions not included in the interface lists:
end_comment

begin_comment
comment|// RUN: grep '[I]MPORT:' %s | sed -e 's/.*[I]MPORT: //'> %t.imports3
end_comment

begin_comment
comment|// IMPORT: __asan_shadow_memory_dynamic_address
end_comment

begin_comment
comment|// IMPORT: __asan_get_shadow_memory_dynamic_address
end_comment

begin_comment
comment|// IMPORT: __asan_option_detect_stack_use_after_return
end_comment

begin_comment
comment|// IMPORT: __asan_should_detect_stack_use_after_return
end_comment

begin_comment
comment|// IMPORT: __asan_set_seh_filter
end_comment

begin_comment
comment|// IMPORT: __asan_unhandled_exception_filter
end_comment

begin_comment
comment|// IMPORT: __asan_test_only_reported_buggy_pointer
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: cat %t.imports1 %t.imports2 %t.imports3 | sort | uniq> %t.imports-sorted
end_comment

begin_comment
comment|// RUN: cat %t.exports | sort | uniq> %t.exports-sorted
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Now make sure the DLL thunk imports everything:
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_comment
comment|// RUN: echo "=== NOTE === If you see a mismatch below, please update interface.inc files."
end_comment

begin_comment
comment|// RUN: diff %t.imports-sorted %t.exports-sorted
end_comment

begin_comment
comment|// REQUIRES: asan-static-runtime
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

