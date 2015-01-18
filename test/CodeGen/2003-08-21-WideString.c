begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s  -o /dev/null
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
comment|/* Solaris. */
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

begin_struct
struct|struct
block|{
name|wchar_t
modifier|*
name|name
decl_stmt|;
block|}
name|syms
init|=
block|{
literal|L"NUL"
block|}
struct|;
end_struct

end_unit

