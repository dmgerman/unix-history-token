begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, Stefan Esser<se@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|INLINE
value|inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INLINE
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* System Parameter Block holding ARC and VENDOR function vector addresses */
end_comment

begin_define
define|#
directive|define
name|SPBlock
value|((SPB *)0xffffffff806fe000ul)
end_define

begin_comment
comment|/*  * Convert between 32bit (ARC) and 64bit (Alpha) pointers  */
end_comment

begin_function
specifier|static
name|INLINE
name|void
modifier|*
name|ptr
parameter_list|(
name|arcptr
name|p
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
operator|(
name|int64_t
operator|)
name|p
operator|.
name|adr
return|;
block|}
end_function

begin_function
specifier|static
name|INLINE
name|arcptr
name|toarcptr
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
name|arcptr
name|p32
decl_stmt|;
name|p32
operator|.
name|adr
operator|=
operator|(
name|int32_t
operator|)
operator|(
name|int64_t
operator|)
name|p
expr_stmt|;
return|return
operator|(
name|p32
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Return entry point for ARC BIOS function "funcno"  */
end_comment

begin_function
specifier|static
name|INLINE
name|void
modifier|*
name|get_arc_vector
parameter_list|(
name|int
name|funcno
parameter_list|)
block|{
name|arcptr
argument_list|(
operator|*
name|arc_vector
argument_list|)
index|[]
operator|=
name|ptr
argument_list|(
name|SPBlock
operator|->
name|FirmwareVectorP
argument_list|)
expr_stmt|;
return|return
name|ptr
argument_list|(
operator|(
operator|*
name|arc_vector
operator|)
index|[
name|funcno
operator|-
literal|1
index|]
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Return entry point for VENDOR function "funcno"  */
end_comment

begin_function
specifier|static
name|INLINE
name|void
modifier|*
name|get_vendor_vector
parameter_list|(
name|int
name|funcno
parameter_list|)
block|{
name|arcptr
argument_list|(
operator|*
name|arc_vector
argument_list|)
index|[]
operator|=
name|ptr
argument_list|(
name|SPBlock
operator|->
name|PrivateVectorP
argument_list|)
expr_stmt|;
return|return
name|ptr
argument_list|(
operator|(
operator|*
name|arc_vector
operator|)
index|[
name|funcno
operator|-
literal|1
index|]
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|INLINE
name|int
name|get_vendor_vector_length
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|SPBlock
operator|->
name|PrivateVectorLength
return|;
block|}
end_function

begin_comment
comment|/*  * Macros to create inline wrappers for ARCS BIOS functions  *   * Parameter:  *	num	function number (starting at 1)  *	result	result type  *	fn	function name  *	param	parameter list (types and formal args)  *	args	parameter list (formal args only)  */
end_comment

begin_define
define|#
directive|define
name|ARC_FN
parameter_list|(
name|num
parameter_list|,
name|result
parameter_list|,
name|fn
parameter_list|,
name|param
parameter_list|,
name|args
parameter_list|)
define|\
value|static inline result fn param { \ 	typedef result _fn_t param; \ 	_fn_t *p_ ## fn = get_arc_vector(num); \ 	return p_ ## fn args; \ }
end_define

begin_define
define|#
directive|define
name|VND_FN
parameter_list|(
name|num
parameter_list|,
name|result
parameter_list|,
name|fn
parameter_list|,
name|param
parameter_list|,
name|args
parameter_list|)
define|\
value|static INLINE result fn param { \ 	typedef result _fn_t param; \ 	_fn_t *p_ ## fn = get_vendor_vector(num); \ 	return p_ ## fn args; \ }
end_define

begin_comment
comment|/* function codes as defined in ARC Specification Version 1.2 */
end_comment

begin_macro
name|ARC_FN
argument_list|(
literal|1
argument_list|,
argument|int32_t
argument_list|,
argument|Load
argument_list|,
argument|(char *Path, u_int32_t TopAddr, u_int32_t *ExecAddr, u_int32_t *LowAddr)
argument_list|,
argument|(Path, TopAddr, ExecAddr, LowAddr)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|2
argument_list|,
argument|int32_t
argument_list|,
argument|Invoke
argument_list|,
argument|(u_int32_t ExecAddr, u_int32_t StackAddr, u_int32_t Argc, char *Argv[], char *Envp[])
argument_list|,
argument|(ExecAddr, StackAddr, Argc, Argv, Envp)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|3
argument_list|,
argument|int32_t
argument_list|,
argument|Execute
argument_list|,
argument|(char *Path, u_int32_t Argc, char *Argv[], char *Envp[])
argument_list|,
argument|(Path, Argc, Argv, Envp)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|4
argument_list|,
argument|void
argument_list|,
argument|Halt
argument_list|,
argument|(void)
argument_list|,
argument|()
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|5
argument_list|,
argument|void
argument_list|,
argument|PowerDown
argument_list|,
argument|(void)
argument_list|,
argument|()
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|6
argument_list|,
argument|void
argument_list|,
argument|Restart
argument_list|,
argument|(void)
argument_list|,
argument|()
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|7
argument_list|,
argument|void
argument_list|,
argument|FwReboot
argument_list|,
argument|(void)
argument_list|,
argument|()
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|8
argument_list|,
argument|void
argument_list|,
argument|EnterInteractiveMode
argument_list|,
argument|(void)
argument_list|,
argument|()
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|10
argument_list|,
argument|CONFIGURATION_COMPONENT *
argument_list|,
argument|GetPeer
argument_list|,
argument|(CONFIGURATION_COMPONENT *Current)
argument_list|,
argument|(Current)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|11
argument_list|,
argument|CONFIGURATION_COMPONENT *
argument_list|,
argument|GetChild
argument_list|,
argument|(CONFIGURATION_COMPONENT *Current)
argument_list|,
argument|(Current)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|12
argument_list|,
argument|CONFIGURATION_COMPONENT *
argument_list|,
argument|GetParent
argument_list|,
argument|(CONFIGURATION_COMPONENT *Current)
argument_list|,
argument|(Current)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|13
argument_list|,
argument|CONFIGURATION_COMPONENT *
argument_list|,
argument|AddChild
argument_list|,
argument|(CONFIGURATION_COMPONENT *Current, CONFIGURATION_COMPONENT *Template,  	void *ConfigurationData)
argument_list|,
argument|(Current, Template, ConfigurationData)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|14
argument_list|,
argument|int32_t
argument_list|,
argument|DeleteComponent
argument_list|,
argument|(CONFIGURATION_COMPONENT *ComponentToDelete)
argument_list|,
argument|(ComponentToDelete)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|15
argument_list|,
argument|CONFIGURATION_COMPONENT *
argument_list|,
argument|GetComponent
argument_list|,
argument|(char *Path)
argument_list|,
argument|(Path)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|16
argument_list|,
argument|int32_t
argument_list|,
argument|GetConfigurationData
argument_list|,
argument|(void *ConfigurationData, CONFIGURATION_COMPONENT *Component)
argument_list|,
argument|(ConfigurationData, Component)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|17
argument_list|,
argument|int32_t
argument_list|,
argument|SaveConfiguration
argument_list|,
argument|(void)
argument_list|,
argument|()
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|18
argument_list|,
argument|SYSTEM_ID *
argument_list|,
argument|GetSystemId
argument_list|,
argument|(void)
argument_list|,
argument|()
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|19
argument_list|,
argument|MEMORY_DESCRIPTOR *
argument_list|,
argument|GetMemoryDescriptor
argument_list|,
argument|(MEMORY_DESCRIPTOR *Current)
argument_list|,
argument|(Current)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|21
argument_list|,
argument|TIME_FIELDS *
argument_list|,
argument|GetTime
argument_list|,
argument|(void)
argument_list|,
argument|()
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|22
argument_list|,
argument|u_int32_t
argument_list|,
argument|GetRelativeTime
argument_list|,
argument|(void)
argument_list|,
argument|()
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|23
argument_list|,
argument|int32_t
argument_list|,
argument|GetDirectoryEntry
argument_list|,
argument|(u_int32_t FileId, DIRECTORY_ENTRY *Buffer, u_int32_t Length, u_int32_t *Count)
argument_list|,
argument|(FileId, Buffer, Length, Count)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|24
argument_list|,
argument|int32_t
argument_list|,
argument|Open
argument_list|,
argument|(const char *Path, OPEN_MODE OpenMode, u_int32_t *FileId)
argument_list|,
argument|(Path, OpenMode, FileId)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|25
argument_list|,
argument|int32_t
argument_list|,
argument|Close
argument_list|,
argument|(u_int32_t FileId)
argument_list|,
argument|(FileId)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|26
argument_list|,
argument|int32_t
argument_list|,
argument|Read
argument_list|,
argument|(u_int32_t FileId, void *Buffer,  u_int32_t N, u_int32_t *Count)
argument_list|,
argument|(FileId, Buffer, N, Count)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|27
argument_list|,
argument|int32_t
argument_list|,
argument|GetReadStatus
argument_list|,
argument|(u_int32_t FileId)
argument_list|,
argument|(FileId)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|28
argument_list|,
argument|int32_t
argument_list|,
argument|Write
argument_list|,
argument|(u_int32_t FileId, void const *Buffer, u_int32_t N, u_int32_t *Count)
argument_list|,
argument|(FileId, Buffer, N, Count)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|29
argument_list|,
argument|int32_t
argument_list|,
argument|Seek
argument_list|,
argument|(u_int32_t FileId, fpos_t *Position, SEEK_MODE SeekMode)
argument_list|,
argument|(FileId, Position, SeekMode)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|30
argument_list|,
argument|int32_t
argument_list|,
argument|Mount
argument_list|,
argument|(char *Path, MOUNT_OPERATION Operation)
argument_list|,
argument|(Path, Operation)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|31
argument_list|,
argument|char *
argument_list|,
argument|GetEnvironmentVariable
argument_list|,
argument|(char *Name)
argument_list|,
argument|(Name)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|32
argument_list|,
argument|int32_t
argument_list|,
argument|SetEnvironmentVariable
argument_list|,
argument|(char *Name, char *Value)
argument_list|,
argument|(Name, Value)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|33
argument_list|,
argument|int32_t
argument_list|,
argument|GetFileInformation
argument_list|,
argument|(u_int32_t FileId, FILE_INFORMATION *Information)
argument_list|,
argument|(FileId, Information)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|34
argument_list|,
argument|int32_t
argument_list|,
argument|SetFileInformation
argument_list|,
argument|(u_int32_t FileId, u_int32_t AttributeFlags, u_int32_t AttributeMask)
argument_list|,
argument|(FileId, AttributeFlags, AttributeMask)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|35
argument_list|,
argument|void
argument_list|,
argument|FlushAllCaches
argument_list|,
argument|(void)
argument_list|,
argument|()
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|36
argument_list|,
argument|int32_t
argument_list|,
argument|TestUnicodeCharacter
argument_list|,
argument|(u_int32_t FileId, WCHAR UnicodeCharacter)
argument_list|,
argument|(FileId, UnicodeCharacter)
argument_list|)
end_macro

begin_macro
name|ARC_FN
argument_list|(
literal|37
argument_list|,
argument|ARC_DISPLAY_STATUS *
argument_list|,
argument|GetDisplayStatus
argument_list|,
argument|(u_int32_t FileId)
argument_list|,
argument|(FileId)
argument_list|)
end_macro

begin_comment
comment|/* Vendor specific function codes have not been verified beyond function 4 */
end_comment

begin_macro
name|VND_FN
argument_list|(
literal|1
argument_list|,
argument|void *
argument_list|,
argument|AllocatePool
argument_list|,
argument|(u_int32_t NumberOfBytes)
argument_list|,
argument|(NumberOfBytes)
argument_list|)
end_macro

begin_macro
name|VND_FN
argument_list|(
literal|2
argument_list|,
argument|void
argument_list|,
argument|StallExecution
argument_list|,
argument|(u_int32_t Microseconds)
argument_list|,
argument|(Microseconds)
argument_list|)
end_macro

begin_macro
name|VND_FN
argument_list|(
literal|3
argument_list|,
argument|u_int32_t
argument_list|,
argument|Print
argument_list|,
argument|(char *Format, int32_t Arg1, int32_t Arg2, int32_t Arg3)
argument_list|,
argument|(Format, Arg1, Arg2, Arg3)
argument_list|)
end_macro

begin_macro
name|VND_FN
argument_list|(
literal|4
argument_list|,
argument|void
argument_list|,
argument|ReturnExtendedSystemInformation
argument_list|,
argument|(EXTENDED_SYSTEM_INFORMATION *SystemInfo)
argument_list|,
argument|(SystemInfo)
argument_list|)
end_macro

end_unit

