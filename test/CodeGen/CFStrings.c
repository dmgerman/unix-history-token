begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target,x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-COFF
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-COFF
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-COFF
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-elf -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-ELF -check-prefix CHECK-ELF32
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-elf -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-ELF -check-prefix CHECK-ELF32
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-elf -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-ELF -check-prefix CHECK-ELF64
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-elf -S %s -o - | FileCheck %s -check-prefix CHECK-ELF-DATA-SECTION
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-macho -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-MACHO -check-prefix CHECK-MACHO32
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-macosx -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-MACHO -check-prefix CHECK-MACHO32
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-macho -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-MACHO -check-prefix CHECK-MACHO64
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -S %s -o - | FileCheck %s -check-prefix CHECK-ASM-COFF
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-elf -S %s -o - | FileCheck %s -check-prefix CHECK-ASM-ELF
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-macho -S %s -o - | FileCheck %s -check-prefix CHECK-ASM-MACHO
end_comment

begin_typedef
typedef|typedef
name|struct
name|__CFString
modifier|*
name|CFStringRef
typedef|;
end_typedef

begin_decl_stmt
specifier|const
name|CFStringRef
name|one
init|=
operator|(
name|CFStringRef
operator|)
name|__builtin___CFStringMakeConstantString
argument_list|(
literal|"one"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|CFStringRef
name|two
init|=
operator|(
name|CFStringRef
operator|)
name|__builtin___CFStringMakeConstantString
argument_list|(
literal|"\xef\xbf\xbd\x74\xef\xbf\xbd\x77\xef\xbf\xbd\x6f"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-COFF: @.str = private unnamed_addr constant [4 x i8] c"one\00", align 1
end_comment

begin_comment
comment|// CHECK-ELF: @.str = private unnamed_addr constant [4 x i8] c"one\00", align 1
end_comment

begin_comment
comment|// CHECK-MACHO: @.str = private unnamed_addr constant [4 x i8] c"one\00", section "__TEXT,__cstring,cstring_literals", align 1
end_comment

begin_comment
comment|// CHECK-COFF: @_unnamed_cfstring_ = private global %struct.__NSConstantString_tag { i32* getelementptr inbounds ([0 x i32], [0 x i32]* @__CFConstantStringClassReference, i32 0, i32 0), i32 1992, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32 3 }, section "cfstring", align {{[48]}}
end_comment

begin_comment
comment|// CHECK-ELF32: @_unnamed_cfstring_ = private global %struct.__NSConstantString_tag { i32* getelementptr inbounds ([0 x i32], [0 x i32]* @__CFConstantStringClassReference, i32 0, i32 0), i32 1992, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32 3 }, section "cfstring", align 4
end_comment

begin_comment
comment|// CHECK-ELF64: @_unnamed_cfstring_ = private global %struct.__NSConstantString_tag { i32* getelementptr inbounds ([0 x i32], [0 x i32]* @__CFConstantStringClassReference, i32 0, i32 0), i32 1992, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i64 3 }, section "cfstring", align 8
end_comment

begin_comment
comment|// CHECK-MACHO32: @_unnamed_cfstring_ = private global %struct.__NSConstantString_tag { i32* getelementptr inbounds ([0 x i32], [0 x i32]* @__CFConstantStringClassReference, i32 0, i32 0), i32 1992, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32 3 }, section "__DATA,__cfstring", align 4
end_comment

begin_comment
comment|// CHECK-MACHO64: @_unnamed_cfstring_ = private global %struct.__NSConstantString_tag { i32* getelementptr inbounds ([0 x i32], [0 x i32]* @__CFConstantStringClassReference, i32 0, i32 0), i32 1992, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i64 3 }, section "__DATA,__cfstring", align 8
end_comment

begin_comment
comment|// CHECK-COFF: @.str.1 = private unnamed_addr constant [7 x i16] [i16 -3, i16 116, i16 -3, i16 119, i16 -3, i16 111, i16 0], align 2
end_comment

begin_comment
comment|// CHECK-ELF: @.str.1 = private unnamed_addr constant [7 x i16] [i16 -3, i16 116, i16 -3, i16 119, i16 -3, i16 111, i16 0], align 2
end_comment

begin_comment
comment|// CHECK-MACHO: @.str.1 = private unnamed_addr constant [7 x i16] [i16 -3, i16 116, i16 -3, i16 119, i16 -3, i16 111, i16 0], section "__TEXT,__ustring", align 2
end_comment

begin_comment
comment|// CHECK-COFF: @_unnamed_cfstring_.2 = private global %struct.__NSConstantString_tag { i32* getelementptr inbounds ([0 x i32], [0 x i32]* @__CFConstantStringClassReference, i32 0, i32 0), i32 2000, i8* bitcast ([7 x i16]* @.str.1 to i8*), i32 6 }, section "cfstring", align {{[48]}}
end_comment

begin_comment
comment|// CHECK-ELF32: @_unnamed_cfstring_.2 = private global %struct.__NSConstantString_tag { i32* getelementptr inbounds ([0 x i32], [0 x i32]* @__CFConstantStringClassReference, i32 0, i32 0), i32 2000, i8* bitcast ([7 x i16]* @.str.1 to i8*), i32 6 }, section "cfstring", align 4
end_comment

begin_comment
comment|// CHECK-ELF64: @_unnamed_cfstring_.2 = private global %struct.__NSConstantString_tag { i32* getelementptr inbounds ([0 x i32], [0 x i32]* @__CFConstantStringClassReference, i32 0, i32 0), i32 2000, i8* bitcast ([7 x i16]* @.str.1 to i8*), i64 6 }, section "cfstring", align 8
end_comment

begin_comment
comment|// CHECK-MACHO32: @_unnamed_cfstring_.2 = private global %struct.__NSConstantString_tag { i32* getelementptr inbounds ([0 x i32], [0 x i32]* @__CFConstantStringClassReference, i32 0, i32 0), i32 2000, i8* bitcast ([7 x i16]* @.str.1 to i8*), i32 6 }, section "__DATA,__cfstring", align 4
end_comment

begin_comment
comment|// CHECK-MACHO64: @_unnamed_cfstring_.2 = private global %struct.__NSConstantString_tag { i32* getelementptr inbounds ([0 x i32], [0 x i32]* @__CFConstantStringClassReference, i32 0, i32 0), i32 2000, i8* bitcast ([7 x i16]* @.str.1 to i8*), i64 6 }, section "__DATA,__cfstring", align 8
end_comment

begin_comment
comment|// CHECK-ELF-DATA-SECTION: .section .rodata.str1.1
end_comment

begin_comment
comment|// CHECK-ELF-DATA-SECTION: .asciz "one"
end_comment

begin_comment
comment|// CHECK-ELF-DATA-SECTION: .section .rodata.str2.2
end_comment

begin_comment
comment|// CHECK-ELF-DATA-SECTION: .short 65533
end_comment

begin_comment
comment|// CHECK-ELF-DATA-SECTION: .short 116
end_comment

begin_comment
comment|// CHECK-ELF-DATA-SECTION: .short 65533
end_comment

begin_comment
comment|// CHECK-ELF-DATA-SECTION: .short 119
end_comment

begin_comment
comment|// CHECK-ELF-DATA-SECTION: .short 65533
end_comment

begin_comment
comment|// CHECK-ELF-DATA-SECTION: .short 111
end_comment

begin_comment
comment|// CHECK-ELF-DATA-SECTION: .short 0
end_comment

begin_comment
comment|// CHECK-ASM-COFF: .section cfstring,"dw"
end_comment

begin_comment
comment|// CHECK-ASM-ELF: .section cfstring,"aw"
end_comment

begin_comment
comment|// CHECK-ASM-MACHO: .section __DATA,__cfstring
end_comment

end_unit

