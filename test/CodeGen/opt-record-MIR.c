begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios -S -o /dev/null %s -O2 -dwarf-column-info -Rpass-missed=regalloc 2>&1 | FileCheck -check-prefix=REMARK %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios -S -o /dev/null %s -O2 -dwarf-column-info 2>&1 | FileCheck -allow-empty -check-prefix=NO_REMARK %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios -S -o /dev/null %s -O2 -dwarf-column-info -opt-record-file %t.yaml
end_comment

begin_comment
comment|// RUN: cat %t.yaml | FileCheck -check-prefix=YAML %s
end_comment

begin_function_decl
name|void
name|bar
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|(
name|float
modifier|*
name|p
parameter_list|,
name|int
name|i
parameter_list|)
block|{
while|while
condition|(
name|i
operator|--
condition|)
block|{
name|float
name|f
init|=
operator|*
name|p
decl_stmt|;
asm|asm("" ::         : "d0", "d1", "d2", "d3", "d4", "d5", "d6", "d7", "d8", "d9", "d10", "d11", "d12", "d13", "d14", "d15", "d16", "d17", "d18", "d19", "d20", "d21", "d22", "d23", "d24", "d25", "d26", "d27", "d28", "d29", "d30", "d31", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "fp", "lr", "sp", "memory");
name|bar
argument_list|(
name|f
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// REMARK: opt-record-MIR.c:10:11: remark: {{.}} spills {{.}} reloads generated in loop
end_comment

begin_comment
comment|// NO_REMARK-NOT: remark:
end_comment

begin_comment
comment|// YAML: --- !Missed
end_comment

begin_comment
comment|// YAML: Pass:            regalloc
end_comment

begin_comment
comment|// YAML: Name:            LoopSpillReload
end_comment

begin_comment
comment|// YAML: DebugLoc:        { File: {{.*}},
end_comment

begin_comment
comment|// YAML:                    Line: 10, Column: 11 }
end_comment

begin_comment
comment|// YAML: Function:        foo
end_comment

begin_comment
comment|// YAML: Args:
end_comment

begin_comment
comment|// YAML:   - NumSpills:       '{{.}}'
end_comment

begin_comment
comment|// YAML:   - String:          ' spills '
end_comment

begin_comment
comment|// YAML:   - NumReloads:      '{{.}}'
end_comment

begin_comment
comment|// YAML:   - String:          ' reloads '
end_comment

begin_comment
comment|// YAML:   - String:          generated
end_comment

begin_comment
comment|// YAML: ...
end_comment

end_unit

