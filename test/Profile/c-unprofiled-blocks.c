begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Blocks that we have no profile data for (ie, it was never reached in training
end_comment

begin_comment
comment|// runs) shouldn't have any branch weight metadata added.
end_comment

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/c-unprofiled-blocks.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name c-unprofiled-blocks.c %s -o - -emit-llvm -fprofile-instr-use=%t.profdata | FileCheck -check-prefix=PGOUSE %s
end_comment

begin_comment
comment|// PGOUSE-LABEL: @never_called(i32 %i)
end_comment

begin_function
name|int
name|never_called
parameter_list|(
name|int
name|i
parameter_list|)
block|{
comment|// PGOUSE: br i1 %{{[^,]*}}, label %{{[^,]*}}, label %{{[^,]*}}{{$}}
if|if
condition|(
name|i
condition|)
block|{}
comment|// PGOUSE: br i1 %{{[^,]*}}, label %{{[^,]*}}, label %{{[^,]*}}{{$}}
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
comment|// PGOUSE: br i1 %{{[^,]*}}, label %{{[^,]*}}, label %{{[^,]*}}{{$}}
while|while
condition|(
operator|--
name|i
condition|)
block|{}
comment|// PGOUSE: br i1 %{{[^,]*}}, label %{{[^,]*}}, label %{{[^,]*}}{{$}}
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
comment|// PGOUSE: switch {{.*}} [
comment|// PGOUSE-NEXT: i32 12
comment|// PGOUSE-NEXT: i32 82
comment|// PGOUSE-NEXT: ]{{$}}
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|12
case|:
return|return
literal|3
return|;
case|case
literal|82
case|:
return|return
literal|0
return|;
default|default:
return|return
literal|89
return|;
block|}
block|}
end_function

begin_comment
comment|// PGOUSE-LABEL: @dead_code(i32 %i)
end_comment

begin_function
name|int
name|dead_code
parameter_list|(
name|int
name|i
parameter_list|)
block|{
comment|// PGOUSE: br {{.*}}, !prof !{{[0-9]+}}
if|if
condition|(
name|i
condition|)
block|{
comment|// This branch is never reached.
comment|// PGOUSE: br i1 %{{[^,]*}}, label %{{[^,]*}}, label %{{[^,]*}}{{$}}
if|if
condition|(
operator|!
name|i
condition|)
block|{}
comment|// PGOUSE: br i1 %{{[^,]*}}, label %{{[^,]*}}, label %{{[^,]*}}{{$}}
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
block|{     }
comment|// PGOUSE: br i1 %{{[^,]*}}, label %{{[^,]*}}, label %{{[^,]*}}{{$}}
while|while
condition|(
operator|--
name|i
condition|)
block|{}
comment|// PGOUSE: br i1 %{{[^,]*}}, label %{{[^,]*}}, label %{{[^,]*}}{{$}}
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
comment|// PGOUSE: switch {{.*}} [
comment|// PGOUSE-NEXT: i32 12
comment|// PGOUSE-NEXT: i32 82
comment|// PGOUSE-NEXT: ]{{$}}
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|12
case|:
return|return
literal|3
return|;
case|case
literal|82
case|:
return|return
literal|0
return|;
default|default:
return|return
literal|89
return|;
block|}
block|}
return|return
literal|2
return|;
block|}
end_function

begin_comment
comment|// PGOUSE-LABEL: @main(i32 %argc, i8** %argv)
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
name|dead_code
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

