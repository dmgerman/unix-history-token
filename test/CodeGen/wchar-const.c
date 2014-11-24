begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -triple i386-pc-win32 | FileCheck %s --check-prefix=CHECK-WIN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -triple x86_64-apple-darwin | FileCheck %s --check-prefix=CHECK-DAR
end_comment

begin_comment
comment|// This should pass for any endianness combination of host and target.
end_comment

begin_comment
comment|// This bit is taken from Sema/wchar.c so we can avoid the wchar.h include.
end_comment

begin_typedef
typedef|typedef
name|__WCHAR_TYPE__
name|wchar_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_IX86
argument_list|)
operator|||
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|_M_X64
argument_list|)
operator|||
name|defined
argument_list|(
name|SHORT_WCHAR
argument_list|)
end_if

begin_define
define|#
directive|define
name|WCHAR_T_TYPE
value|unsigned short
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sun
argument_list|)
operator|||
name|defined
argument_list|(
name|__AuroraUX__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|WCHAR_T_TYPE
value|long
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Solaris or AuroraUX. */
end_comment

begin_define
define|#
directive|define
name|WCHAR_T_TYPE
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-DAR: private unnamed_addr constant [18 x i32] [i32 84,
end_comment

begin_comment
comment|// CHECK-WIN: linkonce_odr unnamed_addr constant [18 x i16] [i16 84,
end_comment

begin_function_decl
specifier|extern
name|void
name|foo
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

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
name|foo
argument_list|(
literal|L"This is some text"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

