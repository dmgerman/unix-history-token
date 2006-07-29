begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* opensslconf.h */
end_comment

begin_comment
comment|/* WARNING: Generated automatically from opensslconf.h.in by Configure. */
end_comment

begin_comment
comment|/* OpenSSL was configured with the following options: */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_DOING_MAKEDEPEND
end_ifndef

begin_comment
comment|/* libgmp is not in the FreeBSD base system. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_GMP
end_ifndef

begin_define
define|#
directive|define
name|OPENSSL_NO_GMP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The Kerberos 5 support is MIT-specific. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_KRB5
end_ifndef

begin_define
define|#
directive|define
name|OPENSSL_NO_KRB5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL_DOING_MAKEDEPEND */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_THREADS
end_ifndef

begin_define
define|#
directive|define
name|OPENSSL_THREADS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_STATIC_ENGINE
end_ifndef

begin_define
define|#
directive|define
name|OPENSSL_NO_STATIC_ENGINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The OPENSSL_NO_* macros are also defined as NO_* if the application    asks for it.  This is a transient feature that is provided for those    who haven't had the time to do the appropriate changes in their    applications.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_ALGORITHM_DEFINES
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OPENSSL_NO_GMP
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_GMP
argument_list|)
end_if

begin_define
define|#
directive|define
name|NO_GMP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OPENSSL_NO_KRB5
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_KRB5
argument_list|)
end_if

begin_define
define|#
directive|define
name|NO_KRB5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_OTHER_DEFINES
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|NO_ASM
end_ifndef

begin_define
define|#
directive|define
name|NO_ASM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* crypto/opensslconf.h.in */
end_comment

begin_comment
comment|/* Generate 80386 code? */
end_comment

begin_undef
undef|#
directive|undef
name|I386_ONLY
end_undef

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|VMS
argument_list|)
operator|||
name|defined
argument_list|(
name|__VMS
argument_list|)
operator|)
end_if

begin_comment
comment|/* VMS uses logical names instead */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HEADER_CRYPTLIB_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|OPENSSLDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|ENGINESDIR
value|"/usr/lib/engines"
end_define

begin_define
define|#
directive|define
name|OPENSSLDIR
value|"/etc/ssl"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|OPENSSL_UNISTD
end_undef

begin_define
define|#
directive|define
name|OPENSSL_UNISTD
value|<unistd.h>
end_define

begin_undef
undef|#
directive|undef
name|OPENSSL_EXPORT_VAR_AS_FUNCTION
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HEADER_IDEA_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|IDEA_INT
argument_list|)
end_if

begin_define
define|#
directive|define
name|IDEA_INT
value|unsigned int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HEADER_MD2_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MD2_INT
argument_list|)
end_if

begin_define
define|#
directive|define
name|MD2_INT
value|unsigned int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HEADER_RC2_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|RC2_INT
argument_list|)
end_if

begin_comment
comment|/* I need to put in a mod for the alpha - eay */
end_comment

begin_define
define|#
directive|define
name|RC2_INT
value|unsigned int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HEADER_RC4_H
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|RC4_INT
argument_list|)
end_if

begin_comment
comment|/* using int types make the structure larger but make the code faster  * on most boxes I have tested - up to %20 faster. */
end_comment

begin_comment
comment|/*  * I don't know what does "most" mean, but declaring "int" is a must on:  * - Intel P6 because partial register stalls are very expensive;  * - elder Alpha because it lacks byte load/store instructions;  */
end_comment

begin_define
define|#
directive|define
name|RC4_INT
value|unsigned int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|RC4_CHUNK
argument_list|)
end_if

begin_comment
comment|/*  * This enables code handling data aligned at natural CPU word  * boundary. See crypto/rc4/rc4_enc.c for further details.  */
end_comment

begin_undef
undef|#
directive|undef
name|RC4_CHUNK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|HEADER_NEW_DES_H
argument_list|)
operator|||
name|defined
argument_list|(
name|HEADER_DES_H
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|DES_LONG
argument_list|)
end_if

begin_comment
comment|/* If this is set to 'unsigned int' on a DEC Alpha, this gives about a  * %20 speed up (longs are 8 bytes, int's are 4). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DES_LONG
end_ifndef

begin_define
define|#
directive|define
name|DES_LONG
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HEADER_BN_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CONFIG_HEADER_BN_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|CONFIG_HEADER_BN_H
end_define

begin_define
define|#
directive|define
name|BN_LLONG
end_define

begin_comment
comment|/* Should we define BN_DIV2W here? */
end_comment

begin_comment
comment|/* Only one for the following should be defined */
end_comment

begin_comment
comment|/* The prime number generation stuff may not work when  * EIGHT_BIT but I don't care since I've only used this mode  * for debuging the bignum libraries */
end_comment

begin_undef
undef|#
directive|undef
name|SIXTY_FOUR_BIT_LONG
end_undef

begin_undef
undef|#
directive|undef
name|SIXTY_FOUR_BIT
end_undef

begin_define
define|#
directive|define
name|THIRTY_TWO_BIT
end_define

begin_undef
undef|#
directive|undef
name|SIXTEEN_BIT
end_undef

begin_undef
undef|#
directive|undef
name|EIGHT_BIT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HEADER_RC4_LOCL_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CONFIG_HEADER_RC4_LOCL_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|CONFIG_HEADER_RC4_LOCL_H
end_define

begin_comment
comment|/* if this is defined data[i] is used instead of *data, this is a %20  * speedup on x86 */
end_comment

begin_define
define|#
directive|define
name|RC4_INDEX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HEADER_BF_LOCL_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CONFIG_HEADER_BF_LOCL_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|CONFIG_HEADER_BF_LOCL_H
end_define

begin_undef
undef|#
directive|undef
name|BF_PTR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEADER_BF_LOCL_H */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HEADER_DES_LOCL_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CONFIG_HEADER_DES_LOCL_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|CONFIG_HEADER_DES_LOCL_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DES_DEFAULT_OPTIONS
end_ifndef

begin_comment
comment|/* the following is tweaked from a config script, that is why it is a  * protected undef/define */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DES_PTR
end_ifndef

begin_define
define|#
directive|define
name|DES_PTR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This helps C compiler generate the correct code for multiple functional  * units.  It reduces register dependancies at the expense of 2 more  * registers */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DES_RISC1
end_ifndef

begin_define
define|#
directive|define
name|DES_RISC1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DES_RISC2
end_ifndef

begin_undef
undef|#
directive|undef
name|DES_RISC2
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DES_RISC1
argument_list|)
operator|&&
name|defined
argument_list|(
name|DES_RISC2
argument_list|)
end_if

begin_expr_stmt
name|YOU
name|SHOULD
name|NOT
name|HAVE
name|BOTH
name|DES_RISC1
name|AND
name|DES_RISC2
name|DEFINED
operator|!
operator|!
operator|!
operator|!
operator|!
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Unroll the inner loop, this sometimes helps, sometimes hinders.  * Very mucy CPU dependant */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DES_UNROLL
end_ifndef

begin_define
define|#
directive|define
name|DES_UNROLL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These default values were supplied by  * Peter Gutman<pgut001@cs.auckland.ac.nz>  * They are only used if nothing else has been defined */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DES_PTR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DES_RISC1
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DES_RISC2
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DES_UNROLL
argument_list|)
end_if

begin_comment
comment|/* Special defines which change the way the code is built depending on the    CPU and OS.  For SGI machines you can use _MIPS_SZLONG (32 or 64) to find    even newer MIPS CPU's, but at the moment one size fits all for    optimization options.  Older Sparc's work better with only UNROLL, but    there's no way to tell at compile time what it is you're running on */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
end_if

begin_comment
comment|/* Newer Sparc's */
end_comment

begin_define
define|#
directive|define
name|DES_PTR
end_define

begin_define
define|#
directive|define
name|DES_RISC1
end_define

begin_define
define|#
directive|define
name|DES_UNROLL
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ultrix
argument_list|)
end_elif

begin_comment
comment|/* Older MIPS */
end_comment

begin_define
define|#
directive|define
name|DES_PTR
end_define

begin_define
define|#
directive|define
name|DES_RISC2
end_define

begin_define
define|#
directive|define
name|DES_UNROLL
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__osf1__
argument_list|)
end_elif

begin_comment
comment|/* Alpha */
end_comment

begin_define
define|#
directive|define
name|DES_PTR
end_define

begin_define
define|#
directive|define
name|DES_RISC2
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_AIX
argument_list|)
end_elif

begin_comment
comment|/* RS6000 */
end_comment

begin_comment
comment|/* Unknown */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__hpux
argument_list|)
end_elif

begin_comment
comment|/* HP-PA */
end_comment

begin_comment
comment|/* Unknown */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__aux
argument_list|)
end_elif

begin_comment
comment|/* 68K */
end_comment

begin_comment
comment|/* Unknown */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__dgux
argument_list|)
end_elif

begin_comment
comment|/* 88K (but P6 in latest boxes) */
end_comment

begin_define
define|#
directive|define
name|DES_UNROLL
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sgi
argument_list|)
end_elif

begin_comment
comment|/* Newer MIPS */
end_comment

begin_define
define|#
directive|define
name|DES_PTR
end_define

begin_define
define|#
directive|define
name|DES_RISC2
end_define

begin_define
define|#
directive|define
name|DES_UNROLL
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|i386
argument_list|)
end_elif

begin_comment
comment|/* x86 boxes, should be gcc */
end_comment

begin_define
define|#
directive|define
name|DES_PTR
end_define

begin_define
define|#
directive|define
name|DES_RISC1
end_define

begin_define
define|#
directive|define
name|DES_UNROLL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Systems-specific speed defines */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DES_DEFAULT_OPTIONS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEADER_DES_LOCL_H */
end_comment

end_unit

