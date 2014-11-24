begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -fms-extensions -xc++ -o -< %s | FileCheck %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
pragma|#
directive|pragma
name|const_seg
name|(
literal|".my_const"
name|)
pragma|#
directive|pragma
name|bss_seg
name|(
literal|".my_bss"
name|)
name|int
name|D
init|=
literal|1
decl_stmt|;
pragma|#
directive|pragma
name|data_seg
name|(
literal|".data"
name|)
name|int
name|a
init|=
literal|1
decl_stmt|;
pragma|#
directive|pragma
name|data_seg
name|(
name|push
name|,
name|label
name|,
literal|".data2"
name|)
specifier|extern
specifier|const
name|int
name|b
decl_stmt|;
specifier|const
name|int
name|b
init|=
literal|1
decl_stmt|;
specifier|const
name|char
modifier|*
name|s
init|=
literal|"my string!"
decl_stmt|;
pragma|#
directive|pragma
name|data_seg
name|(
name|push
name|,
literal|".my_seg"
name|)
name|int
name|c
init|=
literal|1
decl_stmt|;
pragma|#
directive|pragma
name|data_seg
name|(
name|pop
name|,
name|label
name|)
name|int
name|d
init|=
literal|1
decl_stmt|;
name|int
name|e
decl_stmt|;
pragma|#
directive|pragma
name|bss_seg
name|(
literal|".c"
name|)
name|int
name|f
decl_stmt|;
name|void
name|g
parameter_list|(
name|void
parameter_list|)
block|{}
pragma|#
directive|pragma
name|code_seg
name|(
literal|".my_code"
name|)
name|void
name|h
parameter_list|(
name|void
parameter_list|)
block|{}
pragma|#
directive|pragma
name|bss_seg
name|(
name|)
name|int
name|i
decl_stmt|;
pragma|#
directive|pragma
name|bss_seg
name|(
literal|".bss1"
name|)
pragma|#
directive|pragma
name|bss_seg
name|(
name|push
name|,
name|test
name|,
literal|".bss2"
name|)
pragma|#
directive|pragma
name|bss_seg
name|(
name|)
pragma|#
directive|pragma
name|bss_seg
name|(
name|)
name|int
name|TEST1
decl_stmt|;
pragma|#
directive|pragma
name|bss_seg
name|(
name|pop
name|)
name|int
name|TEST2
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//CHECK: @D = global i32 1
end_comment

begin_comment
comment|//CHECK: @a = global i32 1, section ".data"
end_comment

begin_comment
comment|//CHECK: @b = constant i32 1, section ".my_const"
end_comment

begin_comment
comment|//CHECK: @[[MYSTR:.*]] = {{.*}} unnamed_addr constant [11 x i8] c"my string!\00"
end_comment

begin_comment
comment|//CHECK: @s = global i8* getelementptr inbounds ([11 x i8]* @[[MYSTR]], i32 0, i32 0), section ".data2"
end_comment

begin_comment
comment|//CHECK: @c = global i32 1, section ".my_seg"
end_comment

begin_comment
comment|//CHECK: @d = global i32 1, section ".data"
end_comment

begin_comment
comment|//CHECK: @e = global i32 0, section ".my_bss"
end_comment

begin_comment
comment|//CHECK: @f = global i32 0, section ".c"
end_comment

begin_comment
comment|//CHECK: @i = global i32 0
end_comment

begin_comment
comment|//CHECK: @TEST1 = global i32 0
end_comment

begin_comment
comment|//CHECK: @TEST2 = global i32 0, section ".bss1"
end_comment

begin_comment
comment|//CHECK: define void @g()
end_comment

begin_comment
comment|//CHECK: define void @h() {{.*}} section ".my_code"
end_comment

end_unit

