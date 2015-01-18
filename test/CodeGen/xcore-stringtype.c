begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: xcore-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple xcore-unknown-unknown -fno-signed-char -fno-common -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: target triple = "xcore-unknown-unknown"
end_comment

begin_comment
comment|// In the tests below, some types are not supported by the ABI (_Complex,
end_comment

begin_comment
comment|// variable length arrays) and will thus emit no meta data.
end_comment

begin_comment
comment|// The 38 tests that do emit typestrings are gathered into '!xcore.typestrings'
end_comment

begin_comment
comment|// Please see 'Tools Development Guide' section 2.16.2 for format details:
end_comment

begin_comment
comment|//<https://www.xmos.com/download/public/Tools-Development-Guide%28X9114A%29.pdf>
end_comment

begin_comment
comment|// CHECK: !xcore.typestrings = !{
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}},
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}},
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}},
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}},
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}},
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}},
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}},
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}}, !{{[0-9]+}}, !{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK-NOT: , !{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// test BuiltinType
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{void (i1, i8, i8, i8, i16, i16, i16, i32, i32, i32,
end_comment

begin_comment
comment|// CHECK:      i32, i32, i32, i64, i64, i64, float, double, double)*
end_comment

begin_comment
comment|// CHECK:      @builtinType, !"f{0}(b,uc,uc,sc,ss,us,ss,si,ui,si,sl,
end_comment

begin_comment
comment|// CHECK:      ul,sl,sll,ull,sll,ft,d,ld)"}
end_comment

begin_function
name|void
name|builtinType
parameter_list|(
name|_Bool
name|B
parameter_list|,
name|char
name|C
parameter_list|,
name|unsigned
name|char
name|UC
parameter_list|,
name|signed
name|char
name|SC
parameter_list|,
name|short
name|S
parameter_list|,
name|unsigned
name|short
name|US
parameter_list|,
name|signed
name|short
name|SS
parameter_list|,
name|int
name|I
parameter_list|,
name|unsigned
name|int
name|UI
parameter_list|,
name|signed
name|int
name|SI
parameter_list|,
name|long
name|L
parameter_list|,
name|unsigned
name|long
name|UL
parameter_list|,
name|signed
name|long
name|SL
parameter_list|,
name|long
name|long
name|LL
parameter_list|,
name|unsigned
name|long
name|long
name|ULL
parameter_list|,
name|signed
name|long
name|long
name|SLL
parameter_list|,
name|float
name|F
parameter_list|,
name|double
name|D
parameter_list|,
name|long
name|double
name|LD
parameter_list|)
block|{}
end_function

begin_decl_stmt
name|double
specifier|_Complex
name|Complex
decl_stmt|;
end_decl_stmt

begin_comment
comment|// not supported
end_comment

begin_comment
comment|// test FunctionType& Qualifiers
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{void ()* @gI, !"f{0}()"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{void (...)* @eI, !"f{0}()"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{void ()* @gV, !"f{0}(0)"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{void ()* @eV, !"f{0}(0)"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{void (i32, ...)* @gVA, !"f{0}(si,va)"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{void (i32, ...)* @eVA, !"f{0}(si,va)"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{i32* (i32*)* @gQ, !"f{crv:p(cv:si)}(p(cv:si))"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{i32* (i32*)* @eQ, !"f{crv:p(cv:si)}(p(cv:si))"}
end_comment

begin_function_decl
specifier|extern
name|void
name|eI
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|gI
parameter_list|()
block|{
name|eI
argument_list|()
expr_stmt|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|eV
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|gV
parameter_list|(
name|void
parameter_list|)
block|{
name|eV
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|eVA
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|gVA
parameter_list|(
name|int
name|i
parameter_list|,
modifier|...
parameter_list|)
block|{
name|eVA
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
specifier|const
specifier|volatile
name|int
modifier|*
specifier|volatile
specifier|restrict
specifier|const
name|eQ
parameter_list|(
specifier|const
specifier|volatile
name|int
modifier|*
specifier|volatile
specifier|restrict
specifier|const
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|const
specifier|volatile
name|int
modifier|*
specifier|volatile
specifier|restrict
specifier|const
name|gQ
parameter_list|(
specifier|const
specifier|volatile
name|int
modifier|*
specifier|volatile
specifier|restrict
specifier|const
name|i
parameter_list|)
block|{
return|return
name|eQ
argument_list|(
name|i
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// test PointerType
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{i32* (i32*, i32* (i32*)*)*
end_comment

begin_comment
comment|// CHECK:       @pointerType, !"f{p(si)}(p(si),p(f{p(si)}(p(si))))"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{i32** @EP, !"p(si)"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{i32** @GP, !"p(si)"}
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|EP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|GP
decl_stmt|;
end_decl_stmt

begin_function
name|int
modifier|*
name|pointerType
parameter_list|(
name|int
modifier|*
name|I
parameter_list|,
name|int
modifier|*
function_decl|(
modifier|*
name|FP
function_decl|)
parameter_list|(
name|int
modifier|*
parameter_list|)
parameter_list|)
block|{
return|return
name|I
condition|?
name|EP
else|:
name|GP
return|;
block|}
end_function

begin_comment
comment|// test ArrayType
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{[2 x i32]* (i32*, i32*, [2 x i32]*, [2 x i32]*, i32*)*
end_comment

begin_comment
comment|// CHECK:       @arrayType, !"f{p(a(2:si))}(p(si),p(cv:si),p(a(2:si)),
end_comment

begin_comment
comment|// CHECK:       p(a(2:si)),p(si))"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{[0 x i32]* @EA1, !"a(*:cv:si)"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{[2 x i32]* @EA2, !"a(2:si)"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{[0 x [2 x i32]]* @EA3, !"a(*:a(2:si))"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{[3 x [2 x i32]]* @EA4, !"a(3:a(2:si))"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{[2 x i32]* @GA1, !"a(2:cv:si)"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{void ([2 x i32]*)* @arrayTypeVariable1,
end_comment

begin_comment
comment|// CHECK:       !"f{0}(p(a(2:si)))"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{void (void ([2 x i32]*)*)* @arrayTypeVariable2,
end_comment

begin_comment
comment|// CHECK:       !"f{0}(p(f{0}(p(a(2:si)))))"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{[3 x [2 x i32]]* @GA2, !"a(3:a(2:si))"}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|GA2
index|[
literal|3
index|]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
specifier|volatile
name|int
name|EA1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EA2
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EA3
index|[]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EA4
index|[
literal|3
index|]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
specifier|volatile
name|int
name|GA1
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|arrayTypeVariable1
parameter_list|(
name|int
index|[
operator|*
index|]
index|[
literal|2
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arrayTypeVariable2
parameter_list|(
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|int
index|[
operator|*
index|]
index|[
literal|2
index|]
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arrayTypeVariable3
parameter_list|(
name|int
index|[
literal|3
index|]
index|[
operator|*
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// not supported
end_comment

begin_function_decl
specifier|extern
name|void
name|arrayTypeVariable4
parameter_list|(
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|int
index|[
literal|3
index|]
index|[
operator|*
index|]
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// not supported
end_comment

begin_typedef
typedef|typedef
name|int
name|RetType
index|[
literal|2
index|]
typedef|;
end_typedef

begin_function
name|RetType
modifier|*
name|arrayType
parameter_list|(
name|int
name|A1
index|[]
parameter_list|,
name|int
specifier|const
specifier|volatile
name|A2
index|[
literal|2
index|]
parameter_list|,
name|int
name|A3
index|[]
index|[
literal|2
index|]
parameter_list|,
name|int
name|A4
index|[
literal|3
index|]
index|[
literal|2
index|]
parameter_list|,
name|int
name|A5
index|[
specifier|const
specifier|volatile
specifier|restrict
specifier|static
literal|2
index|]
parameter_list|)
block|{
if|if
condition|(
name|A1
condition|)
name|EA2
index|[
literal|0
index|]
operator|=
name|EA1
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
name|A2
condition|)
return|return
operator|&
name|EA2
return|;
if|if
condition|(
name|A3
condition|)
return|return
name|EA3
return|;
if|if
condition|(
name|A4
condition|)
return|return
name|EA4
return|;
if|if
condition|(
name|A5
condition|)
name|EA2
index|[
literal|0
index|]
operator|=
name|GA1
index|[
literal|0
index|]
expr_stmt|;
name|arrayTypeVariable1
argument_list|(
name|EA4
argument_list|)
expr_stmt|;
name|arrayTypeVariable2
argument_list|(
name|arrayTypeVariable1
argument_list|)
expr_stmt|;
name|arrayTypeVariable3
argument_list|(
name|EA4
argument_list|)
expr_stmt|;
name|arrayTypeVariable4
argument_list|(
name|arrayTypeVariable3
argument_list|)
expr_stmt|;
return|return
name|GA2
return|;
block|}
end_function

begin_comment
comment|// test StructureType
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{void (%struct.S1*)* @structureType1,
end_comment

begin_comment
comment|// CHECK:       !"f{0}(s(S1){m(ps2){p(s(S2){m(ps3){p(s(S3){m(s1){s(S1){}}})}})}})"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{void (%struct.S2*)* @structureType2,
end_comment

begin_comment
comment|// CHECK:       !"f{0}(s(S2){m(ps3){p(s(S3){m(s1){s(S1){m(ps2){p(s(S2){})}}}})}})"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{void (%struct.S3*)* @structureType3,
end_comment

begin_comment
comment|// CHECK:       !"f{0}(s(S3){m(s1){s(S1){m(ps2){p(s(S2){m(ps3){p(s(S3){})}})}}}})"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{void (%struct.S4*)* @structureType4,
end_comment

begin_comment
comment|// CHECK:       !"f{0}(s(S4){m(s1){s(S1){m(ps2){p(s(S2){m(ps3){p(s(S3){m(s1){s(S1){}}})}})}}}})"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{%struct.anon* @StructAnon, !"s(){m(A){si}}"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{i32 (%struct.SB*)* @structureTypeB,
end_comment

begin_comment
comment|// CHECK:       !"f{si}(s(SB){m(){b(4:si)},m(){b(2:si)},m(N4){b(4:si)},
end_comment

begin_comment
comment|// CHECK:       m(N2){b(2:si)},m(){b(4:ui)},m(){b(4:si)},m(){b(4:c:si)},
end_comment

begin_comment
comment|// CHECK:       m(){b(4:c:si)},m(){b(4:cv:si)}})"}
end_comment

begin_struct_decl
struct_decl|struct
name|S2
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|S1
block|{
name|struct
name|S2
modifier|*
name|ps2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|S3
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|S2
block|{
name|struct
name|S3
modifier|*
name|ps3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|S3
block|{
name|struct
name|S1
name|s1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|S4
block|{
name|struct
name|S1
name|s1
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|structureType1
parameter_list|(
name|struct
name|S1
name|s1
parameter_list|)
block|{}
end_function

begin_function
name|void
name|structureType2
parameter_list|(
name|struct
name|S2
name|s2
parameter_list|)
block|{}
end_function

begin_function
name|void
name|structureType3
parameter_list|(
name|struct
name|S3
name|s3
parameter_list|)
block|{}
end_function

begin_function
name|void
name|structureType4
parameter_list|(
name|struct
name|S4
name|s4
parameter_list|)
block|{}
end_function

begin_struct
struct|struct
block|{
name|int
name|A
decl_stmt|;
block|}
name|StructAnon
init|=
block|{
literal|1
block|}
struct|;
end_struct

begin_struct
struct|struct
name|SB
block|{
name|int
label|:
literal|4
expr_stmt|;
name|int
label|:
literal|2
expr_stmt|;
name|int
name|N4
range|:
literal|4
decl_stmt|;
name|int
name|N2
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
range|:
literal|4
decl_stmt|;
name|signed
name|int
range|:
literal|4
decl_stmt|;
specifier|const
name|int
operator|:
literal|4
expr_stmt|;
name|int
specifier|const
operator|:
literal|4
expr_stmt|;
specifier|volatile
specifier|const
name|int
operator|:
literal|4
expr_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|structureTypeB
parameter_list|(
name|struct
name|SB
name|sb
parameter_list|)
block|{
return|return
name|StructAnon
operator|.
name|A
return|;
block|}
end_function

begin_comment
comment|// test UnionType
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{void (%union.U1*)* @unionType1,
end_comment

begin_comment
comment|// CHECK:       !"f{0}(u(U1){m(pu2){p(u(U2){m(pu3){p(u(U3){m(u1){u(U1){}}})}})}})"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{void (%union.U2*)* @unionType2,
end_comment

begin_comment
comment|// CHECK:       !"f{0}(u(U2){m(pu3){p(u(U3){m(u1){u(U1){m(pu2){p(u(U2){})}}}})}})"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{void (%union.U3*)* @unionType3,
end_comment

begin_comment
comment|// CHECK:       !"f{0}(u(U3){m(u1){u(U1){m(pu2){p(u(U2){m(pu3){p(u(U3){})}})}}}})"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{void (%union.U4*)* @unionType4,
end_comment

begin_comment
comment|// CHECK:       !"f{0}(u(U4){m(u1){u(U1){m(pu2){p(u(U2){m(pu3){p(u(U3){m(u1){u(U1){}}})}})}}}})"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{%union.anon* @UnionAnon, !"u(){m(A){si}}"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{i32 (%union.UB*)* @unionTypeB,
end_comment

begin_comment
comment|// CHECK:       !"f{si}(u(UB){m(N2){b(2:si)},m(N4){b(4:si)},m(){b(2:si)},
end_comment

begin_comment
comment|// CHECK:       m(){b(4:c:si)},m(){b(4:c:si)},m(){b(4:cv:si)},m(){b(4:si)},
end_comment

begin_comment
comment|// CHECK:       m(){b(4:si)},m(){b(4:ui)}})"}
end_comment

begin_union_decl
union_decl|union
name|U2
union_decl|;
end_union_decl

begin_union
union|union
name|U1
block|{
name|union
name|U2
modifier|*
name|pu2
decl_stmt|;
block|}
union|;
end_union

begin_union_decl
union_decl|union
name|U3
union_decl|;
end_union_decl

begin_union
union|union
name|U2
block|{
name|union
name|U3
modifier|*
name|pu3
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|U3
block|{
name|union
name|U1
name|u1
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|U4
block|{
name|union
name|U1
name|u1
decl_stmt|;
block|}
union|;
end_union

begin_function
name|void
name|unionType1
parameter_list|(
name|union
name|U1
name|u1
parameter_list|)
block|{}
end_function

begin_function
name|void
name|unionType2
parameter_list|(
name|union
name|U2
name|u2
parameter_list|)
block|{}
end_function

begin_function
name|void
name|unionType3
parameter_list|(
name|union
name|U3
name|u3
parameter_list|)
block|{}
end_function

begin_function
name|void
name|unionType4
parameter_list|(
name|union
name|U4
name|u4
parameter_list|)
block|{}
end_function

begin_union
union|union
name|UB
block|{
name|int
label|:
literal|4
expr_stmt|;
name|int
label|:
literal|2
expr_stmt|;
name|int
name|N4
range|:
literal|4
decl_stmt|;
name|int
name|N2
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
range|:
literal|4
decl_stmt|;
name|signed
name|int
range|:
literal|4
decl_stmt|;
specifier|const
name|int
operator|:
literal|4
expr_stmt|;
name|int
specifier|const
operator|:
literal|4
expr_stmt|;
specifier|volatile
specifier|const
name|int
operator|:
literal|4
expr_stmt|;
block|}
union|;
end_union

begin_union
union|union
block|{
name|int
name|A
decl_stmt|;
block|}
name|UnionAnon
init|=
block|{
literal|1
block|}
union|;
end_union

begin_function
name|int
name|unionTypeB
parameter_list|(
name|union
name|UB
name|ub
parameter_list|)
block|{
return|return
name|UnionAnon
operator|.
name|A
return|;
block|}
end_function

begin_comment
comment|// test EnumType
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{i32* @EnumAnon, !"e(){m(EA){3}}"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{i32 (i32)* @enumType,
end_comment

begin_comment
comment|// CHECK:       !"f{si}(e(E){m(A){7},m(B){6},m(C){5},m(D){0}})"}
end_comment

begin_enum
enum|enum
name|E
block|{
name|D
block|,
name|C
init|=
literal|5
block|,
name|B
block|,
name|A
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|EA
init|=
literal|3
block|}
name|EnumAnon
init|=
name|EA
enum|;
end_enum

begin_function
name|int
name|enumType
parameter_list|(
name|enum
name|E
name|e
parameter_list|)
block|{
return|return
name|EnumAnon
return|;
block|}
end_function

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{i32 ()* @testReDecl, !"f{si}()"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{[10 x i32]* @After, !"a(10:si)"}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{[10 x i32]* @Before, !"a(10:si)"}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|After
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Before
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|testReDecl
parameter_list|()
block|{
return|return
name|After
index|[
literal|0
index|]
operator|+
name|Before
index|[
literal|0
index|]
return|;
block|}
end_function

begin_decl_stmt
name|int
name|After
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Before
index|[]
decl_stmt|;
end_decl_stmt

end_unit

