begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_esan_frag -O0 %s -o %t 2>&1
end_comment

begin_comment
comment|// RUN: %env_esan_opts=verbosity=3 %run %t 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|char
name|Buf
index|[
literal|2048
index|]
decl_stmt|;
specifier|const
name|char
name|Str
index|[]
init|=
literal|"TestStringOfParticularLength"
decl_stmt|;
comment|// 29 chars.
name|strcpy
argument_list|(
name|Buf
argument_list|,
name|Str
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|Buf
argument_list|,
name|Str
argument_list|,
literal|17
argument_list|)
expr_stmt|;
return|return
name|strncmp
argument_list|(
name|Buf
argument_list|,
name|Str
argument_list|,
literal|17
argument_list|)
return|;
comment|// CHECK:      in esan::initializeLibrary
comment|// CHECK:      in esan::processRangeAccess {{.*}} 29
comment|// CHECK:      in esan::processRangeAccess {{.*}} 29
comment|// CHECK:      in esan::processRangeAccess {{.*}} 17
comment|// CHECK:      in esan::processRangeAccess {{.*}} 17
comment|// CHECK:      in esan::processRangeAccess {{.*}} 17
comment|// CHECK:      in esan::processRangeAccess {{.*}} 17
comment|// CHECK:      in esan::finalizeLibrary
block|}
end_function

end_unit

