begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check the presence of interface symbols in compiled file.
end_comment

begin_comment
comment|// RUN: %clang_asan -O2 %s -o %t.exe
end_comment

begin_comment
comment|// RUN: nm -D %t.exe | grep " T " | sed "s/.* T //" \
end_comment

begin_comment
comment|// RUN:    | grep "__asan_" | sed "s/___asan_/__asan_/" \
end_comment

begin_comment
comment|// RUN:    | sed -E "s/__asan_version_mismatch_check_v[0-9]+/__asan_version_mismatch_check/" \
end_comment

begin_comment
comment|// RUN:    | grep -v "__asan_default_options" \
end_comment

begin_comment
comment|// RUN:    | grep -v "__asan_stack_" \
end_comment

begin_comment
comment|// RUN:    | grep -v "__asan_on_error"> %t.symbols
end_comment

begin_comment
comment|// RUN: cat %p/../../../../lib/asan/asan_interface_internal.h \
end_comment

begin_comment
comment|// RUN:    | sed "s/\/\/.*//" | sed "s/typedef.*//" \
end_comment

begin_comment
comment|// RUN:    | grep -v "OPTIONAL" \
end_comment

begin_comment
comment|// RUN:    | grep "__asan_.*(" | sed "s/.* __asan_/__asan_/;s/(.*//" \
end_comment

begin_comment
comment|// RUN:> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_load1>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_load2>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_load4>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_load8>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_load16>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_store1>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_store2>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_store4>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_store8>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_store16>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_load_n>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_store_n>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_load1_noabort>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_load2_noabort>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_load4_noabort>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_load8_noabort>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_load16_noabort>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_store1_noabort>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_store2_noabort>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_store4_noabort>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_store8_noabort>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_store16_noabort>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_load_n_noabort>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_store_n_noabort>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_exp_load1>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_exp_load2>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_exp_load4>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_exp_load8>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_exp_load16>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_exp_store1>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_exp_store2>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_exp_store4>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_exp_store8>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_exp_store16>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_exp_load_n>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_report_exp_store_n>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_get_current_fake_stack>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_addr_is_in_fake_stack>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_alloca_poison>> %t.interface
end_comment

begin_comment
comment|// RUN: echo __asan_allocas_unpoison>> %t.interface
end_comment

begin_comment
comment|// RUN: cat %t.interface | sort -u | diff %t.symbols -
end_comment

begin_comment
comment|// FIXME: nm -D on powerpc somewhy shows ASan interface symbols residing
end_comment

begin_comment
comment|// in "initialized data section".
end_comment

begin_comment
comment|// REQUIRES: x86-target-arch,asan-static-runtime
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

