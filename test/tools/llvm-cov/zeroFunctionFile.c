begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"Inputs/zeroFunctionFile.h"
end_include

begin_function
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|NOFUNCTIONS
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
name|foo
argument_list|(
literal|2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/zeroFunctionFile.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: llvm-cov report %S/Inputs/zeroFunctionFile.covmapping -instr-profile %t.profdata 2>&1 | FileCheck --check-prefix=REPORT --strict-whitespace %s
end_comment

begin_comment
comment|// REPORT: 0                 0         -           0                 0         -               0               0         -           0                 0         -
end_comment

begin_comment
comment|// REPORT-NO: 0%
end_comment

begin_comment
comment|// RUN: llvm-cov show -j 1 %S/Inputs/zeroFunctionFile.covmapping -format html -instr-profile %t.profdata -o %t.dir
end_comment

begin_comment
comment|// RUN: FileCheck %s -input-file=%t.dir/index.html -check-prefix=HTML
end_comment

begin_comment
comment|// HTML:<td class='column-entry-green'><pre>- (0/0)
end_comment

begin_comment
comment|// HTML-NO: 0.00% (0/0)
end_comment

end_unit

