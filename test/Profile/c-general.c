begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test instrumentation of general constructs in C.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name c-general.c %s -o - -emit-llvm -fprofile-instr-generate | FileCheck -check-prefix=PGOGEN %s
end_comment

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/c-general.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name c-general.c %s -o - -emit-llvm -fprofile-instr-use=%t.profdata | FileCheck -check-prefix=PGOUSE %s
end_comment

begin_comment
comment|// PGOGEN: @[[SLC:__llvm_profile_counters_simple_loops]] = hidden global [4 x i64] zeroinitializer
end_comment

begin_comment
comment|// PGOGEN: @[[IFC:__llvm_profile_counters_conditionals]] = hidden global [11 x i64] zeroinitializer
end_comment

begin_comment
comment|// PGOGEN: @[[EEC:__llvm_profile_counters_early_exits]] = hidden global [9 x i64] zeroinitializer
end_comment

begin_comment
comment|// PGOGEN: @[[JMC:__llvm_profile_counters_jumps]] = hidden global [22 x i64] zeroinitializer
end_comment

begin_comment
comment|// PGOGEN: @[[SWC:__llvm_profile_counters_switches]] = hidden global [19 x i64] zeroinitializer
end_comment

begin_comment
comment|// PGOGEN: @[[BSC:__llvm_profile_counters_big_switch]] = hidden global [17 x i64] zeroinitializer
end_comment

begin_comment
comment|// PGOGEN: @[[BOC:__llvm_profile_counters_boolean_operators]] = hidden global [8 x i64] zeroinitializer
end_comment

begin_comment
comment|// PGOGEN: @[[BLC:__llvm_profile_counters_boolop_loops]] = hidden global [9 x i64] zeroinitializer
end_comment

begin_comment
comment|// PGOGEN: @[[COC:__llvm_profile_counters_conditional_operator]] = hidden global [3 x i64] zeroinitializer
end_comment

begin_comment
comment|// PGOGEN: @[[MAC:__llvm_profile_counters_main]] = hidden global [1 x i64] zeroinitializer
end_comment

begin_comment
comment|// PGOGEN: @[[STC:__llvm_profile_counters_static_func]] = internal global [2 x i64] zeroinitializer
end_comment

begin_comment
comment|// PGOGEN-LABEL: @simple_loops()
end_comment

begin_comment
comment|// PGOUSE-LABEL: @simple_loops()
end_comment

begin_comment
comment|// PGOGEN: store {{.*}} @[[SLC]], i64 0, i64 0
end_comment

begin_function
name|void
name|simple_loops
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
comment|// PGOGEN: store {{.*}} @[[SLC]], i64 0, i64 1
comment|// PGOUSE: br {{.*}} !prof ![[SL1:[0-9]+]]
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|100
condition|;
operator|++
name|i
control|)
block|{   }
comment|// PGOGEN: store {{.*}} @[[SLC]], i64 0, i64 2
comment|// PGOUSE: br {{.*}} !prof ![[SL2:[0-9]+]]
while|while
condition|(
name|i
operator|>
literal|0
condition|)
name|i
operator|--
expr_stmt|;
comment|// PGOGEN: store {{.*}} @[[SLC]], i64 0, i64 3
comment|// PGOUSE: br {{.*}} !prof ![[SL3:[0-9]+]]
do|do
block|{}
do|while
condition|(
name|i
operator|++
operator|<
literal|75
condition|)
do|;
comment|// PGOGEN-NOT: store {{.*}} @[[SLC]],
comment|// PGOUSE-NOT: br {{.*}} !prof ![0-9]+
block|}
end_function

begin_comment
comment|// PGOGEN-LABEL: @conditionals()
end_comment

begin_comment
comment|// PGOUSE-LABEL: @conditionals()
end_comment

begin_comment
comment|// PGOGEN: store {{.*}} @[[IFC]], i64 0, i64 0
end_comment

begin_function
name|void
name|conditionals
parameter_list|()
block|{
comment|// PGOGEN: store {{.*}} @[[IFC]], i64 0, i64 1
comment|// PGOUSE: br {{.*}} !prof ![[IF1:[0-9]+]]
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|100
condition|;
operator|++
name|i
control|)
block|{
comment|// PGOGEN: store {{.*}} @[[IFC]], i64 0, i64 2
comment|// PGOUSE: br {{.*}} !prof ![[IF2:[0-9]+]]
if|if
condition|(
name|i
operator|%
literal|2
condition|)
block|{
comment|// PGOGEN: store {{.*}} @[[IFC]], i64 0, i64 3
comment|// PGOUSE: br {{.*}} !prof ![[IF3:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
comment|// PGOGEN: store {{.*}} @[[IFC]], i64 0, i64 4
comment|// PGOUSE: br {{.*}} !prof ![[IF4:[0-9]+]]
block|}
elseif|else
if|if
condition|(
name|i
operator|%
literal|3
condition|)
block|{
comment|// PGOGEN: store {{.*}} @[[IFC]], i64 0, i64 5
comment|// PGOUSE: br {{.*}} !prof ![[IF5:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
block|}
else|else
block|{
comment|// PGOGEN: store {{.*}} @[[IFC]], i64 0, i64 6
comment|// PGOUSE: br {{.*}} !prof ![[IF6:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
block|}
comment|// PGOGEN: store {{.*}} @[[IFC]], i64 0, i64 8
comment|// PGOGEN: store {{.*}} @[[IFC]], i64 0, i64 7
comment|// PGOUSE: br {{.*}} !prof ![[IF7:[0-9]+]]
if|if
condition|(
literal|1
operator|&&
name|i
condition|)
block|{}
comment|// PGOGEN: store {{.*}} @[[IFC]], i64 0, i64 10
comment|// PGOGEN: store {{.*}} @[[IFC]], i64 0, i64 9
comment|// PGOUSE: br {{.*}} !prof ![[IF8:[0-9]+]]
if|if
condition|(
literal|0
operator|||
name|i
condition|)
block|{}
block|}
comment|// PGOGEN-NOT: store {{.*}} @[[IFC]],
comment|// PGOUSE-NOT: br {{.*}} !prof ![0-9]+
block|}
end_function

begin_comment
comment|// PGOGEN-LABEL: @early_exits()
end_comment

begin_comment
comment|// PGOUSE-LABEL: @early_exits()
end_comment

begin_comment
comment|// PGOGEN: store {{.*}} @[[EEC]], i64 0, i64 0
end_comment

begin_function
name|void
name|early_exits
parameter_list|()
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
comment|// PGOGEN: store {{.*}} @[[EEC]], i64 0, i64 1
comment|// PGOUSE: br {{.*}} !prof ![[EE1:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
comment|// PGOGEN: store {{.*}} @[[EEC]], i64 0, i64 2
comment|// PGOUSE: br {{.*}} !prof ![[EE2:[0-9]+]]
while|while
condition|(
name|i
operator|<
literal|100
condition|)
block|{
name|i
operator|++
expr_stmt|;
comment|// PGOGEN: store {{.*}} @[[EEC]], i64 0, i64 3
comment|// PGOUSE: br {{.*}} !prof ![[EE3:[0-9]+]]
if|if
condition|(
name|i
operator|>
literal|50
condition|)
break|break;
comment|// PGOGEN: store {{.*}} @[[EEC]], i64 0, i64 4
comment|// PGOUSE: br {{.*}} !prof ![[EE4:[0-9]+]]
if|if
condition|(
name|i
operator|%
literal|2
condition|)
continue|continue;
block|}
comment|// PGOGEN: store {{.*}} @[[EEC]], i64 0, i64 5
comment|// PGOUSE: br {{.*}} !prof ![[EE5:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
comment|// PGOGEN: store {{.*}} @[[EEC]], i64 0, i64 6
do|do
block|{
comment|// PGOGEN: store {{.*}} @[[EEC]], i64 0, i64 7
comment|// PGOUSE: br {{.*}} !prof ![[EE6:[0-9]+]]
if|if
condition|(
name|i
operator|>
literal|75
condition|)
return|return;
else|else
name|i
operator|++
expr_stmt|;
comment|// PGOUSE: br {{.*}} !prof ![[EE7:[0-9]+]]
block|}
do|while
condition|(
name|i
operator|<
literal|100
condition|)
do|;
comment|// PGOGEN: store {{.*}} @[[EEC]], i64 0, i64 8
comment|// Never reached -> no weights
if|if
condition|(
name|i
condition|)
block|{}
comment|// PGOGEN-NOT: store {{.*}} @[[EEC]],
comment|// PGOUSE-NOT: br {{.*}} !prof ![0-9]+
block|}
end_function

begin_comment
comment|// PGOGEN-LABEL: @jumps()
end_comment

begin_comment
comment|// PGOUSE-LABEL: @jumps()
end_comment

begin_comment
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 0
end_comment

begin_function
name|void
name|jumps
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 1
comment|// PGOUSE: br {{.*}} !prof ![[JM1:[0-9]+]]
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|2
condition|;
operator|++
name|i
control|)
block|{
goto|goto
name|outofloop
goto|;
comment|// Never reached -> no weights
if|if
condition|(
name|i
condition|)
block|{}
block|}
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 3
name|outofloop
label|:
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 4
comment|// PGOUSE: br {{.*}} !prof ![[JM2:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
goto|goto
name|loop1
goto|;
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 5
comment|// PGOUSE: br {{.*}} !prof ![[JM3:[0-9]+]]
while|while
condition|(
name|i
condition|)
block|{
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 6
name|loop1
label|:
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 7
comment|// PGOUSE: br {{.*}} !prof ![[JM4:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
block|}
goto|goto
name|loop2
goto|;
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 8
name|first
label|:
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 9
name|second
label|:
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 10
name|third
label|:
name|i
operator|++
expr_stmt|;
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 11
comment|// PGOUSE: br {{.*}} !prof ![[JM5:[0-9]+]]
if|if
condition|(
name|i
operator|<
literal|3
condition|)
goto|goto
name|loop2
goto|;
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 12
comment|// PGOUSE: br {{.*}} !prof ![[JM6:[0-9]+]]
while|while
condition|(
name|i
operator|<
literal|3
condition|)
block|{
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 13
name|loop2
label|:
comment|// PGOUSE: switch {{.*}} [
comment|// PGOUSE: ], !prof ![[JM7:[0-9]+]]
switch|switch
condition|(
name|i
condition|)
block|{
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 15
case|case
literal|0
case|:
goto|goto
name|first
goto|;
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 16
case|case
literal|1
case|:
goto|goto
name|second
goto|;
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 17
case|case
literal|2
case|:
goto|goto
name|third
goto|;
block|}
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 14
block|}
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 18
comment|// PGOUSE: br {{.*}} !prof ![[JM8:[0-9]+]]
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
operator|++
name|i
control|)
block|{
goto|goto
name|withinloop
goto|;
comment|// never reached -> no weights
if|if
condition|(
name|i
condition|)
block|{}
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 20
name|withinloop
label|:
comment|// PGOGEN: store {{.*}} @[[JMC]], i64 0, i64 21
comment|// PGOUSE: br {{.*}} !prof ![[JM9:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
block|}
comment|// PGOGEN-NOT: store {{.*}} @[[JMC]],
comment|// PGOUSE-NOT: br {{.*}} !prof ![0-9]+
block|}
end_function

begin_comment
comment|// PGOGEN-LABEL: @switches()
end_comment

begin_comment
comment|// PGOUSE-LABEL: @switches()
end_comment

begin_comment
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 0
end_comment

begin_function
name|void
name|switches
parameter_list|()
block|{
specifier|static
name|int
name|weights
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|2
block|,
literal|3
block|,
literal|3
block|,
literal|3
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|}
decl_stmt|;
comment|// No cases -> no weights
switch|switch
condition|(
name|weights
index|[
literal|0
index|]
condition|)
block|{
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 2
default|default:
break|break;
block|}
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 1
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 3
comment|// PGOUSE: br {{.*}} !prof ![[SW1:[0-9]+]]
for|for
control|(
name|int
name|i
init|=
literal|0
init|,
name|len
init|=
sizeof|sizeof
argument_list|(
name|weights
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|weights
index|[
literal|0
index|]
argument_list|)
init|;
name|i
operator|<
name|len
condition|;
operator|++
name|i
control|)
block|{
comment|// PGOUSE: switch {{.*}} [
comment|// PGOUSE: ], !prof ![[SW2:[0-9]+]]
switch|switch
condition|(
name|i
index|[
name|weights
index|]
condition|)
block|{
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 5
case|case
literal|1
case|:
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 6
comment|// PGOUSE: br {{.*}} !prof ![[SW3:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
comment|// fallthrough
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 7
case|case
literal|2
case|:
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 8
comment|// PGOUSE: br {{.*}} !prof ![[SW4:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
break|break;
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 9
case|case
literal|3
case|:
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 10
comment|// PGOUSE: br {{.*}} !prof ![[SW5:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
continue|continue;
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 11
case|case
literal|4
case|:
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 12
comment|// PGOUSE: br {{.*}} !prof ![[SW6:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
comment|// PGOUSE: switch {{.*}} [
comment|// PGOUSE: ], !prof ![[SW7:[0-9]+]]
switch|switch
condition|(
name|i
condition|)
block|{
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 14
case|case
literal|6
operator|...
literal|9
case|:
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 15
comment|// PGOUSE: br {{.*}} !prof ![[SW8:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
continue|continue;
block|}
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 13
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 16
default|default:
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 17
comment|// PGOUSE: br {{.*}} !prof ![[SW9:[0-9]+]]
if|if
condition|(
name|i
operator|==
name|len
operator|-
literal|1
condition|)
return|return;
block|}
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 4
block|}
comment|// PGOGEN: store {{.*}} @[[SWC]], i64 0, i64 18
comment|// Never reached -> no weights
if|if
condition|(
name|weights
index|[
literal|0
index|]
condition|)
block|{}
comment|// PGOGEN-NOT: store {{.*}} @[[SWC]],
comment|// PGOUSE-NOT: br {{.*}} !prof ![0-9]+
block|}
end_function

begin_comment
comment|// PGOGEN-LABEL: @big_switch()
end_comment

begin_comment
comment|// PGOUSE-LABEL: @big_switch()
end_comment

begin_comment
comment|// PGOGEN: store {{.*}} @[[BSC]], i64 0, i64 0
end_comment

begin_function
name|void
name|big_switch
parameter_list|()
block|{
comment|// PGOGEN: store {{.*}} @[[BSC]], i64 0, i64 1
comment|// PGOUSE: br {{.*}} !prof ![[BS1:[0-9]+]]
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|32
condition|;
operator|++
name|i
control|)
block|{
comment|// PGOUSE: switch {{.*}} [
comment|// PGOUSE: ], !prof ![[BS2:[0-9]+]]
switch|switch
condition|(
literal|1
operator|<<
name|i
condition|)
block|{
comment|// PGOGEN: store {{.*}} @[[BSC]], i64 0, i64 3
case|case
operator|(
literal|1
operator|<<
literal|0
operator|)
case|:
comment|// PGOGEN: store {{.*}} @[[BSC]], i64 0, i64 4
comment|// PGOUSE: br {{.*}} !prof ![[BS3:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
comment|// fallthrough
comment|// PGOGEN: store {{.*}} @[[BSC]], i64 0, i64 5
case|case
operator|(
literal|1
operator|<<
literal|1
operator|)
case|:
comment|// PGOGEN: store {{.*}} @[[BSC]], i64 0, i64 6
comment|// PGOUSE: br {{.*}} !prof ![[BS4:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
break|break;
comment|// PGOGEN: store {{.*}} @[[BSC]], i64 0, i64 7
case|case
operator|(
literal|1
operator|<<
literal|2
operator|)
operator|...
operator|(
literal|1
operator|<<
literal|12
operator|)
case|:
comment|// PGOGEN: store {{.*}} @[[BSC]], i64 0, i64 8
comment|// PGOUSE: br {{.*}} !prof ![[BS5:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
break|break;
comment|// The branch for the large case range above appears after the case body
comment|// PGOUSE: br {{.*}} !prof ![[BS6:[0-9]+]]
comment|// PGOGEN: store {{.*}} @[[BSC]], i64 0, i64 9
case|case
operator|(
literal|1
operator|<<
literal|13
operator|)
case|:
comment|// PGOGEN: store {{.*}} @[[BSC]], i64 0, i64 10
comment|// PGOUSE: br {{.*}} !prof ![[BS7:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
break|break;
comment|// PGOGEN: store {{.*}} @[[BSC]], i64 0, i64 11
case|case
operator|(
literal|1
operator|<<
literal|14
operator|)
operator|...
operator|(
literal|1
operator|<<
literal|28
operator|)
case|:
comment|// PGOGEN: store {{.*}} @[[BSC]], i64 0, i64 12
comment|// PGOUSE: br {{.*}} !prof ![[BS8:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
break|break;
comment|// The branch for the large case range above appears after the case body
comment|// PGOUSE: br {{.*}} !prof ![[BS9:[0-9]+]]
comment|// PGOGEN: store {{.*}} @[[BSC]], i64 0, i64 13
case|case
operator|(
literal|1
operator|<<
literal|29
operator|)
operator|...
operator|(
operator|(
literal|1
operator|<<
literal|29
operator|)
operator|+
literal|1
operator|)
case|:
comment|// PGOGEN: store {{.*}} @[[BSC]], i64 0, i64 14
comment|// PGOUSE: br {{.*}} !prof ![[BS10:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
break|break;
comment|// PGOGEN: store {{.*}} @[[BSC]], i64 0, i64 15
default|default:
comment|// PGOGEN: store {{.*}} @[[BSC]], i64 0, i64 16
comment|// PGOUSE: br {{.*}} !prof ![[BS11:[0-9]+]]
if|if
condition|(
name|i
condition|)
block|{}
break|break;
block|}
comment|// PGOGEN: store {{.*}} @[[BSC]], i64 0, i64 2
block|}
comment|// PGOGEN-NOT: store {{.*}} @[[BSC]],
comment|// PGOUSE-NOT: br {{.*}} !prof ![0-9]+
comment|// PGOUSE: ret void
block|}
end_function

begin_comment
comment|// PGOGEN-LABEL: @boolean_operators()
end_comment

begin_comment
comment|// PGOUSE-LABEL: @boolean_operators()
end_comment

begin_comment
comment|// PGOGEN: store {{.*}} @[[BOC]], i64 0, i64 0
end_comment

begin_function
name|void
name|boolean_operators
parameter_list|()
block|{
name|int
name|v
decl_stmt|;
comment|// PGOGEN: store {{.*}} @[[BOC]], i64 0, i64 1
comment|// PGOUSE: br {{.*}} !prof ![[BO1:[0-9]+]]
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|100
condition|;
operator|++
name|i
control|)
block|{
comment|// PGOGEN: store {{.*}} @[[BOC]], i64 0, i64 2
comment|// PGOUSE: br {{.*}} !prof ![[BO2:[0-9]+]]
name|v
operator|=
name|i
operator|%
literal|3
operator|||
name|i
expr_stmt|;
comment|// PGOGEN: store {{.*}} @[[BOC]], i64 0, i64 3
comment|// PGOUSE: br {{.*}} !prof ![[BO3:[0-9]+]]
name|v
operator|=
name|i
operator|%
literal|3
operator|&&
name|i
expr_stmt|;
comment|// PGOGEN: store {{.*}} @[[BOC]], i64 0, i64 5
comment|// PGOGEN: store {{.*}} @[[BOC]], i64 0, i64 4
comment|// PGOUSE: br {{.*}} !prof ![[BO4:[0-9]+]]
comment|// PGOUSE: br {{.*}} !prof ![[BO5:[0-9]+]]
name|v
operator|=
name|i
operator|%
literal|3
operator|||
name|i
operator|%
literal|2
operator|||
name|i
expr_stmt|;
comment|// PGOGEN: store {{.*}} @[[BOC]], i64 0, i64 7
comment|// PGOGEN: store {{.*}} @[[BOC]], i64 0, i64 6
comment|// PGOUSE: br {{.*}} !prof ![[BO6:[0-9]+]]
comment|// PGOUSE: br {{.*}} !prof ![[BO7:[0-9]+]]
name|v
operator|=
name|i
operator|%
literal|2
operator|&&
name|i
operator|%
literal|3
operator|&&
name|i
expr_stmt|;
block|}
comment|// PGOGEN-NOT: store {{.*}} @[[BOC]],
comment|// PGOUSE-NOT: br {{.*}} !prof ![0-9]+
block|}
end_function

begin_comment
comment|// PGOGEN-LABEL: @boolop_loops()
end_comment

begin_comment
comment|// PGOUSE-LABEL: @boolop_loops()
end_comment

begin_comment
comment|// PGOGEN: store {{.*}} @[[BLC]], i64 0, i64 0
end_comment

begin_function
name|void
name|boolop_loops
parameter_list|()
block|{
name|int
name|i
init|=
literal|100
decl_stmt|;
comment|// PGOGEN: store {{.*}} @[[BLC]], i64 0, i64 2
comment|// PGOGEN: store {{.*}} @[[BLC]], i64 0, i64 1
comment|// PGOUSE: br {{.*}} !prof ![[BL1:[0-9]+]]
comment|// PGOUSE: br {{.*}} !prof ![[BL2:[0-9]+]]
while|while
condition|(
name|i
operator|&&
name|i
operator|>
literal|50
condition|)
name|i
operator|--
expr_stmt|;
comment|// PGOGEN: store {{.*}} @[[BLC]], i64 0, i64 4
comment|// PGOGEN: store {{.*}} @[[BLC]], i64 0, i64 3
comment|// PGOUSE: br {{.*}} !prof ![[BL3:[0-9]+]]
comment|// PGOUSE: br {{.*}} !prof ![[BL4:[0-9]+]]
while|while
condition|(
operator|(
name|i
operator|%
literal|2
operator|)
operator|||
operator|(
name|i
operator|>
literal|0
operator|)
condition|)
name|i
operator|--
expr_stmt|;
comment|// PGOGEN: store {{.*}} @[[BLC]], i64 0, i64 6
comment|// PGOGEN: store {{.*}} @[[BLC]], i64 0, i64 5
comment|// PGOUSE: br {{.*}} !prof ![[BL5:[0-9]+]]
comment|// PGOUSE: br {{.*}} !prof ![[BL6:[0-9]+]]
for|for
control|(
name|i
operator|=
literal|100
init|;
name|i
operator|&&
name|i
operator|>
literal|50
condition|;
operator|--
name|i
control|)
empty_stmt|;
comment|// PGOGEN: store {{.*}} @[[BLC]], i64 0, i64 8
comment|// PGOGEN: store {{.*}} @[[BLC]], i64 0, i64 7
comment|// PGOUSE: br {{.*}} !prof ![[BL7:[0-9]+]]
comment|// PGOUSE: br {{.*}} !prof ![[BL8:[0-9]+]]
for|for
control|(
init|;
operator|(
name|i
operator|%
literal|2
operator|)
operator|||
operator|(
name|i
operator|>
literal|0
operator|)
condition|;
operator|--
name|i
control|)
empty_stmt|;
comment|// PGOGEN-NOT: store {{.*}} @[[BLC]],
comment|// PGOUSE-NOT: br {{.*}} !prof ![0-9]+
block|}
end_function

begin_comment
comment|// PGOGEN-LABEL: @conditional_operator()
end_comment

begin_comment
comment|// PGOUSE-LABEL: @conditional_operator()
end_comment

begin_comment
comment|// PGOGEN: store {{.*}} @[[COC]], i64 0, i64 0
end_comment

begin_function
name|void
name|conditional_operator
parameter_list|()
block|{
name|int
name|i
init|=
literal|100
decl_stmt|;
comment|// PGOGEN: store {{.*}} @[[COC]], i64 0, i64 1
comment|// PGOUSE: br {{.*}} !prof ![[CO1:[0-9]+]]
name|int
name|j
init|=
name|i
operator|<
literal|50
condition|?
name|i
else|:
literal|1
decl_stmt|;
comment|// PGOGEN: store {{.*}} @[[COC]], i64 0, i64 2
comment|// PGOUSE: br {{.*}} !prof ![[CO2:[0-9]+]]
name|int
name|k
init|=
name|i
condition|?
else|:
literal|0
decl_stmt|;
comment|// PGOGEN-NOT: store {{.*}} @[[COC]],
comment|// PGOUSE-NOT: br {{.*}} !prof ![0-9]+
block|}
end_function

begin_function
name|void
name|do_fallthrough
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
operator|++
name|i
control|)
block|{
name|int
name|j
init|=
literal|0
decl_stmt|;
do|do
block|{
comment|// The number of exits out of this do-loop via the break statement
comment|// exceeds the counter value for the loop (which does not include the
comment|// fallthrough count). Make sure that does not violate any assertions.
if|if
condition|(
name|i
operator|<
literal|8
condition|)
break|break;
name|j
operator|++
expr_stmt|;
block|}
do|while
condition|(
name|j
operator|<
literal|2
condition|)
do|;
block|}
block|}
end_function

begin_comment
comment|// PGOGEN-LABEL: @static_func()
end_comment

begin_comment
comment|// PGOUSE-LABEL: @static_func()
end_comment

begin_comment
comment|// PGOGEN: store {{.*}} @[[STC]], i64 0, i64 0
end_comment

begin_function
specifier|static
name|void
name|static_func
parameter_list|()
block|{
comment|// PGOGEN: store {{.*}} @[[STC]], i64 0, i64 1
comment|// PGOUSE: br {{.*}} !prof ![[ST1:[0-9]+]]
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
operator|++
name|i
control|)
block|{   }
block|}
end_function

begin_comment
comment|// PGOUSE-DAG: ![[SL1]] = metadata !{metadata !"branch_weights", i32 101, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[SL2]] = metadata !{metadata !"branch_weights", i32 101, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[SL3]] = metadata !{metadata !"branch_weights", i32 76, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[EE1]] = metadata !{metadata !"branch_weights", i32 1, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[EE2]] = metadata !{metadata !"branch_weights", i32 52, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[EE3]] = metadata !{metadata !"branch_weights", i32 2, i32 51}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[EE4]] = metadata !{metadata !"branch_weights", i32 26, i32 26}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[EE5]] = metadata !{metadata !"branch_weights", i32 2, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[EE6]] = metadata !{metadata !"branch_weights", i32 2, i32 26}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[EE7]] = metadata !{metadata !"branch_weights", i32 26, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[IF1]] = metadata !{metadata !"branch_weights", i32 101, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[IF2]] = metadata !{metadata !"branch_weights", i32 51, i32 51}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[IF3]] = metadata !{metadata !"branch_weights", i32 51, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[IF4]] = metadata !{metadata !"branch_weights", i32 34, i32 18}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[IF5]] = metadata !{metadata !"branch_weights", i32 34, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[IF6]] = metadata !{metadata !"branch_weights", i32 17, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[IF7]] = metadata !{metadata !"branch_weights", i32 100, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[IF8]] = metadata !{metadata !"branch_weights", i32 100, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[JM1]] = metadata !{metadata !"branch_weights", i32 2, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[JM2]] = metadata !{metadata !"branch_weights", i32 1, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[JM3]] = metadata !{metadata !"branch_weights", i32 1, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[JM4]] = metadata !{metadata !"branch_weights", i32 1, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[JM5]] = metadata !{metadata !"branch_weights", i32 3, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[JM6]] = metadata !{metadata !"branch_weights", i32 1, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[JM7]] = metadata !{metadata !"branch_weights", i32 1, i32 2, i32 2, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[JM8]] = metadata !{metadata !"branch_weights", i32 11, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[JM9]] = metadata !{metadata !"branch_weights", i32 10, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[SW1]] = metadata !{metadata !"branch_weights", i32 16, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[SW2]] = metadata !{metadata !"branch_weights", i32 6, i32 2, i32 3, i32 4, i32 5}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[SW3]] = metadata !{metadata !"branch_weights", i32 1, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[SW4]] = metadata !{metadata !"branch_weights", i32 3, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[SW5]] = metadata !{metadata !"branch_weights", i32 4, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[SW6]] = metadata !{metadata !"branch_weights", i32 5, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[SW7]] = metadata !{metadata !"branch_weights", i32 1, i32 2, i32 2, i32 2, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[SW8]] = metadata !{metadata !"branch_weights", i32 5, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[SW9]] = metadata !{metadata !"branch_weights", i32 2, i32 5}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BS1]] = metadata !{metadata !"branch_weights", i32 33, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BS2]] = metadata !{metadata !"branch_weights", i32 29, i32 2, i32 2, i32 2, i32 2, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BS3]] = metadata !{metadata !"branch_weights", i32 1, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BS4]] = metadata !{metadata !"branch_weights", i32 2, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BS5]] = metadata !{metadata !"branch_weights", i32 12, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BS6]] = metadata !{metadata !"branch_weights", i32 12, i32 3}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BS7]] = metadata !{metadata !"branch_weights", i32 2, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BS8]] = metadata !{metadata !"branch_weights", i32 16, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BS9]] = metadata !{metadata !"branch_weights", i32 16, i32 14}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BS10]] = metadata !{metadata !"branch_weights", i32 2, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BS11]] = metadata !{metadata !"branch_weights", i32 3, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BO1]] = metadata !{metadata !"branch_weights", i32 101, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BO2]] = metadata !{metadata !"branch_weights", i32 67, i32 35}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BO3]] = metadata !{metadata !"branch_weights", i32 67, i32 35}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BO4]] = metadata !{metadata !"branch_weights", i32 67, i32 35}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BO5]] = metadata !{metadata !"branch_weights", i32 18, i32 18}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BO6]] = metadata !{metadata !"branch_weights", i32 51, i32 51}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BO7]] = metadata !{metadata !"branch_weights", i32 34, i32 18}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BL1]] = metadata !{metadata !"branch_weights", i32 52, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BL2]] = metadata !{metadata !"branch_weights", i32 51, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BL3]] = metadata !{metadata !"branch_weights", i32 26, i32 27}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BL4]] = metadata !{metadata !"branch_weights", i32 51, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BL5]] = metadata !{metadata !"branch_weights", i32 52, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BL6]] = metadata !{metadata !"branch_weights", i32 51, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BL7]] = metadata !{metadata !"branch_weights", i32 26, i32 27}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[BL8]] = metadata !{metadata !"branch_weights", i32 51, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[CO1]] = metadata !{metadata !"branch_weights", i32 1, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[CO2]] = metadata !{metadata !"branch_weights", i32 2, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[ST1]] = metadata !{metadata !"branch_weights", i32 11, i32 2}
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|simple_loops
argument_list|()
expr_stmt|;
name|conditionals
argument_list|()
expr_stmt|;
name|early_exits
argument_list|()
expr_stmt|;
name|jumps
argument_list|()
expr_stmt|;
name|switches
argument_list|()
expr_stmt|;
name|big_switch
argument_list|()
expr_stmt|;
name|boolean_operators
argument_list|()
expr_stmt|;
name|boolop_loops
argument_list|()
expr_stmt|;
name|conditional_operator
argument_list|()
expr_stmt|;
name|do_fallthrough
argument_list|()
expr_stmt|;
name|static_func
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

