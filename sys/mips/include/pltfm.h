begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *	JNPR: pltfm.h,v 1.5.2.1 2007/09/10 05:56:11 girish  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PLTFM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PLTFM_H_
end_define

begin_comment
comment|/*  * This files contains platform-specific definitions.  */
end_comment

begin_define
define|#
directive|define
name|SDRAM_ADDR_START
value|0
end_define

begin_comment
comment|/* SDRAM addr space */
end_comment

begin_define
define|#
directive|define
name|SDRAM_ADDR_END
value|(SDRAM_ADDR_START + (1024*0x100000))
end_define

begin_define
define|#
directive|define
name|SDRAM_MEM_SIZE
value|(SDRAM_ADDR_END - SDRAM_ADDR_START)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PLTFM_H_ */
end_comment

end_unit

