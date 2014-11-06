begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check the presense of interface symbols in the ASan runtime dylib.
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
comment|// RUN: rm -f %t.symbols %t.interface
end_comment

begin_comment
comment|// RUN: nm -g `otool -L %t.exe | grep "asan_osx_dynamic.dylib" | \
end_comment

begin_comment
comment|// RUN:                       tr -d '\011' | \
end_comment

begin_comment
comment|// RUN:                       sed "s/.dylib.*/.dylib/"` \
end_comment

begin_comment
comment|// RUN:   | grep " T " | sed "s/.* T //" \
end_comment

begin_comment
comment|// RUN:   | grep "__asan_" | sed "s/___asan_/__asan_/" \
end_comment

begin_comment
comment|// RUN:   | grep -v "__asan_malloc_hook" \
end_comment

begin_comment
comment|// RUN:   | grep -v "__asan_free_hook" \
end_comment

begin_comment
comment|// RUN:   | grep -v "__asan_symbolize" \
end_comment

begin_comment
comment|// RUN:   | grep -v "__asan_default_options" \
end_comment

begin_comment
comment|// RUN:   | grep -v "__asan_on_error"> %t.symbols
end_comment

begin_comment
comment|// RUN: cat %p/../../../asan_interface_internal.h \
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
comment|// RUN: for i in `jot - 0 10`; do echo __asan_stack_malloc_$i>> %t.interface; done
end_comment

begin_comment
comment|// RUN: for i in `jot - 0 10`; do echo __asan_stack_free_$i>> %t.interface; done
end_comment

begin_comment
comment|// RUN: cat %t.interface | sort -u | diff %t.symbols -
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

