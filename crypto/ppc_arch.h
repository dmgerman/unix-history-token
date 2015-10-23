begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__PPC_ARCH_H__
end_ifndef

begin_define
define|#
directive|define
name|__PPC_ARCH_H__
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|OPENSSL_ppccap_P
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PPC_FPU64
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PPC_ALTIVEC
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|PPC_CRYPTO207
value|(1<<2)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

