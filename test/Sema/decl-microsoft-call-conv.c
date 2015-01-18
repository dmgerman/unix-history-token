begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-win32 -verify %s
end_comment

begin_comment
comment|// It's important that this is a .c file.
end_comment

begin_comment
comment|// This is fine, as CrcGenerateTable*() has a prototype.
end_comment

begin_function_decl
name|void
name|__fastcall
name|CrcGenerateTableFastcall
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__fastcall
name|CrcGenerateTableFastcall
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|__fastcall
name|CrcGenerateTableFastcall
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|__stdcall
name|CrcGenerateTableStdcall
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__stdcall
name|CrcGenerateTableStdcall
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|__stdcall
name|CrcGenerateTableStdcall
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|__thiscall
name|CrcGenerateTableThiscall
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__thiscall
name|CrcGenerateTableThiscall
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|__thiscall
name|CrcGenerateTableThiscall
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|__pascal
name|CrcGenerateTablePascal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__pascal
name|CrcGenerateTablePascal
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|__pascal
name|CrcGenerateTablePascal
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|__vectorcall
name|CrcGenerateTableVectorcall
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__vectorcall
name|CrcGenerateTableVectorcall
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|__vectorcall
name|CrcGenerateTableVectorcall
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|__fastcall
name|CrcGenerateTableNoProtoFastcall
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{function with no prototype cannot use the fastcall calling convention}}
end_comment

begin_function_decl
name|void
name|__stdcall
name|CrcGenerateTableNoProtoStdcall
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{function with no prototype cannot use the stdcall calling convention}}
end_comment

begin_function_decl
name|void
name|__thiscall
name|CrcGenerateTableNoProtoThiscall
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{function with no prototype cannot use the thiscall calling convention}}
end_comment

begin_function_decl
name|void
name|__pascal
name|CrcGenerateTableNoProtoPascal
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{function with no prototype cannot use the pascal calling convention}}
end_comment

begin_function_decl
name|void
name|__vectorcall
name|CrcGenerateTableNoProtoVectorcall
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{function with no prototype cannot use the vectorcall calling convention}}
end_comment

begin_function
name|void
name|__fastcall
name|CrcGenerateTableNoProtoDefFastcall
parameter_list|()
block|{}
end_function

begin_function
name|void
name|__stdcall
name|CrcGenerateTableNoProtoDefStdcall
parameter_list|()
block|{}
end_function

begin_function
name|void
name|__thiscall
name|CrcGenerateTableNoProtoDefThiscall
parameter_list|()
block|{}
end_function

begin_function
name|void
name|__pascal
name|CrcGenerateTableNoProtoDefPascal
parameter_list|()
block|{}
end_function

begin_function
name|void
name|__vectorcall
name|CrcGenerateTableNoProtoDefVectorcall
parameter_list|()
block|{}
end_function

begin_comment
comment|// Regular calling convention is fine.
end_comment

begin_function
name|void
name|CrcGenerateTableNoProto
parameter_list|()
block|{}
end_function

end_unit

