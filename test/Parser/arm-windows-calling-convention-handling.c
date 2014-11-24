begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fms-compatibility -fsyntax-only -verify %s
end_comment

begin_function
name|int
name|__cdecl
name|cdecl
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|d
parameter_list|)
block|{
comment|// expected-warning {{calling convention '__cdecl' ignored for this target}}
return|return
name|a
operator|+
name|b
operator|+
name|c
operator|+
name|d
return|;
block|}
end_function

begin_function
name|float
name|__stdcall
name|stdcall
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|,
name|float
name|c
parameter_list|,
name|float
name|d
parameter_list|)
block|{
comment|// expected-warning {{calling convention '__stdcall' ignored for this target}}
return|return
name|a
operator|+
name|b
operator|+
name|c
operator|+
name|d
return|;
block|}
end_function

end_unit

