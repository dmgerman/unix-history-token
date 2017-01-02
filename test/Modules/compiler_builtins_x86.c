begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-unknown-unknown -fsyntax-only -fmodules -fimplicit-module-maps -fmodules-cache-path=%t %s -verify -ffreestanding
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-unknown-unknown -fsyntax-only -fmodules -fmodule-map-file=%resource_dir/module.modulemap -fmodules-cache-path=%t %s -verify -ffreestanding
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

end_unit

