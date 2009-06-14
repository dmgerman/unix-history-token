begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  octeon_ebt3000_cf.h  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OCTEON_EBT3000_H__
end_ifndef

begin_define
define|#
directive|define
name|__OCTEON_EBT3000_H__
end_define

begin_define
define|#
directive|define
name|OCTEON_CF_COMMON_BASE_ADDR
value|(0x1d000000 | (1<< 11))
end_define

begin_define
define|#
directive|define
name|OCTEON_MIO_BOOT_REG_CFGX
parameter_list|(
name|offset
parameter_list|)
value|(0x8001180000000000ull + ((offset) * 8))
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|reserved
range|:
literal|27
decl_stmt|;
comment|/**< Reserved */
name|uint64_t
name|sam
range|:
literal|1
decl_stmt|;
comment|/**< Region 0 SAM */
name|uint64_t
name|we_ext
range|:
literal|2
decl_stmt|;
comment|/**< Region 0 write enable count extension */
name|uint64_t
name|oe_ext
range|:
literal|2
decl_stmt|;
comment|/**< Region 0 output enable count extension */
name|uint64_t
name|en
range|:
literal|1
decl_stmt|;
comment|/**< Region 0 enable */
name|uint64_t
name|orbit
range|:
literal|1
decl_stmt|;
comment|/**< No function for region 0 */
name|uint64_t
name|ale
range|:
literal|1
decl_stmt|;
comment|/**< Region 0 ALE mode */
name|uint64_t
name|width
range|:
literal|1
decl_stmt|;
comment|/**< Region 0 bus width */
name|uint64_t
name|size
range|:
literal|12
decl_stmt|;
comment|/**< Region 0 size */
name|uint64_t
name|base
range|:
literal|16
decl_stmt|;
comment|/**< Region 0 base address */
block|}
name|bits
struct|;
block|}
name|octeon_mio_boot_reg_cfgx_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OCTEON_EBT3000_H__ */
end_comment

end_unit

