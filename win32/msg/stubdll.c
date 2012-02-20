begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|WIN32_LEAN_AND_MEAN
end_define

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_function
name|BOOL
name|WINAPI
name|DllEntryPoint
parameter_list|(
name|HINSTANCE
name|hdll
parameter_list|,
name|DWORD
name|dwreason
parameter_list|,
name|LPVOID
name|ignore
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

end_unit

