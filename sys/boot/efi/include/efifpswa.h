begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_FPSWA_H
end_ifndef

begin_define
define|#
directive|define
name|_EFI_FPSWA_H
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI FP SWA Driver (Floating Point Software Assist)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_INTEL_FPSWA
define|\
value|{ 0xc41b6531, 0x97b9, 0x11d3, 0x9a, 0x29, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d }
end_define

begin_expr_stmt
name|INTERFACE_DECL
argument_list|(
name|_FPSWA_INTERFACE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
struct|struct
name|_FPSWA_RET
block|{
name|UINT64
name|status
decl_stmt|;
name|UINT64
name|err1
decl_stmt|;
name|UINT64
name|err2
decl_stmt|;
name|UINT64
name|err3
decl_stmt|;
block|}
name|FPSWA_RET
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|FPSWA_RET
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FPSWA
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|TrapType
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Bundle
parameter_list|,
name|IN
name|OUT
name|UINT64
modifier|*
name|pipsr
parameter_list|,
name|IN
name|OUT
name|UINT64
modifier|*
name|pfsr
parameter_list|,
name|IN
name|OUT
name|UINT64
modifier|*
name|pisr
parameter_list|,
name|IN
name|OUT
name|UINT64
modifier|*
name|ppreds
parameter_list|,
name|IN
name|OUT
name|UINT64
modifier|*
name|pifs
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|fp_state
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_FPSWA_INTERFACE
block|{
name|UINT32
name|Revision
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
name|EFI_FPSWA
name|Fpswa
decl_stmt|;
block|}
name|FPSWA_INTERFACE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

