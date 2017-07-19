begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -ast-dump -ast-dump-filter Test %s | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -ast-dump %s | FileCheck -check-prefix CHECK-TU -strict-whitespace %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fmodules-local-submodule-visibility -fmodule-name=X -triple x86_64-unknown-unknown -fmodule-map-file=%S/Inputs/module.modulemap -ast-dump -ast-dump-filter Test %s -DMODULES | FileCheck -check-prefix CHECK -check-prefix CHECK-MODULES -strict-whitespace %s
end_comment

begin_decl_stmt
name|int
name|TestLocation
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: VarDecl 0x{{[^ ]*}}<{{.*}}:[[@LINE-1]]:1, col:5> col:5 TestLocation
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MODULES
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|begin
name|X
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|TestIndent
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK:      {{^}}RecordDecl{{.*TestIndent[^()]*$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}`-FieldDecl{{.*x[^()]*$}}
end_comment

begin_struct
struct|struct
name|TestChildren
block|{
name|int
name|x
decl_stmt|;
struct|struct
name|y
block|{
name|int
name|z
decl_stmt|;
block|}
struct|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK:      RecordDecl{{.*}}TestChildren
end_comment

begin_comment
comment|// CHECK-NEXT:   FieldDecl{{.*}}x
end_comment

begin_comment
comment|// CHECK-NEXT:   RecordDecl{{.*}}y
end_comment

begin_comment
comment|// CHECK-NEXT:     FieldDecl{{.*}}z
end_comment

begin_comment
comment|// CHECK-TU: TranslationUnitDecl
end_comment

begin_function
name|void
name|testLabelDecl
parameter_list|()
block|{
name|__label__
name|TestLabelDecl
decl_stmt|;
name|TestLabelDecl
label|:
goto|goto
name|TestLabelDecl
goto|;
block|}
end_function

begin_comment
comment|// CHECK:      LabelDecl{{.*}} TestLabelDecl
end_comment

begin_typedef
typedef|typedef
name|int
name|TestTypedefDecl
typedef|;
end_typedef

begin_comment
comment|// CHECK:      TypedefDecl{{.*}} TestTypedefDecl 'int'
end_comment

begin_macro
name|__module_private__
end_macro

begin_typedef
typedef|typedef
name|int
name|TestTypedefDeclPrivate
typedef|;
end_typedef

begin_comment
comment|// CHECK-MODULE:      TypedefDecl{{.*}} TestTypedefDeclPrivate 'int' __module_private__
end_comment

begin_enum
enum|enum
name|TestEnumDecl
block|{
name|testEnumDecl
block|}
enum|;
end_enum

begin_comment
comment|// CHECK:      EnumDecl{{.*}} TestEnumDecl
end_comment

begin_comment
comment|// CHECK-NEXT:   EnumConstantDecl{{.*}} testEnumDecl
end_comment

begin_struct
struct|struct
name|TestEnumDeclAnon
block|{
enum|enum
block|{
name|testEnumDeclAnon
block|}
name|e
enum|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK:      RecordDecl{{.*}} TestEnumDeclAnon
end_comment

begin_comment
comment|// CHECK-NEXT:   EnumDecl{{.*> .*$}}
end_comment

begin_enum_decl
enum_decl|enum
name|TestEnumDeclForward
enum_decl|;
end_enum_decl

begin_comment
comment|// CHECK:      EnumDecl{{.*}} TestEnumDeclForward
end_comment

begin_decl_stmt
name|__module_private__
name|enum
name|TestEnumDeclPrivate
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-MODULE:      EnumDecl{{.*}} TestEnumDeclPrivate __module_private__
end_comment

begin_struct
struct|struct
name|TestRecordDecl
block|{
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK:      RecordDecl{{.*}} struct TestRecordDecl
end_comment

begin_comment
comment|// CHECK-NEXT:   FieldDecl
end_comment

begin_struct
struct|struct
name|TestRecordDeclEmpty
block|{ }
struct|;
end_struct

begin_comment
comment|// CHECK:      RecordDecl{{.*}} struct TestRecordDeclEmpty
end_comment

begin_struct
struct|struct
name|TestRecordDeclAnon1
block|{
struct|struct
block|{   }
name|testRecordDeclAnon1
struct|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK:      RecordDecl{{.*}} struct TestRecordDeclAnon1
end_comment

begin_comment
comment|// CHECK-NEXT:   RecordDecl{{.*}} struct
end_comment

begin_struct
struct|struct
name|TestRecordDeclAnon2
block|{
struct|struct
block|{   }
struct|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK:      RecordDecl{{.*}} struct TestRecordDeclAnon2
end_comment

begin_comment
comment|// CHECK-NEXT:   RecordDecl{{.*}} struct
end_comment

begin_struct_decl
struct_decl|struct
name|TestRecordDeclForward
struct_decl|;
end_struct_decl

begin_comment
comment|// CHECK:      RecordDecl{{.*}} struct TestRecordDeclForward
end_comment

begin_macro
name|__module_private__
end_macro

begin_struct_decl
struct_decl|struct
name|TestRecordDeclPrivate
struct_decl|;
end_struct_decl

begin_comment
comment|// CHECK-MODULE:      RecordDecl{{.*}} struct TestRecordDeclPrivate __module_private__
end_comment

begin_enum
enum|enum
name|testEnumConstantDecl
block|{
name|TestEnumConstantDecl
block|,
name|TestEnumConstantDeclInit
init|=
literal|1
block|}
enum|;
end_enum

begin_comment
comment|// CHECK:      EnumConstantDecl{{.*}} TestEnumConstantDecl 'int'
end_comment

begin_comment
comment|// CHECK:      EnumConstantDecl{{.*}} TestEnumConstantDeclInit 'int'
end_comment

begin_comment
comment|// CHECK-NEXT:   IntegerLiteral
end_comment

begin_struct
struct|struct
name|testIndirectFieldDecl
block|{
struct|struct
block|{
name|int
name|TestIndirectFieldDecl
decl_stmt|;
block|}
struct|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK:      IndirectFieldDecl{{.*}} TestIndirectFieldDecl 'int'
end_comment

begin_comment
comment|// CHECK-NEXT:   Field{{.*}} ''
end_comment

begin_comment
comment|// CHECK-NEXT:   Field{{.*}} 'TestIndirectFieldDecl'
end_comment

begin_comment
comment|// FIXME: It would be nice to dump the enum and its enumerators.
end_comment

begin_decl_stmt
name|int
name|TestFunctionDecl
argument_list|(
name|int
name|x
argument_list|,
expr|enum
block|{
name|e
block|}
name|y
argument_list|)
block|{
return|return
name|x
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK:      FunctionDecl{{.*}} TestFunctionDecl 'int (int, enum {{.*}})'
end_comment

begin_comment
comment|// CHECK-NEXT:   ParmVarDecl{{.*}} x
end_comment

begin_comment
comment|// CHECK-NEXT:   ParmVarDecl{{.*}} y
end_comment

begin_comment
comment|// CHECK-NEXT:   CompoundStmt
end_comment

begin_comment
comment|// FIXME: It would be nice to 'Enum' and 'e'.
end_comment

begin_decl_stmt
name|int
name|TestFunctionDecl2
argument_list|(
expr|enum
name|Enum
block|{
name|e
block|}
name|x
argument_list|)
block|{
return|return
name|x
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK:      FunctionDecl{{.*}} TestFunctionDecl2 'int (enum {{.*}})'
end_comment

begin_comment
comment|// CHECK-NEXT:   ParmVarDecl{{.*}} x
end_comment

begin_comment
comment|// CHECK-NEXT:   CompoundStmt
end_comment

begin_function_decl
name|int
name|TestFunctionDeclProto
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK:      FunctionDecl{{.*}} TestFunctionDeclProto 'int (int)'
end_comment

begin_comment
comment|// CHECK-NEXT:   ParmVarDecl{{.*}} x
end_comment

begin_function_decl
specifier|extern
name|int
name|TestFunctionDeclSC
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// CHECK:      FunctionDecl{{.*}} TestFunctionDeclSC 'int ()' extern
end_comment

begin_function_decl
specifier|inline
name|int
name|TestFunctionDeclInline
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// CHECK:      FunctionDecl{{.*}} TestFunctionDeclInline 'int ()' inline
end_comment

begin_struct
struct|struct
name|testFieldDecl
block|{
name|int
name|TestFieldDecl
decl_stmt|;
name|int
name|TestFieldDeclWidth
range|:
literal|1
decl_stmt|;
name|__module_private__
name|int
name|TestFieldDeclPrivate
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK:      FieldDecl{{.*}} TestFieldDecl 'int'
end_comment

begin_comment
comment|// CHECK:      FieldDecl{{.*}} TestFieldDeclWidth 'int'
end_comment

begin_comment
comment|// CHECK-NEXT:   IntegerLiteral
end_comment

begin_comment
comment|// CHECK-MODULE:      FieldDecl{{.*}} TestFieldDeclPrivate 'int' __module_private__
end_comment

begin_decl_stmt
name|int
name|TestVarDecl
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:      VarDecl{{.*}} TestVarDecl 'int'
end_comment

begin_decl_stmt
specifier|extern
name|int
name|TestVarDeclSC
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:      VarDecl{{.*}} TestVarDeclSC 'int' extern
end_comment

begin_decl_stmt
name|__thread
name|int
name|TestVarDeclThread
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:      VarDecl{{.*}} TestVarDeclThread 'int' tls{{$}}
end_comment

begin_decl_stmt
name|__module_private__
name|int
name|TestVarDeclPrivate
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-MODULE:      VarDecl{{.*}} TestVarDeclPrivate 'int' __module_private__
end_comment

begin_decl_stmt
name|int
name|TestVarDeclInit
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:      VarDecl{{.*}} TestVarDeclInit 'int'
end_comment

begin_comment
comment|// CHECK-NEXT:   IntegerLiteral
end_comment

begin_function_decl
name|void
name|testParmVarDecl
parameter_list|(
name|int
name|TestParmVarDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: ParmVarDecl{{.*}} TestParmVarDecl 'int'
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MODULES
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|end
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

