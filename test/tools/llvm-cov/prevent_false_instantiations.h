begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Checks that function instantiations don't go to a wrong file.
end_comment

begin_comment
comment|// INSTANTIATION-NOT: {{_Z5func[1,2]v}}
end_comment

begin_comment
comment|// NAN-NOT: {{[ \t]+}}nan%
end_comment

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/prevent_false_instantiations.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: llvm-cov show -format text %S/Inputs/prevent_false_instantiations.covmapping -instr-profile %t.profdata -filename-equivalence %s | FileCheck %s -check-prefix=INSTANTIATION
end_comment

begin_comment
comment|// RUN: llvm-cov report %S/Inputs/prevent_false_instantiations.covmapping -instr-profile %t.profdata | FileCheck %s -check-prefix=NAN
end_comment

begin_define
define|#
directive|define
name|DO_SOMETHING
parameter_list|()
define|\
value|do {                 \   } while (0)
end_define

end_unit

