begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
operator|/
name|O
name|Registers
operator|*
operator|/
end_expr_stmt

begin_endif
endif|#
directive|endif
endif|IO_ISABEGIN
end_endif

begin_comment
comment|/*  * Input / Output Memory Physical Addresses  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IOM_BEGIN
end_ifndef

begin_define
define|#
directive|define
name|IOM_BEGIN
value|0xa0000
end_define

begin_comment
comment|/* Start of I/O Memory "hole" */
end_comment

begin_define
define|#
directive|define
name|IOM_END
value|0xFFFFF
end_define

begin_comment
comment|/* End of I/O Memory "hole" */
end_comment

begin_endif
endif|#
directive|endif
endif|IOM_BEGIN
end_endif

begin_comment
comment|/*  * RAM Physical Address Space (ignoring the above mentioned "hole")  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RAM_BEGIN
end_ifndef

begin_define
define|#
directive|define
name|RAM_BEGIN
value|0x000000
end_define

begin_comment
comment|/* Start of RAM Memory */
end_comment

begin_define
define|#
directive|define
name|RAM_END
value|0xFFFFFF
end_define

begin_comment
comment|/* End of RAM Memory */
end_comment

begin_endif
endif|#
directive|endif
endif|IOM_BEGIN
end_endif

begin_comment
comment|/*  * Oddball Physical Memory Addresses  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMPAQ_RAMRELOC
end_ifndef

begin_define
define|#
directive|define
name|COMPAQ_RAMRELOC
value|0x80c00000
end_define

begin_comment
comment|/* Compaq RAM relocation/diag */
end_comment

begin_define
define|#
directive|define
name|COMPAQ_RAMSETUP
value|0x80c00002
end_define

begin_comment
comment|/* Compaq RAM setup */
end_comment

begin_define
define|#
directive|define
name|WEITEK_FPU
value|0xC0000000
end_define

begin_comment
comment|/* WT
end_comment

end_unit

