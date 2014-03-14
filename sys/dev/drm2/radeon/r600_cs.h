begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__R600_CS_H__
end_ifndef

begin_define
define|#
directive|define
name|__R600_CS_H__
end_define

begin_function_decl
name|int
name|r600_dma_cs_next_reloc
parameter_list|(
name|struct
name|radeon_cs_parser
modifier|*
name|p
parameter_list|,
name|struct
name|radeon_cs_reloc
modifier|*
modifier|*
name|cs_reloc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(__R600_CS_H__) */
end_comment

end_unit

