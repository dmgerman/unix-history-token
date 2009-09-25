begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Written by paradox<ddkprog@yahoo.com>  * Public domain.  *  * x86 registers were borrowed from x86emu.h x86emu_regs.h  * for compatability.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_X86BIOS_H_
end_ifndef

begin_define
define|#
directive|define
name|_X86BIOS_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__BIG_ENDIAN__
end_ifdef

begin_struct
struct|struct
name|x86_register32
block|{
name|uint32_t
name|e_reg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|x86_register16
block|{
name|uint16_t
name|filler0
decl_stmt|;
name|uint16_t
name|x_reg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|x86_register8
block|{
name|uint8_t
name|filler0
decl_stmt|,
name|filler1
decl_stmt|;
name|uint8_t
name|h_reg
decl_stmt|,
name|l_reg
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__BIG_ENDIAN__ */
end_comment

begin_struct
struct|struct
name|x86_register32
block|{
name|uint32_t
name|e_reg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|x86_register16
block|{
name|uint16_t
name|x_reg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|x86_register8
block|{
name|uint8_t
name|l_reg
decl_stmt|,
name|h_reg
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BIG_ENDIAN__ */
end_comment

begin_union
union|union
name|x86_register
block|{
name|struct
name|x86_register32
name|I32_reg
decl_stmt|;
name|struct
name|x86_register16
name|I16_reg
decl_stmt|;
name|struct
name|x86_register8
name|I8_reg
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|x86regs
block|{
name|uint16_t
name|padding
decl_stmt|;
comment|/* CS is unused. */
name|uint16_t
name|register_ds
decl_stmt|;
name|uint16_t
name|register_es
decl_stmt|;
name|uint16_t
name|register_fs
decl_stmt|;
name|uint16_t
name|register_gs
decl_stmt|;
name|uint16_t
name|register_ss
decl_stmt|;
name|uint32_t
name|register_flags
decl_stmt|;
name|union
name|x86_register
name|register_a
decl_stmt|;
name|union
name|x86_register
name|register_b
decl_stmt|;
name|union
name|x86_register
name|register_c
decl_stmt|;
name|union
name|x86_register
name|register_d
decl_stmt|;
name|union
name|x86_register
name|register_sp
decl_stmt|;
name|union
name|x86_register
name|register_bp
decl_stmt|;
name|union
name|x86_register
name|register_si
decl_stmt|;
name|union
name|x86_register
name|register_di
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|x86regs
name|x86regs_t
typedef|;
end_typedef

begin_comment
comment|/* 8 bit registers */
end_comment

begin_define
define|#
directive|define
name|R_AH
value|register_a.I8_reg.h_reg
end_define

begin_define
define|#
directive|define
name|R_AL
value|register_a.I8_reg.l_reg
end_define

begin_define
define|#
directive|define
name|R_BH
value|register_b.I8_reg.h_reg
end_define

begin_define
define|#
directive|define
name|R_BL
value|register_b.I8_reg.l_reg
end_define

begin_define
define|#
directive|define
name|R_CH
value|register_c.I8_reg.h_reg
end_define

begin_define
define|#
directive|define
name|R_CL
value|register_c.I8_reg.l_reg
end_define

begin_define
define|#
directive|define
name|R_DH
value|register_d.I8_reg.h_reg
end_define

begin_define
define|#
directive|define
name|R_DL
value|register_d.I8_reg.l_reg
end_define

begin_comment
comment|/* 16 bit registers */
end_comment

begin_define
define|#
directive|define
name|R_AX
value|register_a.I16_reg.x_reg
end_define

begin_define
define|#
directive|define
name|R_BX
value|register_b.I16_reg.x_reg
end_define

begin_define
define|#
directive|define
name|R_CX
value|register_c.I16_reg.x_reg
end_define

begin_define
define|#
directive|define
name|R_DX
value|register_d.I16_reg.x_reg
end_define

begin_comment
comment|/* 32 bit extended registers */
end_comment

begin_define
define|#
directive|define
name|R_EAX
value|register_a.I32_reg.e_reg
end_define

begin_define
define|#
directive|define
name|R_EBX
value|register_b.I32_reg.e_reg
end_define

begin_define
define|#
directive|define
name|R_ECX
value|register_c.I32_reg.e_reg
end_define

begin_define
define|#
directive|define
name|R_EDX
value|register_d.I32_reg.e_reg
end_define

begin_comment
comment|/* special registers */
end_comment

begin_define
define|#
directive|define
name|R_SP
value|register_sp.I16_reg.x_reg
end_define

begin_define
define|#
directive|define
name|R_BP
value|register_bp.I16_reg.x_reg
end_define

begin_define
define|#
directive|define
name|R_SI
value|register_si.I16_reg.x_reg
end_define

begin_define
define|#
directive|define
name|R_DI
value|register_di.I16_reg.x_reg
end_define

begin_define
define|#
directive|define
name|R_FLG
value|register_flags
end_define

begin_comment
comment|/* special registers */
end_comment

begin_define
define|#
directive|define
name|R_ESP
value|register_sp.I32_reg.e_reg
end_define

begin_define
define|#
directive|define
name|R_EBP
value|register_bp.I32_reg.e_reg
end_define

begin_define
define|#
directive|define
name|R_ESI
value|register_si.I32_reg.e_reg
end_define

begin_define
define|#
directive|define
name|R_EDI
value|register_di.I32_reg.e_reg
end_define

begin_define
define|#
directive|define
name|R_EFLG
value|register_flags
end_define

begin_comment
comment|/* segment registers */
end_comment

begin_define
define|#
directive|define
name|R_DS
value|register_ds
end_define

begin_define
define|#
directive|define
name|R_SS
value|register_ss
end_define

begin_define
define|#
directive|define
name|R_ES
value|register_es
end_define

begin_define
define|#
directive|define
name|R_FS
value|register_fs
end_define

begin_define
define|#
directive|define
name|R_GS
value|register_gs
end_define

begin_define
define|#
directive|define
name|SEG_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x00F000)
end_define

begin_define
define|#
directive|define
name|SEG_OFF
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x0FFFF)
end_define

begin_define
define|#
directive|define
name|FARP
parameter_list|(
name|x
parameter_list|)
value|((le32toh(x)& 0xffff) + ((le32toh(x)>> 12)& 0xffff00))
end_define

begin_define
define|#
directive|define
name|MAPPED_MEMORY_SIZE
value|(1024 * 1024)
end_define

begin_define
define|#
directive|define
name|PAGE_RESERV
value|(4096 * 5)
end_define

begin_function_decl
name|__BEGIN_DECLS
name|void
modifier|*
name|x86bios_alloc
parameter_list|(
name|int
name|count
parameter_list|,
name|int
modifier|*
name|segs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|x86bios_free
parameter_list|(
name|void
modifier|*
name|pbuf
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|x86bios_intr
parameter_list|(
name|struct
name|x86regs
modifier|*
name|regs
parameter_list|,
name|int
name|intno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|x86bios_offset
parameter_list|(
name|uint32_t
name|offs
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_X86BIOS_H_ */
end_comment

end_unit

