begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: shell
end_comment

begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir -p %t/vdir %t/cache %t/outdir
end_comment

begin_comment
comment|// We can't have module.map inside Inputs/Nonmodular.
end_comment

begin_comment
comment|// RUN: cp %S/Inputs/Nonmodular/Nonmodular.modulemap %t/outdir/module.modulemap
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: sed -e "s:VDIR:%t/vdir:g" -e "s:IN_DIR:%S:g" -e "s:OUT_DIR:%t/outdir:g" %S/Inputs/Nonmodular/nonmodular-headers.yaml> %t/vdir/nonmodular-headers.yaml
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodule-name=Nonmodular -fmodules -Wnon-modular-include-in-framework-module -verify -fimplicit-module-maps -fmodules-cache-path=%t/cache -ivfsoverlay %t/vdir/nonmodular-headers.yaml -I %S/Inputs -F %t/vdir -fsyntax-only %S/Inputs/Nonmodular/test.c
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

end_unit

